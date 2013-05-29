/*
** Max Marchuk
** CS 202
** Karla Fant
** Program #3
** This file  contains all of the function definitions for the link class 
** and the overloaded operator definitions for the link class as well. 
**
*/

#include "hfile3.h"

//default constructor for the derived link class
link::link(){

    URL = new char[51];
    
}

//copy constructor for the link object
link::link(const link &linkSource){

    //copy all of the items over from the source to the
    //current object
    setTitle(linkSource.getTitle());
    setAuthor(linkSource.getAuthor());
    setRating(linkSource.getRating());
    setKeyword(linkSource.getKeyword());
    strcpy(URL, linkSource.getURL());
   
}

//default destructor for the link class
link::~link(){

    delete URL;

}

//Overloading the insertion operator
//for the derived class of post, "link".
std::istream & operator>> (istream &in, link &newlink){

    char * tempAuthor   = new char[31];
    char * tempTitle    = new char[31];
    char * tempKeyword  = new char[31];
    char * tempURL = new char[301];

    //begin collecting the information from the user
    cout << "\nAuthor: ";
    in.get(tempAuthor, 30);
    cin.ignore();

    cout << "Title: ";
    in.get(tempTitle, 30);
    cin.ignore();
    
    cout << "Topic: ";
    in.get(tempKeyword, 30);
    cin.ignore();

    cout << "URL: ";
    in.get(tempURL, 50);
    cin.ignore();
    
    //pass all of the data into the link object passed in. 
    newlink.setTitle    (tempTitle);
    newlink.setAuthor   (tempAuthor);    
    newlink.setURL (tempURL);
     
    //delete the temp pointers
    delete tempAuthor;
    delete tempTitle;
    delete tempURL;

} 


//overloading the output operator for the link
//class which is derived from the post class
std::ostream & operator<< (ostream &out, const link &outputlink){

    cout << "\nTitle: "    << outputlink.getTitle() << "\n"
         <<   "Author:  "    << outputlink.getAuthor()  << "\n"
         <<   "URL: "  << outputlink.URL    << "\n"
         <<   outputlink.getRating()  << " people found this post helpful!\n\n";
}

link & link::operator ++ (){

   incrementRate();      

}

//equality operator for ==
bool link::operator == (const link &source) const{

    //check if all of the contents are the same
    if(strcmp(source.getURL(),   this->getURL()) == 0)
      if(strcmp(source.getKeyword(),   this->getKeyword()) == 0)
        if(strcmp(source.getAuthor(),   this->getAuthor()) == 0)
          if(strcmp(source.getTitle(),   this->getTitle()) == 0)
             return true;


    return false;

}
bool link::operator != (const link &source) const{

    //check if any of the items are different.
    if(strcmp(source.getURL(),   this->getURL()) != 0)
        return true;
    if(strcmp(source.getKeyword(),   this->getKeyword()) != 0)
        return true;
    if(strcmp(source.getAuthor(),   this->getAuthor()) != 0)
        return true;
    if(strcmp(source.getTitle(),   this->getTitle()) != 0)
        return true;

    return false;

}

//function for overloading the assignment operator (=) 
//for the link class. This will allow me to assign 
//linkobj1 to linkobj2 and will basically act as a deep copy
link & link::operator = (link & linkSource){

    if(this == &linkSource)
        return *this;

    //copy all of the items over from the source to the
    //current object
    setTitle(linkSource.getTitle());
    setAuthor(linkSource.getAuthor());
    setRating(linkSource.getRating());
    setKeyword(linkSource.getKeyword());
    strcpy(URL, linkSource.getURL());
 
    //return *this; 
}
//the function for setting the URL
void link::setURL(char *newURL){

    strcpy(URL, newURL);
}

//just returns the url of the current object
char * link::getURL() const{

    return URL;

}

//displays the data members of the link object and the base class object
void link::display(){
    cout << "\nTEXT\n\n";
    cout << "\nTitle: "    << getTitle() << "\n"
         <<   "Author:  "    << getAuthor()  << "\n"
         <<   "Response: "  << URL << "\n"
         <<   getRating()  << " people found this post helpful!\n\n";

}    
