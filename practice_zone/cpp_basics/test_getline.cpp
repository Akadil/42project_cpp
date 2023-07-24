#include <iostream>
#include <string>
using namespace std;

/*
    Test the nature of getline function

    Result: Getline firstly looks at input buffer 
            So it means that there should be no cin before the getline?
*/
int main(void)
{
    string name;


    cout << "Check the getline " << endl;
    cin >> name;
    cout << "The names is " << name;
    cout << "Get another line" << endl;
     (cin, name);
    cout << "Your name is " << name << endl;
    return (0);
}