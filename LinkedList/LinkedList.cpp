#include <iostream>
#include <string>

using namespace std;

struct Node {
  string NRP;
  string nama;
  Node* next;
};

class LinkedList {
public:
  LinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  ~LinkedList() {
    Node* currentNode = head;
    while (currentNode != nullptr) {
      Node* nextNode = currentNode->next;
      delete currentNode;
      currentNode = nextNode;
    }
  }

  void addFirst(const string& NRP, const string& nama) {
    Node* newNode = new Node;
    newNode->NRP = NRP;
    newNode->nama = nama;
    newNode->next = head;

    if (head == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      head->next = newNode;
      head = newNode;
    }
  }

  void addLast(const string& NRP, const string& nama) {
    Node* newNode = new Node;
    newNode->NRP = NRP;
    newNode->nama = nama;
    newNode->next = nullptr;

    if (head == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  Node* findByNRP(const string& NRP) {
    Node* currentNode = head;
    while (currentNode != nullptr) {
      if (currentNode->NRP == NRP) {
        return currentNode;
      }
      currentNode = currentNode->next;
    }

    return nullptr;
  }

  void removeByNRP(const string& NRP) {
    Node* previousNode = nullptr;
    Node* currentNode = head;

    while (currentNode != nullptr) {
      if (currentNode->NRP == NRP) {
        if (previousNode == nullptr) {
          head = currentNode->next;
        } else {
          previousNode->next = currentNode->next;
        }

        if (currentNode == tail) {
          tail = previousNode;
        }

        delete currentNode;
        break;
      }

      previousNode = currentNode;
      currentNode = currentNode->next;
    }
  }

  void printAll() {
    Node* currentNode = head;
    while (currentNode != nullptr) {
      cout << "NRP: " << currentNode->NRP << endl;
      cout << "Nama: " << currentNode->nama << endl;
      currentNode = currentNode->next;
    }
  }

  void addDataFromUser() {
    cout << "Masukkan data mahasiswa (NRP, nama): ";

    string NRP, nama;
    cin >> NRP >> nama;

    addLast(NRP, nama);
  }

private:
  Node* head;
  Node* tail;
};

int main() {
  LinkedList linkedList;

  char choice;
  do {
    cout << "1. Tambah data mahasiswa" << endl;
    cout << "2. Cari data mahasiswa" << endl;
    cout << "3. Hapus data mahasiswa" << endl;
    cout << "4. Tampilkan semua data mahasiswa" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih operasi (1/2/3/4/5): ";
    cin >> choice;

    switch (choice) {
      case '1': {
        linkedList.addDataFromUser();
        break;
      }
      case '2': {
        string NRP;
        cout << "Masukkan NRP yang ingin dicari: ";
        cin >> NRP;
        Node* node = linkedList.findByNRP(NRP);
        if (node != nullptr) {
          cout << "Data mahasiswa ditemukan:" << endl;
          cout << "NRP: " << node->NRP << endl;
          cout << "Nama: " << node->nama << endl;
        } else {
          cout << "Data mahasiswa tidak ditemukan" << endl;
        }
        break;
      }
      case '3': {
        string NRP;
        cout << "Masukkan NRP yang ingin dihapus: ";
        cin >> NRP;
        linkedList.removeByNRP(NRP);
        break;
      }
      case '4': {
        linkedList.printAll();
        break;
      }
      case '5': {
        cout << "Keluar dari program." << endl;
        break;
      }
      default: {
        cout << "Pilihan tidak valid. Pilih lagi." << endl;
        break;
      }
    }
  } while (choice != '5');

  return 0;
}
