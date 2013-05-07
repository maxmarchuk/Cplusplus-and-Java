#include "hfile2.h"

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

LLL_node * LLL_node::get_next(){

  return next;

}

