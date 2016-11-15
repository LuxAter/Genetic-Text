#include "genetic/genetic_core.h"
#include "induco.h"
#include <fstream>
#include <iostream>
#include <pessum.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  srand(time(NULL));
  pessum::InitializePessumComponents();
  induco::Break();
  std::ifstream quotes("Quotes.txt");
  std::string quote = "", line = "";
  if (quotes.is_open()) {
    while (getline(quotes, line)) {
      quote += line;
    }
    quotes.close();
  }
  genetic::RunAlgorithm(quote, 100, 0.005);
  induco::Break();
  pessum::TerminatePessumComponents();
  return (1);
}
