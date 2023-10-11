#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    getline(cin, input);

    string output = "";

    for (char c : input) {
        if (c != ' ') {
            int ascii_value = int(c); // Mengambil nilai ASCII dari karakter
            output += char(ascii_value); // Mengonversi nilai ASCII ke karakter dan memasukkannya ke output
        } else {
            output += ' '; // Menambahkan spasi sesuai dengan format
        }
    }

    cout << output << endl;

    return 0;
}
