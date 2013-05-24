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

    delete next;
    delete prev;
    delete blogPost;
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




