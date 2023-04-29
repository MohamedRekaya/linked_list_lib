#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/* Create a new linked list with a single node */
List* createList(int data) {
    if( data < 0 ) return NULL;//For empty list
    List* head = (List*)malloc(sizeof(List));
    head->data = data;
    head->next = NULL;
    return head;
}

/* Append a new node to the end of the linked list */
void appendList(List** headRef, int data) {
    List* newNode = (List*)malloc(sizeof(List));
    newNode->data = data;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
    }
    else {
        List* current = *headRef;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

/* Insert a new node at the given position in the linked list */
void insertList(List** headRef, int data, int position) {
    List* newNode = (List*)malloc(sizeof(List));
    newNode->data = data;

    if (position == 0) {
        newNode->next = *headRef;
        *headRef = newNode;
    }
    else {
        List* current = *headRef;
        int i;
        for (i = 0; i < position - 1 && current != NULL; i++) {
            current = current->next;
        }
        if (current == NULL) {
            printf("Position out of range\n");
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

/**
 * Remove the first node with the specified value from the list.
 *
 * @param headRef Pointer to the head of the list.
 * @param data Value of the node to be removed.
 */
void removeList(List** headRef, int data) {
    List* current = *headRef;
    List* prev = NULL;

    if (current != NULL && current->data == data) {
        *headRef = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    prev->next = current->next;
    free(current);
}

/* Clear all nodes from the linked list */
void clearList(List** headRef) {
    List* current = *headRef;
    List* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL;
}

/* Print all elements of the linked list */
void printList(List* head) {
    if (head == NULL) printf("List is empty!");
    List* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/* Return the number of nodes in the linked list */
int countList(List* head) {
    List* current = head;
    int count = 0;

    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

/* Append an array of integers to the end of the linked list */
void extendList(List** headRef, int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        appendList(headRef, arr[i]);
    }
}

/* Return the index of the first occurrence of the given data in the linked list */
int indexList(List* head, int data) {
    List* current = head;
    int index = 0;

    while (current != NULL) {
        if (current->data == data) {
            return index;
        }
        index++;
        current = current->next;
    }
    return -1;
}

/* Remove and return the node at the given position in the linked list */
int popList(List** headRef, int position) {
    // Check if the list is empty
    if (*headRef == NULL) {
        return -1;
    }

    // Check if the position is out of range
    int len = countList(*headRef);
    if (position < 0 || position >= len) {
        return -1;
    }

    int data = -1;
    List* curr = *headRef;
    List* prev = NULL;
    for (int i = 0; i < position; i++) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL) {  // remove the first element
        *headRef = curr->next;
    } else {
        prev->next = curr->next;
    }
    data = curr->data;
    free(curr);

    return data;
}

/* Returns a new copy of the linked list */
List* copyList(List* head) {
    // Create a new head node and a tail pointer
    List* newHead = NULL;
    List** tailPtr = &newHead;

    // Loop through the original list
    for (List* current = head; current != NULL; current = current->next) {
        // Create a new node with the same data as the current node
        List* newNode = createList(current->data);
        // Append the new node to the new list
        appendList(tailPtr, newNode->data);
        // Move the tail pointer to the next node
        tailPtr = &((*tailPtr)->next);
    }

    // Return the new list
    return newHead;
}

/* Returns the element at the specified index in the list */
int getElementFromList(List* head, int index) {
    // Loop through the list until the index is found
    for (int i = 0; head != NULL; i++, head = head->next) {
        if (i == index) {
            // Return the data at the current node
            return head->data;
        }
    }

    // Index is out of range
    return -1;
}

/* Reverses the order of the nodes in the list */
void reverseList(List** headRef) {
    // Initialize three pointers to NULL
    List* prev = NULL;
    List* current = *headRef;
    List* next = NULL;

    // Loop through the list and reverse the pointers
    while (current != NULL) {
        // Store the next node
        next = current->next;
        // Reverse the current node's pointer
        current->next = prev;
        // Move to the next node
        prev = current;
        current = next;
    }

    // Update the head pointer to point to the new head
    *headRef = prev;
}



