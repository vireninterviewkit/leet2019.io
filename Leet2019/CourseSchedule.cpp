#include "stdafx.h"

//There are a total of n courses you have to take, labeled from 0 to n-1.
//Some courses may have prerequisites, for example to take course 0 you have to
//first take course 1, which is expressed as a pair: [0,1]
//Given the total number of courses and a list of prerequisite pairs, is it
//possible for you to finish all courses?
//
//Example 1:
//Input: 2, [[1,0]] 
//Output: true
//Explanation: There are a total of 2 courses to take. 
//             To take course 1 you should have finished course 0. So it is
//possible.
//
//Example 2:
//Input: 2, [[1,0],[0,1]]
//Output: false
//Explanation: There are a total of 2 courses to take. 
//             To take course 1 you should have finished course 0, and to take
//course 0 you should
//             also have finished course 1. So it is impossible.
//
//Note:
//The input prerequisites is a graph represented by a list of edges, not
//adjacency matrices. Read more about how a graph is represented.
//You may assume that there are no duplicate edges in the input prerequisites. 

namespace Solution2019
{
	namespace CourseSchedule
	{
		namespace TopologicalSort {
			bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
				if (prerequisites.size() == 0) { return true; }

				unordered_map<int, int> indegree; // course id, indegree count
				unordered_map<int, vector<int>> adj; // adjacent nodes
				for (vector<int>& pre : prerequisites) {
					adj[pre[1]].push_back(pre[0]);
					indegree[pre[1]]; //---> dont' forget to insert the starting node too!!!!
					indegree[pre[0]]++;
				}

				queue<int> q;
				for (auto p : indegree) {
					if (p.second == 0) { q.push(p.first); }
				}

				int count = 0;
				while (!q.empty()) {
					int cur = q.front();
					q.pop();
					count++;
					for (int n : adj[cur]) {
						indegree[n]--;
						if (indegree[n] == 0) { q.push(n); }
					}
				}
				return count == indegree.size();
			}
		}

		namespace DFS {
			bool dfs(int node, unordered_map<int, vector<int>>& adj, unordered_set<int>& path, unordered_set<int>& visited) {
				if (path.count(node)) { return false; }
				if (visited.count(node)) { return true; }
				visited.insert(node);
				path.insert(node);
				for (int n : adj[node]) {
					if (!dfs(n, adj, path, visited)) { return false; }
				}
				path.erase(node);
				return true;
			}

			bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
				if (prerequisites.empty()) { return true; }
				unordered_set<int> nodes;
				unordered_map<int, vector<int>> adj;
				for (vector<int>& pre : prerequisites) {
					adj[pre[1]].push_back(pre[0]);
					nodes.insert(pre[0]);
					nodes.insert(pre[1]);
				}

				unordered_set<int> path;
				unordered_set<int> visited;
				for (int n : nodes) {
					if (!dfs(n, adj, path, visited)) { return false; }
				}
				return true;
			}
		}

		void Main() {
			//vector<vector<int>> test = { {0, 1} , {1, 0} };
			vector<vector<int>> test = {{1, 0} };
			print(DFS::canFinish(2, test));
		}
	}
}

