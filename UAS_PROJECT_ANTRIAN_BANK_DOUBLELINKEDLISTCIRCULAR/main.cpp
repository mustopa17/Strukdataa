#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

// deklarasi

struct AntrianBank
{
    string nama;

    AntrianBank *next;
    AntrianBank *prev;
};

AntrianBank *head, *tail, *bantu, *newNode, *del;
void createDoublelinked(string nama)
{
    head = new AntrianBank();
    head->nama = nama;

    head->prev = head;
    head->next = head;
    tail = head;
}

// tambah depan
void tambahpelanggandepan(string nama)
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat!!!";
    }
    else
    {
        newNode = new AntrianBank();
        newNode->nama = nama;

        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
}

void tambahpelangganbelakang(string nama)
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat!!!";
    }
    else
    {
        newNode = new AntrianBank();
        newNode->nama = nama;

        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

// remoevdepan
void hapusdepan()
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat!!!";
    }
    else
    {
        del = head;
        head = head->next;
        head->prev = tail;

        delete del;
    }
}
void hapusbelakang()
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat!!!";
    }
    else
    {
        del = tail;
        tail = tail->prev;
        tail->next = head;
        delete del;
    }
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
void editNode(AntrianBank *node, string newNama)
{
    if (node == NULL)
    {
        cout << "Node tidak valid." << endl;
        return;
    }

    node->nama = newNama;
}

// PRINT DARI BELAKANG
void printListReverse()
{

    bantu = tail;

    do
    {
        cout << "Nama :" << bantu->nama << endl;

        cout << endl;
        bantu = bantu->next;
    } while (bantu != tail);
}

// print doblelinkedlist
void printDoublelinkedlist()
{
    int antrianke = 1;

    bantu = head;

    do
    {
        cout << "Nama Pelanggan :" << bantu->nama << endl;
        cout << "antrian Ke  : " << antrianke << endl;

        cout << endl;
        bantu = bantu->next;
        antrianke++;
    } while (bantu != head);
}

// search data
bool searchByName(string nama)
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
            AntrianBank *temp = head;
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

    createDoublelinked("admin");
    tambahpelangganbelakang("rudi");
    tambahpelangganbelakang("mustopa");
    tambahpelangganbelakang("cic");
    tambahpelangganbelakang("salwa");
    tambahpelanggandepan("elonmusk");
    tambahpelanggandepan("Putin");

    hapusbelakang();
    hapusdepan();
    removeByname("cic");

    printDoublelinkedlist();

    return 0;
}
