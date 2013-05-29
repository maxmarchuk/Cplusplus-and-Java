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

    response = new char[301];
    
}

//copy constructor for the text object
text::text(const text &textSource){

    //copy all of the items over from the source to the
    //current object
    setTitle(textSource.getTitle());
    setAuthor(textSource.getAuthor());
    setRating(textSource.getRating());
    setKeyword(textSource.getKeyword());
    strcpy(response, textSource.getResponse());
   
}

//default destructor for the text class
text::~text(){

   if(response)
       delete response;
}

//Overloading the insertion operator
//for the derived class of post, "text".
std::istream & operator>> (istream &in, text &newText){

    char * tempAuthor   = new char[31];
    char * tempTitle    = new char[31];
    char * tempKeyword  = new char[31];
    char * tempResponse = new char[301];

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

    cout << "Response: ";
    in.get(tempResponse, 50);
    cin.ignore();
    
    //pass all of the data into the text object passed in. 
    newText.setTitle    (tempTitle);
    newText.setAuthor   (tempAuthor);    
    newText.setResponse (tempResponse);
     
    //delete the temp pointers
    delete tempAuthor;
    delete tempTitle;
    delete tempResponse;

} 


//overloadin the output operator for the text
//class which is derived from the post class
std::ostream & operator<< (ostream &out, const text &outputText){

    cout << "\nTitle: "    << outputText.getTitle() << "\n"
         <<   "Author:  "    << outputText.getAuthor()  << "\n"
         <<   "Response: "  << outputText.response    << "\n"
         <<   outputText.getRating()  << " people found this post helpful!\n\n";
}

//the ++ operator. simply calls a function in the curretn object to incremenet the rating of the blog post
text & text::operator ++ (){

   incrementRate();      

}

//equality operator for ==
bool text::operator == (const text &source) const{

    //check if all of the contents are the same
    if(strcmp(source.getResponse(),   this->getResponse()) == 0)
      if(strcmp(source.getKeyword(),   this->getKeyword()) == 0)
        if(strcmp(source.getAuthor(),   this->getAuthor()) == 0)
          if(strcmp(source.getTitle(),   this->getTitle()) == 0)
             return true; //return true if they're al identical. If one of them isn't
                          //equal, it will return false
    return false;

}


//the "inequality" operator
bool text::operator != (const text &source) const{

    //check if any of the items are different.
    if(strcmp(source.getResponse(),   this->getResponse()) != 0)
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
//for the text class. This will allow me to assign 
//textobj1 to textobj2 and will basically act as a deep copy
text & text::operator = (const text & textSource){

    if(this == &textSource)
        return *this;

    //copy all of the items over from the source to the
    //current object
    strcpy(title, textSource.getTitle());
    strcpy(author, textSource.getAuthor());
    strcpy(keyword, textSource.getKeyword());
    postRating = textSource.getRating();
     
}


//the function for setting the response
void text::setResponse(char *newResponse){

    strcpy(response, newResponse);
}

//simply returns the "response" data member
char * text::getResponse() const{

    return response;

}

//dislpays all of the data members, including those of the post class
void text::display() const{

    cout << "\nTitle: "    << getTitle() << "\n"
         <<   "Author:  "    << getAuthor()  << "\n"
         <<   "Response: "  << response    << "\n"
         <<   getRating()  << " people found this post helpful!\n\n";
}

    
