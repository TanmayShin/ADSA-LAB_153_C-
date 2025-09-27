#include <iostream>
#include <algorithm>
using namespace std;

struct Shop 
{
    int start, end;
};


bool compareByEndTime(Shop a, Shop b) 
{
    return a.end < b.end;
}

int main() 
{
    int N, K;
    cout << "Enter number of shops (N): ";
    cin >> N;

    cout << "Enter number of persons (K): ";
    cin >> K;

    int S[100], E[100]; 
    cout << "Enter start times:\n";
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    cout << "Enter end times:\n";
    for (int i = 0; i < N; i++) {
        cin >> E[i];
    }

    
    Shop shops[100];
    for (int i = 0; i < N; i++) {
        shops[i].start = S[i];
        shops[i].end = E[i];
    }

   
    sort(shops, shops + N, compareByEndTime);

    
    int available[100]; 
    for (int i = 0; i < K; i++) {
        available[i] = 0;
    }

    int count = 0;

    
    for (int i = 0; i < N; i++) {
        for (int p = 0; p < K; p++) {
            if (available[p] <= shops[i].start) {
                available[p] = shops[i].end; 
                count++;
                break; 
            }
        }
    }

    cout << "Maximum shops visited: " << count << endl;

    return 0;
}
