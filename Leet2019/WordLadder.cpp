#include "stdafx.h"
//Given two words (beginWord and endWord), and a dictionary's word list, 
//find the length of shortest transformation sequence from beginWord to endWord, such that:
//
//Only one letter can be changed at a time.
//Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//Note:
//
//Return 0 if there is no such transformation sequence.
//All words have the same length.
//All words contain only lowercase alphabetic characters.
//You may assume no duplicates in the word list.
//You may assume beginWord and endWord are non-empty and are not the same.
//
//Example 1:
//Input:
//beginWord = "hit",
//endWord = "cog",
//wordList = ["hot","dot","dog","lot","log","cog"]
//Output: 5
//Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//return its length 5.
//
//Example 2:
//Input:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log"]
//Output: 0
//Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
//

namespace Solution2019
{
	namespace WordLadder
	{
		namespace Short1 {
			int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
				unordered_set<string> wl(wordList.begin(), wordList.end());
				unordered_set<string> visited;
				int level = 0;

				queue<vector<string>> q;
				q.push({ beginWord });

				while (!q.empty()) {
					vector<string> path = q.front();
					q.pop();

					if (path.size() > level) {
						level = path.size();
						for (string w : visited) {
							wl.erase(w);
						}
						visited.clear();
					}

					string last = path.back();
					for (int i = 0; i < last.size(); i++) {
						string news = last;
						for (char c = 'a'; c < 'z'; c++) {
							if (c == news[i]) { continue; }
							news[i] = c;

							if (wl.find(news) != wl.end()) {
								if (news == endWord) {
									return level + 1;
								}
								else {
									vector<string> newPath = path;
									newPath.push_back(news);
									visited.insert(news);
									q.push(newPath);
								}
							}
						}
					}
				}
				return 0;
			}
		}

		namespace Short2 {
			int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
				unordered_set<string> wl(wordList.begin(), wordList.end());
				queue<string> q;
				q.push(beginWord);
				int level = 1;

				while (!q.empty()) {
					int sz = q.size();
					while (sz) {
						sz--;
						string word = q.front();
						q.pop();
						if (word == endWord) { return level; }
						wl.erase(word);

						for (int i = 0; i < word.size(); i++) {
							char tmp = word[i];
							for (char c = 'a'; c < 'z'; c++) {
								word[i] = c;
								if (wl.find(word) != wl.end()) {
									q.push(word);
								}
								word[i] = tmp;
							}
						}
					}
					level++;
				}
				return 0;
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

