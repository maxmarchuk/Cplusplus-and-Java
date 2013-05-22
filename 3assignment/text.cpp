/*
** Max Marchuk
** CS 202
** Karla Fant
** Program #3
** This file  contains all of the function definitions for the text class 
** and the overloaded operator definitions for the text class as well. 
**
*/

#include "hfile3.h"

//default constructor for the derived text class
text::text(){

    response = new char[51];
    
}

//Overloading the insertion operator
//for the derived class of post, "text".
std::istream & operator>> (istream &in, text *&newText){

    char * tempAuthor   = new  char[31];
    char * tempTitle    = new  char[31];
    char * tempResponse = new  char[51];

    //begin collecting the information from the user
    cout << "\nAuthor: ";
    in.get(tempAuthor, 30);
    cin.ignore();

    cout << "\nTitle: ";
    in.get(tempTitle, 30);
    cin.ignore();
    
    cout << "\nRelevant Link: ";
    in.get(tempResponse, 50);
    cin.ignore();
    
    //pass all of the data into the text object passed in. 
    newText->setTitle    (tempTitle );
    newText->setAuthor   (tempAuthor);    
    newText->setResponse (tempResponse);
    
    //delete the temp pointers
    delete tempAuthor;
    delete tempTitle;
    delete tempResponse;

} 
//overloadin the output operator for the text
//class which is derived from the post class
std::ostream & operator<< (ostream &out, const text* &outputText){



}


//the function for setting the response
void text::setResponse(char *newResponse){

}

