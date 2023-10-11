#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;

    Node(int nilai) : data(nilai), kiri(nullptr), kanan(nullptr) {}
};

struct BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    void masukkan(int nilai) {
        root = masukkanRec(root, nilai);
    }

    void traversalInorder() {
        traversalInoderRec(root);
    }

private:
    Node* root;

    Node* masukkanRec(Node* root, int nilai) {
        if (root == nullptr) {
            return new Node(nilai);
        }

        if (nilai < root->data) {
            root->kiri = masukkanRec(root->kiri, nilai);
        } else if (nilai > root->data) {
            root->kanan = masukkanRec(root->kanan, nilai);
        }

        return root;
    }

    void traversalInoderRec(Node* root) {
        if (root != nullptr) {
            traversalInoderRec(root->kiri);
            cout << root->data << " ";
            traversalInoderRec(root->kanan);
        }
    }
};

int main() {
    BinarySearchTree bst;

    for (int i = 0; i < 100; ++i) {
        int nilai;
        if (!(cin >> nilai)) {
            break;
        }
        bst.masukkan(nilai);
    }

    bst.traversalInorder();
    cout << endl;

    return 0;
}
