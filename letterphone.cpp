#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	// This style of initialization learn from "fish in water"
	string dict[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	void findLetters(string instr, string letters, vector<string> &vRet) {
		if (instr.length() == 0)
			vRet.push_back(letters);
		int num, i;
		num = instr[0] - '0';
		if (num < 0 || num > 9)	
			return;
		for (i = 0; i < dict[num].size(); i++) {
			findLetters(instr.substr(1, instr.length()-1), letters + dict[num][i], vRet);
		}
	}
	vector<string> letterCombinations(string digits) {
		// Use recursive method to do it
		vector<string> vRet;
		string letters = "";
		findLetters(digits, letters, vRet);
		return vRet;
	}
};

class Solution2 {
public:
	string dict[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	vector<string> letterCombinations(string digits) {
		// Use a queue to store all the result, and add element to queue for every digit
		int i, j, k, num, retLen;
		string str;
		vector<string> vRet;
		vRet.push_back("");
		for (i = 0; i < digits.length(); i++) {
			num = digits[i] - '0';
			if (num < 0 || num > 9)	;
				// Error
			retLen = vRet.size();
			for (j = 0; j < retLen; j++) {
				str = vRet.front();
				vRet.erase(vRet.begin());
				for (k = 0; k < dict[num].length(); k++) {
					vRet.push_back(str + dict[num][k]);				
				}
			}
		}
		return vRet;
	}
};

int main() {
	return 0;
}
