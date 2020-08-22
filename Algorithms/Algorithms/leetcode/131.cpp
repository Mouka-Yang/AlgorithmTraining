#include "header.h"
using StrIter = std::string::const_iterator;
class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s)
    {
        findPalindrome(s.begin(), s.end());
        return totalResults_;
    }

    void findPalindrome(StrIter start, StrIter end)
    {
        if (start == end) {
            totalResults_.push_back(result_);
            return;
        }

        auto curr = std::next(start, 1);
        while (curr <= end) {
            if (isPalindrome(start, curr)) {
                result_.push_back(std::string(start, curr));
                findPalindrome(curr, end);
                result_.pop_back();
            }
            curr++;
        }
    }

    bool isPalindrome(StrIter start, StrIter end)
    {
        end--;
        while (start < end && *start == *end) {
            start++;
            end--;
        }

        return start >= end;
    }

private:
    std::vector<std::string>              result_{};
    std::vector<std::vector<std::string>> totalResults_{};
};

int main()
{
    std::string a{"aab"};
    Solution().partition(a);
}