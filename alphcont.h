/*
* alphcont.h
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

#define VERSION_S "AlphCont Version 0.96"

#define ALPH_BLEN       2500

#define ALPHCONT_ID     5021
typedef struct ALPHCONT
{
    int ID;
    FILE *in;               /* Input file */
    char inname[NSIZE];     /* Input filename */
    int iform;              /* Input file format */
    int iclean;             /* Input file cleaning level */
    FILE *out;              /* Output file */
    char outname[NSIZE];    /* Output filename */
    int owhat;              /* Output what? */
    int do_stat;            /* Flag to dump only stats */
    int igprob;             /* Flag to ignore problems and continue on */
    int quiet;              /* Flag for no header */
    struct SEQ *seq;        /* Sequence object */
    struct SEQ *fseq;       /* Full-length sequence object */
    struct SEQCOMP *comp;   /* Sequence (simple) composition object */
    char *smask;            /* Sequence matching mask */
    int n_smask;            /* ength of smask */
    int firstb,lastb;       /* First / last base */
    int do_rre;             /* Range relative to the end */
    char row[ALPH_BLEN];    /* String for row search */
    int rowlen;             /* Length of row string */
    char con[ALPH_BLEN];    /* String for count search */
    int conlen;             /* Length of con string */
    char skew[ALPH_BLEN];   /* String for skew search */
    int skewlen;            /* Length of skew string */
    char cent[ALPH_BLEN];   /* String for centroid search */
    int centlen;            /* Length of centroid string */
    int do_not;             /* Flag to invert filtering */
    int do_dfr;             /* Flag to dump fraction composition */
    int do_ign;             /* Flag to ignore N's for fraction option */
    int do_ecc;             /* Flag for Explicit Char Counts */
    int do_btab;            /* Flag to output base count table */
    int do_rtab;            /* Flag to output rows for base count table */
    int do_dtab;            /* Flag to output di-nuc count table */
    int cwin;               /* Composition "window" size */
    int do_qual;            /* Flag for qualifying min/max */
    int do_ds;              /* Flag to dump seq */
    REAL min,max;           /* Flagging limits */
    DOUB val;               /* Run-time count value */
    DOUB val2;              /* Second run-time count value */
    int do_uc;              /* Flag mark pattern-matches with upper case */
    int do_lc;              /* Flag mark pattern-matches with lower case */
    int winsize;            /* Window size */
    int winstep;            /* Window step */
    int winst;              /* Window start */
    int winen;              /* Window end */
}ALPHCONT;

#define CHECK_ALPHCONT(ob) if(ob){DestroyAlphcontI(ob); ob=NULL;}

/***
*   Output codes
*/
#define ALCO_VAL    334     /* output value */
#define ALCO_DCC    335     /* output cumulative counts */
#define ALCO_DFG    336     /* output base flagging */
#define ALCO_DFS    337     /* output base flagging & sequence */
#define ALCO_SEQ    338     /* output qualifying sequences */
#define ALCO_DCW    339     /* output cwin values */

#define DEF_CON_S   "N"     /* Default search string */

#define DEF_WIN_SZ  100
#define DEF_WIN_ST  50

/*********************** ppp ********************
* C function listing generated by gen_prot
* Sun Jan 31 09:09:34 2016
*/
/****************************************************************
* alphcont.c
*/
int main(int argc, char **argv);
void AlphContUse(void);
int AlphContI(int argc,char **argv);
int AlphconProcSeqI(ALPHCONT *alPO, SEQ *seqPO, SEQ *fseqPO, char *nameS);
ALPHCONT *CreateAlphcontPO(void);
int DestroyAlphcontI(ALPHCONT *alPO);
void InitAlphcont(ALPHCONT *alPO);
int CheckAlcoOptionsI(ALPHCONT *alPO);
int OpenAlcoFilesI(ALPHCONT *alPO);
void HandleAlcoHeader(ALPHCONT *alPO, FILE *outPF);
int HandleAlcoSeqCleaningI(SEQ *seqPO, int eec);
int HandleAlcoSubseqI(ALPHCONT *alPO, SEQ *seqPO, SEQ *fseqPO);
int HandleSeqCountsI(ALPHCONT *alPO, SEQ *seqPO);
int GetSeqSkewI(ALPHCONT *alPO, SEQ *seqPO);
int GetSeqCentI(ALPHCONT *alPO, SEQ *seqPO);
int CheckAlphcontSeqmask(ALPHCONT *alPO, SEQ *seqPO, int init_zero);
int ScanSeqCountsI(ALPHCONT *alPO, SEQ *seqPO);
int HandleFractionValueI(ALPHCONT *alPO, SEQ *seqPO);
int MaskedInWindowI(char *maskS,int s,int n);
int IsAlphcontSeqOkI(ALPHCONT *alPO);
int HandleAlcoOutputI(ALPHCONT *alPO, SEQ *seqPO, char *nameS, int sok,
    FILE *outPF);
void DumpAlphconMask(ALPHCONT *alPO, int len, FILE *outPF);
void ReportAlphcontBaseTables(ALPHCONT *alPO, char *nameS, SEQ *seqPO, SEQCOMP *compPO, FILE *outPF);
void ReportAlphcontDinucCounts(SEQCOMP *compPO, int frac, FILE *outPF);
int QSMatchI(char *qS,char *sS,int len,int exp);

