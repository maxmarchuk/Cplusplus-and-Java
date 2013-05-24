/*
** Max Marchuk
** CS 202 ** Karla Fant ** Program #3
**This is the file that has the user input and output and all of that...
*/

#include "hfile3.h"

int main(){
    
    text newText;

    std::cin >> newText; 
    for(int i = 0; i < 223; ++i)
    ++newText;

    cout << newText;

}

