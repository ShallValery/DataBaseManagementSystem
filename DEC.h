/*****************************************************************//**
 * \file   DEC.h
 * \brief  Реализация DECK
 *
 * \author Куминов Валерий ТКИ - 441 (ShallValery)
 * \date   October 2022
 *********************************************************************/
#pragma once
#include "NODE.h"
#include <iostream>

class Deck 
{
    Node* head,* bottom;
    size_t size;

    /*
    \brief Запрет конструктора копирования.
    \param const Deck& - указатель на Deck
    */
    Deck(const Deck&) = delete;

    /*
    \brief Запрет оператора присваивания копирования.
    \param Deck& - указатель на Deck
    */
    Deck& operator=(const Deck&) = delete;

    /*
    \brief Запрет конструктора перемещения.
    \param Deck&& - указатель на Deck
    */
    Deck(Deck&&) = delete;

    /*
    \brief Запрет оператора присваивания перемещения.
    \param Deckk&& - указатель на Deck
    */
    Deck& operator=(Deck&&) = delete;
   

public:

    /*
    \brief Конструктор по умолчанию для класса Deck.
    */
    Deck() :head(nullptr), bottom(nullptr), size(0) {};

    /*
    \brief Метод вноса нового элемента в ДЕК справа.
    \param value - значение, которое будет записано в элементе дека.
    */
    void PushRight(const int value);

    /*
    \brief Метод вноса нового элемента в ДЕК слева.
    \param value - значение, которое будет записано в элементе дека.
    */
    void PushLeft(const int value);

    /*
    \brief Метод удаления из ДЕКа элемента справа.
    */
    int DeleteRight();

    /*
    \brief Метод удаления из ДЕКа элемента слева.
    */
    int DeleteLeft();

    /*!
    \brief Метод возврата количества элементов в ДЕКе.
    */
    size_t GetSize();

    /*
    \brief Метод изменения элемента ДЕКа справа.
    \param value - значение, которое будет записано в элементе дека.
    */
    void ChangeRight(const int value);

    /*
    \brief Метод изменения элемента ДЕКа слева.
    \param value - значение, которое будет записано в элементе дека.
    */
    void ChangeLeft(const int value);


    /*
    \brief Метод будет выводить на экран элемент дека справа.
    */
    int PrintRight();

    /*!
    \brief Метод будет выводить на экран элемент дека слева.
    */
    int PrintLeft();

    friend std::ostream& operator<< (std::ostream& out, Deck& deck);
};