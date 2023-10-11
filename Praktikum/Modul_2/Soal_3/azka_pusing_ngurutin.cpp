#include <iostream>
#include <string>

using namespace std;

struct Node {
  char data;
  Node* left;
  Node* right;
};

Node* createNode(char data) {
  Node* newNode = new Node();
  newNode->data = data;
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode;
}

void insert(Node* root, char data) {
  if (root == nullptr) {
    root = createNode(data);
    return;
  }

  if (data < root->data) {
    insert(root->left, data);
  } else {
    insert(root->right, data);
  }
}

void inorder(Node* root) {
  if (root == nullptr) {
    return;
  }

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

int main() {
  string input;
  getline(cin, input);

  Node* root = nullptr;
  for (char c : input) {
    insert(root, c);
  }

  inorder(root);
  cout << endl;

  return 0;
}
