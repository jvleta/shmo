#ifndef ARRAYS_H_
#define ARRAYS_H_

#define length(x)  (sizeof(x) / sizeof((x)[0]))

typedef struct vector
{
    double *elements;
    int length;
} vector;

typedef struct matrix
{
    double **elements;
    double *elements_data;
    int nrows;
    int ncols;
} matrix;

matrix *init_matrix(int nrows, int ncols);
matrix *zeros_matrix(int nrows, int ncols);
matrix *transpose(const matrix *x);
matrix *multiply_matrices(const matrix *a, const matrix *b);
void print_matrix(const matrix *x);
double *zeros(int nvalues);
double *ones(int nvalues);
double *copy(const double *x);
double *linspace(double min,double max, int nvalues);

void savetxt(char *filename, double *data);
#endif