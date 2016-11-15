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
  // Seeds the random number genoration to the begining time of the program
  srand(time(NULL));
  // Adds a visual space
  induco::Break();
  // Opens file "Quotes.txt" and get all the text in a single line as quote
  std::ifstream quotes("Quotes.txt");
  std::string quote = "", line = "";
  if (quotes.is_open()) {
    while (getline(quotes, line)) {
      quote += line;
    }
    quotes.close();
  }
  // Runs genetic Algorithm with quote, a population of 100, and a mutation
  // chance of 0.005%
  genetic::RunAlgorithm(quote, 100, 0.005);
  // Adds a visual space
  induco::Break();
  return (1);
}
