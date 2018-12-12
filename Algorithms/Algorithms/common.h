#pragma once

#include <Windows.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

// Item struct for knapsack problems
typedef struct _Item {
     int value;
     int weight;

     _Item( int value, int weight ) : value( value ), weight( weight ) {}

} Item;

// Greedy 
vector<int> EgyptianFraction( unsigned int numerator, unsigned int denominator );

// Dynamic Programming
int OneZero_Knapsack_Naive( vector<int>value, vector<int>weight, int MaxWeight );
int OneZero_Knapsack_DP( vector<int>value, vector<int>weight, int MaxWeight );
int OneZero_Knapsack_DP( vector<Item>ItemList, int MaxWeight );
int UnboundedKnapsack_DP( vector<Item>ItemList, int MaxWeight );
