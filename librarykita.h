#ifndef LIBRARYKU_H
#define LIBRARYKU_H
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

//Sistem Program Kasir di Cafeshop
struct WDF
{
    string nama;
    int harga;
    int jumlah;
    WDF *next;
    WDF *prev;
};

struct CoffeeShop
{
    private:
        WDF *head;
        WDF *tail;
    public:
        CoffeeShop()
        {
            head = NULL;
            tail = NULL;
        }


        //fungsi untuk kode struk random
        int kodestruk(int min, int max)
        {
            srand(time(NULL));
            return rand() % (max - min + 1) + min;
        }

        //fungsi untuk nomor meja
        void nomor_meja()
        {
            int no_meja;
            cout << "No.Meja    : ";
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
        cout << "Tanggal    : " << put_time(timeinfo, "%d/%m/%Y %H:%M:%S") << endl;
        }

        //fungsi untuk mencetak struk
        void printreceipt()
        {
            cout << "            WDF Coffeeshop" << endl;
            cout << "           Gang Jeruk No. 5" << endl;
            cout << "            Telp. 1500-212" << endl;
            cout << "=====================================" << endl;
            cout << "Kode Struk : " << kodestruk(1000, 9999) << endl;
            nomor_meja();
            waktu();
            cout << "=====================================" << endl;
            cout << "Menu" "\t\t" << "Qty" << "\t" << "Harga" << "\t" << "Total" << endl;
            cout << "-------------------------------------" << endl;
            
            cout << "-------------------------------------" << endl;
            /*cout << "Sub Total" << endl;
            cout << "PPN (10%)" << endl;
            cout << "Total Bayar" << endl;
            cout << "Kembali" << endl;*/
            cout << "=====================================" << endl;
            cout << "          Senyummu Senyumku" << endl;
            cout << "            Terima Kasih" << endl;
        }

        //fungsi yang digunakan untuk mencetak struk pembeli berdasarkan kode struk;
        /*void mintastruk()
        {
            int kode;
            cout << "Masukkan Kode Struk Anda : " << endl;
            cin >> kode;
            printreceipt();
        }*/

        //fungsi yang berisi menu-menu yang ada di coffeeshop, kode menu, nama menu, dan harga menu;
        void MenuCoffeeShop()
        {
            int kodeMenu;
            string namaMenu;
            int hargaMenu;

            //
        }

        void A

        /*  MENU 1 */
        //menu 1 untuk memilih "Siapakah anda ? " yang terdiri dari menu pembeli, menu penjual, mencetak struk berdasarkan kode struk, dan keluar program.
        void menu1()
        {
            int pilihan;
            cout << "Silahkan Memilih Menu dibawah ini :" << endl;
            cout << "1. Menu Pembeli" << endl;
            cout << "2. Menu Penjual" << endl;
            cout << "3. Keluar Program" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            switch (pilihan)
            {
                case 1:
                    menu2();
                    break;
                case 2:
                    menu3();
                    break;
                case 3:
                    cout << "Terima Kasih Atas Kunjungannya" << endl;
                    break;
                default:
                    cout << "Pilihan tidak tersedia" << endl;
                    break;
            }
        }

        /*  MENU 2 */
        //Menu pembeli, untuk melihat menu, menambah pesanan, menyisipkan pesanan berdasarkan menu tertentu, menghapus pesanan berdasarkan kode menu, menu sorting dengan menggunakan insertion sort berdasarkan kode menu;
        void menu2()
        {
            int pilihan;
            cout << "Menu Pembeli" << endl;
            cout << "1. Lihat Daftar Menu" << endl;
            cout << "2. Tambah Pesanan" << endl;
            cout << "3. Menyisipkan Pesanan" << endl;
            cout << "4. Menghapus Pesanan" << endl;
            cout << "5. Mengurutkan Pesanan" << endl;
            cout << "6. Kembali" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            switch (pilihan)
            {
                case 1:
                    MenuCoffeeShop();
                    break;
                case 2:
                    AddOrderCoffeeShop();
                    break;
                case 3:
                    InsertOrderCoffeeSop();
                    break;
                case 4:
                    DeleteOrderCoffeeShop();
                    break;
                case 5:
                    SortingOrderCoffeeShop();
                    break;
                case 6:
                    menu1();
                    break;
                case 7:
                    cout << "Terima Kasih Atas Kunjungannya" << endl;
                    break;
                default:
                    cout << "Pilihan Tidak Tersedia" << endl;
            }
        }

        /*  Menu 3 */
        //Menu Penjual
        void menu3()
        {
            cout << "Hello world";
        }





                
        //fungsi untuk menjalankan program
        void run()
        {
            menu1();
        }
};

#endif