/*
Задача 1. Простое исключение

Создайте функцию int function(std::string str, int forbidden_length). Эта функция должна возвращать длину переданной строки, 
если эта длина не равна значению переданного параметра forbidden_length. В противном случае она должна выбрасывать исключение bad_length.

Для проверки функции организуйте работу с пользователем. В начале задайте запретную длину, 
а затем считывайте пользовательские строки и выводите их длину до тех пор, пока пользователь не введёт строку запретной длины. 
После этого сообщите ему, что он ввёл строку запретной длины, и завершите программу.

Пример работы программы:
- ведите запретную длину: 5
- Введите слово: Привет
- Длина слова "Привет" равна 6
- Введите слово: мир
- Длина слова "мир" равна 3
- Введите слово: пирог
- Вы ввели слово запретной длины! До свидания
*/
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Bad_length : public exception
{
public:
    const char* what() const override { return "Вы ввели слово запретной длины! До свидания"; }
};

int function(string str, int forbidden_length)
{
    int length = str.length();
    if (length == forbidden_length)
    {
        throw Bad_length();
    }
    return length;
}

int main()
{
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "Russian");

    string input;
    int forbidden_length = 0;
    int result = 0;

    do 
    {
        cout << "Введите запретную длину: ";
        cin >> forbidden_length;

        cout << "Введите слово : ";
        cin >> input;
        
        try
        {
            result = function(input,forbidden_length);
            cout << "Длина слова" << " \"" << input << "\"" << " равна " << result << endl;
        }
        catch (const Bad_length& ex) { cout << ex.what() << endl; return 1; }
        catch (...) { cout << "Вы ввели слово запретной длины! До свидания" << std::endl; return 1; }
    } 
    while (result != forbidden_length);
    

    return 0;
}

