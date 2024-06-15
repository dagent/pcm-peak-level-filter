## Audio Peak Amplitude Meter

This example is for Linux, and uses **arecord** from ALSA, and the **websocketd** program via https://github.com/joewalnes/websocketd.

Run `./mic-peaks.sh` to make sure the script is setup correctly (see the `peakfilter` and `adevice` variables).  Then launch `websocketd.sh` and browse to the appropriate port.  You should see a peak meter that responds to audio.