#include <iostream>
//#include "libraryku.h"
#include <chrono>
#include <ctime>
#include <iomanip>
using namespace std;

struct WDF
{
    int kode_menu;
    string nama_menu;
    int harga;
    int jumlah_pesanan;
    int total_harga;
    WDF *next;
    WDF *prev;
};

struct DoubleLinkedList
{
    private:
        WDF *head;
        WDF *tail;
    public:
        DoubleLinkedList()
        {
            head = NULL;
            tail = NULL;
        }
        //fungsi untuk kode struk secara urut berdasar input
        int kodestruk(int min, int max)
        {
            int range = max - min + 1;
            return rand() % range + min;
        }

        //fungsi untuk nomor meja
        void nomor_meja()
        {
            int no_meja;
            cout << "No.Meja : ";
            cin >> no_meja;
        }

        //waktu sekarang
        void waktu()
        {
        // Mendapatkan waktu saat ini
        chrono::system_clock::time_point now = chrono::system_clock::now();
        
        // Mengubah waktu ke dalam bentuk waktu kalender
        time_t time_now = chrono::system_clock::to_time_t(now);

        // Membuat objek tm untuk memformat waktu sesuai keinginan
        tm *timeinfo = localtime(&time_now);

        // Mencetak waktu dengan format yang diinginkan
        cout << "Tanggal : " << put_time(timeinfo, "%d/%m/%Y %H:%M:%S") << endl;
        }

        //fungsi untuk menampilkan kode menu, daftar makanan dan harga menggunakan array
        void daftar_makanan()
        {
            int kode_makanan[10] = {1, 2, 3, 4, 5, 6, 7, 8};
            string nama_makanan[10] = {"Nasi Goreng", "Nasi Goreng Seafood", "Nasi Goreng Ayam", "Nasi Goreng Sapi", "Nasi Goreng Kambing", "Nasi Goreng Kambing", "Nasi Goreng Kambing", "Nasi Goreng Kambing"};
            int harga_makanan[10] = {15000, 20000, 20000, 25000, 30000, 35000, 40000, 45000};
            cout << "Daftar Makanan : " << endl;
            for (int i = 0; i < 8; i++)
            {
                cout << kode_makanan[i] << ". " << nama_makanan[i] << " - " << harga_makanan[i] << endl;
            }
        }

        //fungsi untuk menampilkan kode menu, daftar kopi dan harga menggunakan array
        void daftar_kopi()
        {
            int kode_kopi[10] = {1, 2, 3, 4, 5, 6, 7, 8};
            string nama_kopi[10] = {"Kopi Hitam", "Kopi Susu", "Kopi Cappucino", "Kopi Latte", "Kopi Moccacino", "Kopi Arabica", "Kopi Robusta", "Kopi Luwak"};
            int harga_kopi[10] = {10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000};
            cout << "Daftar Kopi : " << endl;
            for (int i = 0; i < 8; i++)
            {
                cout << kode_kopi[i] << ". " << nama_kopi[i] << " - " << harga_kopi[i] << endl;
            }
        }

        //fungsi untuk menampilkan kode menu, daftar non kopi dan harga menggunakan array
        void daftar_nonkopi()
        {
            int kode_nonkopi[10] = {1, 2, 3, 4, 5, 6, 7, 8};
            string nama_nonkopi[10] = {"Teh Manis", "Teh Tawar", "Teh Susu", "Teh Tarik", "Teh Hijau", "Teh Hitam", "Teh Jahe", "Teh Sereh"};
            int harga_nonkopi[10] = {5000, 5000, 10000, 10000, 10000, 10000, 10000, 10000};
            cout << "Daftar Non-Kopi : " << endl;
            for (int i = 0; i < 8; i++)
            {
                cout << kode_nonkopi[i] << ". " << nama_nonkopi[i] << " - " << harga_nonkopi[i] << endl;
            }
        }

        //fungsi untuk menampilkan kode menu, daftar snack dan harga menggunakan array
        void snack()
        {
            int kode_snack[10] = {1, 2, 3, 4, 5, 6, 7, 8};
            string nama_snack[10] = {"Keripik Kentang", "Keripik Singkong", "Keripik Pisang", "Keripik Jagung", "Keripik Tempe", "Keripik Tahu", "Keripik Bayam", "Keripik Wortel"};
            int harga_snack[10] = {10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000};
            cout << "Daftar Snack : " << endl;
            for (int i = 0; i < 8; i++)
            {
                cout << kode_snack[i] << ". " << nama_snack[i] << " - " << harga_snack[i] << endl;
            }
        }

        //fungsi untuk input pesanan
        void input_pesanan()
        {
            int kode_menu;
            string nama_menu;
            int harga;
            int jumlah_pesanan;
            int total_harga;
            cout << "Kode Menu : ";
            cin >> kode_menu;
            cout << "Nama Menu : ";
            cin >> nama_menu;
            cout << "Harga : ";
            cin >> harga;
            cout << "Jumlah Pesanan : ";
            cin >> jumlah_pesanan;
            total_harga = harga * jumlah_pesanan;
        }







};

DoubleLinkedList list;

int main() 
{
    return 0;
}