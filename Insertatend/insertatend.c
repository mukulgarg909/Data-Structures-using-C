#include <stdio.h>
struct Node
{
    int data;
    struct Node *next;
}Node;
struct Node *head;
void print()
{
    struct Node* point = head;
    while(point!= NULL)
    {
        printf("List has : %d", point->data);
        point = point->next;
    }
}
int main()
{
    head = NULL;
    struct Node *temp = (int *)malloc(sizeof(struct Node));
    temp->data = 1;
    temp->next = NULL;
    head = temp;
    //printf("$$%d \n",head->data);
    // insert manual node at the end
    struct Node *newNode = (int *)malloc(sizeof(struct Node));
    newNode->data = 2;
    newNode->next = NULL; // last wali node ka next hmesha hi NULL hoga
    //newNode = head;
    struct Node *ptr = (int *)malloc(sizeof(struct Node));
    ptr = head;
     //printf("* %s \n",ptr->next);
    while(ptr->next != NULL)
    {
        printf("# %d \n",ptr->data);
        ptr = ptr->next;

    }
    ptr->next = newNode;//!!!! temp
    print();
}
