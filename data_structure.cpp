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
  root = NULL;

}



void menu::add_new_invoice(info &new_person, info &new_company, money &new_money, int &invoice_type){

  add_new_invoice(new_person, new_company, new_money, invoice_type, root);
  cout << "\n passed root in \n";
}
void menu::add_new_invoice (info &new_person, info &new_company, money &new_money, int &invoice_type, tree_node *& root){

  if(!root)//if a name match hasn't been found and you reached the insertion point
    {
      root = new tree_node(new_person, new_company, new_money, invoice_type);
    }
    else
       cout << "\nRoot exists.\n";


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


//////////////////////////////////////
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
  head = new LLL_node(new_person, new_company, new_money, invoice_type);


  list_items = 1;

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

