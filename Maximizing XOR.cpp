#include <bits/stdc++.h>
using namespace std;

int maximizingXor(int l, int r) {
    int m = 0;
    for (int i=l; i<=r; i++)
        for (int j=l; j<=r; j++)
            if ((i^j) > m)
                m = (i^j);
    return m;
}

int main()
{
    int l, r;
    cin >> l >> r;
    cout << maximizingXor(l, r) << "\n";
    return 0;
}
