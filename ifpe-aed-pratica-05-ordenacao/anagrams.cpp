#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

	// TO DO

        return res;
    }
};

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    auto res = Solution().groupAnagrams(strs);

    for (const auto &group : res) {
        for (const auto &str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

}