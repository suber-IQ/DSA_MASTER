#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool valid(int i, int j, int n) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

void ratMaze(vector<vector<int>>& matrix, int i, int j, vector<string>& ans, string path, vector<vector<bool>>& visited, int n, int* row, int* col, string dir) {
    // base case
    if (i == n - 1 && j == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int newRow = i + row[k];
        int newCol = j + col[k];
        if (valid(newRow, newCol, n) && matrix[newRow][newCol] && !visited[newRow][newCol]) {
            path.push_back(dir[k]);
            ratMaze(matrix, newRow, newCol, ans, path, visited, n, row, col, dir);
            path.pop_back();
        }
    }

    visited[i][j] = false;
}

int main() {
    vector<vector<int>> m{
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    };
    int n = m.size(); // Size of the matrix (number of rows)
    vector<vector<bool>> visited(n, vector<bool>(m[0].size(), false)); // Corrected dimensions
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    string dir = "UDLR";
    string path;
    vector<string> ans;

    int i = 0, j = 0;
    ratMaze(m, i, j, ans, path, visited, n, row, col, dir);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    // T.C: O(3^N^2)
    // S.C: O(n)

    return 0;
}
