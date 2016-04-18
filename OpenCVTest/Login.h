#include <string>

using namespace std;

int loginMenu(int n)
{
    cout << "================================";
    cout << endl;
    cout << endl;
    cout << "Login";
    cout << endl;
    cout << "1. Input User Name"; //Open OpenCV once they figure out how to implement it
    cout << "2. Exit";
    cout << endl;
    cout << "Choose an option: ";
    
    cin >> n;
    
    return n;
}