/*
* comp_seq.h
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


#define VERSION_S "Comp_Seq Version 1.61"

#define MAX_CSL 25000

#define COMPSEQ_ID 5041

typedef struct COMPSEQ
{
    int ID;
    char outname[NSIZE];    /* Output file name */
    FILE *out;              /* Output file */
    int owhat;              /* Flag for different output options */
    /***
    *   Sequence sets
    */
    FILE *in;               /* Query seq file */
    char inname[NSIZE];     /* Query seq set filename */
    int iform;              /* Input file format */
    char rinname[NSIZE];    /* Reference seq set filename */
    struct SEQ *seq;        /* Single Query sequence */ 
    struct SEQSET *seqs;    /* Query sequence set */ 
    struct SEQSET *rseqs;   /* Reference seq set (if specified) */
    struct SEQSET *target;  /* Pointer to target sequence set */
    int nseqs;              /* Number of sequences */
    int ntargseqs;          /* Number of target sequences */
    int ntarg;              /* Number of targets to consider */
    struct PPARS *pp;       /* Pairing parameter datatype */
    char com[MAX_CSL];      /* Temp space to hold seq compliments */
    /***
    *   Various options
    */
    int do_sim;
    int do_com;
    int do_self;
    int do_pself;
    int do_loop;
    int do_ham;             /* lag to do Hamming distance */
    int do_crs;
    int do_dpar;            /* Flag to dump full parameters */
    int do_sa;              /* Flag to show alignment */
    int do_rm;              /* Flag to report matching alignment */
    int do_fmat;            /* Flag to dump full matrix */
    int do_norm;            /* Flag to normalize reported scores */
    int ostat;              /* Flag for only stats reported */
    REAL fullmat;           /* Full match threshold for alignments */
    REAL partmat;           /* Partial match threshold for alignments */
    REAL flo,fhi;           /* Reporting score range; low to high */
    int do_flag;            /* Flag to indicate if in bounds */
    int do_not;             /* Invert flagging criteria */
    int do_eraw;            /* Extract flagged seq subset in raw format */
    int do_ds;              /* Flat to dump sequence (append to rows) */
    /***
    *   Run-time values and allocated sub structs
    */
    REAL max_sc,min_sc;
    REAL av_sc;
    int *offs;              /* Array of alignment offsets[ntarg] */
    REAL *scores;           /* Array of scores[ntarg] */
}COMPSEQ;

#define CHECK_COMPSEQ(ob) if(ob){DestroyCompseqI(ob);ob=NULL;}

/***
*   Output codes
*/
#define CSO_LOOP    3344    /* Loop output */
#define CSO_SELF    3345    /* Self output */
#define CSO_PSELF   3346    /* Parallel self output */
#define CSO_RSER    3347    /* Ref-set serial compare */
#define CSO_FULL    3348    /* Full pair-wise compare */


/*********************** ppp ********************
* C function listing generated by gen_prot
* Tue Aug 16 10:03:11 2005
*/
/****************************************************************
* comp_seq.c
*/
int main(int argc, char **argv);
void Comp_seqUse(void);
int Comp_seqI(int argc, char **argv);
int GetNextSeqI(COMPSEQ *csPO,int s, SEQ **seqPPO);
void HandleNoScoreOut(COMPSEQ *csPO,SEQ *seqPO);
void HandleSeqPairOut(COMPSEQ *csPO, SEQ *fseqPO, SEQ *sseqPO, int sc, int
    comp, int antip);
void HandleSeqLoopOut(COMPSEQ *csPO, SEQ *seqPO, int sc);
int FillFormatSeqLineI(char *sPC,int len,int off,char *seqS);
int FillFormatPairMatchLineI(char *fseqS,char *sseqS,int comp,char *matS);
int GetCompSeqSeqsI(COMPSEQ *csPO,int quiet);
void WriteCompseqHeader(COMPSEQ *csPO,FILE *outPF);
void FillCompseqOutWhatString(int owhat,char *bufS);
void WriteHeaderForFmat(COMPSEQ *csPO,FILE *outPF);
int AddCompseqScoreSpaceI(COMPSEQ *csPO);
int OpenCompseqOutputI(COMPSEQ *csPO);
COMPSEQ *CreateCompseqPO(void);
int DestroyCompseqI(COMPSEQ *csPO);
void InitCompseq(COMPSEQ *csPO);
int CheckCompseqOptionsI(COMPSEQ *csPO);
int ProcessScoresI(COMPSEQ *csPO,int cur,char *seqPC,int len);
int HandleSeqFlaggingI(COMPSEQ *csPO,SEQ *seqPO,FILE *outPF);
int HandleMatrixOutI(COMPSEQ *csPO,char *fnameS,FILE *outPF);
int HandleFullScoreOut(COMPSEQ *csPO,int nsco,int cur,SEQ *seqPO);

