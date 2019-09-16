#include "stdafx.h"
//In a deck of cards, each card has an integer written on it.
//
//Return true if and only if you can choose X >= 2 such that it is 
//possible to split the entire deck into 1 or more groups of cards, where:
//
//Each group has exactly X cards.
//All the cards in each group have the same integer.
// 
//Example 1:
//Input: [1,2,3,4,4,3,2,1]
//Output: true
//Explanation: Possible partition [1,1],[2,2],[3,3],[4,4]
//
//Example 2:
//Input: [1,1,1,2,2,2,3,3]
//Output: false
//Explanation: No possible partition.
//
//Example 3:
//Input: [1]
//Output: false
//Explanation: No possible partition.
//
//Example 4:
//Input: [1,1]
//Output: true
//Explanation: Possible partition [1,1]
//
//Example 5:
//Input: [1,1,2,2,2,2]
//Output: true
//Explanation: Possible partition [1,1],[2,2],[2,2]
//
//Note:
//1 <= deck.length <= 10000
//0 <= deck[i] < 10000

namespace Solution2019
{
	namespace XofaKindinaDeckofCards
	{
		int gcd(int x, int y) {
			if (x > y) { return gcd(y, x); }
			return x == 0 ? y : gcd(y % x, x);
		}

		bool hasGroupsSizeX(vector<int>& deck) {
			unordered_map<int, int> map;
			for (int v : deck) { map[v]++; }

			int g = -1;
			for (auto& it : map) {
				if (g == -1) { g = it.second; }
				else {
					g = gcd(g, it.second);
				}
			}
			return g >= 2;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

