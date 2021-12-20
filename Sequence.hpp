#pragma once

#include <iostream>
#include <string>

//Node class of the Linked List
template<typename Key, typename Info>
class Node {
    //Pointer to the next node
    Node<Key, Info>* next;
    //Key value
    Key key;
    //Info value
    Info info;

    public:
        //Constructors & Destructor
        //Default Constructor
        Node();
        //Copy Constructor
        Node(const Node<Key, Info>&, Node<Key, Info>* nextNode = nullptr);
        //Constructor with key and info
        Node(const Key&, const Info&, Node<Key, Info>* nextNode = nullptr);

        //Setters
        //Set the next node
        void setNext(Node<Key, Info>*);
        //Set the Key value
        void setKey(const Key&);
        //Set the Info value
        void setInfo(const Info&);

        //Getters
        //Get the next node
        Node<Key, Info>* getNext() const;
        //Get the Key value
        const Key& getKey() const;
        //Get the Info value
        const Info& getInfo() const;

        //Operator Overloads
        //Assignment Operator
        Node<Key, Info>& operator=(const Node<Key, Info>&);
        //Equality Operator
        bool operator==(Node<Key, Info>&);
        //Inequality Operator
        bool operator!=(Node<Key, Info>&);
        //Insertion Operator
        template<typename K, typename I>
        friend std::ostream& operator<<(std::ostream&, const Node<K, I>&);
};

//Singly Linked List class
template<typename Key, typename Info>
class Sequence {
    //Pointer to the first node
    Node<Key, Info>* front;
    //Pointer to the last node
    Node<Key, Info>* back;
    //Number of nodes in the list
    unsigned int size;

    //Setters
    //Set the size of the list
    void setSize(unsigned int);
    //Set the front node
    void setFront(Node<Key, Info>*);
    //Set the back node
    void setBack(Node<Key, Info>*);

    //Increment the size of the list by specified amount or 1
    void increaseSize(unsigned int increment = 1);

    //Decrement the size of the list by specified amount or 1
    void decreaseSize(unsigned int increment = 1);

    //Get the front node
    Node<Key, Info>* getFront() const;
    //Get the back node
    Node<Key, Info>* getBack() const;

    public:
        //Constructors & Destructor
        //Default Constructor
        Sequence();
        //Copy Constructor
        Sequence(const Sequence<Key, Info>&);
        //Destructor
        ~Sequence();

        //Getters
        //Get the size of the list
        unsigned int getSize() const;
        //Get the front node
        Node<Key, Info> getFrontNode() const;
        //Get the back node
        Node<Key, Info> getBackNode() const;

        //Insertion
        //Insert a node at the back of the list
        bool pushBack(const Key&, const Info&);
        bool pushBack(const Node<Key, Info>&);
        //Insert a node at the front of the list
        bool pushFront(const Key&, const Info&);
        bool pushFront(const Node<Key, Info>&);
        //Insert a node after the specified node
        bool insertAfter(const Key&, const Info&, const Key&, unsigned int occurance = 1);
        //Insert a node before the specified node
        bool insertBefore(const Key&, const Info&, const Key&, unsigned int occurance = 1);
        //Swap nodes
        bool swap(const Key&, const Key&, unsigned int occuranceFirstNode = 1, unsigned int occuranceSecondNode = 1);

        //Removal
        //Remove node with specified key
        bool remove(const Key&, unsigned int occurance = 1);
        //Remove the front node
        bool popFront();
        //Remove the back node
        bool popBack();
        //Remove all nodes in the list
        bool clear();

        //Check if list is empty
        bool isEmpty() const;
        //Get number of occurances of specified key
        unsigned int occuranceNumber(const Key&) const;
        //Get if specified node exists in the list
        bool includes(const Key&, const Info&, unsigned int occurance = 1) const;
        bool includes(const Node<Key, Info>&, unsigned int occurance = 1) const;

        //Get the node with specified key
        bool getNodeInfo(Info&, const Key&, unsigned int occurance = 1);
        bool getNodeInfoIndex(Info&, unsigned int);

        //Operator Overloads
        //Assignment Operator
        Sequence<Key, Info>& operator=(const Sequence<Key, Info>&) const;
        //Addition assignment operator
        Sequence<Key, Info>& operator+=(const Sequence<Key, Info>&);
        //Addition operator
        Sequence<Key, Info> operator+(const Sequence<Key, Info>&);
        //Equality operator
        bool operator==(const Sequence<Key, Info>&);
        //Inequality operator
        bool operator!=(const Sequence<Key, Info>&);
        //Insertion Operator
        template<typename K, typename I>
        friend std::ostream& operator<<(std::ostream&, const Sequence<K, I>&);

        template<typename K, typename I>
        friend bool split_pos(const Sequence<K, I>&, unsigned int, unsigned int, unsigned int, unsigned int, Sequence<K, I>&, Sequence<K, I>&);

        template<typename K, typename I>
        friend bool split_key(const Sequence<K, I>&, const Key&, unsigned int, unsigned int, unsigned int, unsigned int, Sequence <K, I>&, Sequence <K, I>&);
};