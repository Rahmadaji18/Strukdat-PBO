#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool CekDestinasi(const string& destinasi) {
    int hitungO = 0;
    for (char c : destinasi) {
        if (toupper(c) == 'O') {
            hitungO++;
            if (hitungO > 2) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<string> semua_destinasi;
    string input;

    while (getline(cin, input) && input != "gasss") {
        if (!CekDestinasi(input)) {
            semua_destinasi.push_back(input);
        }
    }

    sort(semua_destinasi.begin(), semua_destinasi.end());

    for (const string& destinasi : semua_destinasi) {
        cout << destinasi << endl;
    }

    return 0;
}
