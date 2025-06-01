#include <iostream>
#include <queue>
using namespace std;

#define MAX 10

void bfs(int start, int adj[][MAX], bool visited[], int n) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << "Ziyaret edilen düğüm: " << node << endl;

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int n; // düğüm sayısı
    int adj[MAX][MAX]; // komşuluk matrisi
    bool visited[MAX] = {false};

    cout << "Düğüm sayısını giriniz (max " << MAX << "): ";
    cin >> n;

    cout << "Komşuluk matrisini giriniz:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    cout << "BFS ile dolaşma sonucu:\n";
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i, adj, visited, n);
        }
    }

    return 0;
}
