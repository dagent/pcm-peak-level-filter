#!/bin/bash

peakfilter="../../peak-filter"

adevice=plughw:1    # ALSA device for input

samplewindow=4096   # How many audio samples for peak-detection

logf=/tmp/mic-peaks.log

date >> $logf

( arecord -D $adevice -t raw -f dat 2>>$logf | $peakfilter -n 100 -s $samplewindow -j ) 2>>$logf

