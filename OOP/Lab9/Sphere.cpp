#include "Sphere.h"
#include <iostream>

Sphere::Sphere(): radius(1.0){
  
}

Sphere::Sphere(double InitialRadius){
  if(InitialRadius > 0){
    radius = InitialRadius;
  }
  else{
    radius = 1.0;
  }
}

void Sphere::SetRadius(double RadiusSet){
  if(RadiusSet > 0){
    radius = RadiusSet;
  }
  else{
    radius = 1.0;
  }
}

double Sphere::GetRadius() const {
  return radius;
}

double Sphere::GetDiameter() const {
  return 2.0 * radius;
}

double Sphere::GetCircumference() const {
  return Pi * GetDiameter();
}

double Sphere::GetArea() const {
  return Pi * radius * radius;
}

double Sphere::GetVolume() const {
  double RadiusCube = radius * radius * radius;
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
