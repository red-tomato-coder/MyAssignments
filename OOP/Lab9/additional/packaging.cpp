#include "packaging.h"
#include <iostream>

Packaging::Packaging()
    : Croissant(), material("Папір"), color("Білий"), isSealed(false) {}

Packaging::Packaging(std::string InitialTimeOfProduction, int InitialLength, int InitialWidth,
                     std::string material, std::string color, bool sealed)
    : Croissant(InitialTimeOfProduction, InitialLength, InitialWidth),
      material(material), color(color), isSealed(sealed) {}

void Packaging::ChangeMaterial(const std::string& newMaterial) {
    material = newMaterial;
}

void Packaging::ChangeColor(const std::string& newColor) {
    color = newColor;
}

void Packaging::Seal() {
    isSealed = true;
}

void Packaging::Unseal() {
    isSealed = false;
}

void Packaging::Statistics() const {
    Croissant::Statistics();
    std::cout << "Матеріал упаковки: " << material << std::endl
              << "Колір упаковки: " << color << std::endl
              << "Запечатано: " << (isSealed ? "Так" : "Ні") << std::endl;
}
