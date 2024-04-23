// Copyright 2022 UNN-IASR
#include "textgen.h"
#include <stdlib.h>
#include <iterator>
typedef std::deque<std::string> prefix;
std::vector<std::string> generator::read_vchodnoi_fail(std::string filename) {
    std::string word = "";
    char cimvol;
    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        std::cout << "Cannot open input file." << std::endl;
    } else {
        while (file.get(cimvol)) {
            if (cimvol == ' ' || cimvol == '\t' ||
                cimvol == '\n' || cimvol == '\0' || cimvol == '\r') {
                if (word.size() != 0 && (cimvol == ' ' || cimvol == '\t' ||
                    cimvol == '\n' || cimvol == '\0' || cimvol == '\r')) {
                    this->words.push_back(word + ' ');
                    word.clear();
                    word.resize(0);
                }
            } else {
                word += cimvol;
            }
        }
    }
    file.close();
    return words;
}
std::map<prefix, std::vector<std::string>> generator::
sozdaem_tablicu(std::vector<std::string>words) {
    prefix pref;
    std::vector<std::string> suffix;
    std::map<prefix, std::vector<std::string>>::iterator it;
    for (auto word : words) {
        if (pref.empty() || pref.size() < NPREF) {
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
//выбираем следующие после первого префиксы
std::deque<std::string>generator::
prefixi(std::map<prefix, std::vector<std::string>> statetab) {
    prefix pref;
    std::map<prefix, std::vector<std::string>>::iterator ita =
    statetab.begin();
    int delitel = statetab.size();
    srand(4561);
    unsigned int* k = 3;
    int pos_start = rand_r(k) % delitel;
    int count = 0;
    while (count != pos_start && ita != statetab.end()) {
        count++;
        ita++;
    }
    prefix pref_chek = ita->first;
    std::deque<std::string>::iterator it1 = pref_chek.begin();
    for (auto word : pref_chek) {
        pref.push_back(word);
    }
    return pref;
}
std::string generator::suffix_poick
(prefix f, std::map<std::deque<std::string>,
std::vector<std::string>> statetab) {
    std::map<prefix, std::vector<std::string>>::iterator itb;
    itb = statetab.find(f);
    if (itb != statetab.end()) {
        std::vector<std::string> suf = itb->second;
        std::string result = "";
        result += suf[rand() % suf.size()];
        return result;
    }
    std::string result = "";
    return result;
}
std::string generator::itogovii_text
(std::map<prefix, std::vector<std::string>> statetab) {
    std::string result = "";
    prefix pref;
    std::map<prefix, std::vector<std::string>>::iterator i =
    statetab.begin();
    prefix p = i->first;
    for (auto word : p) {
        pref.push_back(word);
    }
    prefix prefix = pref;
    int count = 0;
    for (auto word : prefix) {
        result += word + ' ';
        count++;
    }
    std::string stroka = "";
    while (count < MAXGEN) {
        stroka = suffix_poick(prefix, statetab);
        if (stroka == "") {
            prefix = prefixi(statetab);
            stroka = suffix_poick(prefix, statetab);
        }
        result += stroka + ' ';
        count++;
        stroka.pop_back();
        prefix.pop_front();
        prefix.push_back(stroka);
    }
    return result;
}
generator::generator() {}
