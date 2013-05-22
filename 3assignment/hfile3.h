/*
** Max Marchuk
** CS 202 ** Karla Fant ** Program #3
** This is the header file for the program that contains all of the class
** and function prototypes. the definitions are in different .cpp files.
**
*/


#include <iostream>
#include <cstring>
using namespace std;


//base class for the blog posts. Will contain title of post and 
//the name of the person posting it. The derived classes will have 
//the actual feedback based on what type of post it is.
class post
{

    public:
        post            ();
        ~post           ();
        void setTitle   (char * newTitle);
        void setAuthor  (char * newAuthor);
        
    private:
        char * title;
        char * author;
        int postRating; //not set by user. can be used later on to rate 
                        // the user's post by other users.

};

//derived class of the post class. All that it has added on is a char array 
//that is the actual response from a user.
class text : public post
{
    public:
        text                ();
        ~text               ();
        void setResponse    (char * newResponse);
        friend istream & operator  >>  (istream &, text*&);
        friend ostream & operator  <<  (ostream &, const text*&);
        

    private:
        char * response;
};

class link : public post
{
    public:
        link                (char * newLink);
        ~link               (); 

    private:
        char * source;
        bool goodSource;    //modified by the user or blog owner. Determines if the link's source
                            // is reliable. 
                          
}; 
                            
//node class for the doubly linked list. 
//contains a next and previous pointer and the data.
//Also functions to modify and get all of those.
class node
{

    public:
        node             ();
        ~node            ();
        node             (const node *&);
        node * getNext   ();
        node * getPrev   ();
        void   setNext   (node * newNext);
        void   setPrev   (node * newPrev); 

        //node *&          operator  =   (const node &); //overloading = operator to be able to set nodes easily
        //friend bool      operator  ==  (const node *&, const node *&);
     private:
        node * prev;        //pointer to previous node 
        node * next;        //pointer to next node
        post * blogPost;    //dynamic pointer to either a text class or a link class. 
};


//The class to manage the data structure (doubly linked list)
class DLLArray
{

    public:
        void insertNew  (node *& newNode);
        void searchName (char * findName); 
    private:
        node * head;
        int members;

};



