#include <bits/stdc++.h>
using namespace std;
int main() {
    const vector<int> pf { 2, 3, 5 };
    set<long long> uglys { 1 };
    for (int cnt = 1; cnt < 1500; ++cnt) {
        long long cur = *uglys.begin();
        uglys.erase(cur);
        for (int f : pf)
            uglys.insert(cur * f);
    }
    cout << "The 1500'th ugly number is " << *uglys.begin() << ".\n";
}
