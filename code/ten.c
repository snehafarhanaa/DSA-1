#include<iostream>
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

int calculatelength(Node* slow)
{
    Node* prev = slow;
    int a=0;
    do
    {
        prev= prev->link;
        a++;
    }
    while(prev!=slow);
    return a;
}
int findCycle(Node* head)
{

    Node* slow = head;
    Node* fast = head;


    while (fast != nullptr && fast->link != nullptr)
    {
        slow = slow->link;
        fast = fast->link->link;

        if (slow == fast)
        {
            return calculatelength(slow);
        }
    }
    return 0;
}
int main()
{

    Node* head= new Node(3);
    Node* temp1 = new Node(2);
    Node* temp2 = new Node(0);
    Node* temp3 = new Node(4);
    Node* temp4 = new Node(6);
    Node* temp5 = new Node(1);
    Node* temp6 = new Node(7);


    head->link=temp1;
    temp1->link=temp2;
    temp2->link=temp3;
    temp3->link=temp4;
    temp4->link=temp5;
    temp5->link=temp2;

    cout<<findCycle(head)<<endl;
}
