#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include "users.hpp"

using namespace std;

Users::Users()
{
  elementNum = 0;
  elements = nullptr;
  string email, name;
  int accessLvl;

  userData.open("/home/student/Documents/lab09-atakux/users.dat", ifstream::in);

  if(userData)
  {
    while(!userData.eof())
    {
      userData.ignore();
      getline(userData, email);
      getline(userData, name);
      userData >> accessLvl;

      addUser(email, name, accessLvl);
    }
    userData.close();
  }
}



Users::~Users()
{

  delete [] elements;
}


int Users::getElementNum(string email)
{
  for(int i = 0; i < elementNum; i++)
  {
    if(elements[i].email == email)
    {
      return i;
    }
  }
  return -1;
}


void Users::addUser(string email, string name, int access)
{
  User * temp = nullptr;
  temp = new User[elementNum + 1];

  for(int i = 0; i < elementNum; i++)
  {
    temp[i].email = elements[i].email;
    temp[i].name = elements[i].name;
    temp[i].accessLvl = elements[i].accessLvl;
  }

  temp[elementNum].email = email;
  temp[elementNum].name = name;
  temp[elementNum].accessLvl = access;

  if(elementNum > 0)
    delete [] elements;

  elements = nullptr;
  elements = temp;

  elementNum++;
}

void Users::modifyUser(string email, string name, int access)
{
    int temp = getElementNum(email);

    if(temp >= 0)
    {
      elements[temp].name = name;
      elements[temp].accessLvl = access;
    }
}

void Users::deleteUser(string email)
{
  User * temp = nullptr;
  temp = new User[elementNum - 1];
  int count = 0;

  for(int i = 0; i < elementNum; i++)
  {
    if(elements[i].email != email)
    {
      temp[count].email = elements[i].email;
      temp[count].name = elements[i].name;
      temp[count].accessLvl = elements[i].accessLvl;
      count++;
    }
  }
  if(elementNum > 0)
    delete [] elements;

  elements = nullptr;
  elements = temp;

  elementNum--;
}