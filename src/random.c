#include <stdlib.h>
#include "distributions.h"
#include "random.h"


double *uniform_probability_samples(int nsamples)
{
    double *x = zeros(nsamples);

    for (int index = 0; index < nsamples; index++)
    {
        x[index] = ((double)rand() / (double)RAND_MAX);
    }

    return x;
}

double *uniform_rv_samples(double xmin, double xmax, int nsamples)
{
    double *p = uniform_probability_samples(nsamples);
    double *x = zeros(nsamples);

    for (int index = 0; index < nsamples; index++)
    {
        x[index] = xmin + p[index] * (xmax - xmin);
    }

    return x;
}

double *exponential_rv_samples(double lambda, int nsamples)
{
    double *p = uniform_probability_samples(nsamples);
    double *x = zeros(nsamples);

    for (int index = 0; index < nsamples; index++)
    {
        x[index] = exponential_cdf_inverse(lambda, p[index]); 
    }

    return x;
}

double *weibull_rv_samples(double alpha, double beta, int nsamples)
{
    double *p = uniform_probability_samples(nsamples);
    double *x = zeros(nsamples);

    for (int index = 0; index < nsamples; index++)
    {
        x[index] = weibull_cdf_inverse(alpha, beta, p[index]); 
    }

    return x;
}

double *normal_rv_samples(double mu, double sigma, int nsamples)
{
    double *p = uniform_probability_samples(nsamples);
    double *x = zeros(nsamples);

    for (int index = 0; index < nsamples; index++)
    {
        x[index] = normal_cdf_inverse(mu, sigma, p[index]); 
    }

    return x;
}

double *lognormal_rv_samples(double mu, double sigma, int nsamples)
{
    double *p = uniform_probability_samples(nsamples);
    double *x = zeros(nsamples);

    for (int index = 0; index < nsamples; index++)
    {
        x[index] = lognormal_cdf_inverse(mu, sigma, p[index]); 
    }

    return x;
}