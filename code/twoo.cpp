void insertSorted(Node*& head, int num) {
    Node* newNode = new Node(num);

    // Case 1: Insert at the beginning or when the list is empty
    if (head == nullptr || num <= head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 2: Insert in the middle or at the end
    Node* current = head;
    while (current->next != nullptr && current->next->data < num) {
        current = current->next;
    }

    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    cout << "Linked list: ";
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    int n, data, num;

    // Input the number of nodes
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Insert nodes into the sorted linked list
    cout << "Enter the data for the sorted linked list: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        insertSorted(head, data);
    }

    // Print the linked list before insertion
    cout << "Original ";
    printList(head);

    // Input the number to insert
    cout << "Enter the number to insert: ";
    cin >> num;

    // Insert the number into the sorted linked list
    insertSorted(head, num);

    // Print the linked list after insertion
    cout << "After insertion ";
    printList(head);

    // Cleanup memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
