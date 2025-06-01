#include <iostream>
using namespace std;

#define MAX 10

void dfs(int node, int adj[][MAX], bool visited[], int n) {
    visited[node] = true;
    cout << "Ziyaret edilen düğüm: " << node << endl;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, adj, visited, n);
        }
    }
}

int main() {
    int n; 
    int adj[MAX][MAX]; 
    bool visited[MAX] = {false};

    cout << "Düğüm sayısını giriniz (max " << MAX << "): ";
    cin >> n;

    cout << "Komşuluk matrisini giriniz:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    cout << "DFS ile dolaşma sonucu:\n";
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, n);
        }
    }

    return 0;
}
