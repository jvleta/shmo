double normal_pdf(double mu, double sigma, double x);
double normal_cdf(double mu, double sigma, double x);
double normal_cdf_inverse(double mu, double sigma, double p);

double lognormal_pdf(double mu, double sigma, double x);
double lognormal_cdf(double mu, double sigma, double x);
double lognormal_cdf_inverse(double mu, double sigma, double p);

double exponential_pdf(double lambda, double x);
double exponential_cdf(double lambda, double x);
double exponential_cdf_inverse(double lambda, double p);

double gumbel_pdf(double alpha, double beta, double x);
double gumbel_cdf(double alpha, double beta, double x);
double gumbel_cdf_inverse(double alpha, double beta, double p);

double weibull_pdf(double alpha, double beta, double x);
double weibull_cdf(double alpha, double beta, double x);
double weibull_cdf_inverse(double alpha, double beta, double p);
