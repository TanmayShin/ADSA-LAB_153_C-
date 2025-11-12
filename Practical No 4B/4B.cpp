#include <iostream>
using namespace std;

int search_rotated(const int nums[], int n, int target) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
            return mid;
        if(nums[left] <= nums[mid]) { // Left half is sorted
            if(nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        } else { // Right half is sorted
            if(nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1; // Not found
}

int main() {
    int nums[] = {4,5,6,7,0,1,2,3};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 0;
    int idx = search_rotated(nums, n, target);
    if (idx != -1)
        cout << "[" << idx << "]" << endl;
    else
        cout << "[-1]" << endl;
    return 0;
}
