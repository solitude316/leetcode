/**
 * Valid Mountain Array
 * https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3251/
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
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) {
            return false;
        }

        bool has_increasing = false;
        bool is_switched = false;

        for(int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                return false;
            }

            if (arr[i] < arr[i + 1]) {
                has_increasing = true;

                if(is_switched == true) {
                    return false;
                }
            } else {
                if (has_increasing == true) {
                    is_switched = true;
                } else {
                    if (is_switched == false) {
                        return false;
                    }
                }
            }
        }

        return (is_switched == true);
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> nums1 = { 3,5,5 };
    // nums1 = { 0,3,2,1 };
    // nums1 = {9,8,7,6,5,4,3,2,1,0};
    nums1 = {0,1,2,3,4,5,6,7,8,9};
    bool result = solution.validMountainArray(nums1);
    printArr(nums1);
    cout << result;

    return 0;
}
