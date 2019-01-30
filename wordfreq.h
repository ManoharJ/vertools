/*
* wordfreq.h
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


#include "dna.h"

#define VERSION_S   "WordFreq, version 1.0"

#define WFU_NLEN        255

#define WF_UTIL_ID      5171
typedef struct WF_UTIL
{
    int ID;
    FILE *in;               /* Input file */
    char inname[WFU_NLEN];  /* Input filename */
    int iform;              /* Input file format */
    FILE *out;              /* Output file */
    char outname[WFU_NLEN]; /* Output filename */
    int owhat;              /* Output what? */
    int igprob;             /* Flag to ignore problems and continue on */
    struct SEQ *fseq;       /* Full sequence */
    struct SEQ *seq;        /* Sequence object */
    int n;                  /* Count of seqs processed */
    int firsts,lasts;       /* First / last sequence */
    int firstb,lastb;       /* First / last base */
    char lisname[WFU_NLEN]; /* Pre-cooked list name; e.g. for scoring */
    int do_ssc;             /* Flag to report for standard score count (series) */
    int do_ssp;             /* Flag to report for standard score percentile (series) */
    char sprl[BBUFF_SIZE];  /* Score percentile series string */
    char scnl[BBUFF_SIZE];  /* Score count series string */
    struct WORDFREQ *wf;    /* Word frequence object */
    int size;               /* Word size */
    int tw;                 /* Total words */
    int step;               /* Step between samples */
    int min,max;            /* Min max counts to report */
    int do_rre;             /* Range relative to the end */
    int do_not;             /* Invert flagging */
    int do_deg;             /* Flag to collapse degen records */
    int do_norm;            /* Flag to normalize counts */
    int do_ilc;             /* Flag to ignore lower case */
    int do_iuc;             /* Flag to ignore upper case */
    int do_ds;              /* Flag to dump sequences (if scoring) */
    int pmat_s;             /* Staring base for Position-specific matrix */
    int pmat_e;             /* Ending base for Position-specific matrix */
    int pmat_r;             /* Position-specific matrix rows */
    int pmat_c;             /* Position-specific matrix cols */
    struct TABLE *pmat;     /* Position-specific matrix */
}WF_UTIL;

#define CHECK_WF_UTIL(tu)   if(tu){DestroyWf_utilI(tu); tu=NULL;}

#define MAX_PSM_SIZE    4   /* Max word-size for postition specific matrix */

#define SSC_LIST_S  "1,2,3,5,10,20"         /* Standard score counts */
#define SSP_LIST_S  "100,98,95,90,80,50"    /* Standard score percentiles */


/*********************** ppp ********************
* C function listing generated by gen_prot
* Tue Jan 29 13:55:34 2019
*/
/****************************************************************
* wordfreq.c
*/
int main(int argc, char **argv);
void WfUtilUse(void);
int WfUtilI(int argc, char **argv);
WF_UTIL *CreateWf_utilPO(void);
int DestroyWf_utilI(WF_UTIL *wfPO);
void InitWf_util(WF_UTIL *wfPO);
int CheckWfuOptionsI(WF_UTIL *wfPO);
int OpenWfuFilesI(WF_UTIL *wfPO);
int SetUpWfuAuxDataI(WF_UTIL *wfPO);
int SetPosMatLablesI(WF_UTIL *wfPO);
int HandleWfuSubseqI(WF_UTIL *wfPO, SEQ *seqPO, SEQ *fseqPO);
int HandleWfuCaseMaskI(WF_UTIL *wfPO, SEQ *seqPO);
int IsCurrentSeqOkI(WF_UTIL *wfPO, SEQ *seqPO, int n);
void HandleWfuStats(WF_UTIL *wfPO,FILE *outPF);
int HandleWfuSeqOutputI(WF_UTIL *wfPO, SEQ *seqPO, SEQ *fseqPO, FILE *outPF);
int DumpListedNumlistValsI(NUMLIST *valsPO, char *lisS, int do_per, FILE *outPF);
int CollectWfuSeqValsI(WF_UTIL *wfPO, SEQ *seqPO, NUMLIST *valsPO);
void HandleWfuPosMat(WF_UTIL *wfPO, FILE *outPF);
int HandleWfTallyI(WF_UTIL *wfPO, SEQ *seqPO);
int TallyPosMatWordsI(WF_UTIL *wfPO, SEQ *seqPO);
void SummaryHeader(WF_UTIL *wfPO, FILE *outPF);

