# powerlevel
C program -- read 16-bit stereo PCM from STDIN, output peak levels.

- This is not checking for endian -- assumes little-endian data (WAV standard), and that you're on a little-endian machine (Intel or ARM, for instance).
- This program will exit when STDIN closes.
