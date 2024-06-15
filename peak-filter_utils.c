/*
powerlevel -- read from stdin 16-bit stereo audio, output to stdout power levels
based on # of samples
*/

#include "peak-filter.h"
#include <bits/getopt_core.h>  /*This shouldn't be needed, but VScode...*/

int usage(char *pname) {
    printf("\n%s [options]\n\n", pname);
    printf("Read 16-bit stereo channel from STDIN; report peak levels on stdout.\n");
    printf("-s #\tSamples per window (default: %i)\n", samples_per_window );
    printf("-n #\tNormalize to max peak to integer #\n" );
    printf("-j \tOutput JSON\n" );
    printf("-d \tEnable debugging") ;
    printf("\n");
}

int parse_options(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc,argv, "hjds:n:")) != -1)
    {
        switch (opt) {
            case 's':
                samples_per_window = atoi(optarg);
                break;
            case 'd':
                DEBUG_FLAG = true;
                break;
            case 'j':
                JSON_FLAG = true;
                break;
            case 'n':
                NORM_FLAG  = true;
                norm_val =  atoi(optarg);
                break;
            default:
                usage(argv[0]);
                exit(EXIT_FAILURE);
        }
    }
}

int report_options(){
    printd("samples per window = %i\n", samples_per_window);
    ( NORM_FLAG ? printd("normalize value = %i\n", norm_val) : 0 );
    ( JSON_FLAG ? printd("Output JSON\n") : 0 );

}