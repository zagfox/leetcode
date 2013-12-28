#include<iostream>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		// Different from the problem...
		int i, len = s.length();
		int leftNum = 0, pairNum = 0, maxNum = 0;
		for (i = 0; i < len; i++) {
			if (s[i] == '(') {
				leftNum++;	
			}
			else if (s[i] == ')') {
				leftNum--;
				if (leftNum < 0) {
					leftNum = 0;
					pairNum = 0;
				}
				else {
					pairNum += 2;
					if (pairNum > maxNum)
						maxNum = pairNum;
				}
			}
		}
		return maxNum;
	}
};

class Solution2 {
public:
	int longestValidParentheses(string s) {
		// This algorithm cost too much space
		// The platform restrict it
		int i, j, k, len = s.length();
		int opt[10000][10000], maxPair = 0;
		//memset(opt, 0, sizeof(opt));
		for (k = 2; k < len; k += 2) {
			for (i = 0; i + k < len; i++) {
				if (s[i] == '(' && s[i+1] == ')')
					opt[i][i+k] = max(opt[i][i+k], 2 + opt[i+2][i+k]);
				if (s[i] == '(' && s[i+k] == ')')
					opt[i][i+k] = max(opt[i][i+k], 2 + opt[i+1][i+k-1]);
				if (s[i+k-1] == '(' && s[i+k] == ')')
					opt[i][i+k] = max(opt[i][i+k], 2 + opt[i][i+k-2]);
				maxPair = max(maxPair, opt[i][i+k]);
			}
		}
		return maxPair;
	}
};

class Solution3 {
public:
	int findParenthes(string s, int leftNum) {
		// Recursive method, memory limit exceeded...
		if (s.length() == 0)	return 0;
		if (leftNum < 0) return 0;
		if (s[0] == '(')
			return findParenthes(s.substr(1, s.length()-1), leftNum+1);
		else if (s[0] == ')' && leftNum > 0)
			return 2 + findParenthes(s.substr(1, s.length()-1), leftNum-1);
		return 0;
	}
	int longestValidParentheses(string s) {
		findParenthes(s, 0);
	}
};

class Solution4 {
public:
	int longestValidParentheses(string s) {
		// Though use stack, still same algorithm with solution...
		int i, tmpNum = 0, matchNum = 0, maxNum = 0;
		vector<char> stack;
		for (i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				stack.push_back('(');
			}
			else if (s[i] == ')') {
				if (!stack.empty()) {
					stack.pop_back();
					matchNum++;
					if (stack.empty()) {
						tmpNum += 2*matchNum;
						maxNum = max(maxNum, tmpNum);
					}
				}
				else
					matchNum = 0;
					tmpNum = 0;
			}
		}
		return maxNum;
	}
};

class Solution5 {
public:
	int longestValidParentheses(string s) {
		// Learn totally from "fish in water", ac
		int maxNum = 0;
		const char *str = s.c_str(), *p;
		vector<const char *> stack;
		for (p = str; *p != 0; p++) {
			if (*p  == '(')
				stack.push_back(p);
			else {
				if (!stack.empty() && *stack.back() == '(') {
					stack.pop_back();
					if(stack.empty())
						maxNum = max(maxNum, p - str + 1);
					else
						maxNum = max(maxNum, p - stack.back());
				}
				else
					stack.push_back(p);
			}
		}
		return maxNum;
	}
};

int main() {
	Solution sln;
	cout << sln.longestValidParentheses("") << endl;
	return 0;
}
