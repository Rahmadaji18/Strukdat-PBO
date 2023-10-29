#include <iostream>
#include <string>
#include <vector>
using namespace std;

int hitungBunga(int tinggi) {
    if (tinggi == 0) {
        return 1;
    }
    if (tinggi == 1) {
        return 2;
    }

    return 1 + hitungBunga(tinggi - 1) + hitungBunga(tinggi - 2);
}

int main() {
    int H;
    string input;
    vector<int> hasil;

    while (true) {
        cin >> input;

        if (input == "DONE") {
            break;
        }

        try {
            H = stoi(input);
            if (H < 0 || H > 30) {
                cout << "salah bro" << endl;
            } else {
                int result = hitungBunga(H);
                hasil.push_back(result);
            }
        } catch (const invalid_argument& e) {
            continue;
        }
    }

    for (int i = 0; i < hasil.size(); i++) {
        cout << hasil[i] << endl;
    }

    return 0;
}
