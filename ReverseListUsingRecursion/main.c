#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}Node;
struct Node* head; // global variable
void insertAtEnd(int x) // x=data to be inserted
{
    struct Node *newNode = (int *)malloc(sizeof(struct Node));
    struct Node *ptr = (int *)malloc(sizeof(struct Node)); // node type ka hi pointer bnyga
    newNode->data = x;
    newNode->next = NULL;
    if(head == NULL)
    {
        // If linked list is empty. Insert the first node
        head = newNode;

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

    }


}
struct Node* RReverse(struct Node* p)
{
  while(p->next == NULL) // base condition
   {
       head = p;
       return;
   }

    // traverse till the end of the node and point head to last node
   RReverse(p->next); // After each R-call node has been reversed
   struct Node *q = p;
   q->next = p;
   p->next = NULL;

}
void print()
{
    struct Node* temp = head;
    printf("List has: ");
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;

    }
    printf("\n");

}
void rprint(struct Node *head)
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
    head = NULL; // empty list
    insertAtEnd(2); // passing head as address of the 1st node
    insertAtEnd(4);
    insertAtEnd(6);
    insertAtEnd(8);
    print();
    head = RReverse(head);
    printf("List after the reversal is: \n");
    rprint(head);

}



