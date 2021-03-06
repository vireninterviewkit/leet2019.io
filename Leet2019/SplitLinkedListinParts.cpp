#include "stdafx.h"
//Given a (singly) linked list with head node root, write a function 
//to split the linked list into k consecutive linked list "parts".
//
//The length of each part should be as equal as possible: no two parts
//should have a size differing by more than 1. This may lead to some parts being null.
//
//The parts should be in order of occurrence in the input list, and
//parts occurring earlier should always have a size greater than or
//equal parts occurring later.
//
//Return a List of ListNode's representing the linked list parts
//that are formed.
//
//Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
//
//Example 1:
//Input:
//root = [1, 2, 3], k = 5
//Output: [[1],[2],[3],[],[]]
//Explanation:
//The input and each element of the output are ListNodes, not arrays.
//For example, the input root has root.val = 1, root.next.val = 2, 
//\root.next.next.val = 3, and root.next.next.next = null.
//The first element output[0] has output[0].val = 1, output[0].next = null.
//The last element output[4] is null, but it's string representation 
//as a ListNode is [].
//
//Example 2:
//Input: 
//root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
//Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
//Explanation:
//The input has been split into consecutive parts with size difference
//at most 1, and earlier parts are a larger size than the later parts.
//Note:
//
//The length of root will be in the range [0, 1000].
//Each value of a node in the input will be an integer in the range [0, 999].
//k will be an integer in the range [1, 50]. 

namespace Solution2019
{
	namespace SplitLinkedListinParts
	{
		vector<ListNode*> splitListToParts(ListNode* root, int k) {
			vector<ListNode*> result;

			int len = 0;
			ListNode* cur = root;
			while (cur) { len++; cur = cur->next; }
			int s1 = len / k;
			int s2 = len % k;
			
			ListNode* curHead = root;
			ListNode* curTail = root;
			ListNode* curTailPrev = nullptr;
			for (int i = 0; i < k; i++) {				
				int s = s1;
				while (s > 0) { curTailPrev = curTail; curTail = curTail->next; s--; }
				if (s2 > 0) { curTailPrev = curTail; curTail = curTail->next; s2--; }
				result.push_back(curHead);
				if (curTailPrev) { curTailPrev->next = nullptr; }
				curHead = curTail;
			}
			return result;
		}

		void print(vector<ListNode*> list)
		{
			cout << "vector of ListNode: \n";
			if (list.empty()) { cout << "Empty vector!!!\n"; return; }
			for (ListNode* n : list) {
				print(n);
			}
		}
		void Main() {
			string test = "tst test test";
			print(splitListToParts(createList({}), 3));
			//print(splitListToParts(createList({ 1, 2, 3, 4 }), 5));
			//print(splitListToParts(createList({0}), 2));
		}
	}
}

