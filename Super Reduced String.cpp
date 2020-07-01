#include <bits/stdc++.h>
using namespace std;

bool canBeReduced(string s) {
    for (int i=1; i<s.size(); i++)
        if (s[i] == s[i-1])
            return true;
    return false;
}

string superReducedString(string s) {
    if (s == "")
        return "Empty String";
    else if (canBeReduced(s)) {
        for (int i=1; i<s.size(); i++) {
            if (s[i] == s[i-1]) {
                s.erase(i-1, 2);
                i = 0;
            }
        }
        return superReducedString(s);
    } else
        return s;
}

int main()
{
    string s;
    getline(cin, s);
    cout << superReducedString(s) << "\n";
    return 0;
}
