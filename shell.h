#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

int _strcmp_(char *s1, char *s2);
size_t _strncmp_(char *s1, char *s2, size_t n);
int _strlen_(char *s);
char *_strcpy_(char *dest, char *src);
char *_strcat_(char *dest, char *src);
int _putchar(char c);

char *_get_path_(char **env);
int _values_path_(char **arg, char **env);
char *_getline_command_(void);
void _getenv_(char **env);
char **_get_token_(char *lineptr);
void _exit_command_(char **args, char *lineptr, int _exit);
int _fork_fun_(char **arg, char **av, char **env,
		char *lineptr, int np, int c);
char *_strtok_(char *str, const char *delim);


#endif /* SHELL_H */
