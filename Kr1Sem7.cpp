#include <iostream>//���������� ����� � ������
#include <windows.h>//���������� ������������� �� ������� ����������� �������
#include <conio.h>//���������� ������������� �� ������� getch
#include <vector>//���������� ����������� �������
#include "MainMenu.h"//����������� HeaderFile � Enum-����
#include "Checks.h"//����������� HeaderFile � ���������� ����������������� �����
#include "ConsoleOutput.h"//����������� HeaderFile � ������� �� �������
#include "FileInput.h"//����������� HeaderFile � �������� ������
#include "FileOutput.h"//����������� HeaderFile � �������� �������
#include "Input.h"//����������� HeaderFile � ������ � �������
#include "Algoritm.h"//����������� HeaderFile � ������ � �������
#include "PersonalInterface.h"//����������� HeaderFile ����������������� ����������
#include <map>//����������� ���������� �� ������� 
#define QUIT 27//������ ������������ Esc �������� 27

int main()
{
	setlocale(LC_ALL, "Rus"); //�����������
	SetConsoleCP(1251); //������� ��� ��������� ����������� � ��������� ���������� ��� �����
	SetConsoleOutputCP(1251); //������� ��� ��������� ����������� � ��������� ���������� ��� ������
	int userChoice = 0; //���������� ����������������� �����
	std::vector<std::string> text; //������ ������ 
	std::map<std::string, unsigned> chars;//������ ��������
	ShowGreetings(); //����� �����������
	ShowTask(); //����� �������
	do
	{
		ShowTextInput();//����� ����������� ����� ������
		ShowInputOption(); //����� ���� ������
		userChoice = GetChoise(); //���� ����������������� �������
		switch (userChoice) //switch ������ ����������� ����� ��� ���������
		{
		case (ConsoleDataInput):
			text = TextConsoleInput(); //���� ������ � �������
			ShowOutputType(); //����� ��������� �� ���������� ��������� ������ � ����
			userChoice = GetChoise(); //���� ����������������� �������
			if (userChoice == Yes) {
				InputTextFileOutput(text);//���������� �������� ������
			}
			break;
		case (FileDataInput):
			text = TextFileInput(); //���� ������ �� �����
			TextConsoleOutput(text); //����� ��������� ������ �� �������
			break;
		}
		ShowMassiveInput();//����� ����������� ����� �������
		ShowInputOption(); //����� ���� ������
		userChoice = GetChoise(); //���� ����������������� �������
		switch (userChoice) //switch ������ ����������� ����� ��� ���������
		{
		case (ConsoleDataInput):
			chars = CharsConsoleInput(); //���� �������� � �������
			ShowOutputType(); //����� ��������� �� ���������� ��������� ������ � ����
			userChoice = GetChoise(); //���� ����������������� �������
			if (userChoice == Yes) {
				InputCharsFileOutput(chars);//���������� ������� ��������
			}
			break;
		case (FileDataInput):
			chars = CharsFileInput(); //���� �������� �� �����
			CharsConsoleOutput(chars); //����� ��������� ������ �� �������
			break;
		}
		CharCountAlghoritm(&chars, text);//�������� ����� ��������� ��������
		StatisticConsoleOutput(chars);//����� ���������� ��������
			ShowOutputType(); //����� ��������� �� ���������� ��������� ������ � ����
			userChoice = GetChoise(); // ���� ����������������� �������
			if (userChoice == Yes)
			{
				StaticticFileOutput(chars); //���������� ��������� ������� � ����
			}
		text.clear(); //������ ������� ������
		chars.clear();//������ ������� ���������
		std::cout << "������� Esc ����� ��������� ������ ���������." << std::endl;
		std::cout << "������� Enter ����� ����������." << std::endl;
		userChoice = _getch(); //���� ���� ������� ��������� � ����������
	} while (userChoice != QUIT); //�������� ��� ��� ������� ����� ���� ������� Quit
}
