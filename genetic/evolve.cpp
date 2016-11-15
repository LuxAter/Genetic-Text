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
namespace evolve {
double totalfitness = 0, totalbottemup = 0;
int MAX = 122;
int MIN = 32;
}
}

void genetic::evolve::GenorateBasePopulation() {
  for (int i = 0; i < populationsize; i++) {
    Chromosome newchromosome;
    for (int j = 0; j < chromosomelength; j++) {
      newchromosome.str += char((rand() % (MAX - MIN)) + MIN);
    }
    population.push_back(newchromosome);
  }
}

void genetic::evolve::CalculateFitness() {
  for (int i = 0; i < population.size(); i++) {
    population[i].fitness = 0;
    for (int j = 0; j < population[i].str.size(); j++) {
      if (population[i].str[j] == goalvalue[j]) {
        population[i].fitness += 1;
      } else {
        // population[i].fitness +=
        //    (1 / fabs(int(goalvalue[i]) - int(population[i].str[j])));
      }
    }
  }
}

void genetic::evolve::CumulateFitness() {
  double fitness = 0;
  for (int i = population.size() - 1; i >= 0; i--) {
    fitness += population[i].fitness;
    population[i].cumulativefitness = fitness;
  }
  fitness = 0;
  for (int i = 0; i < population.size(); i++) {
    fitness += population[i].fitness;
    population[i].bottemup = fitness;
  }
  totalbottemup = fitness;
}

void genetic::evolve::Killoff() {
  while (population.size() > ceil(populationsize / (double)2)) {
    population.erase(population.begin() + SelectLow());
  }
}

void genetic::evolve::Reproduce() {
  std::vector<Chromosome> newpop;
  std::vector<Chromosome> parents = population;
  while (newpop.size() + parents.size() < populationsize) {
    Chromosome newchromosome;
    newchromosome.str = "";
    int parentone = SelectHigh();
    int parenttwo = SelectHigh();
    if (parenttwo == parentone) {
      if (parenttwo == 0) {
        parenttwo++;
      } else {
        parenttwo = 0;
      }
    }
    for (int i = 0; i < chromosomelength; i++) {
      if (drand() < 0.5) {
        newchromosome.str += population[parenttwo].str[i];
      } else {
        newchromosome.str += population[parentone].str[i];
      }
    }
    newpop.push_back(newchromosome);
  }
  population.clear();
  population = parents;
  population.insert(population.end(), newpop.begin(), newpop.end());
}

void genetic::evolve::Mutate() {
  for (int i = 0; i < population.size(); i++) {
    for (int j = 0; j < chromosomelength; j++) {
      if (drand() < mutationrate) {
        /*int value = int(population[i].str[j]);
        if (drand() > 0.5) {
          value++;
        } else {
          value--;
        }
        if (value > MAX) {
          value = MIN;
        }
        if (value < MIN) {
          value = MAX;
        }
        population[i].str[j] = char(value);*/
        population[i].str[j] = char((rand() % (MAX - MIN)) + MIN);
      }
    }
  }
}

int genetic::evolve::SelectHigh() {
  double point = drand() * totalfitness;
  for (int i = population.size() - 1; i >= 0; i--) {
    if (population[i].cumulativefitness > point) {
      return (i);
    }
  }
  return (0);
}

int genetic::evolve::SelectLow() {
  double point = drand() * totalbottemup;
  for (int i = population.size() - 1; i >= 0; i--) {
    if (point < population[i].bottemup) {
      return (i);
    }
  }
  return (0);
}

void genetic::evolve::SumFitness() {
  for (int i = 0; i < population.size(); i++) {
    totalfitness += population[i].fitness;
  }
}

void genetic::evolve::Sort() {
  std::sort(population.begin(), population.end(), SortCheck);
}

bool genetic::evolve::SortCheck(const Chromosome a, const Chromosome b) {
  return a.fitness > b.fitness;
}
