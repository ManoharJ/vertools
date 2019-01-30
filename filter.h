/*
* filter.h
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

#define VERSION_S       "Filter version 1.5"

#define FILTBUF_SIZE    100000

#define DEF_COL         1

#define MAX_BLK_SIZE    100

#define FILTER_ID       5071
typedef struct FILTER
{
    int ID;
    char inname[NSIZE];     /* input file name */
    FILE *in;               /* input file */
    char *mask;             /* input file mask */
    int n_mask;             /* mask length */
    int n_block;            /* number of line blocks */
    char outname[NSIZE];    /* output file name */
    FILE *out;              /* outpuf file */
    char wlisname[NSIZE];   /* token list filename */
    struct WORDLIST *wlis;  /* token list structure */
    int num;                /* Working number of lines */
    int nok;                /* Working number of qualified lines */
    int col;                /* Column to filter on */
    DOUB min, max;          /* min / max values */
    int firstl,lastl;       /* First and last lines */
    int firstb,lastb;       /* First and last blocks */
    int l_bof,l_blk;        /* Line block offset and block size */
    char blk_mlis[NSIZE];   /* Within-block line mask raw string */
    char *blk_mask;         /* Within-block line number mask */
    int do_bm_not;          /* Flag to invert within-block line mask */
    int rann;               /* Random number to pick */
    int seed;               /* Random seed */
    DOUB ranf, ranp;        /* Random fraction / probability to pick */
    int maxout;             /* Limit on number of output lines */
    int do_not;             /* Flag to invert record qualifcations */
    int skipc;              /* Number of chars to skip in input lines */
    int do_stat;            /* Flag to do stats */
    int do_kc;              /* Flag to keep case for token compare */
    int do_wst;             /* Flag to compare starte for token compare */
    int do_wsub;            /* Flag to check substring for token compare */
    int do_flag;            /* Flag to prepend output lines 1/0 */
    int do_pln;             /* Flag to prepend output lines with line number */
    int do_pfn;             /* Flag to prepend output lines with filename */
    char do_pre[NSIZE];     /* Add prefix to lines */
    char do_suf[NSIZE];     /* Add suffix to lines */
    int do_icbn;            /* Flag to ignore chars before numbers */
    int do_vex;             /* Flag to filter values exclusive of bounds */
    int do_all;             /* Flag to consider all lines */
    int do_abs;             /* Flag to do absolute values */
    int do_A;               /* Number of lines After to report */
    int do_B;               /* Number of lines Before to report */
    int do_quiet;           /* Flag to only output lines; No summary */
}FILTER;

#define CHECK_FILTER(fp)    if(fp){DestroyFilterI(fp);fp=NULL;}


/*********************** ppp ********************
* C function listing generated by gen_prot
* Mon Oct 17 21:29:12 2016
*/
/****************************************************************
* filter.c
*/
int main(int argc, char **argv);
void Filter_numsUse(void);
int Filter_numsI(int argc, char **argv);
int SkipThisLineI(FILTER *filtPO, char *bufS);
char *GetLineStartPC(FILTER *filtPO, char *bufS);
int SetBeforeMaskingI(FILTER *filtPO) ;
FILTER *CreateFilterPO(void);
int DestroyFilterI(FILTER *fpPO);
void InitFilter(FILTER *fpPO);
int CheckFilterOptionsI(FILTER *filtPO);
int HandleFilterBlocksI(FILTER *filtPO);
int HandleFilterMaskingI(FILTER *filtPO);
int BlockForFiltLineI(FILTER *filtPO, int line);
int LineInFiltBlockI(FILTER *filtPO, int line);
int LineInBlockOkI(FILTER *filtPO, int line);
int SetRandFilterMaskingI(FILTER *filtPO, DOUB fracD);
int DoingRandFilterI(FILTER *filtPO, int do_ranp);
int NeedFilterMaskingI(FILTER *filtPO);
int HandleFilterListSetsI(FILTER *filtPO);
int OpenFilterFilesI(FILTER *filtPO);
void ReportFilterStats(FILTER *filtPO, int num, int nok) ;
int FiltGetWordNumValI(FILTER *filtPO, char *wordS, DOUB *valPD);
int IsFiltLineOkI(FILTER *filtPO, int line, char *cPC, int use_mask) ;

