/**
 * Find Numbers with Even Number of Digits
 * https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3237/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for (int item : nums) {
            int digit = 0;
            while(item >= 1) {
                digit++;
                item = item / 10;
            }
            
            if (digit %2 == 0) {
                result++;
            }
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution solution;

    vector<int> nums = { 12,345,2,6,7896 };

    int result = solution.findNumbers(nums);

    cout << result << endl;
}