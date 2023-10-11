#include <iostream>
using namespace std;

struct ListNode {
    int nilai;
    ListNode* selanjutnya;
};

void tambah_head(ListNode*& head, int nilai) {
    ListNode* node_baru = new ListNode;
    node_baru->nilai = nilai;
    node_baru->selanjutnya = head;
    head = node_baru;
}

void print_terbalik(ListNode* head) {
    if (head == nullptr) {
        return;
    }
    if (head->nilai != 0) {
        cout << head->nilai << " ";
    }
    print_terbalik(head->selanjutnya);
}

int main() {
    ListNode* head = nullptr;
    int input_nilai;
    
    while (true) {
        cin >> input_nilai;
        if (input_nilai == 0) {
            break;
        }
        tambah_head(head, input_nilai);
    }
    
    print_terbalik(head);

    while (head != nullptr) {
        ListNode* temp = head;
        head = head->selanjutnya;
        delete temp;
    }
    
    return 0;
}
