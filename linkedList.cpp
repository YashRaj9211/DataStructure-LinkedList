#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class linkedList
{
private:
    Node *header;
    Node *tail;
    int size;

public:
    linkedList()
    { // decleraring a constructor to initializ the heade and tail to NULL and the size to 0
        header = NULL;
        tail = NULL;
        size = 0;
    }
    ~linkedList()
    { // decleraing the destructor to delete the whole linked list and free up the memory allocation
        Node *temp = header;
        while (header != NULL)
        {
            temp = header->next;
            delete header;
            header = temp;
        }
    }

    // Methods that can be performed on the linked list

    void append(int data);            // to inser data at the end of linked list
    void prepend(int data);           // to insert data at the begining of linked list
    void insertAt(int pos, int data); // to insert data at specific position of the linked list
    void deleteFirst();               // to remove the first(header) node from the linked list
    void deletelast();                // to remove the last(tail) node from linked list
    void deleteAt(int pos);           // to remove the node present at specific node of the linked list
    void printList();                 // to display the  linked list elements
    int getSize()
    {
        return size;
    }
};

void linkedList::printList()
{
    Node *itterator = header;
    while (itterator != NULL)
    {
        cout << " " << itterator->data;
        itterator = itterator->next;
    }
    cout<<endl;
}

void linkedList::append(int data)
{
    Node *n = new Node(data);

    if (header == NULL)
    {
        header = n;
        tail = n;
    }
    else if (header != NULL)
    {
        tail->next = n;
        tail = n;
    }
    size++;
}

void linkedList::prepend(int data)
{
    Node *n = new Node(data);

    if (header == NULL)
    {
        header = n;
        tail = n;
    }

    else if (header != NULL)
    {
        // Node *temp = header;
        n->next = header;
        header = n;
    }
    size++;
}

void linkedList::insertAt(int pos, int data)
{
    if (pos < 1 || pos > size + 1)
    {
        cout << "Invalid position!\nPlease enter a valid position" << endl;
    }

    else if (pos == 1)
    {
        prepend(data);
    }
    else if (pos == size + 1)
    {
        append(data);
    }
    else
    {
        Node *n = new Node(data);
        Node *prev;
        Node *curr = header;

        for (int i = 1; i < pos; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = n;
        n->next = curr;
        size++;
    }
}

void linkedList::deleteFirst()
{
    if (header == NULL)
    {
        cout << "List is empty!" << endl;
    }
    else if (header == tail)
    {
        delete header;
        header = NULL;
        tail = NULL;
        size--;
    }
    else
    {
        Node *temp = header->next;
        delete header;
        header = temp;
        size--;
    }
}

void linkedList::deletelast()
{
    if (header == NULL)
    {
        cout << "List is empty!" << endl;
    }
    else if (header == tail)
    {
        deleteFirst();
    }
    else if(header != NULL)
    {
        Node *curr = header;
        Node *prev;

        while (curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }

        tail = prev;
        prev->next = NULL;
        delete curr;
        size--;
    }
}

void linkedList::deleteAt(int pos)
{
    if (pos < 1 || pos > size)
    {
        cout << "Invalid position" << endl;
    }

    else if (pos == 1)
    {
        deleteFirst();
    }
    else if (pos == size)
    {
        deletelast();
    }
    else
    {
        Node *curr = header;
        Node *prev;

        for (int i = 1; i < pos; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        size--;
    }
}

int main()
{
    linkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.prepend(0);
    list.insertAt(3, 10);
    list.printList();
    list.deleteAt(3);
    list.printList();
    list.deleteFirst();
    list.printList();
    list.deletelast();
    list.printList();


  // calling destructor explicitly even thougbh it is not necessary
    return 0;
}