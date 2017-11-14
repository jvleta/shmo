#include <stdlib.h>
#include "distributions.h"
#include "random.h"


vector *uniform_probability_samples(int nsamples)
{
    vector *x = zeros(nsamples);

    for (int index = 0; index < nsamples; index++)
    {
        x->elements[index] = ((double)rand() / (double)RAND_MAX);
    }

    return x;
}

vector *uniform_rv_samples(double xmin, double xmax, int nsamples)
{
    vector *p = uniform_probability_samples(nsamples);
    vector *x = zeros(nsamples);

    for (int index = 0; index < nsamples; index++)
    {
        x->elements[index] = xmin + p->elements[index] * (xmax - xmin);
    }

    return x;
}

vector *exponential_rv_samples(double lambda, int nsamples)
{
    vector *p = uniform_probability_samples(nsamples);
    vector *x = zeros(nsamples);

    for (int index = 0; index < nsamples; index++)
    {
        x->elements[index] = exponential_cdf_inverse(lambda, p->elements[index]); 
    }

    return x;
}

vector *weibull_rv_samples(double alpha, double beta, int nsamples)
{
    vector *p = uniform_probability_samples(nsamples);
    vector *x = zeros(nsamples);

    for (int index = 0; index < nsamples; index++)
    {
        x->elements[index] = weibull_cdf_inverse(alpha, beta, p->elements[index]); 
    }

    return x;
}

vector *normal_rv_samples(double mu, double sigma, int nsamples)
{
    vector *p = uniform_probability_samples(nsamples);
    vector *x = zeros(nsamples);

    for (int index = 0; index < nsamples; index++)
    {
        x->elements[index] = normal_cdf_inverse(mu, sigma, p->elements[index]); 
    }

    return x;
}

vector *lognormal_rv_samples(double mu, double sigma, int nsamples)
{
    vector *p = uniform_probability_samples(nsamples);
    vector *x = zeros(nsamples);

    for (int index = 0; index < nsamples; index++)
    {
        x->elements[index] = lognormal_cdf_inverse(mu, sigma, p->elements[index]); 
    }

    return x;
}