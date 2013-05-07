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
