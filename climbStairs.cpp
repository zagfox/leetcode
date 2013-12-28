class Solution {
public:
	// Use recursion, timeout
	int climbStairs(int n) {
		if (n < 0)
			return 0;
		else if (n == 0)
			return 1;
		else
			return climbStairs(n-2) + climbStairs(n-1);
	}
};
class Solution2 {
public:
	// Use dp
	int climbStairs(int n) {
		int dp[1000];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			dp[i] = dp[i-1] + dp[i-2];	
		}
		return dp[n];
	}
};
class Solution3 {
public:
	// It is fibonacci sequence
	int climbStairs(int n) {
		if (n == 0 || n == 1)
			return 1;
		int f, f1 = 1, f2 = 1;
		for (int i = 2; i <= n; i++) {
			f = f1 + f2;
			f1 = f2;
			f2 = f;
		}
		return f2;
	}
};
