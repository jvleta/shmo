#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include <math.h>
 
int main(int argc, char* argv[])
{
    int number_of_sims_per_process = 10000000;
    int process_id;                       
    double load,resistance;
    int isim;
    int number_of_fails=0;
    double g;                       
    double failure_probability;     
    int total_number_of_failures;   
    int total_number_of_simulations;
 
    double max_load=30.0;
    double min_load=40.0;
    
    double max_resistance=30.0;
    double min_resistance=40.0;

    MPI_Init(&argc, &argv);         
    MPI_Comm_rank(MPI_COMM_WORLD, &process_id);
 
    if(process_id != 0)
    {   
        for (isim=0; isim<number_of_sims_per_process; ++isim)
        {
            srand48(time(NULL));                
            load = (double)random()/RAND_MAX * (max_load - min_load) + min_load;          
            resistance = (double)random()/RAND_MAX * (max_resistance - min_resistance) + min_resistance;          
            g = resistance - load;
            if (g <= 0)
            {
                ++number_of_fails;                
            }
        }
    }
 
    MPI_Reduce(&number_of_fails,
               &total_number_of_failures,
               1,
               MPI_INT,
               MPI_SUM,
               0,
               MPI_COMM_WORLD);
    
    MPI_Reduce(&number_of_sims_per_process,
               &total_number_of_simulations,
               1,
               MPI_INT,
               MPI_SUM,
               0,
               MPI_COMM_WORLD);
    
    total_number_of_simulations -= number_of_sims_per_process;
    
    if (process_id == 0)                     
    {
        failure_probability = ((double)total_number_of_failures/(double)total_number_of_simulations);
        printf("Pf = %e\n", failure_probability);
    }
 
    MPI_Finalize();
    return 0;
}