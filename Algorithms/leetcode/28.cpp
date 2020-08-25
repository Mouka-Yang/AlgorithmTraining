#include <iostream>

class Solution {
public:
    int strStr(std::string haystack, std::string needle)
    {
        if (needle.length() == 0)
            return 0;

        auto i = haystack.find(needle);
        return i == std::string::npos ? -1 : i;
    }
};