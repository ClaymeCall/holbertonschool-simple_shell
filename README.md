# Simple Shell Program

## Description

This project is a simple shell program created as the final project of the first trimester at Holberton School. The shell, named `hsh`, replicates basic functionalities of a Unix shell, including command execution, path searching, and error handling. The program is designed to read commands from the standard input, tokenize them, execute them in a child process, and handle errors. It also supports executing commands both with absolute paths and by searching the `PATH` environment variable.

## Compilation / Installation

First, clone the repo using `git clone https://github.com/ClaymeCall/holbertonschool-simple_shell.git`

To compile the program as we did it, clone the repo, add a file containing your main function, and compile the whole program using the following command:
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o hsh`

## Requirements for the project
- Only allowed text editors were Vim or Emacs
- All files were compiled on Ubuntu 20.04 using the above gcc command.
- All of the code is following [Betty coding style rules](https://github.com/hs-hq/Betty/wiki)
- We were not allowed to use global variables
- We had an allowed maximum of 5 function per file

## Files

- **shell.c**: The entry point and main function of the shell program. It manages the shell's core loop, reading input, processing commands, and calling the necessary functions to execute them.

- **handle_err.c**: This file contains the error handler for the shell. It ensures that any errors encountered during the shell's operation are reported clearly to the user.

- **tokenize.c**: A function that takes the input from stdin and tokenizes it into an array of strings. This breaks down the input command into a format that can be understood and executed by the shell.

- **execute.c**: This function forks the current process, creating a child process to execute the requested program. It handles the execution flow, ensuring that the commands run in a separate process from the shell.

- **search_path.c**: If a command is given without an absolute path, this function searches for the executable in the directories listed in the `PATH` environment variable. It is responsible for locating the correct path to the executable.

## Examples

Here are some examples of how to use the `hsh` program:

1. **Using an absolute path to call a command**:
    ```bash
    $ ./hsh
    $ /bin/ls
    ```
    This will list the contents of the current directory by calling the `ls` command using its absolute path.

2. **Using a command without an absolute path**:
    ```bash
    $ ./hsh
    $ ls
    ```
    The shell will search for `ls` in the `PATH` and execute it.

3. **Using a pipe and echo to execute a command**:
    ```bash
    $ echo "/bin/ls -la" | ./hsh
    ```
    This will pipe the command `"/bin/ls -la"` into the shell, which will then execute it, listing all files in the current directory in long format.

## Testing

Our testing process is designed to ensure the robustness and correctness of the `hsh` program. We followed a structured development and testing approach:

1. **Branching Strategy**:
   - For each feature, a dedicated branch was created. In each branch, the function was compiled with a test main function before being merged into a shared `test` branch.
   - The `test` branch served as a staging area where all new features were integrated and tested together.
   - Once all tests passed on the `test` branch, it was merged into the `main` branch, ensuring that only fully tested and stable code was included in the main project.

2. **Memory Leak Testing**:
   - To ensure there were no memory leaks in our shell program, we used the following command:
     ```bash
     $ valgrind --leak-check=full ./hsh
     ```

3. **Unit Testing**:
   - We developed basic unit tests for each function within the program. These unit tests are located in the `unit_tests` directory.
   - Each test is designed to validate the correct functionality of individual components like tokenization, command execution, path searching, and error handling.

## Authors
C#24 : [Mael EZANIC](https://github.com/Mezanic) | [Clément CALLEJON](https://github.com/ClaymeCall
