#include "hfile2.h"

tree_node::tree_node(){

  head    = new LLL_node;
  left    = NULL;
  right   = NULL;
  char * person_name = NULL;

}


tree_node::~tree_node(){

  recursive_remove(head);
  delete [] person_name;
  delete []


}

void tree_node::recursive_BST (tree_node *& root)
{



}



void tree_node::recursive_LLL(LLL_node *& head){

  if(head == NULL)
    return;

  recursive_LLL( head->get_next() );
  recursive_LLL( head->get_right() );

  delete head;

}
