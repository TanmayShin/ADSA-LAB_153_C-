#include <iostream>
#include <vector>
using namespace std;

bool canTransform(const string &s1, const string &s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    dp[0][0] = true;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (!dp[i][j]) continue;
            if (i == n && j == m) return true;

            if (i < n) {
                // If lowercase, can delete it
                if (islower(s1[i])) {
                    dp[i+1][j] = true;
                    // Or capitalize if matches s2[j]
                    if (j < m && toupper(s1[i]) == s2[j]) {
                        dp[i+1][j+1] = true;
                    }
                }
                else {
                    // If uppercase, must match s2[j]
                    if (j < m && s1[i] == s2[j]) {
                        dp[i+1][j+1] = true;
                    }
                }
            }
        }
    }

    return dp[n][m];
}

int main() {
    string s1, s2;
    cout << "Enter string s1 (uppercase + lowercase): ";
    cin >> s1;
    cout << "Enter string s2 (uppercase): ";
    cin >> s2;

    if (canTransform(s1, s2)) 
        cout << "YES, transformation is possible.\n";
    else
        cout << "NO, transformation not possible.\n";
    
    return 0;
}
