#include "DEC.h"
#include "NODE.h"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

const size_t Deck::GetSize() noexcept
{
    return size;
};

Deck::~Deck() noexcept
{
    for (size_t i = 0; i < size; i++) {
        this->DeleteRight();
    };
    size = 0;

  
};

Deck::Deck(const Deck& other) noexcept
{
   if (this != &other)
   { 
    Node* temp = other.head;
    for (size_t i = 0; i < size - 1; i++)
    {
        this->PushRight(temp->_value);
        temp = temp->next;
    }
   }
};

Deck::Deck(const Deck&& other) noexcept
{
    if (this != &other)
    {
        Node* temp = other.head;
        for (size_t i = 0; i < size - 1; i++)
        {
            this->PushRight(temp->_value);
            temp = temp->next;
        }
        other.~Deck();
    }
};

Deck& Deck::operator=(const Deck& other) noexcept
{
    if (this != &other)
    {
        Node* temp = other.head;
        for (size_t i = 0; i < size - 1; i++)
        {
            this->PushRight(temp->_value);
            temp = temp->next;
        }
    }
    return *this;
};

Deck& Deck::operator=(const Deck&& other) noexcept
{
    if (this != &other)
    {
        Node* temp = other.head;
        for (size_t i = 0; i < size - 1; i++)
        {
            this->PushRight(temp->_value);
            temp = temp->next;
        }
        other.~Deck();
    }
    return *this;
};

void Deck::PushRight(const int value) noexcept
{
    Node* temp = new Node(value);
    if (bottom == nullptr) 
    {
        bottom = head = temp;
    }
    else 
    {
        bottom->next = temp;
        bottom = temp;
    };
    size++;
};

void Deck::PushLeft(const int value) noexcept
{
    Node* temp = new Node(value);
    if (head == nullptr) 
    {
        head = bottom = temp;
    }
    else 
    {
        temp->next = head;
        head = temp;
    };
    size++;
};

int Deck::DeleteRight() 
{
    if (size == 0) throw out_of_range("Пусто");
    const int value = bottom->_value;
       
    if (size == 1) {
        delete head;
        head = nullptr;
        bottom = nullptr;
    }
    else {
        Node* tempNode = head;
        for (size_t i = 1; i < size - 1; i++) 
        {
            tempNode = tempNode->next;
        }
        tempNode->next = nullptr;
        delete bottom;
        bottom = tempNode;
    };
    size--;
    return value;
};
int Deck::DeleteLeft() 
{
    if (size == 0) throw out_of_range("Пусто");
    const int value = head->_value;
    
    if 
        (size == 1) {
        delete head;
        head = nullptr;
        bottom = nullptr;
    }
    else {
        Node* tempHead = head->next;
        delete head;
        head = tempHead;
    }
    size--;
    return value;
};

void Deck::ChangeLeft(const int value) 
{
    if (size == 0) throw out_of_range("Пусто");
    this->DeleteLeft();
    this->PushLeft(value);
};

void Deck::ChangeRight(const int value) 
{
    if (size == 0) throw out_of_range("Пусто");
    this->DeleteRight();
    this->PushRight(value);
};

int Deck::PrintLeft() noexcept
{
    return head->_value;
};

int Deck::PrintRight() noexcept
{
    return bottom->_value;
};
std::ostream& operator<< (std::ostream& out, Deck& deck)
{        
    const size_t size = deck.GetSize();
    for (size_t i = 0; i <  size; i++) {
        out << deck.DeleteLeft() << " ";
    };
    return out; 
};
