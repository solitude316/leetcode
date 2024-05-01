/**
 * Move Zeroes
 * https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3157/
*/
#include <iostream>
#include <vector>
#include <string>

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
    void moveZeroes(vector<int>& nums) {
        int latest_pos = nums.size();
        for(int i = 0; i < latest_pos; i++) {
            if(nums[i] == 0) {
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                latest_pos--;
                i--;
            }
        }
        printArr(nums, "result");
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> nums1 = { 2,1 };
    nums1 = { 0,1,0,3,12 };
    nums1 = {0,0,1};
    
    solution.moveZeroes(nums1);
    
    return 0;
}
