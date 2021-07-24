#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "distributions.h"
#include "random.h"

int main(int argc, char *argv[]) {
  int number_of_simulations = 10000000;
  int process_id;
  double load, resistance;
  int isim;
  int number_of_fails = 0;
  double g = 0.0;
  double failure_probability = 0.0;
  int total_number_of_failures = 0;
 
  double mean_load = 30.0;
  double sigma_load = 3.0;

  double mean_resistance = 45.0;
  double sigma_resistance = 3.0;

  struct vector *load_samples;
  struct vector *resistance_samples;

  double mean_g = 0.0;
  double sigma_g = 0.0;
  double beta = 0.0;

  load_samples =
      normal_rv_samples(mean_load, sigma_load, number_of_simulations);
  resistance_samples = normal_rv_samples(mean_resistance, sigma_resistance,
                                         number_of_simulations);

  for (isim = 0; isim < number_of_simulations; isim++) {
    load = load_samples->elements[isim];
    resistance = resistance_samples->elements[isim];
    g = resistance - load;

    if (g <= 0) {
      number_of_fails++;
    }
  }

  failure_probability =
      ((double)number_of_fails) / ((double) number_of_simulations);
  mean_g = mean_resistance - mean_load;
  sigma_g = sqrt(pow(sigma_load, 2.0) + pow(sigma_resistance, 2.0));
  beta = mean_g / sigma_g;

  printf("Pf (mcs)   = %3.3e\n", failure_probability);
  printf("Beta       = %3.3f\n", beta);
  printf("Pf (exact) = %3.3e\n", normal_cdf(mean_g, sigma_g, 0.0));

  return 0;
}