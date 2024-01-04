#ifndef PENERBANGAN_H_INCLUDED
#define PENERBANGAN_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct elmRelation *address;
typedef struct elmChild *adr_child;
typedef struct elmParent *adr_parent;

struct elmRelation {
    address next;
    adr_child next_child;
};

struct maskapai {
    string id;
    string nama;
    int kapasitas;
};

typedef maskapai infotype;

struct elmParent {
    adr_parent next;
    adr_parent prev;
    infotype info;
    address jadwalP;
};

struct List_maskapai {
    adr_parent first;
    adr_parent last;
};

struct jadwal {
    string rute;
    string jadwal;
    string status;
    int jam;
};

typedef jadwal infoJadwal;

struct elmChild {
    adr_child next;
    infoJadwal* info;
};

struct List_jadwal {
    adr_child first;
};

// Fungsi-Fungsi

adr_parent createElmParent(infotype x);
adr_child createElmChild(infoJadwal* x);  // Perubahan disini
address createRelation();
void insertFirstParent(List_maskapai &L, adr_parent p);
void insertLastParent(List_maskapai &L, adr_parent P);
void showParent(List_maskapai L); //
void deleteFirst(List_maskapai &L);
adr_parent searchParent(List_maskapai L, infotype x);
void deleteRelations(List_maskapai &L, infotype x);
void deleteAfterWithRelation(List_maskapai &L, infotype x); //
void showJadwal(List_jadwal L);
int countChildren(List_maskapai &L, infotype x);  // Perubahan disini
void deleteAfterChild(List_jadwal &L, adr_child P);

// Fungsi-Fungsi Child
adr_child searchChild(List_jadwal &L, infoJadwal* x);  // Perubahan disini
void insertLastChild(List_jadwal &L, adr_child P);
void InsertFirstChild(List_jadwal &L, adr_child P);
void deleteChildWithRelation(List_jadwal &L, List_maskapai &M, infotype parentInfo, infoJadwal childInfo);
void searchChildDalamParent(List_maskapai L, infotype parentInfo, infoJadwal childInfo);


// Fungsi tambahan untuk membuat relasi
void createRelation(List_maskapai &L, List_jadwal &J, infotype parentInfo, infoJadwal* childInfo);  // Perubahan disini

// Fungsi untuk menampilkan seluruh data parent beserta childnya
void showParentWithChildren(List_maskapai L);

#endif // PENERBANGAN_H_INCLUDED
