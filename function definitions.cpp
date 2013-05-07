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




invoice::invoice()
{


}


invoice::~invoice(){}

void invoice::invoice_type(){}

///////////LAWN CARE CLASS
lawncare::lawncare(){

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
painting::painting(){

}

painting::~painting(){

}

void painting::invoice_type(){

}



//////////catering class
catering::catering(){

}

catering::~catering(){

}
void catering::invoice_type(){

}

