# Makefile for wfmerge
# Generated by CMakeC Version 2.56
#    Build date Jan 29 2019 20:50:55
#    Ryan Koehler, ryan@verdascend.com
# Tue Jan 29 21:15:15 2019
#

TARGET = wfmerge
CC = gcc
CFLAGS = -Wall -O2 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
SYSLIBS = -lm
OBJS =    autil.o    dfutil.o   mutil.o    putil.o    sutil.o     \
          sysinfo.o  util.o     wfutil.o   wfmerge.o  

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) ${SYSLIBS}

autil.o:  autil.c    prim.h     

dfutil.o: dfutil.c   prim.h     

mutil.o:  mutil.c    prim.h     

putil.o:  putil.c    prim.h     

sutil.o:  sutil.c    prim.h     

sysinfo.o: sysinfo.c  prim.h     

util.o:   util.c     prim.h     

wfutil.o: wfutil.c   prim.h     score.h    wfutil.h   wordfreq.h 

wfmerge.o: wfmerge.c  prim.h     dna.h      wfutil.h   wfmerge.h  
