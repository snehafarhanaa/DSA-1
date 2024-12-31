#include <iostream>
using namespace std;

// Define the structure for the linked list node
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the end of the linked list
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

// Function to find the smallest difference between any two nodes in the list
int findSmallestDifference(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return -1; // If there are fewer than two nodes, no difference can be calculated
    }

    // Initialize minDiff with a large value based on the data in the first node.
    Node* current = head;
    int minDiff = abs(current->data - current->next->data); // Start with the difference between the first two nodes

    // Traverse through all pairs of nodes to find the minimum difference
    while (current != nullptr) {
        Node* temp = current->next;
        while (temp != nullptr) {
            int diff = abs(current->data - temp->data);
            if (diff < minDiff) {
                minDiff = diff; // Update minDiff if a smaller difference is found
            }
            temp = temp->next;
        }
        current = current->next;
    }

    return minDiff; // Return the smallest difference found
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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

    // Print the linked list
    cout << "Linked List: ";
    printList(head);

    // Find and print the smallest difference
    int smallestDiff = findSmallestDifference(head);

    if (smallestDiff == -1) {
        cout << "Not enough nodes to calculate the difference!" << endl;
    } else {
        cout << "The smallest difference between any two nodes is: " << smallestDiff << endl;
    }

    return 0;
}

