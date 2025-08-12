#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparar(const string &a, const string &b) {
   return a.length() < b.length();
}

vector<vector<string>> groupStrings(vector<string> &strs) {
    vector<vector<string>> res;
    if (strs.empty()) {
        return res;
    }

    sort(strs.begin(), strs.end(), comparar);

    vector<string> current_group;
    current_group.push_back(strs[0]);

    for (size_t i = 1; i < strs.size(); i++) {
        if (strs[i].length() == strs[i - 1].length()) {
            current_group.push_back(strs[i]);
        } else {
            res.push_back(current_group);
             current_group.clear();
            current_group.push_back(strs[i]);
        }
    }
    res.push_back(current_group);

    return res;
}

int main() {

    vector<string> strs = {"Redes", "IFPE", "Algoritmos", "Android",
                           "Complexidade", "IF", "PE", "Recife",
                           "TADS", "2025", "BubbleSort", "Git",
                           "GitHub", "Subversion", "Gradle", "Docker"};

    vector<vector<string>> groups = groupStrings(strs);

    for (const auto &group : groups) {
        for (const auto &str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}