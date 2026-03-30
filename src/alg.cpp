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
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }
            int left_val = arr[left];
            int left_count = 0;
            while (left <= right && arr[left] == left_val) {
                left_count++;
                left++;
            }
            int right_val = arr[right];
            int right_count = 0;
            while (right >= left && arr[right] == right_val) {
                right_count++;
                right--;
            }
            count += left_count * right_count;
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
    for (int i = 0; i < len; i++) {
        int target = value - arr[i];
        int pos = binarySearch(arr, i + 1, len - 1, target);
        if (pos != -1) {
            int first = pos;
            int last = pos;
            
            while (first > i + 1 && arr[first - 1] == target) {
                first--;
            }
            
            while (last < len - 1 && arr[last + 1] == target) {
                last++;
            }
            count += (last - first + 1);
        }
        while (i + 1 < len && arr[i] == arr[i + 1]) {
            i++;
        }
    }
    return count;
}
