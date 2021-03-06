#include "stdafx.h"
//Given two arrays, write a function to compute their intersection.
//
//Example 1:
//Input: nums1 = [1,2,2,1], nums2 = [2,2]
//Output: [2,2]
//
//Example 2:
//Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//Output: [4,9]
//Note:
//
//Each element in the result should appear as many times as it shows in both arrays.
//The result can be in any order.
//Follow up:
//
//What if the given array is already sorted? How would you optimize your algorithm?
//What if nums1's size is small compared to nums2's size? Which algorithm is better?
//What if elements of nums2 are stored on disk, and the memory is 
//limited such that you cannot load all elements into the memory at once? 

namespace Solution2019
{
	namespace IntersectionofTwoArraysII
	{
		namespace UsingMap {
			vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
				unordered_map<int, int> map1;
				for (int v : nums1) { map1[v]++; }

				unordered_map<int, int> map2;
				for (int v : nums2) { map2[v]++; }

				vector<int> result;
				for (auto& p : map1) {
					if (map2.count(p.first)) {
						int count = min(p.second, map2[p.first]);
						for (int i = 0; i < count; i++) { result.push_back(p.first); }
					}
				}
				return result;
			}
		}
		namespace BinarySearch {
			int findStartIndex(vector<int>& A, int target) {
				int start = 0;
				int end = A.size() - 1;
				while (start <= end) {
					int mid = start + (end - start) / 2;
					if (A[mid] >= target) { end = mid - 1; }
					else { start = mid + 1; }
				}
				return  (start < A.size() && A[start] == target) ? start : -1;
			}

			int findLen(vector<int>& A, int i) {
				int j = i;
				while (j < A.size() && A[j] == A[i]) { j++; }
				return j - i;
			}

			vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
				vector<int> result;
				if (nums1.size() == 0 || nums2.size() == 0) { return result; }
				sort(nums1.begin(), nums1.end());
				sort(nums2.begin(), nums2.end());
				for (int i = 0; i < nums1.size(); i++) {
					int target = nums1[i];
					int j = findStartIndex(nums2, target);
					if (j == -1) { continue; }
					for (int k = 0; k < min(findLen(nums1, i), findLen(nums2, j)); k++) {
						result.push_back(target);
					}
					while (i + 1 < nums1.size() && nums1[i] == nums1[i + 1]) { i++; }
				}
				return result;
			}
		}
		void Main() {
			vector<int> nums1 = { 1, 2 };
			vector<int> nums2 = { 1, 1 };
			print(BinarySearch::intersect(nums1, nums2));
		}
	}
}

