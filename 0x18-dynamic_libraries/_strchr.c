#include "main.h"
#include <stddef.h>  /* Include this header for NULL*/

/**
 * _strchr - locates the first occurrence of a character in a string
 * @s: The string to search
 * @c: The character to find
 *
 * Return: A pointer to the first occurrence of c in s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
    while (*s != '\0')
    {
        if (*s == c)
        {
            return s;
        }
        s++;
    }
    return (*s == c) ? s : NULL;
}
