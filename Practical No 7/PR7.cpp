#include <bits/stdc++.h>
using namespace std;


bool canFinish(const vector<int>& tasks, int D, int dailyLimit) 
{
    int days = 1, current = 0;
    for (int task : tasks) {
        if (task > dailyLimit) return false; 
        if (current + task <= dailyLimit)
            current += task;
        else {
            days++;
            current = task;
        }
    }
    return days <= D;
}

int minDailyWork(const vector<int>& tasks, int D) 
{
    int left = *max_element(tasks.begin(), tasks.end());
    int right = accumulate(tasks.begin(), tasks.end(), 0);

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canFinish(tasks, D, mid))
            right = mid;
        else
            left = mid + 1;

    }
    return left;
}

int main() 
{
    int n, D;
    cout << "Enter number of tasks: ";
    cin >> n;

    vector<int> tasks(n);
    cout << "Enter task workloads: ";
    for (int i = 0; i < n; i++) cin >> tasks[i];

    cout << "Enter number of days: ";
    cin >> D;

    int result = minDailyWork(tasks, D);
    cout << "Minimum work per day: " << result << endl;

    return 0;
}
