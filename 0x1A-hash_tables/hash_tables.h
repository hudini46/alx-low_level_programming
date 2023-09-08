#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure to represent a node in a regular hash table */
typedef struct hash_node_s
{
    char *key;                    /* The key, a string */
    char *value;                  /* The value corresponding to the key */
    struct hash_node_s *next;     /* Pointer to the next node in the linked list */
} hash_node_t;

/* Structure to represent a regular hash table */
typedef struct hash_table_s
{
    unsigned long int size;       /* The size of the array */
    hash_node_t **array;          /* Array of pointers to linked lists for collision handling */
} hash_table_t;

/* Function prototypes for regular hash tables */
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

/* Structure to represent a node in a sorted hash table */
typedef struct shash_node_s
{
    char *key;                    /* The key, a string */
    char *value;                  /* The value corresponding to the key */
    struct shash_node_s *next;    /* Pointer to the next node in the linked list */
    struct shash_node_s *sprev;   /* Pointer to the previous element in the sorted linked list */
    struct shash_node_s *snext;   /* Pointer to the next element in the sorted linked list */
} shash_node_t;

/* Structure to represent a sorted hash table */
typedef struct shash_table_s
{
    unsigned long int size;       /* The size of the array */
    shash_node_t **array;         /* Array of pointers to linked lists for collision handling */
    shash_node_t *shead;          /* Pointer to the first element in the sorted linked list */
    shash_node_t *stail;          /* Pointer to the last element in the sorted linked list */
} shash_table_t;

/* Function prototypes for sorted hash tables (shash tables) */
shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

#endif /* HASH_TABLES_H */

