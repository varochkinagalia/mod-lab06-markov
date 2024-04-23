#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <deque>
#include <locale.h>
#include "textgen.h"
using namespace std;
vector<string> generator::read_vchodnoi_fail(string filename)
{
	string word = "";
	char cimvol;
	ifstream file;
	file.open(filename);
	if (!file.is_open())
	{
		cout << "Cannot open input file." << endl;
	}
	else
	{
		while (file.get(cimvol)) {
			if (cimvol == ' ' || cimvol == '\t' || cimvol == '\n' || cimvol == '\0' || cimvol == '\r') {
				if (word.size() != 0 && (cimvol == ' ' || cimvol == '\t' || cimvol == '\n' || cimvol == '\0' || cimvol == '\r')) {
					this->words.push_back(word + ' ');
					word.clear();
					word.resize(0);
				}
			}
			else {
				word += cimvol;
			}
		}
	}
	file.close();
	return words;
}
map<prefix, vector<string>>generator::sozdaem_tablicu(vector<string>words)
{
	prefix pref;
	vector<string> suffix;
	map<prefix, vector<string>>::iterator it;
	for (auto word : words)
	{
		if (pref.empty() || pref.size() < NPREF)
		{
			pref.push_back(word);
			continue;
		}
		it = statetab.find(pref);
		if (it != statetab.end()) {
			it->second.push_back(word);
			pref.pop_front();
			pref.push_back(word);
			continue;
		}
		if (it == statetab.end()) {
			suffix.push_back(word);
			statetab[pref] = suffix;
			suffix.clear();
			pref.pop_front();
			pref.push_back(word);
		}
	}
	return statetab;
}
deque<string>generator::prefixi(map<prefix, vector<string>> statetab)//выбираем последующие префиксы
{
	prefix pref;
	map<prefix, vector<string>>::iterator it=statetab.begin();
	int pos_start = rand() % statetab.size();
	int count = 0;
	while (count != pos_start && it != statetab.end()) {
		count++;
		it++;
	}
	prefix pref_chek = it->first;
	prefix::iterator it1 = pref_chek.begin();
	for (auto word : pref_chek) {
		pref.push_back(word);
	}
	return pref;
}
string generator::suffix_poick(prefix f, map<prefix, vector<string>> statetab)
{
	map<prefix, vector<string>>::iterator it;
	it = statetab.find(f);
	if (it != statetab.end()) {
		vector<string> suf = it->second;
		string result = "";
		result += suf[rand() % suf.size()];
		return result;
	}
	string result = "";
	return result;
}

string generator::itogovii_text(map<prefix, vector<string>> statetab)
{
	string result = "";
	prefix pref;
	map<prefix, vector<string>>::iterator i = statetab.begin();
	prefix p = i->first;
	for (auto word : p)
	{
		pref.push_back(word);
	}
	prefix prefix = pref;
	int count = 0;
	for (auto word : prefix)
	{
		result += word + ' ';
		count++;
	}
	string stroka = "";
	while (count < MAXGEN)
	{
		stroka = suffix_poick(prefix,statetab);
		if (stroka == "")
		{
			prefix = prefixi(statetab);
			stroka = suffix_poick(prefix, statetab);
		}
		result += stroka+' ';
		count++;
		stroka.pop_back();
		prefix.pop_front();
		prefix.push_back(stroka);
	}
	return result;
}
generator::generator() {};
