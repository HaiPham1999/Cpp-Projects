#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string usr, pwd;

bool login(void) {
  string name, pass;
  fstream fd;

  std::cout << "Enter your username: ";
  std::cin >> usr;
  std::cout << "Enter your password: ";
  std::cin >> pwd;

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

  std::cout << "LOGIN AND REGISTRATION SYSTEM" << endl
            << "1. Login" << endl
            << "2. Registration" << endl;
  // std::cout << "1. Login" << endl;
  // std::cout << "2. Registration" << endl;
  std::cout << "Enter your choice: ";
  std::cin >> choice;

  if (choice == 1) {
    if (login())
      std::cout << "Login successfully!" << endl;
    else
      std::cout << "Login Failed!" << endl;
  }

  if (choice == 2) {
    std::cout << "Enter username: ";
    std::cin >> usr;
    std::cout << "Enter password: ";
    std::cin >> pwd;

    file.open("Info_" + usr + ".txt", ios::out | ios::app);
    file << usr << endl << pwd << endl;
    file.close();
  }

  return 0;
}
