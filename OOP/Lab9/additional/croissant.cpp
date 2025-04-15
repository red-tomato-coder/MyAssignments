
#include "croissant.h"
#include "flavour.h"
#include <iostream>

Croissant::Croissant()
    : flavour("Шоколад"), TimeOfProduction("14-04-2025 23:51"), length(25), width(10) {}

void Croissant::ChangeLength(int NewLength) {
    length = (NewLength < 0) ? 20 : NewLength;
}

void Croissant::ChangeWidth(int NewWidth) {
    width = (NewWidth < 0) ? 20 : NewWidth;
}

void Croissant::Statistics() const {
    flavour.Statistics();  // assuming Flavour has this method
    std::cout << "Довжина круасанта: " << length << std::endl
              << "Ширина круасанта: " << width << std::endl;
}

