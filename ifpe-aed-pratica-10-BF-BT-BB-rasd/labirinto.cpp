#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void solve(vector<string> &M) {
    // TODO

}

void print(const vector<string> &M) {
    for (auto &s : M) {
        cout << s << endl;
    }
    cout << endl;
}

int main() {
    vector<string> M1 = {
            ".#...",
            "...##",
            ".#..#",
            "o##.d",
            "#####"
    };

    vector<string> M2 = {
            "#...o",
            "..###",
            ".#...",
            "...#.",
            "###d."
    };

    solve(M1);
    print(M1);

    /* saída valida
    .#...
    xxx##
    x#xx#
    o##xd
    #####
    */

    solve(M2);
    print(M2);

    /*
    #xxxo
    xx###
    x#xxx
    xxx#x
    ###dx
     */


    return 0;
}


