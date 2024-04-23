// Copyright 2022 UNN-IASR
#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_
#include <locale.h>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <deque>
#include <iterator>
typedef deque<string> prefix;
class generator {
 private:
     vector<string> words;
 public:
     //чтение файла
     vector<string> read_vchodnoi_fail(string filename);
     //создание таблицы
     map<prefix, vector<string>> statetab;
     int NPREF = 2;
     map<prefix, vector<string>> sozdaem_tablicu(vector<string>words);
     //генерация выходного текста
     int MAXGEN = 1000;
     deque<string> prefixi(map<prefix, vector<string>> statetab);
     string suffix_poick(prefix pr, map<prefix, vector<string>> statetab);
     string itogovii_text(map<prefix, vector<string>> statetab);
     generator();
};
#endif  // INCLUDE_TEXTGEN_H_
