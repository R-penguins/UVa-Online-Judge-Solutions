/**
 * AOAPC II Example 5-2 The Blocks Problem
 */
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> piles;
void find_block(int a, int &blo, int &pos) {
    for (int b = 0; b < piles.size(); ++b) {
        auto p = find(piles[b].begin(), piles[b].end(), a);
        if (p != piles[b].end()) {
            blo = b;
            pos = p - piles[b].begin();
            return;
        }
    }
}
void clear_above(int blo, int pos) {
    for_each(piles[blo].begin() + pos + 1, piles[blo].end(), [](int i){
        piles[i].push_back(i);
    });
    piles[blo].resize(pos + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b, i = 0;
    cin >> n;
    piles = vector<vector<int>>(n);
    for (auto &p : piles)
        p.push_back(i++);
    string cmd1, cmd2;
    while (cin >> cmd1 >> a >> cmd2 >> b) {
        int bloA, bloB, posA, posB;
        find_block(a, bloA, posA);
        find_block(b, bloB, posB);
        if (bloA == bloB)
            continue;
        if (cmd1 == "move")
            clear_above(bloA, posA);
        if (cmd2 == "onto")
            clear_above(bloB, posB);
        copy(piles[bloA].begin() + posA, piles[bloA].end(), back_inserter(piles[bloB]));
        piles[bloA].resize(posA);
    }
    i = 0;
    for (auto &p : piles) {
        cout << i++ << ":";
        for (int j : p)
            cout << " " << j;
        cout << "\n";
    }
}
