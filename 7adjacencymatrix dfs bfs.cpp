
/*Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to
perform BFS. Use the map of the area around the college as the graph. Identify the prominent land
marks as nodes and perform DFS and BFS on that.*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;
// Function to perform DFS on the graph
void dfs(vector<vector<int>>& graph, int startNode) {
stack<int> s;
vector<bool> visited(graph.size(), false);
s.push(startNode);
visited[startNode] = true;
while (!s.empty()) {
int currNode = s.top();
s.pop();
cout << "Visited Node: " << currNode << endl;
for (int neighbor : graph[currNode]) {
if (!visited[neighbor]) {
s.push(neighbor);
visited[neighbor] = true;
}
}
}
}
// Function to perform BFS on the graph
void bfs(vector<vector<int>>& graph, int startNode) {
queue<int> q;
vector<bool> visited(graph.size(), false);
q.push(startNode);
visited[startNode] = true;
while (!q.empty()) {
int currNode = q.front();
q.pop();
cout << "Visited Node: " << currNode << endl;
for (int neighbor : graph[currNode]) {
if (!visited[neighbor]) {
q.push(neighbor);
visited[neighbor] = true;
}
}
}
}
int main() {
int numNodes;
cout << "Enter the number of nodes in the graph: ";
cin >> numNodes;
map<int, string> nodeNames;
cout << "Enter the name of each node, separated by spaces:\n";
for (int i = 1; i <= numNodes; i++) {
string nodeName;
cin >> nodeName;
nodeNames[i] = nodeName;
}
vector<vector<int>> graph(numNodes + 1); // Since we are using 1-indexed nodes
cout << "Enter the connections between the nodes (Enter 0 0 to stop):\n";
while (true) {
int node1, node2;
cin >> node1 >> node2;
if (node1 == 0 && node2 == 0) {
break;
}
graph[node1].push_back(node2);
graph[node2].push_back(node1);
}
int startNode;
cout << "Enter the starting node for DFS and BFS: ";
cin >> startNode;
cout << "DFS traversal starting from Node " << startNode << ":\n";
dfs(graph, startNode);
cout << "\nBFS traversal starting from Node " << startNode << ":\n";
bfs(graph, startNode);
return 0;
}
