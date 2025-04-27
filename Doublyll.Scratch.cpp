#include <iostream>

using namespace std;

class Node{
    public:

    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=prev=NULL;
    }
};

class DoublyLinkedList{
    Node* head;
    Node* tail;
public:

DoublyLinkedList(){
    head = tail = NULL;
}
//push_front function
 void push_front(int val){
    Node*newNode = new Node(val);
    if (head==NULL)
    {
        head = tail = newNode;
    }else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    
    
 }

 //push_back function
 void push_back(int val){
    Node * newNode = new Node(val);
    if(head == NULL){
        head = tail = NULL;
    }else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    
 }
 //pop_back function in linked list
 void pop_front(){
    if(head == NULL){
        cout<<"Doubly Linked-List is Empty\n";
    }
  Node*temp = head;
   head = head->next;
   if(head != NULL){
    head->prev = NULL;

   }
   temp ->next = NULL;
   delete temp;
 }

 //pop_back function
 void pop_back(){
    if(head == NULL){
        cout<<"The doubly linked list is empty\n";
        return;
    }
    Node* temp = tail;
    tail = tail->prev;

    if(tail != NULL){ //corner case for preventing: when Doubly ll have single node
        tail->next = NULL;
    }
    
   
    temp->prev = NULL;
    
    delete temp;
 }
 //Print Function used to print the Linked List
 void printAll(){
   Node*temp = head;
   while(temp != NULL){
    cout<<temp->data<<" <=> ";
    temp = temp->next;

   }
   cout<<"NULL\n";
 }
};

int main(){
     DoublyLinkedList dll;
     dll.push_front(3);
     dll.push_front(2);
     dll.push_front(1);

     dll.push_back(5);

     dll.pop_front();//removes the 1
     dll.pop_front();//removes 2
     dll.pop_front();//removes 3
     

     dll.pop_back();
     dll.printAll();

    return 0;
}