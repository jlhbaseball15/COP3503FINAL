#include <iostream>
#include "User.h"
#include <string>

using namespace std;

User::User()
{
    
}

User::User(string name, string birthday, string height, string gender, string color){
    this->name = name;
    this->birthday = birthday;
    this->height = height;
    this->gender = gender;
    this->color = color;
}


void User::print(){
    cout<<"Name: "<<this->name<<'\n';
    cout<<"Birthday: "<<this->birthday<<'\n';
    cout<<"Height: "<<this->height<<'\n';
    cout<<"Gender: "<<this->gender<<'\n';
    cout<<"Color: "<<this->color<<'\n';
    
}


void User::setName(string name)
{
    this->name = name;
}

string User::getName()
{
    return this->name;
}

void User::setBirthday(int day, int month, int year)
{
    this->birthday = to_string(day) + "/" + to_string(month) + "/" + to_string(month);
}

string User::getBirthday()
{
    return this->birthday;
}

void User::setHeight(int feet, int inches)
{
    this->height = to_string(feet) + "\'"  + to_string(inches) + "\"";
}

string User::getHeight()
{
    return this->height;
}

void User::setGender(string gender)
{
    this->gender = gender;
}

string User::getGender()
{
    return this->gender;
}

void User::setColor(string color)
{
    this->color = color;
}

string User::getColor()
{
    return this->color;
}

int User::getDay()
{
    return this->day;
}

int User::getMonth()
{
    return this->month;
}

void User ::setMonth(int month)
{
    this->month = month;
}
void User::setDay(int day)
{
    this->day=day;
}

void User::setYear(int year)
{
    this->year=year;
}

int User::getFeet()
{
    return this->feet;
}

int User::getInches()
{
    return this->inches;
}

void User::setFeet(int feet)
{
    this->feet=feet;
}

void User::setInches(int inches)
{
    this->inches=inches;
}


void User::writeToFile()
{
    ofstream myfile;
    myfile.open("user.csv", ofstream :: app);
    myfile << '\n';
    myfile << this->name <<",";
    myfile << this->day << "/" << this->month << "/" << this->year << ",";
    myfile << this->feet << "\' " << this->inches << "\"" << ",";
    myfile << this->gender << ",";
    myfile << this->color << "\n";
    
    myfile.close();
    
}