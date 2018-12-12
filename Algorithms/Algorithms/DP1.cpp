#include "common.h"

/************** 0-1 Knapsack Problem *************************************

/*
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively.
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
You cannot break an item, either pick the complete item, or don¡¯t pick it (0-1 property).

To consider all subsets of items, there can be two cases for every item:
(1) the item is included in the optimal subset,
(2) not included in the optimal set.

Therefore, the maximum value that can be obtained from n items is max of following two values.
1) Maximum value obtained by n-1 items and W weight (excluding nth item).
2) Value of nth item plus maximum value obtained by n-1 items and W minus weight of the nth item (including nth item).

If weight of nth item is greater than W, then the nth item cannot be included and case 1 is the only possibility.

For n items with max weight w, the max value can get is

MaxValue(n,w) = value(n) + MaxValue(n-1, w- weight(n))      , Include the nth item
                MaxValue(n-1, w)                            , Exclude the nth item

if w < weight(n), then
MaxValue = MaxValue(n-1, w)

*/

int MaxValue( vector<int>value, vector<int>weight, int MaxWeight, int size ) {
     if ( size == 0 ) return 0;

     if ( weight[size - 1] > MaxWeight ) {
          return MaxValue( value, weight, MaxWeight, size - 1 );
     }

     return max(
          value[size - 1] + MaxValue( value, weight, MaxWeight - weight[size - 1], size - 1 ),
          MaxValue( value, weight, MaxWeight, size - 1 )
     );

}

int OneZero_Knapsack_Naive( vector<int>value, vector<int>weight, int MaxWeight ) {
     return MaxValue( value, weight, MaxWeight, value.size() );
}

/*

Dynamic Programming approach for 0-1 knapscak

Not work when value or weight include float items !!

*/

#define index(a,b)  ((MaxWeight+1)*(a) + (b))

int OneZero_Knapsack_DP( vector<int>value, vector<int>weight, int MaxWeight ) {
     int size = value.size();
     vector<int> totalValue;
     totalValue.resize( ( MaxWeight + 1 )*( size + 1 ) );       // Use 1-D array to represent matrix tatalValue[size+1][MaxWeight+1]

     for ( int i = 0; i <= size; i++ ) {
          for ( int j = 0; j <= MaxWeight; j++ ) {
               if ( i == 0 || j == 0 )
                    totalValue[index( i, j )] = 0;
               else if ( j >= weight[i - 1] ) {
                    totalValue[index( i, j )] = max(
                         totalValue[index( i - 1, j )],         // Not include the ith item for max weight j
                         value[i - 1] + totalValue[index( i - 1, j - weight[i - 1] )] );     // Include the ith item
               }
               else
                    // Exceed the max weight, so cannot include the ith item
                    totalValue[index( i, j )] = totalValue[index( i - 1, j )];
          }
     }

     return totalValue[index( size, MaxWeight )];

}

bool CompareItemWeight( Item a, Item b ) {
     return a.weight < b.weight;
}

int OneZero_Knapsack_DP( vector<Item>ItemList, int MaxWeight ) {
     int size = ItemList.size();
     map<int, int> totalValue;

     for ( int i = 0; i <= size; i++ ) {
          for ( int j = 0; j <= MaxWeight; j++ ) {
               if ( i == 0 || j == 0 )
                    totalValue.insert( make_pair( index( i, j ), 0 ) );
               else if ( j > ItemList[i - 1].weight )
                    totalValue.insert( make_pair(
                         index( i, j ),
                         max( totalValue[index( i - 1, j )], ItemList[i - 1].value + totalValue[index( i - 1, j - ItemList[i - 1].weight )] )
                    ) );
               else
                    totalValue.insert( make_pair(
                         index( i, j ),
                         totalValue[index( i - 1, j )] ) );
          }
     }
     return totalValue[index( size, MaxWeight )];
}

/*

Unbounded knapsack problem:

Given a knapsack weight W and a set of n items with certain value vali and weight wti,
we need to calculate minimum amount that could make up this quantity exactly.

here we are allowed to use unlimited number of instances of an item.

*/
int UnboundedKnapsack_DP( vector<Item>ItemList, int MaxWeight ) {
     int size = ItemList.size();
     vector<int> totalValue;
     totalValue.resize( MaxWeight+1 );

     for ( int i = 0; i <= MaxWeight; i++ ) {
          for ( int j = 0; j < size; j++ ) {
               if ( ItemList[j].weight <= i )
                    totalValue[i] = max(
                         totalValue[i],
                         totalValue[i - ItemList[j].weight] + ItemList[j].value
                    );
          }
     }

     return totalValue[MaxWeight];
}