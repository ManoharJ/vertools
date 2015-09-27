# Makefile for dna_util
# Generated by CMake Version 2.55
#    Build date Jan 22 2015 16:59:53
#    Ryan Koehler, ryan@verdascend.com
# Sat Sep 26 12:25:55 2015
#

TARGET = dna_util
CC = gcc
CFLAGS = -Wall -O2 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
SYSLIBS = -lm
OBJS =    autil.o    dfutil.o   mutil.o    putil.o    sutil.o     \
          sysinfo.o  util.o     wordlist.o divinds.o  dna.o       \
          dna_char.o dna_comp.o dna_prob.o dna_file.o dna_in.o    \
          dna_out.o  dna_seqs.o dna_snp.o  dna_splc.o seq_info.o  \
          snp_char.o dna_util.o 

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) ${SYSLIBS}

autil.o:  autil.c    prim.h     

dfutil.o: dfutil.c   prim.h     

mutil.o:  mutil.c    prim.h     

putil.o:  putil.c    prim.h     

sutil.o:  sutil.c    prim.h     

sysinfo.o: sysinfo.c  prim.h     

util.o:   util.c     prim.h     

wordlist.o: wordlist.c prim.h     wordlist.h 

divinds.o: divinds.c  prim.h     divinds.h  

dna.o:    dna.c      prim.h     dna.h      

dna_char.o: dna_char.c prim.h     dna.h      

dna_comp.o: dna_comp.c prim.h     dna.h      

dna_prob.o: dna_prob.c prim.h     dna.h      seq_info.h dna_util.h 

dna_file.o: dna_file.c prim.h     dna.h      

dna_in.o: dna_in.c   prim.h     dna.h      

dna_out.o: dna_out.c  prim.h     dna.h      

dna_seqs.o: dna_seqs.c prim.h     dna.h      

dna_snp.o: dna_snp.c  prim.h     dna.h      

dna_splc.o: dna_splc.c prim.h     dna.h      

seq_info.o: seq_info.c prim.h     divinds.h  seq_info.h 

snp_char.o: snp_char.c prim.h     dna.h      

dna_util.o: dna_util.c prim.h     dna.h      seq_info.h wordlist.h  \
          dna_util.h 
