#include<iostream>
#include<string>

std::string space_str(std::string str);

bool is_spam(std::string str);



int main() {
	system("chcp 1251>null");
	int n;

	//Задача 1. Пробелы в строке
	std::cout << "Введите строку -> ";
	std::string str1;
	std::getline(std::cin, str1);
	std::cout << space_str(str1) << "\n\n";

	//Задача 2. Спам
	std::cout << "Введите строку -> ";
	std::string srt2;
	std::getline(std::cin, srt2);
	if (is_spam(srt2))
		std::cout << "Обнаружен спам";
	else
		std::cout << "Спама нет";


	return 0;
}

std::string space_str(std::string str) {
	std::string result(str.length()*2 - 1,' ');
	for (int i = 0; i < str.length(); i++)
		result[i * 2] = str[i];
	return result;
};


bool is_spam(std::string str) {
	for (int i = 0; i < str.length(); i++) 
		str[i] = std::tolower(str[i]);

	const int spams_number = 4;
	static const std::string spams[spams_number]{
		"100% free",
		"sales increace",
		"only today",
		"black friday"
	};
	for (int i = 0; i < spams_number; i++)
		if (str.find(spams[i]) < str.length())
			return true;

	return false;

};


