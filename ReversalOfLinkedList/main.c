#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}Node;
struct Node* insertAtEnd(struct Node* head, int x) // x=data to be inserted
{
    struct Node *newNode = (int *)malloc(sizeof(struct Node));
    struct Node *ptr = (int *)malloc(sizeof(struct Node)); // node type ka hi pointer bnyga
    newNode->data = x;
    newNode->next = NULL;
    if(head == NULL)
    {
        // If linked list is empty. Insert the first node
        head = newNode;
        return head;
    }
    else
    {
        // traverse the list and insert at the end.
        ptr = head; //ptr pointer ko head jidr point kr ra udr point kro
        // if i write head = ptr; toh head ka address lost ho jayega joki humme nhi krna
        while(ptr->next !=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        return head; // starting node ka address return hoga
    }


}

struct Node* Reverse(struct Node* head)
{
    struct Node *prev, *current, *next;
    current = head; // initially current will point to head
    prev = NULL; // prev of the 1st node is NULL

    // now traverse the list one by one and make the link part of the node
    // to point to the prev node address instead of the next node address
    while(current!=NULL)
    {
        // first save the address of the next node from the current node taki hum traverse kr sky prev jodhny k badh
        next = current->next;
        current->next = prev;

        // readjust the current for the rest of traversal
        prev = current;
        current = next;

    }
    // at the end head last node ko point kryga taki voh 1st bn sky jiska address prev pointer meh  hai
    head = prev;
    return head;
}


void print(struct Node *head)
{

    printf("List has: ");
    while(head!=NULL)
    {
        printf("%d ", head->data);
        head = head->next;

    }
    printf("\n");

}
int main()
{
    struct Node* head = NULL; // empty list
    head = insertAtEnd(head, 2); // passing head as address of the 1st node
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 6);
    head = insertAtEnd(head, 8);
    print(head);
    head = Reverse(head);
    printf("List after the reversal is: \n");
    print(head);

}


