#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    vector<vector<int>> trie;
    vector<bool> isTerminal;
    int nodeCount;
public:
    Trie() {
        trie.push_back(vector<int>(26, -1));
        isTerminal.push_back(false);
        nodeCount = 1;
    }

    void insert(const string& word) {
        int node = 0;
        for(char c : word) {
            int idx = c - 'a';
            if(trie[node][idx] == -1) {
                trie[node][idx] = nodeCount++;
                trie.push_back(vector<int>(26, -1));
                isTerminal.push_back(false);
            }
            node = trie[node][idx];
        }
        isTerminal[node] = true;
    }

    bool allPrefixesExist(const string& word) {
        int node = 0;
        for(char c : word) {
            int idx = c - 'a';
            node = trie[node][idx];
            if(node == -1 || !isTerminal[node]) return false;
        }
        return true;
    }
};
