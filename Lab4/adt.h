#include <iostream>
#include <stdlib.h>

class list {
    struct node {
        int data;
        struct node *next;
    } *head;

public:
    list() {
        head = NULL;
    }

    void insertascending(int num);
    void display();
    void merge(list other); 

private:
    node* getHead(); 
};

list::node* list::getHead() {
    return head; // Return the address of the head node
}

void list::insertascending(int num) {
    if (head == NULL || head->data > num) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->next = head;
        head = newnode;
    } else {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        struct node *temp = head;
        while (temp->next && temp->next->data < num) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void list::display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("->%d", temp->data);
        temp = temp->next;
    }
    printf("\n"); 
}

void list::merge(list other) {
    struct node *otherNode = other.head; 
    while (otherNode != NULL) {
        insertascending(otherNode->data); 
        otherNode = otherNode->next;      
    }
}
