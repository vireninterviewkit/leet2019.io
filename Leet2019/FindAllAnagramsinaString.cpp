#include "stdafx.h"

//Given a string s and a non-empty string p, find all the start indices of p's
//anagrams in s.
//Strings consists of lowercase English letters only and the length of both
//strings s and p will not be larger than 20,100.
//The order of output does not matter.
//
//Example 1:
//Input:
//s: "cbaebabacd" p: "abc"
//Output:
//[0, 6]
//Explanation:
//The substring with start index = 0 is "cba", which is an anagram of "abc".
//The substring with start index = 6 is "bac", which is an anagram of "abc".
//
//Example 2:
//Input:
//s: "abab" p: "ab"
//Output:
//[0, 1, 2]
//Explanation:
//The substring with start index = 0 is "ab", which is an anagram of "ab".
//The substring with start index = 1 is "ba", which is an anagram of "ab".
//The substring with start index = 2 is "ab", which is an anagram of "ab".

namespace Solution2019
{
	namespace FindAllAnagramsinaString
	{
		vector<int> findAnagrams(string s, string p) {
			vector<int> result;
			int lens = s.size();
			int lenp = p.size();
			if (lens < lenp || lenp == 0) { return result; }

			unordered_map<char, int> to_be_found;
			for (char c : p) { to_be_found[c]++; }

			int start = 0;
			int found = 0;
			for (int end = 0; end < lens; end++) {
				char c = s[end];
				if (to_be_found.find(c) != to_be_found.end()) {
					to_be_found[c]--;
					found++;
					while (to_be_found[c] < 0) {
						to_be_found[s[start]]++;
						found--;
						start++;
					}
					if (found == lenp) { result.push_back(start); }
				}
				else {
					while (start < end) {
						to_be_found[s[start]]++;
						found--;
						start++;
					}
					start++;
				}
			}
			return result;
		}

		vector<int> findAnagramsCompareTwoHashMapArray(string s, string p) {
			vector<int> pv(26, 0);
			vector<int> sv(26, 0);
			vector<int> result;
			int lens = s.size();
			int lenp = p.size();
			if (lens < lenp) { return result; }

			for (int i = 0; i < lenp; i++) {
				pv[p[i] - 'a']++;
				sv[s[i] - 'a']++;
			}
			if (pv == sv) { result.push_back(0); }
			for (int i = lenp; i < lens; i++) {
				sv[s[i] - 'a']++;
				sv[s[i - lenp] - 'a']--;
				// checking equal is O(26) so O(1)
				if (pv == sv) { result.push_back(i - lenp + 1); }
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

