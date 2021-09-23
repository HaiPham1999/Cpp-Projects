#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string usr, pwd;

bool login(void) {
  string name, pass;
  fstream fd;

  cout << "Enter your username: ";
  cin >> usr;
  cout << "Enter your password: ";
  cin >> pwd;

  fd.open("Info_" + usr + ".txt", ios::in);
  getline(fd, name);
  getline(fd, pass);
  fd.close();

  if (name == usr && pass == pwd)
    return true;
  else
    return false;
}

int main(int argc, char const *argv[]) {
  int choice;
  fstream file;

  cout << "LOGIN AND REGISTRATION SYSTEM" << endl
       << "1. Login" << endl
       << "2. Registration" << endl;
  cout << "Enter your choice: ";
  cin >> choice;

  if (choice == 1) {
    if (login())
      cout << "Login successfully!" << endl;
    else
      cout << "Login Failed!" << endl;
  }

  if (choice == 2) {
    cout << "Enter username: ";
    cin >> usr;
    cout << "Enter password: ";
    cin >> pwd;

    file.open("Info_" + usr + ".txt", ios::out | ios::app);
    file << usr << endl << pwd << endl;
    file.close();
  }

  return 0;
}
