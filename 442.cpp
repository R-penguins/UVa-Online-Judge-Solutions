/**
 * AOAPC II Example 5-3 Matrix Chain Manipulation
 */
#include <bits/stdc++.h>
using namespace std;
struct Matrix
{
    int a, b;
    Matrix(int a = 0, int b = 0) : a(a), b(b) { }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Matrix> mats(26);
    while (n--)
    {
        char name;
        cin >> name;
        int ind = name - 'A';
        cin >> mats[ind].a >> mats[ind].b;
    }
    string expr;
    while (cin >> expr)
    {
        stack<Matrix> s;
        bool error = false;
        long long ans = 0;
        for (char c : expr)
            if (isalpha(c))
                s.push(mats[c - 'A']);
            else if (c == ')')
            {
                Matrix mat2 = s.top();
                s.pop();
                Matrix mat1 = s.top();
                s.pop();
                if (mat1.b != mat2.a)
                {
                    error = true;
                    break;
                }
                ans += mat1.a * mat1.b * mat2.b;
                s.push(Matrix(mat1.a, mat2.b));
            }
        if (error)
            cout << "error\n";
        else
            cout << ans << "\n";
    }
}
