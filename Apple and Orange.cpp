#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

struct RANGE {
    int start;
    int end;
};

RANGE range(int start, int end) {
    RANGE r;
    r.start = start;
    r.end = end;
    return r;
}

bool inRange(int x, RANGE r) {
    if ((r.start <= x) && (x <= r.end))
        return true;
    return false;
}

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int noOfApples = 0;
    int noOfOranges = 0;

    for (int i=0; i<apples.size(); i++) {
        if (inRange(apples[i] + a, range(s, t)))
            noOfApples++;
    }

    for (int i=0; i<oranges.size(); i++) {
        if (inRange(oranges[i] + b, range(s, t)))
            noOfOranges++;
    }

    cout << noOfApples << endl
         << noOfOranges << endl;
}

int main()
{
    string st_temp;
    getline(cin, st_temp);

    vector<string> st = split_string(st_temp);

    int s = stoi(st[0]);

    int t = stoi(st[1]);

    string ab_temp;
    getline(cin, ab_temp);

    vector<string> ab = split_string(ab_temp);

    int a = stoi(ab[0]);

    int b = stoi(ab[1]);

    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    string apples_temp_temp;
    getline(cin, apples_temp_temp);

    vector<string> apples_temp = split_string(apples_temp_temp);

    vector<int> apples(m);

    for (int i = 0; i < m; i++) {
        int apples_item = stoi(apples_temp[i]);

        apples[i] = apples_item;
    }

    string oranges_temp_temp;
    getline(cin, oranges_temp_temp);

    vector<string> oranges_temp = split_string(oranges_temp_temp);

    vector<int> oranges(n);

    for (int i = 0; i < n; i++) {
        int oranges_item = stoi(oranges_temp[i]);

        oranges[i] = oranges_item;
    }

    countApplesAndOranges(s, t, a, b, apples, oranges);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
