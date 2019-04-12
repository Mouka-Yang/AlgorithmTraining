#include <ctime>
#include <cstdlib>
#include "common.h"
#include "misc.h"

int CountPrimes(int n) {
	vector<int> arr;
	for (int i = 2; i < n; i++) arr.push_back(i);

	int i = 0;
	while (i < sqrt(arr.size())) {
		int j = i + 1;
		while (j < arr.size()) {
			if (arr[j] % arr[i] == 0) {
				arr.erase(arr.begin() + j);
			}
			else {
				j ++;
			}
		}
		i++;
	}

	return arr.size();
}



