#include <bits/stdc++.h>
using namespace std;

long flippingBits(long n) {
    return 4294967295 - n;
}

int main()
{
    int q;
    cin >> q;
    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        cin >> n;
        cout << flippingBits(n) << "\n";
    }
    return 0;
}
