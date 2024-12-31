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
        cout << "Enter value for node " << i << ": ";
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

// Function to segregate even and odd nodes in the linked list
Node* segregateEvenOdd(Node* head) {
    if (head == nullptr) return nullptr;

    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;

    Node* current = head;

    while (current != nullptr) {
        if (current->data % 2 == 0) {
            // Even node
            if (evenHead == nullptr) {
                evenHead = current;
                evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = current;
            }
        } else {
            // Odd node
            if (oddHead == nullptr) {
                oddHead = current;
                oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = current;
            }
        }
        current = current->next;
    }

    // Combine even and odd lists
    if (evenTail != nullptr) {
        evenTail->next = oddHead;
    }

    if (oddTail != nullptr) {
        oddTail->next = nullptr;
    }

    return (evenHead != nullptr) ? evenHead : oddHead;
}

// Function to display the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;

    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    if (n <= 0) {
        cout << "The linked list is empty." << endl;
        return 0;
    }

    // Create the linked list
    Node* head = createLinkedList(n);

    cout << "Original linked list: ";
    printList(head);

    // Segregate even and odd nodes
    head = segregateEvenOdd(head);

    cout << "Linked list after segregating even and odd nodes: ";
    printList(head);

    return 0;
}
