/**
 * Sort Array By Parity
 * https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3260/
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
    vector<int> sortArrayByParity(vector<int>& nums) {
        int pos = 0;
        bool odd_found = false;
        printArr(nums, "Origin");
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] %2 == 0) {
                cout << "even found : " << nums[i] << endl;
                if(odd_found == false) {
                    cout << "pos++\n";
                    pos++;
                } else {
                    cout << "pos = " << pos << ", nums[pos] = " << nums[pos] << ", nums[i] = " << nums[i] << endl;
                    int swap = nums[pos];
                    nums[pos] = nums[i];
                    nums[i] = swap;
                    pos++;
                }
            } else {
                cout << "odd funded : " << nums[i] << endl;
                odd_found = true;
            }

            printArr(nums, "Sorting");
        }
        printArr(nums, "resultsss");

        return nums;
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> nums1 = { 3,1,2,4 };
    // nums1 = {0,2,1};
    
    vector<int> result = solution.sortArrayByParity(nums1);
    printArr(result, "result");
    
    return 0;
}
