#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void generate(vector<string> &vRet, string str, int leftNum, int lcount, int rcount) {
		// Learn from "crack it interview"
		// cout << "lcount = " << lcount << ", rcount = " << rcount << endl;
		// cout << "str = " << str << endl;
		if (lcount == 0 && rcount == 0) {
			vRet.push_back(str);
			return;
		}
		if (lcount > 0)
			generate(vRet, str+"(", leftNum+1, lcount-1, rcount);
		if (rcount > 0 && leftNum > 0)
			generate(vRet, str+")", leftNum-1, lcount, rcount-1);
	}
	vector<string> generateParenthesis(int n) {
		vector<string> vRet;	
		generate(vRet, "", 0, n, n);
		return vRet;
	}
};

int main() {
	Solution sln;
	sln.generateParenthesis(1);
	return 0;
}
