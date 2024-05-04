/**
 * Remove Duplicates from Sorted Array II
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150
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
    int removeDuplicates(vector<int>& nums) {
        int stept = 0;
        bool is_duplicated = false;
        int pos = 0;
        is_duplicated = false;
        
        for(int i = 1; i < nums.size(); i++) {
            cout << ++stept << ", nums[" <<pos <<"]= " << nums[pos] << "nums[" << i <<"] = " << nums[i] << endl;
            cout << "is_duplicated = " << is_duplicated << endl;
            if(nums[i] == nums[pos]) {
                cout << "condition1" << endl;
                if (is_duplicated == false) {
                    is_duplicated = true;
                    pos++;
                    nums[pos] = nums[i];
                }
            } else {
                pos++;
                
                nums[pos] = nums[i];
                is_duplicated = false;
            }
            printArr(nums, " moving ");
        }
        
        printArr(nums, " result ");
        return pos + 1;
    }
};


int main(int argc, char** argv) {
    Solution solution;
    vector<int> nums1 = { 0,0,1,1,1,1,2,3,3 };
    
    int result = solution.removeDuplicates(nums1);
    cout << "result = " << result <<endl;

    return 0;
}
