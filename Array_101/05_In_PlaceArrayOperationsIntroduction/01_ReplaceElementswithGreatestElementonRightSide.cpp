/**
 * Replace Elements with Greatest Element on Right Side
 * https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3259/
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
    vector<int> replaceElements(vector<int>& arr) {
        if (arr.size() == 1) {
            arr[0] = -1;
        }
        printArr(arr, "start");
        for(int i = 0; i < arr.size() - 1; i++) {
            arr[i] = arr[i + 1];
            // printArr(arr, "before change");
            for(int j = i + 1; j < arr.size(); j++) {
                if (arr[j] > arr[i]) {
                    arr[i] = arr[j];
                }
                // printArr(arr, "after change");
            }
        }
        arr[arr.size() - 1] = -1;

        return arr;
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> nums1 = { 17,18,5,4,6,1 };
    nums1 = {57010,40840,69871,14425,70605};
    nums1 = {56903,18666,60499,57517,26961};
    
    vector<int> result = solution.replaceElements(nums1);
    
    printArr(result, "output");

    return 0;
}
