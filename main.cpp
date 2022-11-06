#include "DEC.h"
#include <iostream>

using namespace std;

void PrintMenu() {
    cout << "\n     МЕНЮ\n\n";
    cout << "1) Вывести ДЕК\n";
    cout << "2) Добавить элемент (Слева)\n";
    cout << "3) Добавить элемент (Справа)\n";
    cout << "4) Удалить элемент (Слева)\n";
    cout << "5) Удалить элемент (Справа)\n";
    cout << "6) Изменить элемент (Слева)\n";
    cout << "7) Изменить элемент (Справа)\n";
    cout << "8) Вывести все элементы ДЕКа \n";
    cout << "\nВыход - q\n";
}

void PrintElements(Deck& M) {
    if (M.GetSize() == 0) {
        cout << "Элементов не обнаружено!" << endl;
    }
    else if (M.GetSize() == 1) {
        cout << M.PrintLeft() << endl;
    }
    else {
        cout << M.PrintLeft() << " ";
        for (int i = 2; i < M.GetSize(); i++) {
            cout << "__ ";
        };
        cout << M.PrintRight() << endl;
    }
};

int main()
{
    setlocale(0, "rus");
    Deck M;
    char key = '0';
    while (key != 'q') {
        system("cls");
        PrintMenu();
        cin >> key;
        int k = 0;
        switch (key)
        {
        case '1':
            cout << "Элементы дека: ";
            PrintElements(M);
            break;
        case '2':
            cout << "Введите элемент для добавления в ДЕК: ";
            cin >> k;
            M.PushLeft(k);
            cout << "Добавлено." << endl;
            break;
        case '3':
            cout << "Введите элемент для добавления в ДЕК: ";
            cin >> k;
            M.PushRight(k);
            cout << "Добавлено." << endl;
            break;
        case '4':
            M.DeleteLeft();
            cout << "Удалено." << endl;
            break;
        case '5':
            M.DeleteRight();
            cout << "Удалено." << endl;
            break;
        case '6':
            cout << "Введите новое значение: ";
            cin >> k;
            M.ChangeLeft(k);
            cout << "Изменено." << endl;
            break;
        case '7':
            cout << "Введите новое значение: ";
            cin >> k;
            M.ChangeRight(k);
            cout << "Изменено." << endl;
            break;
        case '8':
            if (M.GetSize() == 0)
            {
                cout << "Элементов не обнаружено!" << endl;
            }
            else
            {
                cout << "Вывести все элементы ДЕКа: \n" << M << endl;
                cout << "Выведено." << endl;
            }
            break;

            system("pause");

        }
        return 0;
    }
}