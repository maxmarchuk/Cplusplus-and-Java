#include "hfile2.h"


  void main_menu(menu & menu_obj);
  void add_temp_invoice(menu & menu_obj, int & id);

int main(){

  menu invoice_menu;
  main_menu(invoice_menu);

}


void main_menu(menu & menu_obj){

  int choice = 0;
  int invoice_id = 0;
  while(choice != 6)
  {
  cout << "\nPlease Select a menu option from below:\n"
       << "1) Add a new invoice\n"
       << "2) Remove an invoice\n"
       << "3) Display all invoices\n"
       << "4) Retrieve a person's invoices\n"
       << "5) Remove All invoices\n"
       << "6) Exit program\n\n";
  cout << "Choice: ";
  cin >>choice;

    switch(choice){
      case 1:
        add_temp_invoice(menu_obj, invoice_id);
        break;
    }


  }

}


void add_temp_invoice(menu & menu_obj, int & id){

  int invoice_choice = 0;

  char * temp_name    = new char [31];
  char * temp_email   = new char [31];
  char * temp_address = new char [101];
  char * temp_phone   = new char [15];

    while(invoice_choice = 0);
    {
    cout << "Choose a type of invoice that this will be: \n"
         << "1) Lawn Care Invoice\n"
         << "2) Painting Invoice\n"
         << "3) Catering Invoice\n"
         << "Choice (1-3): ";
         cin >> invoice_choice;
         cin.ignore();
         if(invoice_choice > 3 || invoice_choice < 1)
          invoice_choice = 0;
    }

  //collect customer info
  cout << "Customer Name: ";
    cin.get(temp_name, 30);
      cin.ignore();
  cout << "\nCustomer E-mail: ";
    cin.get(temp_email, 30);
      cin.ignore();
    cout << "\nCustomer Phone Number: ";
    cin.get(temp_phone, 14);
      cin.ignore();
  cout << "\nCustomer Full Address: ";
    cin.get(temp_address, 100);
      cin.ignore();

  info temp_customer(temp_name, temp_email, temp_address, temp_phone);
  //delete the information and reallocate the memory for
  //the temporary char arrays
  delete temp_name;
  delete temp_email;
  delete temp_address;
  temp_name    = new char [31];
  temp_email   = new char [31];
  temp_address = new char [101];
  temp_phone   = new char [15];

  //collect company info
  cout << "\nCompany Name: ";
    cin.get(temp_name, 30);
      cin.ignore();

  cout << "\nCompany E-mail: ";
    cin.get(temp_email, 30);
      cin.ignore();

  cout << "\nCompany Phone Number: ";
    cin.get(temp_phone, 14);
      cin.ignore();

  cout << "\nCompany Full Address: ";
    cin.get(temp_address, 100);
      cin.ignore();
  //make a temp company object to pass into the add invoice functions
  info temp_company(temp_name, temp_email, temp_phone, temp_address);
    //deallocate memory
    delete temp_name;
    delete temp_email;
    delete temp_address;

  //collect money information
  float temp_total    = 0;
  float temp_received = 0;
  float temp_due      = 0;
  cout << "\nTotal Cost for the Job: ";
    cin >> temp_total;
      cin.ignore();
  cout << "\nAmount already paid: ";
    cin >> temp_total;
      cin.ignore();
  temp_due = temp_total - temp_received;

  //create a class object with that informations
   money temp_money(temp_total, temp_received, temp_due);
  //pass the newly collected temp data into an invoice object

  //Pass all of the objects into the add_new_invoice functoin in the menu class object
 // menu_obj.add_new_invoice(temp_customer, temp_company, temp_money);
  cout << "\n\npassing in\n";
  menu_obj.add_new_invoice(temp_customer, temp_company, temp_money, invoice_choice);


 ++id;
}
