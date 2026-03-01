#include <iostream>
using namespace std;
int main() {

// cout << "Hello, World!" << endl;
// cout << "Belajar C++ sangat seru";

// string nama = "kei";
// int umur = 20;
// cout << "Halo, nama saya " << nama << " dan umur saya " << umur <<
// "tahun";

    int apel, melon;
    
    cout << "=== Program Perbandingan Buah ===" << endl;
    cout << "Masukkan jumlah Apel: ";
    cin >> apel;
    cout << "Masukkan jumlah Melon: ";
    cin >> melon;

    cout << "\n--- Hasil Operator Perbandingan ---" << endl;
    cout << boolalpha;
    
    cout << "Apakah jumlah Apel == Melon? : " << (apel == melon) << endl;
    cout << "Apakah jumlah Apel != Melon? : " << (apel != melon) << endl;
    cout << "Apakah jumlah Apel > Melon? : " << (apel > melon) << endl;
    cout << "Apakah jumlah Apel < Melon? : " << (apel < melon) << endl;
    cout << "Apakah jumlah Apel >= Melon? : " << (apel >= melon) << endl;
    cout << "Apakah jumlah Apel <= Melon? : " << (apel <= melon) << endl;
    
    cout << "\n--- Keputusan Belanja ---" << endl;
    if (apel > melon) {
        cout << "Stok Apel lebih banyak, kita jual Apel aja." << endl;
    } else if (melon > apel) {
        cout << "Stok Melon lebih banyak, kita jual Melon aja." << endl;
    } else {
        cout << "Stok sama banyak, kita jual aja semua" << endl;
    }


    // bool malas = true;
    // bool mengantuk = true;
    // if (malas) {
    //     if (mengantuk) {
    //         cout << "Saya tidur";
    //     }
    // } else {
    //     cout << "Gak ngapa-ngapain";
    // }


// entry control loop
    // for (int i = 0; i < 5; i++) {
    // cout << i << endl;
    // }


// exit control loop
    // int i = 0;
    // do {
    //     cout << i << endl;
    //     i++;
    // } while (i < 5);


return 0;
}