#include "Sphere.h"
#include <iostream>

Sphere::Sphere(): TheRadius(1.0){
  
}

Sphere::Sphere(double InitialRadius){
  if(InitialRadius > 0){
    TheRadius = InitialRadius;
  }
  else{
    TheRadius = 1.0;
  }
}

void Sphere::SetRadius(double RadiusSet){
  if(RadiusSet > 0){
    TheRadius = RadiusSet;
  }
  else{
    TheRadius = 1.0;
  }
}

double Sphere::GetRadius() const {
  return TheRadius;
}

double Sphere::GetDiameter() const {
  return 2.0 * TheRadius;
}

double Sphere::GetCircumference() const {
  return Pi * GetDiameter();
}

double Sphere::GetArea() const {
  return Pi * TheRadius * TheRadius;
}

double Sphere::GetVolume() const {
  double RadiusCube = TheRadius * TheRadius * TheRadius;
  return (4.0 * Pi * RadiusCube) / 3.0;
}

void Sphere::DisplayStatistics() const {
  std::cout << "Радіус: " << GetRadius()
            << "\nДіаметер: " << GetDiameter()
            << "\nДовжина: " << GetCircumference()
            << "\nПлоща: " << GetArea()
            << "\nОб'єм: " << GetVolume()
            << "\n==========" << std::endl;
}
