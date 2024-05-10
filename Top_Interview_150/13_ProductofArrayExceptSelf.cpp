/**
 * 238. Product of Array Except Self
 * https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printArr(vector<int>& nums, const string title)
{
    cout << "=============== " << title << " ===============\n";
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
    vector<int> productExceptSelf(vector<int>& nums) {
        long m = 1;
        int zero_count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                m *= nums[i];
            }
            else {
                zero_count++;
            }
        }

        vector<int>result(nums.size(), 0);
        if (zero_count > 1) {
            return result;
        }


        for (size_t i = 0; i < nums.size(); i++) {
            if (zero_count == 1) {
                if (nums[i] == 0) {
                    result[i] = m;
                }
            }
            else {
                result[i] = m / nums[i];
            }
        }

        return result;
    }
};



int main(int argc, char** argv) {
    Solution solution;

    vector<int> nums = { 1,2,3,4 };

    vector<int> result = solution.productExceptSelf(nums);
    printArr(result, " result ");

    nums = { -1,1,0,-3,3 };
    result = solution.productExceptSelf(nums);
    printArr(result, " result ");
    
    return 0;
}