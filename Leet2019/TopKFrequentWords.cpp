﻿#include "stdafx.h"


//Given a non-empty list of words, return the k most frequent elements.
//Your answer should be sorted by frequency from highest to lowest. If two words
//have the same frequency, then the word with the lower alphabetical order comes
//first.
//
//Example 1:
//Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
//Output: ["i", "love"]
//Explanation: "i" and "love" are the two most frequent words.
//    
//Note that "i" comes before "love" due to a lower alphabetical order.
//
//Example 2:
//Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"],
//k = 4
//Output: ["the", "is", "sunny", "day"]
//Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
//    with the number of occurrence being 4, 3, 2 and 1 respectively.
//
//Note:
//You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
//Input words contain only lowercase letters.
//Follow up:
//Try to solve it in O(n log k) time and O(n) extra space.

namespace Solution2019
{
	namespace TopKFrequentWords
	{
		namespace HashMapAndPriorityQueue {
			vector<string> topKFrequent(vector<string>& words, int k) {
				unordered_map<string, int> map;
				for (string w : words) { map[w]++; }

				auto comp = [](const pair<string, int>& p1, const pair<string, int>& p2) {
					if (p1.second == p2.second) { return p1.first < p2.first; }
					return p1.second > p2.second;
				};

				priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(comp);

				for (auto& p : map) {
					pq.push({ p.first, p.second });
					if (pq.size() > k) {
						pq.pop();
					}
				}
				vector<string> result;
				while (!pq.empty()) {
					result.insert(result.begin(), pq.top().first);
					pq.pop();
				}
				return result;
			}
		}

		namespace HashMapAndVector {
			vector<string> topKFrequent(vector<string>& words, int k) {
				unordered_map<string, int> myMap;
				for (string w : words) {
					myMap[w] ++;
				}

				vector<pair<string, int>> A;
				for (auto& p : myMap) {
					A.push_back(p);
				}
				auto comp = [](const pair<string, int>& p1, const pair<string, int>& p2) {
					if (p1.second == p2.second) { return p1.first < p2.first; }
					return p1.second > p2.second;
				};
				sort(A.begin(), A.end(), comp);

				vector<string> result;
				int i = 0;
				for (pair<string, int>& a : A) {
					result.push_back(a.first);
					i++;
					if (i == k) { break; }
				}
				return result;
			}
		}
		void Main() {
			vector<string> test = { "i", "love", "leetcode", "i", "love", "coding" };
			print(HashMapAndPriorityQueue::topKFrequent(test, 2));
		}
	}
}

