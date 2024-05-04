/**
 * 189. Rotate Array
 * https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150
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
    void rotate(vector<int>& nums, int k) {
        
        k = k % nums.size();
        
        vector<int> temp (nums.end() - k, nums.end());
        temp.insert(temp.end(), nums.begin(), nums.end() - k);
        nums = temp;
        printArr(nums, "nums");
    }
};



int main(int argc, char** argv) {
    Solution solution;

    vector<int> nums = {1,2,3,4,5,6,7};

    solution.rotate(nums, 3);
    
    return 0;
}
