#include "stdafx.h"
//Given two arrays arr1 and arr2, the elements of arr2 are
//distinct, and all elements in arr2 are also in arr1.
//
//Sort the elements of arr1 such that the relative ordering 
//of items in arr1 are the same as in arr2.  Elements that 
//don't appear in arr2 should be placed at the end of arr1 
//in ascending order.
//
//Example 1:
//Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
//Output: [2,2,2,1,4,3,3,9,6,7,19]
//
//Constraints:
//arr1.length, arr2.length <= 1000
//0 <= arr1[i], arr2[i] <= 1000
//Each arr2[i] is distinct.
//Each arr2[i] is in arr1.

namespace Solution2019
{
	namespace RelativeSortArray
	{
		vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
			int len2 = arr2.size();
			if (len2 == 0) { return arr1; }
			vector<int> result;

			map<int, int> map;
			for (int i : arr1) { map[i]++; }
			
			for (int i : arr2) {
				for (int j = 0; j < map[i]; j++) { result.push_back(i); }
				map[i] = 0;
			}
			for (auto& it : map) {
				for (int i = 0; i < it.second; i++) { result.push_back(it.first); }
			}
			return result;
		}

		void Main() {
			vector<int> a1 = { 2, 21, 43, 38, 0, 42, 33, 7, 24, 13, 12, 27, 12, 24, 5, 23, 29, 48, 30, 31 };
			vector<int> a2 = { 2, 42, 38, 0, 43, 21 };
			print(relativeSortArray(a1, a2));
		}
	}
}

