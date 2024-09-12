#include "ConsoleOutput.h"//����������� HeaderFile � ������� ������ �� �������


void StatisticConsoleOutput(std::map<std::string, unsigned> chars)
{
	std::cout << "����������" << std::endl;
	for (const auto& [curentChar, count] : chars) {
		std::cout << "'" << curentChar << "'= " << count << std::endl;
	}
}

void CharsConsoleOutput(std::map<std::string, unsigned> chars)
{
	std::cout << "�������� �������:" << std::endl;
	for (const auto& [curentChar, count] : chars) {
		std::cout << "'" << curentChar << "' ";
	}
	std::cout << std::endl;
}

void TextConsoleOutput(std::vector<std::string> text)
{
	std::cout << "������� �����" << std::endl;
	for (auto iter = text.begin(); iter < text.end(); ++iter) {
		std::cout << *iter << std::endl;
	}
}
