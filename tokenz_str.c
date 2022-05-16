#include "shell.h"

/**
 * tokenizer - tokenizes string
 * @str: user input
 * Return: pointer to array of tokens
 */
char **tokenizer(char *str)
{
char **tokens;
char *token;
unsigned int i;
tokens = malloc(sizeof(char) * BUFFER);
if (tokens == NULL)
{
errors(3);
exit(EXIT_FAILURE);
}
token = strtok(str, "\n\t\r ");
i = 0;
while (token != NULL)
{
tokens[i] = token;
token = strtok(NULL, "\n\t\r ");
i++;
}
tokens[i] = NULL;
return (tokens);
}
/**
 * _strcmp - compares two strings to find out if they are exactly the same
 * @name: name supplied by user to search for
 * @variable: variable to compare against
 * @length: length of name
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strcmp(char *name, char *variable, unsigned int length)
{
unsigned int var_length;
unsigned int i;
i = 0;
while (i < length)
{
if (name[i] != variable[i])
return (-1);
i++;
}
return (1);
}
/**
 * *_strcpy - copies string pointed to by src to the buffer pointed to dest
 * @dest: string destination
 * @src: string source
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
int i;
int j = _strlen(src);
for (i = 0; i <= j; i++)
dest[i] = src[i];
return (dest);
}
/**
 * _strlen - returns the length of a string
 * @s: string to be evaluated
 * Return: length of string
 */
int _strlen(char *s)
{
int i = 0;
while (s[i] != '\0')
i++;
return (i);
}