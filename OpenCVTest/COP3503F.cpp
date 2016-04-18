#include <iostream>
#include <fstream>
#include "newUser.h"
#include <string>
#include "Login.h"
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;



vector<newUser> program_users;
string name = "";
int day = 0;
int month = 0;
int year = 0;
int feet = 0;
int inches = 0;
string gender = "";
string color = "";


int main()
{
    
    ifstream myFile("/Users/Archit/Documents/OpenCVTest/OpenCVTest/user.csv");
    string line;
    while (getline(myFile, line))
    {
        string a,b,c,d,e;
        istringstream s(line);
        string field;
        while (getline(s, field,','))
        {
            
            
            
            a = field;
            while (getline(s, field,','))
            {
                if (b == "")
                {
                    b = field;
                }
                else if (b != "" && c == "" && d == "")
                {
                    c = field;
                }
                else if (b != "" && c!= "" && d == "")
                {
                    d = field;
                }
                else{
                    e = field;
                }
            }
            
        }
        newUser* swag = new newUser(a,b,c,d,e);
        program_users.push_back(*swag);
        
    }
    
    
    

    
    sort( program_users.begin( ), program_users.end( ), [ ]( const newUser& lhs, const newUser& rhs )
    {
        return lhs.name < rhs.name;
    });

    
    
    ////////////////////////////
    ///Initializes Main Menu///
    //////////////////////////
    
    cout << "=====================================================================";
    cout << endl;
    cout << endl;
    //All of the '==' will be used to separate the menus for easier viewing
    
    cout << "Welcome to the Computer Vision Recognition System Acquisition Mission";
    cout << endl;
    cout << endl;
    cout << "1. Login";
    cout << endl;
    cout << "2. Add User";
    cout << endl;
    cout << "3. Exit";
    cout << endl;
    cout << endl;
    cout << "================================";
    cout << endl;
    cout << endl;
    
    ////////////////////////////
    //do while loop for main menu//
    //////////////////////////
    
    bool statement = true;
    do {
        cout << "Choose an option: ";
        cout << endl;
        int n;
        
        
        /////////////////////////////
        ///checks menu input/////////
        ////////////////////////////
        
        while(true)
        {
            
            cin >> n;
            cout << endl;
            //checks for letters
            if(cin.fail())
            {
                
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Please enter a number that is related to a menu choice";
                cout << endl;
                continue;
                
            }
            
            //checks for range/odd
            
            if(n < 1 || n > 3)
            {
                
                cout<< "Please enter a number that is related to a menu choice";
                cout << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
                
            }
            
            //double checks for decimals and leaves while with proper input
            else
            {
                false;
                break;
            }
            
            
        }
        if (n == 1)
        {
            cout << "================================";
            cout << endl;
            cout << endl;
            cout << "Login";
            cout << endl;
            cout << "1. Input User Name"; //Open OpenCV once they figure out how to implement it
            cout << endl;
            cout << "2. Exit";
            cout << endl;
            cout << endl;
            cout << "Choose an option: ";
            int n;
            cin >> n;
            cout << endl;
            
            
            if (n == 1)
                //facial recognition would pop up instead of asking for the username
            {
                string n;
                cout << "Username: ";
                cin >> n;
                
                
                // ifstream myFile("user.csv");
                // string line;
                // while (getline(myFile, line))
                // {
                //     std::istringstream s(line);
                //     std::string field;
                //     while (getline(s, field,','))
                //     {
                //         cout << field << "\t";
                //         cout << endl;
                //     }
                // }
                
            }
        }
        
        else if (n == 2)
        {
            newUser* users = new newUser();
            cout << "Ready to create a new user!" << endl;
            cout << "Please type in a username that is between 1 and 15 characters inclusive: ";
            cout << endl;
            cin >> name;
            cout << endl;
            while(name.length() > 15)
            {
                //check for username already being used?
                if(name.length() > 15)
                {
                    cout << "That username is too long!";
                    cout << endl;
                    cout << "Please type in a username that is between 1 and 15 characters inclusive: ";
                    cout << endl;
                    cin >> name;
                    cin.clear();
                    cout << endl;
                }
                else
                {
                    cout << "That username is too short!";
                    cout << endl;
                    cout << "Please type in a username that is between 1 and 15 characters inclusive: ";
                    cout << endl;
                    cin >> name;
                    cin.clear();
                    cout << endl;
                }
                
            }
            
            users->setName(name);
            cin.clear();
            ////////////////////////////
            //checks for day of birth//
            ///////////////////////////
            cout << "Please type the day you were born";
            cout << endl;
            cout << "\tFor example, a person born on the 22nd day of the month would enter the number 22";
            cout << endl;
            
            
            while(true)
            {
                
                cin >> day;
                cout << endl;
                //checks for letters
                if(cin.fail())
                {
                    
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Please enter a number that is a day of the month" << endl;
                    continue;
                    
                }
                
                //checks for range/odd
                n = day;
                
                if(n < 1 || n > 31)
                {
                    
                    cout<< "Please enter a number that is a day of the month";
                    cout << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                    
                }
                
                //double checks for decimals and leaves while with proper input
                else
                {
                    n = day;
                    false;
                    break;
                }
                
                
            }
            
            ///////////////////////////
            ////asks user for month////
            //////////////////////////
            
            cout << "Please enter the numeric value of the month you were born in";
            cout << endl;
            cout << "\tFor example, a user born in April would enter the number 4: ";
            cout << endl;
            true;
            while(true)
            {
                
                cin >> month;
                //checks for letters
                cout << endl;
                if(cin.fail())
                {
                    
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Please enter a number that is between 1 and 12 inclusive" << endl;
                    continue;
                    
                }
                //checks for decimals
                
                n = month;
                
                if(n < 1 || n > 12)
                {
                    
                    cout<< "Please enter a number that is between 1 and 12 inclusive";
                    cout << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                    
                }
                
                //double checks for decimals and leaves while with proper input
                else
                {
                    n = month;
                    false;
                    break;
                }
            }
            
            cout << endl;
            
            
            ////////////////
            ///check year///
            ////////////////
            
            
            cout << "Please enter the year you were born in using 4 digits";
            cout << endl;
            cout << "\tFor example, a user born in 1998 would enter 1998 ";
            cout << endl;
            true;
            while(true)
            {
                
                cin >> year;
                //checks for letters
                cout << endl;
                if(cin.fail())
                {
                    
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Please enter the year you were born in using 4 digits" << endl;
                    continue;
                    
                }
                //checks for decimals
                
                n = year;
                
                if(n < 1900 || n > 2016)
                {
                    
                    if(n < 1900)
                    {
                        cout << "There's now way you can be over 116 years old!" << endl;
                        cout<< "Please enter the year you were born in using 4 digits";
                        cout << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        continue;
                    }
                    else
                    {
                        cout << "Are you from the future?";
                        cout << endl;
                        cout<< "Please enter the year you were born in using 4 digits";
                        cout << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        continue;
                        
                    }
                    
                    
                }
                
                //double checks for decimals and leaves while with proper input
                else
                {
                    n = year;
                    false;
                    break;
                }
            }
            
            users->setDay(day);
            users->setMonth(month);
            users->setYear(year);
            string birthday = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
            //////////////////
            ///check height///
            //////////////////
            
            
            cout << "Please enter your height in feet and inches";
            cout << endl;
            cout << "\tFor example, a user who is exactly 5 feet would enter 5 for feet and 0 inches";
            cout << endl;
            true;
            while(true)
            {
                cout << "Feet: " << endl;
                
                cin >> feet;
                //checks for letters
                if (cin.fail()) {
                    
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Please enter your height in feet and inches" << endl;
                    continue;
                    
                }
                //checks for decimals
                
                n = feet;
                
                if (n < 0 || n > 10) {
                    cout << "Please enter a reasonable height";
                    cout << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }
                
                //double checks for decimals and leaves while with proper input
                else {
                    n = feet;
                    false;
                    break;
                }
            }
            
            ////////////////////////////
            ////gets inches of height///
            ///////////////////////////
            
            
            true;
            while(true)
            {
                cout << "Inches: " << endl;
                
                cin >> inches;
                //checks for letters
                
                cout << endl;
                if(cin.fail())
                {
                    
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Please enter a number that is between 0 and 11 inclusive" << endl;
                    continue;
                    
                }
                //checks for decimals
                
                n = inches;
                
                if(n < 0 || n > 11)
                {
                    
                    cout<< "Please enter a number that is between 0 and 11 inclusive";
                    cout << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                    
                }
                
                //double checks for decimals and leaves while with proper input
                else
                {
                    n = inches;
                    false;
                    break;
                }
                
            }
            
            users->setFeet(feet);
            users->setInches(inches);
            
            string height = to_string(feet) + "\'"  + to_string(inches) + "\"";
            
            cout << "Please enter your gender as \"Male\", \"Female\", or \"Other\"";
            cout << endl;
            cin >> gender;
            cin.clear();
            while(true)
            {
                cout << endl;
                if(gender != "Male" && gender != "Female" && gender != "Other" && gender != "male" &&
                   gender != "female" && gender != "other")
                {
                    cout << "Please enter your gender as \"Male\", \"Female\", or \"Other\"";
                    cout << endl;
                    cin >> gender;
                    cin.clear();
                }
                else
                {
                    false;
                    break;
                }
            }
            
            users->setGender(gender);
            cout << endl;
            
            /////////////////////////
            ////asks for color//////
            ////////////////////////
            cout << "Please enter your favorite color: ";
            cout << endl;
            cin >> color;
            cin.clear();
            
            
            cout << endl;
            
            users->setColor(color);
            
            newUser* temp = new newUser(name, birthday, height, gender, color);
            
            program_users.push_back(*temp);
            
            
            sort( program_users.begin( ), program_users.end( ), [ ]( const newUser& lhs, const newUser& rhs )
            {
                     return lhs.name < rhs.name;
            });
            
            
            //cout<<(program_users.back()).name<<endl;
            
            users->writeToFile();
            
            cout << "=====================================================================\n\n";
            cout << "Computer Vision Recognition System Acquisition Mission Menu\n\n";
            cout << "1. Login\n";
            cout << "2. Add User\n";
            cout << "3. Exit\n\n";
            cout << "================================\n\n";
            
            
        }
        else if (n == 3)
        {
            cout << "================================";
            cout << endl;
            cout << endl;
            cout << "Thanks for coming! See you next time!";
            cout << endl;
            cout << endl;
            cout << "=====================================================================";
            cout << endl;
            statement = false;
        }
    } while (statement == true);
    
    
    return 0;
}