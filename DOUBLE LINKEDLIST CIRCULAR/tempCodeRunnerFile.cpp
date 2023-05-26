
    createDoublelinked("Mustopa", "3333", "admmin", 1);
    system("clear");
    bool exitLoop = false;
    while (!exitLoop)
    {
        cout << "Menu:" << endl;
        cout << "1. Tambah Data Peminjaman" << endl;
        cout << "2. Hapus Data Peminjaman" << endl;
        cout << "3. Tampilkan Data Peminjaman" << endl;
        cout << "4. Edit Data Peminjaman" << endl;
        cout << "5. Tampilkan Data Peminjaman Terbalik" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu: ";

        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)