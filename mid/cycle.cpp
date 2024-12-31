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

// Function to detect a cycle and return the start of the cycle
Node* detectCycle(Node* head) {
    if (head == nullptr) return nullptr;

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect if a cycle exists using the Tortoise and Hare approach
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // Move slow pointer one step
        fast = fast->next->next;     // Move fast pointer two steps

        if (slow == fast) {          // Cycle detected
            // Step 2: Find the start of the cycle
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // The start of the cycle
        }
    }
    return nullptr; // No cycle detected
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

    // Take user input for the number of nodes in the linked list
    int n, value;
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Take input for each node and insert it into the linked list
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertNode(head, value);
    }

    // For testing purposes, create a cycle manually (you can skip this part in a real test)
    // Example: Create a cycle by linking the last node to the 3rd node
    if (n >= 4) {
        Node* temp = head;
        for (int i = 0; i < 2; i++) {
            temp = temp->next;
        }
        Node* cycleStart = temp; // Node where the cycle will start
        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = cycleStart; // Creating the cycle
    }

    // Detect cycle
    Node* cycleStart = detectCycle(head);

    if (cycleStart != nullptr) {
        cout << "Cycle detected! The cycle starts at node with value: " << cycleStart->data << endl;
    } else {
        cout << "No cycle detected!" << endl;
    }

    return 0;
}

