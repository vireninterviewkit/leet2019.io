#include "stdafx.h"

//We are given a binary tree (with root node root), a target node, and an integer
//value K.
//Return a list of the values of all nodes that have a distance K from the target
//node.  The answer can be returned in any order.
// 
//
//Example 1:
//Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
//Output: [7,4,1]
//Explanation: 
//The nodes that are a distance 2 from the target node (with value 5)
//have values 7, 4, and 1.
//
/*
			 3
			/ \
		   5   1
		  / \ / \
		 6  2 0  8
		   / \
		  7   4
*/
//Note that the inputs "root" and "target" are actually TreeNodes.
//The descriptions of the inputs above are just serializations of these objects.
// 
//
//Note:
//The given tree is non-empty.
//Each node in the tree has unique values 0 <= node.val <= 500.
//The target node is a node in the tree.
//0 <= K <= 1000.

namespace Solution2019
{
	namespace AllNodesDistanceKinBinaryTree
	{
		namespace RememberParentPointerWithDFS {
			void findParent(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent) {
				if (node->left) {
					parent[node->left] = node;
					findParent(node->left, parent);
				}
				if (node->right) {
					parent[node->right] = node;
					findParent(node->right, parent);
				}
			}

			void dfs(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent, set<TreeNode*>& visited, int K, vector<int>& result) {
				if (!node || visited.count(node)) { return; }
				visited.insert(node);
				if (K == 0) {
					result.push_back(node->val);
					return;
				}
				dfs(node->left, parent, visited, K - 1, result);
				dfs(node->right, parent, visited, K - 1, result);
				dfs(parent[node], parent, visited, K - 1, result);
			}

			vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
				if (!root || !target) return {};
				if (K == 0) { return { target->val }; }

				unordered_map<TreeNode*, TreeNode*> parent;
				findParent(root, parent);

				vector<int> result;
				set<TreeNode*> visited;
				dfs(target, parent, visited, K, result);
				return result;
			}
		}


		namespace WithoutStoringParentPointers {
			void subtree_add(TreeNode* node, int K, int dist, vector<int>& result) {
				if (!node) { return; }
				if (dist == K) {
					result.push_back(node->val);
				}
				else {
					subtree_add(node->left, K, dist + 1, result);
					subtree_add(node->right, K, dist + 1, result);
				}
			}

			int dfs(TreeNode* node, TreeNode* target, int K, vector<int>& result) {
				if (!node) { return -1; }
				else if (node == target) {
					subtree_add(node, K, 0, result);
					return 1;
				}
				else {
					int L = dfs(node->left, target, K, result);
					int R = dfs(node->right, target, K, result);
					if (L != -1) {
						if (L == K) { result.push_back(node->val); }
						subtree_add(node->right, K, L + 1, result);
						return L + 1;
					}
					else if (R != -1) {
						if (R == K) { result.push_back(node->val); }
						subtree_add(node->left, K, R + 1, result);
						return R + 1;
					}
					else {
						return -1;
					}
				}
			}

			vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
				vector<int> result;
				dfs(root, target, K, result);
				return result;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

