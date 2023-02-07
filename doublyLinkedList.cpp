#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};


class doublyLinkedList{
    private:
    Node *header;
    Node *tail;
    int size;

    public:
    doublyLinkedList(){
        header = NULL;
        tail = NULL;
        size = 0;
    }

    ~doublyLinkedList(){
        Node *next = header;

        while(header != NULL){
            next = header->next;
            delete header;
            header = next;
        }
    }

    void prepend(int data);
    void append(int data);
    void insertAt(int pos, int data);
    void deleteHead();
    void deleteTail();
    void deleteAt(int pos);
    void printList();
    int getSize(){
        return size;
    }
};


void doublyLinkedList::prepend(int data){
    Node *n = new Node(data);

    if(header == NULL){
        cout<<"\nList is empty. Creating new node and making it head.";
        header = n;
        tail = n;
    }

    else if(header != NULL){
        n->next = header;
        header->prev = n;
        header = n;
    }
    size++;
    cout<<"\nSize of list is: "<<size;   

}

void doublyLinkedList::append(int data){
    Node *n = new Node(data);

    if(header ==NULL){
        cout<<"List is empty. Creating new node";
        header = n;
        tail = n;
    }

    else if(header != NULL){
        n->prev = tail;
        tail->next = n;
        tail = n;
    }

    size++;
    cout<<"\nSize of list is: "<<size; 
}

void doublyLinkedList::insertAt(int pos, int data){
    if(pos>size+1 || pos<1){
        cout<<"\nInvalid position!";
    }

    else if(pos == 1){
        prepend(data);
    }
    else if(pos == size+1){
        append(data);
    }

    else if(header != NULL){
        Node *n = new Node(data);
        Node* temp = header;

        for(int i = 1; i<pos; i++){
            temp = temp->next;
        }
        n->next = temp;
        n->prev = temp->prev;
        temp->prev->next = n;
        temp->prev = n;

        size++;
        cout<<"Size of list is: "<<size;
    }
}

void doublyLinkedList::deleteHead(){
    if(header ==NULL){
        cout<<"No header!";
    }

    else if (header->next == NULL){
        cout<<"Only one node is present in list!\n"<<endl;
        delete header;
        header = NULL;
        tail = NULL;
    }

    else if(header != NULL){
        Node *temp = header->next;
        delete header;
        header == temp;
    }
    size--;
}

void doublyLinkedList::deleteTail(){
    if(header == NULL){
        cout<<"\nNo node present!";
    }

    else if (header->next == NULL){
        cout<<"\nOnly one node is present!";
        delete header;
        header = NULL;
        tail = NULL;
    }

    else if(header != NULL){
        Node *temp = tail->prev;
        delete tail;
        tail = temp;
    }
    size--;
}

void doublyLinkedList::deleteAt(int pos){
    if(pos>size+1 || pos<1){
        cout<<"\nInvalid position";
    }

    else if (pos == 1){
        deleteHead();
    }

    else if(pos == size){
        deleteTail();
    }

    else if(header != NULL){
        Node *temp = header;
        for(int i=1; i<size; i++){
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;;
        delete temp;
        size--;
    }
}

void doublyLinkedList::printList(){
    Node *temp = header;
    while(temp->next != NULL){
        cout<<"Data: "<<temp->data;
        temp = temp->next;
    }
}


// Driver code