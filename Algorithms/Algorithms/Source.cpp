#include "common.h"

int main()
{

	// Test Binary search tree
	Node* root = NULL;
	root = BalanceInsertNode(root, 9);
	root = BalanceInsertNode(root, 5);
	root = BalanceInsertNode(root, 10);
	root = BalanceInsertNode(root, 0);
	root = BalanceInsertNode(root, 6);
	root = BalanceInsertNode(root, 11);
	root = BalanceInsertNode(root, -1);
	root = BalanceInsertNode(root, 1);
	root = BalanceInsertNode(root, 2);
	PreOrder(root);
	cin.get();

	cout << endl << "Delete key 10" << endl;
	root = BalanceDeleteNode(root, 10);
	PreOrder(root);

	cout << endl << "Delete key 80" << endl;
	root = BalanceDeleteNode(root, 80);
	PreOrder(root);

	cin.get();
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