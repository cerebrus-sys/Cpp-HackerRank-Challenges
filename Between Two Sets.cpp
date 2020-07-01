#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int lcm(vector<int> ar) {
    int n1, n2;
    int lcm = ar[0];

    for (uint64_t i=1; i<ar.size(); i++) {
        n1 = lcm;
        n2 = ar[i];

        lcm = max(n1, n2);

        do {
            if ((lcm % n1 == 0) && (lcm % n2 == 0)) {
                return lcm;
            } else {
                lcm++;
            }
        } while (true);
    }

    return lcm;
}

bool isMultipleOf(int a, vector<int> b) {
    for (auto c: b) {
        if (c % a != 0)
            return false;
    }
    return true;
}

int min(vector<int> ar) {
    int m = ar[0];
    for (uint64_t i=1; i<ar.size(); i++) {
        if (ar[i] < m)
            m = ar[i];
    }
    return m;
}

int getTotalX(vector<int> a, vector<int> b) {
    int result = 0;

    int ax = lcm(a);

    for (int i=1; ax * i <= min(b); i++) {
        if (isMultipleOf(ax * i, b))
            result++;
    }

    return result;
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);
    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);
        arr[i] = arr_item;
    }

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));
    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);
        brr[i] = brr_item;
    }

    cout << getTotalX(arr, brr) << "\n";
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
