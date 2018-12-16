
"""

	埃及分数

描述：每一个分数都可以表达为多个不同的单元分数的和，
单元分数： 分子为1且分母为正整数

举例：
2/3 -->	1/2 + 1/6
6/14 -->	1/3 + 1/11 + 1/231
12/13 -->	1/2 + 1/3 + 1/12 + 1/156

算法输入：
a,b
a为输入分数的分子
b为输入分数的分母

** 假定分母大于等于分子 **

输出：
对应单元分数的分母序列

eg.
Input	: 2,3
Output	: [2,6]

"""

"""

算法思路（分子 a， 分母 b）：

1. 如果 b 能整除 a，直接返回 b/a
2. 如果 b 不能整除 a，则采用贪心算法的思想，每次求出最接近 a/b 的单元分数（假定为c），再使用递归的方法求得余下部分 a/b - c 的单元分数

"""

# Code
def EgyptianFraction(numerator, denominator):
	result = []

	if denominator % numerator == 0:
		result.append(denominator // numerator)
	elif numerator < denominator:
		# 计算出最大单元分数
		unit = denominator // numerator + 1
		result.append(unit)

		# 求出余下部分的单元分数 a/b - 1/c = (a*c-1) / (b*c)
		remain = EgyptianFraction(numerator * unit - denominator,denominator * unit)
		result.extend(remain)
	# 不考虑其他情况

	return result

"""

	求使括号平衡的最小交换次数

描述：给定 2N 长度的字符串，包含N个 '[' ，N个 ']'，计算使字符串平衡的最小交换次数

平衡字符串定义：S1[S2]， 其中 S1，S2均为平衡字符串

输入：
2N长度字符串

输出：
最小交换次数

举例：

Input  : []][][
Output : 2
First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]

Input  : [[][]]
Output : 0
String is already balanced.

"""

"""

算法思路

顺序遍历字符串，当遇到不匹配的']'时（遇到相应的'['之前），将其与之后最接近它的']'交换位置


"""

# Code
def MinSwapBracketBalancing(Brackets: list):
	# 首先遍历字符串，获取所有左括号的位置
	leftBrackets = []
	leftBrackets.extend([ idx for idx, x in enumerate(Brackets) if x == '['])

	if len(leftBrackets) != len(Brackets) // 2:	
		return 0

	count = 0	# 当前还未平衡的左括号数量
	pos = 0		# 下一个左括号的位置
	sum = 0		# 总共移动次数

	i = 0
	while i < len(Brackets):
		if Brackets[i] == '[':
			# 当前遍历括号为左括号
			count += 1
			pos += 1
		else:
			# 当前括号为右括号
			count -= 1	# 不平衡左括号 - 1
			if count < 0:
				# 右括号在不平衡左括号之前出现
				# 交换两括号位置
				Brackets[i], Brackets[leftBrackets[pos]] = Brackets[leftBrackets[pos]],Brackets[i]

				sum += leftBrackets[pos] - i
				count = 0
				pos += 1
				i += 1
		i += 1


	return sum