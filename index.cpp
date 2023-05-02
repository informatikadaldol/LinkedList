#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string npm;
    Mahasiswa* next;
};

void tambahAwal(Mahasiswa *&head) {
    string nama, npm;
    cout << "Masukkan nama mahasiswa: ";
    cin >> nama;
    cout << "Masukkan NPM mahasiswa: ";
    cin >> npm;

    Mahasiswa *baru = new Mahasiswa;
    baru->nama = nama;
    baru->npm = npm;
    baru->next = head;
    head = baru;
    cout << "Data mahasiswa berhasil ditambahkan di awal" << endl;
}

void tambahAkhir(Mahasiswa *&head) {
    string nama, npm;
    cout << "Masukkan nama mahasiswa: ";
    cin >> nama;
    cout << "Masukkan NPM mahasiswa: ";
    cin >> npm;

    Mahasiswa *baru = new Mahasiswa;
    baru->nama = nama;
    baru->npm = npm;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
        cout << "Data mahasiswa berhasil ditambahkan di akhir" << endl;
        return;
    }

    Mahasiswa *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = baru;
    cout << "Data mahasiswa berhasil ditambahkan di akhir" << endl;
}

void tambahIndex(Mahasiswa *&head) {
    int index;
    cout << "Masukkan index node yang ingin ditambahkan: ";
    cin >> index;

    if (index < 0) {
        cout << "Index tidak valid" << endl;
        return;
    }

    if (index == 0) {
        tambahAwal(head);
        return;
    }

    int counter = 0;
    Mahasiswa *temp = head;
    while (temp != NULL && counter < index - 1) {
        temp = temp->next;
        counter++;
    }

    if (temp == NULL) {
        cout << "Index tidak valid" << endl;
        return;
    }

    string nama, npm;
    cout << "Masukkan nama mahasiswa: ";
    cin >> nama;
    cout << "Masukkan NPM mahasiswa: ";
    cin >> npm;

    Mahasiswa *baru = new Mahasiswa;
    baru->nama = nama;
    baru->npm = npm;
    baru->next = temp->next;
    temp->next = baru;

    cout << "Data mahasiswa berhasil ditambahkan pada index " << index << endl;
}

void hapusAwal(Mahasiswa *&head) {
    if (head == NULL) {
        cout << "Linked list kosong" << endl;
        return;
    }

    Mahasiswa *hapus = head;
    head = head->next;
    delete hapus;

    cout << "Data mahasiswa di awal berhasil dihapus" << endl;
}

void hapusAkhir(Mahasiswa *&head) {
    if (head == NULL) {
        cout << "Linked list kosong" << endl;
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Data mahasiswa di akhir berhasil dihapus" << endl;
        return;
    }

    Mahasiswa *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
}

Mahasiswa *hapus = temp->next;
temp->next = NULL;
delete hapus;

cout << "Data mahasiswa di akhir berhasil dihapus" << endl;
}

void hapusIndex(Mahasiswa *&head) {
int index;
cout << "Masukkan index node yang ingin dihapus: ";
cin >> index;
if (index < 0) {
    cout << "Index tidak valid" << endl;
    return;
}

if (index == 0) {
    hapusAwal(head);
    return;
}

int counter = 0;
Mahasiswa *temp = head;
while (temp != NULL && counter < index - 1) {
    temp = temp->next;
    counter++;
}

if (temp == NULL || temp->next == NULL) {
    cout << "Index tidak valid" << endl;
    return;
}

Mahasiswa *hapus = temp->next;
temp->next = hapus->next;
delete hapus;

cout << "Data mahasiswa pada index " << index << " berhasil dihapus" << endl;
}

void tampilData(Mahasiswa *head) {
if (head == NULL) {
cout << "Linked list kosong" << endl;
return;
}
Mahasiswa *temp = head;
while (temp != NULL) {
    cout << "Nama: " << temp->nama << endl;
    cout << "NPM: " << temp->npm << endl;
    cout << endl;
    temp = temp->next;
}
}

int main() {
Mahasiswa *head = NULL;
int pilihan;
int pilihan2;
int ulang;
int banyak;
cout<<"berapa kali anda ingin mengulang? :";
cin>>banyak;
do{
	system("cls");
	cout<<"\t\tMenu"<<endl;
cout<<"1. Menambahkan Data Mahasiswa"<<endl;
cout<<"2. Menghapus Data Mahasiswa"<<endl;
cout<<"3. Menampilkan Data Mahasiswa"<<endl;
cout<<"4. Keluar Program"<<endl;
cout<<"masukan pilihan anda disini :";
cin>>pilihan;

switch(pilihan){
	case 1:
		cout<<"1.Tambah Data Di Awal "<<endl;
		cout<<"2.Tambah Data Di Akhir "<<endl;
		cout<<"3.Tambah Berdasarkan Index"<<endl;
		cout<<"masukan pilihan :";
		cin>>pilihan2;
		if(pilihan2 == 1){
			tambahAwal(head);
		}else if(pilihan == 2){
			tambahAkhir(head);
		}else if(pilihan2 == 3){
			tambahIndex(head);
		}else{
			cout<<"pilihan yang anda masukan salah!"<<endl;
		}
		break;
	case 2:
		cout<<"1.Hapus Data Di Awal "<<endl;
		cout<<"2.Hapus Data Di Akhir "<<endl;
		cout<<"3.Hapus Berdasarkan Index"<<endl;
		cout<<"masukan pilihan :";
		cin>>pilihan2;
		if(pilihan2 == 1){
			hapusAwal(head);
		}else if(pilihan2 == 2){
			hapusAkhir(head);
		}else if(pilihan2 == 3){
			hapusIndex(head);
		}else{
			cout<<"pilihan yang anda masukan salah!"<<endl;
		}
		break;
	case 3:
		tampilData(head);
		break;
	case 4:
		cout<<"Anda Telah Keluar Dari Program"<<endl;
		break;
  }
  
	banyak++;
 } while(ulang == banyak);

}



//do {
//    cout << "MENU" << endl;
//    cout << "1. Tambah data di awal" << endl;
//    cout << "2. Tambah data di akhir" << endl;
//    cout << "3. Tambah data pada index tertentu" << endl;
//    cout << "4. Hapus data di awal" << endl;
//    cout << "5. Hapus data di akhir" << endl;
//    cout << "6. Hapus data pada index tertentu" << endl;
//    cout << "7. Tampilkan data" << endl;
//    cout << "8. Keluar" << endl;
//    cout << "Pilihan: ";
//    cin >> pilihan;
//    switch (pilihan) {
//        case 1:
//            tambahAwal(head);
//            break;
//        case 2:
//            tambahAkhir(head);
//            break;
//        case 3:
//            tambahIndex(head);
//            break;
//        case 4:
//            hapusAwal(head);
//            break;
//        case 5:
//            hapusAkhir(head);
//            break;
//        case 6:
//            hapusIndex(head);
//            break;
//        case 7:
//            tampilData(head);
//            break;
//        case 8:
//            cout << "Keluar" << endl;
//            break;
//        default:
//            cout << "Pilihan tidak valid" << endl;
//            break;
//    }
//} while (pilihan != 8);
//
//return 0;
//}
