// // deklarasi prosedur
// void nama_parameter(tipe_data_parameter nama_parameter) {
// / isi fungsi
// } :

// // deklarasi fungsi
// Tipe_data nama_fungsi(tipe_data_parameter nama_parameter){
// / isi fungsi
// }

// // contoh
// #include <iostream>
// using namespace std;
// / Fungsi ditaruh sebelum main
// int kuadrat(int x) {
// return x * x;
// }
// / Prosedur ditulis sebelum main
// void sapa(string nama) {
// cout < "Halo, " < nama < "!" < endl;
// }
// int main() {
// sapa("Budi");
// cout < "Hasil 5 kuadrat: " < kuadrat(5) < endl;
// return 0;
// }

// // contoh
// #include <iostream>
// using namespace std;
// / Definisikan prosedur atau fungsi sebelum fungsi main
// int kuadrat(int x);
// void sapa(string nama);
// int main() {
// sapa("Andi");
// cout < "Hasil 3 kuadrat: " < kuadrat(3) < endl;
// return 0;
// }
// / Penulisan fungsi setelah main
// int kuadrat(int x) {
// return x * x;
// }
// / Penulisan prosedur setelah main
// void sapa(string nama) {
// cout < "Halo, " < nama < "!" < endl;
// }


// contoh parameter di prosedur
#include <iostream>
using namespace std;
// Bagian Definisi Prosedur
// Di sini 'namaHero', 'level', dan 'hp' adalah PARAMETER.
// Mereka hanyalah "variabel kosong" yang menunggu nilai.
void tampilkanStatus(string namaHero, int level, double hp) {
cout << " = STATUS HERO =" << endl;
cout << "Nama : " << namaHero << endl;
cout << "Level : " << level << endl;
cout << "Darah : " << hp << "%" << endl;
cout << "===================" << endl;
cout << endl;
}
int main() {
// Bagian pengambilan argumen
// Kasus 1: Mengirim nilai secara langsung
// "Alucard", 15, dan 90.5 adalah argumen.
tampilkanStatus("Alucard", 15, 90.5);
// Kasus 2: Mengirim menggunakan variabel lain
string hero2 = "Miya";
int lvl2 = 12;
double hp2 = 45.0;
// Variabel 'hero2', 'lvl2', dan 'hp2' dikirim sebagai argumen
tampilkanStatus(hero2, lvl2, hp2);
return 0;
}



// // pass by value
// #include <iostream>
// using namespace std;
// / prosedur ini menerima nilai dari variable gajiSaya
// void cobaUbahGaji(int gajiSaya) {
// gajiSaya = 1000000000; / gaji di dalam prosedur
// cout < "Gaji pas di dalam fungsi: " < gajiSaya < endl;
// }
// int main() {
// int gajiSaya = 5000000; / gaji di dalam main
// cout < "Gaji awal: " < gajiSaya < endl;
// cobaUbahGaji(gajiSaya); / kirim ke fungsi
// cout < "Gaji setelah fungsi dipanggil: " < gajiSaya < endl;
// return 0;
// }


// // pass by reference
// #include <iostream>
// using namespace std;
// / perhatikan tanda '&' di sebelah parameter
// void tukarsenjata(string &senjata) {
// senjata = "Sarung Wadimor"; / langsung ganti isi variabel
// aslinya
// }
// int main() {
// string senjatahero = "Kayu Busuk";
// cout < "Senjata awal: " < senjatahero < endl;
// tukarsenjata(senjatahero); / panggil prosedur
// / variable dalam main akan ikut terubah
// cout < "Senjata sekarang: " < senjatahero < endl;
// return 0;
// }


// //default value
// #include <iostream>
// using namespace std;
// / 'kadarGula' punya nilai default "Normal"
// / parameter default wajib di taruh paling kanan!
// void pesankopi(string menu, string kadargula = "Normal") {
// cout < "Pesanan: " < menu < " | Gula: " < kadargula < endl;
// }
// int main() {
// / Kasus 1: pengguna mengirim 1 parameter
// pesankopi("Kopi Susu");
// / Kasus 2: pengguna mengirim 2 parameter dan menggantikan
// parameter default dari prosedur
// pesankopi("Americano", "Less Sugar");
// return 0;
// }



// //fungsi overloading
// #include <iostream>
// using namespace std;
// / Fungsi menjumlahkan bilangan bulat
// int tambah(int a, int b) {
// return a + b;
// }
// / Fungsi 2 menjumlahkan bilangan desimal
// double tambah(double a, double b) {
// return a + b;
// }
// int main() {
// cout < "Hasil Int : " < tambah(5, 6) < endl;
// cout < "Hasil Double : " < tambah(5.5, 6.6) < endl;
// return 0;
// }