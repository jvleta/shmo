#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "distributions.h"
#include "random.h"
#include "recdata.h"

int run_mcs(const RECData &input) {
  int number_of_simulations = 1000000;
  int process_id;
  double load, resistance;
  int isim;
  int number_of_fails = 0;
  double g = 0.0;
  double failure_probability = 0.0;
  int total_number_of_failures = 0;

  double mean_load = input.mean_load;
  double sigma_load = input.sigma_load;

  double mean_resistance = input.mean_resistance;
  double sigma_resistance = input.sigma_resistance;

  auto load_samples =
      normal_rv_samples(mean_load, sigma_load, number_of_simulations);
  auto resistance_samples = normal_rv_samples(mean_resistance, sigma_resistance,
                                              number_of_simulations);

  for (isim = 0; isim < number_of_simulations; isim++) {
    load = load_samples[isim];
    resistance = resistance_samples[isim];
    g = resistance - load;

    if (g <= 0) {
      number_of_fails++;
    }
  }

  failure_probability =
      ((double)number_of_fails) / ((double)number_of_simulations);

  printf("Pf (mcs)   = %3.3e\n", failure_probability);

  return 0;
}