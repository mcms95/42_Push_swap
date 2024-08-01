#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node*    create_new_node(int x)
{
    Node* new = (Node*)malloc(sizeof(Node));
    
    new->data = x;
    new->next = NULL;
    return new;
}

Node* insert_at_head(Node* head, int x)
{
    Node* new = create_new_node(x);
    new->next = head;
    head = new;

    return head;
}

Node* pop(Node* head)
{
    Node* new_head = head;
    if (head == NULL){
        return NULL;
    }
    new_head = head->next;
    free(head);

    return new_head;
    
}

void print_list(Node* head)
{
    Node* current = head;
    while(current != NULL)
    {
        printf("value is: %d\n", current->data);
        current = current->next;

    }
}

int main()
{
    Node* head = NULL;
    head = insert_at_head(head, 2);
    head = insert_at_head(head, 3);
    print_list(head);
    head = pop(head);
    print_list(head);

}