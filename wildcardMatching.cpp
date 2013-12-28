class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		const char *str, *ptr;
		bool star = false;
		for (str = s, ptr = p; *str != 0; str++, ptr++) {
			if (*ptr == '?');
			else if (*ptr == '*') {
				while(*ptr == '*')
					ptr++;
				star = true;
				s = str;
				p = ptr;
				str--;
				ptr--;
			}
			else {
				if (*str != *ptr) {
					if (star){
						s++;
						str = s - 1;
						ptr = p - 1;
					}
					else {
						return false;
					}
				}
			}
		}
		while (*ptr == '*')
			ptr++;
		if (*ptr == 0)
			return true;
		else
			return false;
	}
};
