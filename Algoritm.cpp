#pragma once
#include "Algoritm.h"//����������� HeaderFile � ������� ����������

void CharCountAlghoritm(std::map<std::string, unsigned>* chars, std::vector<std::string> text)
{
    for (auto iter{ (*chars).begin() }; iter != (*chars).end(); iter++)//������ ���������� ������� ��������
    {
        for (auto textIter = text.begin(); textIter < text.end(); ++textIter) {//������ ���������� ������
            std::string tmpstr = *textIter;
            for (size_t i{}; i <= tmpstr.length(); )
            {
                // �������� ������
                size_t position = tmpstr.find(iter->first, i);
                // ���� �� ������� �� ������ ��������� � ������� i, ������� �� �����
                if (position == std::string::npos) break;
                // ���� �� ��������� �������, ����������� ������� ���������
                iter->second++;
                // ��������� � ���������� ������� ����� position
                i = ++position;
            }
        }
       
    }
}
