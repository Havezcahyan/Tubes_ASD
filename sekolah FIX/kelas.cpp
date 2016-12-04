#include "kelas.h"


void createList(List_kelas &L)
{
    First(L) = NULL;
}

void DataKelas(List_kelas &L)
{
    infotype_kelas a;
    a.nama = "IF01";
    a.wali = "Anis";
    a.jurusan = "IPA";
    a.kapasitas = 40;
    a.tingkat = 10;
    a.tipe = "Regular";
    insertFirst(L,alokasi(a));

    a.nama = "IF02";
    a.wali = "Amelia";
    a.jurusan = "IPS";
    a.kapasitas = 40;
    a.tingkat = 10;
    a.tipe = "Int";
    insertFirst(L,alokasi(a));

    a.nama = "IF01";
    a.wali = "Miranda";
    a.jurusan = "IPA";
    a.kapasitas = 35;
    a.tingkat = 10;
    a.tipe = "Regular";
    insertFirst(L,alokasi(a));

    a.nama = "IF06";
    a.wali = "Havez";
    a.jurusan = "IPS";
    a.kapasitas = 38;
    a.tingkat = 11;
    a.tipe = "Int";
    insertFirst(L,alokasi(a));

    a.nama = "IF10";
    a.wali = "Raden";
    a.jurusan = "IPS";
    a.kapasitas = 35;
    a.tingkat = 12;
    a.tipe = "Regular";
    insertFirst(L,alokasi(a));

}
address_kelas alokasi(infotype_kelas x)
{
    address_kelas P;
    P = new elmlist_kelas;
    info(P) = x;
    next(P) = NULL;
    createList(P->Lsiswa);
    return P;
}


void insertFirst(List_kelas &L, address_kelas P)
{
    if(First(L) == NULL)
    {
        First(L) = P;

    }
    else
    {

        next(P) = First(L);
        First(L) = P;
    }
}


void insertAfter(List_kelas &L, address_kelas Prec, address_kelas P){
    if (Prec != NULL)
    {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}
void insertLast(List_kelas &L, address_kelas P){
    if (First(L)!=NULL )
    {
        address_kelas Q;
        Q = First(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = NULL;
    }
    else
    {
        First(L) = P;
    }
}
void printInfo(List_kelas L)
{
    address_kelas P = First(L);
    if(First(L)!=NULL)
    {
        do
        {
            cout<<"Nama Kelas   : "<<info(P).nama<<endl;
            cout<<"Wali kelas   : "<<info(P).wali<<endl;
            cout<<"Jurusan      : "<<info(P).jurusan<<endl;
            cout<<"Kapasitas    : "<<info(P).kapasitas<<endl;
            cout<<"Tingkat      : "<<info(P).tingkat<<endl;
            cout<<"Tipe Kelas   : "<<info(P).tipe<<endl;
            cout<<" \n";
            P = next(P);
        }
        while(P!=NULL);
    }
}


address_kelas findElm(List_kelas L, string jrs,int tkt,string tip)
{
    address_kelas P = First(L);
    while(P != NULL)
    {
        if((info(P).jurusan == jrs) && (info(P).tingkat == tkt) && (info(P).tipe == tip))
        {
            return P;
        }
        P = next(P);
    }

    return NULL;
}
void deleteFirst(List_kelas &L, address_kelas &P){
    if (First(L) != NULL)
    {
        P = First(L);
        if(next(First(L))== NULL)
        {
            First(L) = NULL;
        }
        else
        {
            First(L)=next(P);
            next(P)=NULL;
        }
    }
}
void deleteLast(List_kelas &L, address_kelas &P){

    address_kelas Q;
    Q=First(L);
    if (P != NULL)
    {
        while (next(next(Q)) != NULL)
        {
            Q = next(Q);
        }
        P = next(Q);
        next(Q)= NULL;
    }
}

void deleteAfter(List_kelas &L, address_kelas Prec, address_kelas &P){
    if(First(L) != NULL)
    {
        P = next(Prec);
        next(Prec)=next(P);
        next(P)= NULL;
    }
}
