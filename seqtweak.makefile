# Makefile for seqtweak
# Generated by CMake Version 2.55
#    Build date Aug 14 2016 05:20:35
#    Ryan Koehler, ryan@verdascend.com
# Mon Jan  2 11:16:09 2017
#

TARGET = seqtweak
CC = gcc
CFLAGS = -Wall -O2 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
SYSLIBS = -lm
OBJS =    autil.o    dfutil.o   mutil.o    putil.o    sutil.o     \
          sysinfo.o  util.o     dna.o      dna_char.o dna_file.o  \
          dna_in.o   dna_seqs.o snp_char.o seqtweak.o 

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) ${SYSLIBS}

autil.o:  autil.c    prim.h     

dfutil.o: dfutil.c   prim.h     

mutil.o:  mutil.c    prim.h     

putil.o:  putil.c    prim.h     

sutil.o:  sutil.c    prim.h     

sysinfo.o: sysinfo.c  prim.h     

util.o:   util.c     prim.h     

dna.o:    dna.c      prim.h     dna.h      

dna_char.o: dna_char.c prim.h     dna.h      

dna_file.o: dna_file.c prim.h     dna.h      

dna_in.o: dna_in.c   prim.h     dna.h      

dna_seqs.o: dna_seqs.c prim.h     dna.h      

snp_char.o: snp_char.c prim.h     dna.h      

seqtweak.o: seqtweak.c prim.h     dna.h      seqtweak.h 
