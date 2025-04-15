#include "MassBall.h"
#include <iostream>

MassBall::MassBall() : Ball(1.0, "BIG BALL"), Density(0.9) {}

MassBall::MassBall(double InitialRadius, const std::string& Name, double Density) : Ball(InitialRadius, Name), Density(Density) {}

double MassBall::Mass() const{
  return Density * Sphere::GetVolume();
}

void MassBall::DisplayStatistics() const {
    std::cout << "Густина: " << Density << std::endl;
    std::cout << "Маса: " << MassBall::Mass() << std::endl;
    Ball::DisplayStatistics();

}

