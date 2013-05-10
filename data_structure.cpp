#include "hfile2.h"



//menu default constructor. Only constructor that will ever be called
menu::menu(){

  root = NULL;

}


//default destructor. basically just called a recursive deletion on 
//the whole BST with the root pointer.
menu::~menu(){

  remove_all_invoices(root);

}

//the recursive "destructor". Goes through and deletes 
//all the root pointers in The BST.
void menu::remove_all_invoices(tree_node * & root){

  if(!root)
    return;
  remove_all_invoices(root->get_left());
  remove_all_invoices(root->get_right());
  delete root;
  root = NULL;

}


//the wrapper function for the add_new_invoice function. 
////It just passes in the given data along with root to the recursive add function 
void menu::add_new_invoice(info &new_person, info &new_company, money &new_money, int &invoice_type){

  add_new_invoice(new_person, new_company, new_money, invoice_type, root);
  cout << "\n passed root in \n";

}


//the recursive add function that will go through the BST
//and figure out where it must go. Then it will add a new 
//tree node to where it finds a match. If no match is found,
//it will add a new tree_node at the first empty position.
void menu::add_new_invoice (info &new_person, info &new_company, money &new_money, int &invoice_type, tree_node *& root){

  if(!root)//if a name match hasn't been found and you reached the insertion point
      root = new tree_node(new_person, new_company, new_money, invoice_type); 

  //if the new customer's name is less than the current root's name ( alphabetical order)
  if(strcmp(new_person.get_name(), root->person_name) < 0)
      add_new_invoice(new_person, new_company, new_money, invoice_type, root->get_left());
  
  if(strcmp(new_person.get_name(), root->person_name) > 0)
      add_new_invoice(new_person, new_company, new_money, invoice_type, root->get_right());

   

}

void menu::display_all(){
    
    if(!root)
        return;
    display_all(root->left);
    display_all(root->right);
    display(root);
}

void menu::display(tree_node * root){

    if(!root->head)
        return;
    display(root->get_left());
    display(root->get_right());
    root->
        
}


//////////////////////////////
// LLL_NODE CLASS ///////////
////////////////////////////////

//default constructor
LLL_node::LLL_node(){

  next = NULL;
  invoice_ptr = new invoice;

}

LLL_node::LLL_node(info new_person, info new_company, money new_money, int invoice_type){

  next = NULL;

  switch(invoice_type)
  {

  case 1:
    invoice_ptr = new lawncare(new_person, new_company, new_money);
    break;
  case 2:
    invoice_ptr = new painting(new_person, new_company, new_money);
    break;
  case 3:
    invoice_ptr = new catering(new_person, new_company, new_money);
    break;
  default:
    cout << "\n\nINCORRECT INVOICE TYPE SELECTED. ABORTING\n\n";
    break;

  }


}

LLL_node::~LLL_node(){

  delete next;
  delete invoice_ptr;

}

LLL_node *& LLL_node::get_next(){

  return next;

}

////////////////////////////////////
//      TREE_NODE CLASS  //////////
//////////////////////////////////

tree_node::tree_node(){

  head    = new LLL_node;
  left    = NULL;
  right   = NULL;
  char * person_name = NULL;
  list_items = 0;

}
tree_node::tree_node(info &new_person, info &new_company, money &new_money, int &invoice_type){

  left = NULL;
  right = NULL;
  if(!head)
      head = new LLL_node(new_person, new_company, new_money, invoice_type);
  person_name = new char[strlen(new_person.get_name())+1];
  strcpy(person_name, new_person.get_name());

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

