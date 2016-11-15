#ifndef GENETIC_GENETIC_CORE_H_
#define GENETIC_GENETIC_CORE_H_
#include <cmath>
#include <string>
#include <vector>
namespace genetic {
struct Chromosome {
  std::string str;
  double value, fitness, cumulativefitness, bottemup;
};
// Stores population size, string length, and the current genoration count
extern int populationsize, chromosomelength, genoration;
// Stores the mutation rate %
extern double mutationrate;
// Goal string to match
extern std::string goalvalue;
// Population of strings
extern std::vector<Chromosome> population;
// Core genetic population loop
double RunAlgorithm(std::string gova = "", int popsize = -1,
                    double mutate = -1);
// Genorates a random double from 0-1
double drand();
// Sets all namespace values to defaults of 0
void Clean();
}
#endif
