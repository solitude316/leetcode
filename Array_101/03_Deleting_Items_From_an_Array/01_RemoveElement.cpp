/**
 * Remove Element
 * https://leetcode.com/explore/learn/card/fun-with-arrays/526/deleting-items-from-an-array/3247/
*/
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
    int removeElement(vector<int>& nums, int val) {
        int result = 0;
    
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                nums[i] = nums[nums.size() - 1];
                nums.erase(nums.end() - 1); 
                result++;
                i--;
            }
            printArr(nums);
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution solution;

    vector<int> nums1 = { 0,1,2,2,3,0,4,2 };

    int result = solution.removeElement(nums1, 2);

    printArr(nums1);

    cout << "result = " << result << endl;

    return 0;
}