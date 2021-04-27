#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../users.hpp"
#include "gtest_ext.h"

using ::testing::HasSubstr;

TEST(Users, getElementNumForInvalidEmail) {
  Users userList;
  ASSERT_EQ(userList.getElementNum("invalidemail@domainname.com"), -1) << "### ERROR calling getElementNum given an invalid email, the number of elements should be  \'-1\' ###";
}

TEST(Users, addUser) {
  Users userList;
  userList.addUser("testuser@abc.com","Test User",2);
  int elementNum = userList.getElementNum("testuser@abc.com");
  string getEmailReturn = userList.getEmail(elementNum);
  if(elementNum >= 0)
     userList.deleteUser("testuser@abc.com");

  ASSERT_EQ(getEmailReturn, "testuser@abc.com") << "### ERROR calling addUser, the email should be \'testuser@abc.com\' ###";
}

TEST(Users, modifyUser) {
  Users userList;
  userList.addUser("testuser@abc.com","Test User",2);
  int elementNum = userList.getElementNum("testuser@abc.com");
  userList.modifyUser("testuser@abc.com","Test User Modified",1);
  string getNameReturn = userList.getName(elementNum);
  unsigned short getAccessReturn = userList.getAccess(elementNum);
  if(elementNum >= 0)
     userList.deleteUser("testuser@abc.com");

  ASSERT_EQ(getNameReturn, "Test User Modified") << "### ERROR calling modifyUser, the Name should be \'Test User Modified\' ###";
  ASSERT_EQ(getAccessReturn, 1) << "### ERROR calling modifyUser, the Access should be \'1\' ###";
}

TEST(Users, deleteUser) {
  Users userList;
  userList.addUser("testuser@abc.com","Test User",2);
  userList.deleteUser("testuser@abc.com");
  int elementNum = userList.getElementNum("testuser@abc.com");

  ASSERT_EQ(elementNum, -1) << "### ERROR calling deleteUser, the getElementNumber should be \'-1\' when a test user is added then deleted ###";
}


/*
TEST(Users, addUser) {
  Users userList;
  userList.addUser("testuser@abc.com","Test User",2);
  int elementNum = userList.getElementNum("testuser@abc.com");
  ASSERT_EQ(userList.getEmail(elementNum), "testuser@abc.comx") << "### ERROR calling addUser, the email should be \'testuser@abc.com\' ###";
  if(elementNum >= 0)
     userList.deleteUser("testuser@abc.com");
}
*/

/*
TEST(Products, ProductEntry) {
  Products products;
  products.setProduct(1234,"Test",79.58);
  ASSERT_EQ(products.getNameFromElement(0), "Test") << "### ERROR calling getNameFromElement when setProduct was called providing the Name \'Test\', it was not returned.###";
}

TEST(Products, ProductSearch) {
  Products products;
  products.setProduct(9476,"Apple",0.58);
  products.setProduct(6392,"Banana",1.00);
  products.setProduct(112,"Cereal",4.59);
  products.setProduct(7562,"Coffee",7.56);
  products.setProduct(5295,"Milk",3.29);
  products.setProduct(4439,"Butter",5.00);
  ASSERT_EQ(products.getNameFromCode(4439), "Butter") << "### ERROR calling getNameFromCode when setProduct was called providing the Name \'Butter\', it was not returned.###";
}

TEST(Products, ProductSearchFail) {
  Products products;
  products.setProduct(9476,"Apple",0.58);
  products.setProduct(6392,"Banana",1.00);
  products.setProduct(112,"Cereal",4.59);
  products.setProduct(7562,"Coffee",7.56);
  products.setProduct(5295,"Milk",3.29);
  products.setProduct(4439,"Butter",5.00);
  ASSERT_EQ(products.getNameFromCode(555), "") << "### ERROR calling getNameFromCode when invalid code was searched, should have returned an empty string.###";
}
*/
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
    return RUN_ALL_TESTS();
}
