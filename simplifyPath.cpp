/*********************************************
 * Name: Simplify Path
 * Author: Feng Zhu
 * Function: leetcode problem SImplify Path
 * Time: 10-24-2013
 ********************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class solution {
public:
	string simplifyPath(string path) {
		vector<string> vpath;
		int i = 0, j, len = path.size();
		string s, ret;
		while (i<len) {
			while (path[i] == '/' && i < len)
				i++;
			if (i == len)
				break;
			j = i;
			while (path[j] != '/' && j<len){
				j++;
			}
			s = path.substr(i, j-i);
			if (s.compare("..") == 0) {
				if (!vpath.empty())
					vpath.pop_back();
			}
			else if (s.compare(".") == 0);
			else {
				vpath.push_back(s);
			}
			i = j;
				
		}
		if (vpath.size() == 0)
			ret = "/";
		for (i = 0; i < vpath.size(); i++) {
			ret += "/" + vpath[i];
		}
		return ret;
	}
};

int main() {
	solution sn;
	cout << sn.simplifyPath("/abc/") << endl;
	return 0;
}
