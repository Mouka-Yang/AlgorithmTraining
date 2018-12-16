#include "common.h"
#include "Greedy.h"

/******************** Egyptian Fraction ****************************/
/*
Every positive fraction can be represented as sum of unique unit fractions. 
A fraction is unit fraction if numerator is 1 and denominator is a positive integer, 
for example 1/3 is a unit fraction. Such a representation is called Egyptian Fraction as it was used by ancient Egyptians.

Egyptian Fraction Representation of 2/3 is 1/2 + 1/6
Egyptian Fraction Representation of 6/14 is 1/3 + 1/11 + 1/231
Egyptian Fraction Representation of 12/13 is 1/2 + 1/3 + 1/12 + 1/156

Input : numerator, denominator of the positive fraction
Generally assume that numerator < denominator

Return : List of denominators of Corresponding unit fractions

*/
vector<int> EgyptianFraction( unsigned int numerator, unsigned int denominator ) 
{
     vector<int> ret;
     vector<int> remain;
     int unit;

     if ( denominator % numerator == 0)   // eg. 2/6
     {
          ret.push_back( denominator / numerator );
          return ret;
     }
     else if ( numerator < denominator )
     {
          unit = denominator / numerator + 1;
          ret.push_back( unit );
          remain = EgyptianFraction( numerator*unit - denominator, denominator*unit );
     }
     else 
     {
          ret.push_back( numerator / denominator );
          remain = EgyptianFraction( numerator % denominator, denominator );
     }

     ret.insert( end( ret ), begin( remain ), end( remain ) );
     return ret;
}

/****************** Minimum Swaps for Bracket Balancing *******************/
/*
You are given a string of 2N characters consisting of N กฎ[กฎ brackets and N กฎ]กฏ brackets.
A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings. 
We can make an unbalanced string balanced by swapping adjacent characters. 
Calculate the minimum number of swaps necessary to make a string balanced.

Examples: 

Input  : []][][
Output : 2
First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]

Input  : [[][]]
Output : 0
String is already balanced.

Solution:

 If the first X characters form a balanced string, 
 we can neglect these characters and continue on. 
 If we encounter a กฎ]กฏ before the required กฎ[กฎ, 
 then we must start swapping elements to balance the string.
*/

int MinSwapsBracketBalancing(string Brackets) {
	vector<int> leftBrackets;

	// Get positions of all left brackets
	for (auto i = 0;i<Brackets.size(); i++) {
		if (Brackets[i] == '[')
			leftBrackets.push_back(i);
	}

	auto count = 0;	// Current unbalanced left brackets
	auto pos = 0;	// Next position of next left brackets
	auto sum = 0;	// Total moves to balance brackets

	for (auto i = 0; i < Brackets.size(); i++) {
		if (Brackets[i] == '[') {
			count++;
			pos++;
		}
		else if (--count < 0) {
			// Get unbalanced right bracket
			// Swap it with next left bracket
			swap(Brackets[i], Brackets[leftBrackets[pos]]);
			sum += leftBrackets[pos] - i;
		}
	}

	return sum;

}
