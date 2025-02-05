#include <iostream>
#include "librarynew.h"

using namespace std;

void displayMenu() {
    cout << "\n=====================================" << endl;
    cout << "       Aplikasi Coffee Shop" << endl;
    cout << "=====================================" << endl;
    cout << "1. Tampilkan Menu" << endl;
    cout << "2. Tambah Pesanan" << endl;
    cout << "3. Tampilkan Pesanan" << endl;
    cout << "4. Edit Pesanan" << endl;
    cout << "5. Hapus Pesanan" << endl;
    cout << "6. Cari Pesanan" << endl;
    cout << "7. Urutkan Pesanan" << endl;
    cout << "8. Keluar" << endl;
    cout << "=====================================" << endl;
    cout << "Pilih menu: ";
}

int main() {
    CoffeeShop shop;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                shop.displayStaticMenu();
                break;
            case 2: {
                string name;
                int price, quantity;
                cout << "Masukkan Nama Pesanan: ";
                getline(cin, name);
                cout << "Masukkan Harga: ";
                cin >> price;
                cout << "Masukkan Jumlah: ";
                cin >> quantity;
                shop.addOrder(name, price, quantity);
                cout << "Pesanan berhasil ditambahkan!" << endl;
                break;
            }
            case 3:
                shop.displayOrders();
                break;
            case 4: {
                string name, newName;
                int newPrice, newQuantity;
                cout << "Masukkan Nama Pesanan yang Ingin Diedit: ";
                getline(cin, name);
                cout << "Masukkan Nama Baru: ";
                getline(cin, newName);
                cout << "Masukkan Harga Baru: ";
                cin >> newPrice;
                cout << "Masukkan Jumlah Baru: ";
                cin >> newQuantity;
                if (shop.editOrder(name, newName, newPrice, newQuantity))
                    cout << "Pesanan berhasil diperbarui!" << endl;
                else
                    cout << "Pesanan tidak ditemukan!" << endl;
                break;
            }
            case 5: {
                string name;
                cout << "Masukkan Nama Pesanan yang Ingin Dihapus: ";
                getline(cin, name);
                if (shop.deleteOrder(name))
                    cout << "Pesanan berhasil dihapus!" << endl;
                else
                    cout << "Pesanan tidak ditemukan!" << endl;
                break;
            }
            case 6: {
                string name;
                cout << "Masukkan Nama Pesanan yang Dicari: ";
                getline(cin, name);
                shop.searchOrder(name);
                break;
            }
            case 7:
                shop.sortOrders();
                cout << "Pesanan berhasil diurutkan berdasarkan total harga!" << endl;
                break;
            case 8:
                cout << "Terima kasih telah menggunakan aplikasi ini!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
        }
    } while (choice != 8);

    return 0;
}
