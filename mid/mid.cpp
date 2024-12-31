/*#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Singly linked list structure with head and tail
struct LinkedList {
    Node* head;
    Node* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to print the entire list
    void PrintList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Function to insert an item at the end of the list
    void InsertLast(int item) {
        Node* newNode = new Node{item, nullptr};
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Function to insert an item in a sorted order
    void InsertSorted(int item) {
        Node* newNode = new Node{item, nullptr};
        if (head == nullptr || head->data >= item) {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) {
                tail = newNode;
            }
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->data < item) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            if (newNode->next == nullptr) {
                tail = newNode;
            }
        }
    }

    // Function to delete the minimum element from the list
    void DeleteMin() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* minNode = head;
        Node* prevMinNode = nullptr;
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data < minNode->data) {
                minNode = current;
                prevMinNode = prev;
            }
            prev = current;
            current = current->next;
        }

        if (prevMinNode == nullptr) {
            head = head->next;
        } else {
            prevMinNode->next = minNode->next;
        }

        if (minNode == tail) {
            tail = prevMinNode;
        }

        delete minNode;
    }
};

int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\n1. InsertLast\n2. InsertSorted\n3. PrintList\n4. DeleteMin\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the end: ";
                cin >> value;
                list.InsertLast(value);
                break;
            case 2:
                cout << "Enter value to insert in sorted order: ";
                cin >> value;
                list.InsertSorted(value);
                break;
            case 3:
                list.PrintList();
                break;
            case 4:
                list.DeleteMin();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}
*/
#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Head and tail pointers for the list
Node* head = nullptr;
Node* tail = nullptr;

// Function to print the entire list
void PrintList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

// Function to insert a node at the end of the list
void InsertLast(int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (tail == nullptr) { // List is empty
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Function to insert a node in sorted order
void InsertSorted(int value) {
    Node* newNode = new Node{value, nullptr, nullptr};

    if (head == nullptr) { // List is empty
        head = tail = newNode;
    } else if (value <= head->data) { // Insert at the beginning
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data < value) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        } else { // Update tail if inserted at the end
            tail = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete the minimum element from the list
void DeleteMin() {
    if (head == nullptr) { // List is empty
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node* minNode = head;
    Node* temp = head->next;

    // Find the node with the minimum value
    while (temp != nullptr) {
        if (temp->data < minNode->data) {
            minNode = temp;
        }
        temp = temp->next;
    }

    // Remove the minimum node
    if (minNode->prev != nullptr) {
        minNode->prev->next = minNode->next;
    } else { // Update head if minimum node is the first node
        head = minNode->next;
    }

    if (minNode->next != nullptr) {
        minNode->next->prev = minNode->prev;
    } else { // Update tail if minimum node is the last node
        tail = minNode->prev;
    }

    delete minNode;
}

int main() {
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. InsertLast\n";
        cout << "2. InsertSorted\n";
        cout << "3. DeleteMin\n";
        cout << "4. PrintList\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the end: ";
                cin >> value;
                InsertLast(value);
                break;
            case 2:
                cout << "Enter value to insert in sorted order: ";
                cin >> value;
                InsertSorted(value);
                break;
            case 3:
                DeleteMin();
                break;
            case 4:
                PrintList();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
