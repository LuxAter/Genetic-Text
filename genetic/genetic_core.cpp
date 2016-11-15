#include "../induco.h"
#include "display.h"
#include "evolve.h"
#include "genetic_core.h"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace genetic {
int populationsize = 100, chromosomelength = 10, genoration = 0;
double mutationrate = 0.001;
std::string goalvalue = "";
std::vector<Chromosome> population;
}

double genetic::RunAlgorithm(std::string gova, int popsize, double mutate) {
  if (popsize != -1) {
    populationsize = popsize;
  }
  chromosomelength = gova.size();
  goalvalue = gova;
  if (mutate != -1) {
    mutationrate = mutate;
  }
  bool running = true;
  /*for (int i = 0; i < goalvalue.size(); i++) {
    if (goalvalue[i] == '.') {
      goalvalue[i] = '`';
    }
    if (goalvalue[i] == ' ') {
      goalvalue[i] = '_';
    }
  }*/
  display::DrawStr("[" + goalvalue + "]");
  std::cout << "\n";
  evolve::GenorateBasePopulation();
  genoration = 0;
  while (running == true) {
    evolve::CalculateFitness();
    evolve::SumFitness();
    evolve::Sort();
    evolve::CumulateFitness();
    display::DrawStr(0);
    // std::cout << "\n";
    for (int i = 0; i < population.size(); i++) {
      // display::DrawStr(i);
      // std::cout << ":" << population[i].fitness << ":"
      //          << population[i].cumulativefitness << "\n";
    }
    if (population[0].str == goalvalue) {
      running = false;
      break;
    }
    evolve::Killoff();
    evolve::Reproduce();
    evolve::Mutate();
    // induco::Line(10);
    genoration++;
  }
  std::cout << "\n";
  if (population[0].str == goalvalue) {
    induco::Break();
    std::cout << "Solved in " << genoration << "\n";
    display::DrawStr(0);
  } else {
    induco::Break();
    std::cout << "Failed to solve in " << genoration << "\n";
    std::cout << "Closest value to [" << goalvalue << "]:\n";
    display::DrawStr(0);
  }
  Clean();
  return (0.0);
}

double genetic::drand() { return (fabs((double)rand() / (RAND_MAX + 1))); }

void genetic::Clean() {

  population.clear();
  goalvalue = "";
  populationsize = 0;
  chromosomelength = 0;
  genoration = 0;
  mutationrate = 0;
  evolve::totalfitness = 0;
  evolve::totalbottemup = 0;
}
