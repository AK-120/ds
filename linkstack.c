#include<stdio.h>  
#include<stdlib.h>  
void push();  
void pop();  
void display();  
struct node   
{  
int val;  
struct node *next;  
};  
struct node *head;  
  
int main ()  
{  
    int choice=0;
    while(choice != 3)  
    {  
        printf("\n\nChoose a option...\n");  
        printf("\n1.Push\n2.Pop\n3.Exit");  
        printf("\n Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            } 
            case 3:   
            {  
                return 0;  
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
    } 
}  
}  
void push ()  
{  
    int val;  
    struct node *ptr = (struct node*)malloc(sizeof(struct node));   
    if(ptr == NULL)  
    {  
        printf("Overflow");   
    }  
    else   
    {  
        printf("Enter the value");  
        scanf("%d",&val);  
        if(head==NULL)  
        {         
            ptr->val = val;  
            ptr -> next = NULL;  
            head=ptr;  
        }   
        else   
        {  
            ptr->val = val;  
            ptr->next = head;  
            head=ptr;  
               
        }    
          
    }  
}  
  
void pop()  
{  
    int item;  
    struct node *ptr;  
    if (head == NULL)  
    {  
        printf("Underflow");  
    }  
    else  
    {  
        item = head->val;  
        ptr = head;  
        head = head->next;  
        free(ptr);  
        printf("%d,is element popped",item);  
          
    }  
} 