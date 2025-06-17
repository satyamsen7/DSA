#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    int left;
    int right;
};

void inorder(int index, const vector<Node>& nodes, vector<int>& result) {
    if (index == -1) {
        return;
    }
    inorder(nodes[index - 1].left, nodes, result);
    result.push_back(index);
    inorder(nodes[index - 1].right, nodes, result);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    int n = indexes.size();
    vector<Node> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i].data = i + 1;
        nodes[i].left = indexes[i][0];
        nodes[i].right = indexes[i][1];
    }

    vector<vector<int>> result;
    for (int k : queries) {
        for (int i = 1; i <= n; ++i) {
            if (i % k == 0) {
                int index = i - 1;
                swap(nodes[index].left, nodes[index].right);
            }
        }

        vector<int> inorder_result;
        inorder(1, nodes, inorder_result);
        result.push_back(inorder_result);
    }

    return result;
}