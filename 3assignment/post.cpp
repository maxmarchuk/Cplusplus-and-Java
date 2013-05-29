    /*
** Max Marchuk
** CS 202
** Karla Fant
** Program #3
** This file  contains all of the function definitions for the post class 
**
*/

#include "hfile3.h"
post::post(){

    title   = new char[31];
    author  = new char[31];
    keyword = new char[31];
    postRating = 0;
}

//Copy constructor for the post 
post::post(char *newTitle, char *newAuthor, char *newKeyword, int newRating){

    //allocate the memory for the character arrays
    title   = new char[31];
    author  = new char[31];
    keyword = new char[31];

    //copy all of the information from the source text object
    postRating = newRating;
    strcpy(title, newTitle);
    strcpy(author, newAuthor);
    strcpy(keyword, newKeyword); 

}


post::~post(){

    if(title)
        delete title;
    if(author)
        delete author;
    if(keyword)
        delete keyword;

}





//set the title for the post class obj
void post::setTitle(char *newTitle){
    
    strcpy(title, newTitle);

}
//set the author name for the post class obj
void post::setAuthor(char *newAuthor){

    strcpy(author, newAuthor);

}

//copies keyword
void post::setKeyword(char *newKeyword){

    strcpy(keyword, newKeyword);

}
//returns the title of the obj
char *post::getTitle() const{
    
    return title;

}

//returns the author name
char *post::getAuthor() const{

    return author;

}

//returns keyword
char *post::getKeyword() const{

    return keyword;

}

//returns an integer which is the post rating
int post::getRating() const{

    return postRating;

}
//simply increments the rating integer
void post::incrementRate(){

    ++postRating;

}

//copies the rating from another integer.
////Used in the copy constructor of the text class
void post::setRating(int newRating){

    postRating = newRating;

}



std::ostream & operator << (ostream &out, const post& obj){

    obj.display(); 

}
void post::display() const{

    cout << "\n in post display\n";

}


