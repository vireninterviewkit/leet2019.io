#include "stdafx.h"

//You are a professional robber planning to rob houses along a street. Each house
//has a certain amount of money stashed, the only constraint stopping you from
//robbing each of them is that adjacent houses have security system connected and
//it will automatically contact the police if two adjacent houses were broken
//into on the same night.
//Given a list of non-negative integers representing the amount of money of each
//house, determine the maximum amount of money you can rob tonight without
//alerting the police.
//
//Example 1:
//Input: [1,2,3,1]
//Output: 4
//Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//             Total amount you can rob = 1 + 3 = 4.
//
//Example 2:
//Input: [2,7,9,3,1]
//Output: 12
//Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5
//(money = 1).
//             Total amount you can rob = 2 + 9 + 1 = 12.

namespace Solution2019
{
	namespace HouseRobber
	{
		int rob(vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return 0; }
			if (len == 1) { return nums[0]; }
			if (len == 2) { return max(nums[0], nums[1]); }

			int M[3] = { 0 };
			M[0] = nums[0];
			M[1] = max(nums[0], nums[1]);

			// M[i] = max(M[i-1], M[i-2] + nums[i])
			for (int i = 2; i < len; i++) {
				M[i % 3] = max(M[(i % 3 - 1 + 3) % 3], M[(i % 3 - 2 + 3) % 3] + nums[i]);
			}
			return M[(len - 1) % 3];
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

