#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <deque>
#include <locale.h>
typedef std::deque<std::string> prefix;
class generator
{
private:
	std::vector<std::string> words;
public:
    //чтение файла
	std::vector<std::string> read_vchodnoi_fail(std::string filename);
	
	//создание таблицы
	std::map<prefix, std::vector<std::string>> statetab;
	int NPREF = 2;
	std::map<prefix, std::vector<std::string>> sozdaem_tablicu(std::vector<std::string>words);

	//генерация выходного текста
	int MAXGEN = 1000;
	std::deque<std::string> prefixi(std::map<prefix, std::vector<std::string>> statetab);
	std::string suffix_poick(prefix pr, std::map<prefix, std::vector<std::string>> statetab);
	std::string itogovii_text(std::map<prefix, std::vector<std::string>> statetab);
	generator();
};
