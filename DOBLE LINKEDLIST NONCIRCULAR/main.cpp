#include <iostream>
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
    head->prev = NULL;
    head->next = NULL;
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
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// remoevdepan
void removedepan()
{
    del = head;
    head = head->next;
    head->prev = NULL;
    delete del;
}

// Fungsi untuk menghitung jumlah elemen dalam linked list
int countElements()
{
    int count = 0;
    bantu = head;
    while (bantu != NULL)
    {
        count++;
        bantu = bantu->next;
    }
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
    if (tail == NULL)
    {
        cout << "Linked list kosong." << endl;
        return;
    }

    bantu = tail;
    while (bantu != NULL)
    {
        cout << "Nama :" << bantu->nama << endl;
        cout << "nim :" << bantu->nim << endl;
        cout << "Nama buku :" << bantu->NamaBuku << endl;
        cout << "JumlahBuku :" << bantu->jumlahbuku << endl;
        cout << endl;
        bantu = bantu->prev;
    }
}

// print doblelinkedlist
void printDoublelinkedlist()
{

    bantu = head;
    while (bantu != NULL)
    {
        cout << "Nama :" << bantu->nama << endl;
        cout << "nim :" << bantu->nim << endl;
        cout << "Nama buku :" << bantu->NamaBuku << endl;
        cout << "JumlahBuku :" << bantu->jumlahbuku << endl;
        cout << endl;
        bantu = bantu->next;
    }
}

int main()
{
    createDoublelinked("Mustopa ", "333", "strukdat", 1);
    tambahdepan("elon ", "777", "space", 1);
    tambahdepan("markk ", "555", "fbb", 1);
    removedepan();

    editNode(head->next, "rudi ", "222", "mtk", 3);
    printDoublelinkedlist();
    printListReverse();

    int jumlah = countElements();
    cout << "jumlah element " << jumlah;
}
