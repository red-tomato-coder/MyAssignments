#ifndef MASSBALL_H
#define MASSBALL_H

#include "Ball.h"

class MassBall : public Ball {
public:
    MassBall();
    MassBall(double InitialRadius, const std::string& Name, double Density);

    double Mass() const;

    virtual void DisplayStatistics() const override;

private:
    std::string Name;
    double Density;
};

#endif // BALL_H

