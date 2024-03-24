#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue();
void dequeue();

int main()
{
    int choice;

    while (choice != 3)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            return 0;
        default:
            printf("Enter valid choice\n");
        }
    }

    return 0;
}

void enqueue()
{
    struct node *ptr;
    int item;

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }

    printf("\nEnter value: ");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = NULL;

    if (front == NULL)
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
}

void dequeue()
{
    struct node *ptr;
    if (front == NULL)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        ptr = front;
        front = front->next;
        printf("Dequeued item: %d\n", ptr->data);
        free(ptr);
    } 
}