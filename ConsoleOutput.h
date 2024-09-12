#pragma once
#include <map>//Подключение словаря
#include <string>//Подключение библиотеки строк
#include <vector>//Подключение вектора
#include <iostream>//Библиотека ввода и вывода
void StatisticConsoleOutput(std::map<std::string, unsigned> chars);//Функция вывода сжатого текста на консоль
void CharsConsoleOutput(std::map<std::string, unsigned> chars);//Функция вывода символов на консоль
void TextConsoleOutput(std::vector<std::string> text);//Функция вывода текста на консоль