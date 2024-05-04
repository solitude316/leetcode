/**
 * 55. Jump Game
 * https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printArr(vector<int>& nums, const string title)
{
    cout << "===============" << title << "===============\n";
    cout << "(";
    vector<int>::iterator it;

    for (it = nums.begin(); it != nums.end(); it++) {
        cout << *it;
        if (it != nums.end() - 1) {
            cout << ", ";
        }
    }

    cout << ")\n\n";
}


class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        
        bool result = true;
        int latest_index = (int)(nums.size() - 1);
        for(int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == 0 && i < latest_index) {
                result = false;
                for(int j = 0 ; j < i; j++) {
                    if (j + nums[j] > i) {
                        result = true;
                    }
                }
            }
            
            if (result == false) {
                return false;
            }
        }

        return result;
    }
};



int main(int argc, char** argv) {
    Solution solution;

    vector<int> nums;
    bool result;
    
//    nums = {2,3,1,1,4};
//    result = solution.canJump(nums);
//    cout << "result 1 = " << result << endl;
    
//    nums = {3,2,1,0,4};
//    result = solution.canJump(nums);
//    cout << "result 2 = " << result << endl;
    
//    nums = {2,0,0};
//    result = solution.canJump(nums);
//    cout << "result 3 = " << result << endl;
    
//    nums = {1,0,0,1,1,2,2,0,2,2};
//    result = solution.canJump(nums);
//    cout << "result 4 = " << result << endl;

    nums = {2,3,1,1,4};
    result = solution.canJump(nums);
    cout << "result 4 = " << result << endl;
    
    
    return 0;
}
