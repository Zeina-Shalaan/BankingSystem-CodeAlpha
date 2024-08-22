#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct USER
{
    string UserName;
    string Password;
};

void RegisterUser (USER info)
{
    cout  << "Enter Your UserName: ";
    cin >> info.UserName;

    cout << "Enter Your Password: ";
    cin >> info.Password;

    ifstream infile(info.UserName + ".txt");
    if (infile.good())
    {
        cout << "Username already exists. Please choose a different username." << endl;
        return;
    }

    // Create and write to a file with the username as the filename
    ofstream outfile(info.UserName + ".txt");
    outfile << info.UserName << endl;
    outfile << info.Password << endl;

    outfile.close();
    cout << "Registration successful!" << endl;
}

bool LoginUser (USER login)
{
    cout  << "Enter Your UserName: ";
    cin >> login.UserName;

    cout << "Enter Your Password: ";
    cin >> login.Password;

    ifstream infile(login.UserName + ".txt");
    if (!infile.good())
    {
        cout << "Username not found." << endl;
        return false;
    }
    string storedUsername, storedPassword;
    infile >> storedUsername >> storedPassword;

    infile.close();

    if (storedUsername == login.UserName && storedPassword == login.Password)
    {
        cout << "Login successful!" << endl;
        return true;
    } else
    {
        cout << "Invalid password." << endl;
        return false;
    }
}



int main()
{
    USER user;
    int choice;

    do
    {
        cout << " 1. Register New User ... " << endl;
        cout << " 2. Login with previous data ... " << endl;
        cout << " 3. Exit ... " << endl;
        cout << "Enter Your Choice : "<<endl;
        cin >> choice;



    switch (choice)
    {
    case 1:
        RegisterUser(user);
        break;
    case 2:
       if (LoginUser(user))
       {
           cout << "Welcome back " << user.UserName << " .. !"<<endl;
       }
       break;
    case 3:
        cout << "Exiting Program Now ..... "<<endl;
        break;
    default:
        cout << "Invalid Choice (1-3)";
    }
}while(choice != 3);


    return 0;
}
