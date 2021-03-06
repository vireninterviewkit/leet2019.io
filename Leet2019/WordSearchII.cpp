#include "stdafx.h"
//Given a 2D board and a list of words from the 
//dictionary, find all words in the board.
//
//Each word must be constructed from letters of 
//sequentially adjacent cell, where "adjacent" 
//cells are those horizontally or vertically 
//neighboring. The same letter cell may not be 
//used more than once in a word.
//
//Example:
//Input: 
//board = [
//  ['o','a','a','n'],
//  ['e','t','a','e'],
//  ['i','h','k','r'],
//  ['i','f','l','v']
//]
//words = ["oath","pea","eat","rain"]
//Output: ["eat","oath"]
// 
//Note:
//All inputs are consist of lowercase letters a-z.
//The values of words are distinct.

namespace Solution2019
{
	namespace WordSearchII
	{
		class Trie {
			struct Node {
				Node* children[26];
				bool isEnd;
				Node() {
					isEnd = false;
					memset(children, 0, sizeof(children));
				}
			};
		public:
			Node* root;
			Trie() { root = new Node(); }

			void addWord(string& word) {
				Node* cur = root;
				for (char c : word) {
					if (cur->children[c - 'a'] == nullptr) {
						cur->children[c - 'a'] = new Node();
					}
					cur = cur->children[c - 'a'];
				}
				cur->isEnd = true;
			}

			int hasWord(string& word) {
				Node* cur = root;
				for (char c : word) {
					if (cur->children[c - 'a'] == nullptr) { return 0; }
					cur = cur->children[c - 'a'];
				}
				int result = cur->isEnd ? 2 : 1;
				if (result == 2) { cur->isEnd = false; }
				return result;
			}
		};

		void findHere(vector<vector<char>>& board, int row, int col, int rowCount, int colCount, Trie* trie, string& result, vector<string>& results) {
			if (row < 0 || row >= rowCount || col < 0 || col >= colCount || board[row][col] == '-') { return; }

			char c = board[row][col];
			board[row][col] = '-';
			result.push_back(c);

			int v = trie->hasWord(result);
			if (v == 0) {
				board[row][col] = c;
				result.pop_back();
				return;
			}
			else if (v == 2) { results.push_back(result); }

			findHere(board, row + 1, col, rowCount, colCount, trie, result, results);
			findHere(board, row - 1, col, rowCount, colCount, trie, result, results);
			findHere(board, row, col + 1, rowCount, colCount, trie, result, results);
			findHere(board, row, col - 1, rowCount, colCount, trie, result, results);

			board[row][col] = c;
			result.pop_back();
		}

		vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
			vector<string> results;
			int rowCount = board.size();
			if (rowCount == 0) { return results; }
			int colCount = board[0].size();
			if (colCount == 0) { return results; }
			int len = words.size();
			if (len == 0) { return results; }

			Trie* trie = new Trie();
			for (string w : words) { trie->addWord(w); }

			string result;
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					findHere(board, i, j, rowCount, colCount, trie, result, results);
				}
			}
			return results;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

