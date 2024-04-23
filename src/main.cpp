#include <map>
#include <vector>
#include <string>
#include <deque>
#include <locale.h>
#include "textgen.h"
#include <iostream>
#include <ostream>
#include <fstream>
typedef std::deque<std::string> prefix;
using namespace std;
int main() {
  setlocale(LC_ALL, "ru");
  string file = "skazka.txt";
  generator gen;
  vector<string>words = gen.read_vchodnoi_fail(file);
  map<prefix, vector<string>>tablica = gen.sozdaem_tablicu(words);
  string itog = gen.itogovii_text(tablica);
}