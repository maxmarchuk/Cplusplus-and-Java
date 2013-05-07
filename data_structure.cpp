#include "hfile2.h"


menu::menu(){

  root = new tree_node;

}

menu::~menu(){

  remove_all_invoices(root);

}

void menu::remove_all_invoices(tree_node * & root){

  if(!root)
    return;
  remove_all_invoices(root->get_left());
  remove_all_invoices(root->get_right());
  delete root;

}

void menu::add_new_invoice(info new_person, info new_company, money new_money){



}

void menu::add_new_invoice(info new_person, info new_company, money new_money){


}



//////////////////////////////
// LLL_NODE CLASS ///////////
////////////////////////////////

//default constructor
LLL_node::LLL_node(){

  next = NULL;
  invoice_ptr = new invoice;

}

LLL_node::LLL_node(LLL_node * new_next, invoice * new_invoice_ptr){

  next = new_next;
  invoice_ptr = new_invoice_ptr;

}

LLL_node::~LLL_node(){

  delete next;
  delete invoice_ptr;

}

LLL_node *& LLL_node::get_next(){

  return next;

}


//////////////////////////////////////
//      TREE_NODE CLASS  //////////
//////////////////////////////////

tree_node::tree_node(){

  head    = new LLL_node;
  left    = NULL;
  right   = NULL;
  char * person_name = NULL;

}


tree_node::~tree_node(){

  recursive_LLL(head);
  delete [] person_name;


}

void tree_node::recursive_BST (tree_node *& root)
{



}



void tree_node::recursive_LLL(LLL_node *& head){

  if(head == NULL)
    return;

  recursive_LLL( head->get_next() );

  delete head;

}

tree_node *& tree_node::get_left(){

  return left;

}

tree_node *& tree_node::get_right(){

  return right;

}

