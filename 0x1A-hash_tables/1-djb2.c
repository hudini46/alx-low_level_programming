#include "hash_tables.h"

/**
 * hash_djb2 - Hash function using the djb2 algorithm.
 * @str: The string to hash.
 *
 * Description: This function calculates the hash value for a given string
 *              using the djb2 algorithm, which is a simple and effective
 *              string hashing algorithm.
 *
 * Return: The calculated hash value.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
    unsigned long int hash;
    int c;

    hash = 5381; // Initial hash value
    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return (hash);
}
