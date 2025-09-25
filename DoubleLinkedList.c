/*
 * Asignment4.c
 *
 *  Created on: Aug 25, 2025
 *      Author: mksss
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *pre;
};

int menu();
void createLinkList(struct node **fhead);
void display_reverse(struct node **fhead);
void insertNode(struct node **fhead);
void deleteNode(struct node **fhead);
void reverseList(struct node **fhead);

int main()

{

    struct node *head = NULL;
    int ch;

    do
    {
        ch = menu();
        switch (ch)
        {

        case 1:
            createLinkList(&head);
            break;
        case 2:
            display_reverse(&head);
            break;

        case 3:
            insertNode(&head);
            break;

        case 4:
            deleteNode(&head);
            break;

        case 5:
            reverseList(&head);
            break;

        case 0:
            printf("Thank You Visit again");
        }

    } while (ch != 0);
}

int menu()
{
    int choice = 0;
    do
    {

        printf("\n\tMenu List:");
        printf("\n\t1] Create a Linked List ");
        printf("\n\t2] Display Linked List in reverse order: ");
        printf("\n\t3] Insert a node in Linked List ");
        printf("\n\t4] Delete a node in Linked List ");
        printf("\n\t5] Reverse the Linked List ");
        printf("\n\t0] End the Menu ");

        printf("\n\tWhat Linked List operation you want to perform :");
        scanf("%d", &choice);
    } while (choice < 0 || choice > 5);
    return choice;
}

void createLinkList(struct node **fhead)
{

    struct node *head = *fhead;
    struct node *i = NULL; // for traversal
    struct node *last = NULL;
    struct node *newnode = NULL;
    char ch;

    do
    {
        newnode = (struct node *)calloc(1, sizeof(struct node));
        printf("\n\tEnter node data: ");
        scanf("%d", &newnode->data);
        if (head == NULL)
        {
            head = newnode;
            last = newnode;
        }
        else
        {
            last->next = newnode;
            newnode->pre = last; // add this extra
            last = newnode;
        }

        printf("\n\tDo you want to add one more node(y/n)=");

        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    printf("Linked List created ==> ");

    for (i = head; i != NULL; i = i->next)

    {
        printf("%d ", i->data);
    }

    *fhead = head;
}

void display_reverse(struct node **fhead)
{
    struct node *head = *fhead;
    struct node *temp = head;

    while (temp->next!= NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)//temp!=head -->head not print thus temp!=null
    {   
         printf("%d ", temp->data);
         temp = temp->pre;
       
   
    }
    *fhead = head;
}

void insertNode(struct node **fhead) // adrees of head of ptr passed
{                                    // to avoid confudion keep head local variable and passed paratemeter different fhead
    struct node *head = *fhead;      // to keep code same cant use just fhead u can use *fhead inseted of head in code taken from main
    struct node *last = NULL;
    struct node *newnode = NULL;
    struct node *i = NULL; // for traversal
    int step = 0;
    printf("Where you want to add the New Node \n1]At start \n2]At Mid\n3]At End==>");
    scanf("%d", &step);
    // insert node at start
    if (step == 1)
    {
        newnode = (struct node *)calloc(1, sizeof(struct node));

        printf("\nWhat element you want to want to add at start:");
        scanf("%d", &newnode->data);

        newnode->next = head;
        head->pre = newnode; // just add
        head = newnode;

        printf("\nLinked List after adding node at start ==> ");

        for (i = head; i != NULL; i = i->next)
        {
            printf("%d ", i->data);
        }
    }
    else if (step == 2)
    {
        int cnt = 0;
        //	insert node at mid
        newnode = (struct node *)calloc(1, sizeof(struct node));
        int pos = 0;
        // traverse to reach pre pos of node to be inserted
        last = head;
        printf("\nAt what position you want to add the element:");
        scanf("%d", &pos);

        // traversel to reach last node
        last = head;

        cnt = 2;

        while (cnt < pos)
        {
            last = last->next;
            cnt++;
        }
        printf("\nEnter value you want to insert at the position: ");
        scanf("%d", &newnode->data);

        // newnode->next = last->next;
        // last->next = newnode;

        struct node *front = last->next; // store last ke bad ki node

        // joint last and newnode
        last->next = newnode;
        newnode->pre = last;

        // join newnode and stored node
        newnode->next = front;
        front->pre = newnode;

        printf("\nLinked List after adding node at mid ==> ");

        for (i = head; i != NULL; i = i->next)
        {
            printf("%d ", i->data);
        }
    }
    else if (step == 3)
    {

        // insert at end
        newnode = (struct node *)calloc(1, sizeof(struct node));
        // traversel to reach last node
        last = head;

        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = newnode;
        newnode->pre = last; // just add

        printf("\nEnter value you want to insert at last: ");
        scanf("%d", &newnode->data);

        printf("\nLinked List after adding node at end ==> ");

        for (i = head; i != NULL; i = i->next)
        {
            printf("%d ", i->data);
        }
    }
    else
        printf("Invalid Choice!");

    *fhead = head;
}

void deleteNode(struct node **fhead)
{
    struct node *head = *fhead;
    struct node *last = NULL;
    struct node *i = NULL;
    int step = 0;
    printf("From where you want to Delete the New Node \n1]start \n2]Mid\n3] End==>");
    scanf("%d", &step);
    // delete node at start

    if (step == 1)
    {
        last = head;
        head = head->next;
        head->pre = NULL; // add this
        last->next = NULL;

        printf("\nLinked List after deleting  node at start ==> ");

        for (i = head; i != NULL; i = i->next)
        {
            printf("%d ", i->data);
        }
    }
    else if (step == 2)
    {
        int value = 0;
        // traverse to reach pre pos of node to be inserted
        last = head;
        printf("\nAfter what value  you want to delete the element:");
        scanf("%d", &value);

        last = head;
        while (last->next->data != value)
        {
            last = last->next;
        }
        struct node *store = last->next->next;
        last->next = store;
        store->pre = last;

        printf("\nLinked List after deleting node ==> ");

        for (i = head; i != NULL; i = i->next)
        {
            printf("%d ", i->data);
        }
    }
    else if (step == 3)
    {

        // delete node at end
        last = head;
        while (last->next->next != NULL) // to reach till second last
        {
            last = last->next;
        }
        last->next->pre = NULL; // second last ke bad last uske piche null
        last->next = NULL;

        printf("\nLinked List after deleting  node at end ==> ");

        for (i = head; i != NULL; i = i->next)
        {
            printf("%d ", i->data);
        }
    }
    else
    {
        printf("Invalid Choice");
    }
    *fhead = head;
}

void reverseList(struct node **fhead)
{
    struct node *head = *fhead;
    struct node *temp = *fhead;
    // struct node *last = NULL;

    struct node *swap = NULL;
    struct node *i = NULL;

    while (temp != NULL)
    {
        // struct node *front=temp->next;//front has copy of that address

        swap = temp->pre;
        temp->pre = temp->next;
        temp->next = swap;
        temp = temp->pre; // to move temp forward it must be original next i.e temp ->pre as pre is original next

        // temp->pre=front;
        // front->next=temp;
        // back->pre=temp;
        // temp->next=back;

        // back=temp;
        // temp=front;
    }
    head = swap->pre;

    printf("\nLinked List after rversing ==> ");

    for (i = head; i != NULL; i = i->next)
    {
        printf("%d ", i->data);
    }

    *fhead = head; // here pre will be head i.e last element null temp will point to it
}