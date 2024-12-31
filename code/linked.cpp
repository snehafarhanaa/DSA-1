#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* link;

    Node(int data)
    {
        this->data = data;
        this->link = nullptr;
    }
};

Node* head = nullptr;

void insertFirst(int data)
{
    Node* newNode = new Node(data);
    newNode->link = head;
    head = newNode;
}

void insertLast(int data)
{
    Node* newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->link != nullptr)
    {
        current = current->link;
    }
    current->link = newNode;
}

void insertAt(int data, int position)
{
    if (position < 0)
    {
        cout << "Invalid position." << endl;
        return;
    }
    else if (position == 0)
    {
        insertFirst(data);
        return;
    }
    else
    {
        Node* newNode = new Node(data);
        Node* current = head;
        int currentPosition = 0;
        while (current != nullptr && currentPosition < position - 1)
        {
            current = current->link;
            currentPosition++;
        }
        if (current == nullptr)
        {
            cout << "Position exceeds the length of the list. Node not inserted." << endl;
            delete newNode;
            return;
        }
        else
        {
            newNode->link = current->link;
            current->link = newNode;
        }
    }
}

void deleteFirst()
{
    if (head == nullptr)
    {
        cout << "The list is empty. Nothing to delete." << endl;
        return;
    }
    Node* temp = head;
    head = head->link;
    delete temp;
}

void deleteLast()
{
    if (head == nullptr)
    {
        cout << "The list is empty. Nothing to delete." << endl;
        return;
    }
    else if (head->link == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node* current = head;
    while (current->link->link != nullptr)
    {
        current = current->link;
    }
    delete current->link;
    current->link = nullptr;
}

void deleteItem(int item)
{
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr)
    {
        if (current->data == item)
        {
            if (prev != nullptr)
            {
                prev->link = current->link;
            }
            else
            {
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

int searchItem(int item)
{
    Node* current = head;
    int position = 0;
    while (current != nullptr)
    {
        if (current->data == item)
        {
            return position;
        }
        current = current->link;
        position++;
    }
    return -1;
}

void printList()
{
    Node* current = head;
    cout << "Linked list: ";
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->link;
    }
    cout << "NULL" << endl;
}
void count()
{
    Node* prev= head;
    int a=0;
    while(prev!=nullptr)
    {
        a++;
        prev=prev->link;
    }
    cout <<"number of link list : " <<a<<endl;
}
void countItem(int item)
{
    Node* prev= head;
    int a=0;
    while(prev!=nullptr)
    {
        if(prev->data==item)
        {
            a++;

        }
        prev=prev->link;
    }
    cout <<"number of link list : " <<a<<endl;
}
void middleValue()
{
    Node* fast= head->link;
    Node* slow= head;
    while(fast!=nullptr &&fast->link!=nullptr)
    {
        slow=slow->link;
        fast= fast->link->link;
    }
    cout <<"middle value : " <<slow->data<<endl;
}
void insertINsort(int item)
{
    Node* newNode= new Node(item);
    Node* prev = head;
    while(prev->link!=nullptr && prev->link->data<item)
    {
        prev= prev->link;
    }
    newNode->link=prev->link;
    prev->link= newNode;
}
void DeleteEvenALL()
{
    while(head!=nullptr &&head->data%2==0)
    {
        Node* temp =head;
        head=head->link;
        delete temp;
    }
    Node* current = head;
    while (current != nullptr && current->link != nullptr)
    {
        if (current->link->data % 2 == 0)
        {
            Node* temp = current->link;
            current->link = current->link->link;
            delete temp;
        }
        else
        {
            current = current->link;
        }
    }

}
void reverseList()
{
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }

    head = prev;
}
void rotateLeft(int k)
{
    if (head == nullptr || k == 0)
    {
        return;
    }


    Node* current = head;
    int length = 1;
    while (current->link != nullptr)
    {
        current = current->link;
        length++;
    }

    current->link = head;


    k = k % length;
    if (k == 0)
    {
        current->link = nullptr;
        return;
    }


    Node* newTail = head;
    for (int i = 1; i < length - k; ++i)
    {
        newTail = newTail->link;
    }


    head = newTail->link;
    newTail->link = nullptr;

}
bool isPalindrome()
{
    if (head == nullptr || head->link == nullptr)
    {
        return true;  // Empty list or single node is a palindrome
    }

    // Step 1: Find the middle of the list using slow and fast pointers
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->link != nullptr)
    {
        slow = slow->link;
        fast = fast->link->link;
    }

    // Step 2: Reverse the second half of the list
    Node* prev = nullptr;
    Node* current = slow;
    Node* next = nullptr;
    while (current != nullptr)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }

    // Step 3: Compare the first half and the reversed second half
    Node* firstHalf = head;
    Node* secondHalf = prev;  // 'prev' now points to the reversed second half

    while (secondHalf != nullptr)
    {
        if (firstHalf->data != secondHalf->data)
        {
            return false;  // Not a palindrome if values don't match
        }
        firstHalf = firstHalf->link;
        secondHalf = secondHalf->link;
    }

    return true;
}
bool hasCycle()
{
    if (head == nullptr) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->link != nullptr)
    {
        slow = slow->link;           // Move slow pointer by 1 step
        fast = fast->link->link;     // Move fast pointer by 2 steps

        if (slow == fast)
        {
            return true;  // Cycle detected
        }
    }

    return false;  // No cycle
}

int main()
{
    insertFirst(1);
    insertFirst(3);
    insertFirst(1);

    printList();
    countItem(3);
    middleValue();

    rotateLeft(3);
    printList();
    cout <<isPalindrome()<<endl;
    cout <<hasCycle()<<endl;
}
