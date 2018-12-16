#pragma once

// Item struct for knapsack problems
typedef struct _Item {
	int value;
	int weight;

	_Item(int value, int weight) : value(value), weight(weight) {}

} Item;

int MaxValue(vector<int> value, vector<int> weight, int MaxWeight, int size);

int OneZero_Knapsack_Naive(vector<int> value, vector<int> weight, int MaxWeight);

int OneZero_Knapsack_DP(vector<int> value, vector<int> weight, int MaxWeight);

bool CompareItemWeight(Item a, Item b);

int OneZero_Knapsack_DP(vector<Item> ItemList, int MaxWeight);

int UnboundedKnapsack_DP(vector<Item> ItemList, int MaxWeight);
