#pragma once
#include "Algoritm.h"//Подключение HeaderFile с списком алгоритмов

void CharCountAlghoritm(std::map<std::string, unsigned>* chars, std::vector<std::string> text)
{
    for (auto iter{ (*chars).begin() }; iter != (*chars).end(); iter++)//Проход итератором словаря символов
    {
        for (auto textIter = text.begin(); textIter < text.end(); ++textIter) {//Проход итератором текста
            std::string tmpstr = *textIter;
            for (size_t i{}; i <= tmpstr.length(); )
            {
                // получаем индекс
                size_t position = tmpstr.find(iter->first, i);
                // если не найдено ни одного вхождения с индекса i, выходим из цикла
                if (position == std::string::npos) break;
                // если же вхождение найдено, увеличиваем счетчик вхождений
                iter->second++;
                // переходим к следующему индексу после position
                i = ++position;
            }
        }
       
    }
}
