# Makefile for bpaste
# Generated by CMake Version 2.55
#    Build date Jan  4 2015 10:16:12
#    Ryan Koehler, ryan@verdascend.com
# Sun Jan  4 11:05:15 2015
#

TARGET = bpaste
CC = gcc
CFLAGS = -Wall -O2 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
SYSLIBS = -lm
OBJS =    dfutil.o   putil.o    sutil.o    sysinfo.o  util.o      \
          bpaste.o   

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) ${SYSLIBS}

dfutil.o: dfutil.c   prim.h     

putil.o:  putil.c    prim.h     

sutil.o:  sutil.c    prim.h     

sysinfo.o: sysinfo.c  prim.h     

util.o:   util.c     prim.h     

bpaste.o: bpaste.c   prim.h     
