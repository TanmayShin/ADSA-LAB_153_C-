#include <iostream>
using namespace std;

int main()
{
    int nums[] = {4, 5, 6, 7, 0, 1, 2};  
    int target = 5;
    int low = 0;
    int high = sizeof(nums) / sizeof(nums[0]) - 1;
    int mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            cout << "Target found at index: " << mid << endl;
            return 0;
        }

        // Left half is sorted
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        else
        {
            if (nums[mid] < target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    cout << "Target not found." << endl;
    return -1;
}
