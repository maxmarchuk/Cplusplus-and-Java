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
