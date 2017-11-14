#/bin/bash

mpicc arrays.c misc.c distributions.c random.c mcs.c -o rec -lm -g -std=c99 -fopenmp
#gcc arrays.c misc.c distributions.c random.c differentiation.c mcs_example.c -o mcs -lm -g
#gcc main.c -o main