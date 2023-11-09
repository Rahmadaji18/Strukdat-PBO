#include <iostream>
#include <list>
#include <stdio.h>
#include "graphics.h"
using namespace std;

class Titik {
private:
    int id;
    string nama;
    int x;
    int y;

public:
    Titik(int id, string nama, int x, int y) {
        this->id = id;
        this->nama = nama;
        this->x = x;
        this->y = y;
    }

    Titik() {
        id = 0;
        nama = "";
        x = 0;
        y = 0;
    }

    int getID() {
        return id;
    }

    string getNama() {
        return nama;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
};

class Peta {
private:
    int jumlah_titik;
    list<int> *adjacency_list;
    int **adjacency_matrix;
    Titik *titik_info;

public:
    Peta(int jumlah_titik) {
        this->jumlah_titik = jumlah_titik;
        this->inisialisasiAdjList(jumlah_titik);
        this->inisialisasiAdjMatrix(jumlah_titik);
        this->inisialisasiTitikInfo();
    }

    ~Peta() {
        delete[] adjacency_list;
        for (int i = 0; i < jumlah_titik; i++) {
            delete[] adjacency_matrix[i];
        }
        delete[] adjacency_matrix;
        delete[] titik_info;
    }

    void inisialisasiAdjList(int jumlah_titik) {
        adjacency_list = new list<int>[jumlah_titik];
    }

    void inisialisasiAdjMatrix(int jumlah_titik) {
        adjacency_matrix = new int *[jumlah_titik];
        for (int i = 0; i < jumlah_titik; i++) {
            adjacency_matrix[i] = new int[jumlah_titik];
            for (int j = 0; j < jumlah_titik; j++) {
                adjacency_matrix[i][j] = 0;
            }
        }
    }

    void inisialisasiTitikInfo() {
        titik_info = new Titik[jumlah_titik];
        titik_info[0] = Titik(0, "Minimarket", -10, -20);
        titik_info[1] = Titik(1, "Masjid", 15, -20);
        titik_info[2] = Titik(2, "Sekolah SD", 40, -20);
        titik_info[3] = Titik(3, "Toko Sepatu", 40, 0);
        titik_info[4] = Titik(4, "Toko Buku", 30, 0);
        titik_info[5] = Titik(5, "Rumah", 0, 0);
        titik_info[6] = Titik(6, "Panti Asuhan", -40, 0);
        titik_info[7] = Titik(7, "Sekolah SMP", -60, 0);
        titik_info[8] = Titik(8, "Gereja", -60, 100);
        titik_info[9] = Titik(9, "Pemakaman", -20, 100);
        titik_info[10] = Titik(10, "Pasar", 15, 100);
        titik_info[11] = Titik(11, "Gelora Pancasila", 40, 100);
    }

    void tambahLintasan(int titik_awal, int titik_tujuan) {
        adjacency_list[titik_awal].push_back(titik_tujuan);
        adjacency_list[titik_tujuan].push_back(titik_awal);

        adjacency_matrix[titik_awal][titik_tujuan] = 1;
        adjacency_matrix[titik_tujuan][titik_awal] = 1;
    }

    void tampilkanAdjList() {
        for (int v = 0; v < jumlah_titik; v++) {
            cout << titik_info[v].getNama() << " (" << titik_info[v].getX() << ", " << titik_info[v].getY() << ")";
            auto neighbors = adjacency_list[v].begin();

            if (neighbors != adjacency_list[v].end()) {
                cout << " -> ";
                while (true) {
                    int tujuan = *neighbors;
                    cout << titik_info[tujuan].getNama() << " (" << titik_info[tujuan].getX() << ", " << titik_info[tujuan].getY() << ")";
                    ++neighbors;

                    if (neighbors != adjacency_list[v].end()) {
                        cout << " -> ";
                    } else {
                        break;
                    }
                }
            }
            cout << endl;
        }
    }

    void tampilkanAdjMatrix() {
        for (int i = 0; i < jumlah_titik; i++) {
            for (int j = 0; j < jumlah_titik; j++) {
                cout << adjacency_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void drawGraph() {
    initwindow(640, 480, "Graph Peta");
    setbkcolor(WHITE);
    cleardevice();

    char tempName[100];

    for (int v = 0; v < jumlah_titik; v++) {
        circle(titik_info[v].getX(), titik_info[v].getY(), 20);
        strcpy(tempName, titik_info[v].getNama().c_str());
        outtextxy(titik_info[v].getX() - 10, titik_info[v].getY() - 10, tempName);
    }

    for (int v = 0; v < jumlah_titik; v++) {
        for (const int &tujuan : adjacency_list[v]) {
            line(titik_info[v].getX(), titik_info[v].getY(), titik_info[tujuan].getX(), titik_info[tujuan].getY());

            int midX = (titik_info[v].getX() + titik_info[tujuan].getX()) / 2;
            int midY = (titik_info[v].getY() + titik_info[tujuan].getY()) / 2;

            setcolor(BLACK);
            char label[100];
            sprintf(label, "%d", adjacency_matrix[v][tujuan]);
            outtextxy(midX - 10, midY - 10, label);
        }
    }

    getch();
    closegraph();
}

};

int main() {
    cout << "Peta Rumah" << endl;
    int jumlah_titik = 12;

    Peta petaKu(jumlah_titik);

    petaKu.tambahLintasan(0, 1);
    petaKu.tambahLintasan(0, 5);
    petaKu.tambahLintasan(0, 6);
    petaKu.tambahLintasan(1, 0);
    petaKu.tambahLintasan(1, 2);
    petaKu.tambahLintasan(2, 1);
    petaKu.tambahLintasan(2, 3);
    petaKu.tambahLintasan(3, 2);
    petaKu.tambahLintasan(3, 4);
    petaKu.tambahLintasan(4, 3);
    petaKu.tambahLintasan(4, 5);
    petaKu.tambahLintasan(5, 4);
    petaKu.tambahLintasan(5, 0);
    petaKu.tambahLintasan(5, 6);
    petaKu.tambahLintasan(6, 7);
    petaKu.tambahLintasan(7, 8);
    petaKu.tambahLintasan(7, 6);
    petaKu.tambahLintasan(8, 9);
    petaKu.tambahLintasan(9, 10);
    petaKu.tambahLintasan(9, 5);
    petaKu.tambahLintasan(10, 11);
    petaKu.tambahLintasan(10, 9);
    petaKu.tambahLintasan(11, 10);

    cout << endl;
    cout << "Adjacency List" << endl;
    petaKu.tampilkanAdjList();

    cout << endl;
    cout << "Adjacency Matrix" << endl;
    petaKu.tampilkanAdjMatrix();

    petaKu.drawGraph();

    return 0;
}
