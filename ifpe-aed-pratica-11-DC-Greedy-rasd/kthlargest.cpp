#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &array, int start, int finish) {
   int pivo = array[finish];
   //usar star - 1 ->  Ao inicializá-lo como -1, a função só 
   //funcionará corretamente para partições que começam no índice 0. 
   //A correção é inicializá-lo como start - 1.
   int i = start -1;
   for(size_t j = start; j < finish; j++){
        if(array[j] <= pivo){
            i++;
            swap(array[i], array[j]);
        }
   }
   swap(array[i+1], array[finish]);
    return i+1;
}

int quickselect(vector<int> &values, int k) {
    int ini = 0;
    //'end' deve apontar para o último elemento.
    int end = values.size() -1;

    while(ini <= end){
        int idx_pivo = partition(values, ini, end);

        if(idx_pivo == k){
            return values[k];
        } else if(k < idx_pivo){
            end = idx_pivo -1;
        }else{
            ini = idx_pivo +1;
        }
    }
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
