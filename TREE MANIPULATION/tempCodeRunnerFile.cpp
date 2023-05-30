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

    cout << "hasil update TREE : \n";
    UpdateTree("maryam", Naen);
    retrive(Naen);
    cout << "hasil find TREE : \n";
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