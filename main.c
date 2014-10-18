#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node {
    int value;
    struct node* next;
}node_t;

struct node* insert(struct node* root,int value)
{
    struct node* current;
    struct node* previous;
    struct node* temp;

    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        puts("failure to alloc");
        exit(1);
    }
    temp->value = value;

    if(root->next == NULL)
    {
        root = temp;
        temp->next = NULL;
        return temp;
    }
    else
    {
        current = root;
        while(current->next != NULL && current->value < value)
        {
            previous = current;
            current=current->next; //find aprops position.
        }

        current->next = temp;
        temp->next = previous->next;
    }
    return current;
}

struct node *  init_list()
{
    struct node *root;
    root = (struct node *)malloc(sizeof(struct node));
    root->next = NULL;
    return root; //return root or & root?
}

void travel_list(struct node* root)
{
    for(;root->next != NULL;root = root->next)
    {
        printf("%d\n",root->value);
    }
}
int main(void)
{
    struct node* head;
    head = init_list();
    head = insert(head,10); //heap addr can store stack space?
    travel_list(head);
 //   insert(head,20);
//    insert(head,15);
//    insert(head,20);


    printf("%p\n",head);
    return 0;
}

