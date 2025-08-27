#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &array, int start, int finish) {
    // TODO
   
    return -1;
}

int quickselect(vector<int> &values, int k) {
    // TODO

    return -1;
}

class KthLargest {
    int k;
    vector<int> scores;
public:
    KthLargest(int k, vector<int>& nums) : k(k), scores(nums.size()) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            scores[i] = nums[i];
        }
    }

    int add(int val) {
        scores.push_back(val);
        return quickselect(scores, scores.size() - k);
    }

    const vector<int> & values() {
        return scores;
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    vector<int> vals = {3, 5, 10, 9, 4};
    KthLargest kthLargest (3, nums);

    for (int v : vals) {
        cout << "Adicionando " << v << ", 3o maior eh " << kthLargest.add(v) << endl;
        for (int x : kthLargest.values()) {
            cout << x << " ";
        }
        cout << endl;
    }
}
