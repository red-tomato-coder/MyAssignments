#include <iostream>
#include "Sphere.h"
#include "Banana.h"


int main(){
  Sphere NewSphere;
  Sphere MySphere(13.37);
  Banana NewBanana;
  Banana CoolBanana(20, 10, true);

  NewSphere.DisplayStatistics();
  MySphere.DisplayStatistics();

  NewSphere.SetRadius(81);
  NewSphere.DisplayStatistics();

  NewBanana.DisplayBananaStatus();
  CoolBanana.DisplayBananaStatus();
}
