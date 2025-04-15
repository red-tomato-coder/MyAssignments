#ifndef FLAVOUR_H
#define FLAVOUR_H

#include <string>

class Flavour{
  public:
    Flavour();
    Flavour(std::string NewTaste);

    void ChangeFlavour(std::string NewTaste) ;
    std::string GetTaste() const;
    virtual void Statistics() const;

  private:
    std::string taste;
};

#endif // !FLAVOUR_H
