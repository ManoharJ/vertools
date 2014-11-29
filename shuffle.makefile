# Makefile for shuffle
# Generated by CMake Version 2.54
#    Build date Nov 26 2014 16:56:39
#    Ryan Koehler, ryan@verdascend.com
# Fri Nov 28 13:12:08 2014
#

TARGET = shuffle
CC = gcc
CFLAGS = -Wall -O2 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
SYSLIBS = -lm
OBJS =    mutil.o    putil.o    sutil.o    sysinfo.o  util.o      \
          shuffle.o  

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) ${SYSLIBS}

mutil.o:  mutil.c    prim.h     

putil.o:  putil.c    prim.h     

sutil.o:  sutil.c    prim.h     

sysinfo.o: sysinfo.c  prim.h     

util.o:   util.c     prim.h     

shuffle.o: shuffle.c  prim.h     
