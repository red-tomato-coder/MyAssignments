#ifndef BANANA_H
#define BANANA_H

#include <string>

class Banana {
  public:
    Banana();
    Banana(double length, int ripeness, bool emotionallyReady);

    void SetLength(double newLength);
    void SetRipeness(int newRipeness);
    void SetEmotionalState(bool isReady);

    double GetLength() const;
    int GetRipeness() const;
    bool IsEmotionallyReady() const;

    std::string GetFlavorProfile() const;
    void DisplayBananaStatus() const;

  private:
    double Length;
    int Ripeness;
    bool EmotionallyReady;
};

#endif // BANANA_H
