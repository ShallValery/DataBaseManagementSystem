#pragma once
#include "DEC.h"

class Node 
{
    int _value;
    Node* next;
public:
    /*
    \brief Метод является конструктором с параметрами для класса Node.
    \param value - значение, которое будет записано в элемент дека.
    */
    Node(const int value) { _value = value; next = nullptr; };
    friend class Deck;
};



