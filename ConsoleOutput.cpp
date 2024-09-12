#include "ConsoleOutput.h"//Подключение HeaderFile с выводом данных на консоль


void StatisticConsoleOutput(std::map<std::string, unsigned> chars)
{
	std::cout << "Статистика" << std::endl;
	for (const auto& [curentChar, count] : chars) {
		std::cout << "'" << curentChar << "'= " << count << std::endl;
	}
}

void CharsConsoleOutput(std::map<std::string, unsigned> chars)
{
	std::cout << "Считаные символы:" << std::endl;
	for (const auto& [curentChar, count] : chars) {
		std::cout << "'" << curentChar << "' ";
	}
	std::cout << std::endl;
}

void TextConsoleOutput(std::vector<std::string> text)
{
	std::cout << "Введёный текст" << std::endl;
	for (auto iter = text.begin(); iter < text.end(); ++iter) {
		std::cout << *iter << std::endl;
	}
}
