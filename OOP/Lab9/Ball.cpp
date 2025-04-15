#include "Ball.h"
#include <iostream>

Ball::Ball() : Sphere(1.0), Name("Cool Ball") {}

Ball::Ball(double InitialRadius, const std::string& Name) : Sphere(InitialRadius), Name(Name) {}

std::string Ball::GetName() const {
    return Name;
}

void Ball::SetName(const std::string& NewName) {
    Name = NewName;
}

void Ball::ResetBall(double NewRadius, const std::string NewName) {
    SetRadius(NewRadius);
    SetName(NewName);
}

void Ball::DisplayStatistics() const {
    std::cout << "Назва: " << Name << std::endl;
    Sphere::DisplayStatistics();
}

