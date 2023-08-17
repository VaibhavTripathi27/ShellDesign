# Shell-in-C 

In the given assignment we have to make simple shell using C language, in which we were asked to handle three internal commands which are 'cd', 'pwd',and 'echo' this will be handled directly through shell. We have to make 5 external commands- ls’, ‘date’, ‘rm’, ‘cat’ and ‘mkdir’. For every external commands we have to make a separate file .c file. For this external command I have created a new process using fork() and calling the function using execvp which search the file from entire linux system and execute that.

## Brief Code Explaination  

Whenever the user runs the shell it starts an infinite shell asking for a command. On entering a command by the user, the program checks if that command is one of the internal commands ("cd", "pwd" or "echo") implemented by me. If yes, then that command's code is executed. If no, it checks if the command is one of the external commands ("cat", "date", "ls", "rm" or "mkdir") implemented by me. If yes, the code calls the respective function file. 
On execution, the function calls fork() to create the child process that actually implements the command. While the child process executes, the parent process waits for it to finish using the waitpid() function.

## Externals Commands :- 


- ls: 
	ls-a - display all files, including hidden
	ls-l - displays all the files in a long listing format

- date:
	date -u shows Universal time(GMT)
	date -R shows date in RFC 5322 format
	
- rm:
	rm -d - remove empty directories
	rm -r - remove directories and their contents recursively
	
- mkdir:
	mkdir -v - print a message when directory created
	mkdir -m - set file mode
	
- cat:
	cat -n - numbers all the output lines
	cat -b - numbers all the nonempty output lines

## Internal commands :- 

- cd:
	cd .. - go up one level of the directory tree
	cd /usr/include - To change to the /usr/include directory  

    Implemented with the help of chdir() function imported from the unistd.h header file.

- pwd: 
    prints the present working directory

    Implemented with the help of the getcwd() function from the unistd.h header file.

- echo: 
    writes its arguments to standard output, followed by a 'newline'.  If there are no arguments, only the 'newline' is written.

	

	

- Errors:
	If the input command is not one of the internal or external commands i have programmed, then it will print an error saying "invalid command". 
    If there is some error in the argument of any of the above mentioned commands (for example an incorrect path of cd or an incorrect flag for a command) then the error displayed will be same as the error displayed by the bash shell

