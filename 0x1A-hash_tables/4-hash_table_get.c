#include "hash_tables.h"

/**
 * hash_table_get - Retrieves the value associated with a key in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to retrieve the value for.
 *
 * Description: This function looks up the value associated with the given key
 * in the provided hash table and returns it if the key is found.
 *
 * Return: If the key is not found or if the hash table is NULL - NULL.
 *         Otherwise, the value associated with the key in the hash table.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    hash_node_t *node;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    if (index >= ht->size)
        return (NULL);

    node = ht->array[index];
    while (node && strcmp(node->key, key) != 0)
        node = node->next;

    return ((node == NULL) ? NULL : node->value);
}
