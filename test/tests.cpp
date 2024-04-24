// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "../include/textgen.h"
typedef std::deque<std::string> prefix;
TEST(Test, Test_1) {
    std::vector<std::string> words = {"today", "is", "a", "good", "day"};
    generator gen;
    std::map<prefix, std::vector<std::string>> tablica =
      gen.sozdaem_tablicu(words);
    std::map<prefix, std::vector<std::string>>::iterator it =
      tablica.begin();
    prefix res = it->first;
    prefix p = gen.prefixi(tablica);
    std::string a = "";
    for (auto word : p) {
        a += word + ' ';
    }
    EXPECT_EQ(a, "today is ");
}
TEST(Test, Test_2) {
    std::vector<std::string> words = {"today", "is", "a", "good", "day"};
    generator gen;
    std::map<prefix, std::vector<std::string>> tablica =
      gen.sozdaem_tablicu(words);
    std::map<prefix, std::vector<std::string>>::iterator it =
      tablica.begin();
    prefix res = it->first;
    std::map<prefix, std::vector<std::string>>::iterator it1 =
      tablica.begin();
    std::vector<std::string> suffix = it1->second;
    EXPECT_EQ(res.front(), "a");
    EXPECT_EQ(res.back(), "good");
    EXPECT_EQ(suffix.front(), "day");
}
TEST(Test, Test_3) {
    std::vector<std::string> words = {"today", "is", "a"};
    generator gen;
    std::map<prefix, std::vector<std::string>> tablica =
      gen.sozdaem_tablicu(words);
    std::map<prefix, std::vector<std::string>>::iterator it =
      tablica.begin();
    prefix res = it->first;
    std::string suffix = gen.suffix_poick(res, tablica);
    EXPECT_EQ(suffix, "a");
}
TEST(Test, Test_4) {
    std::vector<std::string> words = {"today", "is", "a", "good", "day"};
    generator gen;
    std::map<prefix, std::vector<std::string>> tablica =
      gen.sozdaem_tablicu(words);
    std::map<prefix, std::vector<std::string>>::iterator it =
      tablica.begin();
    prefix res = it->first;
    std::string suffix = gen.suffix_poick(res, tablica);
    EXPECT_EQ(suffix, "day");
}
TEST(Test, Test_5) {
    generator gen;
    std::map<prefix, std::vector<std::string>> tablica = {
        {{"today", "is"}, {"a"}},
        {{"is", "a"}, {"good"}}
    };
    gen.MAXGEN = 4;
    std::string res = gen.itogovii_text(tablica);
    EXPECT_EQ(res, "is a good a ");
}
