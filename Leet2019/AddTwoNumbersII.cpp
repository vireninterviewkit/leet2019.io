#include "stdafx.h"

//You are given two non - empty linked lists representing two non - negative integers.
//The most significant digit comes first and each of their nodes contain a single digit.
//Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Follow up :
//What if you cannot modify the input lists ? In other words, reversing the lists is not allowed.
//
//Example :
//
//	Input : (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//		Output : 7 -> 8 -> 0 -> 7

namespace Solution2019
{
	namespace AddTwoNumbersII
	{
		ListNode* ReverseLinkedList(ListNode* l)
		{
			if (l == nullptr || l->next == nullptr) { return l; }
			ListNode* cur = l;
			ListNode* next = cur->next;
			ListNode* nN;
			cur->next = nullptr;

			while (next)
			{
				nN = next->next;
				next->next = cur;
				cur = next;
				next = nN;
			}
			return cur;
		}
		
		
		ListNode* AddTwoNumbersIIWithReverseLinkedList(ListNode* l1, ListNode* l2)
		{
			if (l1 == nullptr || l2 == nullptr) { return l1 ? l1 : l2; }

			ListNode* l3 = ReverseLinkedList(l1);
			ListNode* l4 = ReverseLinkedList(l2);

			ListNode* dummy = new ListNode(0);
			ListNode* cur = dummy;
			int carry = 0;
			while (l3 != nullptr || l4 != nullptr) {
				int sum = (l3 ? l3->val : 0) + (l4 ? l4->val : 0) + carry;
				carry = sum / 10;
				cur->next = new ListNode(sum % 10);
				cur = cur->next;

				if (l3 != nullptr) { l3 = l3->next; }
				if (l4 != nullptr) { l4 = l4->next; }
			}

			if (carry > 0) { cur->next = new ListNode(carry); }
			ListNode* result = dummy->next;
			delete dummy;

			return ReverseLinkedList(result);
		}

		int GetLinkedListDepth(ListNode* l) {
			int result = 0;
			if (l == nullptr) { return result; }
			
			while (l != nullptr) {
				result++;
				l = l->next;
			}
			return result;
		}


		int AddTwoNumbersIIInternal(ListNode* l1, ListNode* l2, ListNode** result, int d1, int d2) {
			if (l1 == nullptr || l2 == nullptr) { *result = l1 ? l1 : l2;  return 0; }
			
			ListNode* next = nullptr;
			int sum = 0;
			if (d1 == d2) 
			{				
				sum = l1->val + l2->val + AddTwoNumbersIIInternal(l1->next, l2->next, &next, d1 - 1, d2 - 1);
			} 
			else
			{
				sum = ((d1 > d2) ? l1->val : l2->val) + AddTwoNumbersIIInternal((d1 > d2) ? l1->next : l1, (d1 > d2) ? l2 : l2->next, &next, (d1 > d2) ? d1 - 1 : d1, (d1 > d2) ? d2 : d2-1);
			}
			*result = new ListNode(sum % 10);
			(*result)->next = next;
			return sum / 10;
		}

		ListNode* AddTwoNumbersIIRecursion(ListNode* l1, ListNode* l2) {
			int d1 = GetLinkedListDepth(l1) + 1;
			int d2 = GetLinkedListDepth(l2) + 1;
			ListNode* result;
			ListNode* dummy1 = new ListNode(0);
			dummy1->next = l1;
			ListNode* dummy2 = new ListNode(0);
			dummy2->next = l2;
			AddTwoNumbersIIInternal(dummy1, dummy2, &result, d1, d2);
			if (result->val == 0) { ListNode* prev = result; result = result->next; delete prev; }
			delete dummy1;
			delete dummy2;
			return result;
		}

		ListNode* AddTwoNumberIIStack(ListNode* l1, ListNode* l2) {
			if (l1 == nullptr || l2 == nullptr) { return l1 ? l1 : l2; }
			
			stack<int> s1;
			stack<int> s2;

			while (l1) { s1.push(l1->val); l1 = l1->next; }
			while (l2) { s2.push(l2->val); l2 = l2->next; }

			ListNode* head = nullptr;
			ListNode* prev = nullptr;
			int carry = 0;
			while (!s1.empty() || !s2.empty()) {
				int sum = (s1.empty() ? 0 : s1.top()) + (s2.empty() ? 0 : s2.top()) + carry;
				carry = sum / 10;
				prev = head;
				head = new ListNode(sum % 10);
				head->next = prev;
				if (!s1.empty()) { s1.pop(); }
				if (!s2.empty()) { s2.pop(); }
			}
			if (carry > 0) { prev = head; head = new ListNode(carry); head->next = prev; }
			return head;
		}


		void Main() {
			//ListNode* test = createList({1, 2, 3, 4});
			//test = createList({ 1, 2 });
			//print(ReverseLinkedList(test));
			print(AddTwoNumberIIStack(createList({ 5 }), createList({ 5 })));
			print(AddTwoNumberIIStack(createList({ 9, 9, 9 }), createList({ 1 })));
			print(AddTwoNumberIIStack(createList({ 1 }), createList({ 9, 9, 9, 9 })));
			print(AddTwoNumberIIStack(createList({ 7, 2, 4, 3 }), createList({ 5, 6, 4 })));
			print(AddTwoNumberIIStack(createList({ 7, 2, 4, 3 }), createList({ 0 })));
		}
	}
}

