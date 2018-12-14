#include "common.h"

int main()
{
	// Test Knight'Tour problem
     //vector<vector<int>> path = KnightTour( 4, 0, 0 );
     //vector<vector<int>> path = KnightTour_Heuristic( 4, 0, 0 );
     vector<vector<int>> path = KnightTour_Iterative(16, 0, 0);
	for (auto i : path) {
		for (auto j : i)
			cout << setw(4) << j << "  ";
		cout << endl;
	}
	system("PAUSE");

	// Test Minimum Swaps for Bracket BalancingKD
	cout << MinSwapsBracketBalancing("[[][]]][") << endl;
	system("PAUSE");

	// Test 01_Knapsack problem
	vector<int> value({ 24,18,18,10 });
	vector<int> weight({ 24,10,10,7 });
	vector<Item> itemList;
	itemList.push_back(Item(24, 24));
	itemList.push_back(Item(18, 10));
	itemList.push_back(Item(18, 10));
	itemList.push_back(Item(10, 7));
	int W = 25;
	//cout << OneZero_Knapsack_Naive( value, weight, W ) << endl;
	//cout << OneZero_Knapsack_DP( value, weight, W ) <<endl;
	//cout << OneZero_Knapsack_DP( itemList, W ) << endl;
	cout << UnboundedKnapsack_DP(itemList, W) << endl;
	system("PAUSE");

	// Test EgyptianFraction
	vector<int> ret = EgyptianFraction(12, 13);
	for (vector<int>::iterator it = ret.begin(); it < ret.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;


	system("PAUSE");
}