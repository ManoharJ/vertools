# Makefile for ccase
# Generated by CMake Version 2.55
#    Build date Aug 14 2016 05:20:35
#    Ryan Koehler, ryan@verdascend.com
# Mon Jan  2 11:16:19 2017
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
