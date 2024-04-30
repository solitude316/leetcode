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
    void duplicateZeros(vector<int>& arr) {
        printArr(arr);
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 0) {
                i++;
                arr.insert(arr.begin() + i, 0);
                arr.erase(arr.end() - 1);
            }
            
            printArr(arr);
        }
    }
};

int main(int argc, char** argv) {
    Solution solution;

    vector<int> nums = { 1,0,2,3,0,4,5,0 };

    solution.duplicateZeros(nums);

    printArr(nums);

    return 0;
}