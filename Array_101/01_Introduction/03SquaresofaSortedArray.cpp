/**
 * Squares of a Sorted Array
 * https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3240/
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
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            result[i] = (nums[i] * nums[i]);
        }

        printArr(result);
        for (int i = 0; i < result.size() - 1; i++) {
            int index = i;
            int swap = result[index];
            for (int j = i + 1; j < result.size(); j++) {
                if (swap > result[j]) {
                    index = j;
                    swap = result[index];
                }
            }
            if (i != index) {
                result[index] = result[i];
                result[i] = swap;
            }
            printArr(result);
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution solution;

    vector<int> nums = { -4,-1,0,3,10 };

    vector<int> result = solution.sortedSquares(nums);

    printArr(result);

    return 0;
}