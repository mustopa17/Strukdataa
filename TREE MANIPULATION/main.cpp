#include <iostream>
using namespace std;

// DEKLARASI TREE

struct Keluarga
{
    string data;
    Keluarga *left, *right, *parent;
};
Keluarga *root, *newNode;

// MEMBUAT TREEE
void createTree(string data)
{
    root = new Keluarga();
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
}

// mengecek apakah tree kosong atau tidak
bool isEmpty()
{
    if (root == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// tambah kanan
Keluarga *insertright(string data, Keluarga *bapak)
{
    if (root == NULL)
    {
        cout << "Buat Tree terlebih Dahulu!!!";
        return NULL;
    }
    else
    {
        if (bapak->right != NULL)
        {
            return NULL;
        }
        else
        {
            newNode = new Keluarga();
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->parent = bapak;
            bapak->right = newNode;
            cout << "\n " << data << " Berhasil di tambahkan Ke Anak Kanan " << newNode->parent->data;
            return newNode;
        }
    }
}

// tambah kiri
Keluarga *insertkiri(string data, Keluarga *bapak)
{
    if (root == NULL)
    {
        cout << "Buat Tree terlebih Dahulu!!!";
        return NULL;
    }
    else
    {
        if (bapak->left != NULL)
        {
            return NULL;
        }
        else
        {
            newNode = new Keluarga();
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->parent = bapak;
            bapak->left = newNode;
            cout << "\n " << data << " Berhasil di tambahkan Ke Anak kiri " << newNode->parent->data;
            return newNode;
        }
    }
}

// Mengedit data tree yang diinginkan
void UpdateTree(string newdata, Keluarga *pilihan)
{
    if (root == NULL)
    {
        cout << "Buat Tree terlebih Dahulu!!!";
    }
    else
    {
        string bantu = pilihan->data;
        pilihan->data = newdata;
        cout << "\ndata " << bantu << " Berhasil di ubah Menjadi : " << newdata << endl;
    }
}

// mengetahui isi data dari node yang di tunjuk
void retrive(Keluarga *node)
{
    if (root == NULL)
    {
        cout << "Buat Tree terlebih Dahulu!!!";
    }
    else
    {
        if (node == NULL)
        {
            cout << "node yang ditunjuk tidak ada!!!";
        }
        else
        {
            cout << "RETRIVE  Node DATA  : " << node->data << endl;
        }
    }
}

// mencari root , parent ,anakkanan , anak kiri, saudara ,  dari node yang di tunjuk
void find(Keluarga *node)
{
    if (root == NULL)
    {
        cout << "Buat Tree terlebih Dahulu!!!";
    }
    else
    {
        cout << "data Node :" << node->data;
        cout << " \nroot Node :" << root->data;

        if (node->parent == NULL)
        {
            cout << "  \nTidak Punya orang tua\n";
        }
        else
        {
            cout << "\nParent Node :" << node->parent->data;
        }
        if (node->right == NULL)
        {
            cout << "Tidak Punya Anak Kanan" << endl;
        }
        else
        {
            cout << "Anak kanan Node :" << node->right->data;
        }
        if (node->left == NULL)
        {
            cout << " \n Tidak Punya Anak kiri" << endl;
        }
        else
        {
            cout << "\nAnak Kiri Node :" << node->left->data;
        }
        if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
        {
            cout << " \nSaudara : " << node->parent->left->data << endl;
        }
        else if (node->parent != NULL && node->parent->left == node && node->parent->right != node)
        {
            cout << "\n Saudara : " << node->parent->right->data << endl;
        }
        else
        {
            cout << "\n Tidak Punya saudara !!!\n";
        }
    }
}

// mengunjungi node-node pada tree dengan cara tranversal ( preeorder)

void preorder(Keluarga *node = root)
{
    if (root == NULL)
    {
    }
    else
    {

        if (node != NULL)
        {
            cout << node->data << ", ";
            preorder(node->left);
            preorder(node->right);
        }
    }
}

// mengunjungi node-node pada tree dengan cara tranversal ( inorder)

void inOrder(Keluarga *node = root)
{
    if (root == NULL)
    {
        cout << "\nBuat Tree terlebih Dahulu!!!\n";
    }
    else
    {

        if (node != NULL)
        {
            inOrder(node->left);
            cout << node->data << ", ";
            inOrder(node->right);
        }
    }
}
// mengunjungi node-node pada tree dengan cara tranversal ( PostOrder)

void PostOrder(Keluarga *node = root)
{
    if (root == NULL)
    {
        cout << "\nBuat Tree terlebih Dahulu!!!\n";
    }
    else
    {

        if (node != NULL)
        {
            PostOrder(node->left);
            PostOrder(node->right);
            cout << node->data << ", ";
        }
    }
}
// menghapus node beserta subtree nya (turunan di bawahnya)
void deleteTree(Keluarga *node)
{

    if (!root)
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {

        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);

            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {

                delete node;
                cout << "\nnode berhasil di hapus";
            }
        }
    }
}

// menghapus subtree node beserta turunan di bawahnya (tidak dengan node nya sendiri)
void deleteSub(Keluarga *node)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nSubtree node " << node->data << " berhasil dihapus." << endl;
    }
}

// clear
void clear()
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\nTree berhasil dihapus." << endl;
    }
}

int size(Keluarga *node = root)
{
    if (root == NULL)
    {

        return 0;
    }
    else
    {
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->right) + size(node->left);
        }
    }
}

int height(Keluarga *node = root)
{
    if (root == NULL)
    {

        return 0;
    }
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int heightkiri = height(node->left);
        int heightKanan = height(node->right);
        if (heightkiri >= heightKanan)
        {
            return heightkiri + 1;
        }
        else
        {
            return heightKanan + 1;
        }
    }
}

// karakteristik untuk meliat size , tinggi , dan rata rata
void charateristic()
{
    cout << "\nSize Tree : " << size() << endl;
    cout << "Height Tree : " << height() << endl;
    cout << "Average Node of Tree : " << size() / height() << endl;
}

int main()

{
    createTree("Kakek");
    Keluarga *Naen, *Nuoh, *Nmuam, *Nmustopa, *Nelon, *Njae, *Njef;

    Nuoh = insertkiri("uoh", root);
    Nmuam = insertkiri("MUAM", Nuoh);
    Naen = insertright("aen", root);
    Njae = insertright("JAE", Naen);
    Njef = insertright("JEFBESOS", Njae);
    Nmustopa = insertkiri("MUSTOPA", Naen);
    Nelon = insertkiri("ELON", Nmustopa);

    UpdateTree("maryam", Naen);
    retrive(Naen);
    cout << "\n\nhasil find TREE : \n";
    find(root);
    cout << "hasil preorder TREE : \n";
    preorder(root);

    cout << "\n\n karakteristik : ";
    charateristic();

    deleteTree(root);
    preorder(root);
    cout << "\n\n karakteristik : ";
    charateristic();
    cout << "\n\n\nsize TREE :" << size();
}