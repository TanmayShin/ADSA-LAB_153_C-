#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    vector<string> res;

    void backtrack(const string &num, int target, int pos, long long prev_operand, long long current_value, string expr) {
        if (pos == num.size())
         {
            if (current_value == target) {
                res.push_back(expr);
            }
            return;
        }

        for (int i = pos; i < num.size(); ++i) {
            // Skip numbers with leading zero (except for 0 itself)
            if (i > pos && num[pos] == '0') break;

            string curr_str = num.substr(pos, i - pos + 1);
            long long curr_operand = stoll(curr_str);

            if (pos == 0) {
                // First operand, no operator added
                backtrack(num, target, i + 1, curr_operand, curr_operand, curr_str);
            } else {
                // '+' operator
                backtrack(num, target, i + 1, curr_operand, current_value + curr_operand, expr + "+" + curr_str);

                // '-' operator
                backtrack(num, target, i + 1, -curr_operand, current_value - curr_operand, expr + "-" + curr_str);

                // '*' operator: adjust by removing previous operand and adding multiplied operand
                backtrack(num, target, i + 1, prev_operand * curr_operand,
                          current_value - prev_operand + (prev_operand * curr_operand),
                          expr + "*" + curr_str);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        res.clear();
        backtrack(num, target, 0, 0, 0, "");
        return res;
    }
};

int main() {
    string num;
    int target;
    cout << "Enter the number string: ";
    cin >> num;
    cout << "Enter the target value: ";
    cin >> target;

    Solution sol;
    vector<string> ans = sol.addOperators(num, target);

    cout << "[";
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << "\"" << ans[i] << "\"";
        if (i + 1 < ans.size()) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
