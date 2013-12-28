class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		// n^2 method: time limit exceeded
		int N = gas.size(), totalLeft = 0;
		int i, j;
		vector<int> gasLeft;
		for (i = 0; i < N; i++) {
			gasLeft.push_back(gas[i] - cost[i]);
			totalLeft += gasLeft[i];
		}        
		if (totalLeft < 0)	return -1;

		for (i = 0; i < N; i++) {
			totalLeft = 0;	// Change meaning of total left here
			for (j = 0; j < N; j++) {
				totalLeft += gasLeft[(i + j) % N];
				if (totalLeft < 0)
					break;
			}
			if (j == N)
				return i;
		}
		return -1;
	}
};

class Solution2 {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		// Select biggest is not a right scheme
		int i, N = gas.size();
		int maxLeft = -9999, maxIdx, totalLeft = 0;
		for (i = 0; i < N; i++) {
			if (gas[i] - cost[i] > maxLeft) {
				maxLeft = gas[i] - cost[i];
				maxIdx = i;
			}
			totalLeft += gas[i] - cost[i];
		} 
		if (totalLeft < 0)	return -1;
		return maxIdx;

	}
};

class Solution3 {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		// Algorithm is find the only "positive region"
		int i, N = gas.size();
		int regionSum = 0, regionIdx = 0, total = 0;
		for (i = 0; i < N; i++) {
			regionSum += gas[i] - cost[i];
			if (regionSum < 0) {
				regionSum = 0;
				regionIdx = i+1;
			}
			total += gas[i] - cost[i];
		} 
		if (total < 0)	return -1;
		return regionIdx;
	}
};
