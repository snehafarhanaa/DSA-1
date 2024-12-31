#include <iostream>
using namespace std;

// Define the structure for a Node
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

// Function to create a linked list from user input
Node* createLinkedList(int n) {
    if (n <= 0) {
        return nullptr;
    }

    int value;
    cout << "Enter the value for node 1: ";
    cin >> value;

    Node* head = createNode(value);
    Node* current = head;

    for (int i = 2; i <= n; i++) {
        cin >> value;
        current->next = createNode(value);
        current = current->next;
    }

    return head;
}

// Recursive function to swap data of nodes in pairs
void pairwiseSwap(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    // Swap the data of the current node with the next node
    int temp = head->data;
    head->data = head->next->data;
    head->next->data = temp;

    // Recursion for the next pair
    pairwiseSwap(head->next->next);
}

// Function to print the linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    // Create the linked list
    Node* head = createLinkedList(n);

    cout << "Original Linked List: ";
    printList(head);

    // Swap nodes in pairs
    pairwiseSwap(head);

    cout << "Linked List after Pairwise Swap: ";
    printList(head);

    return 0;
}
