#pragma once

#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <random>
using namespace std;

// Item struct for knapsack problems
typedef struct _Item {
     int value;
     int weight;

     _Item( int value, int weight ) : value( value ), weight( weight ) {}

} Item;

// Greedy 
vector<int> EgyptianFraction( unsigned int numerator, unsigned int denominator );
int MinSwapsBracketBalancing(string Brackets);
// Dynamic Programming
int OneZero_Knapsack_Naive( vector<int>value, vector<int>weight, int MaxWeight );
int OneZero_Knapsack_DP( vector<int>value, vector<int>weight, int MaxWeight );
int OneZero_Knapsack_DP( vector<Item>ItemList, int MaxWeight );
int UnboundedKnapsack_DP( vector<Item>ItemList, int MaxWeight );

// Backtracking
vector<vector<int>> KnightTour(int BoardSize, int startx, int starty);
vector<vector<int>> KnightTour_Iterative(int BoardSize, int startx, int starty);
vector<vector<int>> KnightTour_Heuristic(int BoardSize, int startx, int starty);