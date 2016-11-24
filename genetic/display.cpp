#include "../induco.h"
#include "display.h"
#include "genetic_core.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

void genetic::display::DrawStr(int pointer) {
  int width = induco::GetSize();
  std::cout << "\r ";
  if (width < population[pointer].str.size() - 2) {
    for (int i = 0; i < (width - 5); i++) {
      std::cout << population[pointer].str[i];
    }
    std::cout << "...";
  } else {
    std::cout << population[pointer].str;
  }	
}

void genetic::display::DrawStr(std::string str) {
  int width = induco::GetSize();
  std::cout << "\r";
  if (width < str.size() - 2) {
    for (int i = 0; i < (width - 4); i++) {
      std::cout << str[i];
    }
    std::cout << "...";
  } else {
    std::cout << str;
  }
}
