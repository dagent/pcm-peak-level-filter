/*
powerlevel -- read from stdin stereo audio, output to stdout power levels based on # of samples
*/

#include "peak-filter.h"

bool DEBUG_FLAG = false;
bool PEAKS_FLAG = false;
bool NORM_FLAG = false;
__int16_t norm_val = 100;

/* Default audio values */
int samples_per_window = default_samples_per_window; /*How mandy samples to calculate the power level*/


int main(int argc, char *argv[]) {
    parse_options(argc, argv);
    report_options();

    __int16_t stereo_sample[2];
    
    // Let's open STDIN and loop
    
    const int max_val = 32768;
    int i = 0;
    int ch0 = 0; int ch1 = 0;
    while ( fread(stereo_sample, 2, 2, stdin) ) {
        if ( i++ < samples_per_window ) {
            (ch0 < abs(stereo_sample[0]) ? ch0 = abs(stereo_sample[0]) : 0);
            (ch1 < abs(stereo_sample[1]) ? ch1 = abs(stereo_sample[1]) : 0);

        } else {
            printf("%i %i\n", ch0, ch1);
            i = 0; ch0 = 0; ch1 = 0;
        }
    }
    printd("File input closed");

}
