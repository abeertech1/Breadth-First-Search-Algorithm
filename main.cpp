#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printQueue(queue<int> q, const vector<char>& name) {
    cout << "[";
    bool first = true;
    while (!q.empty()) {
        if (!first) cout << ", ";
        cout << name[q.front()];
        q.pop();
        first = false;
    }
    cout << "]";
}

void BFS_Sim(int start, const vector<vector<int>>& graph, const vector<char>& name) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Simulation (Start = " << name[start] << ")\n";

    int step = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // enqueue neighbors
        for (int nb : graph[node]) {
            if (!visited[nb]) {
                visited[nb] = true;
                q.push(nb);
            }
        }

        cout << "Step " << step++ << ": visit " << name[node] << " | queue = ";
        printQueue(q, name);
        cout << "\n";
    }
}

int main() {
    // 0=A, 1=B, 2=C, 3=D, 4=E
    vector<char> name = {'A', 'B', 'C', 'D', 'E'};

    // Roads: A-B, A-C, B-D, C-E (undirected)
    vector<vector<int>> g(5);
    g[0].push_back(1); g[1].push_back(0); // A-B
    g[0].push_back(2); g[2].push_back(0); // A-C
    g[1].push_back(3); g[3].push_back(1); // B-D
    g[2].push_back(4); g[4].push_back(2); // C-E

    BFS_Sim(0, g, name);
    return 0;
}