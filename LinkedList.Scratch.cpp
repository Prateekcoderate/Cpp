#include <iostream>
using namespace std;
// Building the LinkedList from scratch using concepts of OOPs

class Node
{ // single/individual node

public:
    int data;   // the value stored in the node
    Node *next; // pointer to the next node

    Node(int val) // constructor for the node
    {
        data = val;
        next = NULL;
    }
};

class LinkedList // group of nodes
{
    Node *head; // head pointer
    Node *tail; // tail pointer

public:
    LinkedList() // constructor
    {
        head = tail = NULL;
    }

    // PUSH-FRONT FUNCTION

    void push_front(int val) // Time Complexity: O(1)
    {
        Node *newNode = new Node(val); // dynamic implementation
        // or Node  newNode(val); static implementation
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    // PUSH_BACK FUNCTION 

    void push_back(int val) // Time Complexity:  O(1) with tail and without tail O(n)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // POP_FRONT FUNCTION

    void pop_front() // Time Complexity: O(1)
    {
        if (head == NULL)
        {
            cout << "Linked LinkedList is Empty.\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;

        delete temp;
    }

    // POP_BACK FUNCTION

    void pop_back() // Time Complexity: O(n) where n represents the sz of the linked LinkedList
    {
        if (head == NULL)
        {
            cout << "linked LinkedList is empty\n";
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    // INSERT FUNCTION

    void insert(int val, int pos)
    { //Time Complexity:  O(1)
        if (pos < 0)
        {
            cout << "invalid position\n";
        }
        if (pos == 0)
        {
            push_front(val);
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Invalid position\n";
            }

            temp = temp->next;
        }
        Node *newNode = new Node(val); //
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // SEARCH FUNCTION

    int search(int key)
    { // Time Complexity: O(n)
        Node *temp = head;
        int idx = 0;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }

            temp = temp->next;
            idx++;
        }

        return -1;
    }
    // Function to print the value of the linked LinkedList
    void printAll() // Time Complexity: O(n)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NUll" << endl;
    }
};

int main()
{
    LinkedList ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.printAll();//call to the print fn to print linkedlist

    return 0;
}