#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;


Node*    create_new_node(int x)
{
    Node* new = (Node*)malloc(sizeof(Node));
    
    new->data = x;
    new->next = NULL;
    new->prev = NULL;

    return new;
}

Node* insert_node_at_head(Node* head, int x)
{
    Node* new = create_new_node(x);
    if (head == NULL){
        head = new;
        return new;
    }
    head->prev = new;
    new->next = head;
    head = new;

    return new;
}

Node* insert_node_at_tail(Node* head, int x)
{
    Node* new = create_new_node(x);
    if (head == NULL) {
        return new;
    }
    Node* current = head;  // No allocation needed, just a pointer
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new;
    new->prev = current;
    return head;
}

void print_list(Node* head)
{
    printf("Printing list foward:\n");
    int counter = 1;
    while (head != NULL)
    {
        printf("Value of node %d, is %d\n", counter, head->data);
        head = head->next;
        counter++;
    }
}

void print_list_reversed(Node* head)
{
    printf("Printing list reversed:\n");
    int counter = 1;
    if (head == NULL) return;
    while (head->next != NULL){
        head = head->next;
        counter++;
    }
    while (head != NULL)
    {
        printf("Value of node %d, is %d\n", counter, head->data);
        head = head->prev;
        counter--;
    }
}

void clean_list(Node* head)
{
    Node* current = head;
    Node* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

int main()
{
    Node* head = NULL;
    head = insert_node_at_head(head, 15);
    head = insert_node_at_head(head, 2);
    head = insert_node_at_tail(head, 3);
    print_list(head);

    clean_list(head);

}