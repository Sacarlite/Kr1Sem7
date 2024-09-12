#pragma once
#include <vector>//Библиотека подключения вектора
#include <string>//Библиотека подключения вектора
#include <map>//Библиотека словаря
void StaticticFileOutput(std::map<std::string, unsigned> chars);//Функция сохранения статистики в фаил
void InputCharsFileOutput(std::map<std::string, unsigned> chars);//Функция сохранения символов в фаил
void InputTextFileOutput(std::vector<std::string> text);//Функция сохранения текста в фаил
