
#include <iostream>

using namespace std;

struct MataKuliah
{
    string NamaMk, DosenMk, JadwalMk, Ruangan;
    int Sks;

    MataKuliah *Next;
};

MataKuliah *head, *bantu, *NewNode, *tail;

// membuat  single  linked list
void Createlinkedlist(string NamaMk, string DosenMk, string JadwalMk, string Ruangan, int Sks)
{
    head = new MataKuliah();
    head->NamaMk = NamaMk;
    head->DosenMk = DosenMk;
    head->JadwalMk = JadwalMk;
    head->Ruangan = Ruangan;
    head->Sks = Sks;
    tail = head;
    tail->Next = head;
}

// menghitung semua data
int count()
{
    int jumlah = 0;
    bantu = head;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->Next;
    }
    return jumlah;
}

// menambahkan data dari AWAL / DEPAN
void Addfirst(string NamaMk, string DosenMk, string JadwalMk, string Ruangan, int Sks)
{
    NewNode = new MataKuliah();
    NewNode->NamaMk = NamaMk;
    NewNode->DosenMk = DosenMk;
    NewNode->JadwalMk = JadwalMk;
    NewNode->Ruangan = Ruangan;
    NewNode->Sks = Sks;
    NewNode->Next = head;
    tail->Next = NewNode;
    head = NewNode;
}

void Addlast(string NamaMk, string DosenMk, string JadwalMk, string Ruangan, int Sks)
{
    NewNode = new MataKuliah();
    NewNode->NamaMk = NamaMk;
    NewNode->DosenMk = DosenMk;
    NewNode->JadwalMk = JadwalMk;
    NewNode->Ruangan = Ruangan;
    NewNode->Sks = Sks;

    NewNode->Next = NULL;
    tail->Next = NewNode;
    tail = NewNode;
}

// print linked lisd
void printlinkedlist()
{
    bantu = head;

    while (bantu->Next != head)
    {
        cout << "NamaMk     : " << bantu->NamaMk << endl;
        cout << "DosenMk    : " << bantu->DosenMk << endl;
        cout << "JadwalMk   : " << bantu->JadwalMk << endl;
        cout << "Ruangan    : " << bantu->Ruangan << endl;
        cout << "Sks        : " << bantu->Sks << endl;
        cout << endl;
        bantu = bantu->Next;
    }

    cout
        << endl;
}

int main()
{
    // MataKuliah *MataKuliah1;

    // MataKuliah1 = new MataKuliah();
    // MataKuliah1->NamaMk = "struktur data";
    // MataKuliah1->Next = MataKuliah1;

    // cout << MataKuliah1->NamaMk;

    Createlinkedlist("Bahasa Pemrograman II ", "MUHAMAD HILMAN, S.Kom., M.T.I", "Jumat ", "Daring", 2);

    Addfirst("Komunikasi Data ", "HOLILAH, S.T., M.T.I.", "Senin ", "R3-8", 2);

    Addlast("Struktur data ", "ANDI MOCH JANURIANA, S.T., M.Kom.", "Rabu ", "Daring", 3);
    printlinkedlist();

    return 0;
}
