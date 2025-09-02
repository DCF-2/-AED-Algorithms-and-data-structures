#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    Solution() {}

    int climbStairs(int n) {
            if(n <= 1)return 1;
            vector<int>tabela(n+1);

            tabela[0] = 1;
            tabela[1] = 1;

            for(int i = 2; i <= n; i++){
                tabela[i] = tabela[i-1] + tabela[i-2];
            }
        return tabela[n];
    }
};

int main() {

    cout << Solution().climbStairs(1) << endl; // res = 1
    cout << Solution().climbStairs(2) << endl; // res = 2
    cout << Solution().climbStairs(3) << endl; // res = 3
    cout << Solution().climbStairs(4) << endl; // res = 5
    cout << Solution().climbStairs(5) << endl; // res = 8
    cout << Solution().climbStairs(10) << endl; // res = 89
    cout << Solution().climbStairs(45) << endl; // res = 1836311903 (45 é o limite)

    return 0;
}