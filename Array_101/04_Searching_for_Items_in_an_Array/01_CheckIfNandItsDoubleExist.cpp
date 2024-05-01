/**
 * Check If N and Its Double Exist
 * https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3250/
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
    bool checkIfExist(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                if ((arr[i] ==  2 * arr[j]) || (2 * arr[i] == arr[j])) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> nums1 = { 10,2,5,3 };
    // nums1 = {3,1,7,11};
    nums1 = {7,1,14,11};
    bool result = solution.checkIfExist(nums1);
    printArr(nums1);
    cout << result;

    return 0;
}