#include <iostream>
using namespace std;

// Struktur untuk menyimpan informasi pemuda
struct pemuda { 
    string Nama, Alamat, Status, TglLahir;
    int umur;
    pemuda* next; // Pointer ke data pemuda berikutnya dalam linked list
};
pemuda* awal = NULL, *baru, *bantu, *sebelum;  // Deklarasi pointer global untuk linked list

string Profesi[4] = { "Pelajar", "Mahasiswa", "Bekerja", "Belum Bekerja" }; //Membuat array yang berisi profesi untuk dipilih

// Fungsi untuk memilih profesi
void PilihProfesi() {
    cout << "           Pilih Profesi           " << endl;
    for (int i = 0; i < 4; i++) {
        cout << "           " << i + 1 << ". " << Profesi[i] << endl;
    };
    int noprofesi;
    cout << "Profesi No : "; cin >> noprofesi;
    baru->Status = Profesi[noprofesi - 1]; 
    system("cls");// Membersihkan layar konsol
}

// Fungsi untuk menambahkan data
void TambahData() {
    baru = new pemuda; // Membuat simpul baru untuk menyimpan data
    cout << "Nama : "; cin >> baru->Nama;
    cout << "Umur : "; cin >> baru->umur;
    cout << "Tgl Lahir (DD/MM/YY) : "; cin >> baru->TglLahir;
    cout << "Alamat : "; cin >> baru->Alamat;
    PilihProfesi(); // Memanggil fungsi untuk memilih profesi
    baru->next = awal; // Mengatur pointer next dari data baru untuk menunjuk ke data awal
    awal = baru; // Menjadikan data baru sebagai data awal
    system("cls");
}
// Fungsi untuk menampilkan data
void TampilData() {
    bantu = awal; // Mengatur pointer bantu untuk menunjuk ke data awal
    if (bantu == NULL) {
        cout << "Data masih kosong cuy";
    }
    while (bantu != NULL) {
        cout << "Nama : " << bantu->Nama << endl;
        cout << "Umur : " << bantu->umur << endl;
        cout << "Tgl Lahir : " << bantu->TglLahir << endl;
        cout << "Alamat : " << bantu->Alamat << endl;
        cout << "Profesi : " << bantu->Status << endl;
        bantu = bantu->next; // Pindah ke data berikutnya dalam linked list
    }
    char blk;
    cout << "\nKetik 1 untuk kembali ke menu  "; cin >> blk; system("cls");
}
// Fungsi untuk mengedit data
void EditData() {
    if (awal == NULL) { //jika data kosong maka akan menampilkan pesan
        cout << "Data masih kosong cuy";
        char blk;
        cout << "\nKetik 1 untuk kembali ke menu  "; cin >> blk; system("cls");
    }
    else{
    string cari;
    int pilih;
    cout << "Masukan Tgl Lahir pemuda yang akan diedit : "; cin >> cari; // Meminta input tanggal lahir yang akan diedit
    bantu = awal;
    while (bantu != NULL) {
        if (bantu->TglLahir == cari) {
            cout << "           Data Ditemukan      " << endl;
            cout << "1. Nama : " << bantu->Nama << endl;
            cout << "2. Umur : " << bantu->umur << endl;
            cout << "3. Tgl Lahir : " << bantu->TglLahir << endl;
            cout << "4. Alamat : " << bantu->Alamat << endl;
            cout << "5. Profesi : " << bantu->Status << endl;

            cout << "Edit No : "; cin >> pilih; // Meminta input untuk memilih data yang akan diubah

            switch (pilih) {
            case 1:
                cout << "Nama : "; cin >> baru->Nama;
                break;
            case 2:
                cout << "Umur : "; cin >> baru->umur;
                break;
            case 3:
                cout << "Tgl Lahir (DD/MM/YY) : "; cin >> baru->TglLahir;
                break;
            case 4:
                cout << "Alamat : "; cin >> baru->Alamat;
                break;
            case 5:
                PilihProfesi();
                break;
            }

        }
        bantu = bantu->next; system("cls");
    }
    }
}
// Fungsi untuk menghapus data
void DeleteData() {
    if (awal == NULL) {
        cout << "Data masih kosong cuy";
        char blk;
        cout << "\nKetik 1 untuk kembali ke menu  "; cin >> blk; system("cls");
    }
    else {
    string cari;
    cout << "Masukan Tgl Lahir pemuda yang akan dihapus : "; cin >> cari; // Meminta input tanggal lahir yang akan dihapus
    bantu = awal;
    sebelum = NULL;
    while (bantu != NULL) {
        if (bantu->TglLahir == cari) {
            if (sebelum == NULL) {
                awal = bantu->next; // Jika data yang akan dihapus adalah data awal, maka pointer awal diatur ke data berikutnya
            }
            else {
                sebelum->next = bantu->next; // Jika data yang akan dihapus bukan data awal, maka pointer next dari data sebelumnya diatur ke data setelahnya
            }
            delete bantu; // Menghapus data yang telah ditemukan
            cout << "Data berhasi dihapus yeay";
            char blk;
            cout << "\nKetik 1 untuk kembali ke menu  "; cin >> blk; system("cls");
            return;
        }
        sebelum = bantu;
        bantu = bantu->next;
       
    }
    }
}

int main() {

    bool ulg = true;
    int menu;
    // Menampilkan menu
    do {
        cout << "            Karang Taruna Bekasi            " << endl;
        cout << "           1. Input Data Pemuda/i           " << endl;
        cout << "           2. Lihat Data Pemuda/i           " << endl;
        cout << "           3. Edit  Data Pemuda/i           " << endl;
        cout << "           4. Hapus Data Pemuda/i           " << endl;
        cout << "           5. Keluar                        " << endl;

        cout << "\nMenu No : "; cin >> menu; system("cls"); // Meminta input menu dari user
        cout << endl;

        switch (menu) { //untuk menentukan menu yang dipilih
        case 1:
            TambahData(); // Memanggil fungsi untuk Menambah data
            break;
        case 2:
            TampilData(); // Memanggil fungsi untuk Menampilkan data
            break;
        case 3:
            EditData(); // Memanggil fungsi untuk Mengedit data
            break;
        case 4:
            DeleteData(); // Memanggil fungsi untuk Menghapus data
            break;
        case 5:
            ulg = false; // Keluar dari program
            break;
        }
    } while (ulg == true); // Melakukan loop selama user belum memilih untuk keluar

    return 0;
}
