/**
 * 42. Trapping Rain Water

 * https://leetcode.com/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

void printArr(vector<int>& nums, const string title)
{
    cout << "=============== " << title << " ===============\n";
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
    int trap(vector<int>& height) {
        if (height.size() < 3) {
            return 0;
        }

        size_t top_peak_index = 0;
        size_t left_peak_index = 0;
        size_t right_peak_index = height.size() - 1;

        int answer = 0;
        int subtotal = 0;

        for (size_t i = 1; i < height.size(); i++) {
            if (height[i] > height[top_peak_index]) {
                top_peak_index = i;
            }
        }

        for (size_t i = 1; i <= top_peak_index; i++) {
            if (height[i] >= height[left_peak_index]) {
                left_peak_index = i;
                answer += subtotal;
                subtotal = 0;
            }
            else {
                subtotal += (height[left_peak_index] - height[i]);
            }
        }

        subtotal = 0;
        for (size_t i = right_peak_index - 1; i >= top_peak_index; i--) {
            if (height[i] >= height[right_peak_index]) {
                right_peak_index = i;
                answer += subtotal;
                subtotal = 0;
            }
            else {
                subtotal += (height[right_peak_index] - height[i]);
            }

            if (i == 0) {
                break;
            }
        }

        return answer;
    }
};



int main(int argc, char** argv) {
    Solution solution;

    vector<int> nums;

    nums = { 2,0,2 };

    int result;
    result = solution.trap(nums);
    cout << "result = " << result << endl;

    return 0;
}