// - Bir dizi oluşturun,
// - Dizinin eleman sayısı 1000 olarak tanımlayın,
// - Bu diziye rastgele 1-10.000 arasında değer ataması yapın,
// - Bu diziyi üç farklı sıralama algoritması ile sıralayın,
// - Sıralama yapan bu algoritmaların çalışma sürelerini saniye cinsinden yazdırın,
// - Üç farklı algoritmanın çalışma süresini ekrana yazdırın,
// - Bu farkı tartışın.

// .c uzantılı dosyanızı assignment-2'ye vaktinde pushlayın.
// tartışmanızı .c uzantılı dosyanızın en altına (main() fonksiyonunun altına yorum satırı olarak yazabilirsiniz.)
// Bubble Sort kullanılmayacaktır!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

// prototipler
int randomNumberGenerator();
int insertArr(int arr[]);
int insertionSort(int arr[]);
int mergeSort(int arr[], int left, int right);
int merge(int arr[], int left, int mid, int right);
int quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void findTime(int arr[]);

int randomNumberGenerator(){
    return rand() % 10000 + 1; // 1-10000 arasında rastgele sayı üretir
}

int insertArr(int arr[]){
    for(int i = 0; i < SIZE; i++){
        arr[i] = randomNumberGenerator();
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertionSort(int arr[]){
    for(int i = 1; i < SIZE; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    for(int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

int quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void findTime(int arr[]) {
    clock_t start, end;
    double time_used;

    int temp[SIZE];

    // 🔹 Insertion Sort
    for (int i = 0; i < SIZE; i++) temp[i] = arr[i]; // diziyi kopyala
    start = clock();
    insertionSort(temp);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort süresi: %f saniye\n", time_used);

    // 🔹 Merge Sort
    for (int i = 0; i < SIZE; i++) temp[i] = arr[i];
    start = clock();
    mergeSort(temp, 0, SIZE - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort süresi: %f saniye\n", time_used);

    // 🔹 Quick Sort
    for (int i = 0; i < SIZE; i++) temp[i] = arr[i];
    start = clock();
    quickSort(temp, 0, SIZE - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort süresi: %f saniye\n", time_used);
}


int main(){
    srand(time(NULL));

    int array[SIZE];
    insertArr(array);
    findTime(array);

    return 0;
}

/*
Bu ödevde Insertion Sort, Merge Sort ve Quick Sort algoritmalarının
çalışma süreleri karşılaştırılmıştır.

Sonuçlar incelendiğinde:
- Insertion Sort'un çalışma süresi diğerlerine göre çok daha uzundur.
  Çünkü Insertion Sort, her eleman için dizinin geri kalan kısmını
  kontrol eder ve ortalama durumda O(n²) karmaşıklığa sahiptir.
- Merge Sort, her durumda O(n log n) karmaşıklıkta çalıştığı için
  Insertion Sort’tan çok daha hızlıdır.
  Ancak ek bellek (geçici diziler) kullanır.
- Quick Sort genellikle en hızlısıdır. Ortalama durumda O(n log n)
  karmaşıklığa sahiptir ve belleği verimli kullanır.
  Pivot seçimi uygun yapıldığında Merge Sort’tan da daha iyi performans gösterir.

Bu sonuçlara göre:
- Küçük dizilerde Insertion Sort basitliği nedeniyle tercih edilebilir.
- Büyük veri kümelerinde Merge Sort ve Quick Sort çok daha etkilidir.
- Rastgele 1000 elemanlı dizi üzerinde yapılan ölçümde de
  Quick Sort en hızlı, Insertion Sort en yavaş algoritma olmuştur.

Kısaca, gözlenen farklar algoritmaların teorik karmaşıklıklarıyla
uyumlu şekilde gerçekleşmiştir.
*/