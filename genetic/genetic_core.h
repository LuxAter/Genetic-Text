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
extern int populationsize, chromosomelength, genoration;
extern double mutationrate;
extern std::string goalvalue;
extern std::vector<Chromosome> population;
double RunAlgorithm(std::string gova = "", int popsize = -1,
                    double mutate = -1);
double drand();
void Clean();
}
#endif
