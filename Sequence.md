# Lab 1 - Linked List Implementation

> *22 November, 2021*

> Devansh Das (317256)

## Summary

The code contains 2 different classes:

The Node class is used to create a node for the linked list & contains Key & Value attributes for the node in addition to a pointer to the next node.

The Sequence class is a template class that implements a singly linked list data structure consisting of the defined Node class & holds the front and back pointers along with the size of the linked list.

## Description of Public Methods

### Node Class

``` c++
Node();
//Default Constructor for the Node class. Sets the next pointer to nullptr.
```

``` c++
Node(const Node<Key, Info>&, Node<Key, Info>* nextNode = nullptr);
//Copy Constructor for the Node class. Sets the next pointer to nullptr unless specified.
```

``` c++
Node(const Key&, const Info&, Node<Key, Info>* nextNode = nullptr);
//Contructor for the Node class with a parameter for the key and value of the node. Sets the next pointer to nullptr unless specified.
```

``` c++
void setNext(Node<Key, Info>*);
//Sets the next pointer to the specified node.
```

``` c++
void setKey(const Key&);
//Sets the key of the node to the specified key.
```

``` c++
oid setInfo(const Info&);
//Sets the info of the node to the specified info.
```

``` c++
Node<Key, Info>* getNext() const;
//Returns the next pointer of the node.
```

``` c++
const Key& getKey() const;
//Returns the key of the node.
```

``` c++
const Info& getInfo() const;
//Returns the info of the node.
```

``` c++
Node<Key, Info>& operator=(const Node<Key, Info>&);
//Overloads the assignment operator for the Node class. Sets the Key and Info of the node to the specified node & sets the next pointer to nullptr.
```

``` c++
bool operator==(Node<Key, Info>&);
//Overloads the equality operator for the Node class. Returns true if the Key and Info of the node are equal to the specified node.
```

``` c++
bool operator!=(Node<Key, Info>&);
//Overloads the inequality operator for the Node class. Returns true if the Key and Info of the node are not equal to the specified node.
```

``` c++
friend std::ostream& operator<<(std::ostream&, const Node<Key, Info>&);
//Overloads the insertion operator for the Node class. Returns the Key and Info of the node.
```

### Sequence Class

``` c++
Sequence();
//Default Constructor for the Sequence class. Sets the front and back pointers to nullptr & sets the size to 0.
```

``` c++
Sequence(const Sequence<Key, Info>&);
//Copy Constructor for the Sequence class.
```

``` c++
~Sequence();
//Destructor for the Sequence class. Deletes all nodes in the linked list.
```

``` c++
unsigned int getSize() const;
//Returns the size of the linked list.
```

``` c++
Node<Key, Info> getFrontNode() const;
//Returns the front node of the linked list.
```

``` c++
Node<Key, Info> getBackNode() const;
//Returns the back node of the linked list.
```

``` c++
bool pushBack(const Key&, const Info&);
bool pushBack(const Node<Key, Info>&);
//Adds a node to the back of the linked list. Returns true if the node was added successfully. The two overloads of the function are used to add a node with a specified key and info or with a specified node.
```

``` c++
bool pushFront(const Key&, const Info&);
bool pushFront(const Node<Key, Info>&);
//Adds a node to the front of the linked list. Returns true if the node was added successfully. The two overloads of the function are used to add a node with a specified key and info or with a specified node.
```

``` c++
bool insertAfter(const Key&, const Info&, const Key&, unsigned int occurance = 1);
//Inserts a node after node with specified Key & Info after node with specified Key and first occurance unless specified. Returns true if the node was added successfully.
```

``` c++
bool insertBefore(const Key&, const Info&, const Key&, unsigned int occurance = 1);
//Inserts a node before node with specified Key & Info before node with specified Key and first occurance unless specified. Returns true if the node was added successfully.
```

``` c++
bool swap(const Key&, const Key&, unsigned int occuranceFirstNode = 1, unsigned int occuranceSecondNode = 1);
//Swaps nodes with specified Keys on the first occurances unless specified. Returns true if the nodes were swapped successfully.
```

``` c++
bool remove(const Key&, unsigned int occurance = 1);
//Removes the node with specified Key and first occurance unless specified. Returns true if the node was removed successfully.
```

``` c++
bool popFront();
//Removes the front node of the linked list. Returns true if the node was removed successfully.
```

``` c++
bool popBack();
//Removes the back node of the linked list. Returns true if the node was removed successfully.
```

``` c++
bool clear();
//Removes all nodes from the linked list. Returns true if the nodes were removed successfully.
```

``` c++
bool isEmpty() const;
//Returns true if the linked list is empty.
```

``` c++
unsigned int occuranceNumber(const Key&) const;
//Returns the number of occurances of the node with specified Key.
```

``` c++
bool includes(const Key&, const Info&, unsigned int occurance = 1) const;
bool includes(const Node<Key, Info>&, unsigned int occurance = 1) const;
//Returns true if the linked list includes the node with specified Key and Info on the first occurance unless specified. The two overloads of the function are used to check if the linked list includes the node with specified Key and Info or with a specified node.
```

``` c++
bool getNodeInfo(Info&, const Key&, unsigned int occurance = 1) const;
//Returns the Info of the node with specified Key on the first occurance unless specified.
```

``` c++
bool getNodeInfoIndex(Info&, unsigned int, unsigned int occurance = 1);
//Returns the Info of the node with specified Index.
```

``` c++
Sequence<Key, Info>& operator=(const Sequence<Key, Info>&) const;
//Overloads the assignment operator for the Sequence class.
```

``` c++
Sequence<Key, Info>& operator+=(const Sequence<Key, Info>&);
//Overloads the addition assignment operator for the Sequence class.
```

``` c++
Sequence<Key, Info> operator+(const Sequence<Key, Info>&);
//Overloads the addition operator for the Sequence class. Returns a new Sequence with the nodes of the two sequences.
```

``` c++
bool operator==(const Sequence<Key, Info>&);
//Overloads the equality operator for the Sequence class. Returns true if the Key and Info of all the nodes are equal & in the same order.
```

``` c++
bool operator!=(const Sequence<Key, Info>&);
//Overloads the inequality operator for the Sequence class. Returns true if the Key and Info of all the nodes are not equal or not in the same order.
```

``` c++
friend std::ostream& operator<<(std::ostream&, const Sequence<Key, Info>&);
//Overloads the insertion operator for the Sequence class. Returns the Key and Info of all the nodes.
```

## Testing

Unit tests for most member functions present in the Node & Sequence classes have been implemented in the Sequence_test.cpp file.