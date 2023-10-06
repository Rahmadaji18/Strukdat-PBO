#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    stack<int> tempSetack;
    vector<int> inputAngka;
    string input;

    while (cin >> input && input != "done") {
        int angka;
        stringstream(input) >> angka;
        inputAngka.push_back(angka);
    }

    sort(inputAngka.begin(), inputAngka.end(), greater<int>());

    for (int angka : inputAngka) {
        tempSetack.push(angka);
    }

    while (!tempSetack.empty()) {
        cout << tempSetack.top() << " ";
        tempSetack.pop();
    }

    cout << endl;

    return 0;
}
