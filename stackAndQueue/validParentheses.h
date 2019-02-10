#pragma once

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/
#include <stack>
using namespace std;

class ValidParenthesesSolution {
	enum ParentheseStatus {
		invalid = 0,
		sameTypeofParenthese = 1,
		differentTypeofParenthese = 2
	};
	char a[3] = {'(', '[', '{' };
	char b[3] = {')', ']', '}' };

	ParentheseStatus Checkparenthese(char strStartParenthese, char strEndParenthese) {
		int idx = 0;
		for (; idx < 3; idx++)
		{
			if (strStartParenthese == a[idx])
				break;
		}
		if (idx == 3)
			return invalid;
		return  (b[idx] == strEndParenthese)? sameTypeofParenthese: differentTypeofParenthese;
	}
public:
	bool isValid(string s) {

		stack<char> st;
		int len = s.length();
		for (int idx = 0; idx < len; idx++)
		{
			if (!st.empty()) {
				ParentheseStatus emRt = Checkparenthese(st.top(), s[idx]);
				if (invalid == emRt)
					return false;
				if (sameTypeofParenthese == emRt) {
					st.pop();
				}
				else
					st.push(s[idx]);
			}
			else
				st.push(s[idx]);
		}

		return (st.empty() ? true : false);

	}
};