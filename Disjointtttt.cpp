#include <iostream>
#include <vector>
using namespace std;

class DSU {
    vector<int> parent, rankv;

public:
    DSU(int n) {
        parent.resize(n);
        rankv.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA != rootB) {
            if (rankv[rootA] < rankv[rootB])
                parent[rootA] = rootB;
            else if (rankv[rootA] > rankv[rootB])
                parent[rootB] = rootA;
            else {
                parent[rootB] = rootA;
                rankv[rootA]++;
            }
        }
    }
};

int main() {
    DSU dsu(5);

    dsu.unite(0, 1);
    dsu.unite(1, 2);

    if (dsu.find(0) == dsu.find(2))
        cout << "Connected\n";
    else
        cout << "Not Connected\n";

    return 0;
}
