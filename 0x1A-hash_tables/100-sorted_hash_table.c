#include "hash_tables.h"

/**
 * shash_table_create - Creates a new sorted hash table.
 * @size: The size of the new sorted hash table.
 *
 * Return: A pointer to the newly created sorted hash table, or NULL on error.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    // Allocate memory for the sorted hash table.
    shash_table_t *ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    // Initialize the size, array, and sorted head/tail pointers.
    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
        return (NULL);
    for (unsigned long int i = 0; i < size; i++)
        ht->array[i] = NULL;
    ht->shead = NULL;
    ht->stail = NULL;

    return (ht);
}

/**
 * shash_table_set - Adds or updates an element in a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add or update (cannot be an empty string).
 * @value: The value associated with the key.
 *
 * Return: 1 if successful, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    // Check for NULL pointers or empty keys/values.
    if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
        return (0);

    // Duplicate the value.
    char *value_copy = strdup(value);
    if (value_copy == NULL)
        return (0);

    // Calculate the index for the key.
    unsigned long int index = key_index((const unsigned char *)key, ht->size);

    // Check if the key already exists and update it if so.
    shash_node_t *tmp = ht->shead;
    while (tmp)
    {
        if (strcmp(tmp->key, key) == 0)
        {
            free(tmp->value);
            tmp->value = value_copy;
            return (1);
        }
        tmp = tmp->snext;
    }

    // Allocate memory for the new node.
    shash_node_t *new = malloc(sizeof(shash_node_t));
    if (new == NULL)
    {
        free(value_copy);
        return (0);
    }
    new->key = strdup(key);
    if (new->key == NULL)
    {
        free(value_copy);
        free(new);
        return (0);
    }
    new->value = value_copy;
    new->next = ht->array[index];
    ht->array[index] = new;

    // Update the sorted linked list.
    if (ht->shead == NULL)
    {
        new->sprev = NULL;
        new->snext = NULL;
        ht->shead = new;
        ht->stail = new;
    }
    else if (strcmp(ht->shead->key, key) > 0)
    {
        new->sprev = NULL;
        new->snext = ht->shead;
        ht->shead->sprev = new;
        ht->shead = new;
    }
    else
    {
        tmp = ht->shead;
        while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
            tmp = tmp->snext;
        new->sprev = tmp;
        new->snext = tmp->snext;
        if (tmp->snext == NULL)
            ht->stail = new;
        else
            tmp->snext->sprev = new;
        tmp->snext = new;
    }

    return (1);
}

/**
 * shash_table_get - Retrieves the value associated with a key in a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to retrieve the value for.
 *
 * Return: The value associated with the key, or NULL if the key is not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    // Check for NULL pointers or empty keys.
    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    // Calculate the index for the key.
    unsigned long int index = key_index((const unsigned char *)key, ht->size);

    // Search for the key in the sorted linked list.
    shash_node_t *node = ht->shead;
    while (node != NULL && strcmp(node->key, key) != 0)
        node = node->snext;

    return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - Prints the contents of a sorted hash table in order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
    if (ht == NULL)
        return;

    printf("{");
    shash_node_t *node = ht->shead;
    while (node != NULL)
    {
        printf("'%s': '%s'", node->key, node->value);
        node = node->snext;
        if (node != NULL)
            printf(", ");
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints the contents of a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    if (ht == NULL)
        return;

    printf("{");
    shash_node_t *node = ht->stail;
    while (node != NULL)
    {
        printf("'%s': '%s'", node->key, node->value);
        node = node->sprev;
        if (node != NULL)
            printf(", ");
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table and its elements.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
    if (ht == NULL)
        return;

    shash_table_t *head = ht;
    shash_node_t *node, *tmp;

    // Free memory allocated for elements and keys/values.
    node = ht->shead;
    while (node)
    {
        tmp = node->snext;
        free(node->key);
        free(node->value);
        free(node);
        node = tmp;
    }

    // Free memory allocated for the array.
    free(head->array);

    // Free memory allocated for the hash table itself.
    free(head);
}
