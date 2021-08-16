#include "misc.h"
#include <math.h>

constexpr double one_half = 0.5;
constexpr double zero = 0.0;
constexpr double one = 1.0;
constexpr double two = 2.0;
constexpr double twopi = M_PI * 2;
constexpr double sqrt_of_two = M_SQRT2;

double exponential_pdf(double lambda, double x) {
  return lambda * std::exp(-lambda * x);
}

double exponential_cdf(double lambda, double x) {
  return one - std::exp(-lambda * x);
}

double exponential_cdf_inverse(double lambda, double p) {
  return (-one / lambda) * std::log(one - p);
}

double gumbel_pdf(double alpha, double beta, double x) { return zero; }

double gumbel_cdf(double alpha, double beta, double x) { return zero; }

double gumbel_cdf_inverse(double alpha, double beta, double p) { return zero; }

double weibull_pdf(double alpha, double beta, double x) {
  return (beta / alpha) * std::pow((x / alpha), (beta - 1)) *
         std::exp(-(std::pow((x / alpha), beta)));
}

double weibull_cdf(double alpha, double beta, double x) {
  return one - std::exp(-std::pow((x / alpha), beta));
}

double weibull_cdf_inverse(double alpha, double beta, double p) {
  return alpha * std::pow(-std::log(one - p), (one / beta));
}

double normal_pdf(double mu, double sigma, double x) {
  return one / (sigma * sqrt(twopi)) *
         std::exp(-one_half * std::pow(((x - mu) / sigma), two));
}

double normal_cdf(double mu, double sigma, double x) {
  double z = (x - mu) / sigma;
  return one_half * erfc(-z / sqrt_of_two);
}

double normal_cdf_inverse(double mu, double sigma, double p) {
  double x0 = -sqrt_of_two * erfcinv(two * p);
  return sigma * x0 + mu;
}

double lognormal_pdf(double median, double cv, double x) {
  double mu = std::log(median);
  double sigma = sqrt(std::log(std::pow(cv, two) + one));
  return one / (x * sigma) * normal_pdf((std::log(x) - mu) / sigma, zero, one);
}

double lognormal_cdf(double median, double cv, double x) {
  double mu = std::log(median);
  double sigma = sqrt(std::log(std::pow(cv, two) + one));
  return normal_cdf(std::log(x), mu, sigma);
}

double lognormal_pdf(double mu, double sigma, double x) {
  return one / (x * sigma) * normal_pdf((std::log(x) - mu) / sigma, zero, one);
}

double lognormal_cdf(double mu, double sigma, double x) {
  return normal_cdf(std::log(x), mu, sigma);
}

double lognormal_cdf_inverse(double mu, double sigma, double p) {
  return mu + sigma * std::exp(normal_cdf_inverse(p, mu, sigma));
}
