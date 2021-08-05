#include "form.h"
#include "mcs.h"
#include "recdata.h"

int main() {
  double mean_load = 30.0;
  double sigma_load = 3.0;
  double mean_resistance = 45.0;
  double sigma_resistance = 3.0;

  struct RECData input;
  input.mean_load = mean_load;
  input.sigma_load = sigma_load;
  input.mean_resistance = mean_resistance;
  input.sigma_resistance = sigma_resistance;

  run_mcs(input);
  run_form(input);

  return 0;
}