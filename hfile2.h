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
    void set_phone    (char * new_phone);
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
    virtual ~invoice          (){cout << "\nVirtual Destructor Called\n";}
    int set_id                (int new_id);
    void set_company          (info new_company);
    void set_customer         (info new_customer);
    char * get_cust_name      ();
    virtual void invoice_type ();

  private:
    int id;             //should be automatically set by a variable in main
    money balance;      //contains money class. what the customer needs to pay, paid, etc...
    info company;       //contains information on the company
    info customer;      //contains information on the customer

};

class lawncare : public invoice{

  public:
    lawncare              ();
    ~lawncare             ();
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
    void invoice_type   ();
    void set_warranty   (bool has_warranty);
  private:
    bool warranty;      //whether the person paid for warranty on the paint job
};

class catering : public invoice{

  public:
    catering            ();
    ~catering           ();
    void set_distance   (int new_distance);
    void invoice_type   ();
  private:
    int driving_distance;
};

class LLL_node{

  public:
    LLL_node              ();
    LLL_node              (LLL_node * new_next, invoice * new_invoice_ptr);
    ~LLL_node             ();
    void set_next_to      (LLL_node * new_next);
    void set_invoice      (invoice * new_invoice);
    char * get_person_name();
    LLL_node * get_next   ();
    invoice * get_invoice ();

  private:
    LLL_node * next;
    invoice  * invoice_ptr;
};


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

