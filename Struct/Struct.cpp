#include <iostream>
#include <string>
using namespace std;

struct biodata{
    string nama, NRP, keahlian, hobi, asal, tgl_lahir, tahun_masuk;
    int umur;
    float IPS, IPK;
};

const int jumlah_max = 100;

int main(){
    biodata daftar_mahasiswa[jumlah_max];
    int jumlah_mahasiswa = 0;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tambah Data Mahasiswa" << endl;
        cout << "2. Tampilkan Data Mahasiswa" << endl;
        cout << "3. Ubah Data Mahasiswa" << endl;
        cout << "4. Hapus Data Mahasiswa" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: \n";
        
        int menu;
        cin >> menu;

        switch (menu) {
            case 1: {
                if (jumlah_mahasiswa < jumlah_max) {
                    biodata mahasiswa;
                    cout << "\n" << "Masukkan biodata mahasiswa: \n";
                    cout << "Nama : ";
                    cin.ignore();
                    getline(cin, mahasiswa.nama);
                    cout << "NRP : ";
                    cin >> mahasiswa.NRP;
                    cout << "Umur : ";
                    cin >> mahasiswa.umur;
                    cout << "Keahlian : ";
                    cin >> mahasiswa.keahlian;
                    cout << "Hobi : ";
                    cin >> mahasiswa.hobi;
                    cout << "Asal : ";
                    cin >> mahasiswa.asal;
                    cout << "Tgl Lahir : ";
                    cin >> mahasiswa.tgl_lahir;
                    cout << "Tahun Masuk : ";
                    cin >> mahasiswa.tahun_masuk;
                    cout << "IPS : ";
                    cin >> mahasiswa.IPS;
                    cout << "IPK : ";
                    cin >> mahasiswa.IPK;
                    cout << "\n";
                    daftar_mahasiswa[jumlah_mahasiswa] = mahasiswa;
                    jumlah_mahasiswa++;
                } else {
                    cout << "Jumlah maksimum mahasiswa telah tercapai." << endl;
                }
                break;
            }
            case 2: {
                cout << "\n" << "Daftar Mahasiswa:" << endl;
                for (int i = 0; i < jumlah_mahasiswa; i++) {
                    cout << "Nama: " << daftar_mahasiswa[i].nama << "\nNRP: " << daftar_mahasiswa[i].NRP << "\nUmur: " << daftar_mahasiswa[i].umur << "\nKeahlian: " << daftar_mahasiswa[i].keahlian << "\n"
                    << "Hobi: " << daftar_mahasiswa[i].hobi << "\nAsal: " << daftar_mahasiswa[i].asal << "\nTgl Lahir: " << daftar_mahasiswa[i].tgl_lahir << "\nTahun Masuk: " << daftar_mahasiswa[i].tahun_masuk << "\n"
                    << "IPS: " << daftar_mahasiswa[i].IPS << "\nIPK: " << daftar_mahasiswa[i].IPK << "\n\n";
                }
                break;
            }
            case 3: {
                int index;
                cout << "\n" << "Masukkan indeks mahasiswa yang ingin diubah: ";
                cin >> index;

                if (index >= 0 && index < jumlah_mahasiswa) {
                    cout << "Masukkan biodata mahasiswa baru: \n";
                    cout << "Nama : ";
                    cin.ignore();
                    getline(cin, daftar_mahasiswa[index].nama);
                    cout << "NRP : ";
                    cin >> daftar_mahasiswa[index].NRP;
                    cout << "Umur : ";
                    cin >> daftar_mahasiswa[index].umur;
                    cout << "Keahlian : ";
                    cin >> daftar_mahasiswa[index].keahlian;
                    cout << "Hobi : ";
                    cin >> daftar_mahasiswa[index].hobi;
                    cout << "Asal : ";
                    cin >> daftar_mahasiswa[index].asal;
                    cout << "Tgl Lahir : ";
                    cin >> daftar_mahasiswa[index].tgl_lahir;
                    cout << "Tahun Masuk : ";
                    cin >> daftar_mahasiswa[index].tahun_masuk;
                    cout << "IPS : ";
                    cin >> daftar_mahasiswa[index].IPS;
                    cout << "IPK : ";
                    cin >> daftar_mahasiswa[index].IPK;
                    cout << "\n";
                } else {
                    cout << "Indeks tidak valid." << endl;
                }
                break;
            }
            case 4: {
                int index;
                cout << "\n" << "Masukkan indeks mahasiswa yang ingin dihapus: ";
                cin >> index;

                if (index >= 0 && index < jumlah_mahasiswa) {
                    for (int i = index; i < jumlah_mahasiswa - 1; i++) {
                        daftar_mahasiswa[i] = daftar_mahasiswa[i + 1];
                    }
                    jumlah_mahasiswa--;
                } else {
                    cout << "Indeks tidak valid." << endl;
                }
                break;
            }
            case 5:
                return 0;
            default:
                cout << "\n" << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}
