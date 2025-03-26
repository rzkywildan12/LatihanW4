#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Customer {
    int number;
    string name;
};

queue<Customer> customerQueue;
int customerCounter = 1;

void addCustomer() {
    Customer newCustomer;
    newCustomer.number = customerCounter++;
    cout << "Masukkan nama pelanggan: ";
    cin.ignore();
    getline(cin, newCustomer.name);
    customerQueue.push(newCustomer);
    cout << "Pelanggan " << newCustomer.name << " dengan nomor antrian " << newCustomer.number << " telah ditambahkan.\n";
}

void serveCustomer() {
    if (customerQueue.empty()) {
        cout << "Tidak ada pelanggan dalam antrian.\n";
        return;
    }
    Customer servedCustomer = customerQueue.front();
    customerQueue.pop();
    cout << "Melayani pelanggan: " << servedCustomer.name << " (Nomor " << servedCustomer.number << ")\n";
}

void displayQueue() {
    if (customerQueue.empty()) {
        cout << "Antrian kosong.\n";
        return;
    }
    queue<Customer> tempQueue = customerQueue;
    cout << "Daftar antrian pelanggan: \n";
    while (!tempQueue.empty()) {
        Customer c = tempQueue.front();
        cout << "Nomor " << c.number << " - " << c.name << "\n";
        tempQueue.pop();
    }
}

int main() {
    int choice;
    do {
        cout << "\nSistem Antrian Bank/Rumah Sakit\n";
        cout << "1. Tambah pelanggan\n";
        cout << "2. Layani pelanggan\n";
        cout << "3. Tampilkan antrian\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                serveCustomer();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid, coba lagi.\n";
        }
    } while (choice != 4);
    
    return 0;
}
