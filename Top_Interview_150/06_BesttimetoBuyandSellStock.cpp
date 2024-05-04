/**
 * 121.Best time to Buy and Sell Stock
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=study-plan-v2&envId=top-interview-150
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

        int min_price = prices[0];
        
        for(int i = 0; i < prices.size(); i++) {
            if (prices[i] < min_price) {
                min_price = prices[i];
                continue;
            }

            int temp = prices[i] - min_price;
            if(temp > result) {
                result = temp;
            }
        }

        return result;
    }
};



int main(int argc, char** argv) {
    Solution solution;

    vector<int> nums = {5,12,1,4,5,6};

    int result = solution.maxProfit(nums);
    cout << result << endl;
    
    return 0;
}
