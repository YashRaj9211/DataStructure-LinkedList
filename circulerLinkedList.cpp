#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class circularLinkedList
{
private:
    Node *header;
    int size;

public:
    circularLinkedList()
    {
        header = NULL;
        size = 0;
    }

    void append(int data);
    void prepend(int data);
    void removeNodeAt(int pos);
    void printList();
    int getSize()
    {
        return size;
    }
};

void circularLinkedList::append(int data)
{
    Node *n = new Node(data);

    if (header == NULL)
    {
        header = n;
        n->next = header;
    }

    else if (header != NULL)
    {
        Node *temp = header;

        while (temp->next != header)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->next = header;
    }

    size++;
}

void circularLinkedList::prepend(int data)
{
    Node *n = new Node(data);

    if (header == NULL)
    {
        header = n;
        n->next = header;
    }

    else if (header != NULL)
    {
        Node *temp = header;
        while (temp->next != header)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->next = header;
        header = n;
    }
    size++;
}



void circularLinkedList::removeNodeAt(int pos)
{
    if (pos < 1 || pos > size)
    {
        cout << "Invalid postion" << endl;
    }

    else if (header != NULL)
    {
        Node *curr = header;
        Node *prev;
        for (int i = 0; i < pos - 1; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        size--;
    }
    cout << endl;
}

void circularLinkedList::printList()
{
    Node *itter = header;
    for (int i = 0; i < size; i++)
    {
        cout << itter->data << "-->";
        itter = itter->next;
    }
    cout << endl;
}

// Driver Code

int main()
{
    circularLinkedList cl;
    cl.append(1);
    cl.append(2);
    cl.append(3);
    cl.append(4);
    cl.printList();
    cl.prepend(0);
    cl.printList();
    cl.printList();
    cl.removeNodeAt(2);
    cl.printList();

    return 0;
}