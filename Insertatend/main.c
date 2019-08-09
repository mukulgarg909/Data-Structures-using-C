#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}Node;
struct Node *head;

void insertAtEnd(int x)
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
void print()
{
    struct Node* temp = (int *)malloc(sizeof(struct Node));
    temp = head;
    int sum = 0;
    printf("List has: ");
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        // move to next block of memory
        sum = sum + temp->data;
        temp = temp->next;

    }
    printf("\n");
    printf("Sum is: %d\n", sum);
}
int main()
{
    head = NULL; // empty list
    printf("How many numbers: \n");
    int n;
    scanf("%d", &n);
    int i, x;

    for(i=0; i<n; i++)
    {
         printf("Enter the values:\n");
        scanf("%d", &x);
        insertAtEnd(x);
        print();
    }


}
