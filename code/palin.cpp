/*#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Function to check if the linked list is a palindrome
void isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        cout << "YES" << endl;
        return;
    }

    // Step 1: Find the middle of the linked list
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the linked list
    Node* secondHalf = reverseList(slow);

    // Step 3: Compare the first and second halves
    Node* firstHalf = head;
    Node* secondHalfCopy = secondHalf; // To restore the list later
    bool isPalindrome = true;

    while (secondHalf != nullptr) {
        if (firstHalf->data != secondHalf->data) {
            isPalindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Step 4: Restore the second half to its original order
    reverseList(secondHalfCopy);

    // Step 5: Print the result
    cout << (isPalindrome ? "YES" : "NO") << endl;
}

// Function to insert a new node at the end of the linked list
void append(Node*& head, int data) {
    Node* newNode = new Node(data);
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

// Main function
int main() {
    Node* head = nullptr;

    // Create a linked list 1->2->3->2->1
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 2);
    append(head, 1);

    // Check if the list is a palindrome
    isPalindrome(head);

    return 0;
}

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* newNode = new Node(curr->data); // Create a new node with the current data
        newNode->next = prev; // Add it to the reversed list
        prev = newNode;
        curr = curr->next;
    }
    return prev;
}

// Function to check if the linked list is a palindrome
void isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        cout << "YES" << endl;
        return;
    }

    // Step 1: Create a reversed copy of the linked list
    Node* reversedHead = reverseList(head);

    // Step 2: Compare the original list with the reversed copy
    Node* tempOriginal = head;
    Node* tempReversed = reversedHead;

    bool isPalindrome = true;
    while (tempOriginal != nullptr && tempReversed != nullptr) {
        if (tempOriginal->data != tempReversed->data) {
            isPalindrome = false;
            break;
        }
        tempOriginal = tempOriginal->next;
        tempReversed = tempReversed->next;
    }

    // Step 3: Print the result
    cout << (isPalindrome ? "YES" : "NO") << endl;

    // Clean up the reversed list
    while (reversedHead != nullptr) {
        Node* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }
}

// Function to create a linked list (for demonstration)
Node* createList(int arr[], int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        if (head == nullptr) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Main function
int main() {
    // Create a linked list for testing
    int arr[] = {1, 2, 3, 2, 1};
    Node* head = createList(arr, 5);

    // Check if the list is a palindrome
    isPalindrome(head);

    return 0;
}

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse a linked list and calculate length
Node* reverseListAndCalculateLength(Node* head, int& length) {
    Node* prev = nullptr;
    Node* curr = head;
    length = 0; // Initialize length

    while (curr != nullptr) {
        Node* newNode = new Node(curr->data); // Create a new node with current data
        newNode->next = prev; // Add it to the reversed list
        prev = newNode;
        curr = curr->next;
        length++; // Increment length
    }
    return prev; // Return the head of the reversed list
}

// Function to check if the linked list is a palindrome and print its length
void isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        cout << "YES" << endl;
        cout << "Length: 1" << endl;
        return;
    }

    // Step 1: Reverse the list and calculate the length
    int length = 0;
    Node* reversedHead = reverseListAndCalculateLength(head, length);

    // Step 2: Compare the original list with the reversed copy
    Node* tempOriginal = head;
    Node* tempReversed = reversedHead;

    bool isPalindrome = true;
    while (tempOriginal != nullptr && tempReversed != nullptr) {
        if (tempOriginal->data != tempReversed->data) {
            isPalindrome = false;
            break;
        }
        tempOriginal = tempOriginal->next;
        tempReversed = tempReversed->next;
    }

    // Step 3: Print the result and length
    cout << (isPalindrome ? "YES" : "NO") << endl;
    cout << "Length: " << length << endl;

    // Clean up the reversed list
    while (reversedHead != nullptr) {
        Node* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }
}

// Function to create a linked list (for demonstration)
Node* createList(int arr[], int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        if (head == nullptr) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Main function
int main() {
    // Create a linked list for testing
    int arr[] = {1, 2, 3, 2, 1};
    Node* head = createList(arr, 5);

    // Check if the list is a palindrome and print its length
    isPalindrome(head);

    return 0;
}

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to check if the linked list is a palindrome
bool isPalindrome(Node* head) {
    if (!head || !head->next) return true; // Empty or single-node list is a palindrome

    // Step 1: Find the length of the linked list
    int length = 0;
    Node* temp = head;
    while (temp) {
        length++;
        temp = temp->next;
    }

    // Step 2: Reverse the first half of the list
    Node *prev = nullptr, *current = head, *next = nullptr;
    for (int i = 0; i < length / 2; i++) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Step 3: Handle the second half of the list
    Node* secondHalf = (length % 2 == 0) ? current : current->next;
    Node* firstHalf = prev;

    // Step 4: Compare the two halves
    bool palindrome = true;
    while (firstHalf && secondHalf) {
        if (firstHalf->data != secondHalf->data) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // (Optional) Restore the original list structure
    current = prev;
    prev = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return palindrome;
}

// Function to print "YES" or "NO" if the list is a palindrome
void checkPalindrome(Node* head) {
    if (isPalindrome(head)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

// Main function to test the program
int main() {
    // Manually creating the linked list 1 -> 2 -> 3 -> 2 -> 1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    // Check if the list is a palindrome
    checkPalindrome(head); // Should print "YES"

    // Free the allocated memory (optional for demonstration purposes)
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
*/
