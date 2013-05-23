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

}

post::~post(){


}


//set the title for the post class obj
void post::setTitle(char *newTitle){
    
    strcpy(title, newTitle);

}
//set the author name for the post class obj
void post::setAuthor(char *newAuthor){

    strcpy(author, newAuthor);

}

//returns the title of the obj
char *post::getTitle(){
    
    return title;

}

//returns the author name
char *post::getAuthor(){

    return author;

}

/*
//returns the title of the obj 
char * post::getTitle(){

    return title;

}

//returns the author of the obj
char * post::getAuth(){

    return author;

}

int
*/
