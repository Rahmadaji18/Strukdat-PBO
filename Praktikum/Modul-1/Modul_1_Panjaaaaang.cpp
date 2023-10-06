#include <iostream>
using namespace std;

struct Data_jarak {
public:
    int data;
    Data_jarak* next;
    
    Data_jarak(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

struct LinkedList {
public:
    Data_jarak* head;
    
    LinkedList() {
        head = nullptr;
    }
    
    void input(int data) {
        Data_jarak* dataBaru = new Data_jarak(data);
        if (head == nullptr) {
            head = dataBaru;
        } else {
            Data_jarak* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = dataBaru;
        }
    }
    
    int hitung_jarak() {
        int JarakA = 0;
        Data_jarak* current = head;
        while (current != nullptr && current->data != 0) {
            JarakA++;
            current = current->next;
        }
        return JarakA;
    }
};

int main() {
    LinkedList listJarak;
    
    int JarakB;
    while (cin >> JarakB) {
        if (JarakB == 0) {
            break;
        }
        listJarak.input(JarakB);
    }
    
    int travelLength = listJarak.hitung_jarak();
    
    cout << travelLength << endl;
    
    return 0;
}
