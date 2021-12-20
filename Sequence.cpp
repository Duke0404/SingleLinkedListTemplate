#include "Sequence.hpp"

//Node class implementation
//Constructors & Destructor
//Default Constructor
template<typename Key, typename Info>
Node<Key, Info>::Node() {
    setNext(nullptr);
}

//Copy Constructor
template<typename Key, typename Info>
Node<Key, Info>::Node(const Node<Key, Info>& originalNode, Node<Key, Info>* nextNode) {
    setNext(nextNode);
    setKey(originalNode.getKey());
    setInfo(originalNode.getInfo());
}

//Constructor with key and info
template<typename Key, typename Info>
Node<Key, Info>::Node(const Key& keyValue, const Info& infoValue, Node<Key, Info>* nextNode) {
    setNext(nextNode);
    setKey(keyValue);
    setInfo(infoValue);
}

//Setters
//Set the next node
template<typename Key, typename Info>
void Node<Key, Info>::setNext(Node<Key, Info>* nextNode) {
    next = nextNode;
}

//Set the Key value
template<typename Key, typename Info>
void Node<Key, Info>::setKey(const Key& keyValue) {
    key = keyValue;
}

//Set the Info value
template<typename Key, typename Info>
void Node<Key, Info>::setInfo(const Info& infoValue) {
    info = infoValue;
}

//Getters
//Get the next node
template<typename Key, typename Info>
Node<Key, Info>* Node<Key, Info>::getNext() const {
    return next;
}

//Get the Key value
template<typename Key, typename Info>
const Key& Node<Key, Info>::getKey() const {
    return key;
}

//Get the Info value
template<typename Key, typename Info>
const Info& Node<Key, Info>::getInfo() const {
    return info;
}

//Operator Overloads
//Assignment Operator
template<typename Key, typename Info>
Node<Key, Info>& Node<Key, Info>::operator=(const Node& originalNode) {
    setKey(originalNode.getKey());
    setInfo(originalNode.getInfo());

    return *this;
}
//Equality Operator
template<typename Key, typename Info>
bool Node<Key, Info>::operator==(Node<Key, Info>& otherNode) {
    return (key == otherNode.getKey() && info == otherNode.getInfo());
}

//Inequality Operator
template<typename Key, typename Info>
bool Node<Key, Info>::operator!=(Node<Key, Info>& otherNode) {
    return !(*this == otherNode);
}

//Insertion Operator for the Node class
template<typename Key, typename Info>
std::ostream& operator<<(std::ostream& outputLocation, const Node<Key, Info>& nodeToPrint) {
    outputLocation << "{ " << nodeToPrint.getKey() << ", " << nodeToPrint.getInfo() << " }";
    return outputLocation;
}

//Sequence class implementation
//Constructors & Destructor
//Default Constructor
template<typename Key, typename Info>
Sequence<Key, Info>::Sequence() {
    setSize(0);
    setFront(nullptr);
    setBack(nullptr);
}

//Copy Constructor
template<typename Key, typename Info>
Sequence<Key, Info>::Sequence(const Sequence<Key, Info>& originalSequence) {

    setSize(0);
    setFront(nullptr);
    setBack(nullptr);
    
    if(originalSequence.getSize() != 0) {
        Node<Key, Info>* currentNode = originalSequence.getFront();

        while(currentNode != nullptr) {
            pushBack(*(currentNode));
            currentNode = currentNode->getNext();
        }
    }
}

//Destructor
template<typename Key, typename Info>
Sequence<Key, Info>::~Sequence() {
    if(getSize() != 0) {
        Node<Key, Info>* currentNode = getFront();
        Node<Key, Info>* nextNode;

        while(currentNode != nullptr) {
            nextNode = currentNode->getNext();
            delete currentNode;
            currentNode = nextNode;
        }
    }
}

//Setters
//Set the size of the list
template<typename Key, typename Info>
void Sequence<Key, Info>::setSize(unsigned int sizeValue) {
    size = sizeValue;
}

//Set the front node
template<typename Key, typename Info>
void Sequence<Key, Info>::setFront(Node<Key, Info>* nodeFront) {
    front = nodeFront;
}

//Set the back node
template<typename Key, typename Info>
void Sequence<Key, Info>::setBack(Node<Key, Info>* nodeBack) {
    back = nodeBack;
}

//Getters
//Get the size of the list
template<typename Key, typename Info>
unsigned int Sequence<Key, Info>::getSize() const {
    return size;
}

//Get the front node
template<typename Key, typename Info>
Node<Key, Info>* Sequence<Key, Info>::getFront() const {
    return front;
}

template<typename Key, typename Info>
Node<Key, Info> Sequence<Key, Info>::getFrontNode() const {
    return *front;
}

//Get the back node
template<typename Key, typename Info>
Node<Key, Info>* Sequence<Key, Info>::getBack() const {
    return back;
}

template<typename Key, typename Info>
Node<Key, Info> Sequence<Key, Info>::getBackNode() const {
    return *back;
}

template<typename Key, typename Info>
void Sequence<Key, Info>::increaseSize(unsigned int increment) {
    setSize(getSize() + increment);
}

template<typename Key, typename Info>
void Sequence<Key, Info>::decreaseSize(unsigned int decrement) {
    setSize(getSize() - decrement);
}

//Insert a node at the back of the list
template<typename Key, typename Info>
bool Sequence<Key, Info>::pushBack(const Key& keyValue, const Info& infoValue) {
    Node<Key, Info>* newNode = new Node<Key, Info>(keyValue, infoValue);

    if(getSize() == 0) {
        if(getFront() != nullptr || getBack() != nullptr)
            return false;
        setFront(newNode);
    }
    else {
        if(getFront() == nullptr || getBack() == nullptr)
            return false;
        getBack()->setNext(newNode);
    }

    setBack(newNode);
    increaseSize();
    return true;
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::pushBack(const Node<Key, Info>& nodeToPush) {
    Node<Key, Info>* newNode = new Node<Key, Info>(nodeToPush);

    if(getSize() == 0) {
        if(getFront() != nullptr || getBack() != nullptr)
            return false;
        setFront(newNode);
    }
    else {
        if(getFront() == nullptr || getBack() == nullptr)
            return false;
        getBack()->setNext(newNode);
    }

    setBack(newNode);
    increaseSize();
    return true;
}

//Insert a node at the front of the list
template<typename Key, typename Info>
bool Sequence<Key, Info>::pushFront(const Key& keyValue, const Info& infoValue) {
    Node<Key, Info>* newNode = new Node<Key, Info>(keyValue, infoValue, getFront());

    if(getSize() == 0) {
        if(getFront() != nullptr || getBack() != nullptr)
            return false;
        setBack(newNode);
    }
    else {
        if(getFront() == nullptr || getBack() == nullptr)
            return false;
    }

    setFront(newNode);
    increaseSize();
    return true;
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::pushFront(const Node<Key, Info>& nodeToPush) {
    Node<Key, Info>* newNode = new Node<Key, Info>(nodeToPush, getFront());

    if(getSize() == 0) {
        if(getFront() != nullptr || getBack() != nullptr)
            return false;
        setBack(newNode);
    }
    else {
        if(getFront() == nullptr || getBack() == nullptr)
            return false;
    }

    setFront(newNode);
    increaseSize();
    return true;
}

//Insert a node after the specified node
template<typename Key, typename Info>
bool Sequence<Key, Info>::insertAfter(const Key& keyValue, const Info& infoValue, const Key& location, unsigned int occurance) {
    Node<Key, Info>* current = getFront();
    while(current != nullptr) {
        if(current->getKey() == location) {
            if(occurance == 1) {
                Node<Key, Info>* nodeToInsert = new Node<Key, Info>(keyValue, infoValue, current->getNext());
                current->setNext(nodeToInsert);
                increaseSize();
                
                if(current == getBack())
                    setBack(nodeToInsert);
                
                return true;
            }

            else {
                occurance--;
            }
        }
        current = current->getNext();
    }
    return false;
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::insertBefore(const Key& keyValue, const Info& infoValue, const Key& location, unsigned int occurance) {
    Node<Key, Info>* current = getFront();
    Node<Key, Info>* previous;
    while(current != nullptr) {
        if(current->getKey() == location) {
            if(occurance == 1) {
                Node<Key, Info>* nodeToInsert = new Node<Key, Info>(keyValue, infoValue, current);
                if(current == getFront())
                    setFront(nodeToInsert);
                else
                    previous->setNext(nodeToInsert);
                increaseSize();
                
                return true;
            }

            else {
                occurance--;
            }
        }
        previous = current;
        current = current->getNext();
    }
    return false;
}

//Swap nodes
template<typename Key, typename Info>
bool Sequence<Key, Info>::swap(const Key& FirstKey, const Key& SecondKey, unsigned int occuranceFirstNode, unsigned int occuranceSecondNode) {
    if(getSize() < 2)
        return false;

    else {
        Node<Key, Info> temporaryNode;
        Node<Key, Info>* currentFirst = getFront();
        while(currentFirst != nullptr) {
            if(currentFirst->getKey() == FirstKey) {
                if(occuranceFirstNode == 1) {
                    temporaryNode = *currentFirst;
                    break;
                }

                else
                    occuranceFirstNode--;
            }

            currentFirst = currentFirst->getNext();
        }

        if(temporaryNode != *currentFirst)
            return false;

        Node<Key, Info>* currentSecond = getFront();
        while(currentSecond != nullptr) {
            if(currentSecond->getKey() == SecondKey) {
                if(occuranceSecondNode == 1) {
                    *currentFirst = *currentSecond;
                    *currentSecond = temporaryNode;
                    return true;
                }

                else
                    occuranceSecondNode--;
            }

            currentSecond = currentSecond->getNext();
        }

        return false;
    }


}

//Remove node with specified key
template<typename Key, typename Info>
bool Sequence<Key, Info>::remove(const Key& keyValue, unsigned int occurance) {
    if(isEmpty())
        return false;

    else {
        Node<Key, Info>* current = getFront();
        Node<Key, Info>* previous;

        while(current != nullptr) {
            if(current->getKey() == keyValue) {
                if(occurance == 1) {
                    if(getSize() == 1) {
                        setFront(nullptr);
                        setBack(nullptr);
                    }

                    else if(current == getFront())
                        setFront(current->getNext());

                    else if(current == getBack()) {
                        previous->setNext(nullptr);
                        setBack(previous);
                    }

                    else
                        previous->setNext(current->getNext());

                    delete current;
                    decreaseSize();
                    return true;
                }

                else {
                    occurance--;
                }
            }

            previous = current;
            current = current->getNext();
        }

        return false;
    }
}

//Remove the front node
template<typename Key, typename Info>
bool Sequence<Key, Info>::popFront() {
    if(isEmpty())
        return false;

    else if(getSize() == 1) {
        delete getFront();
        setFront(nullptr);
        setBack(nullptr);
        decreaseSize();
        return true;
    }

    else {
        Node<Key, Info>* temp = getFront();
        setFront(getFront()->getNext());
        delete temp;
        decreaseSize();
        return true;
    }
}

//Remove the back node
template<typename Key, typename Info>
bool Sequence<Key, Info>::popBack() {
    if(isEmpty())
        return false;

    else if(getSize() == 1) {
        delete getBack();
        setFront(nullptr);
        setBack(nullptr);
        decreaseSize();
        return true;
    }

    else {
        Node<Key, Info>* current = getFront();
        Node<Key, Info>* previous = nullptr;

        while(current != nullptr) {
            if(current == getBack()) {
                delete current;
                previous->setNext(nullptr);
                setBack(previous);
                decreaseSize();
                return true;
            }

            previous = current;
            current = current->getNext();
        }

        return false;
    }
}

//Remove all nodes in the list
template<typename Key, typename Info>
bool Sequence<Key, Info>::clear() {
    if(isEmpty())
        return false;

    else {
        Node<Key, Info>* current = getFront();

        while(current != nullptr) {
            current = current->getNext();
            popFront();
        }

        return true;
    }
}

//Check if list is empty
template<typename Key, typename Info>
bool Sequence<Key, Info>::isEmpty() const {
    return getSize() == 0;
}

//Get number of occurances of specified key
template<typename Key, typename Info>
unsigned int Sequence<Key, Info>::occuranceNumber(const Key& keyToFind) const {
    if(isEmpty())
        return 0;

    else {
        Node<Key, Info>* current = getFront();
        unsigned int count = 0;

        while(current != nullptr) {
            if(current->getKey() == keyToFind)
                ++count;

            current = current->getNext();
        }

        return count;
    }
}

//Get if specified node exists in the list
template<typename Key, typename Info>
bool Sequence<Key, Info>::includes(const Key& keyToFind, const Info& infoToFind, unsigned int occurance) const {
    if(isEmpty())
        return false;

    else {
        Node<Key, Info>* current = getFront();

        while(current != nullptr) {
            if(current->getKey() == keyToFind && current->getInfo() == infoToFind) {
                if(occurance == 1)
                    return true;

                else {
                    occurance--;
                }
            }

            current = current->getNext();
        }

        return false;
    }
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::includes(const Node<Key, Info>& nodeToFind, unsigned int occurance) const {
    if(isEmpty())
        return false;

    else {
        Node<Key, Info>* current = getFront();

        while(current != nullptr) {
            if(*current == nodeToFind) {
                if(occurance == 1)
                    return true;

                else {
                    occurance--;
                }
            }

            current = current->getNext();
        }

        return false;
    }
}

//Get the node with specified key
template<typename Key, typename Info>
bool Sequence<Key, Info>::getNodeInfo(Info& infoToGet, const Key& keyToFind, unsigned int occurance) {
    if(isEmpty() || occuranceNumber(keyToFind) == 0)
        return false;

    else {
        Node<Key, Info>* current = getFront();

        while(current != nullptr) {
            if(current->getKey() == keyToFind) {
                if(occurance == 1) {
                    infoToGet = *current;
                    return true;
                }

                else {
                    occurance--;
                }
            }

            current = current->getNext();
        }

        return false;
    }
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::getNodeInfoIndex(Info& infoToGet, unsigned int index) {
    if(isEmpty() || index > getSize() - 1)
        return false;

    else {
        Node<Key, Info>* current = getFront();
        unsigned int count = 0;

        while(current != nullptr) {
            if(count == index) {
                infoToGet = *current;
                return true;
            }

            current = current->getNext();
            count++;
        }

        return false;
    }
}

//Addition assignment operator
template<typename Key, typename Info>
Sequence<Key, Info>& Sequence<Key, Info>::operator+=(const Sequence<Key, Info>& sequenceToAdd) {
    Node<Key, Info>* current = sequenceToAdd.getFront();

    while(current != nullptr) {
        pushBack(current->getKey(), current->getInfo());
        current = current->getNext();
    }

    return *this;
}

//Addition operator
template<typename Key, typename Info>
Sequence<Key, Info> Sequence<Key, Info>::operator+(const Sequence<Key, Info>& sequenceToAdd) {
    Sequence<Key, Info> combinedSequence(*this);
    combinedSequence += sequenceToAdd;
    return combinedSequence;
}

//Equality operator
template<typename Key, typename Info>
bool Sequence<Key, Info>::operator==(const Sequence<Key, Info>& otherSequence) {
    if(getSize() != otherSequence.getSize())
        return false;

    else {
        Node<Key, Info>* current = getFront();
        Node<Key, Info>* otherCurrent = otherSequence.getFront();

        while(current != nullptr) {
            if(*current != *otherCurrent)
                return false;

            current = current->getNext();
            otherCurrent = otherCurrent->getNext();
        }

        return true;
    }
}

//Inequality operator
template<typename Key, typename Info>
bool Sequence<Key, Info>::operator!=(const Sequence<Key, Info>& otherSequence) {
    return !(*this == otherSequence);
}

//Insertion Operator for the Sequence class
template<typename Key, typename Info>
std::ostream& operator<<(std::ostream& outputLocation, const Sequence<Key, Info>& sequenceToPrint) {
    Node<Key, Info>* current = sequenceToPrint.getFront();

    while(current != nullptr) {
        outputLocation << *current << std::endl;
        current = current->getNext();
    }

    return outputLocation;
}

template<typename Key, typename Info>
bool split_pos(const Sequence<Key, Info>& seq, unsigned int start_pos, unsigned int len1, unsigned int len2, unsigned int count, Sequence<Key, Info>& seq1, Sequence<Key, Info>& seq2) {
    if(seq.getSize() == 0)
        return false;

    else {
        seq1.clear();
        seq2.clear();

        Node<Key, Info>* current = seq.getFront();
        unsigned int index = 0;
        unsigned int state = 0;
        unsigned int lastStart;

        while((index <= start_pos + count * (len1 + len2)) || (current != nullptr)) {
            if(state == 0 && index == start_pos) {
                state++;
                lastStart = index;
            }

            if(state == 1) {
                seq1.pushBack(*current);

                if(index == lastStart + len1) {
                    state++;
                    lastStart = index;
                }
            }

            else if(state == 2) {
                seq2.pushBack(*current);

                if(index == lastStart + len2) {
                    state--;
                    lastStart = index;
                }
            }

            index++;
            current = current->getNext();
        }

        return true;
    }
}

template<typename Key, typename Info>
bool split_key(const Sequence<Key, Info>& seq, const Key& start_key, unsigned int start_occ, unsigned int len1, unsigned int len2, unsigned int count, Sequence <Key, Info>& seq1, Sequence <Key, Info>& seq2) {
    if(seq.getSize() == 0 || !(seq.includes(start_key, start_occ)))
        return false;

    else {
        seq1.clear();
        seq2.clear();

        unsigned int index = 0;
        Node<Key, Info>* current = seq.getFront();

        while(current != nullptr) {
            if(current->getKey() == start_key) {
                if(index == start_occ) {
                    break;
                }

                else {
                    index++;
                }
            }

            current = current->getNext();
        }

        return split_pos(seq, index, len1, len2, count, seq1, seq2);
    }
}