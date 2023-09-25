//#include <string>
#include "NotationConverterInterface.hpp"

typedef std::string Elem;

class Node //This is the node class
{
    private:
        std::string operation;
        Node* next;
        Node* prev;
        friend class DLinkedList;
};

class DLinkedList //This is the doubly linked list class 
{
    public:
        DLinkedList();
        void addFront(std::string x);
        const std::string Front();
        const void removeFront();
        friend class LinkedDeque;

    private:
        Node* header;
        Node* trailer;
};




class LinkedDeque //This is the linked deque class
{
    public:
        LinkedDeque(); 
        const std::string front();
        void insertFront(const std::string x);
        void removeFront();
        friend class NotationConverter; 

    private:
        DLinkedList D;
};




class NotationConverter : public NotationConverterInterface //This is the notation converter class
{
    public:
        std::string postfixToInfix(std::string inStr);
        std::string postfixToPrefix(std::string inStr);

        std::string infixToPostfix(std::string inStr);
        std::string infixToPrefix(std::string inStr);

        std::string prefixToInfix(std::string inStr);
        std::string prefixToPostfix(std::string inStr); 
};






 





