#include<iostream>
#include<string.h>
using namespace std;

class Solution {
public:
	// Wrong anwser, assign s3 prior to s1
	bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.length();
		int len2 = s2.length();
		int len3 = s3.length();
		if (len3 != len1 + len2)
			return false;

		int i = 0, j = 0, k = 0;
		while (k != len3) {
			if (s3[k] != s1[i] && s3[k] != s2[j])
				return false;
			if (s3[k] == s1[i]) {
				k++;
				i++;
			}
			else if (s3[k] == s2[j]) {
				k++;
				j++;
			}
			if (i == len1 || j == len2)
				break;
		}

		if (i < len1)
			return strncmp(&s1[i], &s3[k], len3 - k) == 0;
		if (j < len2)
			return strncmp(&s2[j], &s3[k], len3 - k) == 0;
		return true;
	}
};
class Solution2 {
public:
	// Use recursion, time out
	bool isInterleave(string s1, string s2, string s3) {
		if (s1 == "" && s2 == "" && s3 == "")
			return true;
		if (s1 != "" && s1[0] == s3[0])
			if (isInterleave(&s1[1], s2, &s3[1]) == true)
				return true;
		if (s2 != "" && s2[0] == s3[0])
			if (isInterleave(s1, &s2[1], &s3[1]) == true)
				return true;
		return false;
	}
};
class Solution3 {
public:
	// Use dp
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length())
			return false;
		int i, j;
		int opt[1000][1000];
		memset(opt, 0, sizeof(opt));
		opt[0][0] = 1;
		for (i = 1; i <= s1.length(); i++) {
			if (s1[i-1] == s3[i-1])
				opt[i][0] = 1;
			else
				break;
		}
		for (j = 1; j <= s2.length(); j++) {
			if (s2[j-1] == s3[j-1])
				opt[0][j] = 1;
			else
				break;
		}
		for (i = 1; i <= s1.length(); i++) {
			for (j = 1; j <= s2.length(); j++) {
				if (s1[i-1] == s3[i+j-1] && opt[i-1][j] == 1)
					opt[i][j] = 1;
				if (s2[j-1] == s3[i+j-1] && opt[i][j-1] == 1)
					opt[i][j] = 1;
			}
		}
		return opt[s1.length()][s2.length()];
	}
};
// Fish in water use linear space for dp, really efficient
class Solution4 {
public:
	// Use dp, and use O(n) space, inspired by fish in water
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length())
			return false;
		int i, j;
		int line_up[1000], line_down[1000];
		memset(line_up, 0, sizeof(line_up));
		memset(line_down, 0, sizeof(line_down));

		line_up[0] = 1;
		for (j = 1; j <= s2.length(); j++) {
			if (s2[j-1] == s3[j-1])
				line_up[j] = 1;
			else
				break;
		}
		for (i = 1; i <= s1.length(); i++) {
			memset(line_down, 0, sizeof(line_down));
			if (line_up[0] == 1 && s1[i-1] == s3[i-1])
				line_down[0] = 1;
			for (j = 1; j <= s2.length(); j++) {
				if (s1[i-1] == s3[i+j-1] && line_up[j] == 1)
					line_down[j] = 1;
				if (s2[j-1] == s3[i+j-1] && line_down[j-1] == 1)
					line_down[j] = 1;
			}
			memcpy(line_up, line_down, sizeof(line_down));
		}
		return line_up[s2.length()];
	}
};

int main() {
	Solution3 sln3;
	sln3.isInterleave("aabd","abdc","aabddbac");
	Solution4 sln;
	cout<<sln.isInterleave("aabd","abdc","aabddbac")<<endl;
	return 0;
}
