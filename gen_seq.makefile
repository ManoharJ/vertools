# Makefile for gen_seq
# Generated by CMake Version 2.54
#    Build date Nov 26 2014 16:56:39
#    Ryan Koehler, ryan@verdascend.com
# Fri Nov 28 13:12:09 2014
#

TARGET = gen_seq
CC = gcc
CFLAGS = -Wall -O2 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
SYSLIBS = -lm
OBJS =    util.o     autil.o    dfutil.o   mutil.o    putil.o     \
          sutil.o    sysinfo.o  dna.o      dna_char.o dna_cons.o  \
          dna_file.o dna_in.o   dna_out.o  dna_seqs.o dna_snp.o   \
          score.o    snp_char.o gen_seq.o  

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) ${SYSLIBS}

util.o:   util.c     prim.h     

autil.o:  autil.c    prim.h     

dfutil.o: dfutil.c   prim.h     

mutil.o:  mutil.c    prim.h     

putil.o:  putil.c    prim.h     

sutil.o:  sutil.c    prim.h     

sysinfo.o: sysinfo.c  prim.h     

dna.o:    dna.c      prim.h     dna.h      

dna_char.o: dna_char.c prim.h     dna.h      

dna_cons.o: dna_cons.c prim.h     dna.h      tm_pars.h  dna_cons.h 

dna_file.o: dna_file.c prim.h     dna.h      

dna_in.o: dna_in.c   prim.h     dna.h      

dna_out.o: dna_out.c  prim.h     dna.h      

dna_seqs.o: dna_seqs.c prim.h     dna.h      

dna_snp.o: dna_snp.c  prim.h     dna.h      

score.o:  score.c    prim.h     score.h    

snp_char.o: snp_char.c prim.h     dna.h      

gen_seq.o: gen_seq.c  prim.h     dna.h      dna_cons.h gen_seq.h  
