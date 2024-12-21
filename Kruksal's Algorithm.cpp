#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Edge {
    char from, to;
    int weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findSet(int node, vector<int>& members) {
    while (members[node] != node) {
        node = members[node];
    }
    return node;
}

void unionNodes(int u, int v, vector<int>& members) {
    int rootU = findSet(u, members);
    int rootV = findSet(v, members);
    if (rootU != rootV) {
        members[rootV] = rootU; // Merge the sets
    }
}

void kruskalMST(int n, vector<Edge>& edges, unordered_map<char, int>& charToIndex, unordered_map<int, char>& indexToChar) {
    // Step 1: Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    // Step 2: Initialize the members array (each node starts in its own set)
    vector<int> members(n);
    for (int i = 0; i < n; i++) {
        members[i] = i;
    }

    // Step 3: Process edges to construct the MST
    vector<Edge> mst;
    int mstWeight = 0;

    for (Edge& edge : edges) {
        int src = charToIndex[edge.from];
        int dest = charToIndex[edge.to];

        if (findSet(src, members) != findSet(dest, members)) {
            mst.push_back(edge);
            mstWeight += edge.weight;
            unionNodes(src, dest, members);
        }
    }

    // Output the MST
    cout << "\nEdges in the MST:\n";
    for (Edge& edge : mst) {
        cout << edge.from << " -- " << edge.to << " == " << edge.weight << endl;
    }
    cout << "Total weight of MST: " << mstWeight << endl;
}


int main() {
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> e;

    vector<Edge> edges(e);
    unordered_map<char, int> charToIndex;
    unordered_map<int, char> indexToChar;

    cout << "Enter the vertices (e.g., A, B, C, ...):\n";
    for (int i = 0; i < n; i++) {
        char vertex;
        cout << "Vertex " << i + 1 << ": ";
        cin >> vertex;
        charToIndex[vertex] = i;
        indexToChar[i] = vertex;
    }

    cout << "Enter the edges (source, destination, weight):\n";
    for (int i = 0; i < e; i++) {
        cout << "Edge " << i + 1 << ": ";
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    kruskalMST(n, edges, charToIndex, indexToChar);

    return 0;
}