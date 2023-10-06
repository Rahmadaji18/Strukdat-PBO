#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, map<string, string> > dataAkun;

// Vigenere Hash Function
string vigenereHash(string password, string key)
{
    string hash = "";
    for (size_t i = 0; i < password.length(); i++) {
        char c = password[i];
        char k = key[i % key.length()]; // Loop key jika lebih pendek dari password
        char hashedChar = 'a' + ((c - 'a' + k - 'a') % 26); // Enkripsi vigenere
        hash += hashedChar;
    }
    return hash;
}

void registerAkun()
{
    string username, password, fullname;
    cout << "Masukkan Username: " << endl;
    cin >> username;
    cout << "Masukkan Password: " << endl;
    cin >> password;
    cout << "Masukkan Nama Lengkap: " << endl;
    cin >> fullname;

    // Gunakan password sebagai key Vigenere
    string hash_key = vigenereHash(password, password);

    map<string, string> dataDetail;
    dataDetail["username"] = username;
    dataDetail["fullname"] = fullname;

    // masukkan ke map
    dataAkun[hash_key] = dataDetail;
}

void loginAkun()
{
    string username, password;
    cout << "Masukkan Username: " << endl;
    cin >> username;
    cout << "Masukkan Password: " << endl;
    cin >> password;

    string hash_key = vigenereHash(password, password);

    cout << endl;
    if (dataAkun.find(hash_key) != dataAkun.end())
    {
        cout << "Login berhasil!" << endl << endl;
        cout << "==== Account Details ====" << endl;
        cout << "Username: " << dataAkun[hash_key]["username"] << endl;
        cout << "Fullname: " << dataAkun[hash_key]["fullname"] << endl;
    }
    else {
        cout << "Login gagal!" << endl << endl;
    }
}

void printAkun()
{
  cout << endl;
  for (auto i = dataAkun.begin(); i != dataAkun.end(); i++)
  {
    cout << "Key: " << i->first << "\t"
         << " Username: " << i->second["username"] << " Fullname: " << i->second["fullname"] << endl;
  }
}

// Menu
void menu()
{
  while (true)
  {
    int input_user;

    cout << endl;
    cout << "==== MENU ====" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;

    cout << endl;
    cout << "Pilih Menu: " << endl;
    cin >> input_user;

    if (input_user == 1)
    {
      registerAkun();
    }
    else if (input_user == 2)
    {
      loginAkun();
    }
    else if (input_user == 3)
    {
      printAkun();
      break;
    }
    else
    {
      cout << "Invalid!" << endl;
    }
  }
}

int main()
{
  menu();
}