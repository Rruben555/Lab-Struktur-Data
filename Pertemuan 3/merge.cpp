#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {// vector<int>& arr agar dapat mengubah isi arr secara langsung
   
    int n1 = mid - left + 1;//jumlah data di kiri
    int n2 = right - mid;//jumlah data di kanan

    vector<int> L(n1), R(n2);//vector kiri dan kanan

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];//menerima data dari arr untuk bagian kiri
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];//menerima data dari arr untuk bagian kanan


    //inisiasi int untuk sorting
    int i = 0;//bagian kiri 
    int j = 0;//bagian kanan
    int k = left;//untuk array gabungan


    while (i < n1 && j < n2) { //membandingkan bagian kiri dan kanan, yang lebih kecil dimasukkan di arr
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++; //jika bagian kiri yang dimasukkan, index bagian kiri +1, jika tidak, tetap
        } else {
            arr[k] = R[j];
            j++; //jika bagian kanan yang dimasukkan, index bagian kanan +1, jika tidak, tetap
        }
        k++;
    }

    //memasukkan data tersisa ke arr
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


// Fungsi utama merge sort
void mergeSort(vector<int>& arr, int left, int right) {
   
    if (left >= right)//jika cuma 1 data
        return;

    int mid = left + (right - left) / 2; //locate index tengah

    mergeSort(arr, left, mid); //rekursif untuk sort bagian kiri
    mergeSort(arr, mid + 1, right); //rekursif untuk sort bagian kanan
   
    merge(arr, left, mid, right); //merge kiri, kanan, dan mid
}


void printArray(const vector<int>& arr) {//display arr dengan for
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;
   
    vector<int> data(n);
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
   
    cout << "Array sebelum diurutkan: ";
    printArray(data);//display
   
    mergeSort(data, 0, n - 1);//memanggil function mergeSort
   
    cout << "Array setelah diurutkan: ";
    printArray(data);//display
   
    return 0;
}