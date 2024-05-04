/**
 * 169 Majority Element
 * https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150
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
    int majorityElement(vector<int>& nums) {
        int result = nums[0];
        int count = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            if (result == nums[i]) {
                count++;
            } else if (count > 0){
                count--;
            } else {
                result = nums[i];
                count++;
            }
        }
        
        return result;
    }
};


int main(int argc, char** argv) {
    Solution solution;

    vector<int> nums = {2,2,1,1,1,2,2};

    int result = solution.majorityElement(nums);
    cout << result << endl;
    
    return 0;
}
