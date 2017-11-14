#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mpi.h"
#include "random.h"

 
int main(int argc, char* argv[])
{
    int number_of_sims_per_process = 1000000;
    int process_id;                       
    double load,resistance;
    int isim;
    int number_of_fails=0;
    double g;                       
    double failure_probability;     
    int total_number_of_failures;   
    int total_number_of_simulations;
 
    double mean_load = 30.0;
    double sigma_load = 3.0;
    
    double mean_resistance = 30.0;
    double sigma_resistance = 3.0;

    MPI_Init(&argc, &argv);         
    MPI_Comm_rank(MPI_COMM_WORLD, &process_id);
    
    struct vector *load_samples;
    struct vector *resistance_samples;

    if(process_id != 0)
    {
        load_samples       = normal_rv_samples(mean_load, sigma_load, number_of_sims_per_process);
        resistance_samples = normal_rv_samples(mean_resistance, sigma_resistance, number_of_sims_per_process);

        for (isim=0; isim<number_of_sims_per_process; isim++)
        {
            load       = load_samples->elements[isim];          
            resistance = resistance_samples->elements[isim];           
            g          = resistance - load;
            
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