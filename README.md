# Laboratory Exercise

## Laboratory Objectives
1. Explore and use various tools such as: GitHub, VirtualBox, Tuffix, Linux Terminal, and Atom.
1. Write and compile C++ code using:
     1. dynamic memory allocation and deallocation
     2. search and sorting
     3. file access
1. Run and test executable files.

## Getting Started
1. Open the Terminal program in Tuffix.
1. Change the present working directory to the `Documents` directory by typing the following command at the command prompt:

    ```
    cd Documents
    ```

1. Make a copy of this Github repository on your computer using the `git` and `clone` commands that you will input to the terminal. The commands take a URL as a parameter to specify where it can get a copy of the repository. You can find the URL by clicking on the green *Clone or download* button at the top right part of this page. Copy the URL and replace the example text shown below. Note that `username` should be replaced with your own Github username. When you hit <kbd>Enter</kbd> it will ask you to provide your Github username and password. Once done, you will have a copy of the repository on your computer.
    ```
    git clone https://github.com/CSUF-CPSC121-STMAY-2021S/lab09-username.git
    ```
1. Navigate into the new directory using the command line. Note that `username` should be replaced with your own Github username.  As a shortcut, you can type the first few letters of the folder name and press <kbd>Tab</kbd> so that it auto completes the folder name for you.

     ```
     cd lab09-username
     ```
     
## Instructions
1. Title Comment Block
     1. Create your source code file named `main.cpp`, and at the very top of the source code use three one line comments to document your name, date, and the exercise, using the following format:
          <pre>Name: <i>Stephen May</i><br>Date: 01/01/2021<br>Exercise: Labxx Solution</pre>



1. Write a C++ program that performs as a Tuffy Titan Tuffix User Accounts program which presents the user a main menu to list the user accounts, add a user, modify a user, delete a user, or exit the program.

1. Your Users class should meet the following requirements:
     1. Declare a `Users` class in a specification file named `users.hpp`.
     1. Define all member functions that are not inline member functions in an implementation file named `users.cpp`.
     1. Declare a constructor member function that initializes a member variable to zero which will keep track of the number of elements in a dynamically allocated array, and then read a file named `users.dat` located in the present working director and store the contents in a dynamically allocated array of users with each element containing the user email, name, and access level.  Be sure to increase the member variable that keeps track of the number of elements in the array of users as you read the file and store the contents in the array of users.  Ensure your file name contains the complete path name when opening the file.  NOTE: The file is not provided with the repository and will be created after your program adds users and the destructor is called.
     1. Declare a public member function named `getNumElements` to return the number of users.
     1. Declare a public member function named `getElementNum` to return the element number in the list given an email of a user.
     1. Declare a public member function named `getEmail` to return the email given an element number in the list.
     1. Declare a public member function named `getName` to return the name given an element number in the list.
     1. Declare a public member function named `getAccess` to return the access given an element number in the list.  NOTE: The access levels should be stored as integers but printed as strings in the report where level 1 is admin and level 2 basic.
     1. Declare a public member function named `addUser` given the email, name, and access of a user.  Users should be kept sorted by the email in accessing order.
     1. Declare a public member function named `modifyUser` given the email, name, and access of a user.
     1. Declare a public member function named `deleteUser` given the email of a user.
     1. Declare a destructor member function that writes the array of users to the `users.dat` file and then deletes the memory associated with the array of users.

1. Compile the file using the command below. The `-std` option tells the compiler that it will use C++ version 17 standards and the `-o main` option tells the compiler to place the executable code into a file called `main`.

    ```
    clang++ -std=c++17 main.cpp users.cpp -o main
    ```
1. Run the program using the command below and repeat the steps above until you are satisfied your program output meets the above requirements.  I strongly suggest that you run your program using each of the sample outputs below and ensure that all blank lines and new lines are exactly as below.

    ```
    ./main
    ```


1. Typical input and output for the program for menu selection 1:
     ```
             *** TUFFY TITAN TUFFIX USER ACCOUNTS MAIN MENU ***

     1) Display user accounts
     2) Add user account
     3) Modify user account
     4) Delete user account
     5) Exit the program

     Enter your choice: 1

     ====================== USER ACCOUNTS =========================

     eMail                          Name                 Access
     ============================== ==================== ==========
     billgates@microsoft.com        Bill Gates           basic     
     markzuckerberg@facebook.com    Mark Zuckerberg      basic     
     stevejobs@apple.com            Steve Jobs           admin     

             *** TUFFY TITAN TUFFIX USER ACCOUNTS MAIN MENU ***

     1) Display user accounts
     2) Add user account
     3) Modify user account
     4) Delete user account
     5) Exit the program

     Enter your choice: 5
     ```

1. Typical input and output for the program for menu selection 2:
     ```
             *** TUFFY TITAN TUFFIX USER ACCOUNTS MAIN MENU ***

     1) Display user accounts
     2) Add user account
     3) Modify user account
     4) Delete user account
     5) Exit the program

     Enter your choice: 2
     Enter eMail: tuffytitan@fullerton.edu
     Enter name: Tuffy Titan
     Enter access (1=admin 2=basic): 1

             *** TUFFY TITAN TUFFIX USER ACCOUNTS MAIN MENU ***

     1) Display user accounts
     2) Add user account
     3) Modify user account
     4) Delete user account
     5) Exit the program

     Enter your choice: 1

     ====================== USER ACCOUNTS =========================

     eMail                          Name                 Access
     ============================== ==================== ==========
     billgates@microsoft.com        Bill Gates           basic     
     markzuckerberg@facebook.com    Mark Zuckerberg      basic     
     stevejobs@apple.com            Steve Jobs           admin     
     tuffytitan@fullerton.edu       Tuffy Titan          admin     

             *** TUFFY TITAN TUFFIX USER ACCOUNTS MAIN MENU ***

     1) Display user accounts
     2) Add user account
     3) Modify user account
     4) Delete user account
     5) Exit the program

     Enter your choice: 5
     ```

1. Typical input and output for the program for menu selection 3:
     ```
             *** TUFFY TITAN TUFFIX USER ACCOUNTS MAIN MENU ***

     1) Display user accounts
     2) Add user account
     3) Modify user account
     4) Delete user account
     5) Exit the program

     Enter your choice: 3
     Enter eMail: stevejobs@apple.com
     Current name is Steve Jobs, enter new name: Steve Jobs CEO
     Current access is 1, enter new access (1=admin 2=basic): 2

             *** TUFFY TITAN TUFFIX USER ACCOUNTS MAIN MENU ***

     1) Display user accounts
     2) Add user account
     3) Modify user account
     4) Delete user account
     5) Exit the program

     Enter your choice: 1

     ====================== USER ACCOUNTS =========================

     eMail                          Name                 Access
     ============================== ==================== ==========
     billgates@microsoft.com        Bill Gates           basic     
     markzuckerberg@facebook.com    Mark Zuckerberg      basic     
     stevejobs@apple.com            Steve Jobs CEO       basic     
     tuffytitan@fullerton.edu       Tuffy Titan          admin     

             *** TUFFY TITAN TUFFIX USER ACCOUNTS MAIN MENU ***

     1) Display user accounts
     2) Add user account
     3) Modify user account
     4) Delete user account
     5) Exit the program

     Enter your choice: 5
     ```

1. Typical input and output for the program for menu selection 4:
     ```
             *** TUFFY TITAN TUFFIX USER ACCOUNTS MAIN MENU ***

     1) Display user accounts
     2) Add user account
     3) Modify user account
     4) Delete user account
     5) Exit the program

     Enter your choice: 4
     Enter eMail: billgates@microsoft.com

             *** TUFFY TITAN TUFFIX USER ACCOUNTS MAIN MENU ***

     1) Display user accounts
     2) Add user account
     3) Modify user account
     4) Delete user account
     5) Exit the program

     Enter your choice: 1

     ====================== USER ACCOUNTS =========================

     eMail                          Name                 Access
     ============================== ==================== ==========
     markzuckerberg@facebook.com    Mark Zuckerberg      basic     
     stevejobs@apple.com            Steve Jobs CEO       basic     
     tuffytitan@fullerton.edu       Tuffy Titan          admin     

             *** TUFFY TITAN TUFFIX USER ACCOUNTS MAIN MENU ***

     1) Display user accounts
     2) Add user account
     3) Modify user account
     4) Delete user account
     5) Exit the program

     Enter your choice: 5
     ```

1. Run the unit testing program to ensure that your program runs as expected using predefined user input.

    ```
    make test
    ```
    
    <i>Note: You will be prompted to install the cmake program the first time you run the make test command on the device you are working on.  Answer `Yes` to install the program, and you will need to enter the Tuffix superuser (sudo) password, which should be `student`. After you have installed the cmake program, run the `make test` command again.</i>
    
    The unit testing will output the results of a series of tests using specific input and expected output.  Any error will stop the unit testing and will provide information on where the expected output is different from the actual output.  You will need to edit your source code to fix the error, recompile your program, and run `make test` repeatedly until it passes all the test.

## Submission
Periodically throughout the exercise, and when you have completed the exercise, **submit the complete repository to Github**.

   <pre>git add .<br>git commit -m "<i>your comment</i>"<br>git push</pre>

In case it asks you  to configure global variables for an email and name, just copy the commands it provides then replace the dummy text with your email and Github username.

   <pre>git config --global user.email "<i>tuffy@csu.fullerton.edu</i>"<br>git config --global user.name "<i>Tuffy Titan</i>"<br>git commit -m "<i>your comment</i>"<br>git push</pre>

When you completed the final Github push, go back into github.com through the browser interface and ensure all your files have been correctly updated.  You should have the following files:
    <pre>main.cpp<br>main<br>users.hpp<br>users.cpp<br>unittest.xml (in the test folder)</pre>
    
## Grading
1. All points add up to a total of 100 points possible as detailed below.  Partial credit will be given where applicable.

| Points | Description |
| --- | --- |
|50|initial git clone of this repository to your Tuffix machine|
|5|main.cpp file submitted contains the main program structure and meets the program requirements|
|5|main executable file submitted runs without crashing|
|10|users.hpp file submitted contains the Products class declaration and meets the program requirements|
|10|users.cpp file submitted contains the Products class member functions and meets the program requirements|
|20|unit testing results submitted pass each test|
