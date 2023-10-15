#include<bits/stdc++.h>
using namespace std;

/*
    here n is no. of nodes in graph starting from 0 to n-1
    adj is adjacency list of graph representation
*/
int n;
vector<vector<int>> adj;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for(int u: adj[v]) {
        if(color[u] == 0) {
            parent[u] = v;
            if(dfs(u)) {
                return true;
            }
        }
        else if(color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for(int i = 0; i < n; i++) {
        if(color[i] == 0 && dfs(i)) {
            break;
        }
    }

    if(cycle_start == -1) {
        cout << "Graph is Acyclic\n";
    }
    else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for(int v = cycle_end; v != cycle_start; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle Found in graph:\n";
        for(int v: cycle) {
            cout << v << " ";
        }
        cout << "\n";
    }
}