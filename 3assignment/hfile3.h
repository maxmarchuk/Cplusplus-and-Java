/*
** Max Marchuk
** CS 202 ** Karla Fant ** Program #3
** This is the header file for the program that contains all of the class
** and function prototypes. the definitions are in different .cpp files.
**
*/


#include<iostream>
#include <cstring>
using namespace std;


//base class for the blog posts. Will contain title of post and 
//the name of the person posting it. The derived classes will have 
//the actual feedback based on what type of post it is.
class post
{
    public:
        post                    ();
        post                    (char *newTitle, char *newAuthor, char *newKeyword, int newRating);
        virtual ~post           ();
        void setTitle           (char * newTitle);
        void setAuthor          (char * newAuthor);
        void setRating          (int newRating);
        void setKeyword         (char * newKeyword);
        char *getKeyword        () const;
        char *getTitle          () const;
        char *getAuthor         () const;
        int  getRating          () const;
        void incrementRate      ();
        virtual void display    () const;    
        friend ostream & operator <<(ostream &, const post&);
       
    
    protected:
        char * title;
        char * keyword;
        char * author;
        int postRating; //not set by user. can be used later on to rate 
                        // the user's post by other users using ++ operator.
                        // which will increment the rating by 1

};

//derived class of the post class. All that it has added on is a char array 
//that is the actual response from a user.
class text : public post
{
    public:
        text                            ();
        text                            (const text &textSource);
        ~text                           ();
        void setResponse                (char * newResponse);
        char * getResponse              () const ;
        friend istream & operator  >>   (istream &, text&);
        friend ostream & operator  <<   (ostream &, const text&);
        bool operator              ==   (const text&) const; 
        bool operator              !=   (const text&) const; 
        text & operator            =    (const text &);
        text & operator            ++   ();
        void display                    () const;    

    private:
        char * response;

};

//derived class from post. Just another possible post type that can be made.
//the only difference is that it has a URL added on as a data member.
//
class link : public post
{
    public:
        link                ();
        link                (const link &);
        ~link               (); 
        char * getURL       () const;
        void  setURL       (char * newURL);
        friend istream & operator  >>   (istream &, link&);
        friend ostream & operator  <<   (ostream &, const link&);
        bool operator              ==   (const link&) const; 
        bool operator              !=   (const link&) const; 
        link & operator            =    (link&);
        link & operator            ++   ();
        void display                    () const;    


    private:
        char * URL;
                        
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
        void   setPost   (post * newPost);
        void dispPost    ();
        bool keywordIs   (char * keyword);

     private:
        node * prev;        //pointer to previous node 
        node * next;        //pointer to next node
        post * blogPost;    //dynamic pointer to either a text class or a link class. 
};


//The class to manage the data structure (doubly linked list)
class blog 
{

    public:
        blog            ();
        ~blog           ();
        void searchName (char * findName); 
        void insertNew  (post *&);
        void displayAll ();

    private:
        int MAX; 
        node ** head;
        
};



