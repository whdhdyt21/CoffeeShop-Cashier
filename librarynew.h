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

    // fungsi untuk menampilkan menu di CoffeeShop
    void displayMenu()
    {
        cout << endl << endl;
        cout << "=====================================" << endl;
        cout << "           WDF Coffee Haven" << endl;
        cout << "           Gang Jeruk No. 5" << endl;
        cout << "            Telp. 1500-212" << endl;
        cout << "=====================================" << endl;
        cout << "Menu" "\t\t\t\t" << "Harga" << endl;
        cout << "=====================================" << endl;
        cout << "~~~~~~~~~~~~~ Kopi :) ~~~~~~~~~~~~~~~" << endl;
        cout << "1. Espresso" << "\t\t\t" << "15000" << endl;
        cout << "2. Cappucino" << "\t\t\t" << "20000" << endl;
        cout << "3. Latte" << "\t\t\t" << "20000" << endl;
        cout << "4. Mocha" << "\t\t\t" << "25000" << endl;
        cout << "5. Americano" << "\t\t\t" << "15000" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
        cout << "~~~~~~~~~~~~~ Snack :) ~~~~~~~~~~~~~~" << endl;
        cout << "1. Donut" << "\t\t\t" << "10000" << endl;
        cout << "2. Brownies" << "\t\t\t" << "15000" << endl;
        cout << "3. Cookies" << "\t\t\t" << "10000" << endl;
        cout << "4. Pie" << "\t\t\t\t" << "20000" << endl;
        cout << "5. Cake" << "\t\t\t\t" << "25000" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "=====================================" << endl << endl << endl;
    }

    // fungsi untuk menambahkan menu
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

    //fungsi untuk melihat daftar pesanan yang telah dipesan
    void displayOrder()
    {
        cout << endl << endl;
        cout << "---------- Daftar Pesanan  ----------" << endl;
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
        cout << "-------------------------------------" << endl << endl << endl;
    }

    //fungsi untuk mengedit pesanan berdasarkan nama
    void editOrder(string nama, string namaBaru, int hargaBaru, int qtyBaru)
    {
        WDF* curr = head;
        while (curr != NULL)
        {
            if (curr->nama == nama)
            {
                curr->nama = namaBaru;
                curr->harga = hargaBaru;
                curr->qty = qtyBaru;
                return; // Menggunakan return untuk keluar dari fungsi setelah mengedit pesanan
            }
        curr = curr->next;
        }
        cout << "Pesanan tidak ditemukan." << endl; // Menambahkan pesan jika pesanan tidak ditemukan
    }

    // fungsi untuk menghapus menu
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

    //fungsi untuk mencari pesanan berdasarkan nama
    void searchOrder(string nama)
    {
        WDF *curr = head;
        while (curr != NULL)
        {
            if (curr->nama == nama)
            {
                cout << endl << endl;
                cout << "--------- Pesanan Ditemukan ---------" << endl;
                cout << "Nama Pesanan" "\t\t\t" << curr->nama << endl;
                cout << "Harga" "\t\t\t\t" << curr->harga << endl;
                cout << "Qty" "\t\t\t\t" << curr->qty << endl;
                cout << "Total" "\t\t\t\t" << curr->harga * curr->qty << endl;
                cout << "-------------------------------------" << endl << endl << endl;
                break;
            }
            curr = curr->next;
        }
        if (curr == NULL)
        {
            cout << "Pesanan tidak ditemukan." << endl;
        }
    }

    //fungsi untuk mengurutkan pesanan berdasarkan harga total termurah menggunakan insertion sort
    void sortOrder()
    {
        WDF *curr = head;
        while (curr != NULL)
        {
            string nama = curr->nama;
            int harga = curr->harga;
            int qty = curr->qty;
            WDF *temp = curr->prev;
            while (temp != NULL && (temp->harga * temp->qty) > (harga * qty))
            {
                temp->next->nama = temp->nama;
                temp->next->harga = temp->harga;
                temp->next->qty = temp->qty;
                temp = temp->prev;
            }
            if (temp == NULL)
            {
                head->nama = nama;
                head->harga = harga;
                head->qty = qty;
            }
            else
            {
                temp->next->nama = nama;
                temp->next->harga = harga;
                temp->next->qty = qty;
            }
            curr = curr->next;
        }
    }

/*-------------------------------- Tampilan untuk struk --------------------------------*/

    // fungsi untuk kode struk random angka 4 digit
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

    // fungsi untuk waktu saat ini
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
        cout << endl << endl << endl;
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
        cout << "=====================================" << endl << endl << endl;
    }

/*--------------------------------------------------------------------------------------*/

    //fungsi untuk melihat statistik pesanan berdasarkan 
    //harga total, total pesanan, harga pesanan termurah, harga pesanan termahal, jumlah pesanan terbanyak, dan jumlah pesanan tersedikit
    void statistikOrder()
    {
        WDF *curr = head;
        int min = curr->harga * curr->qty;
        int max = curr->harga * curr->qty;
        int total = 0;
        int count = 0;
        int minQty = curr->qty;
        int maxQty = curr->qty;
        string minNama = curr->nama;
        string maxNama = curr->nama;
        string minQtyNama = curr->nama;
        string maxQtyNama = curr->nama;
        while (curr != NULL)
        {
            total += curr->harga * curr->qty;
            count += curr->qty;
            if ((curr->harga * curr->qty) < min)
            {
                min = curr->harga * curr->qty;
                minNama = curr->nama;
            }
            if ((curr->harga * curr->qty) > max)
            {
                max = curr->harga * curr->qty;
                maxNama = curr->nama;
            }
            if (curr->qty < minQty)
            {
                minQty = curr->qty;
                minQtyNama = curr->nama;
            }
            if (curr->qty > maxQty)
            {
                maxQty = curr->qty;
                maxQtyNama = curr->nama;
            }
            curr = curr->next;
        }
        cout << endl << endl;
        cout << "=====================================" << endl;
        cout << "           WDF Coffee Haven" << endl;
        cout << "           Gang Jeruk No. 5" << endl;
        cout << "            Telp. 1500-212" << endl;
        cout << "=====================================" << endl;
        cout << "Total Penjualan" "\t\t\t" << total << endl;
        cout << "Total Pesanan" "\t\t\t" << count << endl;
        cout << "Pesanan Termurah" "\t" << minNama << " - " << min << endl;
        cout << "Pesanan Termahal" "\t" << maxNama << " - " << max << endl;
        cout << "Pesanan Terbanyak" "\t" << maxQtyNama << " - " << maxQty << endl;
        cout << "Pesanan Tersedikit" "\t" << minQtyNama << " - " << minQty << endl;
        cout << "=====================================" << endl << endl << endl;
    }   
};


#endif