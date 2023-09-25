//#include <string>
#include "NotationConverter.hpp"


bool valid(char x) //This is a function that chacks to make sure that the terms given are all terms that are valid
{
    return( ((x == '+')||(x == '-')||(x == '/')||(x== '*')) ||  ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') ) || (x == ' ') || (x == '(') || (x == ')'));
}

//These are all of the functions that are needed in the DlinkedList class
//////////////////////////////////////////////////////////////////
DLinkedList::DLinkedList() //Constructor 
{
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}

void DLinkedList::addFront(std::string x) //The function to add to the front of the doubly linked list
{
    Node* newNode = new Node;
    newNode->operation = x;
    newNode->next = header->next;
    newNode->prev = header->next->prev;
    header->next->prev = newNode;
    header->next->prev->prev->next = header->next->prev;
}

const std::string DLinkedList::Front() //The function that will return the operation that is first in the doubly likned list
{
    std::string temp = header->next->operation;
    return temp;
}

const void DLinkedList::removeFront() //The function that will deleate the first node in the doubly likned list
{
    Node* u = header->next->next;
    header->next = u;
    u->prev = header;
}



/////////////////////////////////////////////////////////////////////////////////
 LinkedDeque::LinkedDeque() : D() //Constructor 
 {
     
 }


const std::string LinkedDeque::front() //This is the function that will return the front operation in the deque
{
    return D.Front();
}

void LinkedDeque::insertFront(std::string x) //This is the function that will insert a new item to the front of the deque
{
    D.addFront(x);
}

void LinkedDeque::removeFront() //This is the function that will remove the item in the front of the deque
{
    D.removeFront();
}





//////////////////////////////////////////////////////////////////////

std::string NotationConverter::infixToPostfix(std::string inStr) //This is the function that does the infix to postfix operation
{   
    LinkedDeque List;
    int Size = inStr.length();
    std::string newString;
    std::string temp;

    for ( int i = 0; i<Size;i++) //This is a for loop that goes through the string to check all of the terms to make sure they are valid
    {
        if(!(valid(inStr[i])))
        {
            throw "NO";
        }
    }
    for(int i = 0; i < Size;i++) //This is the for loop that is used to transform the code into the form wanted 
    {
        temp = inStr[i];
        if (inStr[i] == '(' ) //Here we chack for to see if we found a left parentheses 
        {
            List.insertFront(temp);
        }
        else if (inStr[i] == ')' ) //Here we chack for to see if we found a right parentheses 
        {
            newString += List.front();
            newString += " ";
            List.removeFront();
            List.removeFront();
        }
        else if ((inStr[i] >= 'a' && inStr[i] <= 'z') || (inStr[i] >= 'A' && inStr[i] <= 'Z') ) //Here we check to see if the char at that point in the string is a letter or not
        {
            newString += inStr[i];
            newString += " ";
        }
        else if ((inStr[i] == '+')||(inStr[i] == '-')||(inStr[i] == '/')||(inStr[i] == '*')) //Here we check to see if the char at that point in the string is a operation or not
        {
            List.insertFront(temp);
        }
        else if (inStr[i] == ' ') //Here we check to see if the char at that point in the string is white space or not
        {
            continue;
        }
    }

    return newString;
}


std::string NotationConverter::prefixToInfix(std::string inStr) //This is the function that does the prefix to infix operation
{
    
    LinkedDeque List;
    int n = inStr.length();
    std::string newString;
    std::string stringTemp;
    std::string oper, char1, char2, temp;
    for ( int i = 0; i<n;i++) //This is a for loop that goes through the string to check all of the terms to make sure they are valid
    {
        if(!(valid(inStr[i])))
        {
            throw "NO";
        }
    }
    for (int i = n-1; i >= 0; i--)
    {
       
        stringTemp = inStr[i];
        if ((inStr[i] >= 'a' && inStr[i] <= 'z') || (inStr[i] >= 'A' && inStr[i] <= 'Z') ) //Here we check to see if the char at that point in the string is a letter or not
        {
            List.insertFront(stringTemp);
        }
        else if ((inStr[i] == '+')||(inStr[i] == '-')||(inStr[i] == '/')||(inStr[i] == '*')) //Here we check to see if the char at that point in the string is a operation or not
        {
            char1 = List.front();
            List.removeFront();
            char2 = List.front();
            List.removeFront();
            oper = "(";
            oper += char1;
            oper += " ";
            oper += inStr[i]; 
            oper += " ";
            oper += char2;
            oper += ")";
            List.insertFront(oper);
        }
        else if (inStr[i] == ' ')
        {
            continue;
        }
       
        
        

    }
    newString = List.front();
    return newString;
}



std::string NotationConverter::postfixToPrefix(std::string inStr) //This is the function that does the postfix to prefix operation
{
    LinkedDeque List;
    int n = inStr.length();
    std::string newString;
    std::string stringTemp;
    std::string oper, char1, char2;
    for ( int i = 0; i<n;i++) //This is a for loop that goes through the string to check all of the terms to make sure they are valid
    {
        if(!(valid(inStr[i])))
        {
            throw "NO";
        }
    }
    for (int i = 0; i < n; i++)
    {
        
        stringTemp = inStr[i];
        if ((inStr[i] >= 'a' && inStr[i] <= 'z') || (inStr[i] >= 'A' && inStr[i] <= 'Z') ) //Here we check to see if the char at that point in the string is a letter or not
        {
            List.insertFront(stringTemp);

        }
        else if ((inStr[i] == '+')||(inStr[i] == '-')||(inStr[i] == '/')||(inStr[i] == '*')) //Here we check to see if the char at that point in the string is a operation or not
        {
            char2 = List.front();
            List.removeFront();
            char1 = List.front();
            List.removeFront();
            oper = inStr[i];
            oper += " ";
            oper += char1;
            oper += " ";
            oper += char2;
            List.insertFront(oper);
            
        }
        else if (inStr[i] == ' ')
        {
            continue;
        }
       
        
        

    }
    
    newString = List.front();
    return newString;
}

std::string NotationConverter::infixToPrefix(std::string inStr)  //This is the function that does the infix to prefix operation
{
    int n = inStr.length();
    for ( int i = 0; i<n;i++) ////This is a for loop that goes through the string to check all of the terms to make sure they are valid
    {
        if(!(valid(inStr[i])))
        {
            throw "NO";
        }
    }
    std::string newString;
    newString = infixToPostfix(inStr);
    newString = postfixToPrefix(newString);
    return newString;
   
}

std::string NotationConverter::postfixToInfix(std::string inStr) //This is the function that does the postfix to infix operation
{
    int n = inStr.length();
    for ( int i = 0; i<n;i++) ////This is a for loop that goes through the string to check all of the terms to make sure they are valid
    {
        if(!(valid(inStr[i])))
        {
            throw "NO";
        }
    }
    std::string newString;
    newString = postfixToPrefix(inStr);
    newString = prefixToInfix(newString);
    return newString;
}

std::string NotationConverter::prefixToPostfix(std::string inStr) //This is the function that does the prefix to postfix operation
{
    int n = inStr.length();
    for ( int i = 0; i<n;i++) //This is a for loop that goes through the string to check all of the terms to make sure they are valid
    {
        if(!(valid(inStr[i])))
        {
            throw "NO";
        }
    }
    std::string newString;
    newString = prefixToInfix(inStr);
    newString = infixToPostfix(newString);
    return newString;
}
