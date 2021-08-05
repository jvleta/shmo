#include "arrays.h"
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

std::vector<double> init_array(int nvalues) {
  std::vector<double> x(nvalues);
  return x;
}

std::vector<double> zeros(int nvalues) {
  auto x = init_array(nvalues);
  int index = 0;
  std::for_each(x.begin(), x.end(), [&](int index) {
    x[index] = 0.0;
    ++index;
  });
  return x;
}

std::vector<double> ones(int nvalues) {
  auto x = init_array(nvalues);
  int index = 0;
  std::for_each(x.begin(), x.end(), [&](int index) {
    x[index] = 1.0;
    ++index;
  });
  return x;
}

std::vector<double> linspace(double min, double max, int nvalues) {
  std::vector<double> x = init_array(nvalues);
  for (int index = 0; index < length(x); index++) {
    x[index] = min + (max - min) / (double)(nvalues - 1.0) * (double)(index);
  }
  return x;
}

void savetxt(char *filename, double *data) {
  FILE *f = fopen(filename, "w");
  for (int i = 0; i < length(data); i++) {
    fprintf(f, "%f\n", data[i]);
  }
}