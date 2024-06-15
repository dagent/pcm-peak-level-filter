# PCM peak-level filter
A quick C program -- read 16-bit stereo PCM from STDIN, output peak levels.  JSON output available.

- This **is not** checking for endian-ness -- assumes little-endian data (WAV standard), and that you're on a little-endian machine (Intel or ARM, for instance).
- This program will exit when STDIN closes.
- An example application, using [websocketd](https://github.com/joewalnes/websocketd) my own [LED-Audio-Meter](https://github.com/dagent/LED-Audio-Meter) is available.

