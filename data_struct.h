#include "hfile2.h"




//linear linked list node for the data structure.
//there will be a head pointer to an LLL in every binary
//search tree node.

class LLL_node{

  public:
    LLL_node              ();
    ~LLL_node             ();
    void set_next_to      (LLL_node * new_next);
    LLL_node              (LLL_node * new_next, invoice * new_invoice_ptr);
    void set_invoice      (invoice * new_invoice);
    char * get_person_name();
    LLL_node * get_next   ();
    invoice * get_invoice ();

  private:
    LLL_node * next;
    invoice  * invoice_ptr;
};

//This is the tree node class for the data structure and
//it holds the left and right pointer, along with a head pointer
/// to a linear linked list.
//it also contains the amount of nodes in the linear linkd list.
//there is also a char array to keep track of the names of the people.
//this will make it easier to compare names with the search terms in the future
class tree_node{
  public:
    tree_node       ();
    ~tree_node      ();
  private:
    LLL_node * head;
    tree_node * left;
    tree_node * right;
    int list_items;
    char * person_name;   //will be set to the LLL_node's get_person_name();

};

//this is the class that manages the data structure and does all the operations
//requried on it
class menu{

  public:
    menu                          ();
    ~menu                         ();
    void display_all              ();
    void add_new_invoice          (info new_person, info new_company, money new_money);
    void remove_invoice           (char * person_name, int number);
    void retreive_invoices        (char * person_name);
    void remove_all_invoices      ();
  private:
    tree_node * root; 			

};

