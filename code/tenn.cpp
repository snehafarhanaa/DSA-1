#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to detect a cycle in the linked list
Node* detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { // Cycle detected
            return slow;
        }
    }
    return nullptr; // No cycle
}

// Function to find the starting node of the cycle
Node* findCycleStart(Node* head, Node* meetingPoint) {
    Node* start = head;
    while (start != meetingPoint) {
        start = start->next;
        meetingPoint = meetingPoint->next;
    }
    return start;
}

// Main function to test the linked list for a cycle
int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int n, value, pos;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the values of the nodes:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        Node* newNode = createNode(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Enter the position (0-based index) to connect the last node to create a cycle (-1 for no cycle): ";
    cin >> pos;

    if (pos >= 0) {
        Node* temp = head;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        tail->next = temp; // Create the cycle
    }

    Node* meetingPoint = detectCycle(head);
    if (meetingPoint != nullptr) {
        cout << "Cycle detected.\n";
        Node* cycleStart = findCycleStart(head, meetingPoint);
        cout << "Cycle starts at node with value: " << cycleStart->data << endl;
    } else {
        cout << "No cycle detected.\n";
    }

    return 0;
}

