#ifndef LIBRARYKU_H
#define LIBRARYKU_H
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

struct WDF
{
    string nama;
    int harga;
    int jumlah;
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

        //fungsi untuk print struk
        void printreceipt()
        {
            cout << "WDF Coffeeshop" << endl;
            cout << "Gang Jeruk No. 5" << endl;
            cout << "Telp. 1500-212" << endl;
            cout << "====================================" << endl;
            cout << "Kode Struk : " << kodestruk(1000, 9999) << endl;
            nomor_meja();
            waktu();
            cout << "====================================" << endl;
            cout << "Menu" "\t" << "Qty" << "\t" << "Harga" << "\t" << "Total" << endl;
            cout << "------------------------------------" << endl;
            
            cout << "------------------------------------" << endl;
            cout << "Sub Total" << endl;
            cout << "PPN (10%)" << endl;
            cout << "Total Bayar" << endl;
            cout << "Kembali" << endl;
            cout << "====================================" << endl;
            cout << "Senyummu Senyumku" << endl;
            cout << "Terima Kasih" << endl;
        }





        /*  MENU 1 */
        //menu 1 untuk memilih "Siapakah anda ? " yang terdiri dari penjual, pembeli, dan keluar
        void menu1()
        {
            int pilihan;
            cout << "Siapakah anda ? " << endl;
            cout << "1. Penjual" << endl;
            cout << "2. Pembeli" << endl;
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





        /*  MENU 2 UNTUK PENJUAL */
        /*  MENU */
        //library untuk menu makanan menggunakan array
        void menu_makanan()
        {
            string menu_makanan[10] = {"Nasi Goreng", "Nasi Goreng Seafood", "Nasi Goreng Kambing", "Nasi Goreng Ayam", "Nasi Goreng Sapi", "Nasi Goreng Ikan Asin", "Nasi Goreng Cumi", "Nasi Goreng Udang", "Nasi Goreng Bakso", "Nasi Goreng Telur"};
            int harga_makanan[10] = {15000, 20000, 25000, 20000, 25000, 25000, 25000, 25000, 25000, 25000};
            cout << "=========================" << endl;
            cout << "      MENU MAKANAN       " << endl;
            cout << "=========================" << endl;
            for (int i = 0; i < 10; i++)
            {
                cout << i+1 << ". " << menu_makanan[i] << " - Rp." << harga_makanan[i] << endl;
            }
            cout << endl;
        }

        //library untuk menu kopi menggunakan array
        void menu_kopi()
        {
            string menu_kopi[10] = {"Kopi Hitam", "Kopi Susu", "Kopi Cappucino", "Kopi Latte", "Kopi Moccacino", "Kopi Espresso", "Kopi Americano", "Kopi Flat White", "Kopi Macchiato", "Kopi Affogato"};
            int harga_kopi[10] = {10000, 15000, 20000, 20000, 25000, 20000, 20000, 25000, 25000, 25000};
            cout << "=========================" << endl;
            cout << "         MENU KOPI       " << endl;
            cout << "=========================" << endl;
            for (int i = 0; i < 10; i++)
            {
                cout << i+1 << ". " << menu_kopi[i] << " - Rp." << harga_kopi[i] << endl;
            }
            cout << endl;
        }

        //library untuk menu non kopi menggunakan array
        void menu_nonkopi()
        {
            string menu_nonkopi[10] = {"Teh Manis", "Teh Tawar", "Teh Tarik", "Teh Susu", "Teh Jahe", "Teh Poci", "Teh Hangat", "Teh Dingin", "Teh Panas", "Teh Es"};
            int harga_nonkopi[10] = {5000, 5000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000};
            cout << "=========================" << endl;
            cout << "        MENU NON KOPI    " << endl;
            cout << "=========================" << endl;
            for (int i = 0; i < 10; i++)
            {
                cout << i+1 << ". " << menu_nonkopi[i] << " - Rp." << harga_nonkopi[i] << endl;
            }
            cout << endl;
        }

        //library untuk menu snack menggunakan array
        void menu_snack()
        {
            string menu_snack[10] = {"Keripik Kentang", "Keripik Singkong", "Keripik Pisang", "Keripik Tempe", "Keripik Tahu", "Keripik Jagung", "Keripik Bayam", "Keripik Wortel", "Keripik Ubi", "Keripik Brokoli"};
            int harga_snack[10] = {10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 15000, 15000};
            cout << "=========================" << endl;
            cout << "         MENU SNACK      " << endl;
            cout << "=========================" << endl;
            for (int i = 0; i < 10; i++)
            {
                cout << i+1 << ". " << menu_snack[i] << " - Rp." << harga_snack[i] << endl;
            }
            cout << endl;
        }



        /*  MENAMPILKAN MENU */
        void lihatmenu()
        {
            menu_makanan();
            menu_kopi();
            menu_nonkopi();
            menu_snack();
        }



        /*  MENAMBAH MENU UNTUK PENJUAL */
        //tambah menu makanan dengan input nama dan harga kedalam array
        void tambah_menu_makanan()
        {
            string menu_makanan[10] = {"Nasi Goreng", "Nasi Goreng Seafood", "Nasi Goreng Kambing", "Nasi Goreng Ayam", "Nasi Goreng Sapi", "Nasi Goreng Ikan Asin", "Nasi Goreng Cumi", "Nasi Goreng Udang", "Nasi Goreng Bakso", "Nasi Goreng Telur"};
            int harga_makanan[10] = {15000, 20000, 25000, 20000, 25000, 25000, 25000, 25000, 25000, 25000};
            string nama_makanan;
            int harga;
            cout << "Masukkan nama makanan : ";
            cin >> nama_makanan;
            cout << "Masukkan harga makanan : ";
            cin >> harga;
            for (int i = 0; i < 10; i++)
            {
                if (menu_makanan[i] == "")
                {
                    menu_makanan[i] = nama_makanan;
                    harga_makanan[i] = harga;
                    break;
                }
            }
            cout << "Menu berhasil ditambahkan" << endl;
            cout << endl;
        }

        //tambah menu kopi dengan input nama dan harga kedalam array
        void tambah_menu_kopi()
        {
            string menu_kopi[10] = {"Kopi Hitam", "Kopi Susu", "Kopi Cappucino", "Kopi Latte", "Kopi Moccacino", "Kopi Espresso", "Kopi Arabica", "Kopi Robusta", "Kopi Luwak", "Kopi Toraja"};
            int harga_kopi[10] = {10000, 15000, 20000, 20000, 25000, 20000, 20000, 25000, 25000, 25000};
            string nama_kopi;
            int harga;
            cout << "Masukkan nama kopi : ";
            cin >> nama_kopi;
            cout << "Masukkan harga kopi : ";
            cin >> harga;
            for (int i = 0; i < 10; i++)
            {
                if (menu_kopi[i] == "")
                {
                    menu_kopi[i] = nama_kopi;
                    harga_kopi[i] = harga;
                    break;
                }
            }
            cout << "Menu berhasil ditambahkan" << endl;
            cout << endl;
        }

        //tambah menu non kopi dengan input nama dan harga kedalam array
        void tambah_menu_nonkopi()
        {
            string menu_nonkopi[10] = {"Teh Hitam", "Teh Susu", "Teh Tarik", "Teh Hijau", "Teh Manis", "Teh Tawar", "Teh Jahe", "Teh Jeruk", "Teh Lemon", "Teh Chamomile"};
            int harga_nonkopi[10] = {10000, 15000, 20000, 20000, 25000, 20000, 20000, 25000, 25000, 25000};
            string nama_nonkopi;
            int harga;
            cout << "Masukkan nama non kopi : ";
            cin >> nama_nonkopi;
            cout << "Masukkan harga non kopi : ";
            cin >> harga;
            for (int i = 0; i < 10; i++)
            {
                if (menu_nonkopi[i] == "")
                {
                    menu_nonkopi[i] = nama_nonkopi;
                    harga_nonkopi[i] = harga;
                    break;
                }
            }
            cout << "Menu berhasil ditambahkan" << endl;
            cout << endl;
        }

        //tambah menu snack dengan input nama dan harga kedalam array
        void tambah_menu_snack()
        {
            string menu_snack[10] = {"Keripik Kentang", "Keripik Singkong", "Keripik Pisang", "Keripik Tempe", "Keripik Bayam", "Keripik Jagung", "Keripik Wortel", "Keripik Ubi", "Keripik Teri", "Keripik Udang"};
            int harga_snack[10] = {10000, 15000, 20000, 20000, 25000, 20000, 20000, 25000, 25000, 25000};
            string nama_snack;
            int harga;
            cout << "Masukkan nama snack : ";
            cin >> nama_snack;
            cout << "Masukkan harga snack : ";
            cin >> harga;
            for (int i = 0; i < 10; i++)
            {
                if (menu_snack[i] == "")
                {
                    menu_snack[i] = nama_snack;
                    harga_snack[i] = harga;
                    break;
                }
            }
            cout << "Menu berhasil ditambahkan" << endl;
            cout << endl;
        }

        //tambah menu makanan untuk penjual
        void tambahmenu()
        {
            int pilihan;
            cout << "=========================" << endl;
            cout << "       TAMBAH MENU       " << endl;
            cout << "=========================" << endl;
            cout << "1. Tambah Menu Makanan" << endl;
            cout << "2. Tambah Menu Kopi" << endl;
            cout << "3. Tambah Menu Non Kopi" << endl;
            cout << "4. Tambah Menu Snack" << endl;
            cout << "5. Kembali" << endl;
            cout << "Pilih : ";
            cin >> pilihan;
            switch (pilihan)
            {
            case 1:
                tambah_menu_makanan();
                break;
            case 2:
                tambah_menu_kopi();
                break;
            case 3:
                tambah_menu_nonkopi();
                break;
            case 4:
                tambah_menu_snack();
                break;
            case 5:
                menu2();
                break;
            default:
                cout << "Pilihan tidak tersedia" << endl;
                break;
            }
        }



        /*  HAPUS MENU UNTUK PENJUAL */
        //hapus menu makanan dengan input nama kedalam array
        void hapus_menu_makanan()
        {
            string menu_makanan[10] = {"Nasi Goreng", "Nasi Goreng Pete", "Nasi Goreng Seafood", "Nasi Goreng Ayam", "Nasi Goreng Kambing", "Nasi Goreng Sapi", "Nasi Goreng Telur", "Nasi Goreng Sayur", "Nasi Goreng Bakso", "Nasi Goreng Sosis"};
            int harga_makanan[10] = {10000, 15000, 20000, 20000, 25000, 20000, 20000, 25000, 25000, 25000};
            string nama_makanan;
            cout << "Masukkan nama makanan : ";
            cin >> nama_makanan;
            for (int i = 0; i < 10; i++)
            {
                if (menu_makanan[i] == nama_makanan)
                {
                    menu_makanan[i] = "";
                    harga_makanan[i] = 0;
                    break;
                }
            }
            cout << "Menu berhasil dihapus" << endl;
            cout << endl;
        }

        //hapus menu kopi dengan input nama kedalam array
        void hapus_menu_kopi()
        {
            string menu_kopi[10] = {"Kopi Hitam", "Kopi Susu", "Kopi Tarik", "Kopi Hijau", "Kopi Manis", "Kopi Tawar", "Kopi Jahe", "Kopi Jeruk", "Kopi Lemon", "Kopi Chamomile"};
            int harga_kopi[10] = {10000, 15000, 20000, 20000, 25000, 20000, 20000, 25000, 25000, 25000};
            string nama_kopi;
            cout << "Masukkan nama kopi : ";
            cin >> nama_kopi;
            for (int i = 0; i < 10; i++)
            {
                if (menu_kopi[i] == nama_kopi)
                {
                    menu_kopi[i] = "";
                    harga_kopi[i] = 0;
                    break;
                }
            }
            cout << "Menu berhasil dihapus" << endl;
            cout << endl;
        }

        //hapus menu non kopi dengan input nama kedalam array
        void hapus_menu_nonkopi()
        {
            string menu_nonkopi[10] = {"Teh Hitam", "Teh Susu", "Teh Tarik", "Teh Hijau", "Teh Manis", "Teh Tawar", "Teh Jahe", "Teh Jeruk", "Teh Lemon", "Teh Chamomile"};
            int harga_nonkopi[10] = {10000, 15000, 20000, 20000, 25000, 20000, 20000, 25000, 25000, 25000};
            string nama_nonkopi;
            cout << "Masukkan nama non kopi : ";
            cin >> nama_nonkopi;
            for (int i = 0; i < 10; i++)
            {
                if (menu_nonkopi[i] == nama_nonkopi)
                {
                    menu_nonkopi[i] = "";
                    harga_nonkopi[i] = 0;
                    break;
                }
            }
            cout << "Menu berhasil dihapus" << endl;
            cout << endl;
        }

        //hapus menu snack dengan input nama kedalam array
        void hapus_menu_snack()
        {
            string menu_snack[10] = {"Keripik Kentang", "Keripik Singkong", "Keripik Pisang", "Keripik Tempe", "Keripik Tahu", "Keripik Bayam", "Keripik Wortel", "Keripik Jagung", "Keripik Brokoli", "Keripik Kacang"};
            int harga_snack[10] = {10000, 15000, 20000, 20000, 25000, 20000, 20000, 25000, 25000, 25000};
            string nama_snack;
            cout << "Masukkan nama snack : ";
            cin >> nama_snack;
            for (int i = 0; i < 10; i++)
            {
                if (menu_snack[i] == nama_snack)
                {
                    menu_snack[i] = "";
                    harga_snack[i] = 0;
                    break;
                }
            }
            cout << "Menu berhasil dihapus" << endl;
            cout << endl;
        }

        //switch case untuk menu hapus menu
        void hapusmenu()
        {
            int pilihan;
            cout << "=========================" << endl;
            cout << "         HAPUS MENU      " << endl;
            cout << "=========================" << endl;
            cout << "1. Hapus Menu Makanan" << endl;
            cout << "2. Hapus Menu Kopi" << endl;
            cout << "3. Hapus Menu Non Kopi" << endl;
            cout << "4. Hapus Menu Snack" << endl;
            cout << "5. Kembali" << endl;
            cout << "Pilih : ";
            cin >> pilihan;
            switch (pilihan)
            {
            case 1:
                hapus_menu_makanan();
                break;
            case 2:
                hapus_menu_kopi();
                break;
            case 3:
                hapus_menu_nonkopi();
                break;
            case 4:
                hapus_menu_snack();
                break;
            case 5:
                menu2();
                break;
            default:
                cout << "Pilihan tidak tersedia" << endl;
                break;
            }
        }



        /*  EDIT NAMA DAN HARGA MENU */
        //edit nama dan harga menu makanan dengan input nama dan harga kedalam array
        void edit_menu_makanan()
        {
            string menu_makanan[10] = {"Nasi Goreng", "Nasi Goreng Pete", "Nasi Goreng Seafood", "Nasi Goreng Kambing", "Nasi Goreng Ayam", "Nasi Goreng Sapi", "Nasi Goreng Telur", "Nasi Goreng Sayur", "Nasi Goreng Bakso", "Nasi Goreng Sosis"};
            int harga_makanan[10] = {10000, 15000, 20000, 20000, 25000, 20000, 20000, 25000, 25000, 25000};
            string nama_makanan;
            int harga;
            cout << "Masukkan nama makanan : ";
            cin >> nama_makanan;
            cout << "Masukkan harga makanan : ";
            cin >> harga;
            for (int i = 0; i < 10; i++)
            {
                if (menu_makanan[i] == nama_makanan)
                {
                    menu_makanan[i] = nama_makanan;
                    harga_makanan[i] = harga;
                    break;
                }
            }
            cout << "Menu berhasil diedit" << endl;
            cout << endl;
        }

        //edit nama dan harga menu kopi dengan input nama dan harga kedalam array
        void edit_menu_kopi()
        {
            string menu_kopi[10] = {"Kopi Hitam", "Kopi Susu", "Kopi Tarik", "Kopi Hijau", "Kopi Manis", "Kopi Tawar", "Kopi Jahe", "Kopi Jeruk", "Kopi Lemon", "Kopi Chamomile"};
            int harga_kopi[10] = {10000, 15000, 20000, 20000, 25000, 20000, 20000, 25000, 25000, 25000};
            string nama_kopi;
            int harga;
            cout << "Masukkan nama kopi : ";
            cin >> nama_kopi;
            cout << "Masukkan harga kopi : ";
            cin >> harga;
            for (int i = 0; i < 10; i++)
            {
                if (menu_kopi[i] == nama_kopi)
                {
                    menu_kopi[i] = nama_kopi;
                    harga_kopi[i] = harga;
                    break;
                }
            }
            cout << "Menu berhasil diedit" << endl;
            cout << endl;
        }

        //edit nama dan harga menu non kopi dengan input nama dan harga kedalam array
        void edit_menu_nonkopi()
        {
            string menu_nonkopi[10] = {"Teh Hitam", "Teh Susu", "Teh Tarik", "Teh Hijau", "Teh Manis", "Teh Tawar", "Teh Jahe", "Teh Jeruk", "Teh Lemon", "Teh Chamomile"};
            int harga_nonkopi[10] = {10000, 15000, 20000, 20000, 25000, 20000, 20000, 25000, 25000, 25000};
            string nama_nonkopi;
            int harga;
            cout << "Masukkan nama non kopi : ";
            cin >> nama_nonkopi;
            cout << "Masukkan harga non kopi : ";
            cin >> harga;
            for (int i = 0; i < 10; i++)
            {
                if (menu_nonkopi[i] == nama_nonkopi)
                {
                    menu_nonkopi[i] = nama_nonkopi;
                    harga_nonkopi[i] = harga;
                    break;
                }
            }
            cout << "Menu berhasil diedit" << endl;
            cout << endl;
        }

        //edit nama dan harga menu snack dengan input nama dan harga kedalam array
        void edit_menu_snack()
        {
            string menu_snack[10] = {"Keripik Kentang", "Keripik Singkong", "Keripik Pisang", "Keripik Tempe", "Keripik Bayam", "Keripik Wortel", "Keripik Jagung", "Keripik Ubi", "Keripik Terong", "Keripik Pare"};
            int harga_snack[10] = {10000, 15000, 20000, 20000, 25000, 20000, 20000, 25000, 25000, 25000};
            string nama_snack;
            int harga;
            cout << "Masukkan nama snack : ";
            cin >> nama_snack;
            cout << "Masukkan harga snack : ";
            cin >> harga;
            for (int i = 0; i < 10; i++)
            {
                if (menu_snack[i] == nama_snack)
                {
                    menu_snack[i] = nama_snack;
                    harga_snack[i] = harga;
                    break;
                }
            }
            cout << "Menu berhasil diedit" << endl;
            cout << endl;
        }

        //switch case untuk memilih menu yang akan diedit
        void editmenu()
        {
            int pilihan;
            cout << "Menu Edit" << endl;
            cout << "1. Edit Menu Makanan" << endl;
            cout << "2. Edit Menu Kopi" << endl;
            cout << "3. Edit Menu Non Kopi" << endl;
            cout << "4. Edit Menu Snack" << endl;
            cout << "5. Kembali" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            switch (pilihan)
            {
                case 1:
                    edit_menu_makanan();
                    break;
                case 2:
                    edit_menu_kopi();
                    break;
                case 3:
                    edit_menu_nonkopi();
                    break;
                case 4:
                    edit_menu_snack();
                    break;
                case 5:
                    menu2();
                    break;
            }
        }

        //menu 2 untuk penjual yang terdiri dari menambah menu, menghapus menu, melihat menu, dan mengedit harga dan menu, dan melihat struk, kembali ke menu 1
        void menu2()
        {
            int pilihan;
            cout << "Menu Penjual" << endl;
            cout << "1. Tambah Menu" << endl;
            cout << "2. Hapus Menu" << endl;
            cout << "3. Lihat Menu" << endl;
            cout << "4. Edit Menu" << endl;
            cout << "5. Lihat Struk" << endl;
            cout << "6. Kembali" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            switch (pilihan)
            {
                case 1:
                    tambahmenu();
                    break;
                case 2:
                    hapusmenu();
                    break;
                case 3:
                    lihatmenu();
                    break;
                case 4:
                    editmenu();
                    break;
                case 5:
                    printreceipt();
                    break;
                case 6:
                    menu1();
                    break;
                default:
                    cout << "Pilihan tidak tersedia" << endl;
                    break;
            }
        }





        /*  MENU 3 UNTUK PEMBELI */


        //menu 3 untuk pembeli yang terdiri dari melihat menu, memesan menu, mengedit pesanan, melihat struk, mencetak struk, dan kembali ke menu 1
        void menu3()
        {
            int pilihan;
            cout << "Menu Pembeli" << endl;
            cout << "1. Lihat Menu" << endl;
            cout << "2. Pesan Menu" << endl;
            cout << "3. Edit Pesanan" << endl;
            cout << "4. Cetak Struk" << endl;
            cout << "5. Kembali" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            switch (pilihan)
            {
                case 1:
                    lihatmenu();
                    break;
        /*        case 2:
                    pesanmenu();
                    break;
                case 3:
                    hapuspesanan();
                    break;*/
                case 4:
                    printreceipt();
                    break;
                case 5:
                    menu1();
                    break;
                default:
                    cout << "Pilihan tidak tersedia" << endl;
                    break;
            }
        }

                
        //fungsi untuk menjalankan program
        void run()
        {
            menu1();
        }
};

#endif