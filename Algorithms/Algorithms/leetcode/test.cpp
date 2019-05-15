#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    unordered_map<int, int> aa;
    cout << aa.begin()._Ptr << " " << next(aa.begin())._Ptr << " "  << endl;
}