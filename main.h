#ifndef MAIN_H
#define MAIN_H


/* fflush, perror, printf, fprintf, vfprintf, sprintf, putchar, getline */
#include <stdio.h>

/* access, chdir, close, execve, _exit, fork, getpid, isatty, read, write */
#include <unistd.h>

/* exit, free, malloc */
#include <stdlib.h>

/* pid_t and other system types */
#include <sys/types.h>

/* stat, lstat, fstat */
#include <sys/stat.h>

/* open */
#include <fcntl.h>

/* kill, signal */
#include <signal.h>

/* wait, waitpid, wait3, wait4 */
#include <sys/wait.h>

/* whole library is allowed */
#include <string.h>

int execute(char **argv);
char **tokenize(char *src_str, const char *separator);
char *lookup_path(const char *func);
char *get_path_env(void);
int handle_special_cases(char *buf, ssize_t buf_len);
#endif
