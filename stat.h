/*
* stat.h
*
* Copyright 2019 Ryan Koehler, VerdAscend Sciences, ryan@verdascend.com
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
* See https://www.verdascend.com/ for more
*
*/

#ifndef __STATH__
#define __STATH__
#include "numlist.h"
#include "score.h"


#define PEARSON_TINY    1.0e-20

#define PROBINTSTEPS    10000   /* Number of steps for probibility integral */

#define HIS_NUM_BINS    20      /* Histogram default number of bins */
#define HIS_MAX_BINS    1000    /* Histogram max number of bins */
#define HIS_BTR_XFOLD   2.0     /* Histogram truncation X-fold default */


/*********************** ppp ********************
* C function listing generated by gen_prot
* Sat Jul 12 09:05:50 2014
*/
/****************************************************************
* stat.c
*/
DOUB PearsonsCorD(void *aPO, void *bPO, int n, int ct);
DOUB RankCorD(void *aPO, void *bPO, int n, int ct);
int FillScorecRankArrayI(SCOREC *scPO,int n,DOUB *valsPD);
void FillHisPlotLine(int bval, int ncum, int max, int win, char *bufS);
int ProbabilityIntegralI(DOUB zD, DOUB *pPD) ;
int MakeDiscreteValI(DOUB buckD, DOUB *disPD);
int GetDiscreteBinStartI(DOUB binD, DOUB *binPD, DOUB loD, DOUB *loPD);
int NumlistNaturalHistBinI(NUMLIST *nlPO, int max_bin, int dhis, 
    DOUB *binPD, DOUB *lowPD, DOUB *hiPD);
int NaturalHistBinI(DOUB *valsPD, int num, int max, int dhis,
    DOUB *lowPD, DOUB *binPD);
int NumlistDifStatsI(NUMLIST *nlPO, DOUB *minPD, DOUB *maxPD, DOUB *avPD);
int NumlistPairCorI(NUMLIST *flPO, NUMLIST *slPO, int rank, DOUB *rPD);


#endif
