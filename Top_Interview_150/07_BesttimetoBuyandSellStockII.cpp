/**
 * 121.Best time to Buy and Sell Stock II
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan-v2&envId=top-interview-150
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
    int maxProfit(vector<int>& prices) {
        int result = 0;

        int min_value = prices[0];
        int subtotal = 0;
        int temp;
        for(int i = 1; i < prices.size(); i++) {
            if (prices[i] < min_value) {
                min_value = prices[i];
            }
            
            temp = prices[i] - min_value;
            if (temp > subtotal) {
                subtotal = temp;
                
                if(i == prices.size() - 1) {
                    result += subtotal;
                    subtotal = 0;
                    temp = 0;
                    min_value = prices[i];
                }
            } else {
                result += subtotal;
                subtotal = 0;
                temp = 0;
                min_value = prices[i];
            }
        }

        return result;
    }
};



int main(int argc, char** argv) {
    Solution solution;

    vector<int> nums;
    int result;
    nums = {7,1,5,3,6,4};
    result = solution.maxProfit(nums);
    cout << "result 1 = " << result << endl;
    
    nums = {1,2,3,4,5};
    result = solution.maxProfit(nums);
    cout << "result 2 = " << result << endl;
    
    nums = {7,6,4,3,1};
    result = solution.maxProfit(nums);
    cout << "result 3 = " << result << endl;
    
    nums = {2,4,1};
    result = solution.maxProfit(nums);
    cout << "result 2 = " << result << endl;

    
    return 0;
}
