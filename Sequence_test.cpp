#include <sstream>
#include "Sequence.cpp"

template<typename Key, typename Info>
bool nodeTest(const Node<Key, Info>& nodeToTest, const Key& keyValue, const Info& infoValue, Node<Key, Info>* nextNode = nullptr) {
    return (nodeToTest.getKey() == keyValue && nodeToTest.getInfo() == infoValue && nodeToTest.getNext() == nextNode);
}

template<typename Key, typename Info>
bool SequenceTest(const Sequence<Key, Info>& sequenceToTest, unsigned int numNodes, Node<Key, Info> frontNode, Node<Key, Info> backNode) {
    return (sequenceToTest.getSize() == numNodes && sequenceToTest.getFrontNode() == frontNode && sequenceToTest.getBackNode() == backNode);
}

int main() {

    std::cout << "Node Test" << std::endl;

    // Default constructor Test
    {
        Node<char, bool> node;
        node.setKey('a');
        node.setInfo(true);

        if(nodeTest(node, 'a', true))
            std::cout << "--OK--Default Constructor" << std::endl;

        else
            std::cout << "--FAIL--Default Constructor" << std::endl;

    }

    //Copy constructor Test
    {
        Node<int, bool> node1;
        node1.setKey(-1);
        node1.setInfo(true);

        Node<int, bool> node2(node1);

        if(nodeTest(node2, -1, true))
            std::cout << "--OK--Copy Constructor" << std::endl;

        else
            std::cout << "--FAIL--Copy Constructor" << std::endl;

    }

    //Constructor with key and info Test
    {
        Node<char, bool> node('c', true);

        if(nodeTest(node, 'c', true))
            std::cout << "--OK--Constructor with key and info" << std::endl;

        else
            std::cout << "--FAIL--Constructor with key and info" << std::endl;

    }

    //Assignment operator Test
    {
        Node<char, int> node1('d', 7);
        Node<char, int> node2;

        node2 = node1;

        if(nodeTest(node2, 'd', 7))
            std::cout << "--OK--Assignment operator" << std::endl;

        else
            std::cout << "--FAIL--Assignment operator" << std::endl;

    }

    //Equality operator Test
    {
        Node<unsigned int, std::string> node1(10, "Shit");
        Node<unsigned int, std::string> node2(10, "Shit");

        if(node1 == node2)
            std::cout << "--OK--Equality operator" << std::endl;

        else
            std::cout << "--FAIL--Equality operator" << std::endl;

    }

    //Inequality operator Test
    {
        Node<unsigned int, int> node1(10, -70);
        Node<unsigned int, int> node2(10, -71);

        if(node1 != node2)
            std::cout << "--OK--Inequality operator" << std::endl;

        else
            std::cout << "--FAIL--Inequality operator" << std::endl;

    }

    //Insertion operator Test
    {
        Node<unsigned int, std::string> node(99, "Halo");
        std::ostringstream output;
        output << node;

        if(output.str() == "{ 99, Halo }")
            std::cout << "--OK--Insertion operator" << std::endl;

        else
            std::cout << "--FAIL--Insertion operator" << std::endl;
    }

    std::cout << "Sequence Test" << std::endl;

    //Default constructor Test
    {
        Sequence<unsigned int, std::string> seq;

        if(seq.isEmpty())
            std::cout << "--OK--Default Constructor" << std::endl;

        else
            std::cout << "--FAIL--Default Constructor" << std::endl;

    }

    //Copy constructor Test
    {
        Sequence<unsigned int, std::string> seq1;
        seq1.pushBack(1, "Hello");
        seq1.pushBack(2, "World");
        seq1.pushBack(3, "!");

        Sequence<unsigned int, std::string> seq2(seq1);

        Node<unsigned int, std::string> frontNode(1, "Hello");
        Node<unsigned int, std::string> backNode(3, "!");

        if(SequenceTest(seq2, 3, frontNode, backNode))
            std::cout << "--OK--Copy Constructor" << std::endl;

        else
            std::cout << "--FAIL--Copy Constructor" << std::endl;
    }

    //pushBack Test
    {
        Sequence<unsigned int, std::string> seq;
        seq.pushBack(1, "Hello");
        seq.pushBack(2, "World");
        seq.pushBack(3, "!");

        Node<unsigned int, std::string> backNode(3, "!");

        if(seq.getBackNode() == backNode)
            std::cout << "--OK--pushBack" << std::endl;

        else
            std::cout << "--FAIL--pushBack" << std::endl;
    }

    //pushFront Test
    {
        Sequence<unsigned int, std::string> seq;
        seq.pushFront(1, "Hello");
        seq.pushFront(2, "World");
        seq.pushFront(3, "!");

        Node<unsigned int, std::string> frontNode(3, "!");

        if(seq.getFrontNode() == frontNode)
            std::cout << "--OK--pushFront" << std::endl;

        else
            std::cout << "--FAIL--pushFront" << std::endl;
    }

    //insertAfter Test
    {
        Sequence<unsigned int, std::string> seq;
        seq.pushBack(1, "Hello");
        seq.pushBack(2, "World");
        seq.pushBack(3, "!");

        seq.insertAfter(4, "Wow", 3);

        Node<unsigned int, std::string> inserted(4, "Wow");

        if(seq.getBackNode() == inserted)
            std::cout << "--OK--insertAfter" << std::endl;

        else
            std::cout << "--FAIL--insertAfter" << std::endl;
    }

    //swap Test
    {
        Sequence<unsigned int, std::string> seq1;
        seq1.pushBack(1, "Hello");
        seq1.pushBack(2, "World");
        seq1.pushBack(3, "!");

        seq1.swap(1, 2);

        Node<unsigned int, std::string> frontNode(2, "World");

        if(seq1.getFrontNode() == frontNode)
            std::cout << "--OK--swap" << std::endl;

        else
            std::cout << "--FAIL--swap" << std::endl;
    }

    //remove Test
    {
        Sequence<unsigned int, std::string> seq1;
        seq1.pushBack(1, "Hello");
        seq1.pushBack(2, "World");
        seq1.pushBack(3, "!");

        seq1.remove(3);

        Node<unsigned int, std::string> backNode(3, "!");

        if(seq1.getBackNode() != backNode)
            std::cout << "--OK--remove" << std::endl;

        else
            std::cout << "--FAIL--remove" << std::endl;
    }

    //popBack Test
    {
        Sequence<unsigned int, std::string> seq1;
        seq1.pushBack(1, "Hello");
        seq1.pushBack(2, "World");
        seq1.pushBack(3, "!");

        seq1.popBack();

        Node<unsigned int, std::string> backNode(2, "World");

        if(seq1.getBackNode() == backNode)
            std::cout << "--OK--popBack" << std::endl;

        else
            std::cout << "--FAIL--popBack" << std::endl;
    }

    //popFront Test
    {
        Sequence<unsigned int, std::string> seq1;
        seq1.pushBack(1, "Hello");
        seq1.pushBack(2, "World");
        seq1.pushBack(3, "!");

        seq1.popFront();

        Node<unsigned int, std::string> frontNode(2, "World");

        if(seq1.getFrontNode() == frontNode)
            std::cout << "--OK--popFront" << std::endl;

        else
            std::cout << "--FAIL--popFront" << std::endl;
    }

    //clear Test
    {
        Sequence<unsigned int, std::string> seq1;
        seq1.pushBack(1, "Hello");
        seq1.pushBack(2, "World");
        seq1.pushBack(3, "!");

        seq1.clear();

        if(seq1.isEmpty())
            std::cout << "--OK--clear" << std::endl;

        else
            std::cout << "--FAIL--clear" << std::endl;
    }

    //occuranceNumber Test
    {
        Sequence<unsigned int, std::string> seq1;
        seq1.pushBack(1, "Hello");
        seq1.pushBack(1, "Hi");

        if(seq1.occuranceNumber(1) == 2)
            std::cout << "--OK--occurrences" << std::endl;

        else
            std::cout << "--FAIL--occurrences" << std::endl;
    }

    //includes Test
    {
        Sequence<unsigned int, std::string> seq1;
        seq1.pushBack(1, "Hello");
        seq1.pushBack(1, "Hi");

        if(seq1.includes(1, "Hello"))
            std::cout << "--OK--includes" << std::endl;

        else
            std::cout << "--FAIL--includes" << std::endl;
    }

    //Assignment Operator Test
    {
        Sequence<unsigned int, std::string> seq1;
        seq1.pushBack(1, "Hello");
        seq1.pushBack(2, "World");
        seq1.pushBack(3, "!");

        Sequence<unsigned int, std::string> seq2(seq1);

        Node<unsigned int, std::string> frontNode(1, "Hello");
        Node<unsigned int, std::string> backNode(3, "!");

        if(SequenceTest(seq2, 3, frontNode, backNode))
            std::cout << "--OK--Assignment Operator" << std::endl;

        else
            std::cout << "--FAIL--Assignment Operator" << std::endl;
    }

    //Addition assignment operator Test
    {
        Sequence<unsigned int, std::string> seq1;
        seq1.pushBack(1, "Hello");
        seq1.pushBack(2, "World");
        seq1.pushBack(3, "!");

        Sequence<unsigned int, std::string> seq2;
        seq2.pushBack(4, "Hi");
        seq2.pushBack(5, "Bye");

        seq1 += seq2;

        Node<unsigned int, std::string> frontNode(1, "Hello");
        Node<unsigned int, std::string> backNode(5, "Bye");

        if(SequenceTest(seq1, 5, frontNode, backNode))
            std::cout << "--OK--Addition assignment operator" << std::endl;

        else
            std::cout << "--FAIL--Addition assignment operator" << std::endl;
    }

    //Addition operator Test
    {
        Sequence<unsigned int, std::string> seq1;
        seq1.pushBack(1, "Hello");
        seq1.pushBack(2, "World");
        seq1.pushBack(3, "!");

        Sequence<unsigned int, std::string> seq2;
        seq2.pushBack(4, "Hi");
        seq2.pushBack(5, "Bye");

        Sequence<unsigned int, std::string> seq3 = seq1 + seq2;

        Node<unsigned int, std::string> frontNode(1, "Hello");
        Node<unsigned int, std::string> backNode(5, "Bye");

        if(SequenceTest(seq3, 5, frontNode, backNode))
            std::cout << "--OK--Addition operator" << std::endl;

        else
            std::cout << "--FAIL--Addition operator" << std::endl;
    }

    //Equality operator Test
    {
        Sequence<unsigned int, std::string> seq1;
        seq1.pushBack(1, "Hello");
        seq1.pushBack(2, "World");
        seq1.pushBack(3, "!");

        Sequence<unsigned int, std::string> seq2;
        seq2.pushBack(1, "Hello");
        seq2.pushBack(2, "World");
        seq2.pushBack(3, "!");

        if(seq1 == seq2)
            std::cout << "--OK--Equality operator" << std::endl;

        else
            std::cout << "--FAIL--Equality operator" << std::endl;
    }

    //Inequality operator Test
    {
        Sequence<unsigned int, std::string> seq1;
        seq1.pushBack(1, "Hello");
        seq1.pushBack(2, "World");
        seq1.pushBack(3, "!");

        Sequence<unsigned int, std::string> seq2;
        seq2.pushBack(1, "Hello");
        seq2.pushBack(2, "World");
        seq2.pushBack(3, "?");

        if(seq1 != seq2)
            std::cout << "--OK--Inequality operator" << std::endl;

        else
            std::cout << "--FAIL--Inequality operator" << std::endl;
    }

    //Insertion operator Test
    {
        Sequence<unsigned int, std::string> seq1;
        seq1.pushBack(1, "Hello");
        seq1.pushBack(2, "World");

        std::ostringstream output;
        output << seq1;

        if(output.str() == "{ 1, Hello }\n{ 2, World }\n")
            std::cout << "--OK--Insertion operator" << std::endl;

        else
            std::cout << "--FAIL--Insertion operator" << std::endl;
    }

    //Split_pos test
    {
        Sequence<unsigned int, std::string> seq;
        seq.pushBack(1, "Hello");
        seq.pushBack(2, "World");
        seq.pushBack(3, "!");
        seq.pushBack(4, "Bye");
        seq.pushBack(5, "Bye");
        seq.pushBack(6, "This");
        seq.pushBack(7, "is");
        seq.pushBack(8, "a");
        seq.pushBack(9, "test");
        seq.pushBack(10, "of");
        seq.pushBack(11, "the");
        seq.pushBack(12, "developer's");
        seq.pushBack(13, "patience");
        seq.pushBack(14, "!");

        Sequence<unsigned int, std::string> seq1;
        Sequence<unsigned int, std::string> seq2;

        split_pos(seq, 1, 2, 2, 3, seq1, seq2);

        std::cout << "seq1: " << seq1 << std::endl;
        std::cout << "seq2: " << seq2 << std::endl;
    }

    //split_key test
    {
        Sequence<unsigned int, std::string> seq;
        seq.pushBack(1, "Hello");
        seq.pushBack(2, "World");
        seq.pushBack(3, "!");
        seq.pushBack(4, "Bye");
        seq.pushBack(5, "Bye");
        seq.pushBack(6, "This");
        seq.pushBack(7, "is");
        seq.pushBack(8, "a");
        seq.pushBack(9, "test");
        seq.pushBack(10, "of");
        seq.pushBack(11, "the");
        seq.pushBack(12, "developer's");
        seq.pushBack(13, "patience");
        seq.pushBack(14, "!");

        Sequence<unsigned int, std::string> seq1;
        Sequence<unsigned int, std::string> seq2;

        split_pos(seq, 1, 2, 2, 3, seq1, seq2);

        std::cout << "seq1: " << seq1 << std::endl;
        std::cout << "seq2: " << seq2 << std::endl;
    }
}