/*
* histogram.h
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

#ifndef __HISTOGRAMH__
#define __HISTOGRAMH__
#include "numlist.h"


#define HISTOGRAM_ID     6045

typedef struct HISTOGRAM
{
    int ID;
    struct NUMLIST *bins;   /* ember names */
    int n;                  /* umber of bins */
    DOUB bsize;             /* in size */
    DOUB lo,hi,ran;         /* ow, High values and range */
    int nov,nun;            /* umbers under / over */
    struct NUMLIST *vals;   /* alues; Pointer to source only, not owned */
    int val_n;              /* umber of source values */
    DOUB val_hi,val_lo;     /* i and low source values */
    DOUB val_ran;           /* ange of source values */
} HISTOGRAM;

#define CHECK_HISTOGRAM(fp)     if(fp){DestroyHistogramI(fp);fp=NULL;}



/*********************** ppp ********************
* C function listing generated by gen_prot
* Fri Jul 11 09:53:22 2014
*/
/****************************************************************
* histogram.c
*/
HISTOGRAM *CreateHistogramPO(NUMLIST *valsPO);
int DestroyHistogramI(HISTOGRAM *hisPO);
void InitHistogram(HISTOGRAM *hisPO);
void DumpHistogram(HISTOGRAM *hisPO, int bins, FILE *outPF);
int SetHistogramValueSourceI(HISTOGRAM *hisPO, NUMLIST *valsPO);
int SetHistogramParamsI(HISTOGRAM *hisPO, DOUB bsizeD, DOUB loD, DOUB hiD);
int GetHistogramParamsI(HISTOGRAM *hisPO, DOUB *binPD, DOUB *loPD, DOUB *hiPD);
int GetHistogramNumBinsI(HISTOGRAM *hisPO) ;
int SetUpHistogramBinningI(HISTOGRAM *hisPO, int max, int dis);
int TallyHistogramI(HISTOGRAM *hisPO);
int GetHistogramUnOvCountsI(HISTOGRAM *hisPO, int *unPI, int *ovPI);
int HistogramValuesForBinI(HISTOGRAM *hisPO, int bin, int *numPI, DOUB *stPD, 
    DOUB *enPD);
int GetHistogramMaxTwoBinsI(HISTOGRAM *hisPO, int *maxPI, int *smaxPI) ;
int HistogramBinForValueI(HISTOGRAM *hisPO, DOUB vD, int *bPI, DOUB *stPD, DOUB *enPD);
int HistogramAutoFormatStringI(HISTOGRAM *hisPO, char *formS);
int NumlistToHistogramI(NUMLIST *nlPO, DOUB binD, DOUB loD, DOUB hiD, 
    HISTOGRAM **hisPPO);


#endif
