
#ifndef POWERLEVEL_H
#define POWERLEVEL_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

extern bool DEBUG_FLAG;
#define printd(...) ( DEBUG_FLAG ? fprintf(stderr, __VA_ARGS__) : 0 )

extern bool NORM_FLAG; /* Print renormalized */
extern bool JSON_FLAG; /* Print JSON */
extern __int16_t norm_val;

/* Default audio values */
#define default_samples_per_window 2048; /*How mandy samples to calculate the power level*/
extern int samples_per_window ; 
extern int report_options();

/* utility functions */
int usage(char *pname) ;
int parse_options(int argc, char *argv[]) ;

#endif /* POWERLEVEL_H */

