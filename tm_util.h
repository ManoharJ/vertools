/*
* tm_util.h
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

#define VERSION_S   "Tm_Util Version 1.21"

#define TMU_NLEN        255

#define DEF_LTM_ROWS    30
#define DEF_LTM_COLS    15

#define TM_UTIL_PFMT    "%6.3f"

#define TM_UTIL_ID      5151
typedef struct TM_UTIL
{
    int ID;
    FILE *in;               /* Input file */
    char inname[TMU_NLEN];  /* Input filename */
    int iform;              /* Input file format */
    struct SEQ *seq,*sseq;  /* Sequence structure / second strand */
    struct SEQ *fseq;       /* Full (input) sequence */
    FILE *out;              /* Output file */
    char outname[TMU_NLEN]; /* Output filename */
    int oform;              /* Output file format */
    int owhat;              /* Output what info? */
    char parname[TMU_NLEN]; /* Tm parameter filename */
    struct TM_PARS *tm;     /* Tm parameter structure */
    int algo;               /* Tm algorithm */
    DOUB con1,con2,con3;    /* Concentration terms */
    DOUB salt,mg,temp;      /* Salt, Mg, temperature */
    int pdc;                /* Paramter table default column */
    int do_rsd;             /* Flag to reverse target strand */    
    int quiet;              /* Flag to be quiet */
    int do_dpar;            /* Flag to dump parameters */          
    int do_ds;              /* Flag to dump seqs */          
    int do_therm;           /* Flag to dump thermo terms */    
    int do_dtherm;          /* Flag to dump delta thermo terms (tes) */    
    int do_cmb;             /* Flag for competitive miss-match binding */
    int do_fds;             /* Flag to compute fraction double strand */
    int do_tes;             /* Flag for two explicit seqs / value */
    int do_btes;            /* Flag for two explicit seqs, blast alignment */
    int do_den;             /* Flag for dangling end values */
    int do_tmpro;           /* Flag to report temp profile */
    int do_padbad;          /* Flag to pad for bad values */
    int do_tab_lo;          /* Flag thermo table low (min) length */
    int do_tab_hi;          /* Flag thermo table high (max) value */
    int do_tab_j;           /* Jump for table option */
    int do_tabex;           /* Flag for special combo table-samp + flag + extract */
    DOUB tlen;              /* Target length value */
    int tlp;                /* Target length start position */
    int do_tlrev;           /* Flag for target length to start reverse */
    int do_tlmin;           /* Flag for target length to be min */
    int do_otls;            /* Flag to output seqs with tlen option */
    DOUB minv,maxv;         /* Min / max values for flagging */
    int do_flag;            /* Flag to indicate min/max value flagging */
    int do_not;             /* Invert flagging qualification test */
    int do_eraw;            /* Flag to extract flagged seqs */
    int do_emin;            /* Flag to extract only min-length flagged seqs */
    int do_emax;            /* Flag to extract only max-length flagged seqs */
    int do_emid;            /* Flag to extract only mid-length flagged seqs */
    struct TABLE *ltm_tab;  /* Length-Tm table */
    int firstb,lastb;       /* First/last base for restricted base range */
    int do_rre;             /* Restrict range relative to end */
    DOUB Tm,dG,dH,dS,fds;   /* Runtime values */
    DOUB Tm2,dG2,dH2,dS2,fds2;      /* 2'nd set of runtime values */
}TM_UTIL;

#define CHECK_TM_UTIL(tu)   if(tu){DestroyTm_utilI(tu); tu=NULL;}


/*********************** ppp ********************
* C function listing generated by gen_prot
* Sun Jan  1 21:39:09 2017
*/
/****************************************************************
* tm_util.c
*/
int main(int argc, char **argv);
void TmUtilUse(void);
int TmUtilI(int argc, char **argv);
TM_UTIL *CreateTm_utilPO(void);
int DestroyTm_utilI(TM_UTIL *tuPO);
int InitTm_utilI(TM_UTIL *tuPO);
void ClearTm_utilThermoVals(TM_UTIL *tuPO);
int HandleTmLenI(TM_UTIL *tuPO, FILE *outPF);
int HandleTmProfileI(TM_UTIL *tuPO, FILE *outPF);
int HandleThermoSampleTableI(TM_UTIL *tuPO, FILE *outPF);
int GetTableRowFlagValIndicesI(TM_UTIL *tuPO, int row, int *fPI, int *lPI);
int LoadTmutilSequenceI(TM_UTIL *tuPO, int n);
int CallDsetTwoSeqsI(TM_UTIL *tuPO);
int OpenTmutilFilesI(TM_UTIL *tuPO);
int CheckTmutilOptionsI(TM_UTIL *tuPO);
int SetTmParOptionsI(TM_UTIL *tuPO);
void ReportTmutilSettings(TM_UTIL *tuPO, FILE *outPF);
void ReportFlaggedOutputI(TM_UTIL *tuPO, FILE *outPF);
void ReportTmutilOutput(TM_UTIL *tuPO, FILE *outPF);
int SeqFlaggingValI(TM_UTIL *tuPO, DOUB *valPD);
int HandleTmutilOutputI(TM_UTIL *tuPO, int good, char *seqS, int slen,
    char *nameS, FILE *outPF);
int HandleCompetitiveFbOutputI(TM_UTIL *tuPO,FILE *outPF);
void ReportDsetProblemSeq(char *nameS,FILE *outPF);
int HandleTmuSubseqI(TM_UTIL *tuPO, SEQ *seqPO, SEQ *fseqPO);

