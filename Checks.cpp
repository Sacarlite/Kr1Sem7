#include "Checks.h"//Подключение HeaderFile Checks


int GetChoise()
{

    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            int value = std::stoi(str);//Преобразование строки в целочисленный тип данных
            if ((value == 1 || value == 2)&& str.length() == 1) {
                std::cin.clear();//Возврат поток ввода в рабочее состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
                return value;

            }
            else {
                throw std::exception();//Выброс ошибки
            }
        }
        catch (std::exception&) {//Обработка ошибки
            std::cin.clear();//Возврат поток ввода в рабочее состояние 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;
        }
    }
}
int GetMenuPoint()
{

    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            int value = std::stoi(str);//Преобразование строки в целочисленный тип данных
            if ((value == 1 || value == 2||value==3 || value == 4) && str.length() == 1) {
                std::cin.clear();//Возврат поток ввода в рабочее состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
                return value;

            }
            else {
                throw std::exception();//Выброс ошибки
            }
        }
        catch (std::exception&) {//Обработка ошибки
            std::cin.clear();//Возврат поток ввода в рабочее состояние 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;
        }
    }
}
