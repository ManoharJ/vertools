# Makefile for num
# Generated by CMake Version 2.55
#    Build date Jan 19 2016 08:44:23
#    Ryan Koehler, ryan@verdascend.com
# Mon Jan 25 07:21:19 2016
#

TARGET = num
CC = gcc
CFLAGS = -Wall -O2 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
SYSLIBS = -lm
OBJS =    autil.o    dfutil.o   mutil.o    putil.o    sutil.o     \
          sysinfo.o  util.o     num.o      

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) ${SYSLIBS}

autil.o:  autil.c    prim.h     

dfutil.o: dfutil.c   prim.h     

mutil.o:  mutil.c    prim.h     

putil.o:  putil.c    prim.h     

sutil.o:  sutil.c    prim.h     

sysinfo.o: sysinfo.c  prim.h     

util.o:   util.c     prim.h     

num.o:    num.c      prim.h     
