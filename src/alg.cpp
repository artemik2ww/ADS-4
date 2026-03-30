// Copyright 2021 NNTU-CS
#include <cstddef>

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        
        if (sum == value) {
            int left_val = arr[left];
            int right_val = arr[right];
            
            if (left_val == right_val) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }
            int left_count = 0;
            int temp_left = left;
            while (temp_left <= right && arr[temp_left] == left_val) {
                left_count++;
                temp_left++;
            }
            
            int right_count = 0;
            int temp_right = right;
            while (temp_right >= left && arr[temp_right] == right_val) {
                right_count++;
                temp_right--;
            }
            
            count += left_count * right_count;
            left = temp_left;
            right = temp_right;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    
    return count;
}

int binarySearch(int *arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    
    for (int i = 0; i < len - 1; i++) {
        int target = value - arr[i];
        
        int found_index = binarySearch(arr, i + 1, len - 1, target);
        
        if (found_index != -1) {
            int j = found_index;
            int left_count = 0;
            int temp = j;
            while (temp >= i + 1 && arr[temp] == target) {
                left_count++;
                temp--;
            }
            
            int right_count = 0;
            temp = j + 1;
            while (temp < len && arr[temp] == target) {
                right_count++;
                temp++;
            }
            count += left_count + right_count;
            int current_val = arr[i];
            while (i + 1 < len && arr[i + 1] == current_val) {
                i++;
            }
        }
    }
    return count;
}
