﻿#include "stdafx.h"
//You are playing the following Nim Game with your friend: 
//There is a heap of stones on the table, each time one of 
//you take turns to remove 1 to 3 stones. The one who removes
//the last stone will be the winner. You will take the first
//turn to remove the stones.
//
//Both of you are very clever and have optimal strategies for 
//the game. Write a function to determine whether you can win 
//the game given the number of stones in the heap.
//
//Example:
//
//Input: 4
//Output: false 
//Explanation: If there are 4 stones in the heap, then you will never win the game;
//             No matter 1, 2, or 3 stones you remove, the last stone will always be 
//             removed by your friend.

namespace Solution2019
{
	namespace NimGame
	{
		bool canWinNim(int n) {
			return n % 4 != 0;
		}

		namespace DP {
			bool canWinNim(int n) {
				if (n < 4) { return true; }
				vector<bool> dp(n + 1, false);
				dp[0] = true;
				dp[1] = true;
				dp[2] = true;
				dp[3] = true;
				for (int i = 4; i <= n; i++) {
					dp[i] = !dp[i - 1] || !dp[i - 2] || !dp[i - 3];
				}
				return dp[n];
			}
		}

		//从4开始递推：5、6、7能分别拿掉1、2、3个石头，对方就拿到的是4，
		//就输了，即5、6、7->true。但是当n = 8时，无论拿掉多少个石头，
		//对方拿到的都是5 / 6 / 7个石头，对方就赢了，故8->false。
		//往后依此递推，9，10，11都可以给对方留下8个，对方就输了。
		//即对于每个n是false，n + 1、n + 2、n + 3都是true，
		//n + 4都是false。递推关系满足n被4整除时返回false。
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

