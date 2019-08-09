#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
}Node;
struct Node* head; // gloabal variable cam be accessed anywhere
void Insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    //1. Create a new node using malloc function
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    // Initially list is empty then make the new node as head
    if(head == NULL)
    {
        head = temp; // head hi temp node ko point kryga
    }

    else
    {
// assign linked list first node pointer to tmep
    temp = head;

// loop to find the last node of linked list
    while(temp->next)
    {
        // move temp pointer to next memory block
        temp=temp->next;
    }
    // assign newNode to the end of the list
    temp->next=newNode;
    }


}
void Print()
{
    // local Node* i.e pointer to node variable meh haed ka address lekr list ko traverse kro
    struct Node* temp = head;
    printf("List is: ");
    while(temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
        head = NULL;

        // Ask user to input some number (x)
        // I will insert all that number into end of the list
        printf("How many numbers?\n");
        int n,i,x;
        scanf("%d", &n);
        for(i=0 ; i<n; i++)
        {
            printf("Enter the number:\n");
            scanf("%d", &x);
            Insert(x);
            Print();
        }

}
