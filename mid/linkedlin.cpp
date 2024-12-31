/*#include <iostream>
using namespace std;

// Define the structure of a node
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

// Function to insert a node at the end of the linked list
void insertAtEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
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

// Function to perform linear search
bool linearSearch(Node* head, int target) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == target) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* head = nullptr; // Initialize an empty linked list
    int n, value, target;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertAtEnd(head, value);
    }

    cout << "The linked list is: ";
    printList(head);

    cout << "Enter the value to search: ";
    cin >> target;

    if (linearSearch(head, target)) {
        cout << target << " found in the list.\n";
    } else {
        cout << target << " not found in the list.\n";
    }

    return 0;
}
*/
#include <iostream>
using namespace std;

// Define the structure of a node in a doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(Node*& head, Node*& tail, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) { // If the list is empty
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Function to print the doubly linked list from the head
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout<<"NULL";
    cout << endl;
}

// Function to perform linear search in a doubly linked list
bool linearSearch(Node* head, int target) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == target) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* head = nullptr; // Initialize an empty doubly linked list
    Node* tail = nullptr;
    int n, value, target;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertAtEnd(head, tail, value);
    }

    cout << "The doubly linked list is: ";
    printList(head);

    cout << "Enter the value to search: ";
    cin >> target;

    if (linearSearch(head, target)) {
        cout << target << " found in the list.\n";
    } else {
        cout << target << " not found in the list.\n";
    }

    return 0;
}
