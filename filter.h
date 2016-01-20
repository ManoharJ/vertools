/*
* filter.h
*
* Copyright 2016 Ryan Koehler, VerdAscend Sciences, ryan@verdascend.com
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

#define VERSION_S       "Filter version 1.1"

#define FILTBUF_SIZE    100000

#define DEF_COL         1


#define FILTER_ID       5071
typedef struct FILTER
{
    int ID;
    char inname[NSIZE];     /* input file name */
    FILE *in;               /* input file */
    char *mask;             /* input file mask */
    int n_mask;             /* mask length */
    char outname[NSIZE];    /* output file name */
    FILE *out;              /* outpuf file */
    char wlisname[NSIZE];   /* token list filename */
    struct WORDLIST *wlis;  /* token list structure */
    int num;                /* working number of lines */
    int nok;                /* working number of qualified lines */
    int col;                /* column to filter on */
    DOUB min, max;          /* min / max values */
    int firstl,lastl;       /* first and last lines */
    int rann;               /* random number to pick */
    int seed;               /* random seed */
    DOUB ranf, ranp;        /* random fraction / probability to pick */
    int do_not;             /* flag to invert record qualifcations */
    int skipc;              /* number of chars to skip in input lines */
    int do_stat;            /* flag to do stats */
    int do_kc;              /* flag to keep case for token compare */
    int do_wst;             /* flag to compare starte for token compare */
    int do_wsub;            /* flag to check substring for token compare */
    int do_flag;            /* flag to prepend output lines 1/0 */
    int do_pln;             /* flag to prepend output lines with line number */
    int do_icbn;            /* flag to ignore chars before numbers */
    int do_A;               /* Number of lines After to report */
    int do_B;               /* Number of lines Before to report */
    int do_quiet;           /* flag to only output lines; No summary */
}FILTER;

#define CHECK_FILTER(fp)    if(fp){DestroyFilterI(fp);fp=NULL;}


/*********************** ppp ********************
* C function listing generated by gen_prot
* Sun Jan 17 11:41:30 2016
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
int HandleFilterMaskingI(FILTER *filtPO);
int DoingRandFilterI(FILTER *filtPO, int do_ranp);
int NeedFilterMaskingI(FILTER *filtPO);
int HandleFilterListSetsI(FILTER *filtPO);
int OpenFilterFilesI(FILTER *filtPO);
void ReportFilterStats(FILTER *filtPO, int num, int nok) ;
int FiltGetWordNumValI(FILTER *filtPO, char *wordS, DOUB *valPD);
int IsFiltLineOkI(FILTER *filtPO, int line, char *cPC, int use_mask) ;

