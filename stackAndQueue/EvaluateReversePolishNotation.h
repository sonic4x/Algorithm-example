#pragma once

/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation:
((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/
#include <stack>
#include <vector>
#include <iostream>
#include <string>  //for stoi

#include <unordered_map>
#include <functional>
using namespace std;



class Sln_EvaluateReversePolishNotation {

	inline bool op(const string& s) {
		return s == "+" || s == "-" || s == "/" || s == "*";
	}
	inline int doOp(const int a, const int b, const string op) {
		if (op == "+") return a + b;
		if (op == "-") return a - b;
		if (op == "*") return a * b;
		if (op == "/") return a / b;
		cout << "Error" << endl;
		exit(1);
	}
public:
	int evalRPN(vector<string>& tokens) {
		int num1, num2;
		stack<int> nums;
		for (auto &n : tokens) {
			if (op(n)) {
				num1 = nums.top(); nums.pop(); num2 = nums.top(); nums.pop();
				nums.push(doOp(num2, num1, n));
			}
			else nums.push(stoi(n));
		}
		return nums.top();
	}

};

//use unordered_map and function<>, lambda
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		unordered_map<string, function<int(int, int) > > map = {
			{ "+" , [](int a, int b) { return a + b; } },
			{ "-" , [](int a, int b) { return a - b; } },
			{ "*" , [](int a, int b) { return a * b; } },
			{ "/" , [](int a, int b) { return a / b; } }
		};
		std::stack<int> stack;
		//here use string& instead of string will save time.
		// You can also use auto& s:tokens
		for (string& s : tokens) {   
									
			if (map.end() == map.find(s)) {
				stack.push(stoi(s));
			}
			else {
				int op1 = stack.top();
				stack.pop();
				int op2 = stack.top();
				stack.pop();
				stack.push(map[s](op2, op1));
			}
		}
		return stack.top();
	}
};