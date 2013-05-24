/*
** Max Marchuk
** CS 202
** Karla Fant
** Program #3
** This file contains all of the function definitions for anything that has to 
** do with the data structure.
*/
 
#include "hfile3.h"


DLLArray::DLLArray()
{

    MAX = 11;
    head = new node*[MAX];

}

DLLArray::~DLLArray(){
    
    for(int i = 0; i < MAX; ++i)
        delete head[i];

}

void DLLArray::insertNew(node *&newNode){

    for(int i = 0; i < MAX; ++i)
    {
        if(head[i] == NULL)
        {
            head[i] = newNode;
            head[i]->setNext(NULL);

        }
    }
}
