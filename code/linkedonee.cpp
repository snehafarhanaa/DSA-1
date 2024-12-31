#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to calculate the size of the linked list
int getSize(struct Node* head) {
    int count = 0;
    struct Node* current = head; // Start from the head
    while (current != NULL) {
        count++;                 // Increment count for each node
        current = current->next; // Move to the next node
    }
    return count;
}

// Function to create a linked list from an array of integers
struct Node* createLinkedList(int arr[], int size) {
    if (size == 0) return NULL;

    struct Node* head = createNode(arr[0]);
    struct Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Main function
int main() {
    // Input array representing the linked list
    int input[] = {34, 12, 55, 42, 11};
    int n = sizeof(input) / sizeof(input[0]);

    // Create the linked list
    struct Node* head = createLinkedList(input, n);

    // Calculate and print the size of the linked list
    printf("Size of the linked list: %d\n", getSize(head));

    // Free the allocated memory
    struct Node* current = head;
    struct Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

