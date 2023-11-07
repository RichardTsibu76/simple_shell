#ifndef MAIN_H
#define MAIN_H

/* THE HEADER FILES FOR THE FUNCTIONS */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>


/* THE PROTOTYPES OF ALL THE FUNCTIONS */

void sigint_handler(int sig_int);

/* WHEN EXITING THE SHELL */
bool exit_op(char  **argv);

bool inter_rupt(char **argv, char *buffer);

size_t white_space(char **argv, char *t_buf);

char **check_quote(char *buffer, char **word);

extern char **environ;

void put_err(char *pro_name, char *cmd);

int put_char(char c);

void put_prompt(void);

/* THIS IS FOR STRRING DUPLICATE FOR KEEPING A COPY OF BUFFER */
char *_strdup(char *str);

/* THIS IS THE MAIN FUNCTION WHERE TOKENIZATION TAKES PLACE */
char **break_line(char *buf_tok);

/* THIS IS FOR THE PATH OF ALL THE EXECUTABLES EMBEDDED IN THE ENVIRON */
char *_path(char *file_name, char *all_path);

/* THIS TYPICALLY FOR THE GETTING ACCESS TO THE PATH */
char *_getenv(char **env, char *name);

/* THE PROTOTYPE FOR THE TRUE FOR FALSE WITH TYPPE BOOL */
bool put_env(char **env);

/* PROTOTYPE FOR THE CREATING A PROCESS PROCESSS */
void call_fork(char **argv, char *prog_name, char *full_path, char **env);

/*CALCULATING THE LENGTH OF THE STRING */
int _strlen(char *s);
/* THE FUNCTION PROTOTYPE FOR COPYING STRING FROM SOURCE TO DESTINATION */
char *_strcpy(char *dest, char *src);

/*JOINS OR APPENDS STRINGS */
char *_strcat(char *dest, char *src);

/*COMPARE STRINGS */
int _strcmp(char *s1, char *s2);

/*STRING COMPARE*/
int _strncmp(char *s1, char *s2, int n);

/*STRING MANUPULATION */
char *_strchr(char *s, char c);

#endif
