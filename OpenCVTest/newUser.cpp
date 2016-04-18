#include <iostream>
#include "newUser.h"
#include <string>

using namespace std;

newUser::newUser()
{
    
}

newUser::newUser(string name, string birthday, string height, string gender, string color){
    this->name = name;
    this->birthday = birthday;
    this->height = height;
    this->gender = gender;
    this->color = color;
}



void newUser::setName(string name)
{
    this->name = name;
}

string newUser::getName()
{
    return this->name;
}

void newUser::setBirthday(int day, int month, int year)
{
    this->birthday = to_string(day) + "/" + to_string(month) + "/" + to_string(month);
}

string newUser::getBirthday()
{
    return this->birthday;
}

void newUser::setHeight(int feet, int inches)
{
    this->height = to_string(feet) + "\'"  + to_string(inches) + "\"";
}

string newUser::getHeight()
{
    return this->height;
}

void newUser::setGender(string gender)
{
    this->gender = gender;
}

string newUser::getGender()
{
    return this->gender;
}

void newUser::setColor(string color)
{
    this->color = color;
}

string newUser::getColor()
{
    return this->color;
}

int newUser::getDay()
{
    return this->day;
}

int newUser::getMonth()
{
    return this->month;
}

void newUser ::setMonth(int month)
{
    this->month = month;
}
void newUser::setDay(int day)
{
    this->day=day;
}

void newUser::setYear(int year)
{
    this->year=year;
}

int newUser::getFeet()
{
    return this->feet;
}

int newUser::getInches()
{
    return this->inches;
}

void newUser::setFeet(int feet)
{
    this->feet=feet;
}

void newUser::setInches(int inches)
{
    this->inches=inches;
}


void newUser::writeToFile()
{
    ofstream myfile;
    myfile.open("user.csv", ofstream :: app);
    myfile << this->name <<",";
    myfile << this->day << "/" << this->month << "/" << this->year << ",";
    myfile << this->feet << "\' " << this->inches << "\"" << ",";
    myfile << this->gender << ",";
    myfile << this->color << endl;
    
    myfile.close();
    
}