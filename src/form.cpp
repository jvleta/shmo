#include <math.h>
#include <stdio.h>

#include "distributions.h"
#include "form.h"

int run_form(const RECData &input) {
  double mean_g = input.mean_resistance - input.mean_load;
  double sigma_g =
      sqrt(pow(input.sigma_load, 2.0) + pow(input.sigma_resistance, 2.0));
  double beta = mean_g / sigma_g;

  printf("Beta       = %3.3f\n", beta);
  printf("Pf (exact) = %3.3e\n", normal_cdf(mean_g, sigma_g, 0.0));

  return 0;
}