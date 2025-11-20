import java.util.Arrays;

public class Main {

    // Merge Sort -> O(nlogn)
    static void merge(int arr[], int left, int mid, int right){
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int[] L = new int[n1];
        int[] R = new int[n2];

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

    static void mergeSort(int arr[], int left, int right){
        if(left < right){
            int mid = (left + right) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    // Binary Search -> O(logn)
    static int binarySearch(int arr[], int target){
        int left = 0, right = arr.length - 1;

        while(left <= right){
            int mid = (left + right) / 2;

            if(arr[mid] == target) return mid;
            else if(arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }

    public static void main(String[] args) {

        int[] suspicious_ips = {992, 15, 4021, 77, 15, 2500, 903, 4};
        int previous_suspicious_ip = 15;

        mergeSort(suspicious_ips, 0, suspicious_ips.length - 1);

        int result = binarySearch(suspicious_ips, previous_suspicious_ip);

        if(result != -1){
            System.out.println("IP " + previous_suspicious_ip + " bugun supheli listesinde mevcut.");

            int count = 0;
            for(int x : suspicious_ips)
                if(x == previous_suspicious_ip) count++;

            System.out.println("IP " + previous_suspicious_ip + " bugun " + count + " kez kaydedilmistir.");

            if(count > 2)
                System.out.println("Supheli IP tekrar tespit edildi: BANLANDI");
        } else {
            System.out.println("Bu IP bugun supheli listesinde mevcut degil.");
        }
    }
}