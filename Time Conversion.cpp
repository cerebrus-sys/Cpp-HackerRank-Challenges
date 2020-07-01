#include <bits/stdc++.h>
using namespace std;

string timeConversion(string s) {
    bool isPM = (s[8] == 'P');
    int hour = (int(s[0]) - 48) * 10 + (int(s[1]) - 48);

    string tmp;
    for (int i=0; i<8; i++)
        tmp += s[i];
    s = tmp;

    if ((hour == 12) && !isPM) {
        s[0] = '0';
        s[1] = '0';
    }
    else if ((hour != 12) && isPM) {
        hour = hour + 12;
        int x = hour % 10;
        s[1] = char(x) + 48;
        hour = (hour - x) / 10;
        s[0] = char(hour) + 48;
    }

    return s;
}

int main()
{
    string s;
    getline(cin, s);

    string result = timeConversion(s);

    cout << result << "\n";
    return 0;
}
