#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
    
    Node(int nilai) : data(nilai), kiri(nullptr), kanan(nullptr) {}
};

Node* masukkan(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    
    if (data < root->data) {
        root->kiri = masukkan(root->kiri, data);
    } else if (data > root->data) {
        root->kanan = masukkan(root->kanan, data);
    }
    
    return root;
}

void printLeafNodes(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    if (root->kiri == nullptr && root->kanan == nullptr) {
        cout << root->data << " ";
    }
    
    printLeafNodes(root->kiri);
    printLeafNodes(root->kanan);
}

int main() {
    int n, nilai;
    Node* root = nullptr;

    cin >> n;

    if (n > 1000) {
        cout << "Bang udah Bang" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> nilai;
        root = masukkan(root, nilai);
    }

    printLeafNodes(root);

    delete root;

    return 0;
}
