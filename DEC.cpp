/*****************************************************************//**
 * \file   DEC.cpp
 * \brief  Реализация DECK
 *
 * \author Куминов Валерий ТКИ - 441 (ShallValery)
 * \date   October 2022
 *********************************************************************/


#include "DEC.h"
#include "NODE.h"
#include <sstream>
#include <string>
#include <iostream>


using namespace std;



size_t Deck::GetSize() 
{
    return size;
};

void Deck::PushRight(const int value) 
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

void Deck::PushLeft(const int value) 
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
int Deck::DeleteLeft() 
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

void Deck::ChangeLeft(const int value) 
{
    this->DeleteLeft();
    this->PushLeft(value);
};

void Deck::ChangeRight(const int value) 
{
    this->DeleteRight();
    this->PushRight(value);
};

int Deck::PrintLeft() 
{
    return head->_value;
};

int Deck::PrintRight() 
{
    return bottom->_value;
};
std::ostream& operator<< (std::ostream& out, Deck& deck)
{        
    std::string ret;
    const size_t size = deck.GetSize();
    for (int i = 0; i < size; i++) {
        std::ostringstream temp;
        temp << deck.DeleteLeft();
        ret += temp.str() + " ";
    };
    return out << ret;
};
