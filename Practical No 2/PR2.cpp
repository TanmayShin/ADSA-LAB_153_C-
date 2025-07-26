#include <iostream>
using namespace std;


void merge(int a[], int s, int m, int e) 
{
    int len1 = m - s + 1, len2 = e - m;
    int* left = new int[len1];
    int* right = new int[len2];

    for (int i = 0; i < len1; i++) left[i] = a[s + i];
    for (int i = 0; i < len2; i++) right[i] = a[m + 1 + i];

    int i = 0, j = 0, k = s;
    while (i < len1 && j < len2) 
    {
        if (left[i] >= right[j]) a[k++] = left[i++];
        else a[k++] = right[j++];
    }

    while (i < len1) a[k++] = left[i++];
    while (j < len2) a[k++] = right[j++];

    
}


void mergeSort(int a[], int s, int e) 
{
    if (s < e) 
    {
        int m = s + (e - s) / 2;
        mergeSort(a, s, m);
        mergeSort(a, m + 1, e);
        merge(a, s, m, e);
    }
}

int main() 
{
    int a[100], n, i;

    cout << "Enter size: ";
    cin >> n;
    if (n < 1 || n > 100) {
        cout << "Invalid size!" << endl;
        return 1;
    }

    cout << "Enter " << n << " numbers: ";
    for (i = 0; i < n; i++) cin >> a[i];

    
    mergeSort(a, 0, n - 1);

    
    cout << "Result: ";
    for (i = 0; i < n; i++) cout << a[i] << ' ';
    cout << endl;

    return 0;
}
