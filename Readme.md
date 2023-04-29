
# Linked List Library

This is a simple linked list library written in C. It provides a basic implementation of a linked list data structure, along with several common operations on linked lists.

## How to use it?

To use this library in your own C project, simply include the `linked_list.h` header file in your source code and link against the `linked_list.c` implementation file.

```c
#include "linked_list.h"

int main() {
    // Example usage of linked list library
    return 0;
}
```
## Test functions
You can test all the library functions, by running the commnad `make run`, you need to have a GCC compiler.

## Functions

### `List* createList(int value)`

Create a new List with the specified integer value.

### `void appendList(Node** headRef, int value)`

Append a new node with the specified integer value to the end of the linked list.

### `void insertList(Node** headRef, int value, int position)`

Insert a new node with the specified integer value at the specified position in the linked list.

### `void removeList(Node** headRef, int data)`

Delete the first node with the specified integer value from the linked list.

### `void clearList(Node** headRef)`

Making linked list empty.

### `int countList(Node* head)`

Get the number of nodes in the linked list.

### `void printList(Node* node)`

Print the integer values of all nodes in the linked list.

### `void reverseList(Node** headRef)`

Reverse the order of the nodes in the linked list.

### `void extendList(List** headRef, int arr[], int n)`

Adds multiple nodes to the end of the linked list from an array.

### `int popList(List** headRef, int position)`

Removes the node at the specified position in the linked list.

### `List* copyList(List* head)`

Copies a linked list.

### `int getElementFromList(List* head, int index)`

Gets the element at the given index in a linked list.

### `int indexList(List* head, int data)`

Returns the position of the first node in the linked list with the specified data.


## License

This library is licensed under the MIT license.
