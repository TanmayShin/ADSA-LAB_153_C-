#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(vector<int>& set, int sum)
{
    int n = set.size();
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++) 
        {
            if (set[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j - set[i-1]];
        }
    }
    return dp[n][sum];
}

int main() 
{
    int n, sum;
    cout << "Enter number of elements in the set: ";
    cin >> n;
    vector<int> set(n);

    cout << "Enter elements of the set: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> set[i];
    }

    cout << "Enter the sum to find: ";
    cin >> sum;

    if (isSubsetSum(set, sum))
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";

    return 0;
}
