#include <iostream>
#include <ctype.h>

std::string solve( std::string s );

/*  Check the nature of isdigit */
/*
    Result: 
*/
int main() {
    std::cout << "The nature of isdigit is " << std::isdigit('0') << std::endl;
    std::cout << solve("2048a") << std::endl;
    return 0;
}

std::string solve( std::string s ) {
    for( int i = 0; i < s.length(); i++ ) {
        if( !std::isdigit( s[i] )) {
            return "False";
        }
    }
    return "True";
}