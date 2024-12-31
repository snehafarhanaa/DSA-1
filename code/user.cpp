#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Node* detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return slow;
        }
    }
    return nullptr;
}

Node* findCycleStart(Node* head, Node* meetingPoint) {
    Node* start = head;
    while (start != meetingPoint) {
        start = start->next;
        meetingPoint = meetingPoint->next;
    }
    return start;
}


