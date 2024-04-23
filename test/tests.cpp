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
    EXPECT_EQ(res.front(), "today");
    EXPECT_EQ(res.back(), "is");
}
TEST(Test, Test_2) {
    std::vector<std::string> words = {"today", "is", "a", "good", "day"};
    generator gen;
    std::map<prefix, std::vector<std::string>> tablica =
      gen.sozdaem_tablicu(words);
    std::map<prefix, std::vector<std::string>>::iterator it =
      tablica.begin();
    prefix res = it->first;
    std::vector<std::string>> suffix = it->second;
    EXPECT_EQ(res.front(),"today");
    EXPECT_EQ(res.back(),"is");
    EXPECT_EQ(suffix.front(),"a");
}
TEST(Test, Test_3) {
    std::vector<std::string> words = {"today", "is", "a"};
    generator gen;
    std::map<prefix, std::vector<std::string>> tablica =
      gen.sozdaem_tablicu(words);
    std::map<prefix, std::vector<std::string>>::iterator it =
      tablica.begin();
    prefix res = it->first;
    string suffix = gen.suffix_poick(res,tablica);
    EXPEECT_EQ(suffix,"a");
}
TEST(Test, Test_4) {
    std::vector<std::string> words = {"today", "is", "a", "good", "day"};
    generator gen;
    std::map<prefix, std::vector<std::string>> tablica =
      gen.sozdaem_tablicu(words);
    std::map<prefix, std::vector<std::string>>::iterator it =
      tablica.begin();
    prefix res = it->first;
    string suffix = gen.suffix_poick(res,tablica);
    EXPEECT_EQ(suffix,"a");
TEST(Test, Test_5) {
    generator gen;
    std::map<prefix, std::vector<std::string>> tablica = {
        {{"today", "is"}, {"a"}},
        {{"is", "a"}, {"good"}}
    };
    gen.MAXGEN = 4;
    std::string res = gen.itogovii_text(tablica);
    EXPECT_EQ(res,"today is a good");
}
