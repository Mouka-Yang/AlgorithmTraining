/*
 Word Ladder

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <list>
using namespace std;

class Solution
{
  public:
    bool canTransform(string &a, string &b)
    {
        auto diff = 0;
        for (auto i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
                diff++;
            if (diff > 1)
                return false;
        }
        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int end_i = 0;
        for (; end_i < wordList.size(); end_i++)
        {
            if (wordList[end_i] == endWord)
            {
                break;
            }
        }
        if (end_i == wordList.size())
            return 0;

        wordList.push_back(beginWord);
        int start_i = wordList.size() - 1;

        vector<unordered_set<int>> adj(wordList.size());
        for (auto i = 0; i < wordList.size(); i++)
        {
            for (auto j = 0; j < wordList.size(); j++)
            {
                if (i != j && canTransform(wordList[i], wordList[j]))
                {
                    adj[i].insert(j);
                    adj[j].insert(i);
                }
            }
        }

        vector<int> dist(wordList.size(), -1);
        vector<int> visited(wordList.size(), 0);
        list<int> queue;
        dist[start_i] = 0;
        visited[start_i] = 1;
        queue.push_back(start_i);
        while (!queue.empty())
        {
            int cur = queue.front();
            queue.pop_front();

            for (auto &cur_adj : adj[cur])
            {
                if (!visited[cur_adj])
                {
                    visited[cur_adj] = 1;
                    dist[cur_adj] = dist[cur] + 1;

                    if (cur_adj == end_i)
                        break;
                    queue.push_back(cur_adj);
                }
            }
            if (dist[end_i] >= 0)
                break;
        }

        for_each(adj.begin(), adj.end(), [&wordList](const unordered_set<int> &x) {
            for_each(x.begin(), x.end(), [&wordList](const int y) {
                cout << wordList[y] << " ";
            });
            cout << "\n";
        });

        return dist[end_i]+1;
    }
};

int main()
{
    string begin = "hit";
    string end = "cog";
    vector<string> mylist = {"hot", "dot", "dog", "lot", "log", "cog"};
    Solution().ladderLength(begin, end, mylist);
}