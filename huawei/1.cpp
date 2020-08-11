/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: 上机编程认证
 * Note: 缺省代码仅供参考，可自行决定使用、修改或删除
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

constexpr auto ARR_LEN = 7 * 24;
using LongInt = long long;
// 待实现函数，在此函数中填入答题代码
class Solution
{
public:
    vector<int> GetBestTimeWindow(int n, const vector<int> &arr) const
    {
        // TODO: 在此添加你的代码
        int startIndex = 0;
        int endIndex = -1;
        LongInt totalAccessCount = 0;

        int startIndexOfMaxWindow = -1;
        int endIndexOfMaxWindow = -1;
        int maxWindowsLength = 0;

        while (startIndex < ARR_LEN)
        {
            if (totalAccessCount <= n)
            {
                // endIndex = (endIndex + 1) % ARR_LEN;
                if (endIndex - startIndex + 1 > maxWindowsLength)
                {
                    startIndexOfMaxWindow = startIndex;
                    maxWindowsLength = endIndex - startIndex + 1;
                }
                endIndex++;
                totalAccessCount += arr[endIndex % ARR_LEN];
            }
            else
            {
                totalAccessCount -= arr[startIndex];
                startIndex++;
            }
        }

        if (maxWindowsLength == 0)
        {
            return vector<int>{-1, -1};
        }
        return vector<int>({startIndexOfMaxWindow, (startIndexOfMaxWindow + maxWindowsLength - 1) % ARR_LEN});
    }
};

// 以下为考题输入输出框架，此部分代码不建议改动
inline int ReadInt()
{
    int number;
    std::cin >> number;
    return number;
}

template <typename T>
inline std::vector<T> ReadVector(int size)
{
    std::vector<T> objects(size);
    for (int i = 0; i < size; ++i)
    {
        std::cin >> objects[i];
    }
    return objects;
}

template <typename T>
inline void WriteVector(const std::vector<T> &objects, char delimeter = ' ')
{
    auto it = objects.begin();
    if (it == objects.end())
    {
        return;
    }
    std::cout << *it;
    for (++it; it != objects.end(); ++it)
    {
        std::cout << delimeter << *it;
    }
}

int main()
{
    int n = ReadInt();
    vector<int> arr = ReadVector<int>(ARR_LEN);
    Solution solu;
    vector<int> res = solu.GetBestTimeWindow(n, arr);
    WriteVector(res);
    return 0;
}
