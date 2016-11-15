#include "../induco.h"
#include "display.h"
#include "genetic_core.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

void genetic::display::DrawStr(int pointer) {
  /*std::string out = population[pointer].str;
  for (int i = 0; i < out.size(); i++) {
    if (out[i] == '`') {
      out[i] = '.';
    }
    if (out[i] == '_') {
      out[i] = ' ';
    }
  }*/
  std::cout << "\r " << population[pointer].str;
}

void genetic::display::DrawStr(std::string str) {
  std::string out = str;
  /*for (int i = 0; i < out.size(); i++) {
    if (out[i] == '`') {
      out[i] = '.';
    }
    if (out[i] == '_') {
      out[i] = ' ';
    }
  }*/
  std::cout << "\r" << out;
}
