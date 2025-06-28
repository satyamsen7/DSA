#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Edge {
    int dest;
    int weight;
    string color;
};

int calculate_score(const vector<vector<int>>& adj_matrix, const vector<pair<int, int>>& claimed_edges) {
    int score = 0;
    vector<bool> visited(adj_matrix.size(), false);
    vector<int> component_sizes;

    function<void(int, int&)> dfs = [&](int u, int& size) {
        visited[u] = true;
        size++;
        for (int v = 0; v < adj_matrix.size(); ++v) {
            if (adj_matrix[u][v] && find(claimed_edges.begin(), claimed_edges.end(), make_pair(u, v)) != claimed_edges.end() && !visited[v]) {
                dfs(v, size);
            }
        }
    };

    for (int i = 0; i < adj_matrix.size(); ++i) {
        if (!visited[i]) {
            int size = 0;
            dfs(i, size);
            component_sizes.push_back(size);
        }
    }

    for (int size : component_sizes) {
        if (size == 1) continue;
        if (size == 2) score += 1;
        else if (size == 3) score += 2;
        else if (size == 4) score += 4;
        else if (size == 5) score += 7;
        else if (size == 6) score += 15;
        else if (size >= 7) score += 21;
    }

    return score;
}

int main() {
    int num_cities, num_routes;
    cin >> num_cities >> num_routes;

    map<string, int> city_indices;
    vector<string> city_names(num_cities);

    for (int i = 0; i < num_cities; ++i) {
        string city_name;
        cin >> city_name;
        city_indices[city_name] = i;
        city_names[i] = city_name;
    }

    vector<vector<Edge>> adj_list(num_cities);
    vector<vector<int>> adj_matrix(num_cities, vector<int>(num_cities, 0));

    for (int i = 0; i < num_routes; ++i) {
        string city1, city2, color;
        int weight;
        cin >> city1 >> city2 >> weight >> color;

        int u = city_indices[city1];
        int v = city_indices[city2];

        adj_list[u].push_back({v, weight, color});
        adj_list[v].push_back({u, weight, color});

        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    int num_claimed;
    cin >> num_claimed;

    vector<pair<int, int>> claimed_edges;
    for (int i = 0; i < num_claimed; ++i) {
        string city1, city2;
        cin >> city1 >> city2;

        int u = city_indices[city1];
        int v = city_indices[city2];

        claimed_edges.push_back(make_pair(u, v));
        claimed_edges.push_back(make_pair(v, u));
    }

    cout << calculate_score(adj_matrix, claimed_edges) << endl;

    return 0;
}