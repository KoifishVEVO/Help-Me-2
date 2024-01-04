#include "penerbangan.h"

int main() {
    // Inisialisasi list maskapai
    List_maskapai maskapaiList;
    maskapaiList.first = NULL;
    maskapaiList.last = NULL;

    // Inisialisasi list jadwal
    List_jadwal jadwalList;
    jadwalList.first = NULL;
    infotype p;
    infoJadwal c;

    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Tambah Maskapai\n";
        cout << "2. Tambah Jadwal\n";
        cout << "3. Tambah Relasi\n";
        cout << "4. Tampilkan Informasi Maskapai dan Jadwal\n";
        cout << "5. Tampilkan Informasi Jadwal\n";
        cout << "6. Tampilkan Semua Maskapai\n";
        cout << "7. Hapus Maskapai dan semua relasinya\n";
        cout << "8. Cari data Maskapai\n";
        cout << "9. Cari data jadwal pada Maskapai Tertentu\n";
        cout << "10. Hapus data Jadwal pada maskapai tertentu beserta relasinya\n";
        cout << "11. Hitung jumlah data child dari parent tertentu\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Menambahkan maskapai ke dalam list
                infotype maskapaiInfo;
                cout << "Masukkan ID Maskapai: ";
                cin >> maskapaiInfo.id;
                cout << "Masukkan Nama Maskapai: ";
                cin >> maskapaiInfo.nama;
                cout << "Masukkan Kapasitas Maskapai: ";
                cin >> maskapaiInfo.kapasitas;
                cout << endl;

                adr_parent maskapai = createElmParent(maskapaiInfo);
                insertLastParent(maskapaiList, maskapai);

                break;
            }
            case 2: {
                // Menambahkan jadwal ke dalam list
                infoJadwal* jadwalInfo = new infoJadwal;
                cout << "Masukkan Rute Jadwal: ";
                cin >> jadwalInfo->rute;
                cout << "Masukkan Hari Jadwal: ";
                cin >> jadwalInfo->jadwal;
                cout << "Masukkan Status Jadwal: ";
                cin >> jadwalInfo->status;
                cout << "Masukkan Jam Jadwal: ";
                cin >> jadwalInfo->jam;
                cout << endl;

                adr_child jadwal = createElmChild(jadwalInfo);
                insertLastChild(jadwalList, jadwal);

                break;
            }
            case 3: {
                // Membuat relasi antara maskapai dan jadwal
                infotype maskapaiInfo;
                cout << "Masukkan ID Maskapai: ";
                cin >> maskapaiInfo.id;

                infoJadwal* jadwalInfo = new infoJadwal;
                cout << "Masukkan Rute Jadwal: ";
                cin >> jadwalInfo->rute;
                cout << endl;

                createRelation(maskapaiList, jadwalList, maskapaiInfo, jadwalInfo);

                break;
            }
            case 4: {
                // Menampilkan informasi maskapai beserta jadwalnya
                showParentWithChildren(maskapaiList);
                cout << endl;
                break;
            }
            case 5: {
                showJadwal(jadwalList);
                cout << endl;
                break;
            }
            case 6: {
                showParent(maskapaiList);
                cout << endl;
                break;
            }
            case 7: {

                cout << "Masukkan ID maskapai" << endl;
                cin >> p.id;
                deleteAfterWithRelation(maskapaiList, p);
                cout << endl;
                break;
            }
            case 8: {
                cout << "Masukkan ID maskapai yang ingin dicari: " << endl;
                cin >> p.id;
                adr_parent finder = searchParent(maskapaiList, p);
                if (finder == NULL){
                    cout << "Data tidak ditemukan "<<endl;
                } else {
                    cout << "Data ditemukan"<<endl;
                    cout << "ID: " << finder->info.id <<endl;
                    cout << "Nama: " << finder->info.nama <<endl;
                    cout << "Kapasitas: " << finder->info.kapasitas <<endl;

                }
                cout << endl;
                break;
            }
            case 9: {
                cout << "Masukkan ID maskapai : " << endl;
                cin >> p.id;
                cout << "Masukkan rute jadwal yang ingin dicari: " << endl;
                cin >> c.rute;
                searchChildDalamParent(maskapaiList, p, c);
                cout << endl;
                break;
            }
            case 10: {
                cout << "Masukkan ID maskapai : " << endl;
                cin >> p.id;
                cout << "Masukkan rute jadwal yang ingin dihapus: " << endl;
                cin >> c.rute;
                deleteChildWithRelation(jadwalList, maskapaiList, p, c);
                cout << endl;
                break;
            }
            case 11: {
                cout << "Masukkan ID maskapai : " << endl;
                cin >> p.id;

                int count = countChildren(maskapaiList, p);
                if (count == 0){
                    cout << "Maskapai tidak memiliki jadwal" << endl;
                } else {
                cout << "Jumlah data rute Maskapai " << p.id << ": " << count << endl;
                }

            }
            case 0: {
                cout << "Terimakasih sudah memakai aplikasi kami!";
                break;
            }

            default: {
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
            }
        }
    } while (choice != 0);

    return 0;
}
