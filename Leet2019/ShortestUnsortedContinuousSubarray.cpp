#include "stdafx.h"
//Given an integer array, you need to find one continuous subarray that if 
//you only sort this subarray in ascending order, then the whole array will 
//be sorted in ascending order, too.
//
//You need to find the shortest such subarray and output its length.
//
//Example 1:
//Input: [2, 6, 4, 8, 10, 9, 15]
//Output: 5
//Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make 
//the whole array sorted in ascending order.
//
//Note:
//Then length of the input array is in range [1, 10,000].
//The input array may contain duplicates, so ascending order here means <=.

namespace Solution2019
{
	namespace ShortestUnsortedContinuousSubarray
	{
		int findUnsortedSubarray(vector<int> nums) {
			int len = nums.size();
			int maxV = INT_MIN;
			int end = -2;
			for (int i = 0; i < len; i++)
			{
				maxV = max(maxV, nums[i]);
				if (nums[i] < maxV) { end = i; }
			}
			int start = -1;
			int minV = INT_MAX;
			for (int i = len - 1; i >= 0; i--) {
				minV = min(minV, nums[i]);
				if (nums[i] > minV) {
					start = i;
				}
			}
			return end - start + 1;
		}

		int findUnsortedSubarrayWithSort(vector<int> nums) {
			vector<int> sorted(nums.begin(), nums.end());
			sort(sorted.begin(), sorted.end());
			int len = nums.size();
			int i = 0;
			while (i<len && nums[i] == sorted[i]) { i++; }
			int j = len - 1;
			while ( j >= 0 && nums[j] == sorted[j]) { j--; }
			return j > i ? j - i + 1 : 0;
		}

		void Main() {
			print(findUnsortedSubarray({ 1, 3, 2, 2, 2 }));
			print(findUnsortedSubarray({2, 6, 4, 8, 10, 9, 15}));
		}
	}
}

