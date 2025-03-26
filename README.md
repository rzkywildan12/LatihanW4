# A. Deskripsi Lengkap Program antrianQueue.cpp
---
## 📌1. STRUKTUR PROGRAM
Program ini terdiri dari beberapa bagian utama :
<br>**1. Library yang digunakan**
```
#include <iostream>
#include <queue>
#include <string>
```
* `#include <iostream>` &rarr; Digunakan untuk operasi input-output.
* `#include <queue>` &rarr; Digunakan untuk memanfaatkan struktur data queue.
* `#include <string>` &rarr; Digunakan untuk menangai input berupa string (nama pelanggan)
---
## 📌2. STRUKTUR DATA UNTUK MENYIMPAN INFORMASI PELANGGAN
```
struct Customer {
    int number;
    string name;
};
```
* `Customer` &rarr; Adalah struct yang menyimpan informasi pelanggan :
* `number` &rarr; Berguna untuk menyimpan nomor antrian pelanggan
* `name` &rarr; Berguna untuk menyimpan nama pelanggan
---
## 📌3. VARIABEL GLOBAL
```
queue<Customer> customerQueue;
int customerCounter = 1;
```
* `customerQueue` &rarr; Queuue untuk menyimpan daftar pelanggan.
* `customerCounter` &rarr; Variabel counter untuk memberikan nomor antrian secara otomatis
--- 
## 📌4. FUNGSI UNTUK MENGELOLA ANTRIAN
**🔷a). Fungsi untuk menambah pelanggan ke antrian**
```
void addCustomer() {
   Customer newCustomer;
   newCustomer.number = cusomerCounter;
   cout << "Masukan nama pelanggan: ";
   cin.ignore();
   getline(cin, newCustomer.name);
   customerQueue.push(newCustomer);
   cout << " Pelanggan" <<newCustomer.name << " dengan nomor antrian " << newCustomer.number << " telah ditambahkan.\n";
}
```
* Membuat pelanggan baru dengan nomor antrian otomatis (`customerCounter`).
* Meminta input nama pelanggan menggunakan `getline(vin, newCustomer.name)`.
* Menambahkan pelanggan ke queue menggunakan `customerQueue.push(newCustomer)`.
* Menampilkan konfirmasi bahwa pelanggan telah ditambahkan.
--- 
**🔷b). Fungsi untuk melayani pelanggan**
```
void serverCustomer() {
   if (customerQueue.empty()) {
       cout << "Tidak ada pelanggan dalam antrian.\n";
       return;
}
Customer servedCustomer = customerQueue.front();
customerQueue.pop();
cout << "Melayani pelanggan: " << servedCustomer.name << " (Nomor " << servedCustomer.number << ")\n";
```
* Memeriksa apakah antrian kosong. Jika kosong, program akan menampilkan pesan "Tidak ada pelanggan dalam antrian".
* Mengambil pelanggan pertama dalam antrian (`customerQueue.front()` ).
* Menghapus pelanggan dari antrian setelah dilayani (`customerQueue.pop()` ).
* Menampilkan informasi pelanggan yang sedang dilayani.
--- 
**🔷c). Fungsi untuk menampilkan daftar antrian**
```
void displayQueue() {
   if (customerQueue.empty()) {
      cout << "Antrian kosong.\n";
      return;
} 
queue<Customer> tempQueue = customerQueue;
cout << "Daftar antrian pelanggan: \n";
while (!tempQueue.empty()) {
    Customer c = tempQueue.front();
    cout << "Nomor" << c.number << " - " << c.name << "\n";
    tempQueue.pop();
  }
}
```
* Memeriksa apakah antrian kosong. jika ya, program akan menampilkan pesan "Antrian kosong".
* Menggunakan queue sementara (`tempQueue`) agar tidak mengubah queue utama saat menampilakn antrian
* Menampilkan daftar pelanggan yang sedang menunggu dalam antrian.
--- 
## 📌5. FUNGSI `main()` (Menu Utama) 
```
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
```
* Menampilkan menu pilihan untuk pengguna
* Meminta input pengguna (`cin >> choice`)
* Menggunakan switch-case untuk menangani pilihan :
  * `1` &rarr; Menambahkan pelanggan (`addCustomer()`).
  * `2` &rarr; Melayani pelanggan (`servercustomer()`).
  * `3` &rarr; Menampilkan daftar antrian (`displayQueue()`).
  * `4` &rarr; Keluar dari program.
  * Pilihan selain 1-4 akan menampilkan "Pesan tidak valid, coba lagi".
--- 
**Contoh Eksekusi Program**
<br>Contoh 1 : Menambahkan Pelanggan
```
Sistem Antrian Bank/Rumah Sakit
1. Tambah pelanggan
2. Layani pelanggan
3. Tamppilkan antrian
4. Keluar
Pilihan : 1
Masukan nama pelanggan : Andi
Pelanggan Andi dengan nomor antrian 1 telah ditambahkan.
```
<br>Contoh 2 : Menampilkan Antrian<br />






