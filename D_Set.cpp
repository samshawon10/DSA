#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSet
{
    int n;
    vector<int> parent, rank;

public:
    DSet(int n) : n(n)
    {
        parent = vector<int>(n);
        rank = vector<int>(n);
    }

    void makeSet(int x)
    {
        parent[x] = x;
        rank[x] = 0;
    }
    int find(int x)
    { // returns the representative of the set containing x
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
        {
            // x and y are already in the same set
            // no need to do anything
            return;
        }

        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};
// kruskals algorithm can be implemented using this DSet class
class Graph
{
    int n;
    vector<vector<int>> edges;

public:
    Graph(int n) : n(n) {}
    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, u, v});
    }
    void kruskalMST()
    {
        vector<vector<int>> T;
        DSet ds(n);
        for (int i = 0; i < n; i++)
        {
            ds.makeSet(i);
        }
        sort(edges.begin(), edges.end());
        for (vector<int> e : edges)
        {
            int w = e[0];
            int u = e[1];
            int v = e[2];
            if (ds.find(u) != ds.find(v))
            {
                T.push_back({u, v, w});
                ds.unionSets(u, v);
            }
        }
        int cost = 0;
        cout << "Edges in the Minimum Spanning Tree:\n";
        for (vector<int> e : T)
        {
            cout << e[0] << " -- " << e[1] << " == " << e[2] << endl;
            cost += e[2];
        }
        cout << "Total cost of the Minimum Spanning Tree: " << cost << endl;
    }
};
int main()
{
    Graph g(3);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 6);
    g.addEdge(0, 1, 2);

    g.kruskalMST();

    return 0;
}
