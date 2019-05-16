#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    unordered_map<int, int> aa;
    cout << distance(aa.begin(),min_element(aa.begin(),aa.end()))<< endl;
}