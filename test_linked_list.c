#include <stdio.h>
#include "linked_list.h"


int main() {
    //Test createList(int data) func, <0 for empty list 	
    List* myList = createList(-1);
    //Test appendList(List** headRef, int data);	
    appendList(&myList, 5);
    appendList(&myList, 7);
    appendList(&myList, 9);
    appendList(&myList, 3);
    appendList(&myList, 2);

    printf("Original list: ");
    //Test printList(List* headRef);
    printList(myList);

    //Test removeList(List** headRef, int data);
    removeList(&myList, 9);
    printf("List after deleting 9: ");
    printList(myList);

    //Test reverseList(List** headRef);
    reverseList(&myList);
    printf("Reversed list: ");
    printList(myList);

    //Test insertList(List** headRef, int data, int position);
    //positions start from 0
    insertList(&myList, 9, 2);
    printf("List after inserting 9 at position 2: ");
    printList(myList);

    //Test clearList(List** headRef);
    clearList(&myList);
    printf("List after clearing it: ");
    printList(myList);

    //Test extendList(List** headRef, int arr[], int n);
    int arr[5] = {5, 7, 9, 3, 2};
    printf("List after extending it: ");
    extendList(&myList, arr, 5);
    printList(myList);

    // Test countList(List* headRef);
    int n = countList(myList);
    printf("The length of LL: %d\n", n);

    //Test indexList(List* headRef, int data);
    int index = indexList(myList, 9);
    printf("The index of 9: %d\n", index);

    //Test popList(List** headRef, int index);
    int data = popList(&myList, 2);
    printf("List after poping %d: ", data);
    printList(myList);

    //Test copyList(List* headRef);
    List* myListCp = copyList(myList);
    printf("Copy of myList: ");
    printList(myListCp);
    printf("myListcp address: %p different from myList address: %p \n",(void*) &myListCp, (void*)&myList);

    //Test getElementFromList(List* headRef, int position);
    int data1 = getElementFromList(myList, 2);
    printf("The data of third node: %d\n", data1);
   

    return 0;
}

