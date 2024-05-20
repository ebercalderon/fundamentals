#include <iostream>
using namespace std;
#define INF 99999
 

int floyd_warshall(int* graph, int V)
{
    int dist[V][V], i, j, k;
 
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = *((graph + i * V) + j);
        }
    }
 
    for (k = 0; k < V; k++) {
 
        for (i = 0; i < V; i++) {
 
            for (j = 0; j < V; j++) {
 
                if (dist[i][k]
                        + dist[k][j]
                    < dist[i][j]) {
                    dist[i][j]
                        = dist[i][k]
                          + dist[k][j];
                }
            }
        }
    }
 
    int sum = 0;
 
    for (i = 0; i < V; i++) {
        for (j = i + 1; j < V; j++) {
            sum += dist[i][j];
        }
    }
    return sum;
}
 
int sumOfshortestPath(int N, int E,
                      int edges[][3])
{
    int g[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            g[i][j] = INF;
        }
    }
 
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
 
        g[u][v] = w;
        g[v][u] = w;
    }
    return floyd_warshall((int*)g, N);
}
 
int main()
{
    int N = 4;
    int E = 3;
    int Edges[][3]
        = { { 0, 1, 1 }, { 1, 2, 2 },
            { 2, 3, 3 } };
    cout << sumOfshortestPath(N, E, Edges);
    return 0;
}
