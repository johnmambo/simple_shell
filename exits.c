#include "shell.h"

/**
 *CtrlC - Avoid exit with Ctrl C
 *@sig_num: Signal number 
 *
 *Description: Avoid exit with Ctrl C
 *Return: nothing
 */

void CtrlC(int sig_num)
{
(void) sig_num;
write(STDOUT_FILENO, "\n$ ", 3);
}
