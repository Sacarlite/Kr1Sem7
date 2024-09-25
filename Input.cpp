#include "Input.h"//Подключение HeaderFile с вводом данных с консоли
#include <iostream>//Подключение библиотеки ввода и вывода
#include "Checks.h"//Подключение HeaderFile с проверками пользовательского ввода
#include "MainMenu.h"//Подключение HeaderFile с Enum menu
#include <map>//Подключение словаря

std::vector<std::string> TextConsoleInput()
{
	while (true) {
		std::vector<std::string> text;//Объявления вектора строк
        std::string str;//Объявление вводимой строки
        std::cout << "Ввод анализируемого текста текста, при окончании ввода введите пустую строку:" << std::endl;
        try {	
            while(true) {
                std::getline(std::cin, str);//Ввод строки с консоли
                if (str.empty()) {//Если строка пуста то цикл прекращается
                    break;
                }
                text.push_back(str);//Добавление строки в конец вектора
            }
            if (text.empty()) {
                throw std::exception();
            }
            return text;
        }
        catch (std::exception) {
            std::cout << "Произошла ошибка при вводе данных повторите попытку." << std::endl;
            text.clear();//Чистка вектора строк
            str.clear();//Чистка строки
            continue;
        }
    }
}

std::map<std::string, unsigned> CharsConsoleInput()
{
    const int charCount = 1;
    const int defaultCount = 0;
    std::string str;//Объявление вводимой строки
    std::map<std::string, unsigned> chars;//Вектор символов
    std::cout << "Введите символы и нажмите ENTER:" << std::endl;
    while (true) {
        try {
            std::getline(std::cin, str);//Ввод строки с консоли
            if (str.empty()) {//Если строка пуста то цикл прекращается
                throw std::exception();
            }
            break;
        }
        catch (std::exception) {
            std::cout << "Произошла ошибка при вводе данных повторите попытку." << std::endl;
            str.clear();//Чистка строки
            continue;
        }
    }
    //Перебор строки и деление на символы
    for (auto iter = str.begin(); iter < str.end(); ++iter) {

        std::string strin(charCount, *iter);
        auto a = chars.find(strin);
        //if (!chars.contains(strin)) {//Если символ не присутствует в словаре
        //    chars.insert({ strin, defaultCount });//Добавление в словарь 
        //}
    }
    return chars;
}
