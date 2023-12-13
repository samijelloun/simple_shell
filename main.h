#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 100
extern char *dir;
extern char *pathCopy;
int status;
void exit_shell();
void executeCommand(char **tokens, char **env);
int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env);
void excutehandle(char **tokens, char **env);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
#endif /* MAIN_H */
