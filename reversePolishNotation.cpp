#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
	// Use recursion
public:
	int evalRPN(vector<string> &tokens) {
		if (tokens.size() == 0)
			return 0;
		string s = tokens[tokens.size()-1];
		int a, b;
		tokens.pop_back();
		if (s.compare("+") == 0) {
			b = evalRPN(tokens);
			a = evalRPN(tokens);
			return a + b;
		}
		else if (s.compare("-") == 0) {
			b = evalRPN(tokens);
			a = evalRPN(tokens);
			return a - b;
		}
		else if (s.compare("*") == 0) {
			b = evalRPN(tokens);
			a = evalRPN(tokens);
			return a * b;
		}
		else if (s.compare("/") == 0) {
			b = evalRPN(tokens);
			a = evalRPN(tokens);
			return a / b;
		}
		else
			return stoi(s);
	}
};

class Solution2 {
	// Use stack, inspired by Magi Su
public:
	int evalRPN(vector<string> &tokens) {
		stack<int> tkStack;
		int b, a;
		for (int i = 0; i < tokens.size(); i++) {
			if (isdigit(tokens[i][0]) || tokens[i].size() > 1)
				tkStack.push(std::stoi(tokens[i]));
			else {
				b = tkStack.top();
				tkStack.pop();
				a = tkStack.top();
				tkStack.pop();

				switch(tokens[i][0]) {
					case '+':
						tkStack.push(a + b);
						break;
					case '-':
						tkStack.push(a - b);
						break;
					case '*':
						tkStack.push(a * b);
						break;
					case '/':
						tkStack.push(a / b);
						break;
				}
			}
		}
		return tkStack.top();
	}
};
class Solution3 {
	// Change a little on sln2
public:
	int evalRPN(vector<string> &tokens) {
		stack<int> tkStack;

		for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
			if (isdigit((*it)[0]) || (*it).size() > 1)
				tkStack.push(stoi(*it));
			else {
				int b, a;
				b = tkStack.top();
				tkStack.pop();
				a = tkStack.top();
				tkStack.pop();

				switch((*it)[0]) {
					case '+':
						tkStack.push(a + b);
						break;
					case '-':
						tkStack.push(a - b);
						break;
					case '*':
						tkStack.push(a * b);
						break;
					case '/':
						tkStack.push(a / b);
						break;
				}
			}
		}
		return tkStack.top();
	}
};

int main() {
	Solution sln;
	return 0;
}
