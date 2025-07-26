#include <iostream>
using namespace std;

int countZeros(int arr[], int size)
{
    int low = 0;
    int high = size - 1;
    int fZI = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == 0) {
            fZI = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (fZI == -1) {
        cout << "No Zero is Found INVAID INPUT" << endl;
        return 0;
    }

    return size - fZI;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];  

    cout << "Enter " << size << " elements (all 1s followed by 0s):" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int zeroCount = countZeros(arr, size);

    cout << "Number of 0s = " << zeroCount << endl;

    return 0;
}
