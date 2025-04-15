#include "Banana.h"
#include <iostream>

Banana::Banana(): Length(15.0), Ripeness(5), EmotionallyReady(false) {}

Banana::Banana(double length, int ripeness, bool emotionallyReady) {
  Length = (length > 0) ? length : 15.0;
  Ripeness = (ripeness >= 1 && ripeness <= 10) ? ripeness : 5;
  EmotionallyReady = emotionallyReady;
}

void Banana::SetLength(double newLength) {
  Length = (newLength > 0) ? newLength : 15.0;
}

void Banana::SetRipeness(int newRipeness) {
  Ripeness = (newRipeness >= 1 && newRipeness <= 10) ? newRipeness : 5;
}

void Banana::SetEmotionalState(bool isReady) {
  EmotionallyReady = isReady;
}

double Banana::GetLength() const {
  return Length;
}

int Banana::GetRipeness() const {
  return Ripeness;
}

bool Banana::IsEmotionallyReady() const {
  return EmotionallyReady;
}

std::string Banana::GetFlavorProfile() const {
  if (Ripeness <= 3) return "На смак як делфі - жахливий";
  if (Ripeness <= 6) return "Солодкий на смак, зійде";
  if (Ripeness <= 8) return "Дуже класний банан";
  return "САМИЙ ЧУДОВИЙ БАНАН, ЩО Є ТІЛЬКИ В ЦЬОМУ СВІТІ";
}

void Banana::DisplayBananaStatus() const {
  std::cout << "Довжина банана: " << Length << " см"
            << "\nСтиглість (1-10): " << Ripeness
            << "\nГотовність до споживання (емоційна): " 
            << (EmotionallyReady ? "Так" : "Ні")
            << "\nСмаковий профіль: " << GetFlavorProfile()
            << "\n==========" << std::endl;
}
