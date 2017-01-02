/*
* seq_info.h
*
* Copyright 2017 Ryan Koehler, VerdAscend Sciences, ryan@verdascend.com
*
* The programs and source code of the vertools collection are free software.
* They are distributed in the hope that they will be useful,
* WITHOUT ANY WARRANTY OF FITNESS FOR ANY PARTICULAR PURPOSE.  
* 
* Permission is granted for research, educational, and commercial use and 
* modification as long as 1) Code and any derived works are not redistributed
* for any fee, and 2) Proper credit is given to the authors. If you wish to 
* include this software in a product, please contact the authors.
*
*/


/**
*   Word-based info 
*/
#define MAX_WFI     10000   /* Buffer size; .i.e max len */
#define MAX_WSIZE   20      /* Max word size to consider */




/*********************** ppp ********************
* C function listing generated by gen_prot
* Wed Nov 28 08:54:50 2001
*/
/****************************************************************
* seq_info.c
*/
DOUB SeqWordFreqInfoD(char *seqPC,int len,int min,int max);
int Fill123WordCountsI(char *seqS,int len,int *onePI,int *twoPI,int *thrPI);
int Seq123ShannonInfoI(char *seqPC, int len, DOUB *onePD, DOUB *twoPD,
    DOUB *thrPD);
int Seq123ShannonEvenInfoI(char *seqPC, int len, DOUB *onePD, DOUB *twoPD,
    DOUB *thrPD);
int Seq123BrillouinInfoI(char *seqPC, int len, DOUB *onePD, DOUB *twoPD,
    DOUB *thrPD);
int Seq123BergerParkerInfoI(char *seqPC, int len, DOUB *onePD, DOUB *twoPD,
    DOUB *thrPD);
DOUB NormBergerParkerIndexD(int max,int num,int adim);

