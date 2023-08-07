#ifndef CUSTOM_LISTS_H
#define CUSTOM_LISTS_H

#include <stdlib.h>

typedef struct custom_list_node
{
    int value;
    struct custom_list_node *next;
} custom_list_t;

size_t print_custom_list(const custom_list_t *list);
custom_list_t *add_custom_node(custom_list_t **start, const int value);
void free_custom_list(custom_list_t *start);
int check_custom_cycle(custom_list_t *list);

#endif /* CUSTOM_LISTS_H */
