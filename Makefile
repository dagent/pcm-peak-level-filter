TARGET = peak-filter
CC = gcc

default: peak-filter_utils.c peak-filter.c peak-filter.h
	$(CC) peak-filter.c peak-filter_utils.c -o $(TARGET)

clean:
	rm *.o $(TARGET)
