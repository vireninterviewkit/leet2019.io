#include "stdafx.h"
//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//For example, the following two linked lists:
//
//begin to intersect at node c1.
//
//Example 1:
//Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
//Output: Reference of the node with value = 8
//Input Explanation: The intersected node's value is 8 (note that this must not be 0 
//if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. 
//From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes before the 
//intersected node in A; There are 3 nodes before the intersected node in B.
// 
//Example 2:
//Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
//Output: Reference of the node with value = 2
//Input Explanation: The intersected node's value is 2 (note that this must not be 0 
//if the two lists intersect). From the head of A, it reads as [0,9,1,2,4]. 
//From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected 
//node in A; There are 1 node before the intersected node in B.
// 
//Example 3:
//Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
//Output: null
//Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, 
//it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, 
//while skipA and skipB can be arbitrary values.
//Explanation: The two lists do not intersect, so return null.
//
//Notes:
//If the two linked lists have no intersection at all, return null.
//The linked lists must retain their original structure after the function returns.
//You may assume there are no cycles anywhere in the entire linked structure.
//Your code should preferably run in O(n) time and use only O(1) memory.

namespace Solution2019
{
	namespace IntersectionofTwoLinkedLists
	{
		ListNode *getIntersectionNodeWithLoopAlgo(ListNode *headA, ListNode *headB) {
			if (!headA || !headB) { return nullptr; }

			ListNode* tailA = headA;
			while (tailA->next) { tailA = tailA->next; }

			tailA->next = headB;

			ListNode* slow = headA->next;
			ListNode* fast = headA->next->next;
			while (fast && fast->next) {
				if (slow == fast) { break; }
				slow = slow->next;
				fast = fast->next->next;
			}
			if (!fast || !fast->next) { tailA->next = nullptr; return nullptr; }
			fast = headA;
			while (slow != fast) {
				slow = slow->next;
				fast = fast->next;
			}
			tailA->next = nullptr;
			return slow;
		}

		ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			int lenA = 0;
			int lenB = 0;
			ListNode* curA = headA;
			ListNode* curB = headB;
			while (curA) { lenA++; curA = curA->next; }
			while (curB) { lenB++; curB = curB->next; }

			bool curALonger = lenA > lenB;
			ListNode* longer = curALonger ? headA : headB;
			ListNode* shorter = curALonger ? headB : headA;
			int diff = curALonger ? (lenA - lenB) : (lenB - lenA);
			while (diff > 0) {
				longer = longer->next;
				diff--;
			}
			while (longer != shorter) { ///--------> note that when both of them are null this also breaks, and returns null
				longer = longer->next;
				shorter = shorter->next;
			}
			return shorter;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

