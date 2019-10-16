#include "stdafx.h"
//Serialization is the process of converting a data structure or object into a 
//sequence of bits so that it can be stored in a file or memory buffer, or 
//transmitted across a network connection link to be reconstructed later in
//the same or another computer environment.
//
//Design an algorithm to serialize and deserialize a binary tree. There is no 
//restriction on how your serialization/deserialization algorithm should work. 
//You just need to ensure that a binary tree can be serialized to a string and 
//this string can be deserialized to the original tree structure.
//
//Example: 
//
//You may serialize the following tree:
//
//    1
//   / \
//  2   3
//     / \
//    4   5
//
//as "[1,2,3,null,null,4,5]"
//
//Clarification: 
//The above format is the same as how LeetCode serializes a binary tree. You do 
//not necessarily need to follow this format, so please be creative and come up 
//with different approaches yourself.
//
//Note: Do not use class member/global/static variables to store states.
//Your serialize and deserialize algorithms should be stateless.

namespace Solution2019
{
	namespace SerializeandDeserializeBinaryTree
	{

		class Codec {
		public:

			// Encodes a tree to a single string.
			string serialize(TreeNode* root) {
				ostringstream out;
				serialize(root, out);
				return out.str();
			}

			// Decodes your encoded data to tree.
			TreeNode* deserialize(string data) {
				istringstream in(data);
				return deserialize(in);
			}
		private:
			void serialize(TreeNode* root, ostringstream& out) {
				if (!root) { out << "# "; }
				else {
					out << root->val << " ";
					serialize(root->left, out);
					serialize(root->right, out);
				}
			}

			TreeNode* deserialize(istringstream& in) {
				string val;
				in >> val;
				if (val == "#") { return nullptr; }
				TreeNode* root = new TreeNode(stoi(val));
				root->left = deserialize(in);
				root->right = deserialize(in);
				return root;
			}
		};

		// Your Codec object will be instantiated and called as such:
		// Codec codec;
		// codec.deserialize(codec.serialize(root))

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

