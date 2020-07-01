#include <bits/stdc++.h>
using namespace std;

int camelcase(string s) {
    int n = 1;
    for (auto i: s)
        if (i == toupper(i))
            n++;
    return n;
}

int main()
{
    string s;
    getline(cin, s);

    cout << camelcase(s) << "\n";
    return 0;
}
