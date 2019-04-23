/*
Ransom Note

Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
  public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> letters(26, 0);
        for (char &c : magazine)
            letters[c - 'a']++;

        for (char &c : ransomNote)
            if (--letters[c - 'a'] > 0)
                return false;

        return true;
    }
};