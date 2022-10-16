#pragma once


class Node {
    int value_t;
    Node* next;
public:
    /*
    \brief Метод будет являться конструктором с параметрами для класса Node.
    \param value - значение, которое будет записано в элементе дека.
    */
    Node(const int value) { value_t = value; next = nullptr; };
    friend class Deck;
};

class Deck {
    Node* head, * bottom;
    size_t size;

   /*
   \brief Метод будет запрещать конструктор копирования.
   \param Stack& - указатель на Stack
   */
    Deck(const Deck&) = delete;

    /*
    \brief Метод будет запрещать оператор присваивания копирования.
    \param Stack& - указатель на Stack
    */
    Deck& operator=(const Deck&) = delete;

    /*
    \brief Запрет конструктора перемещения.
    \param const Stack&& - указатель на Stack
    */
    Deck(Deck&&) = delete;

    /*
    \brief Запрет оператора присваивания перемещения.
    \param Stack&& - указатель на Stack
    */
    Deck& operator=(Deck&&) = delete;

public:
    /*
    \brief Метод будет являться конструктором по умолчанию для класса Deck.
    */
    Deck() :head(nullptr), bottom(nullptr), size(0) {};

    /*
    \brief Метод будет вносить новый элемент в дек справа.
    \param value - значение, которое будет записано в элементе дека.
    */
    void movieR(const int value);

    /*
    \brief Метод будет вносить новый элемент в дек слева.
    \param value - значение, которое будет записано в элементе дека.
    */
    void movieL(const int value);

    /*
    \brief Метод будет удаляеть из дека элемент справа.
    */
    int deletionR();

    /*
    \brief Метод будет удалять из дека элемент слева.
    */
    int deletionL();

    /*!
    \brief Метод вернет количество элементов в деке.
    */
    size_t getSize();

    /*
    \brief Метод будет изменяеть элемент дека справа.
    \param value - значение, которое будет записано в элементе дека.
    */
    void changeR(const int value);

    /*
    \brief Метод будет изменяеть элемент дека слева.
    \param value - значение, которое будет записано в элементе дека.
    */
    void changeL(const int value);


    /*
    \brief Метод будет выводить на экран элемент дека справа.
    */
    int printR();
    friend ostream& operator<< (ostream& out, Deck& deck);

    /*!
    \brief Метод будет выводить на экран элемент дека слева.
    */
    int printL();

};