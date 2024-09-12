#include "FileOutput.h"//Подключение HeaderFile с выводом данных в фаил
#include <fstream>//Библиотека ввода и вывода из фаила
#include <iostream>//Библиотека ввода и вывода
#include "Checks.h"//Подключение HeaderFile с обработкой ошибок пользовательского ввода
#include "MainMenu.h"//Подключение HeaderFile с Enum menu
#include "PersonalInterface.h"//Подключение HeaderFile с пользовательским интерфейсом
#include <filesystem>//Подключение библеотеки для проверки состояния фаила
class FileWriteException//Пользовательский класс ошибок фаилового взаимодействия
{
public:
	FileWriteException(std::string message) : message{ message } {}//Конструктор класса 
	std::string getMessage() const { return message; }//Возврат сообщение об ошибки
private:
	std::string message;//Поле хранящее сообщение об ошибке
};
void WriteStatistics(std::map<std::string, unsigned> chars,std::string fileName)//Функция записи данных квартир в фаил
{
	std::ofstream  out;//Создания потока записи в фаил
	out.exceptions(std::ofstream::badbit | std::ofstream::failbit);//Установка побитовых флагов ошибок фаилового взаимодействия
	try {
		out.open(fileName);//открытие фаила для записи
		out << " Статистика:" << std::endl;
		//Запись данных
		for (const auto& [curentChar, count] : chars) {
			out << "'" << curentChar << "'= " << count << std::endl;
		}
		out.close();//закрытия потока
		std::cout << "Данные успешно сохранены" << std::endl;
	}
	catch(const std::exception&)//Обработка ошибки
	{
		throw FileWriteException("Невозможно записать данные в файл. Повторите попытку.");//Выброс пользовательской ошибки фаилового вывода
	}
}
void WriteText(std::vector<std::string> text, std::string fileName)//Функция записи данных квартир в фаил
{
	std::ofstream  out;//Создания потока записи в фаил
	out.exceptions(std::ofstream::badbit | std::ofstream::failbit);//Установка побитовых флагов ошибок фаилового взаимодействия
	try {
		out.open(fileName);//открытие фаила для записи
		for (auto iter = text.begin(); iter < text.end(); ++iter) {
			out << *iter << std::endl;
		}
		out.close();//закрытия потока
		std::cout << "Данные успешно сохранены" << std::endl;
	}
	catch (const std::exception&)//Обработка ошибки
	{
		throw FileWriteException("Невозможно записать данные в файл. Повторите попытку.");//Выброс пользовательской ошибки фаилового вывода
	}
}
void WriteChars(std::map<std::string, unsigned> chars, std::string fileName)//Функция записи данных квартир в фаил
{
	std::ofstream  out;//Создания потока записи в фаил
	out.exceptions(std::ofstream::badbit | std::ofstream::failbit);//Установка побитовых флагов ошибок фаилового взаимодействия
	try {
		out.open(fileName);//открытие фаила для записи
		//Запись данных
		for (const auto& [curentChar, count] : chars) {
			out <<  curentChar  << std::endl;
		}
		out.close();//закрытия потока
		std::cout << "Данные успешно сохранены" << std::endl;
	}
	catch (const std::exception&)//Обработка ошибки
	{
		throw FileWriteException("Невозможно записать данные в файл. Повторите попытку.");//Выброс пользовательской ошибки фаилового вывода
	}
}
void StaticticFileOutput(std::map<std::string, unsigned> chars)
{
	std::ifstream out2;//Создания потока чтения из фаила
	std::string fileName;//Переменная имени или пути фаила
	out2.exceptions(std::ifstream::badbit | std::ifstream::failbit);//Установка побитовых флагов ошибок фаилового взаимодействия
	int userChoice = 0;//Переменная пользовательского ввода
	while (true) {
		std::cout << "Введите имя фаила (в разрешении .txt): ";
		std::cin >> fileName;//Ввод пути к фаилу
		try {
			if(fileName.find(".txt") == std::string::npos)//Поиск в имени фаила части .txt если указатель не указывает на элемент строки происходит повторный запрос
			{
				std::cout << "Не верное разрешение у файла.Повторитие попытку. "<<std::endl;
				continue;
			}
			try
			{
				if (std::filesystem::is_regular_file(fileName)) {//Проверка на системные фаилы
					std::cout << "Фаил с таким именем уже существует" << std::endl;
				}

			}
			catch (const std::exception&)
			{
				throw FileWriteException("Невозможно записать данные в файл. Повторите попытку.");//Выброс пользовательской ошибки фаилового вывода

			}
			out2.open(fileName);//Попытка открытия фаила
			ShowOutputChoise();//Функция вывода на консоль выбора файла
			userChoice = GetChoise();//Ввод пользовательского выбора
			if (userChoice == Yes) {
				
				out2.close();//Закрытия потока чтения из фаила
				WriteStatistics(chars, fileName);//Функция записи в фаил
			}
			else {
				out2.close();//Закрытия потока чтения из фаила
				continue;
			}
			break;
		}
		catch (const std::exception&) {
			try {
				WriteStatistics(chars, fileName);//Функция записи в фаил
				break;
			}
			catch ( FileWriteException err) {//Обработка ошибки взаимодействия с фаилом
				std::cout << err.getMessage() << std::endl;//Вывод сообщения об ошибки
			}
		}
		catch (FileWriteException err) {//Обработка ошибки взаимодействия с фаилом
			std::cout << err.getMessage() << std::endl;//Вывод сообщения об ошибки
		}

	}
}
void InputCharsFileOutput(std::map<std::string, unsigned> chars)
{
	std::ifstream out2;//Создания потока чтения из фаила
	std::string fileName;//Переменная имени или пути фаила
	out2.exceptions(std::ifstream::badbit | std::ifstream::failbit);//Установка побитовых флагов ошибок фаилового взаимодействия
	int userChoice = 0;//Переменная пользовательского ввода
	while (true) {
		std::cout << "Введите имя фаила (в разрешении .txt): ";
		std::cin >> fileName;//Ввод пути к фаилу
		try {
			if (fileName.find(".txt") == std::string::npos)//Поиск в имени фаила части .txt если указатель не указывает на элемент строки происходит повторный запрос
			{
				std::cout << "Не верное разрешение у файла.Повторитие попытку. " << std::endl;
				continue;
			}
			try
			{
				if (std::filesystem::is_regular_file(fileName)) {//Проверка на системные фаилы
					std::cout << "Фаил с таким именем уже существует" << std::endl;
				}

			}
			catch (const std::exception&)
			{
				throw FileWriteException("Невозможно записать данные в файл. Повторите попытку.");//Выброс пользовательской ошибки фаилового вывода

			}
			out2.open(fileName);//Попытка открытия фаила
			ShowOutputChoise();//Функция вывода на консоль выбора файла
			userChoice = GetChoise();//Ввод пользовательского выбора
			if (userChoice == Yes) {

				out2.close();//Закрытия потока чтения из фаила
				WriteChars(chars, fileName);//Функция записи в фаил
			}
			else {
				out2.close();//Закрытия потока чтения из фаила
				continue;
			}
			break;
		}
		catch (const std::exception&) {
			try {
				WriteChars(chars, fileName);//Функция записи в фаил
				break;
			}
			catch (FileWriteException err) {//Обработка ошибки взаимодействия с фаилом
				std::cout << err.getMessage() << std::endl;//Вывод сообщения об ошибки
			}
		}
		catch (FileWriteException err) {//Обработка ошибки взаимодействия с фаилом
			std::cout << err.getMessage() << std::endl;//Вывод сообщения об ошибки
		}

	}
}
void InputTextFileOutput(std::vector<std::string> text)
{
	std::ifstream out2;//Создания потока чтения из фаила
	std::string fileName;//Переменная имени или пути фаила
	out2.exceptions(std::ifstream::badbit | std::ifstream::failbit);//Установка побитовых флагов ошибок фаилового взаимодействия
	int userChoice = 0;//Переменная пользовательского ввода
	while (true) {
		std::cout << "Введите имя фаила (в разрешении .txt): ";
		std::cin >> fileName;//Ввод пути к фаилу
		try {
			if (fileName.find(".txt") == std::string::npos)//Поиск в имени фаила части .txt если указатель не указывает на элемент строки происходит повторный запрос
			{
				std::cout << "Не верное разрешение у файла.Повторитие попытку. " << std::endl;
				continue;
			}
			try
			{
				if (std::filesystem::is_regular_file(fileName)) {//Проверка на системные фаилы
					std::cout << "Фаил с таким именем уже существует" << std::endl;
				}

			}
			catch (const std::exception&)
			{
				throw FileWriteException("Невозможно записать данные в файл. Повторите попытку.");//Выброс пользовательской ошибки фаилового вывода

			}
			out2.open(fileName);//Попытка открытия фаила
			ShowOutputChoise();//Функция вывода на консоль выбора файла
			userChoice = GetChoise();//Ввод пользовательского выбора
			if (userChoice == Yes) {

				out2.close();//Закрытия потока чтения из фаила
				WriteText(text, fileName);//Функция записи в фаил
			}
			else {
				out2.close();//Закрытия потока чтения из фаила
				continue;
			}
			break;
		}
		catch (const std::exception&) {
			try {
				WriteText(text, fileName);//Функция записи в фаил
				break;
			}
			catch (FileWriteException err) {//Обработка ошибки взаимодействия с фаилом
				std::cout << err.getMessage() << std::endl;//Вывод сообщения об ошибки
			}
		}
		catch (FileWriteException err) {//Обработка ошибки взаимодействия с фаилом
			std::cout << err.getMessage() << std::endl;//Вывод сообщения об ошибки
		}

	}
}

