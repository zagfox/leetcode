/*****************************************
 * Name: leetcode valid parentheses
 * Author: zhufeng
 * Date: 11-11-2013
 ******************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		// Classic stack matching problem
		// Code by "fish in water" is more concise
		vector<char> stack;
		int i;
		for (i = 0; i < s.length(); i++) {
			switch (s[i]) {
			case '(':
				stack.push_back('(');
				break;
			case ')':
				if (!stack.empty() && stack.back() == '(')
					stack.pop_back();
				else
					return false;
				break;
			case '[':
				stack.push_back('[');
				break;
			case ']':
				if (!stack.empty() && stack.back() == '[')
					stack.pop_back();
				else
					return false;
				break;
			case '{':
				stack.push_back('{');
				break;
			case '}':
				if (!stack.empty() && stack.back() == '{')
					stack.pop_back();
				else
					return false;
				break;
			default:
				break;
			}
		}
		if (stack.empty())
			return true;
		else
			return false;
	}
};

int main() {
	Solution sln;
	cout << sln.isValid("()") << endl;
	return 0;
}
