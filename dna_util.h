/*
* dna_util.h
*
* Copyright 2014 Ryan Koehler, VerdAscend Sciences, ryan@verdascend.com
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

#define VERSION_S 	"Dna_Util version 0.82"

#define DNA_UTIL_ID  	5051
typedef struct DNA_UTIL
{
	int ID;
	FILE *in;				/*	Input file */
	char inname[NSIZE];		/*	Input filename */
	int iform;				/*	Input file format */
	int iclean;				/*	Input file cleaning level */
	FILE *out;				/*	Output file */
	char outname[NSIZE];	/*	Output filename */
	int owhat;				/*	Output what? */
	int do_flg;				/*	Flag output */
	int oform;				/*	Output format */
	int igprob;				/*	Flag to ignore problems and continue on */
	int do_comp;			/*	Flag to (reverse) compliment */
	int do_rev;				/*	Flag to reverse (i.e. 3' to 5') */
	int do_inv;				/*	Flag to inverse (comp but 3' to 5') */
    int do_nan;             /* Flag for no added auto naming */
    int nfblock, nfline;    /* Per block and per line nice format values */
	int do_clean;			/*	Flag to clean up seqs */
	int do_exi;				/*	Flag to expand IUB codes */
    int do_cstat;           /*  Flag to report Case-based stats */
    int do_csep;            /*  Flag to do Case-based separation of seqs */
    char wlisname[NSIZE];   /* Token list filename */
    struct WORDLIST *wlis;  /* Token list structure */
	int do_kc;				/* Flag to keep case for subset comparison */
    int do_wst;             /* Flag to compare starte for token compare */
    int do_wsub;            /* Flag to check substring for token compare */
	int do_tnb;				/*	Flag to truncate name on blank */
	int do_not;				/*	Invert flagging */
	int do_num;				/*	Report number of seqs */
	struct SEQ *seq;		/*	Sequence object */
	int first,firstb;		/*	First sequence / base */
	int last,lastb;			/*	Last sequence / base */
	int lo_mran,hi_mran;	/*	Mask low and high base bounds */
	int do_imask;			/*	Flag to ivert mask base bounds */
	int do_rre;				/*	Range relative to the end */
	int do_famb;			/*	Filter any seqs with ambigs */
	int do_fsnp;			/*	Filter any seqs with SNPs */
	int min_len,max_len;	/*	Filter with this length range */
	int n_flags;            /*	Number of flag filters */
	int len_hi,len_lo;		/*	Running stat; high / low length */ 
	int snp_hi,snp_lo;		/*	Running stat; high / low SNP count */
	int snp_c,amb_c;		/*	Running stat; SNP / ambig counts */
	int do_pol,do_pml;		/*	Output probes of this length */
	int opl_st,opl_j;		/*	Start and jump for opl option */
	char olpname[NSIZE];	/*	Listed probe filename */
	FILE *olp;				/*	Listed probe input file */
	int olp_up,olp_dn;		/*	Listed probe up/down extra */
	int do_pat;				/*	Probe allowed truncation */
	int do_pco;				/*	Probe clean only */
	int ifwmin,ifwmax;		/*	Info (word-based) min and max */
	int do_insh;			/*	Info shannon index */
	int do_inbr;			/*	Info brillouin index */
	int do_inbp;			/*	Info berger-parker index */
}DNA_UTIL;

#define CHECK_DNA_UTIL(tu)	if(tu){DestroyDna_utilI(tu); tu=NULL;}

/***
*	Output codes
*/
#define DNUO_SEQ    91		/*	Sequence output */
#define DNUO_LIS	94		/*	List output */
#define DNUO_STAT	96		/*	Stats output */
#define DNUO_OSTAT	97		/*	Only stats reported */
#define DNUO_PROBE  98		/*	Probes output */
#define DNUO_INFO	99		/*	Info output */
#define DNUO_CSEP   100		/*	Case-base separation */

#define CLEAN_CASE	110
#define CLEAN_ALL	111
#define CLEAN_SNP	112



/*********************** ppp ********************
* C function listing generated by gen_prot
* Tue Jul 26 17:14:07 2011
*/
/****************************************************************
* dna_prob.c
*/
int CheckDnuProbeOptionsI(DNA_UTIL *duPO);
int HandleDuProbesOutI(DNA_UTIL *duPO,FILE *outPF);
int HandleDuOneProbeOutI(DNA_UTIL *duPO, char *seqPC, int len, char *pnameS, FILE *outPF);

/****************************************************************
* dna_util.c
*/
int main(int argc, char **argv);
void DnaUtilUse(void);
int DnaUtilI(int argc, char **argv);
DNA_UTIL *CreateDna_utilPO(void);
int DestroyDna_utilI(DNA_UTIL *duPO);
void InitDna_util(DNA_UTIL *duPO);
int AnyInfoSettingsI(DNA_UTIL *duPO);
int CheckDnuOptionsI(DNA_UTIL *duPO);
int OpenDnuFilesI(DNA_UTIL *duPO);
int SetUpOptionFlags(DNA_UTIL *duPO);
int SetUpDnuAuxDataI(DNA_UTIL *duPO);
int HandleDuSeqFlipsI(DNA_UTIL *duPO);
int HandleDuSeqMaskingI(DNA_UTIL *duPO);
int HandleDuSubseqI(DNA_UTIL *duPO);
int IsCurrentSeqOkI(DNA_UTIL *duPO,int n);
int HandleDuApgI(DNA_UTIL *duPO,int n);
int HandleMergeSeqsI(SEQ *fPO, SEQ *sPO, int dir, int over, SEQ **newPPO);
void HandleDuCleanExp(DNA_UTIL *duPO);
int HandleDuOutputI(SEQ *seqPO, int ok, DNA_UTIL *duPO, FILE *outPF);
int HandleDnaOstatI(char *nameS, char *seqS, int len, FILE *outPF);
void HandleDuStats(DNA_UTIL *duPO,int n,int nok,FILE *outPF);
void HandleDnuFlagHeader(DNA_UTIL *duPO,FILE *outPF);
void HandleDnuOstatHeader(DNA_UTIL *duPO,FILE *outPF);
void HandleDnuInfoHeader(DNA_UTIL *duPO,FILE *outPF);
int HandleDnaInfoOutI(DNA_UTIL *duPO,FILE *outPF);
int DuOpenOutfileForSeqI(SEQ *seqPO,DNA_UTIL *duPO);
int HandleCaSepOutputI(DNA_UTIL *duPO, char *nameS, char *seqS, int len, FILE *outPF);
int CaSepCharClass(char c);
int UpSepCharCountStory(int t, int *cPI, char *nS);
void HandCaSepOneSeqOut(DNA_UTIL *duPO, char *seqS, int s, int e, char *nameS, char *baseS, 
    FILE *outPF);

