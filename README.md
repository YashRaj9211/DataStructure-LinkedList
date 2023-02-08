
# Linked Lists




## Singly Linked List
This code is an implementation of a linked list in C++. A linked list is a data structure in which elements are stored as nodes, where each node points to the next node in the list. The code defines a linked list **class linkedList** that has the following methods:

**append**(int data): Inserts a new node with value data at the end of the linked list.

**prepend**(int data): Inserts a new node with value data at the start of the linked list.

**insertAt**(int pos, int data): Inserts a new node with value data at the position pos of the linked list.

**deleteFirst**(): Removes the first node of the linked list.

deletelast(): Removes the last node of the linked list.

**deleteAt**(int pos): Removes the node at position pos of the linked list.

**printList**(): Displays all elements of the linked list.

**getSize**(): Returns the number of nodes in the linked list.

Each node of the linked list is represented by an object of the `Node` class, which has two data members: data that stores the value of the node, and next that stores a pointer to the next node in the list.

The linked list is implemented using dynamic memory allocation, where `new` nodes are created using the new operator and removed using the delete operator. The `linkedList` class also has a destructor, which is called when an object of the class goes out of scope and deletes all nodes in the linked list, freeing up the memory allocated to them.




### Append method on Singly Linked List

```C++
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
```
The function void `linkedList::append(int data)` is a member function of the `linkedList` class. This function adds a new node to the end of a linked list and updates the tail pointer of the list.

The function starts by creating a new node n using `Node *n = new Node(data);`. Node is the class of the nodes in the linked list, and `new Node(data)` creates a new node with data as its value.

Next, the function checks if the header of the linked list is NULL using `if (header == NULL)`. If the header is NULL, then the linked list is empty, and the new node becomes both the header and tail of the linked list.

If the header is not NULL, the function adds the new node to the end of the list. The next pointer of the current tail node is set to the new node using `tail->next = n;`. Then the tail pointer is updated to the new node using `tail = n;`.

Finally, the size of the linked list is incremented by one using `size++;`.

### Prepend method on Singly Linked List

```C++
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
```

The function `void linkedList::prepend(int data)` is a member function of the linkedList class in C++, which adds a new node containing the given integer `data` to the beginning of the linked list. The function performs the following steps:

A new node `n` is created using `Node *n = new Node(data)`, where Node is a class representing a node in the linked list and data is the integer value that the new node will contain.

If the linked list is empty, i.e. `if header == NULL`, then header and tail pointers are both set to n, which is the only node in the linked list.

If the linked list is not empty, then `n->next` is set to header, and header is updated to n. This effectively makes `n` the new first node in the linked list and shifts all other nodes one position to the right.

Finally, the size of the linked list is increased by 1 using `size++`.

This function allows for inserting a new node at the beginning of the linked list in `O(1)` time complexity, which is efficient compared to inserting at the end of the linked list.


### Prepend method on Singly Linked List

```C++
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
```

This code is a member function of a linked list class in C++. The function inserts a new node with the given `data` at a specified position in the linked list.In the function `if (pos < 1 || pos > size + 1)` this line checks if the specified position `pos` checks if the specified position is valid, i.e., between `1` and the size of the linked `list + 1`. If the position is invalid, it prints an error message. If the position is 1, it calls the `prepend` function to add the node to the beginning of the linked list. If the position is `size + 1`, it calls the `append` function to add the node to the end of the linked list.

Else if the function is anywhere in between then it creates a new node, `Node *n = new Node(data)`, declares a Node object pointer `prev`  (`Node *prev`) declares another Node object pointer `curr` pointing to `header` (`Node *curr = header`)
```C++
for (int i = 1; i < pos; i++)
        {
            prev = curr;
            curr = curr->next;
}
```
This line starts a `for` loop that will run `pos - 1` times. `prev` and `curr` will move along the linked list so that `curr` will be at the specified position `pos` and `prev` will be at the node immediately before `curr`

`prev->next = n` this line updates the `next` pointer of `prev` to point to the new node `n`.

`n->next = curr` updates the `next` pointer of `n` to point to `curr`.
In this manner `prev` points to `n` and `n` points to `curr` which is desired as now `n` is inserted in between list.
`size++` increments the size of the linked list by 1.

### Deleting header of Singly Linked List

```C++
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
```

This function `deleteFirst()` deletes the first node i.e. `header` of the linked list.

First, it checks if the list is empty by checking if the header node is `NULL`. If the list is empty, it prints a message "List is empty!".

If the list is not empty, it checks if the `header` node is also the `tail` node, meaning that there's *only one node* in the list. In this case, it deletes the node by calling `delete header`. Then, it sets the `header` and `tail` pointers to `NULL` and decrements the `size` of the list.

If there are more than one nodes in the list, the function creates a temporary `Node` pointer `temp` pointing to the next node after `header`, then deletes `header` and updates `header` to point to `temp`. The size of the list is decremented by 1.


### Deleting tail of Singly Linked List

```C++
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
```

This deletes the tail of the linked list.The code checks if the list is empty by checking if header is NULL. If the list is empty, it prints a message "List is empty!". If the list has only one element, it calls the `deleteFirst` function to delete the only node in the list.

Otherwise, if the list has more than one node, the code sets two pointers, `curr` and `prev`, to `header` and `NULL` respectively, and uses a `while` loop to traverse the list. The loop continues until `curr->next` is `NULL`, which indicates that `curr` is the last node(`tail`) in the list. At each iteration, `prev` is set to `curr`, and `curr` is set to `curr->next`.

Once the loop has finished, `prev` points to the second-to-last node, `curr` points to the last node, and `tail` is set to `prev`. The `next` pointer of `prev` is set to `NULL`, indicating that `prev` is the new last node. Finally, the `delete` operator is called to `delete curr`, and the size of the list is decremented by 1.

### Deleting tail of Singly Linked List

```C++
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
```

Function delets the node from between the linked list. It check if the specified position `pos` is valid or not: If the specified position is less than 1 or greater than the size of the list, then it returns "Invalid position".

If the specified postion is 1 then it calls the `deleteFirst`. If postion is equal to the size of list then it calls the `deletelast`. If the specified position is not 1 or not equal to the size of the list:

a. Initialize two pointers `curr` and `prev` `curr` pointing to `header`.

b.  Loop through the linked list until the `curr` reaches the specified position. aslo incrimenting the `prev` to `curr` and `curr` to `curr->next`

c. Set the value of `prev->next` to `curr->next` since curr is the node that we need to delete hence the node before the `curr` (`prev`) node is made to point to node after `curr`(`curr->next`)

d. After this curr is deleted `delete curr`.

e. Decrement the size `size--`






        











