#include <math.h> 
#include "misc.h"



double erfinv(double x)
{
    double tt1, tt2, lnx, sgn;
    double PI=3.14159;
    sgn = (x < 0) ? -1.0f : 1.0f;
 
    x = (1 - x)*(1 + x);        // x = 1 - x*x;
    lnx = log(x);
 
    tt1 = 2/(PI*0.147) + 0.5f * lnx;
    tt2 = 1/(0.147) * lnx;
 
    return(sgn*sqrt(-tt1 + sqrt(tt1*tt1 - tt2)));
}

double erfcinv(double x)
{
    return erfinv(1.0 - x);
}