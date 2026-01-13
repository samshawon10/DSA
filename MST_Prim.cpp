#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    int n; // Number of vertices

    vector<vector<int>> adj; // To store the constructed MST
    bool directed;           // Graph is directed or not
    vector<int> q, key, p;   // To keep track of vertices included in MST
public:
    Graph(int n, bool dir) : n(n), directed(dir)
    {
        adj = vector<vector<int>>(n, vector<int>(n, 0));
        q = vector<int>(n);
        key = vector<int>(n);
        p = vector<int>(n);
    }

    void addEdge(int u, int v, int w)
    {
        adj[u][v] = w;
        if (!directed)
        {
            adj[v][u] = w;
        }
    }
    bool isedge(int u, int v)
    {
        if (adj[u][v] != 0)
            return true;
        else
            return false;
    }

    int ExtractMin()
    {
        int min_key = INT_MAX;
        int min_index = -1;
        for (int i = 0; i < n; i++)
        {
            if (q[i] == 1 && key[i] < min_key)
            {
                min_key = key[i];
                min_index = i;
            }
        }

        return min_index;
    }

    void MST_Prim(int r)
    {
        for (int i = 0; i < n; i++)
        {
            q[i] = 1;         // Initially all vertices are in Q
            key[i] = INT_MAX; // Set all keys to infinity
            p[i] = -1;        // Initialize parent array
        }
        key[r] = 0; // Set key of source vertex to 0
        for (int i = 0; i <= n; i++)
        {
            int u = ExtractMin();
            q[u] = 0; // Remove u from Q
            if (u == -1) break; // All vertices processed
            for (int v = 0; v < n; v++)
            {
                if (isedge(u, v))
                { // v is adjacent to u
                    if (q[v] == 1 && adj[u][v] < key[v])
                    {
                        p[v] = u;
                        key[v] = adj[u][v];
                    }
                }
            }
        }
        int cost = 0;
        cout << "Edge \tWeight\n";
        for (int i = 0; i < n; i++)
        {
            if (i != r)
            {
                cout << p[i] << " - " << i << "\t" << adj[i][p[i]] << " \n";
            }
            
            cost += key[i];
        }
        cout << "Total cost of MST: " << cost << endl;
    }
};

int main()
{
    Graph g(5, false);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 3, 3);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 3, 6);
    g.addEdge(3, 4, 2);
    g.MST_Prim(2);

    return 0;
}