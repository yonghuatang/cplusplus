// Depth-First Search (DFS) and Breadth-First Search (BFS)??? Implementation
// Compiled using C++20 (g++ -std=c++2a)
#include <iostream>
#include <vector>
#include <map>
using namespace std;


// make it class template??
class Graph {
    private:
        map<int, vector<int>> adj; // Adjacency list
        map<int, bool> visited;

    public:
        Graph() { cout << "A graph is created." << endl; }  // Constructor

        ~Graph() { cout << "A graph is destroyed." << endl; }  // Destructor

        // Adds an edge connecting two nodes (vertices)
        void addEdge(int node, int neighbour) {
            if (adjacent(node, neighbour)) {
                cout << "Invalid: Duplicate adjacent neighbour found./Edge already exists. Node: " << node << " Neighbour: " << neighbour << endl;
            } else {
                adj[node].push_back(neighbour);
            }
        }

        // Overloads addEdge by accepting vector as input parameter
        void addEdge(int node, vector<int> neighbours) {
            for (int i : neighbours) {
                if (adjacent(node, i)) {
                    cout << "Invalid: Duplicate adjacent neighbour found. Node: " << node << " Neighbour: " << i << endl;
                } else {
                    adj[node].push_back(i);
                }
            }
        }

        // Removes an edge
        void removeEdge() {}

        void addNode() {}

        void addNode(int node) {/* overload */}

        void removeNode() {}

        // Evaluates whether if a neighbour is adjacent to a node
        bool adjacent(int node, int neighbour) {
            auto temp_adj = adj[node];
            if (std::find(temp_adj.begin(), temp_adj.end(), neighbour) != temp_adj.end()) {
                return true;
            }
            return false;
        }

        // Returns all the neighbours of a particular node
        vector<int> neighbours(int node) {
            return adj[node];
        }

        // A function to print all elements in a vector
        void printVector(vector<int> v) const {
            for (int i : v) {
                cout << i << " ";
            }
        }

        // Prints all nodes and their neighbours in the graph
        void printAll() {
            for (auto it=adj.begin(); it!=adj.end(); it++) {
                cout << "Node: " << it->first << "     Neighbour(s): ";
                printVector(it->second);
                cout << "\n";
            }
        }

        // Depth-first search
        void dfs(int s) {
            if (visited[s]) {
                return;  // exits the function, return void
            }
            visited[s] = true;
            for (auto node : adj[s]) {
                if (!visited[node]) {
                    dfs(node);  // recursion
                }
            }
        }

        // 
        void bfs() {
            // ???
        }

        // Resets (clears) the adjacency list
        void resetAdj() {
            adj.clear();
            if (!adj.empty()) {
                cout << "Error resetting Graph::adj" << endl;
            }
        }

        // Resets (clears) the visited list
        void resetVisited() {
            visited.clear();
            if (!visited.empty()) {
                cout << "Error resetting Graph::visited" << endl;
            }
        }
};


/*
add_vertex(G, x): adds the vertex x, if it is not there;
remove_vertex(G, x): removes the vertex x, if it is there;
remove_edge(G, x, y): removes the edge from the vertex x to the vertex y, if it is there;
*/
int main() {
    Graph g;
    // Construct the graph by populating the adjacency list
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.printAll();

    return 0;
}