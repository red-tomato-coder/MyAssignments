#ifndef CROISSANT_H
#define CROISSANT_H

#include <string>
#include "flavour.h"

class Croissant{
  public:
    Croissant(std::string InitialTimeOfProduction, int InitialLength, int InitialWidth);
    Croissant();
    void ChangeLength(int NewLength);
    void ChangeWidth(int NewWidth);
    void virtual Statistics() const;

  private:
    Flavour flavour;
    std::string TimeOfProduction;
    int length;
    int width;
};

#endif // !CROISSANT_H
