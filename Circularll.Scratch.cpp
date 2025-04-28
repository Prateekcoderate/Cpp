//here we're implementing the linked list from the scratch
#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node*next;
Node(int val){
    data = val;
    next = NULL;
}

};
class CircularLinkedList{
Node* head;
Node* tail;
public:
CircularLinkedList(){
    head = tail = NULL; 
}

//creating a insert at the head function in Circular-LL
void insertAtHead(int val){
    Node*newNode= new Node(val);
    if(tail == NULL){
        head = tail = newNode;
        tail->next = head;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    
}

// insert at the tail
void insertAtTail(int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = tail = newNode;
        tail->next = head;
    }else
    {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
    
}
//delete at the Head Function
void deleteAtHead(){
  
    //case-1  cll doesn't have any node
    if(head == NULL){
        cout<<"Circular linked list is empty\n";
    return;}
    //case-2  cll has single node
    else if(head == tail){
            delete head;
            head = tail = NULL;
        }
        //case-3 Cll has 2 or more than 2 nodes
        else
        {  Node* temp =head;
            head = head->next;
            tail->next = head;
            temp ->next = NULL;
            delete temp;
        }
        
    }
    
    //delete at tail
    void deleteAtTail(){
        if(head==NULL) return;
        else if (head==tail)
        {
            delete head;
            head=tail=NULL;
        }else
        {
            Node* temp = tail;
            Node* prev = head;
            while (prev->next !=tail)
            {
                prev = prev->next;
                
            }
            tail = prev;
                
                tail->next = head;
                temp->next = NULL;
                delete temp;
            
        }
        
        
    }

void print(){
    if(head ==  NULL) return;
    cout<<head->data<<"->";
    Node*temp =head->next;
    while (temp != head)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}
};

int main(){
    CircularLinkedList cll;   
    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtHead(3);

    cll.insertAtTail(6);

    cll.print();

    cll.deleteAtHead();

    cll.print();

    cll.deleteAtTail();
    cll.print();
    return 0;
}