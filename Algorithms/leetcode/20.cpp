#include <iostream>
#include <stack>
#include <unordered_set>

class Solution {
public:
    bool isLeft(char c)
    {
        return c == '(' or c == '{' or c == '[';
    }
    bool isRight(char c)
    {
        return c == ']' or c == '}' or c == ')';
    }

    char getRightFromLeft(char c)
    {
        char r;
        switch (c) {
        case '(':
            r = ')';
            break;
        case '{':
            r = '}';
            break;
        case '[':
            r = ']';
            break;
        }
        return r;
    }

    bool isValid(std::string s)
    {
        std::stack<char> inputLeftBracket;

        for (auto& c : s) {
            if (isLeft(c)) {
                inputLeftBracket.push(c);
            } else {
                if (inputLeftBracket.empty()) {
                    return false;
                } else {
                    auto currentLeft = inputLeftBracket.top();
                    if (getRightFromLeft(currentLeft) != c) {
                        return false;
                    } else {
                        inputLeftBracket.pop();
                    }
                }
            }
        }

        return inputLeftBracket.empty();
    }
};

int main()
{
    std::string input;
    std::cin >> input;
    auto res = Solution().isValid(input);
    std::cout << res << std::endl;
}