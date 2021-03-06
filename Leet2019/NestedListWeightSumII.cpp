#include "stdafx.h"
//Given a nested list of integers, return the sum of all integers in the 
//list weighted by their depth.
//
//Each element is either an integer, or a list -- whose elements may also
//be integers or other lists.
//
//Different from the previous question where weight is increasing from 
//root to leaf, now the weight is defined from bottom up. i.e., the leaf
//level integers have weight 1, and the root level integers have the 
//largest weight.
//
//Example 1:
//Input: [[1,1],2,[1,1]]
//Output: 8 
//Explanation: Four 1's at depth 1, one 2 at depth 2.
//
//Example 2:
//Input: [1,[4,[6]]]
//Output: 17 
//Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 
//1*3 + 4*2 + 6*1 = 17.

namespace Solution2019
{
	namespace NestedListWeightSumII
	{
		/*
		// This is the interface that allows for creating nested lists.
		// You should not implement it, or speculate about its implementation
		class NestedInteger {
		public:
			// Constructor initializes an empty nested list.
			NestedInteger();

			// Constructor initializes a single integer.
			NestedInteger(int value);

			// Return true if this NestedInteger holds a single integer, rather than a nested list.
			bool isInteger() const;

			// Return the single integer that this NestedInteger holds, if it holds a single integer
			// The result is undefined if this NestedInteger holds a nested list
			int getInteger() const;

			// Set this NestedInteger to hold a single integer.
			void setInteger(int value);

			// Set this NestedInteger to hold a nested list and adds a nested integer to it.
			void add(const NestedInteger& ni);

			// Return the nested list that this NestedInteger holds, if it holds a nested list
			// The result is undefined if this NestedInteger holds a single integer
			const vector<NestedInteger>& getList() const;
		};

		int depthSumInverse(vector<NestedInteger>& nestedList) {
			int len = nestedList.size();
			if (len == 0) { return 0; }

			vector<vector<int>> results;
			queue<NestedInteger> q;
			for (auto n : nestedList) { q.push(n); }

			while (!q.empty()) {
				int sz = q.size();
				vector<int> level;
				while (sz) {
					sz--;
					NestedInteger cur = q.front();
					q.pop();
					if (cur.isInteger()) { level.push_back(cur.getInteger()); }
					else {
						for (NestedInteger n : cur.getList()) { q.push(n); }
					}
				}
				results.push_back(level);
			}

			int result = 0;
			int weight = results.size();
			for (vector<int>& r : results) {
				result += accumulate(r.begin(), r.end(), 0) * weight;
				weight--;
			}
			return result;
		}

		int depthSumInverseAnother(vector<NestedInteger>& nestedList) {
			int sum = 0;
			int result = 0;
			vector<NestedInteger> newList;
			while(!nestedList.empty()) {
				newList.clear();
				for (NestedInteger n : nestedList) {
					if (n.isInteger()) {sum += n.getInteger();}
					else {
						for (auto i : n.getList()) {newList.push_back(i);}
					}
				}
				result += sum;
				swap(nestedList, newList);
			}
			return result;
		}
		*/
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

