//***********************************************************************
// Author: Minhaz Mohammad
// A C program that reads in data from the command line and stores
// it as a linear linked list.
//***********************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for a node in the linked list and a global head
struct node
{
    char name[50];
    struct node *next;
}*head;

// Function to add a name to the linked list
void insert(char * nameInput)
{
    struct node *temp = NULL;
    struct node *right = NULL;
    
    temp = (struct node *)malloc(sizeof(struct node));
    
    strcpy(temp->name , nameInput);
    
    temp->next = NULL;
    
    if (head == NULL)
    {
        head = temp;
        head->next = NULL;
    }
    else
    {
        right = head;
        
        while(right->next != NULL)
        {
            right = right->next;
        }
        
        right->next = temp;
    }
    
    return;
}

// Function to display names in linked list
void display()
{
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    
    temp = head;
    
    if(temp == NULL)
    {
        return;
    }
    else
    {
        while(temp != NULL)
        {
            printf("%s\n", temp->name);
            
            temp = temp->next;
            
            if(temp == NULL)
            {
                break;
            }
        }
    }
    
    return;
}

// Function to count names in linked list
int count()
{
    struct node *temp = NULL;
    
    int c = 0;
    
    temp = head;
    
    while(temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    
    return c;
}

// Function to delete a specific name in the linked list
char delete(char * nameInput)
{
    struct node *temp = NULL;
    struct node *prev = NULL;
    
    temp = head;
    
    while(temp != NULL)
    {
        if(strcmp(temp->name , nameInput) == 0)
        {
            if(temp == head)
            {
                head = temp->next;
                free(temp);
                
                return 1;
            }
            else
            {
                prev->next = temp->next;
                free(temp);
                
                return 1;
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    
    return 0;
}

// Main function with a continuous while loop to display menu
// and switch statement for options
int main()
{
    int input = 0;
    char nameInput[50];
    
    while(1)
    {
        printf("\nMenu\n");
        printf("===============\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Count\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        
        printf("\n");
        printf("Enter a number from the menu: ");
        
        if(scanf("%d", &input) <= 0)
        {
            printf("Enter only an integer.\n");
            exit(0);
        }
        else
        {
            switch(input)
            {
                case 1:
                    printf("Enter the name to insert: ");
                    scanf("%s", nameInput);
                    insert(nameInput);
                    break;
                case 2:
                    if(head == NULL)
                    {
                        printf("No names in list.\n");
                    }
                    else
                    {
                        display();
                    }
                    break;
                case 3:
                    printf("The number of names in this list is %d\n", count());
                    break;
                case 4:
                    if(head == NULL)
                        printf("No names in list.\n");
                    else
                    {
                        printf("Enter the name you would like to delete: ");
                        scanf("%s", nameInput);
                        
                        if(delete(nameInput))
                        {
                            printf("%s was deleted successfully.\n", nameInput);
                        }
                        else
                        {
                            printf("%s was not found in the list.\n", nameInput);
                        }
                    }
                    break;
                case 5:
                    printf("You have exited the program, Goodbye!\n");
                    return 0;
                    break;
                default:
                    printf("Invalid option.\n");
            }
        }
    }
    
    return 0;
}
