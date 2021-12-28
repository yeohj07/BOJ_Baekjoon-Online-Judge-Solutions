#include<stdio.h>

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int x[], int y[], int left, int right) {
    int pivot = y[left], pivot_adr = left, low = left+1, high = right, temp;
    while(low <= high) {
        while(low <= right && (pivot > y[low] || (pivot == y[low] && x[pivot_adr] > x[low]))) low++;
        while(high >= (left+1) && (pivot < y[high] || (pivot == y[high] && x[pivot_adr] < x[high]))) high--;
        if(low <= high) swap(x, low, high), swap(y, low, high);
    }
    swap(x, left, high);
    swap(y, left, high);
    return high;
}

void quickSort(int x[], int y[], int left, int right) {
    if(left <= right) {
        int pivot = partition(x, y, left, right);
        quickSort(x, y, left, pivot-1);
        quickSort(x, y, pivot+1, right);
    }
}

int main() {
    int x[100005], y[100005], n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);
    quickSort(x, y, 0, n-1);
    for(int i=0; i<n; i++) printf("%d %d\n", x[i], y[i]);
}
