/* Print the size of a linked list.
Input:34->12->55->42->11
Output:5*/
#include using namespace std;
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
int getSize(Node* head){
int size = 0;
Node* current = head;
while(current !=nullptr){
size++;
current=current->next;
}
return size;
}
int main(){
Node* head = createNode(34);
head->next = createNode(12);
head->next->next = createNode(55);
head->next->next->next = createNode(42);
cout<<"Size of the linked list: "< return 0;
}



/*Given the head of a linked list, print the value of the middle node.
Input:34->12->55->42->11
Output:55
Input:12->8->65->10
Output:8 */
#include using namespace std;
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
void printMiddle(Node* head){
if(head == nullptr){
cout<<" The list os Empty."< return;
}
Node* slow = head;
Node* fast = head;
while(fast != nullptr&& fast->next != nullptr){
slow = slow->next;
fast = fast->next->next;
}
cout<<"Middle Node Value: "<data< }
int main(){
Node* head1 = createNode(34);
head1->next = createNode(12);
head1->next->next = createNode(55);
head1->next->next->next=createNode(42);
head1->next->next->next->next=createNode(11);
cout<<"Input: 34->12->55->42->11 "< printMiddle(head1);
Node* current;
while(head1!=nullptr){
current = head1;
head1 = head1->next;
delete current;
}
return 0;
}




/*Print the number of occurrences of a given number in a linked list.
Input: 1->2->1->2->1->3->1, num = 1
Output: 4 */
#include using namespace std;
struct Node{
int data;
Node* next;
};
Node* createNode(int data){
Node* newNode = new Node();
newNode->data= data;
newNode->next=nullptr;
return newNode;
}
int countOccurrences(Node* head,int num){
int count =0;
Node* current = head;
while(current!=nullptr){
if(current->data==num){
count++;
}
current = current->next;
}
return count;
}
int main(){
Node* head=createNode(1);
head->next=createNode(2);
head->next->next=createNode(1);
head->next->next->next=createNode(2);
head->next->next->next->next=createNode(1);
head->next->next->next->next->next=createNode(3);
head->next->next->next->next->next->next=createNode(1);
int num = 1;
cout<<"Input: 1->2->1->2->1->3->1,Num = "< cout<<"Number of Occurrences: "< Node* current = head;
while(current!= nullptr){
Node* temp = current;
current = current->next;
delete temp;
}
return 0;
}


/*Given a sorted linked list, insert a number so that after insertion, it remains
sorted.
Input Output
1->4->6->7->9->11, num = 3 1->3->4->6->7->9->11*/
#include using namespace std;
struct Node{
int data;
Node* next;
Node(int value) : data(value),next(nullptr){}
};
Node* insertSort(Node* head,int num){
Node* newNode = new Node(num);
if(!head||numdata){
newNode->next = head;
return newNode;
}
Node* current = head;
while(current->next&&current->next->data current=current->next;
}
newNode->next = current->next;
current->next=newNode;
return head;
}
void printList(Node* head){
Node* temp=head;
while(temp){
cout<data;
if(temp->next)
cout<<"->";
temp= temp->next;
}
cout< }
int main(){
Node* head=new Node(1);
head->next=new Node(4);
head->next->next=new Node(6);
head->next->next->next=new Node(7);
head->next->next->next->next=new Node(9);
head->next->next->next->next->next=new Node(11);
cout<<"Original List: ";
printList(head);
int num=15;
cout<<"Insertion:"< head=ins
