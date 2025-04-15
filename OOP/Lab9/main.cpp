#include <iostream>
#include "Sphere.h"
#include "Ball.h"
#include "MassBall.h"

int main(){
  Sphere NewSphere;
  Sphere MySphere(13.37);
  Ball NewBall;
  Ball MyBall(15, "BLL");
  MassBall NewMassBall;
  MassBall MyMassBall(99, "BASKETBOL ^_^", 3);

  NewSphere.DisplayStatistics();
  MySphere.DisplayStatistics();

  NewSphere.SetRadius(81);
  NewSphere.DisplayStatistics();

  std::cout << "00000000000" << std::endl;
  std::cout << NewBall.GetName() << std::endl;
  std::cout << "00000000000" <<std::endl;

  NewBall.SetName("AMOGUS");
  MyBall.ResetBall(18, "18");

  NewBall.DisplayStatistics();
  MyBall.DisplayStatistics();


  NewMassBall.DisplayStatistics();
  MyMassBall.DisplayStatistics();
}
