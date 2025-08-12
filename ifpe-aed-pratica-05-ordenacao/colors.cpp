#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /// @brief Algoritimo da bandeira holandesa.
    /// @param nums 
    void sortColors(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int hight = nums.size()- 1;

    while (mid <= hight){
            if(nums[mid]== 0){
                swap(nums[low], nums[mid]);
                mid++;
                low++;
        }else if(nums[mid] == 1){
                    mid++;
            }else if(nums[mid] == 2){
                swap(nums[mid], nums[hight]);
                hight--;
            }
    }
    
        
    }
};

int main() {
    vector<int> test1 = {2, 0, 2, 1, 1, 0};
    vector<int> test2 = {2, 0, 1};
    vector<int> test3 = {1, 1, 0, 2, 0, 2, 1, 2, 0, 1, 1, 0, 2, 0, 2};

    Solution().sortColors(test1); for (int v : test1) cout << v << " "; cout << endl;
    Solution().sortColors(test2); for (int v : test2) cout << v << " "; cout << endl;
    Solution().sortColors(test3); for (int v : test3) cout << v << " "; cout << endl;

    return 0;
}