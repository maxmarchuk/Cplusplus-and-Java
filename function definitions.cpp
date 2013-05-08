#include "hfile2.h"


info::info(){

  name    = new char[31];
  email   = new char[31];
  address = new char[101];
  phone   = new char[15];
}


info::info(char * new_name, char * new_email, char * new_address, char * new_phone){

  //allocate the memory for the new object
  name    = new char[31];
  email   = new char[31];
  address = new char[101];
  phone   = new char[15];

  //copy the given input into it right away
  strcpy(name, new_name);
  strcpy(email, new_email);
  strcpy(address, new_address);
  strcpy(phone, new_phone);

}

//default destructor
info::~info(){
  //deallocate all of the dynamic memory
  delete name;
  delete email;
  delete address;
}

char * info::get_name(){

  return name;
}


//////////////////////////
// INVOICE CLASS////////////
//////////////////////////

invoice::invoice()
{


}
  void invoice::set_company(info &new_company){}
  void invoice::set_customer(info &new_person){}
  void invoice::set_money(money &new_money){}


invoice::~invoice(){}

void invoice::display(){}

///////////LAWN CARE CLASS
lawncare::lawncare(info new_person, info new_company, money new_money){
  cout << "\nWhat is the frequency of lawncare that is being provided? (times per week): ";
  cin >> frequency_of_care;
  cin.ignore();

  //finally copy all of the necessary data over
  set_company(new_company);
  set_customer(new_person);
  set_money(new_money);

}

lawncare::~lawncare(){

}
void lawncare::invoice_type(){

}

////MONEY CLASS

//default constructor; set everything to zero
money::money(){

  total = 0.0;
  received = 0.0;
  due = 0.0;

}

//my specified constructor that takes in the data and simply et sit
money::money(float new_total, float new_received, float new_due){

  total = new_total;
  received = new_received;
  due = new_due;

}

money::~money(){

}


/////PAINTING CLASS
painting::painting(info new_person, info new_company, money new_money){

  int has_warranty = 1;//default 1 for warranty

  cout << "\nDid "<< new_person.get_name() << " pay for warranty on the paint job?"
       << "\n1) Yes"
       << "\n2) No"
       << "Enter 1 or 2: ";
  cin >> has_warranty;
  cin.ignore();
  if(has_warranty == 1)
    set_warranty(true);
  else
    set_warranty(false);

  //finally copy all of the necessary data over
  set_company(new_company);
  set_customer(new_person);
  set_money(new_money);

}

void painting::set_warranty(bool has_warranty){

  warranty = has_warranty;

}

painting::~painting(){

}

void painting::invoice_type(){

}



//////////catering class
catering::catering(info new_person, info new_company, money new_money){

  int has_warranty = 1;//default 1 for warranty

  cout << "\nHow far must the employee drive to deliver the food?\nHours: ";
  cin >> driving_distance;
  cin.ignore();

  //finally copy all of the necessary data over
  set_company(new_company);
  set_customer(new_person);
  set_money(new_money);

}

catering::~catering(){

}
void catering::invoice_type(){

}

