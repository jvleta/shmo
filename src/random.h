#pragma once

#include "arrays.h"

struct random_variable {
  char *distribution_type;
  double mu;
  double cv;
  double sigma;
};

std::vector<double> uniform_probability_samples(int nsamples);
std::vector<double> uniform_rv_samples(double xmin, double xmax, int nsamples);
std::vector<double> exponential_rv_samples(double lambda, int nsamples);
std::vector<double> weibull_rv_samples(double alpha, double beta, int nsamples);
std::vector<double> normal_rv_samples(double mu, double sigma, int nsamples);
std::vector<double> lognormal_rv_samples(double mu, double sigma, int nsamples);
