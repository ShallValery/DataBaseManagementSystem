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

int Deck::DeleteRight() noexcept
{
    const int value = bottom->_value;
    if (size == 1) {
        delete head;
        head = nullptr;
        bottom = nullptr;
    }
    else {
        Node* tempNode = head;
        for (int i = 1; i < size - 1; i++) 
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
int Deck::DeleteLeft() noexcept
{
    const int value = head->_value;
    if (size == 1) {
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

void Deck::ChangeLeft(const int value) noexcept
{
    this->DeleteLeft();
    this->PushLeft(value);
};

void Deck::ChangeRight(const int value) noexcept
{
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
