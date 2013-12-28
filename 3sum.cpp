/*
 * 3Sum: leetcode problem, along with 3 sum closest, 4sum
 * Author: zagfox
 * Time: 11/02/2013
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		//Main idea is to change this problem to 2sum problem
		//Time complexity is O(n^2)
		int i, l, r;
		vector<vector<int> > vRet;
		if (num.size() < 3)
			return vRet;
		std::sort(num.begin(), num.end());
		//Written this way to get rid of duplicate circumstance.
		for (i = num.size() - 1; i >= 2; i--) {
			l = 0;
			r = i-1;
			while (l < r) {
				if (num[l] + num[r] < -num[i]) {
					while (l < r && num[l] == num[l+1]) l++;
					l++;
				}
				else if (num[l] + num[r] > -num[i]) {
					while (l < r && num[r-1] == num[r]) r--;
					r--;
				}
				else {
					vector<int> vTmp;
					vTmp.push_back(num[l]);
					vTmp.push_back(num[r]);
					vTmp.push_back(num[i]);
					vRet.push_back(vTmp);
				
					// Can only add l or r.
					while (l < r && num[l] == num[l+1]) l++;
					l++;
					while (l < r && num[r-1] == num[r]) r--;
				}
			}
			while (i >=2 && num[i-1] == num[i]) i--;
		}
		return vRet;
	}
	int threeSumClosest(vector<int> &num, int target) {
		// Similar to 3Sum
		int i, l, r;
		int tmp, ret = 99999;
		if (num.size() < 3)
			return 0;
		std::sort(num.begin(), num.end());
		for (i = num.size() - 1; i >=2; i--) {
			l = 0;
			r = i - 1;
			while (l < r) {
				tmp = num[l] + num[r] + num[i];
				if (abs(tmp - target) < abs(ret - target)) {
					ret = tmp;
				}
				if (tmp == target)
					return ret;
				else if (tmp < target) {
					// Add this sentence for duplicate message takes 56ms, longer than not add this (42ms)
					// Maybe there is not many duplicate charactor, and logic compare takes time.
					while (l < r && num[l] == num[l+1]) l++;
					l++;
				}
				else {
					while (l < r && num[r-1] == num[r]) r--;
					r--;
				}
			}
			while (i >= 3 && num[i-1] == num[i]) i--;
		}
		return ret;
	}

	vector<vector<int> > fourSum(vector<int> &num, int target) {
		int i, j, l, r, tmp;
		vector<vector<int> > vRet;
		if (num.size() < 4)
			return vRet;
		std::sort(num.begin(), num.end());
		//Written this way to get rid of duplicate circumstance.
		for (i = num.size() - 1; i >= 3; i--) {
			for (j = i - 1; j >= 2; j--) {
				l = 0;
				r = j-1;
				while (l < r) {
					tmp = num[l] + num[r] + num[j] + num[i]; 
					if (tmp < target) {
						while (l < r && num[l] == num[l+1]) l++;
						l++;
					}
					else if (tmp > target) {
						while (l < r && num[r-1] == num[r]) r--;
						r--;
					}
					else {
						vector<int> vTmp;
						vTmp.push_back(num[l]);
						vTmp.push_back(num[r]);
						vTmp.push_back(num[j]);
						vTmp.push_back(num[i]);
						vRet.push_back(vTmp);

						while (l < r && num[l] == num[l+1]) l++;
						l++;
						while (l < r && num[r-1] == num[r]) r--;
					}
				}
				while (j >=2 && num[j-1] == num[j]) j--;
			}
			while (i >=3 && num[i-1] == num[i]) i--;
		}
		return vRet;

	}
};
int main()
{
	Solution sln;
	vector<int> vInt;
	vector<vector<int> > vRet;
	vInt.push_back(1);
	vInt.push_back(0);
	vInt.push_back(-1);
	vInt.push_back(0);
	vInt.push_back(-2);
	vInt.push_back(2);
	vRet = sln.fourSum(vInt, 0);

	return 0;
}
