#include "main.h"

char lastdir[MAX_PATH];

int launch_cmd(char **argv)
{
    if (strcmp(argv[0], "ls") == 0)
    {
        return ls(argv);
    }
    else if (strcmp(argv[0], "cat") == 0)
    {
        return cat(argv);
    }
    else if (strcmp(argv[0], "date") == 0)
    {
        return date(argv);
    }
    else if (strcmp(argv[0], "rm") == 0)
    {
        return rm(argv);
    }
    else if (strcmp(argv[0], "mkdir") == 0)
    {
        return mkdir(argv);
    }
    else
    {
        printf("Error: Invalid Command!");
    }
}

int launch_internal_cmd(char **argv)
{
    pid_t pid, wt_pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        // child process
        if (execvp(argv[0], argv) == -1)
        {
            perror("Erro: ");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        // Error forking
        perror("Error: ");
    }
    else
    {
        // Parent Process
        do
        {
            wt_pid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

void execmd(char **argv)
{
    char *command = NULL;

    if (argv)
    {
        // get the command
        command = argv[0];

        if (strcmp(command, "cd") == 0)
        {
            if (argv[1] == NULL)
            {
                fprintf(stderr, "Error: expected argument to \"cd\"\n");
            }
            else
            {
                if (chdir(argv[1]) != 0)
                {
                    perror("Error: ");
                }
            }
        }
        else if (strcmp(command, "pwd") == 0)
        {
            char cur_dir[1000];
            if (getcwd(cur_dir, sizeof(cur_dir)) == NULL)
            {
                perror("Error: ");
            }
            else
            {
                printf("%s\n", cur_dir);
            }
        }
        else if (strcmp(command, "echo") == 0)
        {
            if (argv[1] == NULL)
            {
                printf("\n");
            }
            else
            {
                for(int i=1; argv[i] != NULL; i++ )
                {
                    printf("%s ", argv[i]);
                }
            }
            printf("\n");
        }
        else
        {
            // for external commands
            launch_cmd(argv);
        }
    }
}