#include "main.h"

/**
 * _strcpy - copies the string pointed by src to dest
 * @dest: The destination buffer
 * @src: The source string
 *
 * Return: A pointer to the destination string (dest)
 */
char *_strcpy(char *dest, char *src)
{
    char *dest_ptr = dest;

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return dest_ptr;
}
