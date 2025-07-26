#include <iostream>
using namespace std;


int countzero(int m) 
{
    int zeros = 0;
    for (int i = 5; i <= m; i *= 5)
        zeros += m / i;
    return zeros;
}


int snwz(int n) 
{
    if (n < 0) return 0;
    int low = 0, high = 5 * n;
    int answer = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int zeros = countzero(mid);
        if (zeros >= n) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

int main() 
{
    int n;
    cout << "Enter the Number with Trailing Zeros: ";
    cin >> n;

    int m = snwz(n);

    
    if (countzero(m) == n) {
        cout << "The Smallest Number Whose Factorial has Least " << n;
        cout << " Trailing Zeros is: " << m << endl;
    } else {
        cout << "No factorial exists with exactly " << n << " trailing zeros." << endl;
    }

    return 0;
}
