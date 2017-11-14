#include <stdio.h>
#include <stdlib.h> 
#include "arrays.h"


vector *init_vector(int nvalues)
{
    vector *x = malloc(sizeof(vector));
    x->elements = malloc(sizeof(double) * nvalues);
    x->length = nvalues;
    return x;
}

matrix *init_matrix(int nrows, int ncols) 
{
    matrix *x = malloc(sizeof(matrix));
    x->elements = malloc(nrows * sizeof(double*));
    x->elements_data = malloc(nrows * ncols * sizeof(double*));
    x->nrows = nrows;
    x->ncols = ncols;

    for (int i = 0; i < nrows; i++)
    {
        x->elements[i] = x->elements_data + i * ncols;
    }

    return x;    
}

matrix *zeros_matrix(int nrows, int ncols)
{
    matrix *x = init_matrix(nrows, ncols);
    
    for (int m = 0; m < nrows; m++)
    {
        for (int n = 0; n < ncols; n++)
        {
            x->elements[m][n] = 0.0;
        }
    }

    return x;

}

matrix *transpose(const matrix *x)
{
    matrix *x_tranpose = zeros_matrix(x->ncols, x->nrows);

    for (int m = 0; m < x_tranpose->nrows; m++)
    {
        for (int n = 0; n < x_tranpose->ncols; n++)
        {
            x_tranpose->elements[m][n] = x->elements[n][m];
        }
    }
    return x_tranpose;
}

void print_matrix(const matrix *x)
{
    for (int m = 0; m < x->nrows; m++)
    {
        for (int n = 0; n < x->ncols; n++)
        {
            printf("%3.2f ",x->elements[m][n]);
        }
        printf("\n");
    }    
    printf("\n");
}

vector *copy(const vector *x)
{
    vector *y = zeros(x->length);
    for (int ix = 0; ix < x->length; ix++)
    {
        y->elements[ix] = x->elements[ix];
    }
    return y;
}

vector *zeros(int nvalues)
{
    vector *x = init_vector(nvalues);
    for (int index = 0; index < x->length; index++)
    {
        x->elements[index] = 0.0;
    }
    return x;
}

vector *ones(int nvalues)
{
    vector *x = init_vector(nvalues);
    for (int index = 0; index < x->length; index++)
    {
        x->elements[index] = 1.0;
    }
    return x;
}

vector *linspace(double min, double max, int nvalues)
{
    vector *x = init_vector(nvalues);
    for (int index = 0; index < x->length; index++)
    {

        x->elements[index] = min + (max - min) / (double)(nvalues - 1.0) * (double)(index);
    }
    return x;
}

void savetxt(char *filename, vector *data)
{
    FILE *f = fopen(filename, "w");
    //if (f == NULL)
    //{
    //    printf("Error opening file!\n");
    //    exit(1);
    //}

    
    for (int i = 0; i < data->length; i++)
    {
        fprintf(f, "%f\n", data->elements[i]);
    }
}