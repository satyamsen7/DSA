#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;

    dist[startX][startY] = 0;
    q.push({startX, startY});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == goalX && y == goalY) {
            return dist[x][y];
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            while (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == '.' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
                nx += dx[i];
                ny += dy[i];
            }
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int startX, startY, goalX, goalY;
    cin >> startX >> startY >> goalX >> goalY;

    cout << minimumMoves(grid, startX, startY, goalX, goalY) << endl;

    return 0;
}