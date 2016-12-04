#ifndef SISWA_H_INCLUDED
#define SISWA_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define parent(P) P->parent



struct siswa {
    int id;
    string nama;
    string wali;
    string jurusan;
    int tingkat;
    string tipe;
};

 typedef siswa infotype_siswa;
 typedef struct elmlist_siswa *address_siswa;


 struct elmlist_siswa{
     infotype_siswa info;
     address_siswa next;
     address_siswa prev;

 };

struct List_siswa{
    address_siswa first;
    address_siswa last;
};




/** TIDAK PERLU MODIFIKASI */
void createList(List_siswa &L);
void insertFirst(List_siswa &L, address_siswa P);
void insertLast(List_siswa&L, address_siswa P);
void insertAfter(List_siswa &L,address_siswa Prec, address_siswa P);
void deleteFirst(List_siswa &L, address_siswa &P);
void deleteLast(List_siswa &L, address_siswa &P);
void deleteAfter(List_siswa &L,address_siswa Prec, address_siswa &P);
address_siswa findElmSiswa(List_siswa L,string jrs, int tkt, int id);


 /** PERLU MODIFIKASI */
address_siswa alokasi(infotype_siswa x);
void printInfo(List_siswa L);

#endif // KELAS_H_INCLUDED
