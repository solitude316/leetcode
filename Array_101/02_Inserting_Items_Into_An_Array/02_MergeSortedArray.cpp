/**
 * Merge Sorted Array
 * https://leetcode.com/explore/learn/card/fun-with-arrays/525/inserting-items-into-an-array/3253/
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; i++) {
            nums1[m] = nums2[i];
            for(int j = m; j > 0; j--) {
                if (nums1[j] < nums1[j - 1]) {
                    int swap = nums1[j];
                    nums1[j] = nums1[j - 1];
                    nums1[j - 1] = swap;
                }
            }
            m++;
        }
    }
};

int main(int argc, char** argv) {
    Solution solution;

    vector<int> nums1 = { 1,2,3,0,0,0 };
    vector<int> nums2 = { 2,5,6 };

    solution.merge(nums1, 3, nums2, 3);

    printArr(nums1);

    return 0;
}