/*
powerlevel -- read from stdin stereo audio, output to stdout power levels based on # of samples
*/

#include "peak-filter.h"

bool DEBUG_FLAG = false;
bool NORM_FLAG = false;
bool JSON_FLAG = false;
__int16_t norm_val = 100;

/* Default audio values */
int samples_per_window = default_samples_per_window; /*How mandy samples to calculate the power level*/

int main(int argc, char *argv[]) {
    parse_options(argc, argv);
    report_options();

    const int max_val = 32768;
    __int16_t stereo_sample[2];

    float mult_factor = 1;
    ( NORM_FLAG ? mult_factor = (float) norm_val /  (float) max_val : 0 ) ;

    printd("multiplication factor is %f\n", mult_factor);
    
    // Let's open STDIN and loop

    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
    
    int i = 0;
    int ch0 = 0; int ch1 = 0;
    while ( fread(stereo_sample, 2, 2, stdin) ) {
        if ( i++ < samples_per_window ) {
            (ch0 < abs(stereo_sample[0]) ? ch0 = abs(stereo_sample[0]) : 0);
            (ch1 < abs(stereo_sample[1]) ? ch1 = abs(stereo_sample[1]) : 0);
        } else {
            ( JSON_FLAG ? 
            printf("{\"c1\":%i, \"c2\":%i}\n", (int) ( ch0 * mult_factor ), (int) ( ch1 * mult_factor ) ) :
            printf("%i %i\n", (int) ( ch0 * mult_factor ), (int) ( ch1 * mult_factor ) )
            ) ;
            // printf("%i %i\n", ch0 , ch1  );
            i = 0; ch0 = 0; ch1 = 0;
        }
    }
    printd("File input closed\n");
}
