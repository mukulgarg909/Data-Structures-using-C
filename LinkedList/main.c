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
    //1. Create a new node using malloc function
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
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
        head = NULL; // empty list

        // Ask user to input some number (x)
        // I will insert all that number into beggining of the list
        printf("How many numbers?\n");
        int n,i,x;
        scanf("%d", &n);
        for(i=0 ; i<n; i++)
        {
            printf("Enter the number:\n");
            scanf("%d", &x);
            Insert(x); // main k upr method definition likho
            Print();
        }
    //getch();
}
