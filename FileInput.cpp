#include "FileInput.h"//Подключение HeaderFile с вводом данных из фаила
#include <fstream>//Библеотека ввода и вывода из фаила
#include <iostream>//Библеотека ввода и вывода
#include <filesystem>//Подключение библеотеки для проверки состояния фаила


std::vector<std::string> TextFileInput()
{
	std::vector<std::string> text;//Объявления вектора cтрок
	std::string fileName;//Объявление переменной имени фаила
	std::ifstream file;//Создание потока для чтения из фаила
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);//Установка побитовых флагов ошибок фаилового взаимодействия
	while (true)
	{
		std::cout << "Введите имя фаила (в разрешении .txt): " << std::endl;
		std::cin >> fileName;//Ввод пути к фаилу
		try
		{
			if (fileName.find(".txt") == std::string::npos)//Поиск в имени фаила части .txt если указатель не указывает на элемент строки происходит повторный запрос
			{
				std::cout << "Не верное разрешение у файла.Повторитие попытку. " << std::endl;
				continue;
			}
			//if (std::filesystem::is_regular_file(fileName)) {//Проверка на системные фаилы
				file.open(fileName);//Открытие потока ввода
				std::cout << "Фаил открыт успешно. " << std::endl;
			//}
		}
		catch (const std::exception&)//Обработка ошибки при чтении из фаила
		{
			std::cout << " Произошла ошибка при открытии фаила.Повторите попытку:" << std::endl;
			continue;

		}
		try {
			file.exceptions(!std::ifstream::badbit | !std::ifstream::failbit);
			std::string str;//Объявление вводимой строки
			while (getline(file, str)) {
				if (str.empty()) {//Если строка пуста то цикл прекращается
					break;
				}
				text.push_back(str);//Добавление строки в конец вектора
			}
			if (text.empty()) {
					throw std::exception();
				}
		}
		catch (const std::exception) {//Обработка ошибки
			std::cout << "Произошла ошибка при чтении информации. Повторите попытку:" << std::endl;
			text.clear();
			file.close();//закрытие потока
			continue;
		}
		file.close();//закрытие потока
		return  text;
	}
}

std::map<std::string, unsigned> CharsFileInput()
{

	std::map<std::string, unsigned> chars;//Вектор символов
	std::string fileName;//Объявление переменной имени фаила
	std::ifstream file;//Создание потока для чтения из фаила
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);//Установка побитовых флагов ошибок фаилового взаимодействия
	while (true)
	{
		std::cout << "Введите имя фаила (в разрешении .txt): " << std::endl;
		std::cin >> fileName;//Ввод пути к фаилу
		try
		{
			if (fileName.find(".txt") == std::string::npos)//Поиск в имени фаила части .txt если указатель не указывает на элемент строки происходит повторный запрос
			{
				std::cout << "Не верное разрешение у файла.Повторитие попытку. " << std::endl;
				continue;
			}
			if (std::filesystem::is_regular_file(fileName)) {//Проверка на системные фаилы
				file.open(fileName);//Открытие потока ввода
				std::cout << "Фаил открыт успешно. " << std::endl;
			}
		}
		catch (const std::exception&)//Обработка ошибки при чтении из фаила
		{
			std::cout << " Произошла ошибка при открытии фаила.Повторите попытку:" << std::endl;
			continue;

		}
		try {
			file.exceptions(!std::ifstream::badbit | !std::ifstream::failbit);
			const int charCount = 1;
			const unsigned defaultCount = 0;
			std::string str;//Объявление вводимой строки
			std::getline(file, str);//Ввод строки с консоли
			if (str.empty()) {//Если строка пуста то цикл прекращается
				throw std::exception();
			}
			
			//Перебор строки и деление на символы
			for (auto iter = str.begin(); iter < str.end(); ++iter) {

				std::string strin(charCount, *iter);
				if (!chars.contains(strin)) {//Если символ не присутствует в словаре
					chars.insert({ strin, defaultCount });//Добавление в словарь 
				}
			
			}
		}
		catch (const std::exception) {//Обработка ошибки
			std::cout << "Произошла ошибка при чтении информации. Повторите попытку:" << std::endl;
			file.close();//закрытие потока
			continue;
		}
		file.close();//закрытие потока
		
		return chars;
	}
}
