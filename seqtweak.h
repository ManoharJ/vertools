/*
* seqtweak.h
*
* Copyright 2018 Ryan Koehler, VerdAscend Sciences, ryan@verdascend.com
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


#define VERSION_S "SeqTweak Version 0.8"


#define MAX_TWEAKSEQ    200     /* Max seq len; buffer size */
#define MAX_IDSIZE      5       /* Max InDel size */
#define MAX_TWK_TRYS    10000
#define MAX_TWK_STARTS  1000

#define MASK_NO         'n'
#define MASK_YES        '.'
#define MASK_MISMATCH   'M'
#define MASK_INSERT     'I'
#define MASK_DELETE     'D'

#define SEQTWEAK_ID     5141 
typedef struct SEQTWEAK
{
    int ID;
    FILE *in;               /* Input file */
    char inname[NSIZE];     /* Input filename */
    int iform;              /* Input file format */
    FILE *out;              /* Output file */
    char outname[NSIZE];    /* Output filename */
    struct SEQ *seq;        /* Sequence object */
    int seqlen;             /* Run-time seq length */
    char seqname[NSIZE];    /* Run-time seq name */
    char *seqseq;           /* Run-time pointer to sequence string */
    int firstb,lastb;       /* First / last base (as specified) */
    int do_rre;             /* Flag for range releative to end (backwards) */
    int mis;                /* Number of missmatches */
    int ins;                /* Number of inserts */
    int del;                /* Number of deletions */
    int ids;                /* In/Del word size */
    int mds;                /* Minimum disruption separation */
    int tmod;               /* Total base change (mod) count */
    char bname[NSIZE];      /* Base name for tweaked guys */
    int do_amb;             /* Flag for All Missmatch Bases */
    int do_cpm;             /* Flag for close-packed missmatches */
    int do_sh;              /* Flag for shuffle and full shuffle */
    int do_tlc;             /* Flag to tweak lower case only */
    int seed;               /* Random number seed */
    int do_nre;             /* Flag for naming relative to 3' end */
    int do_iuc, do_ilc;     /* Flag to ignore Upper / lower case */
    int do_muc, do_mlc;     /* Flag to mark tweaks with Upper / lower case */
    int do_dmask;           /* Flag to dump masking */
    int num;                /* Number of different tweaks to output per in */
    int seq_n, tweak_n;     /* Run-time counts of sequence, tweak number */
    int sti,eni;            /* Run-time sequence tweak start, end index */
    int ntpos;              /* Run-time number tweakable positions */
    char mask[MAX_TWEAKSEQ];    /* Run-time mask for changes */
    char tseq1[MAX_TWEAKSEQ];   /* New tweaked sequence */
    char tseq2[MAX_TWEAKSEQ];   /* New tweaked sequence, 2 */
    char tseq3[MAX_TWEAKSEQ];   /* New tweaked sequence, 3 */
    char mbase[MAX_TWEAKSEQ];   /* Run-time modified base (for change case) */
}SEQTWEAK;

#define CHECK_SEQTWEAK(ob) if(ob){DestroySeqtweakI(ob); ob=NULL;}
    

/*********************** ppp ********************
* C function listing generated by gen_prot
* Mon Jan 28 18:09:51 2019
*/
/****************************************************************
* seqtweak.c
*/
int main(int argc, char **argv);
void SeqTweakUse(void);
int SeqTweakI(int argc,char **argv);
SEQTWEAK *CreateSeqtweakPO(void);
int DestroySeqtweakI(SEQTWEAK *stPO);
void InitSeqtweak(SEQTWEAK *stPO);
int OkSeqTweakOptsI(SEQTWEAK *stPO);
int SetUpSeqtweakI(SEQTWEAK *stPO);
void WriteSeqtweakHeader(SEQTWEAK *stPO,FILE *outPF);
int UpdateSeqVarsI(SEQTWEAK *stPO);
int TweakableSeqI(SEQTWEAK *stPO);
int TweakShuffleSeqI(SEQTWEAK *stPO, int verb, FILE *outPF);
int TweakSeqBasesI(SEQTWEAK *stPO, int verb, FILE *outPF);
void ReportOldMaskOuts(SEQTWEAK *stPO, char *nnameS, FILE *outPF);
void ChangeDisMaskSeqCase(SEQTWEAK *stPO) ;
void FillDisruptString(SEQTWEAK *stPO, char *twkS) ;
int InitTweakSeqMaskI(SEQTWEAK *stPO);
int FillTweakMaskI(SEQTWEAK *stPO);
int FillTweakInDelMaskI(SEQTWEAK *stPO);
int FillTweakMissShotgunMaskI(SEQTWEAK *stPO);
int FillTweakMissClosePackMaskI(SEQTWEAK *stPO);
void MaskDisruption(SEQTWEAK *stPO, int pos, int size);
int ClosestDisruption(SEQTWEAK *stPO, int pos, int size);
void SetTweakedName(SEQTWEAK *stPO, char *newS);
void SetTweakedSimName(SEQTWEAK *stPO, char *newS);

