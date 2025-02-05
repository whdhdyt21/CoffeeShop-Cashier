#ifndef LIBRARYNEW_H
#define LIBRARYNEW_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <limits>
#include <cstdlib>

using namespace std;

// Kelas CoffeeShop mengelola daftar pesanan menggunakan double linked list
class CoffeeShop {
private:
    struct Node {
        string name;
        int price;
        int quantity;
        Node* next;
        Node* prev;
        Node(const string &n, int p, int q) : name(n), price(p), quantity(q), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    // Konstruktor
    CoffeeShop() : head(nullptr), tail(nullptr) {}

    // Destruktor: Melepaskan semua node untuk menghindari memory leak
    ~CoffeeShop() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Menampilkan menu statis Coffee Shop
    void displayStaticMenu() const {
        cout << "\n\n=====================================" << endl;
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

    // Menambahkan pesanan ke akhir list
    void addOrder(const string &name, int price, int quantity) {
        Node* newNode = new Node(name, price, quantity);
        if (!head) {  // List kosong
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Menampilkan semua pesanan yang telah ditambahkan
    void displayOrders() const {
        cout << "\n\n---------- Daftar Pesanan ----------" << endl;
        cout << "=====================================" << endl;
        cout << "Menu" "\t\t" << "Qty" << "\t" << "Harga" << "\t" << "Total" << endl;
        cout << "-------------------------------------" << endl;
        Node* curr = head;
        while (curr) {
            cout << curr->name << "\t\t" 
                 << curr->quantity << "\t" 
                 << curr->price << "\t" 
                 << curr->price * curr->quantity << endl;
            curr = curr->next;
        }
        cout << "-------------------------------------" << endl << endl;
    }

    // Mengedit pesanan berdasarkan nama yang diberikan
    bool editOrder(const string &name, const string &newName, int newPrice, int newQuantity) {
        Node* curr = head;
        while (curr) {
            if (curr->name == name) {
                curr->name = newName;
                curr->price = newPrice;
                curr->quantity = newQuantity;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    // Menghapus pesanan berdasarkan nama yang diberikan
    bool deleteOrder(const string &name) {
        Node* curr = head;
        while (curr) {
            if (curr->name == name) {
                if (curr == head) {
                    head = curr->next;
                    if (head) head->prev = nullptr;
                    else tail = nullptr;
                } else if (curr == tail) {
                    tail = curr->prev;
                    if (tail) tail->next = nullptr;
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }
                delete curr;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    // Mencari pesanan berdasarkan nama dan menampilkan detailnya
    void searchOrder(const string &name) const {
        Node* curr = head;
        while (curr) {
            if (curr->name == name) {
                cout << "\n\n--------- Pesanan Ditemukan ---------" << endl;
                cout << "Nama Pesanan: " << curr->name << endl;
                cout << "Harga       : " << curr->price << endl;
                cout << "Qty         : " << curr->quantity << endl;
                cout << "Total       : " << curr->price * curr->quantity << endl;
                cout << "-------------------------------------" << endl << endl;
                return;
            }
            curr = curr->next;
        }
        cout << "Pesanan tidak ditemukan." << endl;
    }

    // Mengurutkan pesanan berdasarkan total harga menggunakan insertion sort
    void sortOrders() {
        if (!head) return;
        Node* curr = head->next;
        while (curr) {
            string name = curr->name;
            int price = curr->price;
            int quantity = curr->quantity;
            Node* pos = curr->prev;
            while (pos && (pos->price * pos->quantity) > (price * quantity)) {
                pos->next->name = pos->name;
                pos->next->price = pos->price;
                pos->next->quantity = pos->quantity;
                pos = pos->prev;
            }
            if (!pos) {
                head->name = name;
                head->price = price;
                head->quantity = quantity;
            } else {
                pos->next->name = name;
                pos->next->price = price;
                pos->next->quantity = quantity;
            }
            curr = curr->next;
        }
    }
};

#endif