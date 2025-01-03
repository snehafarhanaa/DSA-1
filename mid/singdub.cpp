/*#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* link;

    Node(int data) {
        this->data = data;
        this->link = nullptr;
    }
};

Node* head = nullptr;

void insertFirst(int data) {
    Node* newNode = new Node(data);
    newNode->link = head;
    head = newNode;
}

void insertLast(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->link != nullptr) {
        current = current->link;
    }
    current->link = newNode;
}

void insertAt(int data, int position) {
    if (position < 0) {
        cout << "Invalid position." << endl;
        return;
    } else if (position == 0) {
        insertFirst(data);
        return;
    } else {
        Node* newNode = new Node(data);
        Node* current = head;
        int currentPosition = 0;
        while (current != nullptr && currentPosition < position - 1) {
            current = current->link;
            currentPosition++;
        }
        if (current == nullptr) {
            cout << "Position exceeds the length of the list. Node not inserted." << endl;
            delete newNode;
            return;
        } else {
            newNode->link = current->link;
            current->link = newNode;
        }
    }
}

void deleteFirst() {
    if (head == nullptr) {
        cout << "The list is empty. Nothing to delete." << endl;
        return;
    }
    Node* temp = head;
    head = head->link;
    delete temp;
}

void deleteLast() {
    if (head == nullptr) {
        cout << "The list is empty. Nothing to delete." << endl;
        return;
    } else if (head->link == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* current = head;
    while (current->link->link != nullptr) {
        current = current->link;
    }
    delete current->link;
    current->link = nullptr;
}

void deleteItem(int item) {
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->data == item) {
            if (prev != nullptr) {
                prev->link = current->link;
            } else {
                head = current->link;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->link;
    }
    cout << "Item not found. Node not deleted." << endl;
}

int searchItem(int item) {
    Node* current = head;
    int position = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return position;
        }
        current = current->link;
        position++;
    }
    return -1;
}

void printList() {
    Node* current = head;
    cout << "Linked list: ";
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->link;
    }
    cout << "NULL" << endl;
}

int main() {
    int option, data, position, item;

    while (true) {
        cout << "\n!!!  MENU  !!!\n";
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Insert At\n";
        cout << "4. Delete First\n";
        cout << "5. Delete Last\n";
        cout << "6. Delete Item\n";
        cout << "7. Print the list\n";
        cout << "8. Search\n";
        cout << "9. Quit\n";
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                insertFirst(data);
                break;
            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                insertLast(data);
                break;
            case 3:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert at: ";
                cin >> position;
                insertAt(data, position);
                break;
            case 4:
                deleteFirst();
                break;
            case 5:
                deleteLast();
                break;
            case 6:
                cout << "Enter the item to delete: ";
                cin >> item;
                deleteItem(item);
                break;
            case 7:
                printList();
                break;
            case 8:
                cout << "Enter the item to search: ";
                cin >> item;
                position = searchItem(item);
                if (position != -1) {
                    cout << "Item found at position " << position << "." << endl;
                } else {
                    cout << "Item not found in the list." << endl;
                }
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid option. Please select a valid option." << endl;
        }
    }

    return 0;
}

*/
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};


Node* head = nullptr;


void insertFirst(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}



void insertLast(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}



void insertAt(int data, int position) {
    Node* newNode = new Node(data);
    if (position == 0) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    Node* current = head;
    int currentPosition = 0;
    while (current != nullptr && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == nullptr) {
        cout << "Position is out of bounds!" << endl;
    } else {
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}



void deleteFirst() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete the first node." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}



void deleteLast() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete the last node." << endl;
        return;
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->prev->next = nullptr;
        delete current;
    }
}



void deleteItem(int item) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == item) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            delete current;
            return;
        }
        current = current->next;
    }
    cout << "Item not found. Node not deleted." << endl;
}



void printForward() {
    Node* current = head;
    cout << "Doubly linked list (forward): ";
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}



void printBackward() {
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        current = current->next;
    }
    cout << "Doubly linked list (backward): NULL";
    while (current != nullptr) {
        cout << " <- " << current->data;
        current = current->prev;
    }
    cout << endl;
}



int main() {
    int option, data, position, item;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Insert At\n"; //hidden
        cout << "4. Delete First\n";
        cout << "5. Delete Last\n";
        cout << "6. Delete Item\n";
        cout << "7. Print the list (forward)\n";
        cout << "8. Print the list (backward)\n";
        cout << "9. Quit\n";
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                insertFirst(data);
                break;
            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                insertLast(data);
                break;
            case 3:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert at: ";
                cin >> position;
                insertAt(data, position);
                break;
            case 4:
                deleteFirst();
                break;
            case 5:
                deleteLast();
                break;
            case 6:
                cout << "Enter the item to delete: ";
                cin >> item;
                deleteItem(item);
                break;
            case 7:
                printForward();
                break;
            case 8:
                printBackward();
                break;
            case 9:
                while (head != nullptr) {
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                }
                return 0;
            default:
                cout << "Invalid option. Please select a valid option." << endl;
        }
    }
}


