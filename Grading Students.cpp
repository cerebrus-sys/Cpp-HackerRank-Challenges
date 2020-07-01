#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int nextMultiple(int x) {
    while (x % 5 != 0)
        x++;
    return x;
}

vector<int> gradingStudents(vector<int> grades) {
    for (int i=0; i<grades.size(); i++) {
        int grade = grades[i];
        if (grade >= 38) {
            int nextMultiple = ::nextMultiple(grade);
            if (nextMultiple - grade < 3)
                grades[i] = nextMultiple;
        }
    }
    return grades;
}

int main()
{
    string grades_count_temp;
    getline(cin, grades_count_temp);

    int grades_count = stoi(ltrim(rtrim(grades_count_temp)));

    vector<int> grades(grades_count);

    for (int i = 0; i < grades_count; i++) {
        string grades_item_temp;
        getline(cin, grades_item_temp);

        int grades_item = stoi(ltrim(rtrim(grades_item_temp)));

        grades[i] = grades_item;
    }

    vector<int> result = gradingStudents(grades);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";
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
