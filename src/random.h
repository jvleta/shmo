#ifndef RANDOM_H_
#define RANDOM_H_

#include "arrays.h"

typedef struct random_variable
{
    char *distribution_type;
    double mu;
    double cv;
    double sigma; 
} random_variable;

struct vector *uniform_probability_samples(int nsamples);
struct vector *uniform_rv_samples(double xmin, double xmax, int nsamples);
struct vector *exponential_rv_samples(double lambda, int nsamples);
struct vector *weibull_rv_samples(double alpha, double beta, int nsamples);
struct vector *normal_rv_samples(double mu, double sigma, int nsamples);
struct vector *lognormal_rv_samples(double mu, double sigma, int nsamples);

#endif