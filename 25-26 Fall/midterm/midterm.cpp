#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right);
void mergeSort(vector<int>& arr, int left, int right);
int binarySearch(const vector<int>& arr, int target);

// Merge Sort -> O(nlogn)
void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

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

void mergeSort(vector<int>& arr, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Binary Search -> O(logn)
int binarySearch(const vector<int>& arr, int target){
    int left = 0, right = arr.size() - 1;

    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(){
    vector<int> suspicious_ips = {992, 15, 4021, 77, 15, 2500, 903, 4};
    int previous_suspicious_ip = 15;

    mergeSort(suspicious_ips, 0, suspicious_ips.size() - 1);

    int result = binarySearch(suspicious_ips, previous_suspicious_ip);

    if(result != -1){
        cout << "IP " << previous_suspicious_ip << " bugun supheli listesinde mevcut.\n";

        int count = 0;
        for(int x : suspicious_ips)
            if(x == previous_suspicious_ip) count++;

        cout << "IP " << previous_suspicious_ip << " bugun " << count << " kez kaydedilmistir.\n";

        if(count > 2)
            cout << "Supheli IP tekrar tespit edildi: BANLANDI\n";
    } else {
        cout << "Bu IP bugun supheli listesinde mevcut degil.\n";
    }

    return 0;
}