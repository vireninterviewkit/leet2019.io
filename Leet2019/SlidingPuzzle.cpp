#include "stdafx.h"

//On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and
//an empty square represented by 0.
//A move consists of choosing 0 and a 4-directionally adjacent number and
//swapping it.
//The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
//Given a puzzle board, return the least number of moves required so that the
//state of the board is solved. If it is impossible for the state of the board to
//be solved, return -1.
//
//Examples:
//Input: board = [[1,2,3],[4,0,5]]
//Output: 1
//Explanation: Swap the 0 and the 5 in one move.
//Input: board = [[1,2,3],[5,4,0]]
//Output: -1
//Explanation: No number of moves will make the board solved.
//Input: board = [[4,1,2],[5,0,3]]
//Output: 5
//Explanation: 5 is the smallest number of moves that solves the board.
//An example path:
//After move 0: [[4,1,2],[5,0,3]]
//After move 1: [[4,1,2],[0,5,3]]
//After move 2: [[0,1,2],[4,5,3]]
//After move 3: [[1,0,2],[4,5,3]]
//After move 4: [[1,2,0],[4,5,3]]
//After move 5: [[1,2,3],[4,5,0]]
//Input: board = [[3,2,4],[1,5,0]]
//Output: 14
//
//Note:
//board will be a 2 x 3 array as described above.
//board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].

namespace Solution2019
{
	namespace SlidingPuzzle
	{
		namespace BFS { // BFS is much faster
			int slidingPuzzle(vector<vector<int>>& board) {
				string target = "123450";
				string start = "";
				for (int i = 0; i < board.size(); i++) {
					for (int j = 0; j < board[0].size(); j++) {
						start += to_string(board[i][j]);
					}
				}

				unordered_set<string> visited;
				visited.insert(start);
				vector<vector<int>> dirs = { { 1, 3 }, { 0, 2, 4 }, { 1, 5 }, { 0, 4 }, { 1, 3, 5 }, { 2, 4 } };
				queue<string> q;
				q.push(start);
				int result = 0;

				while (!q.empty()) {
					int sz = q.size();
					while (sz) {
						sz--;
						string cur = q.front();
						q.pop();
						if (cur == target) { return result; }

						int zero = cur.find('0');
						for (int dir : dirs[zero]) {
							string next = cur;
							swap(next[zero], next[dir]);
							if (visited.find(next) != visited.end()) { continue; }
							visited.insert(next);
							q.push(next);
						}
					}
					result++;
				}
				return -1;
			}
		
		}
		namespace DFSVerySlow {
			unordered_map<int, vector<int>> moves = { {0,{1,3}},{1,{0,2,4}},{2,{1,5}},{3,{0,4}},{4,{3,5,1}},{5,{4,2}} };
			void dfs(string s, unordered_map<string, int>& m, int curZero, int swapZero, int curMove, int& minMove) {
				swap(s[curZero], s[swapZero]);
				if (s == "123450") { minMove = min(minMove, curMove); }
				if (curMove < minMove && (m[s] == 0 || m[s] > curMove)) {
					m[s] = curMove;
					for (int newZero : moves[swapZero]) {
						dfs(s, m, swapZero, newZero, curMove + 1, minMove);
					}
				}
			}

			int slidingPuzzle(vector<vector<int>>& board) {
				string s = to_string(board[0][0]) + to_string(board[0][1]) + to_string(board[0][2]) + to_string(board[1][0]) + to_string(board[1][1]) + to_string(board[1][2]);
				unordered_map<string, int> m; // previous setup string, minMove count
				int minMoves = INT_MAX;
				dfs(s, m, s.find('0'), s.find('0'), 0, minMoves);
				return minMoves == INT_MAX ? -1 : minMoves;
			}
		}
		void Main() {
			vector<vector<int>> test = { {1,2,3},{4,0,5} };
			print(BFS::slidingPuzzle(test));
		}
	}
}

