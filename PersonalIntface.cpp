#include <iostream>//Подключение библеотеки ввода и вывода
#include "PersonalInterface.h"

void ShowTask() {
	std::cout << "Задан текст. Задано множество из N символов. Подсчитать количество" << std::endl;
	std::cout << "вхождений в тексте каждого из символов массива." << std::endl;
	}

void ShowOutputDataOption()
{
	std::cout << "Вы хотите сохранить исходные данные в файл?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Нет" << std::endl;
	std::cout << "Ввод:";
}
void ShowInputOption()
{
	std::cout << "Какой вид ввода данных вы хотите использовать?" << std::endl;
	std::cout << "1)Фаиловый" << std::endl;
	std::cout << "2)Консольный" << std::endl;
	std::cout << "Ввод:";
}

void ShowGreetings()
{
	std::cout << "Контрольная работа №1 Боковой Владислав 415г" << std::endl;
}

void ShowOutputType()
{
	std::cout << "Вы хотите записать данные в файл?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Нет" << std::endl;
	std::cout << "Ввод:";
}
void ShowInputDataOutputType()
{
	std::cout << "Вы хотите записать исходные данные в файл?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Нет" << std::endl;
	std::cout << "Ввод:";
}
void ShowTextInput()
{
	std::cout << "Введите текст." << std::endl;
}
void ShowMassiveInput()
{
	std::cout << "Введите массив." << std::endl;
}
void ShowOutputChoise()
{
	std::cout << "Вы хотите перезаписать данный фаил?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Ввести новое имя(путь к фаилу)" << std::endl;
	std::cout << "Ввод:";
}


