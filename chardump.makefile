# Makefile for chardump
# Generated by CMake Version 2.54
#    Build date Nov 26 2014 16:56:39
#    Ryan Koehler, ryan@verdascend.com
# Fri Nov 28 13:12:02 2014
#

TARGET = chardump
CC = gcc
CFLAGS = -Wall -O2 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
SYSLIBS = -lm
OBJS =    putil.o    sutil.o    sysinfo.o  util.o     chardump.o 

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) ${SYSLIBS}

putil.o:  putil.c    prim.h     

sutil.o:  sutil.c    prim.h     

sysinfo.o: sysinfo.c  prim.h     

util.o:   util.c     prim.h     

chardump.o: chardump.c prim.h     
