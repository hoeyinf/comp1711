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
    printf("Adding %d to linked list...\n\n", value);
    node *current = linked_list;
    while (current->next != NULL)
    {
        current = current->next;
    }
    node *new = malloc(sizeof(node));
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
    node *next;
    node *current = linked_list;
    printf("Removing position %d in linked list...\n\n", pos);
    if (pos == 0)
    {
        next = current->next;
        // replaces first node with the second node
        current->value = next->value;
        current->next = next->next;
    }
    else
    {
        int counter = 0;
        // loop until the position before the node to delete
        while (counter < pos - 1)
        {
            current = current->next;
            counter++;
        }

        // change pointer of current node to the pointer of node being deleted
        next = current->next;
        current->next = next->next;
    }
    // delete node
    free(next);
}

/**
 * @brief Print the linked list in a neatly formatted way
 *
 * @param linked_list the linked list.
 */
void print_linked_list(node *linked_list)
{
    node *current = linked_list;
    int i = 0;
    while (current != NULL)
    {
        printf("[%d]\t%d\t%p\n", i, current->value, current->next);
        current = current->next;
        i++;
    }
    printf("\n");
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
    first.value = 0;
    first.next = NULL;

    // this will be our linked list from now on.
    node *linked_list = &first;
    for (int i = 1; i < 5; i++)
    {
        add_new_node(linked_list, i);
    }
    printf("Length of linked list is %d\n\n", length(linked_list));
    print_linked_list(linked_list);
    remove_node(linked_list, 0);
    print_linked_list(linked_list);
    add_new_node(linked_list, 69);
    print_linked_list(linked_list);
    int len = length(linked_list);
    printf("Length of linked list is %d\n\n", len);
}