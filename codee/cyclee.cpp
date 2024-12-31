#include <iostream>
using namespace std;

// Define the structure for a Node
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Function to create a linked list from user input
Node* createLinkedList(int n) {
    Node* head = nullptr;
    Node* current = nullptr;

    for (int i = 1; i <= n; i++) {
        int value;
        cin >> value;

        Node* newNode = createNode(value);

        if (head == nullptr) { // For the first node
            head = newNode;
        } else {
            current->next = newNode;
        }

        current = newNode;
    }

    return head;
}

// Function to create a loop in the linked list
void createLoop(Node* head, int pos) {
    if (pos == -1) return;

    Node* loopNode = head;
    Node* tail = head;

    for (int i = 1; i < pos; i++) {
        if (loopNode != nullptr) {
            loopNode = loopNode->next;
        }
    }

    while (tail->next != nullptr) {
        tail = tail->next;
    }

    tail->next = loopNode; // Create the loop
}

// Function to detect a loop in the linked list
bool detectLoop(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        Node* checker = head;

        // Check if we have already visited the node
        while (checker != temp) {
            if (checker == temp->next) {
                return true; // Loop detected
            }
            checker = checker->next;
        }

        temp = temp->next;
    }

    return false;
}

// Function to display the linked list (for testing without a loop)
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n, pos;

    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    // Create the linked list
    Node* head = createLinkedList(n);

    cout << "Enter the position to create a loop (-1 for no loop): ";
    cin >> pos;

    // Create a loop in the linked list if required
    createLoop(head, pos);

    // Detect if there is a loop
    if (detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop in the linked list." << endl;

        // Print the linked list if no loop exists
        cout << "Linked list: ";
        printList(head);
    }

    return 0;
}

