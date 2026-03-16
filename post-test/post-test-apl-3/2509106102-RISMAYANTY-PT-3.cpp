#include <iostream>
#include <iomanip>
using namespace std;

struct user {
    string username;
    string password;
    string role;
};

struct infopaket {
    string hari;    
    string jamsesi;
    int bulanMember;
    int harga;
};

struct member {
    int id;
    string nama;
    string username;
    string namapaket;
    infopaket detail;
};

#define MAX_MEMBER 100
#define MAX_user 20
#define PERTEMUAN_PER_BULAN 4

// fungsi rekursif
int hitungpertemuan(int bulan) {
    if (bulan <= 0) {
        return 0;
    }
    return PERTEMUAN_PER_BULAN + hitungpertemuan(bulan - 1);
}

string infohari(string namapaket) {
    if (namapaket == "SUN") {
        return "Senin-Jumat";
    } else if (namapaket == "MOON") {
        return "Senin-Jumat";
    } else if (namapaket == "STAR") {
        return "Sabtu-Minggu";
    } else {
        return "-";
    }
}

bool validasihari(string hari, string namapaket) {
    if (namapaket == "SUN" || namapaket == "MOON") {
        return (hari == "Senin" || hari == "senin" ||
                hari == "Selasa" || hari == "selasa" ||
                hari == "Rabu" || hari == "rabu" ||
                hari == "Kamis" || hari == "kamis" ||
                hari == "Jumat" || hari == "jumat");
    } else if (namapaket == "STAR") {
        return (hari == "Sabtu" || hari == "sabtu" ||
                hari == "Minggu" || hari == "minggu");
    }
    return false;
}

string inputharivalid(string namapaket) {
    string hari;
    while (true) {
        cout << "MAU PADEL DI HARI APA (" << infohari(namapaket) << "): ";
        getline(cin, hari);
        
        if (validasihari(hari, namapaket)) {
            if (hari.length() > 0) {
                hari[0] = toupper(hari[0]);
                for (int i = 1; i < hari.length(); i++) {
                    hari[i] = tolower(hari[i]);
                }
            }
            return hari;
        } else {
            cout << "[!] HARI TIDAK VALID! ";
            if (namapaket == "SUN" || namapaket == "MOON") {
                cout << "Paket weekday hanya bisa: Senin-Jumat" << endl;
            } else {
                cout << "Paket weekend hanya bisa: Sabtu&Minggu" << endl;
            }
        }
    }
}

// FUNGSI OVERLOADING
int hargapaket(string namapaket, int bulan) {
    int hargaPerSesi;
    if (namapaket == "SUN") hargaPerSesi = 450;
    else if (namapaket == "MOON") hargaPerSesi = 500;
    else if (namapaket == "STAR") hargaPerSesi = 650;
    else hargaPerSesi = 0;
    
    int totalPertemuan = hitungpertemuan(bulan);
    return hargaPerSesi * totalPertemuan;
}

int hargapaket(string namapaket) {
    if (namapaket == "SUN") {
        return 450;
    } else if (namapaket == "MOON") {
        return 500;
    } else if (namapaket == "STAR") {
        return 650;
    } else {
        return 0;
    }
}

void infopilihanjam(string namapaket) {
    cout << "\n--- PILIH JAM SESI (max 1 pilihan) ---" << endl;
    
    if (namapaket == "SUN") {
        cout << "1. 06.00 - 07.00" << endl;
        cout << "2. 07.00 - 08.00" << endl;
        cout << "3. 08.00 - 09.00" << endl;
        cout << "4. 09.00 - 10.00" << endl;
        cout << "5. 10.00 - 11.00" << endl;
        cout << "6. 11.00 - 12.00" << endl;
        cout << "7. 12.00 - 13.00" << endl;
        cout << "8. 13.00 - 14.00" << endl;
        cout << "9. 14.00 - 15.00" << endl;
        cout << "10. 15.00 - 16.00" << endl;
    } else if (namapaket == "MOON" || namapaket == "STAR") {
        cout << "1. 16.00 - 17.00" << endl;
        cout << "2. 17.00 - 18.00" << endl;
        cout << "3. 18.00 - 19.00" << endl;
        cout << "4. 19.00 - 20.00" << endl;
        cout << "5. 20.00 - 21.00" << endl;
        cout << "6. 21.00 - 22.00" << endl;
        cout << "7. 22.00 - 23.00" << endl;
    }
}

string jamsesi(string namapaket, int pilihan) {
    if (namapaket == "SUN") {
        if (pilihan >= 1 && pilihan <= 10) {
            int start = 5 + pilihan;
            return to_string(start) + ".00-" + to_string(start + 1) + ".00";
        }
    } else if (namapaket == "MOON" || namapaket == "STAR") {
        if (pilihan >= 1 && pilihan <= 7) {
            int start = 15 + pilihan;
            return to_string(start) + ".00-" + to_string(start + 1) + ".00";
        }
    }
    return "-";
}

void tampilkaninfopaket() {
    cout << "\n====================================================" << endl;
    cout << "               PAKET SESI DI MILO PADEL             " << endl;
    cout << "====================================================" << endl;
    cout << "1. SUN   : weekday, jam 06.00-16.00 | Rp 450.000/sesi" << endl;
    cout << "2. MOON  : weekday, jam 16.00-23.00 | Rp 500.000/sesi" << endl;
    cout << "3. STAR  : weekend, jam 16.00-23.00 | Rp 650.000/sesi" << endl;
    cout << "====================================================" << endl;
    cout << "[FYI] 1 bulan = 4 pertemuan (1x seminggu)" << endl;
    cout << "====================================================" << endl;
}

// CREATE
void buatmember(member members[], int &jumlahmember, string username) {
    for (int i = 0; i < jumlahmember; i++) {
        if (members[i].username == username) {
            cout << "\n[!] MEMBER SUDAH ADA" << endl;
            cout << "    menu 'lihat data saya' buat lihat data sendiri" << endl;
            return;
        }
    }
    
    if (jumlahmember < MAX_MEMBER) {
        cout << "\n--- BUAT AKUN MEMBER ---" << endl;
        member baru;
        baru.id = jumlahmember + 1;
        baru.username = username;
        
        cout << "Nama: ";
        getline(cin, baru.nama);
        
        tampilkaninfopaket();
        cout << "Paket (SUN/MOON/STAR): ";
        getline(cin, baru.namapaket);
        
        if (baru.namapaket != "SUN" && baru.namapaket != "MOON" && baru.namapaket != "STAR") {
            cout << "[!] MAAF, PAKET INI GA ADA!" << endl;
            return;
        }
        
        baru.detail.hari = inputharivalid(baru.namapaket);
        
        infopilihanjam(baru.namapaket);
        cout << "JAM BERAPA (1-" << (baru.namapaket == "SUN" ? "10" : "7") << "): ";
        int pilihanJam;
        cin >> pilihanJam;
        cin.ignore();
        baru.detail.jamsesi = jamsesi(baru.namapaket, pilihanJam);
        
        cout << "\nMAU JOIN BERAPA BULAN: ";
        cin >> baru.detail.bulanMember;
        cin.ignore();
        
        baru.detail.harga = hargapaket(baru.namapaket);
        
        members[jumlahmember] = baru;
        jumlahmember++;
        
        int totalPertemuan = hitungpertemuan(baru.detail.bulanMember);
        int total = hargapaket(baru.namapaket, baru.detail.bulanMember);
        
        cout << "\n[+] YEY AKUN MEMBER UDAH ADA!" << endl;
        cout << "      Paket           : " << baru.namapaket << endl;
        cout << "      Hari            : " << baru.detail.hari << endl;
        cout << "      Jam sesi        : " << baru.detail.jamsesi << endl;
        cout << "      Durasi          : " << baru.detail.bulanMember << " bulan" << endl;
        cout << "      Pertemuan/Bulan : " << PERTEMUAN_PER_BULAN << "x" << endl;
        cout << "      Total Pertemuan : " << totalPertemuan << "x" << endl;
        cout << "      Harga /Sesi     : Rp " << baru.detail.harga << ".000" << endl;
        cout << "      TOTAL BAYAR   : Rp " << total << ".000 " << endl;
        
    } else {
        cout << "\n[!] KAPASITAS MEMBER UDAH FULL!" << endl;
    }
}

// READ
void bacasemuadata(member members[], int jumlahmember) {
    if (jumlahmember == 0) {
        cout << "\n[!] DATA MEMBER MASIH KOSONG" << endl;
    } else {
        cout << "\n====================================================================================" << endl;
        cout << "                                  DAFTAR MEMBER PADEL                                 " << endl;
        cout << "======================================================================================" << endl;
        cout << left << setw(4) << "ID" 
             << setw(15) << "Nama member" 
             << setw(15) << "username"
             << setw(8)  << "Paket"
             << setw(10) << "Hari"
             << setw(12) << "Jam sesi"
             << setw(10) << "Bulan"
             << setw(12) << "Total" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        
        for (int i = 0; i < jumlahmember; i++) {
            int totalPertemuan = hitungpertemuan(members[i].detail.bulanMember);
            int total = hargapaket(members[i].namapaket, members[i].detail.bulanMember);
            
            cout << left << setw(4) << members[i].id
                 << setw(18) << members[i].nama
                 << setw(15) << members[i].username
                 << setw(8) << members[i].namapaket
                 << setw(12) << members[i].detail.hari
                 << setw(12) << members[i].detail.jamsesi
                 << setw(10) << (to_string(members[i].detail.bulanMember) + " bln")
                 << setw(12) << ("Rp " + to_string(total) + "K") << endl;
        }
        cout << "================================================================================" << endl;
    }
}

void bacadatasaya(member members[], int jumlahmember, string username) {
    bool ditemukan = false;
    
    for (int i = 0; i < jumlahmember; i++) {
        if (members[i].username == username) {
            int totalPertemuan = hitungpertemuan(members[i].detail.bulanMember);
            int total = hargapaket(members[i].namapaket, members[i].detail.bulanMember);
            
            cout << "\n=====================================" << endl;
            cout << "             DATA MEMBER ANDA          " << endl;
            cout << "=======================================" << endl;
            cout << "ID              : " << members[i].id << endl;
            cout << "Nama            : " << members[i].nama << endl;
            cout << "Paket           : " << members[i].namapaket << endl;
            cout << "Hari            : " << members[i].detail.hari << endl;
            cout << "Jam sesi        : " << members[i].detail.jamsesi << endl;
            cout << "Durasi          : " << members[i].detail.bulanMember << " bulan" << endl;
            cout << "Pertemuan/Bulan : " << PERTEMUAN_PER_BULAN << "x" << endl;
            cout << "Total Pertemuan : " << totalPertemuan << "x" << endl;
            cout << "Harga /Sesi     : Rp " << members[i].detail.harga << ".000" << endl;
            cout << " TOTAL BAYAR   : Rp " << total << ".000 " << endl;
            cout << "========================================" << endl;
            ditemukan = true;
            break;
        }
    }
    
    if (!ditemukan) {
        cout << "\n[!] BELUM JOIN MEMBER!" << endl;
        cout << "    YUK buat akun dulu" << endl;
    }
}

// UPDATE
void updatedatamember(member members[], int jumlahmember) {
    if (jumlahmember == 0) {
        cout << "\n[!] DATA MEMBER MASIH KOSONG" << endl;
    } else {
        cout << "\nDaftar Member:" << endl;
        for (int i = 0; i < jumlahmember; i++) {
            cout << "  [" << members[i].id << "] " << members[i].nama 
                 << " | Paket: " << members[i].namapaket << endl;
        }
        
        int index;
        cout << "\nID yang mau diupdate: ";
        cin >> index;
        cin.ignore();
        
        if (index > 0 && index <= jumlahmember) {
            int idx = index - 1;
            cout << "\n--- UPDATE DATA MEMBER ---" << endl;
            cout << "Nama: " << members[idx].nama << endl;
            cout << "Paket sekarang: " << members[idx].namapaket << endl;
            
            tampilkaninfopaket();
            cout << "Paket Baru (SUN/MOON/STAR): ";
            getline(cin, members[idx].namapaket);
            
            members[idx].detail.hari = inputharivalid(members[idx].namapaket);
            
            infopilihanjam(members[idx].namapaket);
            cout << "Pilih jam sesi (1-" << (members[idx].namapaket == "SUN" ? "10" : "7") << "): ";
            int pilihanJam;
            cin >> pilihanJam;
            cin.ignore();
            members[idx].detail.jamsesi = jamsesi(members[idx].namapaket, pilihanJam);
            
            cout << "MAU JOIN BERAPA BULAN: ";
            cin >> members[idx].detail.bulanMember;
            cin.ignore();
            
            members[idx].detail.harga = hargapaket(members[idx].namapaket);
            
            int totalPertemuan = hitungpertemuan(members[idx].detail.bulanMember);
            int total = hargapaket(members[idx].namapaket, members[idx].detail.bulanMember);
            
            cout << "\n[+] Paket member \"" << members[idx].nama << "\" YEY UPDATE BERHASIL!" << endl;
            cout << "    Total Pertemuan : " << totalPertemuan << "x" << endl;
            cout << "     TOTAL BAYAR   : Rp " << total << ".000 " << endl;
        } else {
            cout << "\n[!] ID MEMBER GA ADA!" << endl;
        }
    }
}

// DELETE
void deletedatamember(member members[], int &jumlahmember) {
    if (jumlahmember == 0) {
        cout << "\n[!] DATA MEMBER MASIH KOSONG!" << endl;
    } else {
        cout << "\nDaftar Member:" << endl;
        for (int i = 0; i < jumlahmember; i++) {
            cout << "  [" << members[i].id << "] " << members[i].nama << endl;
        }
        
        int index;
        cout << "\nID yang mau dihapus: ";
        cin >> index;
        cin.ignore();
        
        if (index > 0 && index <= jumlahmember) {
            for (int i = index - 1; i < jumlahmember - 1; i++) {
                members[i] = members[i + 1];
            }
            jumlahmember--;
            cout << "\n[+] MEMBER ID INI " << index << " BERHASIL DIHAPUS!" << endl;
        } else {
            cout << "\n[!] ID MEMBER GA ADA!" << endl;
        }
    }
}

// MAIN PROGRAM
int main() {
    user users[MAX_user] = {
        {"risma", "102", "member"},
        {"admin", "milopadel", "admin"}
    };
    int jumlahuser = 2;
    
    member members[MAX_MEMBER];
    int jumlahmember = 0;
    
    string inputnama, inputpw; 
    string userLogin, roleLogin;
    
    while (true) {
        cout << "!===================================!" << endl;
        cout << "        WELCOME TO MILO PADEL        " << endl;
        cout << "!===================================!" << endl;
        
        cout << "\n--- MENU UTAMA---" << endl;
        cout << "1. Registrasi Akun Baru" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";
        int pilihanawal;
        cin >> pilihanawal;
        cin.ignore();
        
        if (pilihanawal == 1) {
            cout << "\n--- REGISTRASI AKUN ---" << endl;
            cout << "username: ";
            getline(cin, inputnama);
            
            bool usernameada = false;
            for (int i = 0; i < jumlahuser; i++) {
                if (inputnama == users[i].username) {
                    usernameada = true;
                    break;
                }
            }
            
            if (usernameada) {
                cout << "[!] username \"" << inputnama << "\" SUDAH DIGUNAKAN!" << endl;
                continue;
            }
            
            cout << "Password: ";
            getline(cin, inputpw);
            users[jumlahuser].username = inputnama;
            users[jumlahuser].password = inputpw;
            users[jumlahuser].role = "user";
            jumlahuser++;
            
            cout << "\n[+] REGIS BERHASIL! YUK LOGIN" << endl;
            cout << endl;
        }
        
        else if (pilihanawal == 2) {
            cout << "\n--- LOGIN user ---" << endl;
            
            bool loginSukses = false;
            
            for (int percobaan = 0; percobaan < 3; percobaan++) {
                cout << "username: ";
                getline(cin, inputnama);
                cout << "Password: ";
                getline(cin, inputpw);
                
                bool usnbenar = false;
                bool pwbenar = false;
                
                for (int i = 0; i < jumlahuser; i++) {
                    if (inputnama == users[i].username) {
                        usnbenar = true;
                        if (inputpw == users[i].password) {
                            pwbenar = true;
                            userLogin = inputnama;
                            roleLogin = users[i].role;
                            break;
                        }
                    }
                }
                
                if (usnbenar && pwbenar) {
                    loginSukses = true;
                    break;
                }
                
                cout << "\n[!] LOGIN GAGAL" << endl;
                if (!usnbenar) {
                    cout << "    -> userNAME GA ADA NIH!" << endl;
                } else {
                    cout << "    -> PASSWORD SALAH!" << endl;
                }
                
                if (percobaan == 2) {
                    cout << "\n[!] AKSES DITOLAK! GAGAL LOGIN 3x." << endl;
                    return 0;
                }
                
                cout << "    -> Sisa percobaan: " << (2 - percobaan) << endl << endl;
            }
            
            if (!loginSukses) {
                return 0;
            }
            
            int pilihan; 
            bool menuberjalan = true;
            
            do {
                cout << endl;
                cout << "============================================" << endl;
                cout << "          login sebagai: " << userLogin << " (" << roleLogin << ")" << endl;
                cout << "          mau ngapain nih???                " << endl;
                cout << "============================================" << endl;
                
                if (roleLogin == "admin") {
                    cout << "1. Buat Akun Member Baru      " << endl;
                    cout << "2. Tampilkan Semua Data       " << endl;
                    cout << "3. Update Paket Member    " << endl;
                    cout << "4. Hapus Member" << endl;
                    cout << "5. Logout                     " << endl;
                    cout << "=======================================" << endl;
                    cout << "Pilih menu (1-5): ";
                    cin >> pilihan;
                    cin.ignore();
                    
                    if (pilihan < 1 || pilihan > 5) {
                        cout << "[!] PILIHAN TIDAK VALID! hanya 1-5." << endl;
                        continue;
                    }
                    
                    switch (pilihan) {
                        case 1: 
                            buatmember(members, jumlahmember, "admin_managed"); 
                            break;
                        case 2: 
                            bacasemuadata(members, jumlahmember); 
                            break;
                        case 3: 
                            updatedatamember(members, jumlahmember); 
                            break;
                        case 4: 
                            deletedatamember(members, jumlahmember); 
                            break;
                        case 5:
                            cout << "\n[+] BERHASIL LOGOUT! kembali ke menu utama." << endl;
                            menuberjalan = false;
                            break;
                    }
                } else {
                    cout << "1. Lihat Jadwal & Harga Paket   " << endl;
                    cout << "2. Buat Akun Member        " << endl;
                    cout << "3. Lihat Data Saya              " << endl;
                    cout << "4. Logout                       " << endl;
                    cout << "============================================" << endl;
                    cout << "Pilih menu (1-4): ";
                    cin >> pilihan;
                    cin.ignore();
                    
                    if (pilihan < 1 || pilihan > 4) {
                        cout << "[!] PILIHAN TIDAK VALID! hanya 1-4." << endl;
                        continue;
                    }
                    
                    switch (pilihan) {
                        case 1: 
                            tampilkaninfopaket(); 
                            break;
                        case 2: 
                            buatmember(members, jumlahmember, userLogin); 
                            break;
                        case 3: 
                            bacadatasaya(members, jumlahmember, userLogin); 
                            break;
                        case 4:
                            cout << "\n[+] BERHASIL LOGOUT! kembali ke menu utama." << endl;
                            menuberjalan = false;
                            break;
                    }
                }
                
            } while (menuberjalan);
            
        } else if (pilihanawal == 3) {
            cout << "\nTHANK YOU! see you milovers." << endl;
            break;
        } else {
            cout << "[!] PILIHAN TIDAK VALID!" << endl;
        }
    }
    
    return 0;
}