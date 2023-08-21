#include <unistd.h>  /* Include necessary system header for write function */
#include "main.h"     /* Include the header file with function prototypes */

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 *
 * Return: On success 1, on error -1
 */
int _putchar(char c)
{
    return write(1, &c, 1);  /* Using the write system call to print the character */
}
