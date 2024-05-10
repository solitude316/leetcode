/**
 * 12. Integer to Roman
 * https://leetcode.com/problems/integer-to-roman/description/?envType=study-plan-v2&envId=top-interview-150
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
    string intToRoman(int num) {
        vector<int> digits(4, 0);

        digits[3] = num / 1000;
        digits[2] = (num % 1000) / 100;
        digits[1] = (num % 100) / 10;
        digits[0] = num % 10;

        string answer = "";
        string substr = "";

        for (int i = 0; i < digits[3]; i++) {
            answer += "M";
        }

        if (digits[2] == 9) {
            answer += "CM";
        }
        else if (digits[2] >= 5) {
            answer += "D";
            int diti = digits[2] - 5;
            for (int i = 0; i < diti; i++) {
                answer += "C";
            }
        }
        else if (digits[2] == 4) {
            answer += "CD";
        }
        else {
            for (int i = 0; i < digits[2]; i++) {
                answer += "C";
            }
        }

        if (digits[1] == 9) {
            answer += "XC";
        }
        else if (digits[1] >= 5) {
            answer += "L";
            int diti = digits[1] - 5;
            for (int i = 0; i < diti; i++) {
                answer += "X";
            }
        }
        else if (digits[1] == 4) {
            answer += "XL";
        }
        else {
            for (int i = 0; i < digits[1]; i++) {
                answer += "X";
            }
        }

        if (digits[0] == 9) {
            answer += "IX";
        }
        else if (digits[0] >= 5) {
            answer += "V";
            int diti = digits[0] - 5;
            for (int i = 0; i < diti; i++) {
                answer += "I";
            }
        }
        else if (digits[0] == 4) {
            answer += "IV";
        }
        else {
            for (int i = 0; i < digits[0]; i++) {
                answer += "I";
            }
        }

        return answer;
    } 
};



int main(int argc, char** argv) {
    Solution solution;

    int s;

    s = 1994;
    cout << s << " = " << solution.intToRoman(s) << endl;

    s = 3999;
    cout << s << " = " << solution.intToRoman(s) << endl;

    s = 58;
    cout << s << " = " << solution.intToRoman(s) << endl;

    s = 3749;
    cout << s << " = " << solution.intToRoman(s) << endl;

    return 0;
}