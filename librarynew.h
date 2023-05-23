#ifndef LIBRARYNEW_H
#define LIBRARYNEW_H
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

// Sistem Program Kasir di Cafeshop
struct WDF
{
    string nama;
    int harga;
    int qty;
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

    // fungsi untuk kode struk random angka dan huruf
    int kodestruk(int min, int max)
    {
        srand(time(NULL));
        int kodestruk = rand() % (max - min + 1) + min;
        return kodestruk;
    }

    // fungsi untuk nomor meja
    void nomor_meja()
    {
        int no_meja;
        cout << "No.Meja    : ";
        cin >> no_meja;
    }

    // waktu sekarang
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

    // fungsi untuk mencetak struk
    void printReceipt(int sub_total, int& PPN10, int& total, int& tunai, int& kembalian)
    {
        cout << "=====================================" << endl;
        cout << "           WDF Coffee Haven" << endl;
        cout << "           Gang Jeruk No. 5" << endl;
        cout << "            Telp. 1500-212" << endl;
        cout << "=====================================" << endl;
        cout << "Kode Struk : " << kodestruk(1000, 9999) << endl;
        nomor_meja();
        waktu();
        cout << "=====================================" << endl;
        cout << "Menu" "\t\t" << "Qty" << "\t" << "Harga" << "\t" << "Total" << endl;
        cout << "-------------------------------------" << endl;
        // Tampilkan menu yang dipesan
        WDF *curr = head;
        while (curr != NULL)
        {
            cout << curr->nama << "\t\t" << curr->qty << "\t" << curr->harga << "\t" << curr->qty * curr->harga << endl;
            sub_total += (curr->qty * curr->harga);
            curr = curr->next;
        }
        cout << "-------------------------------------" << endl;
        PPN10 = sub_total * 0.1;
        total = sub_total + PPN10;

        // Menampilkan sub total, ppn, total, tunai, kembalian
        cout << "Sub Total\t\t\t" << sub_total << endl;
        cout << "PPN 10%\t\t\t\t" << PPN10 << endl;
        cout << "Total\t\t\t\t" << total << endl;
        cout << "Masukkan Uang\t\t\t";
        cin >> tunai;
        kembalian = tunai - total;
        cout << "Kembalian\t\t\t" << kembalian << endl;
        cout << "=====================================" << endl;
        cout << " ~ Brewing Love, Serving Happiness ~ " << endl;
        cout << "        ( ＾◡＾)◞ ♥ ◟(＾◡＾✿)" << endl;
        cout << "=====================================" << endl;
    }

    void addMenu(string nama, int harga, int qty)
    {
        WDF *baru = new WDF;
        baru->nama = nama;
        baru->harga = harga;
        baru->qty = qty;
        baru->next = NULL;
        baru->prev = NULL;
        if (head == NULL)
        {
            head = baru;
            tail = baru;
        }
        else
        {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }

    void deleteOrder(string nama)
    {
        WDF *curr = head;
        while (curr != NULL)
        {
            if (curr->nama == nama)
            {
                if (curr == head)
                {
                    head = curr->next;
                    head->prev = NULL;
                    delete curr;
                    break;
                }
                else if (curr == tail)
                {
                    tail = curr->prev;
                    tail->next = NULL;
                    delete curr;
                    break;
                }
                else
                {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    delete curr;
                    break;
                }
            }
            curr = curr->next;
        }
    }

    //fungsi untuk melihat daftar menu
    void displayOrder()
    {
        cout << "=====================================" << endl;
        cout << "           WDF Coffee Haven" << endl;
        
        cout << "            Telp. 1500-212" << endl;
        cout << "=====================================" << endl;
        cout << "Menu" "\t\t" << "Qty" << "\t" << "Harga" << "\t" << "Total" << endl;
        cout<< "-------------------------------------" << endl;
        //tampilkan menu yang dipesan
        WDF *curr = head;
        while (curr != NULL)
        {
            cout << curr->nama << "\t\t" << curr->qty << "\t" << curr->harga << "\t" << curr->qty * curr->harga << endl;
            curr = curr->next;
        }
        cout << "-------------------------------------" << endl;
    }

    void displayMenu()
    {
        cout << "=====================================" << endl;
        cout << "           WDF Coffee Haven" << endl;
        cout << "           Gang Jeruk No. 5" << endl;
        cout << "            Telp. 1500-212" << endl;
        cout << "=====================================" << endl;
        cout << "Menu" "\t\t" << "Harga" << endl;
        cout << "-------------------------------------" << endl;
        cout << "1. Espresso" << "\t\t" << "Rp. 20.000" << endl;
        cout << "2. Cappucino" << "\t\t" << "Rp. 25.000" << endl;
        cout << "3. Caffe Latte" << "\t\t" << "Rp. 25.000" << endl;
        cout << "4. Caffe Mocha" << "\t\t" << "Rp. 30.000" << endl;
        cout << "5. Caramel Macchiato" << "\t" << "Rp. 30.000" << endl;
        cout << "6. Caffe Americano" << "\t" << "Rp. 20.000" << endl;
        cout << "7. Caffe Flat White" << "\t" << "Rp. 25.000" << endl;
        cout << "8. Caffe Vienna" << "\t\t" << "Rp. 25.000" << endl;
        cout << "9. Caffe Mocha" << "\t\t" << "Rp. 30.000" << endl;
        cout << "10. Caffe Vienna" << "\t\t" << "Rp. 25.000" << endl;
        cout << "11. Caffe Mocha" << "\t\t" << "Rp. 30.000" << endl;
        cout << "12. Caffe Vienna" << "\t\t" << "Rp. 25.000" << endl;
        cout << "13. Caffe Mocha" << "\t\t" << "Rp. 30.000" << endl;
        cout << "14. Caffe Vienna" << "\t\t" << "Rp. 25.000" << endl;
        cout << "15. Caffe Mocha" << "\t\t" << "Rp. 30.000" << endl;
        cout << "-------------------------------------" << endl;
        cout << "=====================================" << endl;
    }

    //edit pesanan berdasarkan nama yang di input, kemudian mengganti nama, harga, dan qty
    void editOrder(string nama, string namaBaru, int hargaBaru, int qtyBaru)
    {
        WDF *curr = head;
        while (curr != NULL)
        {
            if (curr->nama == nama)
            {
                curr->nama = namaBaru;
                curr->harga = hargaBaru;
                curr->qty = qtyBaru;
                break;
            }
            curr = curr->next;
        }
    }
    
    //mencari order berdasarkan nama
    void searchOrder(string nama)
    {
        WDF *curr = head;
        while (curr != NULL)
        {
            if (curr->nama == nama)
            {
                cout << "------- Pesanan Ditemukan -------" << endl;
                cout << "Nama Menu\t\t\t" << curr->nama << endl;
                cout << "Harga\t\t\t\t" << curr->harga << endl;
                cout << "Qty\t\t\t\t" << curr->qty << endl;
                cout << "Total\t\t\t\t" << curr->harga * curr->qty << endl;
                cout << "---------------------------------" << endl;
                break;
            }
            curr = curr->next;
        }
    }

    //Mengurutkan pesanan berdasarkan total dari yang termurah menggunakan insertion sort
    void sortOrder()
    {
        WDF *curr = head;
        WDF *temp = NULL;
        while (curr != NULL)
        {
            temp = curr->next;
            while (temp != NULL)
            {
                if (curr->harga * curr->qty > temp->harga * temp->qty)
                {
                    string nama = curr->nama;
                    int harga = curr->harga;
                    int qty = curr->qty;
                    curr->nama = temp->nama;
                    curr->harga = temp->harga;
                    curr->qty = temp->qty;
                    temp->nama = nama;
                    temp->harga = harga;
                    temp->qty = qty;
                }
                temp = temp->next;
            }
            curr = curr->next;
        }
    }
};


#endif