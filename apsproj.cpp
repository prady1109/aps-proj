#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
T get_input(const string &strQuery);
string get_username();
string get_password();
void save_user(const string &username, const string &password);
void login();
void register_user();
void main_menu();

template <typename T>
T get_input(const string &strQuery)
{
    cout << strQuery << "\n> ";
    T out = T();
    while (!(cin >> out))
    {
        cin.clear();
        cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        cout << "\t\t\t\t\tError!" "\n";
    }
    return out;
}
/////
string get_password()
{
    string password1 = get_input <string> ("\t\t\tPlease enter your password.");
    string password2 = get_input <string> ("\t\t\tPlease re-enter your password.");

    while (password1 != password2)
    {
        cout << "\t\t\t\t\tError! Passwords do not match." "\n";
        password1 = get_input <string>("\t\t\tPlease enter your password.");
        password2 = get_input <string>("\t\t\tPlease re-enter your password.");
    }
    return password1;
}
/////
string get_username()
{
    string username = get_input <string>("\t\t\tPlease enter a Username.");
    cout << "\t\t\tUsername: " << username << "\t\t";

    while (get_input <int>("\t\t\tIf you wish to confirm your Username please enter 1.") != 1)
    {
        username = get_input <string>("\t\t\tPlease enter a Username.");
        cout << "\t\t\tUsername: " << username << "\t\t";
    }
    return username;
}
/////
void login()
{
    string line = " ";
    ifstream readFile("userandpassword.txt");
    string UserName;
    string Password;
    string _UserName;
    string _Password;
    cout << "\t\t\tEnter UserName: ";
    cin >> UserName;
    cout << "\t\t\tEnter Password: ";
    cin >> Password;
    bool found = false;

    while (getline(readFile,line))
    {
        stringstream iss(line);
        iss >> _UserName >> _Password;
        if (UserName == _UserName && Password == _Password)
        {
            cout<<"\t\t\t\t\t\t";

            for(int i=0;i<5;i++)
            {
                cout<<".";
                Sleep(100);
            }
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout << "\t\t\t\t\tLogin Successful!"<< endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\t\t\t\t\tInvalid Username And Password"<< endl;
        cout<<"\t\t\t\tTo Register press 1 and for trying Logging again press 2"<<endl;
        int choice;
        cout<<"\t\t\t\t\t";
        A:
        cin>>choice;
        switch(choice)
        {
            case 1:
                register_user();
                break;
            case 2:
                login();
                break;
            default:
            cout<<"Wrong input. Please choose again.\n> ";
            goto A;
        }
    }

}
/////
void main_menu()
{
    int choice = get_input <int>("\n\n\n\n\n\n\n"
        "\t\t\t\tHello, Would you like to Log in or Register?" "\n"
        "\t\t\t\t[1] Login" "\n"
        "\t\t\t\t[2] Register" "\n"
        "\t\t\t\t[3] Exit");
    B:
    switch (choice)
    {
        case 1:
            login();
            break;
        case 2:
            register_user();
            cout<<"\t\t\t\t\t\t";
            for(int i=0;i<5;i++)
            {
                cout<<".";
                Sleep(100);
            }
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout <<"\t\t\t\t\tRegistered Successfully!"<< endl;
            break;
        case 3:
            exit(0);
            break;
        default:
            cout<<"Wrong input. Please enter your choice again.\n> ";
            cin>>choice;
            goto B;
    }
}
/////
void register_user()
{
    string username = get_username();
    string password = get_password();
    save_user(username, password);
}
/////
void save_user(const string &username, const string &password)
{
    ofstream myfile;
    myfile.open ("userandpassword.txt",ios::app);
    myfile << username<< " "<< password;
    myfile<<'\n';
    myfile.close();
}/////
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}
////
void Welcome_window()
{

    gotoxy(45,15);
    Sleep(500);
    printf("DEVELOPED BY:-");
    gotoxy(45,16);
    Sleep(500);
    printf("(BATCH : B8/B7)");
    gotoxy(45,17);
    Sleep(500);
    printf("Praduman Gupta (17103301)");
    gotoxy(45,18);
    Sleep(500);
    printf("Harshit Singhal     (17103300)");
    gotoxy(45,19);
    Sleep(500);
    printf("Ishan Jain  (17103)");
    gotoxy(45,20);
    Sleep(500);
    printf("Harsh Tyagi    (17103322)");

}
int main()
{
    Welcome_window();
    Sleep(6000);
    system("cls");
    main_menu();
    Sleep(2000);
    system("cls");
}
