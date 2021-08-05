#include "misc.h"
#include <math.h>

double exponential_pdf(double lambda, double x) {
  return lambda * exp(-lambda * x);
}

double exponential_cdf(double lambda, double x) {
  return 1.0 - exp(-lambda * x);
}

double exponential_cdf_inverse(double lambda, double p) {
  return (-1.0 / lambda) * log(1.0 - p);
}

double gumbel_pdf(double alpha, double beta, double x) { return 0.0; }

double gumbel_cdf(double alpha, double beta, double x) { return 0.0; }

double gumbel_cdf_inverse(double alpha, double beta, double p) { return 0.0; }

double weibull_pdf(double alpha, double beta, double x) {
  return (beta / alpha) * pow((x / alpha), (beta - 1)) *
         exp(-(pow((x / alpha), beta)));
}

double weibull_cdf(double alpha, double beta, double x) {
  return 1.0 - exp(-pow((x / alpha), beta));
}

double weibull_cdf_inverse(double alpha, double beta, double p) {
  return alpha * pow(-log(1.0 - p), (1.0 / beta));
}

double normal_pdf(double mu, double sigma, double x) {
  double pi = 3.14159;
  return 1. / (sigma * sqrt(2. * pi)) * exp(-.5 * pow(((x - mu) / sigma), 2.0));
}

double normal_cdf(double mu, double sigma, double x) {
  double z = (x - mu) / sigma;
  return 0.5 * erfc(-z / sqrt(2.));
}

double normal_cdf_inverse(double mu, double sigma, double p) {
  double x0 = -sqrt(2.0) * erfcinv(2.0 * p);
  return sigma * x0 + mu;
}

double lognormal_pdf(double mu, double sigma, double x) {
  return 1.0 / (x * sigma) * normal_pdf((log(x) - mu) / sigma, 0.0, 1.0);
}

double lognormal_cdf(double mu, double sigma, double x) {
  return normal_cdf(log(x), mu, sigma);
}

double lognormal_cdf_inverse(double mu, double sigma, double p) {
  return mu + sigma * exp(normal_cdf_inverse(p, mu, sigma));
}