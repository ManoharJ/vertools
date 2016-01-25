# Makefile for wordfreq
# Generated by CMake Version 2.55
#    Build date Jan 19 2016 08:44:23
#    Ryan Koehler, ryan@verdascend.com
# Mon Jan 25 07:21:32 2016
#

TARGET = wordfreq
CC = gcc
CFLAGS = -Wall -O2 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
SYSLIBS = -lm
OBJS =    autil.o    dfutil.o   mutil.o    putil.o    sutil.o     \
          sysinfo.o  util.o     numlist.o  wordlist.o dna.o       \
          dna_char.o dna_file.o dna_in.o   dna_out.o  dna_seqs.o  \
          dna_snp.o  snp_char.o table.o    table_io.o table_str.o  \
          table_val.o wfutil.o   wordfreq.o 

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) ${SYSLIBS}

autil.o:  autil.c    prim.h     

dfutil.o: dfutil.c   prim.h     

mutil.o:  mutil.c    prim.h     

putil.o:  putil.c    prim.h     

sutil.o:  sutil.c    prim.h     

sysinfo.o: sysinfo.c  prim.h     

util.o:   util.c     prim.h     

numlist.o: numlist.c  prim.h     numlist.h  

wordlist.o: wordlist.c prim.h     wordlist.h 

dna.o:    dna.c      prim.h     dna.h      

dna_char.o: dna_char.c prim.h     dna.h      

dna_file.o: dna_file.c prim.h     dna.h      

dna_in.o: dna_in.c   prim.h     dna.h      

dna_out.o: dna_out.c  prim.h     dna.h      

dna_seqs.o: dna_seqs.c prim.h     dna.h      

dna_snp.o: dna_snp.c  prim.h     dna.h      

snp_char.o: snp_char.c prim.h     dna.h      

table.o:  table.c    prim.h     table.h    

table_io.o: table_io.c prim.h     table.h    

table_str.o: table_str.c prim.h     table.h    

table_val.o: table_val.c prim.h     table.h    

wfutil.o: wfutil.c   prim.h     score.h    wfutil.h   wordfreq.h 

wordfreq.o: wordfreq.c prim.h     table.h    wfutil.h   wordfreq.h 
