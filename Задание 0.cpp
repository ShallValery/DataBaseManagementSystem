/*****************************************************************//**
 * \file   Задание 0.cpp
 * \brief  Заполнение массива и сортировка
 *
 * \author Куминов Валерий ТКИ - 441 (ShallValery)
 * \date   September 2022
 *********************************************************************/

#include <iostream>
#include <random>
#include <string>
using namespace std;

/**
 * \brief Функция ввода размера массива.
 *
 * \param message Вывод сообщения о требовании ввода размера массива
 * \return Возвращает int значение длинны массива
 *         В случае неверного ввода длинны массива - бросает исключение
 */
size_t GetSize(const string message);

/**
 *\brief Функция для выделения памяти для массива
 *\param size Размер выделяемой памяти
 *\return Указатель на выделенный в памяти массив
 */
int* CreateVector(const int size);


/**
 * \brief Функция сортировки методом вставок
 *
 * \param array
 * \param size
 */
void InsertionSort(int* array, size_t size);

/**
 * Функция заполнения массива псевдослучайными числами.
 *
 * \param size Размер массива
 * \param array Указатель на массив
 */
void  FillRandome(size_t size, int* array);

/**
*\brief Функция вывода массива
*
* \param array Указатель на массив
* \param size Размер массива
* \return Возвращает строку символов массива
*/
string Print(int* array, size_t size);

/**
 * \brief Основная программа. Осуществляет вызов вышеперечисленных функций
 *
 * \return Возвращает 0 при успешной работе программы
 */
int main()
{
    setlocale(0, "");

    int size = GetSize("Введите размер массива ");
    int* array = CreateVector(size);
    FillRandome(size, array);
    InsertionSort(array, size);
    cout << Print(array, size) << endl;
    return 0;
}

size_t GetSize(const string message)
{
    int value;
    cout << message;
    cin >> value;
    while (value <= 0)
    {
        cout << "Введенная переменная отрицательна, попробуйте снова \n";
        cin >> value;
    }
    return value;
}

int* CreateVector(const int size)
{
    int* array = new int[size];
    return array;
}

void  FillRandome(size_t size, int* array)
{
    int LowLimit = -100;
    int HightLimit = 100;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(LowLimit, HightLimit);

    for (int i = 0; i < size; i++)
    {
        array[i] = distrib(gen);
    }
}

void InsertionSort(int* array, size_t size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        while (j >= 0 && array[j] > array[j + 1])
        {
            swap(array[j], array[j + 1]);
            j--;
        }
    }

}

string Print(int* array, size_t size)
{
    string massive;
    stringstream buffer;
    for (size_t i = 0; i < size; i++)
    {
        buffer << array[i];
    }
    return buffer.str();
}