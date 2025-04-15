#ifndef SPHERE_H
#define SPHERE_H

//Я ВІДМОВИВСЯ ВІД КОНТРОЛЮ MICROSOFT НАД МОЇМ КОДОМ З ЇХНІМИ #pragma once.
//Не шкодую про це

const double Pi = 3.14159;

class Sphere {
  public:
    Sphere();
    Sphere(double InitialRadius);
    void SetRadius(double RadiusSet);

    double GetRadius() const;
    double GetDiameter() const;
    double GetCircumference() const;
    double GetArea() const;
    double GetVolume() const;

    virtual void DisplayStatistics() const;

  private:
    double radius;
};

#endif // SPHERE_H
