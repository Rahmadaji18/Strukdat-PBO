#include <iostream>
using namespace std;

const int SIZE_ARR = 26;

// Hash Tab
struct HashTable
{
  string username, password;
} dataAkun[SIZE_ARR];

// Fungsi Caesar Cipher
string caesarCipher(string input, int shift)
{
  string result = "";
  for (char character : input)
  {
    if (isalpha(character))
    {
      char base = islower(character) ? 'a' : 'A';
      result += (base + (character - base + shift) % 26);
    }
    else
    {
      result += character;
    }
  }
  return result;
}

// Hash
int hashFunction(string password)
{
  string vokal = "AIUEO";
  string nonVokal = "BCDFGHJKLMNPQRSTUVWXYZ";
  
  int shift = 0;

  for (char character : password)
  {
    if (isalpha(character))
    {
      char base = islower(character) ? 'a' : 'A';
      if (vokal.find(character) != string::npos)
      {
        shift += vokal.find(character) + 1;
      }
      else if (nonVokal.find(character) != string::npos)
      {
        shift += nonVokal.find(character) + 1;
      }
    }
  }

  return shift % SIZE_ARR;
}

// Print all hash table
void printAll()
{
  for (int i = 0; i < SIZE_ARR; i++)
  {
    cout << i << " [ " << dataAkun[i].username << " - " << dataAkun[i].password << " ]" << endl;
  }
}

void menu()
{
  while (true)
  {
    int input_user;

    cout << endl;
    cout << "MENU" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl
         << endl;

    cout << "Pilih: " << endl;
    cin >> input_user;
    cout << endl;

    if (input_user == 1)
    {
      string username, password;

      cout << "Masukkan Username: " << endl;
      cin >> username;
      cout << "Masukkan Password: " << endl;
      cin >> password;

      int index = hashFunction(password);
      password = caesarCipher(password, index);

      if (dataAkun[index].username.empty() && dataAkun[index].password.empty())
      {
        dataAkun[index].username = username;
        dataAkun[index].password = password;
      }
      else
      {
        cout << "Akun sudah ada!" << endl;
      }
    }
    else if (input_user == 2)
    {
      // Menu Login
      cout << "Menu Login" << endl;
    }
    else if (input_user == 3)
    {
      printAll();
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
