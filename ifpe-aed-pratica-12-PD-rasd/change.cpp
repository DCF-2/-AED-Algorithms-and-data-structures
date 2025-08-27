#include <vector>
#include <iostream>

using namespace std;

class Solution {

    

public:

    int coinChange(vector<int>& coins, int amount) {
        // TODO
       
        return -1;
    }

    
};

int main() {

    cout << Solution().coinChange3({1, 2, 5}, 11) << endl; // res = 3
    cout << Solution().coinChange3({1, 6, 7, 9, 11}, 13) << endl; // res = 2
    cout << Solution().coinChange3({1, 2, 5, 10}, 16) << endl; // res = 3
    cout << Solution().coinChange3({1, 2, 7, 10}, 16) << endl; // res = 3 (greedy = 4)
    cout << Solution().coinChange3({1,2,5,7,8,4}, 30) << endl; // res = 4
    cout << Solution().coinChange3({83, 186, 408, 419}, 6249) << endl; // res = 20

    return 0;
}