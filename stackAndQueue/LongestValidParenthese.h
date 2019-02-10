#pragma once
/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"

Example 3:
Input: "(()(()()"
Output: 4
*/

#include <stack>
using namespace std;

//using stack
class LongestValidParentheseSolution {
public:
	int longestValidParentheses(string s) {
		int len = s.size();
		if (len == 0)
			return 0;

		int maxLength = 0;
		int curlength = 0;
		stack<int> st;   //put idx instead of char
		st.push(-1);
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '(') {
				st.push(i);
			}
			else {
				st.pop();
				if (!st.empty()) {
					curlength = i - st.top();
					if (maxLength < curlength)
						maxLength = curlength;
				}	
				else {
					st.push(i);
				}
			}
		}
		return maxLength;
	}
};

//using dynamic programing
#include <vector>
#include <ciso646>  //for not, and,...
#include <algorithm> // for max_element
class LongestValidParentheseSolution2 {
public:
	int longestValidParentheses(string s) {
		if (not s.size()) return 0;
		vector<int> dp(s.size(), 0);      // len(valid_substr) ending at i   

		for (int i = 1; i<s.size(); i++)
		{
			if (s[i - 1] == '(' and s[i] == ')')
				dp[i] = ((i>1) ? dp[i - 2] : 0) + 2;
			if (s[i - 1] == ')' and
				s[i] == ')' 
				) {

				if (i - dp[i - 1] - 1 >= 0 and s[i - dp[i - 1] - 1] == '(') {
					dp[i] = dp[i - 1] 
							+ ((i - dp[i - 1] - 2 < 0) ? 0 : dp[i - dp[i - 1] - 2]) 
							+ 2;
				}

					
			}
		}
		return *max_element(dp.begin(), dp.end());
	}
};