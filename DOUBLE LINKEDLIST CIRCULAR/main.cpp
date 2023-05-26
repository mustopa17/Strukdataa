#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

// deklarasi

struct DataPeminjamanBuku
{
    string nama, nim, NamaBuku;
    int jumlahbuku;

    DataPeminjamanBuku *next;
    DataPeminjamanBuku *prev;
};

DataPeminjamanBuku *head, *tail, *bantu, *newNode, *del;
void createDoublelinked(string nama, string nim, string NamaBuku, int jumlahbuku)
{
    head = new DataPeminjamanBuku();
    head->nama = nama;
    head->nim = nim;
    head->jumlahbuku = jumlahbuku;
    head->NamaBuku = NamaBuku;

    head->prev = head;
    head->next = head;
    tail = head;
}

// tambah depan
void tambahdepan(string nama, string nim, string NamaBuku, int jumlahbuku)
{
    newNode = new DataPeminjamanBuku();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->jumlahbuku = jumlahbuku;
    newNode->NamaBuku = NamaBuku;

    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
}

// remoevdepan
void removedepan()
{
    del = head;
    head = head->next;
    head->prev = tail;

    delete del;
}

// Fungsi untuk menghitung jumlah elemen dalam linked list
int countElements()
{
    int count = 0;
    bantu = head;

    do
    {
        count++;
        bantu = bantu->next;
    } while (bantu != head);

    return count;
}

// FUNGSI EDIT
void editNode(DataPeminjamanBuku *node, string newNama, string newNim, string newBuku, int newJumlah)
{
    if (node == NULL)
    {
        cout << "Node tidak valid." << endl;
        return;
    }

    node->nama = newNama;
    node->nim = newNim;
    node->NamaBuku = newBuku;
    node->jumlahbuku = newJumlah;
}

// PRINT DARI BELAKANG
void printListReverse()
{

    bantu = tail;

    do
    {
        cout << "Nama :" << bantu->nama << endl;
        cout << "nim :" << bantu->nim << endl;
        cout << "Nama buku :" << bantu->NamaBuku << endl;
        cout << "JumlahBuku :" << bantu->jumlahbuku << endl;
        cout << endl;
        bantu = bantu->next;
    } while (bantu != tail);
}

// print doblelinkedlist
void printDoublelinkedlist()
{

    bantu = head;

    do
    {
        cout << "Nama :" << bantu->nama << endl;
        cout << "nim :" << bantu->nim << endl;
        cout << "Nama buku :" << bantu->NamaBuku << endl;
        cout << "JumlahBuku :" << bantu->jumlahbuku << endl;
        cout << endl;
        bantu = bantu->next;
    } while (bantu != head);
}

// search data
bool searchByHead(string nama)
{
    bantu = head;

    do
    {
        if (bantu->nama == nama)
            return true;

        bantu = bantu->next;
    } while (bantu != head);

    return false;
}

// menghapus node tertentu
void removeByname(string nama)
{
    if (head->nama == nama)
    {
        if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            DataPeminjamanBuku *temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }
        cout << "Data berhasil dihapus." << endl;
        return;
    }
    bantu = head->next;
    while (bantu != head)
    {
        if (bantu->nama == nama)
        {
            bantu->prev->next = bantu->next;
            bantu->next->prev = bantu->prev;
            delete bantu;
            cout << "Data berhasil dihapus." << endl;
            return;
        }
        bantu = bantu->next;
    }
    cout << "Data tidak ditemukan." << endl;
}

int main()
{
    int totalElements;

    string nama, nim, NamaBuku, hapus;
    int jumlahbuku;

    createDoublelinked("Mustopa", "3333", "admmin", 1);

    bool exitLoop = false;
    while (!exitLoop)
    {
        cout << "Menu:" << endl;
        cout << "1. Tambah Depan Data Peminjaman" << endl;
        cout << "2. Hapus  Data By Nama Peminjaman" << endl;
        cout << "3. Tampilkan Data Peminjaman" << endl;
        cout << "4. Edit Data Peminjaman" << endl;
        cout << "5. Tampilkan Data Peminjaman Terbalik" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu: ";

        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            cout << "Masukkan data peminjaman baru:" << endl;
            cout << "Nama: ";
            getline(cin, nama);
            cout << "NIM: ";
            getline(cin, nim);
            cout << "Nama Buku: ";
            getline(cin, NamaBuku);
            cout << "Jumlah Buku: ";
            cin >> jumlahbuku;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            tambahdepan(nama, nim, NamaBuku, jumlahbuku);
            system("cls");
            cout << "Data peminjaman ditambahkan." << endl;
            break;
        case 2:
            cout << "Nama yang akan di hapus : ";
            getline(cin, hapus);
            system("cls");
            removeByname(hapus);
            break;
        case 3:
            system("cls");
            cout << "\nTampilan Data Peminjaman:" << endl;
            printDoublelinkedlist();
            totalElements = countElements();
            cout << "Jumlah elemen dalam linked list: " << totalElements << endl;
            break;

        case 4:
            if (head == NULL)
            {
                cout << "Linked list kosong." << endl;
            }
            else
            {
                int index;
                cout << "Masukkan indeks data peminjaman yang akan diedit: ";
                cin >> index;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (index < 1 || index > countElements())
                {
                    cout << "Indeks tidak valid." << endl;
                }
                else
                {
                    bantu = head;
                    for (int i = 1; i < index; i++)
                    {
                        bantu = bantu->next;
                    }

                    string newNama, newNim, newBuku;
                    int newJumlah;

                    cout << "Masukkan data peminjaman yang baru:" << endl;
                    cout << "Nama: ";
                    getline(cin, newNama);
                    cout << "NIM: ";
                    getline(cin, newNim);
                    cout << "Nama Buku: ";
                    getline(cin, newBuku);
                    cout << "Jumlah Buku: ";
                    cin >> newJumlah;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    editNode(bantu, newNama, newNim, newBuku, newJumlah);
                    system("cls");
                    cout << "Data peminjaman diindeks " << index << " berhasil diubah." << endl;
                }
            }
            break;
        case 5:
            system("cls");
            cout << "\nTampilan Data Peminjaman Terbalik:" << endl;
            printListReverse();
            totalElements = countElements();
            cout << "Jumlah elemen dalam linked list: " << totalElements << endl;
            break;
            break;
        case 6:
            exitLoop = true;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
