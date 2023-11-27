#include <stdio.h>
#include <stdlib.h>

/**
 * @brief The struct for a node - contains a value, and a pointer to the next node.
 *
 */
typedef struct node
{
    int value;
    struct node *next;
} node;

/**
 * @brief Ask the user for the new value of the node, and add it to the end of the linked list.
 *
 * @param linked_list pass in the linked list (the first node)
 */
void add_new_node(node *linked_list, int value)
{
    node *current = linked_list;
    while (current->next != NULL)
    {
        current = current->next;
    }
    node *new = malloc(sizeof(struct node));
    new->value = value;
    new->next = NULL;
    current->next = new;
}

/**
 * @brief Remove the linked list item at the given position, or give some helpful error message if there is no node there.
 *
 * @param linked_list pass in the linked list (the first node)
 * @param pos The position to be removed (0-indexed)
 */
void remove_node(node *linked_list, int pos)
{
    if (pos == 0)
    {
        linked_list = linked_list->next;
    }
    int counter = 0;
    node *current = linked_list;
    while (counter < pos - 1)
    {
        current = current->next;
        counter++;
    }
    node *next = current->next;
    current->next = next->next;
    // be extra careful about removing the first and the last item :)
}

/**
 * @brief Print the linked list in a neatly formatted way
 *
 * @param linked_list the linked list.
 */
void print_linked_list(node *linked_list, int length)
{
    node *current = linked_list;
    int counter = 0;
    while (counter < length)
    {
        printf("%d\n", current->value);
        current = current->next;
        counter++;
    }
}

/**
 * @brief Returns the length of the linked list - this one is provided as it might be useful for you :)
 *
 * @param linked_list the linked list
 * @return int the length of the linked list
 */
int length(node *linked_list)
{
    int counter = 1;
    node *current = linked_list;
    while (current->next != NULL)
    {
        current = current->next;
        counter++;
    }
    return counter;
}

int main()
{

    // creating a first node to get us started...
    node first;
    first.value = 1;
    first.next = NULL;

    // this will be our linked list from now on.
    node *linked_list = &first;
    add_new_node(linked_list, 2);
    add_new_node(linked_list, 3);
    add_new_node(linked_list, 4);
    int len = length(linked_list);
    print_linked_list(linked_list, len);
}