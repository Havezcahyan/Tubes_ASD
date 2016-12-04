#include "siswa.h"


void createList(List_siswa &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

void insertFirst(List_siswa &L, address_siswa P)
{
    if(first(L)==NULL)
    {
        first(L)=P;
        last(L)=P;
    }
    else
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_siswa&L, address_siswa P)
{
    if (first(L)=NULL)
    {
        first(L)=P;
        last(L)=P;
    }
    else
    {
        prev(P)=last(L);
        next(last(L))=P;
        last(L)=P;
    }
}

void insertAfter(List_siswa &L,address_siswa Prec, address_siswa P)
{
    prev(P)=Prec;
    next(Prec)=P;
    next(P)=(next(Prec));
    prev(next(Prec)) = P;
}

void deleteFirst(List_siswa &L, address_siswa &P)
{
    P = first(L);
    if(next(first(L)) == NULL)
    {
        first(L) = NULL;
    }
    else
    {
        first(L)=next(P);
        next(P)=NULL;
        prev(first(L))=NULL;
    }
}
void deleteLast(List_siswa &L, address_siswa &P)
{
    P=last(L);
    last(L)=prev(P);
    prev(P)=NULL;
    next(last(L))=NULL;
}
void deleteAfter(List_siswa &L,address_siswa Prec, address_siswa &P)
{
    P=next(Prec);
    next(Prec)=(next(P));
    prev(next(P))=(Prec);
    prev(P) = NULL;
    next(P) = NULL;
}

address_siswa alokasi(infotype_siswa x)
{
    address_siswa P = new elmlist_siswa;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}


void printInfo(List_siswa L)
{
    address_siswa P = first(L);
    if(first(L)!=NULL)
    {
        while(P!=NULL)
        {
            cout<<"ID Siswa  : "<<info(P).id<<endl;
            cout<<"Nama      : "<<info(P).nama<<endl;
            cout<<"Wali      : "<<info(P).wali<<endl;
            cout<<"Jurusan   : "<<info(P).jurusan<<endl;
            cout<<"Tingkat   : "<<info(P).tingkat<<endl;
            cout<<"Tipe Kelas: "<<info(P).tipe<<endl;
            P = next(P);
        }

    }
}

address_siswa findElmSiswa(List_siswa L,string jrs, int tkt, int id)
{
    address_siswa P = first(L);
    while(P != NULL)
    {
        if((info(P).jurusan == jrs) && (info(P).tingkat == tkt) && (info(P).id == id))
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}


