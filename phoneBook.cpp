#include <iostream>
#include <string>
using namespace std;

const int MAX_CONTACTS = 100;

struct Contact {
    string name;
    string phone;
};

class Phonebook {
private:
    Contact contacts[MAX_CONTACTS];
    int count;

public:
    Phonebook() : count(0) {}

    void addContact(const string& name, const string& phone) {
        if (count < MAX_CONTACTS) {
            contacts[count].name = name;
            contacts[count].phone = phone;
            count++;
            cout << "Kontak berhasil ditambahkan!\n";
        } else {
            cout << "Phonebook penuh! Tidak dapat menambahkan kontak lagi.\n";
        }
    }

    void displayContacts() {
        if (count == 0) {
            cout << "Phonebook kosong!\n";
            return;
        }
        cout << "Daftar Kontak:\n";
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << contacts[i].name << " - " << contacts[i].phone << endl;
        }
    }

    void searchContact(const string& name) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (contacts[i].name == name) {
                cout << "Kontak ditemukan: " << contacts[i].name << " - " << contacts[i].phone << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Kontak tidak ditemukan.\n";
        }
    }

    void deleteContact(const string& name) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (contacts[i].name == name) {
                for (int j = i; j < count - 1; j++) {
                    contacts[j] = contacts[j + 1];
                }
                count--;
                cout << "Kontak berhasil dihapus!\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Kontak tidak ditemukan.\n";
        }
    }
};

int main() {
    Phonebook pb;
    int choice;
    string name, phone;

    do {
        cout << "\nSistem Manajemen Kontak:\n";
        cout << "1. Tambah Kontak\n";
        cout << "2. Tampilkan Kontak\n";
        cout << "3. Cari Kontak\n";
        cout << "4. Hapus Kontak\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Masukkan nama: ";
                getline(cin, name);
                cout << "Masukkan nomor telepon: ";
                getline(cin, phone);
                pb.addContact(name, phone);
                break;
            case 2:
                pb.displayContacts();
                break;
            case 3:
                cout << "Masukkan nama untuk mencari: ";
                getline(cin, name);
                pb.searchContact(name);
                break;
            case 4:
                cout << "Masukkan nama untuk dihapus: ";
                getline(cin, name);
                pb.deleteContact(name);
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 5);

    return 0;
}
