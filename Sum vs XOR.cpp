#include <bits/stdc++.h>
using namespace std;

long sumXor(long n) {
    long c = 0;
    while (n) {
        c += n % 2 ? 0 : 1;
        n /= 2;
    }
    c = pow(2, c);
    return c;
}

int main()
{
    string s;
    getline(cin, s);
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    cout << sumXor(stol(s)) << "\n";
    return 0;
}
