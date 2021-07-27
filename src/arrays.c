#include "arrays.h"
#include <stdio.h>
#include <stdlib.h>

double *init_array(int nvalues) {
  double *x = malloc(sizeof(double) * nvalues);
  return x;
}

double *copy(const double *x) {
  double *y = zeros(length(x));
  for (int ix = 0; ix < length(x); ix++) {
    y[ix] = x[ix];
  }
  return y;
}

double *zeros(int nvalues) {
  double *x = init_array(nvalues);
  for (size_t index = 0; index < length(x); index++) {
    x[index] = 0.0;
  }
  return x;
}

double *ones(int nvalues) {
  double *x = init_array(nvalues);
  for (int index = 0; index < length(x); index++) {
    x[index] = 1.0;
  }
  return x;
}

double *linspace(double min, double max, int nvalues) {
  double *x = init_array(nvalues);
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