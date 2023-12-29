#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits.h>
using namespace std;

unordered_map<int, vector<pair<int, int>>> graph;

void shortest_path(int start)
{
    unordered_map<int, int> distances;
    for (auto &it : graph)
    {
        distances[it.first] = INT_MAX;
    }
    distances[start] = 0;
    vector<int> visited;
    vector<int> unvisited;
    for (auto &it : graph)
    {
        unvisited.push_back(it.first);
    }
    int current = start;
    while (!unvisited.empty())
    {
        for (auto &neighbor : graph[current])
        {
            if (find(visited.begin(), visited.end(), neighbor.first) == visited.end())
            {
                distances[neighbor.first] = min(distances[neighbor.first], distances[current] + neighbor.second);
            }
        }
        visited.push_back(current);
        unvisited.erase(find(unvisited.begin(), unvisited.end(), current));
        if (!unvisited.empty())
        {
            current = *min_element(unvisited.begin(), unvisited.end(),
                                   [&](const int &node1, const int &node2)
                                   {
                                       return distances[node1] < distances[node2];
                                   });
        }
    }
    for (auto &it : distances)
    {
        cout << "Shortest distance from " << start << " to " << it.first << " is " << it.second << endl;
    }
}

int main()
{
    graph = {
        {1, {{2, 1}, {3, 4}}},
        {2, {{4, 3}}},
        {3, {{4, 2}, {5, 5}}},
        {4, {{5, 1}}},
        {5, {}}};
    shortest_path(1);
    return 0;
}
