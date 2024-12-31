/*#include <iostream>
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

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to find the kth smallest element in the linked list
int findKthSmallest(Node* head, int k) {
    int count = 0;
    Node* temp = head;

    // Traverse the list and count up to the kth smallest
    while (temp != nullptr) {
        count++;
        if (count == k) {
            return temp->data; // Return the kth element
        }
        temp = temp->next;
    }

    // If k is larger than the size of the list, return -1 to indicate error
    return -1;
}

int main() {
    Node* head = nullptr;
    int n, value, k;

    // Take user input for the number of nodes in the linked list
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Take input for each node and insert it into the linked list
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertNode(head, value);
    }

    // Ask the user for the value of k
    cout << "Enter the value of k to find the kth smallest element: ";
    cin >> k;

    // Find the kth smallest element
    int result = findKthSmallest(head, k);
    if (result != -1) {
        cout << "The " << k << "th smallest element is: " << result << endl;
    } else {
        cout << "The list is smaller than " << k << " elements." << endl;
    }

    return 0;
}
*/
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

// Function to find the size of the linked list
int getSize(Node* head) {
    int size = 0;
    Node* temp = head;
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }
    return size;
}

// Function to find the kth largest element in the linked list
int findKthLargest(Node* head, int k) {
    int size = getSize(head);

    // If k is larger than the size of the list, return -1 (invalid)
    if (k > size || k <= 0) {
        cout << "Invalid value of k!" << endl;
        return -1;
    }

    // Traverse to the (size - k + 1)th element from the start
    Node* temp = head;
    int target = size - k;
    for (int i = 0; i < target; i++) {
        temp = temp->next;
    }

    return temp->data;
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

    // Print the linked list
    cout << "The linked list is: ";
    printList(head);

    // Take input for k (position of the largest element)
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    // Find and print the kth largest element
    int result = findKthLargest(head, k);
    if (result != -1) {
        cout << "The " << k << "th largest element is: " << result << endl;
    }

    return 0;
}

