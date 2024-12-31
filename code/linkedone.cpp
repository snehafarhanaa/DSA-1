#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to calculate the size of the linked list
int getSize(struct Node* head) {
    int count = 0;
    struct Node* current = head; // Start from the head of the list

    while (current != NULL) {
        count++;                // Increment count for each node
        current = current->next; // Move to the next node
    }
    return count;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Driver code
int main() {
    // Create a linked list: 1 -> 2 -> 3
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    // Print the size of the linked list
    printf("Size of the linked list: %d\n", getSize(head));

    // Free the allocated memory (optional for small programs, but good practice)
    struct Node* current = head;
    struct Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

