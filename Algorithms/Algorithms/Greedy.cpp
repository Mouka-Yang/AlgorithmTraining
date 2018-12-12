#include "common.h"

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

