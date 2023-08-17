#include "main.h"

int main(void)
{

    char *input_command = NULL, *input_command_copy = NULL;
    const char *delim = " \n"; // for tokenization
    char *token;
    char **token_array;
    int token_count = 0, i = 0;
    size_t size = 0;
    ssize_t chars_read;

    // Infinite loop so that the shell runs until we want to exit
    while (1)
    {
        printf("$ ");
        chars_read = getline(&input_command, &size, stdin);

        // checking if the getline function failed or reached end of file
        if (chars_read == -1)
        {
            printf("Exiting! \n");
            return (-1);
        }

        input_command_copy = malloc(sizeof(char) * chars_read);
        if (input_command_copy == NULL)
        {
            perror("tsh: memory allocation error!");
            return (-1);
        }

        // making a copy of the input entered by user
        strcpy(input_command_copy, input_command);

        // split the string into an array of words
        token = strtok(input_command, delim);

        // counting the number of tokens
        while (token != NULL)
        {
            token_count++;
            token = strtok(NULL, delim);
        }
        token_count++;

        // allocate space and store tokens in the token_array
        token_array = malloc(sizeof(char *) * token_count);

        token = strtok(input_command_copy, delim);
        for (i = 0; token != NULL; i++)
        {
            token_array[i] = malloc(sizeof(char) * strlen(token));
            strcpy(token_array[i], token);

            token = strtok(NULL, delim);
        }
        token_array[i] = NULL;

        // printf("%s\n", input_command);

        execmd(token_array);
    }

    // freeing the memory allocated
    free(token_array);
    free(input_command);
    free(input_command_copy);

    return 0;
}
