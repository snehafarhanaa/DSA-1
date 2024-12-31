//userinput+printlist+size+middle value+ occurrence+sort+delete even num+ reverse+
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* head = nullptr;
void insertFirst(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}
int getSize(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
void printList() {
    Node* current = head;
    cout << "Linked list: ";
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}
void printMiddle(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "The middle node value is: " << slow->data << endl;
}
int countOccurrences(Node* head, int target) {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        if (current->data == target) {
            count++;
        }
        current = current->next;
    }
    cout << "The number " << target << " occurs " << count << " times in the linked list." << endl;
    return count;
}
void insertINsort(int item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = nullptr;

    Node* prev = head;
    while (prev->next != nullptr && prev->next->data < item) {
        prev = prev->next;
    }
    newNode->next = prev->next;
    prev->next = newNode;
}
void deleteEvenNumbers() {
    while (head != nullptr && head->data % 2 == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data % 2 == 0) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}
void reverseList() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move the `prev` pointer to the current node
        current = next;       // Move to the next node
    }

    head = prev; // Update the head to the new front
}
/*Node* rotateLeft(Node* head, int k) {
    if (head == nullptr || k == 0) return head;

    // Find the length of the linked list
    Node* temp = head;
    int length = 1;
    while (temp->next != nullptr) {
        length++;
        temp = temp->next;
    }

    // If k is greater than or equal to the length of the list, take modulo
    k = k % length;
    if (k == 0) return head;

    // Connect the last node to the head to form a circular linked list
    temp->next = head;

    // Find the new tail (length - k - 1) and the new head (length - k)
    temp = head;
    for (int i = 1; i < length - k; i++) {
        temp = temp->next;
    }

    // Set the new head and break the circular link
    Node* newHead = temp->next;
    temp->next = nullptr;

    return newHead;
}*/
int main()
{
    int data,n,target,num;
    cin >> n;
    for(int i=0; i<n; i++){
    cin >> data;
    insertFirst(data);
    }
    printList();
    cout << "Size of the linked list: " << getSize(head) << endl;
    printMiddle(head);
    cin >> target;
    countOccurrences(head, target);
    cin >> num;
    insertINsort(num);
    printList();
    deleteEvenNumbers();
    printList();
    reverseList();
    printList();

}
