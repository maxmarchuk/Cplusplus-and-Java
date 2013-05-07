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
     

}

void recursive_BST (tree_node *& root)
{



}
void tree_node::recursive_LLL(tree_node *& head){

  if(get_next())
    recursive_remove(get_next());
   
 
}
