#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

// Question One (1) - Remove Duplicates from Sorted Array
int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int i = 0;
    for (int j = 1; j < nums.size(); ++j) {
        if (nums[j] != nums[i]) {
            ++i;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}

// Question Two (2) - Rotate Array
void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;  // In case k is greater than the array length

    // Reverse the whole array
    std::reverse(nums.begin(), nums.end());

    // Reverse the first k elements
    std::reverse(nums.begin(), nums.begin() + k);

    // Reverse the remaining elements
    std::reverse(nums.begin() + k, nums.end());
}

// Question Three (3) - Contains Duplicate
bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> seen;

    for (int num : nums) {
        if (seen.count(num) > 0) {
            return true;
        }
        seen.insert(num);
    }

    return false;
}

// Question Four (4) - Single Number
int singleNumber(std::vector<int>& nums) {
    int result = 0;

    for (int num : nums) {
        result ^= num;
    }

    return result;
}

int main() {
    // Example usage
    std::vector<int> nums1 = {1, 1, 2, 2, 3, 4, 4, 5};
    int len = removeDuplicates(nums1);
    std::cout << "Length after removing duplicates: " << len << std::endl;

    std::vector<int> nums2 = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums2, 3);
    std::cout << "Rotated array: ";
    for (int num : nums2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums3 = {1, 2, 3, 4, 5, 1};
    bool hasDuplicate = containsDuplicate(nums3);
    std::cout << "Contains duplicate: " << std::boolalpha << hasDuplicate << std::endl;

    std::vector<int> nums4 = {4, 2, 3, 2, 3};
    int singleNum = singleNumber(nums4);
    std::cout << "Single number: " << singleNum << std::endl;

    return 0;
}


