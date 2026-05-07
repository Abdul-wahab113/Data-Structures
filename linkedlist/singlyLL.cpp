#include <iostream>
using namespace std;

class Node
{
public:
    // data members
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // methods
    void insert(int data);
    void insertAtFront(int data);
    void deleteNode(int key);
    void display();
};

void LinkedList::insert(int data)
{

    // if linked list is empty
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }

    // if linked list already has some node

    // iterate all the nodes in the list and exit when last node reached
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // chaning step
    temp->next = new Node(data);
    // cout << temp->next << endl;
}

void LinkedList::insertAtFront(int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }

    Node *newNode = new Node(data);

    // insert newnode at front
    newNode->next = head;
    // update head
    head = newNode;
}

void LinkedList::deleteNode(int key)
{

    // if LL is empty
    if (head == NULL)
    {
        cout << "Linked List is empty!" << endl;
        return;
    }

    // if linked list has only one node
    if (head->data == key)
    {
        head = head->next;
        return;
    }

    // if ll has more nodes
    Node *temp = head;
    Node *prevTemp = head;

    while (temp != NULL && temp->data != key)
    {
        prevTemp = temp;
        temp = temp->next;
    }

    // Check if node was found
    if (temp == NULL)
    {
        cout << "The Given Target: " << key << " NOT FOUND!" << endl;
        return;
    }

    prevTemp->next = temp->next;
    delete temp;

    // cout << "previous Node: " << prevTemp->data << endl;
    // cout << "Target Node: " << temp->data << endl;
}

void LinkedList::display()
{

    if (head == NULL)
    {
        cout << "Linked List Is Empty!" << endl;
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
};

int main()
{

    LinkedList ll;

    // ll.display();

    ll.insert(12);
    ll.insert(32);
    ll.insert(17);
    ll.insert(19);
    ll.insertAtFront(10);

    cout << "Before Deletion :" << endl;
    ll.display();

    cout << endl;

    ll.deleteNode(22);

    cout << "After Deletion :" << endl;
    ll.display();

    cout << endl;

    return 0;
}