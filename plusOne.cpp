#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int len = digits.size();
		// inspired by fish in water, set c = 1 at first
		int c = 1;		
		for (int i = len - 1; i >= 0; i--) {
			digits[i] += c;
			c = digits[i] / 10;
			digits[i] = digits[i] % 10;
			if (c == 0)
				break;

			if (i != 0)
				digits[i-1]++;
			else
				digits.insert(digits.begin(), c);
		}
		return digits;
	}
};

int main() {
	Solution sln;
	vector<int> vec;
	vec.push_back(9);
	sln.plusOne(vec);
}
