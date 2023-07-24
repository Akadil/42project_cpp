#include <iostream>
#include <string>
using namespace std;

/*
    Test the nature of cin operator with string

    Result: Only the first word is taken seperated by spaces, the 
            rest of the string is saved inside of input buffer. 
            So the rest of cin in the code can take it

            It is like a split with spaces
*/
int main(void)
{
    string name;
    string name2;

    cout << "Type your full name!" << endl;
    cin >> name;
    cout << "Your first name is " << name << endl;
    cin >> name;
    cout << "Your second name is " << name << endl;
    cout << "\nTalking about the rest..." << endl;
    cin >> name;
    cout << "What am I? " << name << endl;
    return (0);
}