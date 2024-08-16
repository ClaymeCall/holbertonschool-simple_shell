#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>    /* for access, chdir, close, execve, _exit, fork, getpid
			  , isatty, read, write */
#include <dirent.h>    /* for closedir, opendir, readdir */
#include <stdio.h>     /* for fflush, perror, printf, fprintf, vfprintf,
			  sprintf, putchar, getline */
#include <stdlib.h>    /* for exit, free, malloc */
#include <sys/types.h> /* for pid_t and other system types */
#include <sys/stat.h>  /* for stat, lstat, fstat */
#include <fcntl.h>     /* for open */
#include <signal.h>    /* for kill, signal */
#include <sys/wait.h>  /* for wait, waitpid, wait3, wait4 */
#include <string.h>    /* for strtok and more full library allowed */

int execute(char **argv);
char **tokenize(char *src_str, const char *separator);
void lookup_path(const char *func);

#endif
