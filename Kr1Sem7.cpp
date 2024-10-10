#include <iostream>//Библиотека ввода и вывода
#include <windows.h>//Библиотека ответственная за русскую локализацию консоли
#include <conio.h>//Библиотека ответственная за функцию getch
#include <vector>//Библиотека подключения вектора
#include "MainMenu.h"//Подключение HeaderFile с Enum-меню
#include "Checks.h"//Подключение HeaderFile с проверками пользовательского ввода
#include "ConsoleOutput.h"//Подключение HeaderFile с выводом на консоль
#include "FileInput.h"//Подключение HeaderFile с файловым вводом
#include "FileOutput.h"//Подключение HeaderFile с файловым выводом
#include "Input.h"//Подключение HeaderFile с вводом с консоли
#include "Algoritm.h"//Подключение HeaderFile с вводом с консоли
#include "PersonalInterface.h"//Подключение HeaderFile пользовательского интерфейса
#include <map>//Подключение библиотеки со словарём 
#define QUIT 27//Макрос присваивания Esc значение 27

int main()
{
	setlocale(LC_ALL, "Rus"); //Локализация
	SetConsoleCP(1251); //функции для настройки локализации в строковых переменных при вводе
	SetConsoleOutputCP(1251); //функции для настройки локализации в строковых переменных при выводе
	int userChoice = 0; //Переменная пользовательского ввода
	std::vector<std::string> text; //Вектор текста 
	std::map<std::string, unsigned> chars;//Вектор символов
	ShowGreetings(); //Вывод приветствия
	ShowTask(); //Вывод задания
	do
	{
		ShowTextInput();//Вывод предложение ввода текста
		ShowInputOption(); //Вывод типа вввода
		userChoice = GetChoise(); //Ввод пользовательского решения
		switch (userChoice) //switch выбора консольного ввода или файлового
		{
		case (ConsoleDataInput):
			text = TextConsoleInput(); //Ввод текста с консоли
			ShowOutputType(); //Вывод сообщения об сохранении выбранных данных в файл
			userChoice = GetChoise(); //Ввод пользовательского решения
			if (userChoice == Yes) {
				InputTextFileOutput(text);//Сохранение введёного текста
			}
			break;
		case (FileDataInput):
			text = TextFileInput(); //Ввод текста из файла
			TextConsoleOutput(text); //Вывод считанных данных на консоль
			break;
		}
		ShowMassiveInput();//Вывод предложение ввода массива
		ShowInputOption(); //Вывод типа вввода
		userChoice = GetChoise(); //Ввод пользовательского решения
		switch (userChoice) //switch выбора консольного ввода или файлового
		{
		case (ConsoleDataInput):
			chars = CharsConsoleInput(); //Ввод символов с консоли
			ShowOutputType(); //Вывод сообщения об сохранении выбранных данных в файл
			userChoice = GetChoise(); //Ввод пользовательского решения
			if (userChoice == Yes) {
				InputCharsFileOutput(chars);//Сохранение введёных символов
			}
			break;
		case (FileDataInput):
			chars = CharsFileInput(); //Ввод символов из файла
			CharsConsoleOutput(chars); //Вывод считанных данных на консоль
			break;
		}
		CharCountAlghoritm(&chars, text);//Алгоритм счёта вхождения символов
		StatisticConsoleOutput(chars);//Вывод статистики символов
			ShowOutputType(); //Вывод сообщения об сохранении выбранных данных в файл
			userChoice = GetChoise(); // Ввод пользовательского решения
			if (userChoice == Yes)
			{
				StaticticFileOutput(chars); //Сохранение итогового массива в фаил
			}
		text.clear(); //Чистка вектора текста
		chars.clear();//Чистка словаря симоволов
		std::cout << "Нажмите Esc чтобы завершить работу программы." << std::endl;
		std::cout << "Нажмите Enter чтобы продолжить." << std::endl;
		userChoice = _getch(); //Ввод кода символа введённого с клавиатуры
	} while (userChoice != QUIT); //Проверка что код символа равен коду макроса Quit
}
