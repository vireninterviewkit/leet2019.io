#include "stdafx.h"
//There are N students in a class. Some of them are friends, while some are not. 
//Their friendship is transitive in nature. For example, if A is a direct friend 
//of B, and B is a direct friend of C, then A is an indirect friend of C. And we
//defined a friend circle is a group of students who are direct or indirect friends.
//
//Given a N*N matrix M representing the friend relationship between students in
//the class. If M[i][j] = 1, then the ith and jth students are direct friends 
//with each other, otherwise not. And you have to output the total number of 
//friend circles among all the students.
//
//Example 1:
//Input: 
//[[1,1,0],
// [1,1,0],
// [0,0,1]]
//Output: 2
//Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
//The 2nd student himself is in a friend circle. So return 2.
//
//Example 2:
//Input: 
//[[1,1,0],
// [1,1,1],
// [0,1,1]]
//Output: 1
//Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are
//direct friends, 
//so the 0th and 2nd students are indirect friends. All of them are in the same friend
//circle, so return 1.
//
//Note:
//N is in range [1,200].
//M[i][i] = 1 for all students.
//If M[i][j] = 1, then M[j][i] = 1. 

namespace Solution2019
{
	namespace FriendCircles
	{
		void dfs(int i, vector<bool>& visited, int colCount, vector<vector<int>>& M) {
			visited[i] = true;
			for (int j = 0; j < colCount; j++) {
				if (M[i][j] && !visited[j]) {
					dfs(j, visited, colCount, M);
				}
			}
		}

		int findCircleNumDFS(vector<vector<int>>& M) {
			int rowCount = M.size();
			if (rowCount == 0) { return 0; }
			int colCount = M[0].size();
			if (colCount == 0) { return 0; }
			vector<bool> visited(rowCount, false);

			int count = 0;
			for (int i = 0; i < rowCount; i++) {
				if (!visited[i]) {
					dfs(i, visited, colCount, M);
					count++;
				}
			}
			return count;
		}

		int findCircleNumBFS(vector<vector<int>>& M) {
			int rowCount = M.size();
			if (rowCount == 0) { return 0; }
			int colCount = M[0].size();
			if (colCount == 0) { return 0; }
			vector<bool> visited(rowCount, false);

			int count = 0;
			queue<int> q;
			for (int i = 0; i < rowCount; i++) {
				if (!visited[i]) {
					q.push(i);

					while (!q.empty()) {
						int cur = q.front();
						q.pop();
						visited[cur] = true;
						for (int j = 0; j < colCount; j++) {
							if (M[cur][j] && !visited[j]) {
								q.push(j);
							}
						}
					}
					count++;
				}
			}
			return count;
		}

		namespace UnionFind {
			int find(int x, vector<int>& parents) {
				return parents[x] == x ? x : find(parents[x], parents);
			}


			int findCircleNum(vector<vector<int>>& M) {
				int n = M.size();
				if (n == 0) { return 0; }

				vector<int> leads(n, 0);
				for (int i = 0; i < n; i++) { leads[i] = i; }

				int result = n;
				for (int i = 0; i < n; i++) {
					for (int j = i + 1; j < n; j++) {
						if (M[i][j]) {
							int lead1 = find(i, leads);
							int lead2 = find(j, leads);
							if (lead1 != lead2) {
								leads[lead1] = lead2;
								result--;
							}
						}
					}
				}
				return result;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

