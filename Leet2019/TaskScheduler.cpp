#include "stdafx.h"
//Given a char array representing tasks CPU need to do. It contains 
//capital letters A to Z where different letters represent different
//tasks. Tasks could be done without original order. Each task
//could be done in one interval. For each interval, CPU could 
//finish one task or just be idle.
//
//However, there is a non-negative cooling interval n that means
//between two same tasks, there must be at least n intervals 
//that CPU are doing different tasks or just be idle.
//
//You need to return the least number of intervals the CPU will
//take to finish all the given tasks.
//
//Example:
//Input: tasks = ["A","A","A","B","B","B"], n = 2
//Output: 8
//Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
// 
//Note:
//The number of tasks is in the range [1, 10000].
//The integer n is in the range [0, 100].

namespace Solution2019
{
	namespace TaskScheduler
	{
		int leastInterval(vector<char>& tasks, int n) {
			vector<int> map(26, 0);
			for (char c : tasks) {
				map[c - 'A'] ++;
			}
			sort(map.begin(), map.end());

			int result = 0;
			while (map[25] > 0) {
				int i = 0;
				while (i <= n) {
					if (map[25] == 0) { break; }
					if (25 - i >= 0 && map[25 - i] > 0) { map[25 - i]--; }
					result++;
					i++;
				}
				sort(map.begin(), map.end());
			}
			return result;
		}

		int leastIntervalAnother(vector<char>& tasks, int n) {

			int maxCount = 0;
			vector<int> map(26, 0);
			for (char c : tasks) {
				map[c - 'A']++;
				maxCount = max(maxCount, map[c - 'A']);
			}

			int result = (maxCount - 1) * (n + 1);
			for (int v : map) {
				if (v == maxCount) { result++; }
			}
			int len = tasks.size();
			return max(result, len);
		}

		void Main() {
			vector<char> test = { 'A', 'A', 'A', 'B', 'B', 'B'};
			print(leastInterval(test, 2));
		}
	}
}

