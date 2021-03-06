#include "stdafx.h"
// 

namespace Solution2019
{
	namespace DesignLinkedList
	{
		class MyLinkedList {
			public:
				struct ListNode {
					int val;
					ListNode* next;
					ListNode(int x) { val = x; next = nullptr; }
				};

				ListNode* head;
				ListNode* tail;
				int len;
				/** Initialize your data structure here. */
				MyLinkedList() {
					head = nullptr;
					tail = nullptr;
					len = 0;
				}

				/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
				int get(int index) {
					if (index < 0 || index > len-1) { return -1; }
					ListNode* cur = head;
					int i = 0;
					while (cur) {
						if (i == index) { return cur->val; }
						cur = cur->next;
						i++;
					}
					return -1;
				}

				/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
				void addAtHead(int val) {
					ListNode* newNode = new ListNode(val);
					if (!tail) { tail = newNode; }
					else { newNode->next = head; }
					head = newNode;
					len++;
				}

				/** Append a node of value val to the last element of the linked list. */
				void addAtTail(int val) {
					ListNode* newNode = new ListNode(val);
					if (!head) { head = newNode; }
					else { tail->next = newNode; }
					tail = newNode;
					len++;
				}

				/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
				void addAtIndex(int index, int val) {
					if (index < 0 || index > len) { return; }
					if (index == 0) { addAtHead(val); }
					else if (index == len) { addAtTail(val); }
					else {
						ListNode* cur = head;
						int i = 0;
						while (cur) {
							if (i == index - 1) { break; }
							cur = cur->next;
							i++;
						}
						ListNode* newNode = new ListNode(val);
						newNode->next = cur->next;
						cur->next = newNode;
						len++;
					}
				}

				/** Delete the index-th node in the linked list, if the index is valid. */
				void deleteAtIndex(int index) {
					if (index < 0 || index > len - 1) { return; }
					if (index == 0) {
						ListNode* tmp = head;
						head = head->next;
						delete tmp;
						if (!head) { tail = nullptr; }
					}
					else {
						ListNode* cur = head;
						int i = 0;
						while (cur) {
							if (i == index - 1) { break; }
							cur = cur->next;
							i++;
						}						
						ListNode* tmp = cur->next;
						cur->next = cur->next->next;
						delete tmp;
						if (cur->next == nullptr) { tail = cur; }
					}
					len--;
					
				}
			}; 
		void Main() {
			MyLinkedList test;
			test.addAtHead(56);
			test.get(1);
			test.addAtHead(41);
			test.addAtTail(98);
			test.get(3);
			test.addAtIndex(1, 33);
			test.addAtHead(72);
			test.addAtHead(52);
			test.addAtHead(89);
			test.addAtHead(0);
			test.addAtHead(98);
			test.addAtIndex(7, 97);
			test.addAtIndex(2, 51);
			test.get(1);
			test.get(6);
			test.addAtIndex(6, 49);
			test.get(8);
			test.addAtHead(72);
			test.addAtIndex(7, 8);
			test.addAtIndex(8, 58);
			test.addAtHead(10);
			test.addAtIndex(3, 6);
			test.addAtIndex(9, 61);
			test.addAtHead(63);
			test.get(16);
			test.deleteAtIndex(7);
			test.addAtIndex(16, 55);
			test.get(4);
			test.get(10);
			test.deleteAtIndex(6);
			test.addAtTail(96);
			test.addAtHead(69);
			test.addAtTail(20);
			test.addAtHead(3);
			test.addAtTail(44);
			test.addAtTail(4);
			test.addAtIndex(8, 16);
			test.get(15);
			test.get(21);
			test.addAtHead(41);
			test.deleteAtIndex(1);
			test.deleteAtIndex(11);
			test.get(21);
			test.deleteAtIndex(22);
			test.get(2);
			test.addAtIndex(5, 7);
			test.addAtTail(62);
			test.addAtHead(95);
			test.addAtTail(91);
			test.addAtHead(69);
			test.get(24);
			test.addAtTail(51);
			test.addAtTail(94);
			test.addAtHead(93);
			test.get(29);
			test.get(10);
			test.addAtHead(68);
			test.addAtHead(13);
			test.addAtIndex(32, 42);
			test.addAtHead(48);
			test.addAtHead(55);
			test.addAtHead(79);
			test.addAtHead(5);
			test.addAtHead(36);
			test.addAtTail(32);
			test.addAtIndex(25, 40);
			test.addAtHead(8);
			test.addAtTail(68);
			test.deleteAtIndex(30);
			test.addAtHead(66);
			test.addAtHead(92);
			test.addAtIndex(27, 26);
			test.addAtTail(90);
			test.addAtIndex(11, 19);
			test.addAtTail(68);
			test.addAtIndex(17, 62);
			test.get(15);
			test.addAtIndex(17, 97);
			test.addAtIndex(35, 89);
			test.get(44);
			test.addAtTail(90);
			test.addAtTail(67);
			test.addAtHead(2);
			test.addAtHead(51);
			test.addAtHead(30);
			test.deleteAtIndex(38);
			test.addAtHead(30);
			test.addAtTail(43);
			test.addAtTail(76);
			test.addAtTail(16);
			test.addAtTail(38);
			test.addAtHead(82);
			test.addAtHead(81);
			test.addAtTail(67);
			test.addAtTail(67);
			test.addAtIndex(3, 16);
			test.get(57);
			test.addAtTail(94);
			test.addAtHead(11);
			test.addAtTail(31);
			test.addAtHead(50);
		}
	}
}

