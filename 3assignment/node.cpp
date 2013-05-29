/*
** Max Marchuk
** CS 202
** Karla Fant
** Program #3
** This file contains all of the function definitinos for the node class.
*/
#include "hfile3.h"




//default constructor
node::node(){
    
    next = NULL;
    prev = NULL;
    blogPost = NULL; 
}

//default destructo
node::~node(){

    if(next)
        delete next;
    if(prev)
        delete prev;
}

//returns previous pointer
node * node::getNext(){

    return next;

}

//returns next pointer
node * node::getPrev(){

    return prev;

}

//sets the next pointer to the argument passed in
void node::setNext(node * newNext){

    next = newNext;

}

//sets the prev pointer to the argument passed in
void node::setPrev(node * newPrev){

    prev = newPrev;

}

void node::setPost(post * newPost){

    blogPost = newPost;

}

//simply checks if the keyword is the same in the node 
//as in the object passed in
bool node::keywordIs(char * keyword){

    //checks if the current node's has the same keyword
    //as the word passed in
    if(strcmp(keyword, blogPost->getKeyword()) == 0)
        return true;
    //return false if they are not the same
    return false;
}

void node::dispPost(){

    cout << *blogPost;
}

