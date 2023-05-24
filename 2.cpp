#include <iostream>
#include "librarynew.h"

CoffeeShop cs;
    void tambahMenu()
    {
        string nama;
        int harga, qty;
        //menggunakan getline agar dapat menambahkan pesanan yang memiliki spasi
        cout << "Masukkan nama menu : ";
        cin.ignore();
        getline(cin, nama); 
        cout << "Masukkan harga menu : ";
        cin >> harga;
        cout << "Masukkan jumlah menu : ";
        cin >> qty;
        cs.addMenu(nama, harga, qty);
    } 

    void hapusOrder()
    {
        string nama;
        cout << "Masukkan nama menu untuk dihapus: ";
        //menggunakan getline agar dapat menghapus pesanan yang memiliki spasi
        cin.ignore();
        getline(cin, nama);
        cs.deleteOrder(nama);
    }

    void tampilOrder()
    {
        cs.displayOrder();
    }

    void cetakStruk()
    {
        int sub_total = 0;
        int PPN10 = 0;
        int total = 0;
        int tunai = 0;
        int kembalian = 0;

        cs.printReceipt(sub_total, PPN10, total, tunai, kembalian);
    }

    void tampilDaftarMenu()
    {
        cs.displayMenu();
    }
    //edit pesanan berdasarkan nama yang di input, kemudian mengganti nama, harga, dan qty
    void editPesanan()
    {
        string nama, namaBaru;
        int harga, qty;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Menggunakan cin.ignore() untuk membersihkan buffer
        cout << "Masukkan nama untuk diedit: ";
        getline(cin, nama);
        cout << "Masukkan nama baru: ";
        getline(cin, namaBaru);
        cout << "Masukkan harga baru: ";
        cin >> harga;
        cout << "Masukkan jumlah baru: ";
        cin >> qty;
        cs.editOrder(nama, namaBaru, harga, qty);
    }

    //Mencari pesanan berdasarkan nama
    void cariPesanan()
    {
        string nama;
        cout << "Masukkan nama menu yang dicari : ";
        //menggunakan getline agar dapat mencari pesanan yang memiliki spasi
        cin.ignore();
        getline(cin, nama);
        cs.searchOrder(nama);
    }

    //Mengurutkan pesanan berdasarkan total harga dari yang termurah menggunakan insertion sort
    void urutPesanan()
    {
        cs.sortOrder();
    }

    void statistikPesanan()
    {
        cs.statistikOrder();
    }


    void menu()
    {
        int pilihan, sub_total, PPN10, total, tunai, kembalian;
        do
        {
            cout << "=====================================" << endl;
            cout << "           WDF Coffee Haven" << endl;
            cout << "           Gang Jeruk No. 5" << endl;
            cout << "            Telp. 1500-212" << endl;
            cout << "=====================================" << endl;
            cout << "1. Tampilkan daftar menu" << endl;
            cout << "2. Tambah pesanan" << endl;
            cout << "3. Tampilkan Pesanan" << endl;
            cout << "4. Edit Pesanan" << endl;
            cout << "5. Hapus Pesanan" << endl;
            cout << "6. Cari Pesanan" << endl;
            cout << "7. Urutkan Pesanan" << endl;
            cout << "8. Cetak Struk" << endl;
            cout << "9. Statistik Pesanan" << endl;
            cout << "10. Keluar Program" << endl;
            cout << "=====================================" << endl;
            cout << "Masukkan pilihan : ";
            cin >> pilihan;
            cout << "=====================================" << endl;
            switch (pilihan)
            {
            case 1:
                tampilDaftarMenu();
                break;
            case 2:
                do
                {
                    tambahMenu();
                    cout << "Tambah pesanan lagi? (1. Ya, 2. Tidak) : ";
                    cin >> pilihan;
                } while (pilihan == 1);
                break;
            case 3:
                tampilOrder();
                break;
            case 4:
                editPesanan();
                cout << "Pesanan berhasil diedit" << endl;
                break;
            case 5:
                hapusOrder();
                cout << "Pesanan berhasil dihapus" << endl;
                break;
            case 6:
                cariPesanan();
                break;
            case 7:
                urutPesanan();
                cout << "Pesanan berhasil diurutkan" << endl;
                break;
            case 8:
                cetakStruk();
                break;
            case 9:
                cs.statistikOrder();
                break;
            case 10:
                cout << "\n\n\n";
                cout << "=====================================" << endl;
                cout << "~ ♡(^ᴗ^)♡ Terima kasih kamu ♡(^ᴗ^)♡ ~" << endl;
                cout << "=====================================" << endl;
                cout << "\n\n\n";
                break;
            default:
                cout << "Pilihan tidak tersedia" << endl;
                break;
            }
        } while (pilihan != 10);
    }

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}