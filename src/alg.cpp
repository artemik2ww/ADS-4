// Copyright 2021 NNTU-CS
#include "alg.h"

static int lowerBoundInt(int* arr, int len, int x) {
    int l = 0, r = len;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m] < x) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    return l;
}

static int upperBoundInt(int* arr, int len, int x) {
    int l = 0, r = len;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m] <= x) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    return l;
}

int countPairs1(int* arr, int len, int value) {
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

int countPairs2(int* arr, int len, int value) {
    int l = 0;
    int r = len - 1;
    int k = 0;

    while (l < r) {
        int sum = arr[l] + arr[r];

        if (sum < value) {
            l++;
        }
        else if (sum > value) {
            r--;
        }
        else {
            if (arr[l] == arr[r]) {
                int n = r - l + 1;
                k += n * (n - 1) / 2;
                break;
            }

            int leftValue = arr[l];
            int rightValue = arr[r];

            int lCount = 0;
            int rCount = 0;

            while (l <= r && arr[l] == leftValue) {
                l++;
                lCount++;
            }

            while (r >= l && arr[r] == rightValue) {
                r--;
                rCount++;
            }

            k += lCount * rCount;
        }
    }

    return k;
}

int countPairs3(int* arr, int len, int value) {
    int k = 0;
    int i = 0;

    while (i < len) {
        int cur = arr[i];
        int curS = i;

        while (i < len && arr[i] == cur) {
            i++;
        }

        int curk = i - curS;
        int need = value - cur;

        if (need < cur) {
            continue;
        }

        int lb = lowerBoundInt(arr, len, need);
        int ub = upperBoundInt(arr, len, need);
        int needk = ub - lb;

        if (needk == 0) {
            continue;
        }

        if (need == cur) {
            k += curk * (curk - 1) / 2;
        }
        else {
            k += curk * needk;
        }
    }

    return k;
}
