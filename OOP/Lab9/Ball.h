#ifndef BALL_H
#define BALL_H

#include "Sphere.h"
#include <string>

class Ball : public Sphere {
public:
    Ball();
    Ball(double InitialRadius, const std::string& Name);

    std::string GetName() const;
    void SetName(const std::string NewName);
    void ResetBall(double NewRadius, const std::string& NewName);

    virtual void DisplayStatistics() const override;

private:
    std::string Name;
};

#endif // BALL_H

