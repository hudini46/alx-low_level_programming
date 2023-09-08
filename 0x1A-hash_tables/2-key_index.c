#include "hash_tables.h"

/**
 * key_index - Calculates the index at which a key should be stored in a hash table.
 * @key: The key to calculate the index for.
 * @size: The size of the hash table's array.
 *
 * Description: This function calculates the index at which a key/value pair
 * should be stored in the array of a hash table using the djb2 hashing algorithm.
 *
 * Return: The calculated index for the key.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    return (hash_djb2(key) % size);
}
