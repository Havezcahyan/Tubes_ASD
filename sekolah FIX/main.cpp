#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "siswa.h"
#include "kelas.h"
using namespace std;

int main()
{
    List_kelas k;
    infotype_kelas a;
    infotype_siswa b;
    createList(k);
    DataKelas(k);
    char yn = 'y';
    int menu=0;
    while (/**yn = 'y')**/menu != 5)
    {
        system("cls");
        cout<<"     SEKOLAH \n"<<endl;
        cout<<"1. Tambah Data"<<endl;
        cout<<"2. Hapus Data"<<endl;
        cout<<"3. Cari Data"<<endl;
        cout<<"4. Tampilkan Data"<<endl;
        cout<<"5. Keluar"<<endl;
        cout<<endl;
        cout<<"Masukan Opsi : ";
        cin>>menu;
        switch (menu)
        {
        case 1:
        {
            system("cls");
            int menuintr = 0;
            while (menuintr != 3)
            {
                cout<<"     TAMBAH DATA \n"<<endl;
                cout<<"1. Input Data Kelas"<<endl;
                cout<<"2. Input Data Siswa"<<endl;
                cout<<"3. Main Menu"<<endl;
                cout<<"Masukan Opsi : ";
                cin>>menuintr;
                if (menuintr == 1)
                {
                    system("cls");
                    cout<<"     Masukan Data Kelas"<<endl;
                    cout<<"Nama     : ";
                    cin>>a.nama;
                    cout<<endl;
                    cout<<"Wali     : ";
                    cin>>a.wali;
                    cout<<endl;
                    cout<<"Jurusan  : ";
                    cin>>a.jurusan;
                    cout<<endl;
                    cout<<"Kapasitas: ";
                    cin>>a.kapasitas;
                    cout<<endl;
                    cout<<"Tingkat  : ";
                    cin>>a.tingkat;
                    cout<<endl;
                    cout<<"Tipe     : ";
                    cin>>a.tipe;
                    cout<<endl;
                    if (findElm(k,a.jurusan,a.tingkat,a.tipe)== NULL)
                    {
                        int x = 0;
                        while (x != 4)
                        {
                            cout<<"1.Insert First"<<endl;
                            cout<<"2.Insert After"<<endl;
                            cout<<"3.Insert Last"<<endl;
                            cout<<"4.Kembali"<<endl;
                            cout<<"Masukan Opsi : ";
                            cin>>x;
                            cout<<endl;
                            if (x == 1)
                            {
                                insertFirst(k,alokasi(a));
                                cout<<"Data Berhasil Dimasukan!"<<endl;
                                Sleep(1000);
                                break;
                            }
                            else if (x == 2)
                            {
                                address_kelas carkel;
                                infotype_kelas z;
                                cout<<"     CARI DATA KELAS \n"<<endl;
                                cout<<"1. Masukkan Jurusan      : ";
                                cin>>z.jurusan;
                                cout<<endl;
                                cout<<"2. Masukkan Tingkat      : ";
                                cin>>z.tingkat;
                                cout<<endl;
                                cout<<"3. Masukkan Tipe Kelas   : ";
                                cin>>z.tipe;
                                cout<<endl;
                                carkel = findElm(k,z.jurusan,z.tingkat,z.tipe);
                                if(carkel != NULL)
                                {
                                    insertAfter(k,carkel,alokasi(a));
                                    cout<<"Data Berhasil Dimasukan!"<<endl;
                                    Sleep(1000);
                                    break;
                                }
                                else
                                {
                                    cout<<"Kelas Yang Di Cari Tidak Ada"<<endl;
                                    Sleep(1000);
                                }
                            }
                            else if (x == 3)
                            {
                                insertLast(k,alokasi(a));
                                cout<<"Data Berhasil Dimasukan!"<<endl;
                                Sleep(1000);
                                break;
                            }
                            else
                            {
                                cout<<"Opsi Yang Anda Masukan Salah"<<endl;
                                Sleep(1000);
                            }
                        }
                    }
                    else
                    {
                        cout<<"Data Sudah Ada"<<endl;
                        Sleep(1000);
                    }
                    break;
                }
                else if (menuintr == 2)
                {
                    system("cls");
                    address_kelas carkelas;
                    cout<<"     Masukan Data Siswa"<<endl;
                    cout<<"ID       : ";
                    cin>>b.id;
                    cout<<endl;
                    cout<<"Nama     : ";
                    cin>>b.nama;
                    cout<<endl;
                    cout<<"Wali     : ";
                    cin>>b.wali;
                    cout<<endl;
                    cout<<"Jurusan  : ";
                    cin>>b.jurusan;
                    cout<<endl;
                    cout<<"Tingkat  : ";
                    cin>>b.tingkat;
                    cout<<endl;
                    cout<<"Tipe     : ";
                    cin>>b.tipe;
                    cout<<endl;
                    carkelas = findElm(k, b.jurusan, b.tingkat,b.tipe);
                    if (carkelas != NULL)
                    {
                        if(findElmSiswa(carkelas->Lsiswa,b.jurusan,b.tingkat,b.id)== NULL)
                        {
                            insertFirst(carkelas->Lsiswa, alokasi(b));
                            cout<<"Data Berhasil Dimasukan!"<<endl;
                            Sleep(1000);
                            break;
                        }
                        else
                        {
                            cout<<"Siswa Sudah Ada"<<endl;
                        }
                    }
                    else
                    {
                        cout<<"Tidak Ada Kelas Yang cocok"<<endl;
                        Sleep(1000);
                    }
                }
                else if (menuintr == 3)
                {
                    system("cls");
                }
                else
                {
                    cout<<"Opsi Yang Anda Masukan Salah!"<<endl;
                    Sleep(500);
                    system("cls");
                }
            }
            break;
        }
        case 2:
        {
            system("cls");
            int menudel = 0;
            while (menudel != 3)
            {
                cout<<"     DELETE DATA \n"<<endl;
                cout<<"1. Delete Data Kelas"<<endl;
                cout<<"2. Delete Data Siswa"<<endl;
                cout<<"3. Main Menu"<<endl;
                cout<<"Masukan Opsi : ";
                cin>>menudel;
                if(menudel == 1)
                {
                    system("cls");
                    address_kelas carkel;
                    cout<<"Delete Data Kelas"<<endl;
                    cout<<"1. Masukkan Jurusan  : ";
                    cin>>a.jurusan;
                    cout<<endl;
                    cout<<"2. Masukkan Tingkat  : ";
                    cin>>a.tingkat;
                    cout<<endl;
                    cout<<"3. Masukkan Tipe     : ";
                    cin>>a.tipe;
                    cout<<endl;
                    carkel = findElm(k,a.jurusan,a.tingkat,a.tipe);
                    if(carkel != NULL)
                    {
                        if(carkel == First(k))
                        {
                            deleteFirst(k,carkel);
                        }
                        else if(next(carkel) != NULL)
                        {
                            address_kelas prec = First(k);
                            while(next(prec) != carkel)
                            {
                                prec = next(prec);
                            }
                            deleteAfter(k,prec,carkel);
                        }
                        else
                        {
                            deleteLast(k,carkel);
                        }
                    }
                }
                if (menudel == 2)
                {
                    system("cls");
                    cout<<"Delete Data Siswa"<<endl;
                    cout<<"1.Masukkan ID        : ";
                    cin>>b.id;
                    cout<<endl;
                    cout<<"2.Masukkan Jurusan   : ";
                    cin>>b.jurusan;
                    cout<<endl;
                    cout<<"3.Masukkan Tingkat   : ";
                    cin>>b.tingkat;
                    cout<<endl;
                    cout<<"4.Masukkan Tipe Kelas: ";
                    cin>>b.tipe;
                    cout<<endl;
                    address_kelas carkel = findElm(k,b.jurusan,b.tingkat,b.tipe);
                    if (carkel != NULL)
                    {
                        address_siswa carsis = findElmSiswa(carkel->Lsiswa,b.jurusan,b.tingkat,b.id);
                        if (carsis != NULL)
                        {
                            if(carsis == first(carkel->Lsiswa))
                            {
                                deleteFirst(carkel->Lsiswa,carsis);
                            }
                            else if (next(first(carkel->Lsiswa)) != NULL)
                            {
                                address_siswa prec = first(carkel->Lsiswa);
                                while(next(prec) != carsis)
                                {
                                    prec = next(prec);
                                }
                                deleteAfter(carkel->Lsiswa,prec,carsis);
                            }
                            else
                            {
                                deleteLast(carkel->Lsiswa,carsis);
                            }
                        }
                    }
                }
                if (menudel == 3)
                {
                    system("cls");
                    break;
                }
                else
                {
                    cout<<"Menu Opsi Yang Anda Masukkan Salah"<<endl;
                    Sleep(500);
                    system("cls");
                }
            }
            break;
        }
        case 3:
        {
            system("cls");
            int menucar = 0;
            while (menucar != 3)
            {
                address_kelas carkel;
                address_siswa carsis;
                cout<<"     CARI DATA  \n"<<endl;
                cout<<" 1. Cari Data Kelas "<<endl;
                cout<<" 2. Cari Data Siswa "<<endl;
                cout<<" 3. Main Menu "<<endl;
                cout<<"Masukan Opsi : ";
                cin>>menucar;
                if (menucar == 1)
                {
                    system("cls");
                    address_kelas carkel;
                    cout<<"     CARI DATA KELAS \n"<<endl;
                    cout<<"1. Masukkan Jurusan      : ";
                    cin>>a.jurusan;
                    cout<<endl;
                    cout<<"2. Masukkan Tingkat      : ";
                    cin>>a.tingkat;
                    cout<<endl;
                    cout<<"3. Masukkan Tipe Kelas   : ";
                    cin>>a.tipe;
                    cout<<endl;
                    carkel = findElm(k,a.jurusan,a.tingkat,a.tipe);
                    if(carkel != NULL)
                    {
                        cout<<"Nama         : "<<info(carkel).nama<<endl;
                        cout<<"Wali         : "<<info(carkel).wali<<endl;
                        cout<<"Jurusan      : "<<info(carkel).jurusan<<endl;
                        cout<<"Kapasitas    : "<<info(carkel).kapasitas<<endl;
                        cout<<"Tingkat      : "<<info(carkel).tingkat<<endl;
                        cout<<"Tipe Kelas   : "<<info(carkel).tipe<<endl;
                    }
                    else
                    {
                        cout<<"Kelas yang Dicari Tidak Ada"<<endl;
                    }
                }
                if (menucar == 2)
                {
                    system("cls");
                    cout<<"     CARI DATA SISWA \n"<<endl;
                    cout<<"1.Masukkan ID        : ";
                    cin>>b.id;
                    cout<<endl;
                    cout<<"2.Masukkan Jurusan   : ";
                    cin>>b.jurusan;
                    cout<<endl;
                    cout<<"3.Masukkan Tingkat   : ";
                    cin>>b.tingkat;
                    cout<<endl;
                    cout<<"4.Masukkan Tipe Kelas: ";
                    cin>>b.tipe;
                    cout<<endl;
                    address_kelas carkel = findElm(k,b.jurusan,b.tingkat,b.tipe);
                    if (carkel != NULL)
                    {
                        address_siswa carsis = findElmSiswa(carkel->Lsiswa,b.jurusan,b.tingkat,b.id);
                        if (carsis != NULL)
                        {
                            cout<<"ID Siswa : "<<info(carsis).id<<endl;
                            cout<<"Nama     : "<<info(carsis).nama<<endl;
                            cout<<"Wali     : "<<info(carsis).wali<<endl;
                            cout<<"Jurusan  : "<<info(carsis).jurusan<<endl;
                            cout<<"Tingkat  : "<<info(carsis).tingkat<<endl;
                            cout<<"Tipe     : "<<info(carsis).tipe<<endl;
                        }
                    }
                    else
                    {
                        cout<<"Siswa Tidak Di Temukan"<<endl;
                    }
                    if (menucar == 3)
                    {
                        break;
                    }
                }
            }
            break;
        }
        case 4:
        {
            system("cls");
            int menutam = 0;
            while (menutam != 3)
            {
                cout<<" \n";
                cout<<"     Tampilkan Data \n"<<endl;
                cout<<"1. Tampilkan Data Kelas"<<endl;
                cout<<"2. Tampilkan Data Siswa"<<endl;
                cout<<"3. Main Menu"<<endl;
                cout<<"Masukan Opsi : ";
                cin>>menutam;
                cout<<endl;
                if (menutam == 1)
                {
                    system("cls");
                    printInfo(k);
                }
                else if (menutam == 2 )
                {
                    address_kelas P = First(k);
                    if(First(k)!=NULL)
                    {
                        while (P != NULL)
                        {
                            if (first(P->Lsiswa) != NULL)
                            {
                                address_siswa Q = first(P->Lsiswa);
                                while(Q!=NULL)
                                {
                                    cout<<"ID Siswa  : "<<info(Q).id<<endl;
                                    cout<<"Nama      : "<<info(Q).nama<<endl;
                                    cout<<"Wali      : "<<info(Q).wali<<endl;
                                    cout<<"Jurusan   : "<<info(Q).jurusan<<endl;
                                    cout<<"Tingkat   : "<<info(Q).tingkat<<endl;
                                    cout<<"Tipe Kelas: "<<info(Q).tipe<<endl;
                                    cout<<endl;
                                    Q = next(Q);
                                }
                            }
                            P = next(P);
                        }
                    }
                    else
                    {
                        cout<<"Data Masih Kosong"<<endl;
                        Sleep(1000);
                    }
                }
                else
                {
                    system("cls");
                    cout<<"Opsi Yang Anda Masukan Salah"<<endl;
                }
            }
            break;
        }
        case 5:
        {
            cout<<"Terima Kasih"<<endl;
            return 0;
        }
        default :
        {
            cout<<"Opsi Yang Anda Masukan Salah"<<endl;
            Sleep(500);
            system("cls");
            break;
        }

        }
        //cin>>yn;

    }
    return 0;
}
