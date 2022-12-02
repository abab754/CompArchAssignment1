#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    int val;
    struct node *next;
} node;

int size(node *head)
{
    int count = 0;
    node *ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

int contains(node *head, int value)
{
    node *current = head;
    while (current)
    {
        if ((current->val) == value)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void insert(node **head, int value)
{
    node *new_node = NULL;

    node *ptr = *head;

    if (*head == NULL)
    {
        new_node = (node *)malloc(sizeof(node));
        new_node->val = value;

        *head = new_node;
        new_node->next = NULL;
        return;
    }

    if (value < ptr->val)
    {
        new_node = (node *)malloc(sizeof(node));
        new_node->val = value;

        new_node->next = ptr;
        *head = new_node;
    }
    else if (ptr != NULL && ptr->next == NULL)
    {
        if (value > ptr->val)
        {
            new_node = (node *)malloc(sizeof(node));
            new_node->val = value;

            ptr->next = new_node;
            new_node->next = NULL;
            return;
        }
        else if (value < ptr->val)
        {
            new_node = (node *)malloc(sizeof(node));
            new_node->val = value;

            new_node->next = ptr;
            *head = new_node;
            new_node->next->next = NULL;
            return;
        }
    }
    else
    {
        while (ptr != NULL)
        {
            if (value == ptr->val)
            {
                return;
            }
            if (ptr->next != NULL)
            {

                if (value > ptr->val && value < ptr->next->val)
                {
                    new_node = (node *)malloc(sizeof(node));
                    new_node->val = value;

                    new_node->next = ptr->next;
                    ptr->next = new_node;
                    return;
                }
            }
            // end of the list and new node is greatest
            if (ptr->next == NULL)
            {
                new_node = (node *)malloc(sizeof(node));
                new_node->val = value;

                ptr->next = new_node;
                new_node->next = NULL;
                return;
            }

            ptr = ptr->next;
        }
    }
}

void delete (node **head, int value)
{
    node *previous, *current = *head;
    if (contains(current, value) == 0)
    {
        return;
    }

    if (current != NULL && current->val == value)
    {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->val != value)
    {
        previous = current;
        current = current->next;
    }

    if (*head == NULL)
    {
        return;
    }

    previous->next = current->next;

    free(current);
}

void delete_list(node *head)
{
    node *current = head, *next = head;

    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

void print_list(node *head)
{

    node *ptr = head;

    printf("%d :", size(head));


    for (int i = 0; i < size(head); i++)
    {
        printf(" %d", ptr->val);
        ptr = ptr->next;

        // if (i < size(head) - 1)
        // {
        //     printf(" ");
        // }
    }

}

int main(void)
{
    node *head = NULL;
    int i;
    char c;

    fflush(stdout);
    while (1)
    {
        if (scanf("%c %i", &c, &i) == EOF)
        {
            break;
        }

        if (tolower(c) == 'i')
        {
            insert(&head, i);
        }
        else if (tolower(c) == 'd')
        {
            delete (&head, i);
        }
        else
        {
            continue;
        }
        print_list(head);

        printf("\n");
    }

    printf("\n");

    delete_list(head);

    return EXIT_SUCCESS;
}