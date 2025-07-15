#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    vector<vector<int>> tri;
    vector<bool> isTerminal;
    int N;

    Trie() {
        tri.push_back(vector<int>(2, -1));
        isTerminal.push_back(false);
        N = 1;
    }

    void insert(const int n) {
        int node = 0;
        for(int i = 30; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if(tri[node][bit] == -1) {
                tri[node][bit] = N++;
                tri.push_back(vector<int>(2, -1));
                isTerminal.push_back(false);
            }
            node = tri[node][bit];
        }
        isTerminal[node] = true;
    }

    bool find(const int n) {
        int node = 0;
        for(int i = 30; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if(tri[node][bit] == -1) return false;
            node = tri[node][bit];
        }
        return isTerminal[node];
    }
};
