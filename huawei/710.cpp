#include <algorithm>
#include <iostream>
#include <locale>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

const std::vector<std::string> ChiLang = {
    "Yi", "Er", "San", "Si", "Wu", "Liu", "Qi", "Ba", "Jiu", "Ling"};
const std::vector<std::string> EngLang = {
    "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Zero"};

enum class LangType { UNKNOWN, CHINESE, ENGLISH };
LangType langType = LangType::UNKNOWN;
using CharIter    = std::string::const_iterator;

bool isLower(char c)
{
    return c >= 'a' && c <= 'z';
}

std::pair<std::string, CharIter> getWord(CharIter startChar, CharIter endChar)
{
    auto currentChar = std::next(startChar, 1);
    while (currentChar != endChar && islower(*currentChar)) {
        std::advance(currentChar, 1);
    }

    std::string word(startChar, currentChar);
    return std::make_pair(word, currentChar);
}

LangType getInputLangType(std::string digit)
{
    if (std::find(ChiLang.cbegin(), ChiLang.cend(), digit) != ChiLang.cend()) {
        return LangType::CHINESE;
    }
    return LangType::ENGLISH;
}

bool isLegal(std::string digit)
{
    auto currentType = getInputLangType(digit);
    return currentType == langType;
}

std::string getTranslatedDigit(std::string digit)
{
    if (langType == LangType::CHINESE) {
        auto index =
            std::distance(ChiLang.cbegin(), std::find(ChiLang.cbegin(), ChiLang.cend(), digit));
        return EngLang[index];
    }
    auto index =
        std::distance(EngLang.cbegin(), std::find(EngLang.cbegin(), EngLang.cend(), digit));
    return ChiLang[index];
}

int main()
{
    std::string inputStr = "";
    // std::cin >> inputStr;
    inputStr = "OneTwoThree";

    auto        startChar = inputStr.cbegin();
    auto        endChar   = inputStr.cend();
    std::string outputStr = "";
    bool        isEnd     = false;

    while (startChar != endChar) {
        auto [digit, nextChar] = getWord(startChar, endChar);
        if (langType == LangType::UNKNOWN) {
            langType = getInputLangType(digit);
        }
        if (!isLegal(digit)) {
            std::cout << "ERROR"
                      << "\n";
            isEnd = true;
            break;
        }
        auto translatedDigit = getTranslatedDigit(digit);
        outputStr += translatedDigit;
        startChar = nextChar;
    }

    if (!isEnd) {
        std::cout << outputStr << "\n";
    }
}