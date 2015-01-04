# Makefile for filepick
# Generated by CMake Version 2.55
#    Build date Jan  4 2015 10:16:12
#    Ryan Koehler, ryan@verdascend.com
# Sun Jan  4 11:05:21 2015
#

TARGET = filepick
CC = gcc
CFLAGS = -Wall -O2 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
SYSLIBS = -lm
OBJS =    dfutil.o   putil.o    sutil.o    sysinfo.o  util.o      \
          wordlist.o filepick.o 

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) ${SYSLIBS}

dfutil.o: dfutil.c   prim.h     

putil.o:  putil.c    prim.h     

sutil.o:  sutil.c    prim.h     

sysinfo.o: sysinfo.c  prim.h     

util.o:   util.c     prim.h     

wordlist.o: wordlist.c prim.h     wordlist.h 

filepick.o: filepick.c prim.h     wordlist.h filepick.h 
