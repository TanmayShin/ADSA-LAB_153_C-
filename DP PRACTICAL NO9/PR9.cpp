#include <iostream>
#include <vector>
using namespace std;

int coinChangeWays(const vector <int> & coins, int sum )  {
    vector <int> ways(sum + 1, 0);
    ways[0] = 1;

    for(int coin : coins ) {
        for(int i = coin; i <= sum; ++i ) {
            ways[i] += ways[i - coin];
        }
    }
    return ways[sum];
 }

 int main()
 {
    int n,sum;
    cout<<" Enter the Number of Coins Denomination: ";
    cin>>n;
    
    vector<int> coins(n);
    cout << "Enter the Coin Denomination: ";

    for(int i = 0; i < n; i++)
    {
        cin>>coins[i];
    }
    
    cout<<" Enter the sum to make: ";
    cin>>sum;

    int result = coinChangeWays(coins,sum);
    cout << " Number of Ways to make sum is "<< sum << " = " << result <<endl;

    return 0;
 }
