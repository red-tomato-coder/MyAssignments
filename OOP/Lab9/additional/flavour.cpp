#include "flavour.h"
#include <iostream>
#include <string>

Flavour::Flavour(): taste("ШОКОЛАД :)"){

}

Flavour::Flavour(std::string NewTaste){
  if(NewTaste != ""){
    taste = NewTaste;
  }   
  else{
    taste = "ШОКОЛАД :)";
  }
}

void Flavour::ChangeFlavour(std::string NewTaste) {
  if(NewTaste != ""){
    taste = NewTaste;
  }
  else{
    taste = "ШОКОЛАД :)";
  }
}

std::string Flavour::GetTaste() const{
  return taste;
}

void Flavour::Statistics() const{
  std::cout << "==========\n"
    << "Смак: " << taste <<std::endl;
}
