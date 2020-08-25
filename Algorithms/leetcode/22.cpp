#include "header.h"
class Solution {
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        generatePartialParenthesis(n, 0, 0);
        return results_;
    }
    void generatePartialParenthesis(int n, int insertedLeftParenNum, int insertedRightParenNum)
    {
        if (insertedLeftParenNum == n) {
            if (insertedRightParenNum != n) {
                currentResult.append(n - insertedRightParenNum, ')');
            }
            results_.push_back(currentResult);
        }
        else {
            auto currentLength = currentResult.length();
            for (auto i = 0; i <= std::min(insertedLeftParenNum, insertedLeftParenNum - insertedRightParenNum); i++) {
                currentResult.append(i, ')');
                currentResult.push_back('(');
                generatePartialParenthesis(n, insertedLeftParenNum + 1, insertedRightParenNum + i);
                currentResult.erase(currentResult.begin() + currentLength, currentResult.end());
            }
        }
    }

private:
    std::vector<std::string> results_{};
    std::string currentResult{};
};

int main()
{
    Solution().generateParenthesis(3);
}