#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    void *next;
    int data;
} Node;

Node *head = NULL;

// ADD NODE TO THE LIST
Node *addNode(int data)
{   
    Node *new = NULL;
    // two cases:

    // if list is empty
    if (head == NULL)
    {
        new = malloc(sizeof(Node));
        if (new == NULL)
            return NULL;
        
        new->data = data;
        head = new;
        new->next = NULL;

    } else {
        // if list is not empty
        new = malloc(sizeof(Node));
        if (new == NULL)
            return NULL;
        
        new->data = data;
        new->next = head;
        head = new;

    }
    return new;
}
// REMOVE NODE FROM THE LIST
int removeNode(int data)
{
    Node *current = head;
    Node *prev = head;
    while (current != NULL)
    {
        if (current->data == data)
        {
            if(current == head)
            {
                head = current->next;
            } else {
                prev->next = current->next;
                free(current);
                current = NULL;
            }
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}

// INSERT NODE INTO A POSITION IN THE LIST


// print operation
void printList()
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\n");
    return;

}

void printMenu()
{
    printf("you have the following options:\n");
    printf("\t1. Add a node to the list\n");
    printf("\t2. Remove a node from the list\n");
    printf("\t3. Insert a node into a position in the list\n");
    printf("\t4. Print your list.\n");
    printf("\t5. Quit.\n");
    return;
}

int main(int argc, char **argv)
{
    int option = -1;
    while (option != 5)
    {
        printMenu();
        int num_received = scanf("%d", &option);
        if (num_received == 1 && option > 0 && option <= 5)
        {
            switch (option)
            {
                case 1:
                    // add operation
                    printf("what data should i insert?:\n");
                    scanf("%d", &option);
                    Node *new = addNode(option);
                    break;
                case 2:
                    // remove operation
                    printf("what data should i remove?:\n");
                    scanf("%d", &option);
                    int success = removeNode(option);
                    if (!success)
                        printf("element not found\n");
                    break;
                case 3:
                    // insert operation
                    break;
                case 4:
                    // print operation
                    printList();
                    break;
                case 5:
                    break;
            }
        }
    }
    return 0;
}