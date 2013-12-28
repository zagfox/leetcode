/***************************************
 * Name: subset
 * Function: subset and subset2 in leetcode
 * Author: zhufeng
 * Date: 11-11-2013
 ***************************************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*******************
 * SubSet
 *******************/
class Solution {
public:
	void findSubsets(vector<int> &S, int pos, vector<int> tmpSet, vector<vector<int> > &vRet) {
		if (pos >= S.size()) {
			vRet.push_back(tmpSet);
			return;
		}
		tmpSet.push_back(S[pos]);
		findSubsets(S, pos+1, tmpSet, vRet);
		tmpSet.pop_back();
		findSubsets(S, pos+1, tmpSet, vRet);
	}
	vector<vector<int> > subsets(vector<int> &S) {
		// Classic recursion problem
		vector<int> vSet;
		vector<vector<int> > vRet;
		std::sort(S.begin(), S.end());
		findSubsets(S, 0, vSet, vRet);
		return vRet;
	}
};

/*******************
 * SubSet2
 *******************/
class Solution2 {
public:
	void findSubsets(vector<int> &S, int pos, vector<int> tmpSet, vector<vector<int> > &vRet) {
		if (pos >= S.size()) {
			vRet.push_back(tmpSet);
			return;
		}
		// If decide to use it, just use it
		tmpSet.push_back(S[pos]);
		findSubsets(S, pos+1, tmpSet, vRet);
		tmpSet.pop_back();
		// If do not use it, skip all same value
		while (pos < S.size()-1 && S[pos] == S[pos+1])
			pos++;
		findSubsets(S, pos+1, tmpSet, vRet);
	}
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		// Classic recursion problem
		vector<int> vSet;
		vector<vector<int> > vRet;
		std::sort(S.begin(), S.end());
		findSubsets(S, 0, vSet, vRet);
		return vRet;
	}
};

int main() {
	return 0;
}
