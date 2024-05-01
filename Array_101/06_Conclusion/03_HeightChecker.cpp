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
    int heightChecker(vector<int>& heights) {
        printArr(heights, "Input");
        int count = 0;
        
        vector<int> sorted_arr = heights;
        
        int minimum_index;
        int minimum_value;
        for(int i = 0; i < sorted_arr.size() - 1; i++) {
            minimum_index = i;
            minimum_value = sorted_arr[minimum_index];

            for(int j = i + 1; j < sorted_arr.size(); j++) {
                if (minimum_value > sorted_arr[j]) {
                    minimum_index = j;
                    minimum_value = sorted_arr[minimum_index];
                }
            }

            sorted_arr[minimum_index] = sorted_arr[i];
            sorted_arr[i] = minimum_value;
        }

        for(int i = 0; i < sorted_arr.size(); i++) {
            if (sorted_arr[i] != heights[i]) {
                count++;
            }
        }

        printArr(sorted_arr, "result");

        return count;
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> nums1 = { 1,1,4,2,1,3 };
    
    int result = solution.heightChecker(nums1);
    cout << "result = " << result;
    
    return 0;
}
