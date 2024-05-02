/**
 * Remove Element
 * https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150
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
    int removeElement(vector<int>& nums, int val) {

        for (int index = 0; index < nums.size(); index++) {
            if (nums[index] == val) {
                nums.erase(nums.begin() + index);
                index--;
            }
        }

        printArr(nums, "result");

        return nums.size();
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> nums1 = { 3,2,2,3 };

    int result = solution.removeElement(nums1, 3);


    return 0;
}