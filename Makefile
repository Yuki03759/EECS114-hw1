CC = g++
CFLAGS =
COPTFLAGS = -O3 -g
LDFLAGS =

default: insertion-sort mergesort
#	@echo "=================================================="
#	@echo "To build your sorting code, use:"
#	@echo "  make insertion-sort    # For Insertion sort"
#	@echo "  make mergesort    	 # For Mergesort"
#	@echo ""
#	@echo "To clean this subdirectory (remove object files"
#	@echo "and other junk), use:"
#	@echo "  make clean"
#	@echo "=================================================="

# Insertion sort driver 
insertion-sort: driver.o sort.o insertion-sort.o
	$(CC) $(COPTFLAGS) -o $@ $^

# Mergesort driver
mergesort: driver.o sort.o mergesort.o
	$(CC) $(COPTFLAGS) -o $@ $^

%.o: %.cc
	$(CC) $(CFLAGS) $(COPTFLAGS) -o $@ -c $<

clean:
	rm -f core *.o *~ insertion-sort mergesort

# eof
