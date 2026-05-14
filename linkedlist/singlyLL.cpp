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
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    // methods
    /*
    CRUD:
    C -> Create || insert
    R -> Read || display
    U -> Update || update
    D -> Delete || delete
    */
    void insert(int data);
    void insertAtFront(int data);
    void deleteNode(int key);
    void updateNode(int data, int newVal);
    void display();

    // problems
    void reverse();
    void middleNode();
    void removeDuplicates();
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

    // Check if node was not  found
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

void LinkedList::updateNode(int key, int newVal)
{

    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }

    // if key is not the first node
    Node *temp = head;

    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    // if key not found
    if (temp == NULL)
    {
        cout << "Key Not Found!" << endl;
        return;
    }

    temp->data = newVal;
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

void LinkedList::reverse()
{
    // Handle empty list
    if (head == NULL)
    {
        return;
    }
    // Three pointers approach
    Node *prev = NULL;
    Node *current = head;

    while (current != NULL)
    {
        // Store next node BEFORE reversing
        Node *next = current->next;

        // Reverse the link
        current->next = prev;

        // Move pointers forward
        prev = current;
        current = next;
    }

    // Update head to new first node
    head = prev;
}

void LinkedList::middleNode()
{
    if (head == NULL)
    {
        cout << "Linked List is empty!" << endl;
        return;
    }

    Node *slow;
    Node *fast;

    slow = fast = head;

    while (fast != NULL && fast->next != NULL)
    {

        // 1 step for the slow pointer
        // and 2 steps for the fast pointer
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle Node :" << slow->data << endl;
}

void LinkedList::removeDuplicates(){
    if (head == NULL)
    {
        return;
    }

    Node *current = head;
    while (current != NULL)
    {
        Node *runner = current;
        while (runner->next != NULL)
        {
            if (runner->next->data == current->data)
            {
                Node *duplicate = runner->next;
                runner->next = duplicate->next;
                delete duplicate;
            }
            else
            {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

int main()
{

    LinkedList ll;

    // ll.display();

    ll.insert(12);
    ll.insert(32);
    ll.insert(17);
    ll.insert(19);
    ll.insert(32);
    ll.insert(17);
    // ll.insertAtFront(10);
    cout << "Before removeDuplicates: ";
    ll.display();
    cout << endl;

    ll.removeDuplicates();
    cout << "After removeDuplicates: ";
    ll.display();
    cout << endl;

    // cout << "Before Deletion :" << endl;
    // ll.display();

    // cout << endl;

    // ll.deleteNode(22);

    // cout << "After Deletion :" << endl;
    // ll.display();

    // cout << endl;

    // cout << "Before Updation :" << endl;
    // ll.display();
    // cout << endl;
    // ll.updateNode(112, 18);
    // cout << "after Updation :" << endl;
    // ll.display();

    // cout << "Before Reverse :" << endl;
    // ll.display();
    // cout << endl;

    // ll.reverse();

    // cout << "After Reverse :" << endl;
    // ll.display();
    // cout << endl;

    ll.middleNode();

    return 0;
}