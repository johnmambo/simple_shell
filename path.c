#include "shell.h"

/**
 * _which - searches directories in PATH variable for command
 * @command: to search for
 * @fullpath: full path of command to execute
 * @path: full PATH variable
 * Return: pointer to full_path
 */
char *_which(char *command, char *fullpath, char *path)
{
unsigned int command_length, path_length, original_path_length;
char *path_copy, *token;
command_length = _strlen(command);
original_path_length = _strlen(path);
path_copy = malloc(sizeof(char) * original_path_length + 1);
if (path_copy == NULL)
{
errors(3);
return (NULL);
}
_strcpy(path_copy, path);
/* copy PATH directory + command name and check if it exists */
token = strtok(path_copy, ":");
if (token == NULL)
token = strtok(NULL, ":");
while (token != NULL)
{
path_length = _strlen(token);
fullpath = malloc(sizeof(char) * (path_length + command_length) + 2);
if (fullpath == NULL)
{
errors(3);
return (NULL);
}
_strcpy(fullpath, token);
fullpath[path_length] = '/';
_strcpy(fullpath + path_length + 1, command);
fullpath[path_length + command_length + 1] = '\0';
if (access(fullpath, X_OK) != 0)
{
free(fullpath);
fullpath = NULL;
token = strtok(NULL, ":");
}
else
break;
}
free(path_copy);
return (fullpath);

/**
 * main - main loop of shell
 * Return: 0 on success
 */
 int main(void)
{
char *line, *path, *fullpath;
char **tokens;
int flag, builtin_status, child_status;
struct stat buf;
while (TRUE)
{
prompt(STDIN_FILENO, buf);
line = _getline(stdin);
if (_strcmp(line, "\n", 1) == 0)
{
free(line);
continue;
}
tokens = tokenizer(line);
if (tokens[0] == NULL)
continue;
builtin_status = builtin_execute(tokens);
if (builtin_status == 0 || builtin_status == -1)
{
free(tokens);
free(line);
}
if (builtin_status == 0)
continue;
if (builtin_status == -1)
_exit(EXIT_SUCCESS);
flag = 0; /* 0 if full_path is not malloc'd */
path = _getenv("PATH");
fullpath = _which(tokens[0], fullpath, path);
if (fullpath == NULL)
fullpath = tokens[0];
else
flag = 1; /* if fullpath was malloc'd, flag to free */
child_status = child(fullpath, tokens);
if (child_status == -1)
errors(2);
free_all(tokens, path, line, fullpath, flag);
}
return (0);