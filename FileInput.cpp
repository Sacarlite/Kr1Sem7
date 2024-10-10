#include "FileInput.h"//����������� HeaderFile � ������ ������ �� �����
#include <fstream>//���������� ����� � ������ �� �����
#include <iostream>//���������� ����� � ������
#include <filesystem>//����������� ���������� ��� �������� ��������� �����


std::vector<std::string> TextFileInput()
{
	std::vector<std::string> text;//���������� ������� c����
	std::string fileName;//���������� ���������� ����� �����
	std::ifstream file;//�������� ������ ��� ������ �� �����
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	while (true)
	{
		std::cout << "������� ��� ����� (� ���������� .txt): " << std::endl;
		std::cin >> fileName;//���� ���� � �����
		try
		{
			if (fileName.find(".txt") == std::string::npos)//����� � ����� ����� ����� .txt ���� ��������� �� ��������� �� ������� ������ ���������� ��������� ������
			{
				std::cout << "�� ������ ���������� � �����.���������� �������. " << std::endl;
				continue;
			}
			//if (std::filesystem::is_regular_file(fileName)) {//�������� �� ��������� �����
				file.open(fileName);//�������� ������ �����
				std::cout << "���� ������ �������. " << std::endl;
			//}
		}
		catch (const std::exception&)//��������� ������ ��� ������ �� �����
		{
			std::cout << " ��������� ������ ��� �������� �����.��������� �������:" << std::endl;
			continue;

		}
		try {
			file.exceptions(!std::ifstream::badbit | !std::ifstream::failbit);
			std::string str;//���������� �������� ������
			while (getline(file, str)) {
				if (str.empty()) {//���� ������ ����� �� ���� ������������
					break;
				}
				text.push_back(str);//���������� ������ � ����� �������
			}
			if (text.empty()) {
					throw std::exception();
				}
		}
		catch (const std::exception) {//��������� ������
			std::cout << "��������� ������ ��� ������ ����������. ��������� �������:" << std::endl;
			text.clear();
			file.close();//�������� ������
			continue;
		}
		file.close();//�������� ������
		return  text;
	}
}

std::map<std::string, unsigned> CharsFileInput()
{

	std::map<std::string, unsigned> chars;//������ ��������
	std::string fileName;//���������� ���������� ����� �����
	std::ifstream file;//�������� ������ ��� ������ �� �����
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	while (true)
	{
		std::cout << "������� ��� ����� (� ���������� .txt): " << std::endl;
		std::cin >> fileName;//���� ���� � �����
		try
		{
			if (fileName.find(".txt") == std::string::npos)//����� � ����� ����� ����� .txt ���� ��������� �� ��������� �� ������� ������ ���������� ��������� ������
			{
				std::cout << "�� ������ ���������� � �����.���������� �������. " << std::endl;
				continue;
			}
			if (std::filesystem::is_regular_file(fileName)) {//�������� �� ��������� �����
				file.open(fileName);//�������� ������ �����
				std::cout << "���� ������ �������. " << std::endl;
			}
		}
		catch (const std::exception&)//��������� ������ ��� ������ �� �����
		{
			std::cout << " ��������� ������ ��� �������� �����.��������� �������:" << std::endl;
			continue;

		}
		try {
			file.exceptions(!std::ifstream::badbit | !std::ifstream::failbit);
			const int charCount = 1;
			const unsigned defaultCount = 0;
			std::string str;//���������� �������� ������
			std::getline(file, str);//���� ������ � �������
			if (str.empty()) {//���� ������ ����� �� ���� ������������
				throw std::exception();
			}
			
			//������� ������ � ������� �� �������
			for (auto iter = str.begin(); iter < str.end(); ++iter) {

				std::string strin(charCount, *iter);
				if (!chars.contains(strin)) {//���� ������ �� ������������ � �������
					chars.insert({ strin, defaultCount });//���������� � ������� 
				}
			
			}
		}
		catch (const std::exception) {//��������� ������
			std::cout << "��������� ������ ��� ������ ����������. ��������� �������:" << std::endl;
			file.close();//�������� ������
			continue;
		}
		file.close();//�������� ������
		
		return chars;
	}
}
