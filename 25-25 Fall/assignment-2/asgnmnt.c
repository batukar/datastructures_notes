// Ad: Mehmet Ali
// Soyad: Dönmez
// Okul No: 232503026
// Sınıf: 3. Sınıf 
// Öğrenim Türü (Örgün/İkinci Öğretim): Örgün Öğretim
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
// Hizli Siralama (Quick Sorting)
// dusuk = dizinin baslangic indexi, yuksek = dizinin dizinin bitis indexi
// index1, index2 kendi arasinda degistirilecek (takaslanacak) degerler

// Quick Sort
void quickSort(int dizi[], int dusuk, int yuksek);
void eleman_swap(int *index1, int *index2);
int dizi_bolme(int dizi[], int dusuk, int yuksek);


// Merge Sort
void mergeSort(int dizi[], int sol, int sag);
void birlesim(int dizi[], int sol, int orta, int sag);





int main(){
   // printf("Merak etme, ödevler gayet basit.\nKendine güven ve bunu tamamla!\n");

    int dizi[1000];
    int dizi2[1000];
    int dizi3[1000];

    srand(time(NULL)); // ayni sayilarin gelmesini onler
    // Diziye 1 - 10.000 arasi random sayilar ata.
    for(int a = 0; a < 1000; a++){
        dizi[a] = rand() % 10000 + 1;
    }
    for(int a = 0; a < 1000; a++){
        dizi2[a] = rand() % 10000 + 1;
    }
    for(int a = 0; a < 1000; a++){
        dizi3[a] = rand() % 10000 + 1;
    }
    // Diziyi ekrana yazdir
    printf("1000 Elemanli dizi: \n\n");
    for(int a=0; a < 1000; a++){
        printf("%d, ", dizi[a]);
    }
    
    /*
    Hocam sizin ipucu olarak verdiginiz clock() fonksiyonunu kullandigimda islem cok hizli gerceklestigi gerekcesiyle surekli
    calisma suresini 0 saniye olarak veriyordu. Bende biraz arastirip bu yontemi buldum. Bu sure hesaplama yontemiyle yaklasik
    bir sonuc aldim. Odevde istediginiz karsilastirmayi yapabilmek icin sure hesaplama yontemini bu sekilde yaziyorum.
        
    Umarim kabul edersiniz 
    */
    LARGE_INTEGER start, end, freq;

    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    quickSort(dizi, 0, 999);

    QueryPerformanceCounter(&end);

    double qS_time = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart; // quick sort hizi
 
    printf("\n\nHizli Siralama algoritmasi ile siralanmis dizi: \n\n");
    for(int a = 0; a < 1000; a++){
        printf("%d, ", dizi[a]);
    }
    printf("\n\nAlgoritma calisma hizi: %.8f saniye", qS_time);



    
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    mergeSort(dizi2, 0, 999);

    QueryPerformanceCounter(&end);

    double mS_time = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;

    printf("\n\n\n Birlestirme Algoritmasi ile siralanmis dizi: \n\n");
    for(int a=0; a < 1000; a++){
        printf("%d, ", dizi[a]);
    }
    printf("\n\nBirlestirme Algoritamsi calisma hizi: %.8f saniye", mS_time);

    return 0;
}

// --------------------------------------- HIZLI SIRALAMA ALGORITMASI ---------------------------------------------
// Algoritma fonksiuyonu
void quickSort(int dizi[], int dusuk, int yuksek){
 
    if(dusuk < yuksek){
        int pivot = dizi_bolme(dizi, dusuk, yuksek);

        // Pivot degerinin sol tarafindaki kisim
        quickSort(dizi, dusuk, pivot -1);
        // Pivot degerinin sag tarafindaki kisim
        quickSort(dizi, pivot + 1, yuksek);

    }
}

// Dizi Eleman Takas fonksiyonu
void eleman_swap(int *index1, int *index2){

    // tmp (Gecici) integer sayesinde index1 ve index2 degerlerini kendi aralarinda takasliyorum

    int tmp;
    tmp = *index1;
    *index1 = *index2;
    *index2 = tmp;
}

// Diziyi sectigimiz pivot elemana gore bolen fonksiyon
int dizi_bolme(int dizi[], int dusuk, int yuksek){

    int pvt = dizi[yuksek]; // Dizinin son elemanini pivot olarak seciyorum.

    // dusuk_index'e -1 degeri vererek henuz bir dizinin elemanini gostermemesini sagliyorum. Takas isleminden once 1 arttiriyorum.
    int dusuk_index = dusuk - 1;

    for(int i = dusuk; i < yuksek; i++){
        if(dizi[i] < pvt){
            dusuk_index++;
            eleman_swap(&dizi[dusuk_index], &dizi[i]); // Eleman pivottan kucuk ise pivotun soluna tasinir.
        }
    }

    // Pivot degerini dogru indexe yerlestirir
    eleman_swap(&dizi[dusuk_index + 1], &dizi[yuksek]);
    // Pivot'un yeni index degerini dondurur
    return dusuk_index + 1;
}
// --------------------------------------- HIZLI SIRALAMA ALGORITMASI ---------------------------------------------

// --------------------------------------- BIRLESTIRME SIRALAMA ALGORIMASI ---------------------------------------------
void mergeSort(int dizi[], int sol, int sag){
    if( sol < sag){
        int orta = sol + ((sag - sol) / 2); // Ortayi hesaplama
        mergeSort(dizi, sol, orta);         // Sol yarim diziyi siralar
        mergeSort(dizi, orta + 1, sag);     // Sag yarim diziyi siralar
        birlesim(dizi, sol, orta, sag);        // Dizileri birlestirir
    }
}

void birlesim(int dizi[], int sol, int orta, int sag){
    int sol_boyut = orta - sol + 1;  // Sol yarim dizinin boyutu
    int sag_boyut = sag - orta;        // Sag yarim dizinin boyutu

    int sol_dizi[sol_boyut];
    int sag_dizi[sag_boyut];

    for(int i=0; i < sol_boyut; i++){
        sol_dizi[i] = dizi[sol+i];  // Sol gecici diziyi doldur
    }
    for(int i=0; i < sag_boyut; i++){
        sag_dizi[i] = dizi[orta + 1 + i]; // Sag gecici diziyi doldur
    }

    /*  Dizi birlestirme islemi. 
        Sol dizinin x. index degeri < Sag dizinin y. index degeri ise sol dizinin elemanini diziye ekle. 
        Degilse sag dizinin elemanini diziye ekle
    */ 

    int x=0, y=0, f=sol;

    while(x < sol_boyut && y < sag_boyut){
        if(sol_dizi[x] <= sag_dizi[y]){
            dizi[f] = sol_dizi[x];
            x++;
        }
        else{
            dizi[f] = sag_dizi[y];
            y++;
        }
        f++;

    }

    while(x < sol_boyut){       // Eger sag dizi sona ulasirsa sol dizide kalan elemanlari ekler
        dizi[f] = sol_dizi[x];
        x++;
        f++;
    }

    while(y < sag_boyut){       // Eger sol dizi sona ulasirsa sag dizide kalan elemanlari ekler
        dizi[f] = sag_dizi[y];
        y++;
        f++;
    }



}
// --------------------------------------- BIRLESTIRME SIRALAMA ALGORIMASI ---------------------------------------------
