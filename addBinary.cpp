#include<iostream>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		// Bit compute, one by one
		int i, j, bit_a, bit_b, bit_c;
		char ch;
		string s = "";
		bit_c = 0;
		for (i = a.length()-1, j = b.length()-1; i >= 0 || j >=0; i--, j--) {
			bit_a = 0;
			bit_b = 0;
			if (i >= 0)
				bit_a = a[i] - '0';
			if (j >= 0)
				bit_b = b[j] - '0';
			s += ('0' + (bit_a^bit_b^bit_c));
			bit_c = (bit_a + bit_b + bit_c) >> 1;
		}
		if (bit_c > 0)
			s += ('0' + bit_c);
		for (i = 0; i < s.length()/2; i++) {
			ch = s[i];
			s[i] = s[s.length()-1-i];
			s[s.length()-1-i] = ch;
		}
		return s;
	}
};

class Solution2 {
public:
	string addBinary(string a, string b) {
		// Inspired by "fish in water", so some modify
		int i, j, bit_a, bit_b, bit_c;
		string s = "";
		bit_c = 0;
		for (i = a.length()-1, j = b.length()-1; i >= 0 || j >=0; i--, j--) {
			bit_a = (i>=0? a[i]-'0':0);
			bit_b = (j>=0? b[j]-'0':0);
			s += ('0' + (bit_a + bit_b + bit_c)%2);
			bit_c = (bit_a + bit_b + bit_c)/2;
		}
		if (bit_c > 0)
			s += ('0' + bit_c);
		std::reverse(s.begin(), s.end());
		return s;
	}
};

int main() {
	Solution sln;
	cout << sln.addBinary("11", "1") << endl;
	return 0;
}
