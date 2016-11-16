#include "genetic/display.h"
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
  bool running = true;
  double mutation = 0.005;
  int population = 100, input = 0;
  std::string quote = "";
  std::vector<std::string> options = {
      "Meta Meta Analize", "Meta Analize",      "Analize", "Set Quote",
      "Set Population",    "Set Mutation Rate", "Quit"};
  while (running == true) {
    induco::Break();
    input = induco::Menu("Genetic Text Alogrithm", options);
    if (input == 1) {
      induco::Break();
      int startn = induco::GetValue("n-0");
      int endn = induco::GetValue("n-f");
      for (int i = startn; i < endn; i++) {
        quote = "";
        for (int j = 0; j < i; j++) {
          quote += char((rand() % (122 - 32)) + 32);
        }
        double totaltime = 0;
        long int totalgenorations = 0;
        for (int j = 0; j < 100; j++) {
          totaltime +=
              genetic::RunAlgorithm(quote, population, mutation, false);
          totalgenorations += genetic::genoration;
        }
        induco::Line(50);
        std::cout << "<" << i << ">\n";
        totaltime /= 100.0;
        totalgenorations /= 100.0;
        std::cout << "Average Genorations For All Genetic Runs: \n";
        std::cout << totalgenorations << "\n";
        std::cout << "Average Time For All Genetic Runs: \n";
        std::cout << induco::DisplayTime(totaltime, true) << "\n";
      }
      induco::Break();
      induco::Pause();
      induco::Break();
    }
    if (input == 2) {
      induco::Break();
      int iterations = induco::GetValue("Iterations");
      double totaltime = 0;
      long int totalgenorations = 0;
      for (int i = 0; i < iterations; i++) {
        if (quote == "") {
          std::ifstream quotes("Quotes.txt");
          std::string line = "";
          if (quotes.is_open()) {
            while (getline(quotes, line)) {
              quote += line;
            }
            quotes.close();
          }
        }
        if (population <= 0) {
          population = 1;
        }
        induco::Line(10);
        totaltime += genetic::RunAlgorithm(quote, population, mutation, true);
        totalgenorations += genetic::genoration;
      }
      induco::Break();
      genetic::display::DrawStr("\"" + quote + "\"");
      std::cout << "Total Genorations For All Genetic Runs: \n";
      std::cout << totalgenorations << "\n";
      std::cout << "Total Time For All Genetic Runs: \n";
      std::cout << induco::DisplayTime(totaltime, true) << "\n";
      totaltime /= (double)iterations;
      totalgenorations /= (double)iterations;
      std::cout << "Average Genorations For All Genetic Runs: \n";
      std::cout << totalgenorations << "\n";
      std::cout << "Average Time For All Genetic Runs: \n";
      std::cout << induco::DisplayTime(totaltime, true) << "\n";
      induco::Line(induco::GetSize());
      induco::Pause();
      induco::Break();
    }
    if (input == 3) {
      induco::Break();
      if (quote == "") {
        std::ifstream quotes("Quotes.txt");
        std::string line = "";
        if (quotes.is_open()) {
          while (getline(quotes, line)) {
            quote += line;
          }
          quotes.close();
        }
      }
      if (population <= 0) {
        population = 1;
      }
      genetic::RunAlgorithm(quote, population, mutation);
    }
    if (input == 4) {
      induco::Break();
      quote = induco::SGetValue("Quote");
    }
    if (input == 5) {
      induco::Break();
      population = round(induco::GetValue("Population"));
    }
    if (input == 6) {
      induco::Break();
      mutation = induco::GetValue("Mutate");
    }
    if (input == 7) {
      induco::Break();
      running = false;
    }
  }
  return (1);
}
