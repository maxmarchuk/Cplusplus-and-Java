/*
** Max Marchuk
** CS 202
** Karla Fant
** Program #3
** This file contains all of the function definitions for anything that has to 
** do with the data structure.
*/
 
#include "hfile3.h"

//default constructor
blog::blog()
{

    MAX = 11;
    //allocate an array of pointers
    head = new node*[MAX];

}

//default destructor.
//goes through each array index and deletes the head pointer
blog::~blog(){

    for(int i = 0; i < MAX; ++i)
    {
        if(head[i])
            delete head[i];
    }

}

//insertion function. takes in a post pointer
//and basically just copies it over to the next open node.
void blog::insertNew(post *& postPtr){

    for(int i = 0; i < MAX; ++i)
    {
        //if the current head pointer doesn't have a 
        //node in it at the time of insertion
        if(head[i] == NULL)
        {
            //create the new node an dinsert all of the data
            head[i] = new node;
            head[i]->setNext(NULL);
            head[i]->setPrev(NULL);
            head[i]->setPost(postPtr);
            return;            
        }
        //if the current index in the array has the same keyword
        //as the new object being passed in
        else if(head[i]->keywordIs(postPtr->getKeyword()))
        {
           //pass the node in and link up its next pointer
           //to the current first node
           node * holder = head[i]->getNext(); 
           node * temp = head[i]->getNext();
           temp = new node;
           temp->setPost(postPtr);
           temp->setPrev(head[i]); 
           temp->setNext(holder); 
     }
    }
}

//Displays everything in the data structure
void blog::displayAll(){

    node * temp;
    //if the data structure exists at all
    if(head)
    {
        for(int i = 0; i < MAX; ++i)
        {
            //if the current index exists
            if(head[i])
            {
                //display all of the list with a while loop
                temp = head[i];
                while(temp)
                {
                    temp->dispPost();
                    temp = temp->getNext();
                }
            }
        }
    }
}

