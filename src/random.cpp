#include "random.h"
#include "distributions.h"
#include <stdlib.h>

std::vector<double> uniform_probability_samples(int nsamples) {
  std::vector<double> x = zeros(nsamples);

  for (int index = 0; index < nsamples; index++) {
    x[index] = ((double)rand() / (double)RAND_MAX);
  }

  return x;
}

std::vector<double> uniform_rv_samples(double xmin, double xmax, int nsamples) {
  std::vector<double> p = uniform_probability_samples(nsamples);
  std::vector<double> x = zeros(nsamples);

  for (int index = 0; index < nsamples; index++) {
    x[index] = xmin + p[index] * (xmax - xmin);
  }

  return x;
}

std::vector<double> exponential_rv_samples(double lambda, int nsamples) {
  std::vector<double> p = uniform_probability_samples(nsamples);
  std::vector<double> x = zeros(nsamples);

  for (int index = 0; index < nsamples; index++) {
    x[index] = exponential_cdf_inverse(lambda, p[index]);
  }

  return x;
}

std::vector<double> weibull_rv_samples(double alpha, double beta,
                                       int nsamples) {
  std::vector<double> p = uniform_probability_samples(nsamples);
  std::vector<double> x = zeros(nsamples);

  for (int index = 0; index < nsamples; index++) {
    x[index] = weibull_cdf_inverse(alpha, beta, p[index]);
  }

  return x;
}

std::vector<double> normal_rv_samples(double mu, double sigma, int nsamples) {
  std::vector<double> p = uniform_probability_samples(nsamples);
  std::vector<double> x = zeros(nsamples);

  for (int index = 0; index < nsamples; index++) {
    x[index] = normal_cdf_inverse(mu, sigma, p[index]);
  }

  return x;
}

std::vector<double> lognormal_rv_samples(double mu, double sigma,
                                         int nsamples) {
  std::vector<double> p = uniform_probability_samples(nsamples);
  std::vector<double> x = zeros(nsamples);

  for (int index = 0; index < nsamples; index++) {
    x[index] = lognormal_cdf_inverse(mu, sigma, p[index]);
  }

  return x;
}