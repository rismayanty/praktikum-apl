#include <iostream>
using namespace std;

 int main() {


    // login system
    string nama, password; 
    string namaWajib = "Rismayanty";
    string nim = "102";
    int percobaan = 0;
    bool loginBerhasil = false;

    cout << "!=============================!" << endl;
    cout << "       SELAMAT DATANG DI       " << endl;
    cout << "        KONVERSI WAKTU         " << endl;
    cout << "!=============================!" << endl;
 
    while (percobaan < 3) {
        cout << "\n--- LOGIN USER ---" << endl;
        cout << "Nama: ";
        getline(cin, nama);
        
        cout << "Password: ";
        getline(cin, password);

        bool namaBenar = (nama == namaWajib);
        bool passwordBenar = (password == nim);

        if (namaBenar && passwordBenar) {
            loginBerhasil = true;
            break;
        } else {
            percobaan++;
            cout << "\n[!] LOGIN GAGAL" << endl;
            
            if (!namaBenar) {
                cout << "    -> Nama wajib \"Rismayanty\"!" << endl;
            }
            if (!passwordBenar) {
                cout << "    -> Password salah!" << endl;
            }
            cout << "    -> Sisa percobaan: " << (3 - percobaan) << endl;
        }
    }

    if (!loginBerhasil) {
        cout << "\n[!] AKSES DITOLAK! gagal login 3 kali." << endl;
        return 0;
    }


    // menu utama
    int pilihan;
    int waktuInput;
    
    do {
        cout << endl;
        cout << "=======================================" << endl;
        cout << "           MENU KONVERSI WAKTU         " << endl;
        cout << "=======================================" << endl;
        cout << "1. Konversi Jam   -> Menit dan Detik   " << endl;
        cout << "2. Konversi Menit -> Jam dan Detik     " << endl;
        cout << "3. Konversi Detik -> Jam dan Menit     " << endl;
        cout << "4. Keluar                              " << endl;
        cout << "=======================================" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        if (pilihan < 1 || pilihan > 4) {
            cout << "[!] PILIHAN TIDAK VALID! Masukkan 1-4." << endl;
            continue;
        }

        // konversi
        switch (pilihan) {
            case 1:
                cout << "\n--- KONVERSI JAM ---" << endl;
                cout << "Masukkan jumlah jam: ";
                cin >> waktuInput;
                cout << "Hasil: " << waktuInput << " Jam = " 
                     << (waktuInput * 60) << " Menit dan " 
                     << (waktuInput * 3600) << " Detik" << endl;
                break;

            case 2:
                cout << "\n--- KONVERSI MENIT ---" << endl;
                cout << "Masukkan jumlah menit: ";
                cin >> waktuInput;
                cout << "Hasil: " << waktuInput << " Menit = " 
                     << (waktuInput / 60) << " Jam dan " 
                     << (waktuInput * 60) << " Detik" << endl;
                break;

            case 3:
                cout << "\n--- KONVERSI DETIK ---" << endl;
                cout << "Masukkan jumlah detik: ";
                cin >> waktuInput;
                cout << "Hasil: " << waktuInput << " Detik = " 
                     << (waktuInput / 3600) << " Jam dan " 
                     << ((waktuInput % 3600) / 60) << " Menit" << endl;
                break;

            case 4:
                cout << "\n=======================================" << endl;
                cout << "   TERIMA KASIH, " << nama << "! SEE YOU...   " << endl;
                cout << "=======================================" << endl;
                break;
        }

    } while (pilihan != 4);

    return 0;
}