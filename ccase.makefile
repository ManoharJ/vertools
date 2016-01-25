# Makefile for ccase
# Generated by CMake Version 2.55
#    Build date Jan 19 2016 08:44:23
#    Ryan Koehler, ryan@verdascend.com
# Mon Jan 25 07:21:46 2016
#

TARGET = ccase
CC = gcc
CFLAGS = -Wall -O2 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
SYSLIBS = -lm
OBJS =    putil.o    sutil.o    sysinfo.o  util.o     ccase.o    

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) ${SYSLIBS}

putil.o:  putil.c    prim.h     

sutil.o:  sutil.c    prim.h     

sysinfo.o: sysinfo.c  prim.h     

util.o:   util.c     prim.h     

ccase.o:  ccase.c    prim.h     
