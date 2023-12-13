#include "main.h"

extern char **environ;
char *_getenv(char *name)
{
int k;
char *v, *t, *tr, *val;

k = 0;
while (environ[k])
{
t = _strdup(environ[k]);
v = strtok(t, "=");
if (_strcmp(v, name) == 0)
{
val = strtok(NULL, "\n");
tr = _strdup(val);
free(t);
return (tr);
}
free(t), t = NULL;
k++;
}

return (NULL);
}
void executeCommand(char **tokens, char **env)
{
pid_t pid = fork();
char *path  = _getenv("PATH");
char *pathCopy = NULL;
char *dir;
char *fullPath = NULL;
size_t dir_len;
size_t cmd_len;

if (path != NULL)
{
pathCopy = _strdup(path);
dir = strtok(pathCopy, ":");
}
if (pid == -1)
{
perror("fork");
}
else if (pid == 0)
{
if (_strchr(tokens[0], '/') != NULL)
{
if (execve(tokens[0], tokens, env) == -1)
{
perror("execve");
exit(status);
}
}
while (dir != NULL)
{
cmd_len = _strlen(tokens[0]);
dir_len = _strlen(dir);
fullPath = malloc(dir_len + cmd_len + 2);
_strcpy(fullPath, dir);
fullPath[dir_len] = '/';
_strcpy(fullPath + dir_len + 1, tokens[0]);
if (access(fullPath, F_OK) == 0)
{

if (execve(fullPath, tokens, env) != -1)
{
free(fullPath);
free(pathCopy);
exit(status);
}
}
free(fullPath);
dir = strtok(NULL, ":");
}
write(STDERR_FILENO, "./hsh: 1: ", 10);
write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
write(STDERR_FILENO, ": not found\n", 12);
free(pathCopy);
status = 127;

}
else
{
wait(&status);
status >>= 8;
}
}
