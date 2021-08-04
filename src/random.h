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

double *uniform_probability_samples(int nsamples);
double *uniform_rv_samples(double xmin, double xmax, int nsamples);
double *exponential_rv_samples(double lambda, int nsamples);
double *weibull_rv_samples(double alpha, double beta, int nsamples);
double *normal_rv_samples(double mu, double sigma, int nsamples);
double *lognormal_rv_samples(double mu, double sigma, int nsamples);

#endif