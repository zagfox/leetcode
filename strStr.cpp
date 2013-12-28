#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
	char *strStr(char *haystack, char *needle) {
		// Note: The Solution object is instantiated only once and is reused by each test case.
		if (haystack == NULL || needle == NULL)
			return NULL;
		int l1, l2;
		int i,j;
		l1 = strlen(haystack);
		l2 = strlen(needle);
		for (i = 0; i < l1-l2+1; i++) {
			for (j = 0; j < l2; j++) {
				if (haystack[i+j] == needle[j]) ;
				else break;
			}
			if (j == l2)
				return &haystack[i];
		}
		return NULL;
	}
};
/**********************************
 * Version by Fish in Water 
 * There is also KMP algorithm for it, not recorded yet
 *****************************************8*/

class Solution2 {
public:
	char *strStr(char *haystack, char *needle) {  
		// Start typing your C/C++ solution below  
		// DO NOT write int main() function  
		if(haystack == NULL || needle == NULL)  
			return NULL;        
		int hLen = strlen(haystack);  
		int nLen = strlen(needle);  
		if(hLen<nLen)  
			return NULL;  
		for(int i=0; i<hLen - nLen+1; i++)  
		{  
			int j=0;  
			char* p = &haystack[i];  
			for(; j< nLen; j++)  
			{  
				if(*p != needle[j])  
					break;  
				p++;  
			}  
			if(j == nLen)  
				return &haystack[i];  
		}  
		return NULL;  
	}
};
int main() {
	Solution sn;
	return 0;
}
