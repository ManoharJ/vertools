/*
* tm_pars.h
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


/***
*    Energy value array indices
*    Sequence near-neighbor doubles AA, AC, AG, AT, CA, ... are indices 0-15
*    Extra index terms
*/
#define INITAT_IND      16
#define INITCG_IND      17
#define NN_IND_NUM      18

#define H_TABLE         20
#define S_TABLE         21


/***
*    Data structure to hold parameters for Tm calculation
*/
#define TM_PARS_ID      4072
typedef struct TM_PARS
{
    int ID;
    int algo;           /* lag indicating what algorithm to use */
    int csym;           /* heck symmetry (to correct concentration term) */
    int dir;            /* lag to indicate strand direction */
    int ambig_ok;       /* lag to not complain about ambiguous bases */
    char source[NSIZE]; /* ame of file of parameters */
    double conc,conc2,conc3;    /* NA concentrations (M) */
    double salt;        /* Salt concentration (M) */
    double mg;          /* Mg concentration (M) */
    double tp;          /* Temperature */
    struct TABLE *htab; /* Table of enthalpies; Rows = NN; Cols = position */ 
    int ht_col, ht_d;   /* htab number of columns, default column */
    struct TABLE *stab; /* Table of entropies; Rows = NN; Cols = position */
    int st_col, st_d;   /* stab number of columns, default column */
    double Gterm[5][5][5][5];
    double Hterm[5][5][5][5];
    double Gprop[4][4][4][4];
    double Hprop[4][4][4][4];
    double Gcoax[4][4][4][4];
    double Hcoax[4][4][4][4];
    double HinitAT,GinitAT,HinitGC,GinitGC;
    double Ggap[30];
    double GATclosepen;
}TM_PARS;

#define CHECK_TM_PARS(ob) if(ob){DestroyTm_parsI(ob); ob=NULL;}


/***
*    Algorithm codes 
*/
#define ALGO_SANTA      51
#define ALGO_OLIGO      52
#define ALGO_MELTING    53
#define ALGO_24         54
#define ALGO_PNA        57
#define ALGO_PEYRET     58


/***
*    Defaults and limits
*/
#define DEF_TM_ALGO     ALGO_SANTA  /* Default nearest neighbors algorithm */

#define DEF_NN_CONC     1e-10       /* Default nearest neighbors conc. */
#define MIN_NN_CONC     1e-20       /* Min nearest neighbors conc. */
#define MAX_NN_CONC     1.0         /* Max nearest neighbors conc. */

#define DEF_NN_SALT     1.0         /* Default nearest neighbors salt */
#define MIN_NN_SALT     0.0         /* Min nearest neighbors salt */
#define MAX_NN_SALT     4.0         /* Max nearest neighbors salt */

#define DEF_NN_MG       0.0         /* Default nearest neighbors Mg++ */
#define MIN_NN_MG       0.0         /* Min nearest neighbors Mg++ */
#define MAX_NN_MG       1.0         /* Max nearest neighbors Mg++ */

#define DEF_NN_TEMP     37.0        /* Default temp C */
#define MIN_NN_TEMP     0.0         /* Minimum allowed temp C */
#define MAX_NN_TEMP     100.0       /* Maximum allowed temp C */

#define DEF_AMBIG_OK    FALSE       /* Flag to allow ambig bases */

#define MIN_TM_LEN      5           /* Minimum Tm length */
#define MAX_TM_LEN      255         /* Maximum Tm length allowed */

/*********
*    PNA "Correction" factors
*/
#define PNA_TM_SC_D     0.81
#define PNA_TM_CON_D    20.9    
#define PNA_TM_PYR_D    -27.2    
#define PNA_TM_LEN_D    0.52



/*********************** ppp ********************
* C function listing generated by gen_prot
* Mon Dec 31 11:45:10 2012
*/
/****************************************************************
* dna_tm.c
*/
int SeqTmThermI(TM_PARS *tmPO, char *seqS, int len, DOUB *tPR, DOUB *gPR,
    DOUB *hPR, DOUB *sPR);
DOUB TmFromGCContD(TM_PARS *tmPO,char *seqS,int len);
int SetSeqTmInitTermsI(TM_PARS *tmPO,char *seqS,int len,DOUB *hPD,DOUB *sPD);
int GetThermoTabTermsI(TM_PARS *tmPO, int term, int pos, int len, DOUB *hPD, DOUB *sPD);
int SeqEndInitIndex(char c);
int TallySeqTmNNTermsI(TM_PARS *tmPO,char *seqS,int len,DOUB *hPD, DOUB *sPD);
DOUB TmFromThermoSumsD(TM_PARS *tmPO,DOUB hD,DOUB sD,int len);
int SeqLenForThermI(TM_PARS *tmPO, char *seqS, int len, DOUB targD, int dir,
    DOUB *ltmPD, DOUB *htmPD, int do_fds);
DOUB CalcPNATmI(TM_PARS *tmPO,char *seqS,int len);

/****************************************************************
* dset_tm.c
*/
int SeqDsetEnergyI(TM_PARS *tmPO,char *seqtopPC,char *seqbotPC,int verboseI,
    int modeI, DOUB *tPD, DOUB *gPD, DOUB *hPD, DOUB *sPD, DOUB *xPD);
int ValidDsetModeI(char *seqtopPC,char *seqbotPC,int modeI);
int DsetNumValsI(int modeI);
int LoadTmCompleteParsI(TM_PARS *tmPO,FILE *fPF);
int InitTmCompleteParsI(TM_PARS *tmPO);
void DumpCompleteTmPars(TM_PARS *tmPO,FILE *outPF);
int SeqToNumsI(char *seqS,int *numsPI,int max,int mode,int verb);

/****************************************************************
* tm_io.c
*/
void DumpTmPars(TM_PARS *tmPO, char *preS, int full, FILE *outPF);
void DumpSimpleTmPars(TM_PARS *tmPO, char *preS,FILE *outPF);
void FillTmAlgoString(TM_PARS *tmPO,char *bufS);
void FillTmConcString(TM_PARS *tmPO,char *bufS);
void FillTmSaltString(TM_PARS *tmPO,char *bufS);
void FillTmTempString(TM_PARS *tmPO,char *bufS);
void FillTmMgString(TM_PARS *tmPO,char *bufS);
void FillTmStrandDirString(TM_PARS *tmPO,char *bufS);
int ParseTmAlgoI(char *nameS);
void FillTmParSourceString(TM_PARS *tmPO,char *bufS);
int LoadTmParNNEnergiesI(TM_PARS *tmPO,char *inS);

/****************************************************************
* tm_pars.c
*/
TM_PARS *CreateTm_parsPO(void);
int DestroyTm_parsI(TM_PARS *tmPO);
void InitTmPars(TM_PARS *tmPO);
void InitThermoPars(TM_PARS *tmPO);
void ClearTmParNNTables(TM_PARS *tmPO);
int InitTmParNNTablesI(TM_PARS *tmPO, int r, int c);
void UpdateTmParsNNTabVars(TM_PARS *tmPO);
void PrettyTmParTableForm(TM_PARS *tmPO);
void SetSantaTmThermPars(TM_PARS *tmPO);
void SetOligoTmThermPars(TM_PARS *tmPO);
int SetThermoTableNNValI(TM_PARS *tmPO, int which, char *nnS, int c, DOUB vD);
int NNSeqPairIndexI(char *inS);
void SetTmParAlgo(TM_PARS *tmPO, int which, int init);
int GetTmParAlgoI(TM_PARS *tmPO);
int LegitTmParConcI(DOUB cD);
void SetTmParConc(TM_PARS *tmPO,DOUB cD, DOUB secD, DOUB thirD);
int GetTmParConcI(TM_PARS *tmPO,DOUB *fPD, DOUB *sPD, DOUB *tPD);
int ConcTermsForTmAlgoI(TM_PARS *tmPO);
int LegitTmParSaltI(DOUB cD);
void SetTmParSalt(TM_PARS *tmPO,DOUB cD);
int GetTmParSaltI(TM_PARS *tmPO,DOUB *saltPD);
int LegitTmParTempI(DOUB tD);
void SetTmParTemp(TM_PARS *tmPO,DOUB cD);
int GetTmParTempI(TM_PARS *tmPO,DOUB *tPD);
int LegitTmParMgI(DOUB cD);
void SetTmParMg(TM_PARS *tmPO,DOUB cD);
int GetTmParMgI(TM_PARS *tmPO,DOUB *tPD);
void SetTmParAmbigBaseOK(TM_PARS *tmPO,int ok);
void SetTmStrandDir(TM_PARS *tmPO,int dir);
void SetTmParDefCol(TM_PARS *tmPO,int which, int col);
int SetTmParsTableColLabs(TM_PARS *tmPO, int which);

