# Makefile for plotmat
# Generated by CMake Version 2.55
#    Build date Aug 14 2016 05:20:35
#    Ryan Koehler, ryan@verdascend.com
# Mon Jan  2 11:15:56 2017
#

TARGET = plotmat
CC = gcc
CFLAGS = -Wall -O2 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
SYSLIBS = -lm -lgd -lpng -lz -ljpeg
OBJS =    autil.o    dfutil.o   mutil.o    putil.o    sutil.o     \
          sysinfo.o  util.o     numlist.o  wordlist.o score.o     \
          color.o    plot_lib.o plot_spec.o table.o    table_io.o  \
          table_ops.o table_stat.o table_str.o table_val.o plotmat.o  

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

score.o:  score.c    prim.h     score.h    

color.o:  color.c    prim.h     color.h    

plot_lib.o: plot_lib.c prim.h     color.h    plot_lib.h 

plot_spec.o: plot_spec.c prim.h     color.h    plot_lib.h 

table.o:  table.c    prim.h     table.h    

table_io.o: table_io.c prim.h     table.h    

table_ops.o: table_ops.c prim.h     table.h    score.h    

table_stat.o: table_stat.c prim.h     table.h    

table_str.o: table_str.c prim.h     table.h    

table_val.o: table_val.c prim.h     table.h    

plotmat.o: plotmat.c  prim.h     numlist.h  wordlist.h table.h     \
          color.h    plot_lib.h plotmat.h  
