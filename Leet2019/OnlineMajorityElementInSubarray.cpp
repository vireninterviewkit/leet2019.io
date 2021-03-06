#include "stdafx.h"
//Implementing the class MajorityChecker, which has 
//the following API:
//
//MajorityChecker(int[] arr) constructs an instance 
//of MajorityChecker with the given array arr;
//int query(int left, int right, int threshold) has 
//arguments such that:
//0 <= left <= right < arr.length representing a 
//subarray of arr;
//2 * threshold > right - left + 1, ie. the threshold
//is always a strict majority of the length of the subarray
//Each query(...) returns the element in 
//arr[left], arr[left+1], ..., arr[right] that occurs at 
//least threshold times, or -1 if no such element exists.
//
//Example:
//MajorityChecker majorityChecker = new MajorityChecker([1,1,2,2,1,1]);
//majorityChecker.query(0,5,4); // returns 1
//majorityChecker.query(0,3,3); // returns -1
//majorityChecker.query(2,3,2); // returns 2
//
//Constraints:
//1 <= arr.length <= 20000
//1 <= arr[i] <= 20000
//For each query, 0 <= left <= right < len(arr)
//For each query, 2 * threshold > right - left + 1
//The number of queries is at most 10000

namespace Solution2019
{
	namespace OnlineMajorityElementInSubarray
	{
		namespace RandomPick {
			class MajorityChecker {

			private:
				unordered_map<int, vector<int>> pos;
				vector<int> a;
				int try_bound;
			public:
				MajorityChecker(vector<int>& arr) : a(arr) {
					srand(time(nullptr));
					for (int i = 0; i < arr.size(); i++) {
						pos[arr[i]].push_back(i);
					}
					try_bound = 20;
				}

				int getOccurrence(int num, int l, int r) {
					auto iter = pos.find(num);
					if (iter == pos.end()) { return 0; }

					const vector<int>& vec = iter->second;
					auto iterL = lower_bound(vec.begin(), vec.end(), l);
					if (iterL == vec.end()) { return 0; }
					auto iterR = upper_bound(vec.begin(), vec.end(), r);
					return iterR - iterL;
				}


				int getRandom(int l, int r) {
					return rand() % (r - l + 1) + l;
				}


				int query(int left, int right, int threshold) {
					for (int i = 0; i < try_bound; i++) {
						int elem = a[getRandom(left, right)];
						if (getOccurrence(elem, left, right) >= threshold) {
							return elem;
						}
					}
					return -1;
				}
			};

			/**
			 * Your MajorityChecker object will be instantiated and called as such:
			 * MajorityChecker* obj = new MajorityChecker(arr);
			 * int param_1 = obj->query(left,right,threshold);
			 */
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

