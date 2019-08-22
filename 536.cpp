/**
 * AOAPC II Exercise 6-3 Tree Recovery
 * ULM Local 1997
 * 20 AC;
 */
#include <bits/stdc++.h>
using namespace std;
string preord, inord, postord;
void recover(int pre_beg, int pre_end, int in_beg, int in_end)
{
    char root = preord[pre_beg];
    int in_root_pos = inord.find(root), left_sz = in_root_pos - in_beg;
    if (left_sz)
        recover(pre_beg + 1, pre_beg + left_sz, in_beg, in_root_pos);
    if (in_root_pos < in_end - 1)
        recover(pre_beg + 1 + left_sz, pre_end, in_root_pos + 1, in_end);
    postord += root;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    while (cin >> preord >> inord)
    {
        postord = "";
        recover(0, preord.size(), 0, inord.size());
        cout << postord << "\n";
    }
}
