#include <iostream>
#include "librarynew.h"

CoffeeShop cs;
    void tambahMenu()
    {
        string nama;
        int harga, qty;
        cout << "Masukkan nama menu : ";
        cin >> nama;
        cout << "Masukkan harga menu : ";
        cin >> harga;
        cout << "Masukkan jumlah menu : ";
        cin >> qty;
        cs.addMenu(nama, harga, qty);
    } 

    void hapusOrder()
    {
        string nama;
        cout << "Masukkan nama menu : ";
        cin >> nama;
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
            cout << "1. Tambah Menu" << endl;
            cout << "2. Hapus Order" << endl;
            cout << "3. Tampilkan Order" << endl;
            cout << "4. Cetak Struk" << endl;
            cout << "5. Exit" << endl;
            cout << "=====================================" << endl;
            cout << "Masukkan pilihan : ";
            cin >> pilihan;
            switch (pilihan)
            {
            case 1:
                tambahMenu();
                break;
            case 2:
                hapusOrder();
                break;
            case 3:
                tampilOrder();
                break;
            case 4:
                cetakStruk();
                break;
            case 5:
                cout << "Terima kasih telah berkunjung di WDF Coffee Haven" << endl;
                break;
            default:
                cout << "Pilihan tidak tersedia" << endl;
                break;
            }
        } while (pilihan != 5);
    }




int main(int argc, char const *argv[])
{
    menu();
    return 0;
}