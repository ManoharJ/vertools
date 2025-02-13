# Makefile for pick_seq
# Generated by CMakeC Version 2.56
#    Build date Jan 29 2019 21:15:08
#    Ryan Koehler, ryan@verdascend.com
# Mon Sep 16 21:05:29 2019
#

TARGET = pick_seq
CC = gcc
CFLAGS = -Wall -O2 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
SYSLIBS = -lm
OBJS =    autil.o    dfutil.o   mutil.o    putil.o    sutil.o     \
          sysinfo.o  util.o     dna.o      dna_in.o   dna_out.o   \
          dna_char.o snp_char.o dna_file.o dna_seqs.o dna_snp.o   \
          dna_pp.o   dna_pair.o dna_loop.o score.o    numlist.o   \
          pick_seq.o 

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

dna_in.o: dna_in.c   prim.h     dna.h      

dna_out.o: dna_out.c  prim.h     dna.h      

dna_char.o: dna_char.c prim.h     dna.h      

snp_char.o: snp_char.c prim.h     dna.h      

dna_file.o: dna_file.c prim.h     dna.h      

dna_seqs.o: dna_seqs.c prim.h     dna.h      

dna_snp.o: dna_snp.c  prim.h     dna.h      

dna_pp.o: dna_pp.c   prim.h     dna.h      dna_pair.h 

dna_pair.o: dna_pair.c prim.h     dna.h      dna_pair.h 

dna_loop.o: dna_loop.c prim.h     dna.h      dna_pair.h 

score.o:  score.c    prim.h     score.h    

numlist.o: numlist.c  prim.h     numlist.h  

pick_seq.o: pick_seq.c prim.h     dna.h      dna_pair.h score.h     \
          pick_seq.h 
