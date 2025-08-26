#include <iostream>
using namespace std;

int maxProfit(int prices[], int n) 
{
    int profit = 0;
    for (int i = 0; i < n - 1; i++) 
    {
        if (prices[i + 1] > prices[i])
        {
            profit += prices[i + 1] - prices[i];
        }
    }
    return profit;
}

int main() 
{
    int n;
    cout << "Enter the number of days: ";
    cin >> n;
    
    int* prices = new int[n];  

    cout << "Enter the prices for " << n << " days:\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> prices[i];
    }

    int result = maxProfit(prices, n);
    cout << "Maximum Profit: " << result << endl;

    delete[] prices;  
    return 0;
}
