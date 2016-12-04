#ifndef KELAS_H_INCLUDED
#define KELAS_H_INCLUDED
#define Nil NULL
#include "siswa.h"
#define next(P) P->next
#define First(L) L.First
#define info(P) P->info
#include <iostream>

using namespace std;

struct kelas {
    string nama;
    string wali;
    string jurusan;
    int kapasitas;
    int tingkat;
    string tipe;
};

typedef kelas infotype_kelas;
typedef struct elmlist_kelas *address_kelas;


 struct elmlist_kelas {
     infotype_kelas info;
     address_kelas next;
     List_siswa Lsiswa;
 };


 struct List_kelas{
     address_kelas First;
};





void createList(List_kelas &L);
void insertFirst(List_kelas &L, address_kelas P);
void insertAfter(List_kelas &L, address_kelas Prec, address_kelas P);
void insertLast(List_kelas &L, address_kelas P);
void deleteFirst(List_kelas &L, address_kelas &P);
void deleteLast(List_kelas &L, address_kelas &P);
void deleteAfter(List_kelas &L, address_kelas Prec, address_kelas &P);
address_kelas findElm(List_kelas L, string jrs,int tkt,string tip);



/** PERLU MODIFIKASI */
address_kelas alokasi(infotype_kelas x);
void printInfo(List_kelas L);
void DataKelas(List_kelas &L);


#endif // KELAS_H_INCLUDED
