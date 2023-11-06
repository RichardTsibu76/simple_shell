#ifndef MAIN_H
#define MIAN_H

/* These are the list of header files */
/* Header for input and output */
#include <stdio.h>
/* Header files manipulating strings */
#include <string.h>
/* Header for unix or other functions or system calls */
#include <unistd.h>
/* Header for allocating memory dynamically  for malloc precisely*/
#include <stdlib.h>
/* Header files for file controllability */
#include <fcntl.h>
/* handling system and type definitons for data structures */
#include <sys/types.h>
/* For signal handling */ 
#include <signal.h>
/* the header for the boolen true or false */
#include <stdbool.h>

/* THE VARIOUS PROTOTYPES OF THE FUNCTIONS AS PART OF THE SYNOPSIS */
int put_char(char c);
void put_prompt(void);
/* for string duplicate */

char *_strdup(char *str);
/* for tokenization using delimeter */
char **break_line(char *buf_tok);
char *_getenv(char **env, char *name);
bool put_env(char **env);
void call_fork(char **argv, char *prog_name, char *full_path, char **env);
/* This function calculate the len of string */
int _strlen(char *s);
/* This function prototypes is for copying of strng from source to destination */
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
/* using the string compare function */
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strchr(char *s, char c);

#endif
