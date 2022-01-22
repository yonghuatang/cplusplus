/*
Undirected Graph Traversals:
1. Depth-First Search (DFS)
2. Breadth-First Search (BFS)
3. Dijkstra's Algorithm
Compiled using C++20 (g++ -std=c++2a)
James Tang - 16 January 2022
*/

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>

using namespace std;

#define VERBOSE_WARNING  // high verbosity


// For an undirected graph G(V,E), every pair of unordered nodes (or vertices) (vi,vj) forms an edge
class undirectedGraph {
    private:
        map<int, vector<int>> adj; // Adjacency list
        map<int, bool> visited;  // Visited list
        map<int, vector<std::pair<int, int>>> edgeWeight;  // Weight of each edge, default is zero. <node, <<neighbour, weight>, ...>>
        stack<int> cache;  // Stack implementation of DFS
        

    public:
        // Constructor
        undirectedGraph() {
            cout << "A graph is created." << endl;
        }

        // Destructor
        ~undirectedGraph() {
            cout << "A graph is destroyed." << endl;
        }

        // Adds an edge connecting two nodes
        void addEdge(int node, int neighbour, int weight=0) {
            if (adjacent(node, neighbour)) {
                #ifdef VERBOSE_WARNING
                cout << "=== Warning: Edge already exists. Node: " << node << " Neighbour: " << neighbour << " ===" << endl;
                #endif  // VERBOSE_WARNING
            } else if (node == neighbour) {
                #ifdef VERBOSE_WARNING
                cout << "=== Warning: Neighbour cannot be self (loop). Node: " << node << " Neighbour: " << neighbour << " ===" << endl;
                #endif  // VERBOSE_WARNING
            } else {
                adj[node].push_back(neighbour);
                visited[node] = false;
                edgeWeight[node].push_back(std::make_pair(neighbour, weight));
                // If a node shares an edge with its neighbour, then from the neighbour's perspective
                // it should also share the same edge, i.e., the adjacency list (matrix) is symmetric.
                if (!adjacent(neighbour, node)) {
                    adj[neighbour].push_back(node);
                    visited[neighbour] = false;
                    edgeWeight[neighbour].push_back(std::make_pair(node, weight));
                }
            }
        }

        // Overloads addEdge by accepting vector as input parameter
        void addEdge(int node, vector<int> neighbours, vector<int> weights = {}) {
            if ((weights.size() != 0) && (neighbours.size() != weights.size())) {
                cout << "Neighbours and weights not compatible in size." << endl;
                return;
            }
            int weightIndex = -1;
            for (int i : neighbours) {
                weightIndex++;
                int weight = (weights.size()==0 ? 0 : weights[weightIndex]);
                if (adjacent(node, i)) {
                    #ifdef VERBOSE_WARNING
                    cout << "=== Warning: Edge already exists. Node: " << node << " Neighbour: " << i << " ===" << endl;
                    #endif  // VERBOSE_WARNING
                } else if (node == i) {
                    #ifdef VERBOSE_WARNING
                    cout << "=== Warning: Neighbour cannot be self (loop). Node: " << node << " Neighbour: " << i << " ===" << endl;
                    #endif  // VERBOSE_WARNING
                } else {
                    adj[node].push_back(i);
                    visited[i] = false;
                    edgeWeight[node].push_back(std::make_pair(i, weight));
                    // If a node shares an edge with its neighbour, then from neighbour's perspective
                    // it should also share the same edge.
                    if (!adjacent(i, node)) {
                        adj[i].push_back(node);
                        visited[node] = false;
                        edgeWeight[i].push_back(std::make_pair(node, weight));
                    }
                }
            }
        }

        // Removes an edge
        void removeEdge(int node, int neighbour) {
            if (!nodeExists(node) || !nodeExists(neighbour)) {
                cout << "Edge does not exist to be removed." << endl;
                return;  // Exits the function at this point
            }
            // Erase-remove idiom
            adj[node].erase(std::remove(adj[node].begin(), adj[node].end(), neighbour), adj[node].end());
            adj[neighbour].erase(std::remove(adj[neighbour].begin(), adj[neighbour].end(), node), adj[neighbour].end());
            // remove edge weight also!!
        }

        // Adds a new (isolated) node 
        void addNode(int node) {
            if (!nodeExists(node)) {
                adj[node];
                visited[node] = false;
            } else {
                #ifdef VERBOSE_WARNING
                cout << "Warning: Node: " << node << " already exists." << endl;
                #endif  // VERBOSE_WARNING
            }
        }

        // Overloads addNode by accepting vector as input parameter
        void addNode(vector<int> nodes) {
            for (int i : nodes) {
                if (!nodeExists(i)) {
                    adj[i];  // adds key to map without corresponding value
                    visited[i] = false;
                } else {
                    #ifdef VERBOSE_WARNING
                    cout << "Warning: Node: " << i << " already exists." << endl;
                    #endif  // VERBOSE_WARNING
                }
            }
        }

        // Removes a node
        void removeNode(int node) {
            if (!nodeExists(node)) {
                cout << "Node: " << node << " does not exist to be removed." << endl;
                return;
            }
            auto wasNeighbours = neighbours(node);
            adj.erase(node);
            for (auto neighbour : wasNeighbours) {
                adj[neighbour].erase(std::remove(adj[neighbour].begin(), adj[neighbour].end(), node), adj[neighbour].end());
            }
            cout << "Node: " << node << " and its neighbours' reference to it has been removed" << endl;
            // remove edge weight also!!
        }

        // Checks whether a node exists
        bool nodeExists(int node) {
            for (auto it=adj.begin(); it!=adj.end(); it++) {
                if (it->first == node) {
                    return true;
                }
            }
            return false;
        }

        // Evaluates whether if a neighbour is adjacent to a node
        bool adjacent(int node, int neighbour) {
            if (!nodeExists(node)) {  // Prevents std::map from creating new key (node) if not exists
                return false;
            }
            if (std::find(adj[node].begin(), adj[node].end(), neighbour) != adj[node].end()) {
                return true;
            }
            return false;
        }

        // Returns the degree (number of neighbours) of a particular node
        // To find number of neighbours call neighbours().size()
        vector<int> neighbours(int node) {
            return adj[node];
        }

        // Checks whether that all the nodes are visited
        bool allVisited() const {
            for (auto it=visited.begin(); it!=visited.end(); it++) {
                if (!it->second) {
                    return false;
                }
            }
            return true;
        }

        // A function to print all elements in a vector
        void printVector(vector<int> v) const {
            for (int i : v) {
                cout << i << " ";
            }
        }

        // A function to print all elements in a stack
        void printStack() const {
            auto cacheTemp = cache;  // Create a copy of cache
            string output = "";
            while (!cacheTemp.empty()) {
                output = to_string(cacheTemp.top()) + " => " + output;
                cacheTemp.pop();
            }
            cout << "| " << output << endl;
        }

        // Checks whether a node is isolated (i.e. not connected to any other nodes)
        void printIsolated() const {
            vector<int> isolated;
            if (adj.empty()) {
                cout << "Adjacency list is empty." << endl;
                return;
            }
            for (auto it=adj.begin(); it!=adj.end(); it++) {
                if (it->second.size() == 0) {
                    isolated.push_back(it->first);
                }
                cout << "\n";
            }
            cout << "Isolated vertices: " ;
            printVector(isolated);
            cout << "\n";
        }

        // Prints all nodes and their neighbours in the graph
        void printGraph() const {
            if (adj.empty()) {
                cout << "Adjacency list is empty." << endl;
                return;
            }
            cout << "=== Adjacency list ===" << endl;
            for (auto it=adj.begin(); it!=adj.end(); it++) {
                cout << "Node: " << it->first << "     Neighbour(s): ";
                printVector(it->second);
                cout << "\n";
            }
        }

        // Prints visited status of all nodes
        void printVisited() const {
            if (visited.empty()) {
                cout << "Visited list is empty." << endl;
                return;
            }
            cout << "=== Visited list ===" << endl;
            for (auto it=visited.begin(); it!=visited.end(); it++) {
                cout << "Node: " << it->first << "     Visited: " << (it->second ? "YES" : "NO") << endl;
            }
        }

        // Prints weight of all edges
        void printWeight() {
            if (edgeWeight.empty()) {
                cout << "Edge-weight list is empty." << endl;
                return;
            }
            cout << "=== Edge-weight list===" << endl;
            for (auto it=edgeWeight.begin(); it!=edgeWeight.end(); it++) {
                cout << "Node: " << it->first << "     Neighbours: ";
                for (auto i : it->second) {
                    cout << i.first << "=" << i.second << " ";
                }
                cout << "\n";
            }
        }

        // Depth-first search (DFS)
        void dfs(int s/*, int startNode ??*/) {
            static bool checked{false}; // ??
            if (!checked) {
                cout << "RUNNING CHECKED" << endl;  // FOR DEBUG
                checked = true;
                if (adj.empty() || visited.empty()) {
                    cout << "Adjacency list or visited list is empty." << endl;
                }
            } else if (visited[s]) {
                return;  // exits the function, return void
            } else {
                visited[s] = true;
                cache.push(s);  // ??
                printStack();
                for (auto node : adj[s]) {
                    if (!visited[node]) {
                        dfs(node);  // recursion??
                    }
                }
            }
        }

        // Breadth-first search (BFS)
        void bfs(int startNode) {
            cout << "=== Breadth-first search (BFS) ===" << endl;
            int depth = 0;
            map<int, int> label;
            visited[startNode] = true;
            label[startNode] = depth;
            cout << "Depth: 0     Node: " << startNode << endl;
            while (!allVisited()) {
                for (auto it=label.begin(); it!=label.end(); it++) {
                    if (it->second == depth) {
                        cout << "Depth: " << depth + 1 << "     Node(s): ";
                        for (auto i : neighbours(it->first)) {
                            if (!visited[i]) {
                                visited[i] = true;
                                label[i] = depth + 1;
                                cout << i << " ";
                            }
                        }
                        cout << "\n";
                    }
                }
                depth++;
            }
        } // BUG!!

        // <thisNode, <previousNode, distance>>
        typedef std::pair<int, std::pair<int, int>> PAIR;

        // Comparator structure for priority queue in void dijkstra()
        struct compDijkstra {
            bool operator()(const PAIR& p1, const PAIR& p2) {
                return p1.second.second > p2.second.second;  // min heap
            }
        };

        // <TYPE, CONTAINER, COMPARATOR>
        typedef std::priority_queue<PAIR, vector<PAIR>, compDijkstra> PQ;

        // Pops a particular element in a priority queue, because std::priority_queue has no member function to do so
        PQ popOutdated(PQ pq, int popNode) {
            PQ pq_new;
            while (!pq.empty()) {
                if (pq.top().first != popNode) {
                    pq_new.push(pq.top());
                }
                pq.pop();
            }
            return pq_new;
        }

        //
        int findDistanceInPQ(PQ pq, int thisNode) {
            PQ pq_temp = pq;
            int distance = -1;
            while (!pq_temp.empty()) {
                if (pq_temp.top().first == thisNode) {
                    distance = pq_temp.top().second.second;
                    break;
                }
                pq_temp.pop();
            }
            return distance;
        }

        // Dijkstra's algorithm
        void dijkstra(int startNode, int targetNode) {
            cout << "=== Dijkstra's algorithm ===" << endl;
            if (startNode == targetNode) {
                cout << "Trivial: startNode and targetNode are the same." << endl;
                cout << "Distance/cost to target node: 0" << endl;
                return;  // exits the function at this point
            }

            PQ pq;
            stack<PAIR> visitedStack;
            const int INF = 1000000007;

            // Pushes every node in the graph into the priority queue with previousNode = INF and distance = INF
            for (auto it=adj.begin(); it!=adj.end(); it++) {
                pq.push(std::make_pair(it->first, std::make_pair(INF, INF)));
            }

            // Makes the startNode to have previousNode = -1 and distance = 0
            pq = popOutdated(pq, startNode);
            pq.push(std::make_pair(startNode, std::make_pair(-1, 0)));
            visited[startNode] = true;

            // While the targetNode is not ordered on top of the priority queue
            while (pq.top().first != targetNode) {
                const auto currentNode = pq.top().first;
                const auto currentDistance = pq.top().second.second;
                visited[currentNode] = true;
                for (auto adjNode : neighbours(currentNode)) {
                    if (!visited[adjNode]) {
                        for (auto it=edgeWeight[currentNode].begin(); it!=edgeWeight[currentNode].end(); it++) {
                            if (it->first == adjNode) {
                                if (currentDistance + it->second < findDistanceInPQ(pq, adjNode)) {
                                    pq = popOutdated(pq, adjNode);
                                    pq.push(std::make_pair(adjNode, std::make_pair(currentNode, currentDistance + it->second)));
                                }
                            }
                        }
                    }
                }
                visitedStack.push(pq.top());
                pq.pop();
                cerr << currentNode << endl; // for debug
            }
            visited[targetNode] = true;
            cout << "Distance/cost to target node: " << pq.top().second.second << endl;

            // Backtrack path from target node to starting node
            // for () {

            // }
            // cout << "Path: ";
            // for () {
            //     cout <<  << " => ";
            // }
            // cout << "\n";
        }
};

/* ----------------- Example -----------------

    0                       6
      \                     |
        \                   |
          1 - - 2 - - 4 - - 5 - - 7 - - 8
          |     |           |
          \     /           |
             3              9 - - 10


--------------------------------------------*/

int main() {
    // Create a Graph object
    undirectedGraph g;

    // Construct the graph by populating the adjacency list
    g.addEdge(0, 1, 1);
    g.addEdge(1, {0, 2, 3}, {1, 1, 1});
    g.addEdge(2, {1, 3, 4}, {1, 1, 1});
    g.addEdge(3, {1, 2}, {1, 1});
    g.addEdge(4, {2, 5}, {1, 1});
    g.addEdge(5, {4, 6, 7, 9}, {1, 1, 1, 1});
    g.addEdge(6, 5, 1);
    g.addEdge(7, {5, 8}, {1, 1});
    g.addEdge(8, 7, 1);
    g.addEdge(9, {5, 10}, {1, 1});
    g.addEdge(10, 9, 1);

    // After constructing the graph we can manipulate it
    g.printGraph();
    // g.bfs(0);
    g.dijkstra(0, 10);
    g.printVisited();
    g.printWeight();
    // g.dfs();
    // g.printGraph();  // should be the same graph
    // g.printVisited();  // should be all true

    return 0;
}

/* OUTPUT (with VERBOSE_WARNING)
A graph is created.
=== Warning: Edge already exists. Node: 1 Neighbour: 0 ===
=== Warning: Edge already exists. Node: 2 Neighbour: 1 ===
=== Warning: Edge already exists. Node: 3 Neighbour: 1 ===
=== Warning: Edge already exists. Node: 3 Neighbour: 2 ===
=== Warning: Edge already exists. Node: 4 Neighbour: 2 ===
=== Warning: Edge already exists. Node: 5 Neighbour: 4 ===
=== Warning: Edge already exists. Node: 6 Neighbour: 5 ===
=== Warning: Edge already exists. Node: 7 Neighbour: 5 ===
=== Warning: Edge already exists. Node: 8 Neighbour: 7 ===
=== Warning: Edge already exists. Node: 9 Neighbour: 5 ===
=== Warning: Edge already exists. Node: 10 Neighbour: 9 ===
=== Adjacency list ===
Node: 0     Neighbour(s): 1
Node: 1     Neighbour(s): 0 2 3
Node: 2     Neighbour(s): 1 3 4
Node: 3     Neighbour(s): 1 2
Node: 4     Neighbour(s): 2 5
Node: 5     Neighbour(s): 4 6 7 9
Node: 6     Neighbour(s): 5
Node: 7     Neighbour(s): 5 8
Node: 8     Neighbour(s): 7
Node: 9     Neighbour(s): 5 10
Node: 10     Neighbour(s): 9
=== Visited ===
Node: 0     Visited: NO
Node: 1     Visited: NO
Node: 2     Visited: NO
Node: 3     Visited: NO
Node: 4     Visited: NO
Node: 5     Visited: NO
Node: 6     Visited: NO
Node: 7     Visited: NO
Node: 8     Visited: NO
Node: 9     Visited: NO
Node: 10     Visited: NO
=== Adjacency list ===
Node: 0     Neighbour(s): 1
Node: 1     Neighbour(s): 0 2 3
Node: 2     Neighbour(s): 1 3 4
Node: 3     Neighbour(s): 1 2
Node: 4     Neighbour(s): 2 5
Node: 5     Neighbour(s): 4 6 7 9
Node: 6     Neighbour(s): 5
Node: 7     Neighbour(s): 5 8
Node: 8     Neighbour(s): 7
Node: 9     Neighbour(s): 5 10
Node: 10     Neighbour(s): 9 
=== Visited ===
Node: 0     Visited: NO
Node: 1     Visited: NO
Node: 2     Visited: NO
Node: 3     Visited: NO
Node: 4     Visited: NO
Node: 5     Visited: NO
Node: 6     Visited: NO
Node: 7     Visited: NO
Node: 8     Visited: NO
Node: 9     Visited: NO
Node: 10     Visited: NO
A graph is destroyed.
*/
