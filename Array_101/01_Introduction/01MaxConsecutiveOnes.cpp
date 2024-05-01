/**
 * Max Consecutive Ones
 * https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3238/
 * 
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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.size() == 0)
            throw invalid_argument("nums should has item.");

        int max = 0;
        int count = 0;
        for (int item : nums) {
            if (item == 1) {
                count++;
                if (count > max) {
                    max = count;
                }
            }
            else {
                count = 0;
            }
        }
        return max;
    }
};

int main(int argc, char** argv) {
    Solution solution;

    vector<int> nums = { 1,0,1,1,0,1 };

    int result = solution.findMaxConsecutiveOnes(nums);

    cout << result << endl;
}