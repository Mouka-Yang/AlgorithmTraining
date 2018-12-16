import Greedy
import DynamicProgramming

"""

	Greedy algorithm test

"""

# Test for Minimum swap for bracket balancing
#print(Greedy.MinSwapBracketBalancing(list('[]][][')))

# Test for EgyptianFraction
#ret = Greedy.EgyptianFraction(12,13)
#for unit in ret:
#	print('1/{} '.format(unit))

"""

	Dynamic Programming

"""

# Test for 0-1 Knapsack problems
value=[24,18,18,10 ]
weight = [24,10,10,7 ]
W = 25
print(DynamicProgramming.OneZero_Knapsack_DP(weight, value, W))