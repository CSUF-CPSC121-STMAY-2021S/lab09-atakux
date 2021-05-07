#ifndef USERS_HPP
#define USERS_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

struct Memeber
{
  string email, name;
  int accessLvl;
};

class Users
{
private:
  fstream userData;
  int elementNum;
  Memeber * elements;

public:
  Users();

  int getNumElements()
  {
    return elementNum;
  }

  int getElementNum(string);


  string getEmail(int x)
  {
    return elements[x].email;
  }

  string getName(int x)
  {
    return elements[x].name;
  }

  int getAccess(int x)
  {
    return elements[x].accessLvl;
  }

  void addUser(string, string, int);
  void modifyUser(string, string, int);
  void deleteUser(string);

  ~Users();

};

#endif
