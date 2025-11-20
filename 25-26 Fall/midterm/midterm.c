#include <stdio.h>

void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);
int binarySearch(int arr[], int size, int target);

// Merge Sort -> O(nlogn)
void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++) L[i] = arr[left + i];
    for(int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        if(L[i] < R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Binary Search -> O(logn)
int binarySearch(int arr[], int size, int target){
    int left = 0, right = size - 1;
    while(left <= right){
        int mid = (left + right) / 2;

        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(){
    int suspicious_ips[] = {992, 15, 4021, 77, 15, 2500, 903, 4};
    int previous_suspicious_ip = 15;
    int size = sizeof(suspicious_ips) / sizeof(suspicious_ips[0]);

    mergeSort(suspicious_ips, 0, size - 1);

    int result = binarySearch(suspicious_ips, size, previous_suspicious_ip);

    if(result != -1){
        printf("IP %d bugun supheli listesinde mevcut.\n", previous_suspicious_ip);

        int count = 0;
        for(int i = 0; i < size; i++)
            if(suspicious_ips[i] == previous_suspicious_ip) count++;

        printf("IP %d bugun %d kez kaydedilmistir.\n", previous_suspicious_ip, count);

        if(count > 2)
            printf("Supheli IP tekrar tespit edildi: BANLANDI\n");
    } else {
        printf("Bu IP bugun supheli listesinde mevcut degil.\n");
    }

    return 0;
}