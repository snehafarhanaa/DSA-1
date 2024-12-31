#include <iostream>
using namespace std;

// Define the structure for the linked list node
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the end
void insertNode(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode; // If the list is empty, make the new node the head
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next; // Traverse to the last node
        }
        temp->next = newNode; // Insert the new node at the end
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout<< "NULL";
    cout << endl;
}

// Function to sort the linked list in ascending order using Bubble Sort
void sortList(Node* head) {
    if (head == nullptr) return; // If the list is empty, do nothing

    Node* i = head;
    Node* j = nullptr;
    int temp;

    while (i != nullptr) {
        j = i->next;
        while (j != nullptr) {
            if (i->data > j->data) {
                // Swap the data of nodes
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}

int main() {
    Node* head = nullptr;
    int n, value;

    // Take user input for the number of nodes in the linked list
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Take input for each node and insert it into the linked list
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertNode(head, value);
    }

    // Print the linked list before sorting
    cout << "Original list: ";
    printList(head);

    // Sort the linked list in ascending order
    sortList(head);

    // Print the linked list after sorting
    cout << "Sorted list: ";
    printList(head);

    return 0;
}

