/*
 * @file linked_list.h
 * @brief Header file for a linked list library
 *
 * This library provides functions for creating and manipulating a singly linked list
 *
 * Author: Mohamed Rekaya
 * Date: 2023-04-28
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/**
 * @struct Node
 * @brief A struct representing a single node in the linked list
 *
 * The Node struct contains a data field and a pointer to the next node in the list
 */
typedef struct Node {
    int data;
    struct Node* next;
} List;

/**
 * @brief Creates a new linked list with a single node containing the given data
 *
 * @param data The integer data for the first node in the list
 * @return A pointer to the new linked list
 */
List* createList(int data);

/**
 * @brief Adds a new node to the end of the linked list
 *
 * @param headRef A pointer to a pointer to the head of the linked list
 * @param data The integer data for the new node
 */
void appendList(List** headRef, int data);

/**
 * @brief Adds a new node to the linked list at the specified position
 *
 * @param headRef A pointer to a pointer to the head of the linked list
 * @param data The integer data for the new node
 * @param position The position at which to insert the new node
 */
void insertList(List** headRef, int data, int position);

/**
 * @brief Removes the first node in the linked list with the specified data
 *
 * @param headRef A pointer to a pointer to the head of the linked list
 * @param data
 */
void removeList(List** headRef, int data);

/**
 * @brief Removes all nodes from the linked list
 *
 * @param headRef A pointer to a pointer to the head of the linked list
 */
void clearList(List** headRef);

/**
 * @brief Prints the data of all nodes in the linked list
 *
 * @param head A pointer to the head of the linked list
 */
void printList(List* head);

/**
 * @brief Returns the number of nodes in the linked list
 *
 * @param head A pointer to the head of the linked list
 * @return The number of nodes in the linked list
 */
int countList(List* head);

/**
 * @brief Adds multiple nodes to the end of the linked list from an array
 *
 * @param headRef A pointer to a pointer to the head of the linked list
 * @param arr The array of integers to add to the list
 * @param n The number of elements in the array
 */
void extendList(List** headRef, int arr[], int n);

/**
 * @brief Returns the position of the first node in the linked list with the specified data
 *
 * @param head A pointer to the head of the linked list
 * @param data The integer data to search for
 * @return The position of the first node with the specified data, or -1 if not found
 */
int indexList(List* head, int data);

/**
 * @brief Removes the node at the specified position in the linked list
 *
 * @param headRef A pointer to a pointer to the head of the linked list
 * @param position The position of the node to remove
 * @return The integer data of the removed node
 */
int popList(List** headRef, int position);

/**
 * @brief Copies a linked list
 *
 * @param head The head of the linked list to copy
 *
 * @return A pointer to the head of the copied linked list
 */
List* copyList(List* head);

/**
 * @brief Gets the element at the given index in a linked list
 *
 * @param head The head of the linked list to search
 * @param index The index of the element to get
 *
 * @return The element at the given index, or -1 if the index is out of bounds
 */
int getElementFromList(List* head, int index);

/**
 * @brief Reverses the order of elements in the given linked list.
 *
 * @param headRef A pointer to a pointer to the head of the linked list.
 */
void reverseList(List** headRef);

#endif
