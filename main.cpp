//Name: Angela DeLeo
//Date: 04.26.2021
//Exercise: Lab09 Solution
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include "users.hpp"

using namespace std;

int main()
{
  Users u;
  int choice, lvl;
  string email, name, type;

  u.addUser("billgates@microsoft.com", "Bill Gates", 2);
  u.addUser("markzuckerberg@facebook.com", "Mark Zuckerberg", 2);
  u.addUser("stevejobs@apple.com", "Steve Jobs", 1);

  do {
    cout << "\t\t*** TUFFY TITAN TUFFIX USER ACCOUNTS MAIN MENU ***";
    cout << endl << endl;
    cout << "1) Display user accounts" << endl;
    cout << "2) Add user account" << endl;
    cout << "3) Modify user account" << endl;
    cout << "4) Delete user account" << endl;
    cout << "5) Exit the program" << endl;

    cout << endl << "Enter your choice: ";
    cin >> choice;

    switch (choice) {

      case 1:
        cout << endl << "====================== USER ACCOUNTS =========================" << endl;
        cout << "eMail                          Name                 Access" << endl;
        cout << "============================== ==================== ==========";
        for(int i = 0; i < u.getNumElements(); i++)
        {
          lvl = u.getAccess(i);
          if(lvl == 1)
            type = "admin";
          else if(lvl == 2)
            type = "basic";

          cout << left << setw(31) << u.getEmail(i)
               << left << setw(21) << u.getName(i)
               << right << setw(1) << type
               << setw(1) << setfill(' ') << endl;
        }
        break;

      case 2:
        cout << "Enter eMail: ";
        cin >> email;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter access (1=admin 2=basic): ";
        cin >> lvl;
        u.addUser(email, name, lvl);
        break;

      case 3:
        cout << "Enter eMail: ";
        cin >> email;
        for(int i = 0; i < u.getNumElements(); i++)
        {
          if(u.getEmail(i) == email)
          {
            cin.ignore();
            cout << "Current name is " << u.getName(i) << ", enter new name: ";
            getline(cin, name);

            cout << "Current access is " << u.getAccess(i) << ", enter new access (1=admin 2=basic): ";
            cin >> lvl;

            u.modifyUser(email, name, lvl);
          }
        }
        break;

      case 4:
        cout << "Enter eMail: ";
        cin >> email;

        for(int i = 0; i < u.getNumElements(); i++)
        {
          if(u.getEmail(i) == email)
          {
            u.deleteUser(email);
          }
        }
        break;
    }
  } while(choice != 5);


  return 0;
}
