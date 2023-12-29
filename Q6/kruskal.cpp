#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge
{
    int src, dest, weight;
};
struct Subset
{
    int parent, rank;
};
bool compareEdges(Edge a, Edge b)
{
    return a.weight < b.weight;
}
int find(Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void unionSubsets(Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
vector<Edge> kruskalMST(int V, vector<Edge> edges)
{
    vector<Edge> result;
    Subset subsets[V];
    int e = 0;
    sort(edges.begin(), edges.end(), compareEdges);
    for (int i = 0; i < V; i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    for (int i = 0; i < edges.size(); i++)
    {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);
        if (x != y)
        {
            result.push_back(edges[i]);
            unionSubsets(subsets, x, y);
            e++;
        }
        if (e == V - 1)
            break;
    }
    return result;
}
void printMST(vector<Edge> edges)
{
    int total_weight = 0;
    cout << "Edges of the Minimum Spanning Tree:" << endl;
    for (int i = 0; i < edges.size(); i++)
    {
        cout << edges[i].src << " -- " << edges[i].dest << " (weight: " << edges[i].weight << ")" << endl;
        total_weight += edges[i].weight;
    }
    cout << "Total weight of the MST: " << total_weight << endl;
}
int main()
{
    int V, E;
    cout << "Enter the number of vertices and edges in the graph: ";
    cin >> V >> E;
    vector<Edge> edges;
    cout << "Enter the source vertex, destination vertex, and weight of each edge:"
         << endl;
    for (int i = 0; i < E; i++)
    {
        Edge e;
        cin >> e.src >> e.dest >> e.weight;
        edges.push_back(e);
    }
    vector<Edge> mst = kruskalMST(V, edges);
    printMST(mst);
    return 0;
}