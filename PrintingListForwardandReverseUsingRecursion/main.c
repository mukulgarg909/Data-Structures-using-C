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
void Print(struct Node *p)
{
    if(p==NULL) // base condition
    {
        printf("\n");
        return;
    }
    printf("%d ", p->data);
    Print(p->next);

}
void ReversePrint(struct Node *p)
{
    if(p==NULL) // base condition
    {
        return;
    }
    ReversePrint(p->next);
    printf("%d ", p->data); // recursive call k badh print kra value ko


}
int main()
{
    struct Node* head = NULL; // empty list
    head = insertAtEnd(head, 2); // passing head as address of the 1st node
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 6);
    head = insertAtEnd(head, 8);
    printf("Forward List: \n");
    Print(head);
    printf("Backward List: \n");
    ReversePrint(head);


}


