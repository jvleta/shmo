#pragma once

#include <vector>

#define length(x) (sizeof(x) / sizeof((x)[0]))

typedef struct vector {
  double *elements;
  int length;
} vector;

typedef struct matrix {
  double **elements;
  double *elements_data;
  int nrows;
  int ncols;
} matrix;

std::vector<double> zeros(int nvalues);
std::vector<double> ones(int nvalues);
std::vector<double> linspace(double min, double max, int nvalues);
void savetxt(char *filename, double *data);
