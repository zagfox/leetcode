/******************************************************************
 * Name: clone Graph
 * Author: Feng Zhu
 * Date: 10-25-2013
 * Refer: http://leetcode.com/2012/05/clone-graph-part-i.html
 *		  http://haixiaoyang.wordpress.com/2012/06/01/clone-graph/
 ***************************************************************/
#include<iostream>
#include<queue>
#include<map>
using namespace std;

 // Definition for undirected graph.
  struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		// Note: The Solution object is instantiated only once and is reused by each test case.
		if (node == NULL)
			return NULL;
		int i, len;
		queue<UndirectedGraphNode*> queA;
		UndirectedGraphNode *root, *curNode, *neiborNode;
		map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;

		root = new UndirectedGraphNode(node->label);
		nodeMap[node] = root;

		queA.push(node);
		while (!queA.empty()) {
			curNode = queA.front();
			queA.pop();
			len = curNode->neighbors.size();
			for (i = 0; i < len; i++) {
				neiborNode = curNode->neighbors[i];
				if (nodeMap.find(neiborNode) == nodeMap.end()) {
					UndirectedGraphNode *p = new UndirectedGraphNode(neiborNode->label);
					nodeMap[curNode]->neighbors.push_back(p);
					nodeMap[neiborNode] = p;
					queA.push(neiborNode);
				}
				else {
					nodeMap[curNode]->neighbors.push_back(nodeMap[neiborNode]);
				}
			}
		}
		return root;
	}
};
int main() {
	return 0;
}
