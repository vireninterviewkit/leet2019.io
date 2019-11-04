#include "stdafx.h"

//Design a class which receives a list of words in the constructor, and
//implements a method that takes two words word1 and word2 and return the
//shortest distance between these two words in the list. Your method will be
//called repeatedly many times with different parameters. 
//
//Example:
//Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//Input: word1 = �coding�, word2 = �practice�
//Output: 3
//Input: word1 = "makes", word2 = "coding"
//Output: 1
//
//Note:
//You may assume that word1 does not equal to word2, and word1 and word2 are both
//in the list. 

namespace Solution2019
{
	namespace ShortestWordDistanceII
	{
		class WordDistance {
		private:
			unordered_map<string, vector<int>> map;
		public:
			WordDistance(vector<string>& words) {
				for (int i = 0; i < words.size(); i++) {
					map[words[i]].push_back(i);
				}
			}

			int shortest(string word1, string word2) {
				vector<int> i1s = map[word1];
				vector<int> i2s = map[word2];
				int i1 = 0;
				int i2 = 0;
				int result = INT_MAX;
				while (i1 < i1s.size() && i2 < i2s.size()) {
					result = min(result, abs(i1s[i1] - i2s[i2]));
					if (i1s[i1] < i2s[i2]) { i1++; }
					else { i2++; }
				}
				return result;
			}
		};

		/**
		 * Your WordDistance object will be instantiated and called as such:
		 * WordDistance* obj = new WordDistance(words);
		 * int param_1 = obj->shortest(word1,word2);
		 */
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

