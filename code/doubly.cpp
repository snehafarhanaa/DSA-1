/*#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to reverse a doubly linked list
Node* reverseDoublyLinkedList(Node* head) {
    if (!head) return nullptr;

    Node* current = head;
    Node* temp = nullptr;

    // Swap next and prev for all nodes
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node (previous due to reversal)
    }

    // Adjust the head pointer
    if (temp) {
        head = temp->prev;
    }

    return head;
}

// Function to print the doubly linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function to test the program
int main() {
    // Create a doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Original List: ";
    printList(head);

    // Reverse the list
    head = reverseDoublyLinkedList(head);

    cout << "Reversed List: ";
    printList(head);

    // Free allocated memory (optional for demonstration purposes)
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to detect a cycle in a doubly linked list
bool detectCycle(Node* head) {
    if (!head) return false;

    Node* slow = head; // Moves one step at a time
    Node* fast = head; // Moves two steps at a time

    while (fast && fast->next) {
        slow = slow->next;         // Move slow one step
        fast = fast->next->next;   // Move fast two steps

        // Check if slow and fast meet
        if (slow == fast) {
            return true; // Cycle detected
        }
    }
    return false; // No cycle found
}

// Helper function to create a doubly linked list
Node* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    return head;
}

// Function to print a doubly linked list (useful for testing non-cyclic lists)
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function to test the cycle detection
int main() {
    // Create a doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    int arr[] = {1, 2, 3, 4, 5};
    Node* head = createList(arr, 5);

    // Introduce a cycle for testing (5 -> 3)
    Node* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = head->next->next; // Create a cycle
    head->next->next->prev = tail; // Maintain reverse link consistency

    // Check for a cycle
    if (detectCycle(head)) {
        cout << "Cycle detected in the doubly linked list." << endl;
    } else {
        cout << "No cycle in the doubly linked list." << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to check if a doubly linked list is a palindrome
bool isPalindrome(Node* head) {
    if (!head) return true; // Empty list is a palindrome

    // Find the tail of the list
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }

    // Compare nodes from the head and tail
    Node* front = head;
    Node* back = tail;
    while (front != back && front->prev != back) {
        if (front->data != back->data) {
            return false; // Not a palindrome
        }
        front = front->next; // Move front pointer forward
        back = back->prev;   // Move back pointer backward
    }

    return true; // It's a palindrome
}

// Helper function to create a doubly linked list
Node* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    return head;
}

// Main function to test the palindrome check
int main() {
    // Create a doubly linked list: 1 <-> 2 <-> 3 <-> 2 <-> 1
    int arr[] = {1, 2, 3, 2, 1};
    Node* head = createList(arr, 5);

    // Check if the list is a palindrome
    if (isPalindrome(head)) {
        cout << "The doubly linked list is a palindrome." << endl;
    } else {
        cout << "The doubly linked list is not a palindrome." << endl;
    }

    // Free allocated memory (optional for demonstration purposes)
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to check if a doubly linked list is a palindrome and calculate its length
bool isPalindromeAndLength(Node* head, int& length) {
    if (!head) {
        length = 0;
        return true; // An empty list is a palindrome
    }

    // Find the length and tail of the list
    length = 0;
    Node* tail = head;
    while (tail) {
        length++;
        if (tail->next) {
            tail = tail->next;
        } else {
            break;
        }
    }

    // Check for palindrome
    Node* front = head;
    Node* back = tail;

    while (front != back && front->prev != back) {
        if (front->data != back->data) {
            return false; // Not a palindrome
        }
        front = front->next; // Move front forward
        back = back->prev;   // Move back backward
    }

    return true; // It's a palindrome
}

// Helper function to create a doubly linked list
Node* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    return head;
}

// Main function to test the palindrome and length calculation
int main() {
    // Create a doubly linked list: 1 <-> 2 <-> 3 <-> 2 <-> 1
    int arr[] = {1, 2, 3, 2, 1};
    Node* head = createList(arr, 5);

    int length = 0;
    if (isPalindromeAndLength(head, length)) {
        cout << "The doubly linked list is a palindrome." << endl;
    } else {
        cout << "The doubly linked list is not a palindrome." << endl;
    }
    cout << "Length of the doubly linked list: " << length << endl;

    // Free allocated memory (optional for demonstration purposes)
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
*/
