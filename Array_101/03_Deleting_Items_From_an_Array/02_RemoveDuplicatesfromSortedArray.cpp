#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int>& nums)
{
    cout << "(";
    vector<int>::iterator it;

    for (it = nums.begin(); it != nums.end(); it++) {
        cout << *it;
        if (it != nums.end() - 1) {
            cout << ", ";
        }
    }

    cout << ")\n";
}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {    
                if (nums[i] == nums[j]) {
                    for(int k = j; k < nums.size() - 1; k++) {
                        nums[k] = nums[k + 1];
                    }
                    nums.erase(nums.end() - 1);
                    i--;
                    break;
                }
            }
        }

        return nums.size();
    }
};

int main(int argc, char** argv) {
    Solution solution;

    vector<int> nums1 = { 0,0,1,1,1,2,2,3,3,4 };

    // nums1 = {1,1,2};

    int result = solution.removeDuplicates(nums1);

    printArr(nums1);

    cout << "result = " << result << endl;

    return 0;
}