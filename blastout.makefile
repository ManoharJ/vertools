# Makefile for blastout
# Generated by CMakeC Version 2.56
#    Build date Jan 29 2019 21:15:08
#    Ryan Koehler, ryan@verdascend.com
# Mon Sep 16 21:06:48 2019
#

TARGET = blastout
CC = gcc
CFLAGS = -Wall -O2 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
SYSLIBS = -lm
OBJS =    autil.o    dfutil.o   mutil.o    putil.o    sutil.o     \
          sysinfo.o  util.o     blast_io.o blasthit.o blaststr.o  \
          blastout.o 

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) ${SYSLIBS}

autil.o:  autil.c    prim.h     

dfutil.o: dfutil.c   prim.h     

mutil.o:  mutil.c    prim.h     

putil.o:  putil.c    prim.h     

sutil.o:  sutil.c    prim.h     

sysinfo.o: sysinfo.c  prim.h     

util.o:   util.c     prim.h     

blast_io.o: blast_io.c prim.h     blastout.h 

blasthit.o: blasthit.c prim.h     blastout.h 

blaststr.o: blaststr.c prim.h     blastout.h 

blastout.o: blastout.c prim.h     blastout.h 
