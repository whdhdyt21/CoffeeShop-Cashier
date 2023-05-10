#ifndef LIBRARYKU_H
#define LIBRARYKU_H
#include <iostream>
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

        //fungsi untuk menampilkan daftar makanan dan harga menggunakan array
        void daftar_makanan()
        {
            string makanan[5] = {"1. Nasi Goreng", "2. Mie Goreng", "3. Nasi Uduk", "4. Nasi Kuning", "5. Nasi Kebuli"};
            int harga_makanan[5] = {15000, 12000, 10000, 20000, 25000};
            cout << "Daftar Makanan : " << endl;
            for (int i = 0; i < 5; i++)
            {
                cout << makanan[i] << " \t\t " << harga_makanan[i] << endl;
            }
        }

        //fungsi untuk menampilkan daftar kopi dan harga menggunakan array
        void daftar_kopi()
        {
            string kopi[5] = {"1. Kopi Hitam", "2. Kopi Susu", "3. Kopi Latte", "4. Kopi Cappucino", "5. Kopi Moccacino"};
            int harga_kopi[5] = {10000, 12000, 15000, 20000, 25000};
            cout << "Daftar Kopi : " << endl;
            for (int i = 0; i < 5; i++)
            {
                cout << kopi[i] << " \t\t " << harga_kopi[i] << endl;
            }
        }

        //fungsi untuk menampilkan daftar non-kopi dan harga menggunakan array
        void daftar_nonkopi()
        {
            string nonkopi[5] = {"1. Teh Manis", "2. Teh Tawar", "3. Jus Jeruk", "4. Jus Alpukat", "5. Jus Mangga"};
            int harga_nonkopi[5] = {5000, 5000, 10000, 15000, 15000};
            cout << "Daftar Non-Kopi : " << endl;
            for (int i = 0; i < 5; i++)
            {
                cout << nonkopi[i] << " \t\t " << harga_nonkopi[i] << endl;
            }
        }

        //fungsi untuk menampilkan daftar snack dan harga menggunakan array
        void daftar_snack()
        {
            string snack[5] = {"1. Pisang Goreng", "2. Roti Bakar", "3. Roti Bakar Keju", "4. Roti Bakar Coklat", "5. Roti Bakar Susu"};
            int harga_snack[5] = {5000, 10000, 12000, 12000, 12000};
            cout << "Daftar Snack : " << endl;
            for (int i = 0; i < 5; i++)
            {
                cout << snack[i] << " \t\t " << harga_snack[i] << endl;
            }
        }

        //fungsi untuk menampilkan daftar menu
        void daftar_menu()
        {
            //switch case
            int pilih;
            cout << "Daftar Menu : " << endl;
            cout << "1. Makanan" << endl;
            cout << "2. Kopi" << endl;
            cout << "3. Non-Kopi" << endl;
            cout << "4. Snack" << endl;
            cout << "Pilih : ";
            cin >> pilih;
            switch (pilih)
            {
            case 1:
                daftar_makanan();
                break;
            case 2:
                daftar_kopi();
                break;
            case 3:
                daftar_nonkopi();
                break;
            case 4:
                daftar_snack();
                break;
            default:
                break;
            }
        }

        


};

#endif