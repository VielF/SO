# makefile for scheduling program
#
# make rr - for round-robin scheduling
# make priority_rr - for priority with round robin scheduling

CC=gcc
CFLAGS=-Wall -fsanitize=address
LDFLAGS=-lc -lm -lasan

.PHONY: all clean

all: rr priority_rr fcfs

rr: driver.o list.o CPU.o schedule_rr.o loadfile.h
	$(CC) $(CFLAGS) -o rr driver.o schedule_rr.o list.o CPU.o $(LDFLAGS)

priority_rr: driver.o list.o CPU.o schedule_rr_p.o loadfile.h
	$(CC) $(CFLAGS) -o priority_rr driver.o schedule_rr_p.o list.o CPU.o $(LDFLAGS)

fcfs: driver.o list.o CPU.o schedule_fcfs.o loadfile.h
	$(CC) $(CFLAGS) -o fcfs driver.o schedule_fcfs.o list.o CPU.o $(LDFLAGS)

driver.o: driver.c schedule.h
	$(CC) $(CFLAGS) -c driver.c

schedule_rr.o: schedule_rr.c schedule.h
	$(CC) $(CFLAGS) -c schedule_rr.c

schedule_rr_p.o: schedule_rr_p.c schedule.h
	$(CC) $(CFLAGS) -c schedule_rr_p.c

schedule_fcfs.o: schedule_fcfs.c schedule.h
	$(CC) $(CFLAGS) -c schedule_fcfs.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

CPU.o: CPU.c CPU.h
	$(CC) $(CFLAGS) -c CPU.c

clean:
	rm -rf *.o
	rm -rf rr
	rm -rf priority_rr
	rm -rf fcfs
