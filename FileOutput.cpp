#include "FileOutput.h"//����������� HeaderFile � ������� ������ � ����
#include <fstream>//���������� ����� � ������ �� �����
#include <iostream>//���������� ����� � ������
#include "Checks.h"//����������� HeaderFile � ���������� ������ ����������������� �����
#include "MainMenu.h"//����������� HeaderFile � Enum menu
#include "PersonalInterface.h"//����������� HeaderFile � ���������������� �����������
#include <filesystem>//����������� ���������� ��� �������� ��������� �����
class FileWriteException//���������������� ����� ������ ��������� ��������������
{
public:
	FileWriteException(std::string message) : message{ message } {}//����������� ������ 
	std::string getMessage() const { return message; }//������� ��������� �� ������
private:
	std::string message;//���� �������� ��������� �� ������
};
void WriteStatistics(std::map<std::string, unsigned> chars,std::string fileName)//������� ������ ������ ������� � ����
{
	std::ofstream  out;//�������� ������ ������ � ����
	out.exceptions(std::ofstream::badbit | std::ofstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	try {
		out.open(fileName);//�������� ����� ��� ������
		out << " ����������:" << std::endl;
		//������ ������
		for (const auto& [curentChar, count] : chars) {
			out << "'" << curentChar << "'= " << count << std::endl;
		}
		out.close();//�������� ������
		std::cout << "������ ������� ���������" << std::endl;
	}
	catch(const std::exception&)//��������� ������
	{
		throw FileWriteException("���������� �������� ������ � ����. ��������� �������.");//������ ���������������� ������ ��������� ������
	}
}
void WriteText(std::vector<std::string> text, std::string fileName)//������� ������ ������ ������� � ����
{
	std::ofstream  out;//�������� ������ ������ � ����
	out.exceptions(std::ofstream::badbit | std::ofstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	try {
		out.open(fileName);//�������� ����� ��� ������
		for (auto iter = text.begin(); iter < text.end(); ++iter) {
			out << *iter << std::endl;
		}
		out.close();//�������� ������
		std::cout << "������ ������� ���������" << std::endl;
	}
	catch (const std::exception&)//��������� ������
	{
		throw FileWriteException("���������� �������� ������ � ����. ��������� �������.");//������ ���������������� ������ ��������� ������
	}
}
void WriteChars(std::map<std::string, unsigned> chars, std::string fileName)//������� ������ ������ ������� � ����
{
	std::ofstream  out;//�������� ������ ������ � ����
	out.exceptions(std::ofstream::badbit | std::ofstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	try {
		out.open(fileName);//�������� ����� ��� ������
		//������ ������
		for (const auto& [curentChar, count] : chars) {
			out <<  curentChar  << std::endl;
		}
		out.close();//�������� ������
		std::cout << "������ ������� ���������" << std::endl;
	}
	catch (const std::exception&)//��������� ������
	{
		throw FileWriteException("���������� �������� ������ � ����. ��������� �������.");//������ ���������������� ������ ��������� ������
	}
}
void StaticticFileOutput(std::map<std::string, unsigned> chars)
{
	std::ifstream out2;//�������� ������ ������ �� �����
	std::string fileName;//���������� ����� ��� ���� �����
	out2.exceptions(std::ifstream::badbit | std::ifstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	int userChoice = 0;//���������� ����������������� �����
	while (true) {
		std::cout << "������� ��� ����� (� ���������� .txt): ";
		std::cin >> fileName;//���� ���� � �����
		try {
			if(fileName.find(".txt") == std::string::npos)//����� � ����� ����� ����� .txt ���� ��������� �� ��������� �� ������� ������ ���������� ��������� ������
			{
				std::cout << "�� ������ ���������� � �����.���������� �������. "<<std::endl;
				continue;
			}
			try
			{
				if (std::filesystem::is_regular_file(fileName)) {//�������� �� ��������� �����
					std::cout << "���� � ����� ������ ��� ����������" << std::endl;
				}

			}
			catch (const std::exception&)
			{
				throw FileWriteException("���������� �������� ������ � ����. ��������� �������.");//������ ���������������� ������ ��������� ������

			}
			out2.open(fileName);//������� �������� �����
			ShowOutputChoise();//������� ������ �� ������� ������ �����
			userChoice = GetChoise();//���� ����������������� ������
			if (userChoice == Yes) {
				
				out2.close();//�������� ������ ������ �� �����
				WriteStatistics(chars, fileName);//������� ������ � ����
			}
			else {
				out2.close();//�������� ������ ������ �� �����
				continue;
			}
			break;
		}
		catch (const std::exception&) {
			try {
				WriteStatistics(chars, fileName);//������� ������ � ����
				break;
			}
			catch ( FileWriteException err) {//��������� ������ �������������� � ������
				std::cout << err.getMessage() << std::endl;//����� ��������� �� ������
			}
		}
		catch (FileWriteException err) {//��������� ������ �������������� � ������
			std::cout << err.getMessage() << std::endl;//����� ��������� �� ������
		}

	}
}
void InputCharsFileOutput(std::map<std::string, unsigned> chars)
{
	std::ifstream out2;//�������� ������ ������ �� �����
	std::string fileName;//���������� ����� ��� ���� �����
	out2.exceptions(std::ifstream::badbit | std::ifstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	int userChoice = 0;//���������� ����������������� �����
	while (true) {
		std::cout << "������� ��� ����� (� ���������� .txt): ";
		std::cin >> fileName;//���� ���� � �����
		try {
			if (fileName.find(".txt") == std::string::npos)//����� � ����� ����� ����� .txt ���� ��������� �� ��������� �� ������� ������ ���������� ��������� ������
			{
				std::cout << "�� ������ ���������� � �����.���������� �������. " << std::endl;
				continue;
			}
			try
			{
				if (std::filesystem::is_regular_file(fileName)) {//�������� �� ��������� �����
					std::cout << "���� � ����� ������ ��� ����������" << std::endl;
				}

			}
			catch (const std::exception&)
			{
				throw FileWriteException("���������� �������� ������ � ����. ��������� �������.");//������ ���������������� ������ ��������� ������

			}
			out2.open(fileName);//������� �������� �����
			ShowOutputChoise();//������� ������ �� ������� ������ �����
			userChoice = GetChoise();//���� ����������������� ������
			if (userChoice == Yes) {

				out2.close();//�������� ������ ������ �� �����
				WriteChars(chars, fileName);//������� ������ � ����
			}
			else {
				out2.close();//�������� ������ ������ �� �����
				continue;
			}
			break;
		}
		catch (const std::exception&) {
			try {
				WriteChars(chars, fileName);//������� ������ � ����
				break;
			}
			catch (FileWriteException err) {//��������� ������ �������������� � ������
				std::cout << err.getMessage() << std::endl;//����� ��������� �� ������
			}
		}
		catch (FileWriteException err) {//��������� ������ �������������� � ������
			std::cout << err.getMessage() << std::endl;//����� ��������� �� ������
		}

	}
}
void InputTextFileOutput(std::vector<std::string> text)
{
	std::ifstream out2;//�������� ������ ������ �� �����
	std::string fileName;//���������� ����� ��� ���� �����
	out2.exceptions(std::ifstream::badbit | std::ifstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	int userChoice = 0;//���������� ����������������� �����
	while (true) {
		std::cout << "������� ��� ����� (� ���������� .txt): ";
		std::cin >> fileName;//���� ���� � �����
		try {
			if (fileName.find(".txt") == std::string::npos)//����� � ����� ����� ����� .txt ���� ��������� �� ��������� �� ������� ������ ���������� ��������� ������
			{
				std::cout << "�� ������ ���������� � �����.���������� �������. " << std::endl;
				continue;
			}
			try
			{
				if (std::filesystem::is_regular_file(fileName)) {//�������� �� ��������� �����
					std::cout << "���� � ����� ������ ��� ����������" << std::endl;
				}

			}
			catch (const std::exception&)
			{
				throw FileWriteException("���������� �������� ������ � ����. ��������� �������.");//������ ���������������� ������ ��������� ������

			}
			out2.open(fileName);//������� �������� �����
			ShowOutputChoise();//������� ������ �� ������� ������ �����
			userChoice = GetChoise();//���� ����������������� ������
			if (userChoice == Yes) {

				out2.close();//�������� ������ ������ �� �����
				WriteText(text, fileName);//������� ������ � ����
			}
			else {
				out2.close();//�������� ������ ������ �� �����
				continue;
			}
			break;
		}
		catch (const std::exception&) {
			try {
				WriteText(text, fileName);//������� ������ � ����
				break;
			}
			catch (FileWriteException err) {//��������� ������ �������������� � ������
				std::cout << err.getMessage() << std::endl;//����� ��������� �� ������
			}
		}
		catch (FileWriteException err) {//��������� ������ �������������� � ������
			std::cout << err.getMessage() << std::endl;//����� ��������� �� ������
		}

	}
}

