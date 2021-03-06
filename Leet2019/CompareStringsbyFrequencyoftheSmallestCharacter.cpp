#include "stdafx.h"
//Let's define a function f(s) over a non-empty string s, which 
//calculates the frequency of the smallest character in s. 
//For example, if s = "dcce" then f(s) = 2 because the smallest
//character is "c" and its frequency is 2.
//
//Now, given string arrays queries and words, return an integer
//array answer, where each answer[i] is the number of words such 
//that f(queries[i]) < f(W), where W is a word in words.
//
//Example 1:
//Input: queries = ["cbd"], words = ["zaaaz"]
//Output: [1]
//Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").
//
//Example 2:
//Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
//Output: [1,2]
//	Explanation: On the first query only f("bbb") < f("aaaa"). On the 
//	second query both f("aaa") and f("aaaa") are both > f("cc").
// 
//Constraints:
//1 <= queries.length <= 2000
//1 <= words.length <= 2000
//1 <= queries[i].length, words[i].length <= 10
//queries[i][j], words[i][j] are English lowercase letters.

namespace Solution2019
{
	namespace CompareStringsbyFrequencyoftheSmallestCharacter
	{
		int getFrequency(string s) {
			int result = 0;
			char k = s[0];
			for (char c : s) {
				if (k == c) { result++; }
				else if (c < k) { result = 1; k = c; }
			}
			return result;
		}
		vector<int> numSmallerByFrequencySlow(vector<string>& queries, vector<string>& words) {
			vector<int> result;
			vector<int> wc;
			for (string w : words) { wc.push_back(getFrequency(w)); }
			for (string q : queries) {
				int f = getFrequency(q);
				int curResult = 0;
				for (int i : wc) { if (i > f) { curResult++; } }
				result.push_back(curResult);
			}
			return result;
		}

		vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
			vector<int> result;
			vector<int> bucket(12, 0);
			for (string w : words) {
				bucket[getFrequency(w)]++;
			}
			for (int i = 10; i >= 1; i--) {
				bucket[i] += bucket[i + 1];
			}
			for (string q : queries) {
				result.push_back(bucket[getFrequency(q) + 1]);
			}
			return result;
		}

		void Main() {			
			vector<string> queries = { "bba", "abaaaaaa", "aaaaaa", "bbabbabaab", "aba", "aa", "baab", "bbbbbb", "aab", "bbabbaabb" };
			vector<string> words = { "aaabbb", "aab", "babbab", "babbbb", "b", "bbbbbbbbab", "a", "bbbbbbbbbb", "baaabbaab", "aa" };
			print(numSmallerByFrequency(queries, words));
		}
	}
}

