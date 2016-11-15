#include "../induco.h"
#include "display.h"
#include "genetic_core.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

void genetic::display::DrawStr(int pointer) {
  std::cout << "\r " << population[pointer].str;
}

void genetic::display::DrawStr(std::string str) { std::cout << "\r" << str; }
