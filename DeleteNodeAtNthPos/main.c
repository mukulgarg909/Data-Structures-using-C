#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}Node;
struct Node* head;
void Insert(int data, int pos)
{
    // create m/m block for newly created node
    struct Node* newNode = (int *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // Special case when the list is empty or when we have to add node @position 1
    if(pos == 1)
    {
        newNode->next = head; // eventually node1->next points to NULL as head points to NULL
        head = newNode; // make head points to the first node
        return; // ends this function from the call stack
    }

    struct Node* ptr = head; // declare a new pointer variable which store the head address and traverse to n-1 position in  link list

    // traverse the link list to the (n-1) position node
       int i;
       for(i=1; i<pos-1; i++) // or start loop from 0 to n-2
       {
           ptr = ptr->next;
       }
    newNode->next = ptr->next; // Point the next pointer of the new node() to the next of current node(ptr).
    ptr->next = newNode; // Point the next pointer of current node to the new node.
}

void Delete(int n)
{
    struct Node* temp1 = head;
    if(n==1)
    {
        head = temp1->next;
        free(temp1);

    }
    else{
        int i;
        for(i=0; i<n-2; i++)
        {
            temp1 = temp1->next; // temp1 points to n-1 node
        }
        struct Node* temp2 = temp1->next; // temp2 points to nth node
        temp1->next = temp2->next; // now (n-1)th node points to (n+1)th node
        free(temp2); // delete kro temp2 ko as it is pointing to the node which has been deleted i.e nth node
    }
}

void print()
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    head = NULL;
    // insert 2 @position 1
    Insert(2,1); // list is 2
    Insert(3,2); // list is 2, 3
    Insert(4,3); // list is 4, 2, 3
    Insert(5,4); // list is 4, 5, 2, 3
    Insert(6,5); // list is 6, 4, 5, 2, 3
    print();
    int n;
    printf("Enter the position where you want to delete: \n");
    scanf("%d", &n);
    Delete(n);
    print();

}

