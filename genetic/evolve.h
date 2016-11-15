#ifndef GENETIC_EVOLVE_H_
#define GENETIC_EVOLVE_H_
#include "genetic_core.h"
namespace genetic {
namespace evolve {
// Sum of the fitness of population
extern double totalfitness, totalbottemup;
// The maximum ascii character value
extern int MAX;
// The minimum ascii character value
extern int MIN;
// Randomly genorates a populaiton of strings consisting of characters between
// MIN and MAX
void GenorateBasePopulation();
// Determins the fitness of the population
void CalculateFitness();
// Sums the fitness and sets the cumulative fitness values of population
void CumulateFitness();
// Using SelectLow kills of 50% of the worst strings for population
void Killoff();
// Combines and mutates strings untill population is back at base level
void Reproduce();
// Randomly mutates one character from the strings based off of mutation rate
void Mutate();
// Using weighted randomness selects more fit population
int SelectHigh();
// Using weighted randomness selects less fit population
int SelectLow();
// Sums the fitness of population
void SumFitness();
// Sorts the population based of fitness best->worst
void Sort();
// Function to determine sorting system
bool SortCheck(const Chromosome a, const Chromosome b);
}
}
#endif
