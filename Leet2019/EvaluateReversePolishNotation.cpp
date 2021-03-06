#include "stdafx.h"

//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//Valid operators are +, -, *, /. Each operand may be an integer or another
//expression.
//
//Note:
//Division between two integers should truncate toward zero.
//The given RPN expression is always valid. That means the expression would
//always evaluate to a result and there won't be any divide by zero operation.
//
//Example 1:
//Input: ["2", "1", "+", "3", "*"]
//Output: 9
//Explanation: ((2 + 1) * 3) = 9
//
//Example 2:
//Input: ["4", "13", "5", "/", "+"]
//Output: 6
//Explanation: (4 + (13 / 5)) = 6
//
//Example 3:
//Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
//Output: 22
//Explanation: 
//  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//= ((10 * (6 / (12 * -11))) + 17) + 5
//= ((10 * (6 / -132)) + 17) + 5
//= ((10 * 0) + 17) + 5
//= (0 + 17) + 5
//= 17 + 5
//= 22

namespace Solution2019
{
	namespace EvaluateReversePolishNotation
	{
		namespace UseStack {
			int calc(int i1, int i2, char op) {
				switch (op) {
				case '+': return i1 + i2;
				case '-': return i1 - i2;
				case '*': return i1 * i2;
				case '/': return i1 / i2;
				}
				return -1;
			}

			int evalRPN(vector<string>& tokens) {
				int len = tokens.size();
				if (len == 0) { return 0; }

				stack<int> s;
				for (string t : tokens) {
					if (t == "+" || t == "-" || t == "*" || t == "/") {
						int i2 = s.top();
						s.pop();
						int i1 = s.top();
						s.pop();
						s.push(calc(i1, i2, t[0]));
					}
					else {
						s.push(stoi(t));
					}
				}
				return s.top();
			}
		}

		namespace UseRecursion {
			int evalRPN(vector<string>& tokens) {
				if (tokens.empty()) { return 0; }
				string t = tokens.back();
				tokens.pop_back();
				if (t == "+" || t == "-" || t == "*" || t == "/") {
					int r2 = evalRPN(tokens);
					int r1 = evalRPN(tokens);
					if (t == "+") { return r1 + r2; }
					else if (t == "-") { return r1 - r2; }
					else if (t == "*") { return r1 * r2; }
					else { return r1 / r2; }
				}
				else {
					return stoi(t);
				}
			}
		}

		void Main() {
			vector<string> test = { "2", "1", "+", "3", "*" };
			print(UseRecursion::evalRPN(test));
		}
	}
}

