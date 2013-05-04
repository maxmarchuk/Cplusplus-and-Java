#include "hfile2.h"


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



