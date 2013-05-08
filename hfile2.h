#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

//Contains the information for a customer or a company.
//both the customer and company have the same information
//so there is no point in deriving a new class for each one.
class info{

  public:
    info();
    info(char * new_name, char * new_email, char * new_address, char * new_phone);
    ~info();
    void set_name     (char * new_name);
    void set_email    (char * new_email);
    void set_address  (char * new_address);
    void disp_name    ();
    char * get_name   ();//returns the name. Used for the BST to sort and search
    void disp_email   ();
    void disp_address ();
    void disp_phone   ();

  private:
    char * name;      // Can be company name or customer name
    char * email;
    char * phone;
    char * address;

};

// The class that contains all the information that has anything
// to do with the money. the invoice class "has a" money class object in it.
class money{

  public:
    money               ();
    ~money              ();
    money               (float new_total, float new_received, float new_due);
    float set_total     (float new_total);
    float set_received  (float new_received); //adds to the previous amount
    float set_due       (float new_due);
  private:
    float total;        //the total amount that was required to pay
    float received;     //how much has been paid off already
    float due;          //how much the customer still hasn't paid
};


// Invoice class. Base class for the three different
// types of invoices declared after this class
class invoice{

  public:
    invoice                   ();
    invoice                   (int new_id, money new_money, info new_company, info customer);
    virtual ~invoice          ();
    int set_id                (int new_id);
    void set_company          (info &new_company);
    void set_customer         (info &new_customer);
    void set_money            (money &new_money);
    char * get_cust_name      ();
    virtual void display ();

  private:
    int id;             //should be automatically set by a variable in main
    money balance;      //contains money class. what the customer needs to pay, paid, etc...
    info company;       //contains information on the company
    info customer;      //contains information on the customer

};


//derived class from the invoice class.
//just has added int private data member added
class lawncare : public invoice{

  public:
    lawncare              ();
    ~lawncare             ();
    lawncare              (info new_person, info new_company, money new_money);
    void invoice_type     ();
    void set_frequency    (int new_frequency);
    void show_frequency   ();
  private:
    int frequency_of_care;//how many times a month this service is provided
};

class painting : public invoice{

  public:
    painting            ();
    ~painting           ();
    painting            (info new_person, info new_company, money new_money);
    void invoice_type   ();
    void set_warranty   (bool has_warranty);
  private:
    bool warranty;      //whether the person paid for warranty on the paint job
};

class catering : public invoice{

  public:
    catering            ();
    ~catering           ();
    catering            (info new_person, info new_company, money new_money);
    void set_distance   (int new_distance);
    void invoice_type   ();
  private:
    int driving_distance;
};


//linear linked list node for the data structure.
//there will be a head pointer to an LLL in every binary
//search tree node.

class LLL_node{

  public:
    LLL_node              ();
    ~LLL_node             ();
    LLL_node              (info new_person, info new_company, money new_money, int invoice_type);
    void set_next_to      (LLL_node * new_next);
    LLL_node *& get_next   ();
    void set_invoice      (invoice * new_invoice);
    char * get_person_name();
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
    tree_node             ();
    tree_node             (info new_person, info new_company, money new_money, int invoice_type);
    ~tree_node            ();
    tree_node *& get_left  ();
    tree_node *& get_right ();
    int get_num_items     ();
    void recursive_LLL    (LLL_node *& head);
    void recursive_BST    (tree_node *& root);

  private:
    LLL_node  * head;
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
    void add_new_invoice          (info new_person, info new_company, money new_money, int invoice_type);
    void add_new_invoice          (info new_person, info new_company, money new_money, int invoice_type, tree_node *& root);
    void remove_invoice           (char * person_name, int number);
    void retreive_invoices        (char * person_name);
    void remove_all_invoices      (tree_node * & root);

  private:
    tree_node * root;

};

