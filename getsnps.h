/*
* getsnps.h
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

#define VERSION_S	"GetSNPs version 0.5"

#define SUM_FILE	"sum.out"
#define DIV_CHAR	'|'
#define DEF_WSIZE	40

#define	AMASK_DIM	100

#define HEADLEN	500
#define SEQMAX 	50000
#define SNPMAX 	2000
#define CFMAX	500
#define N_SNP   4

typedef struct SNPREC
{
	char name[CFMAX];	/*	Unique id */
	char head[HEADLEN];	/*	Full header line */
	int taxid;			/*	"taxid" field from SNPdb ? */
	int class;			/*	"class" field from SNPdb ? */
	int apos;           /*	Allele position */

	char vtype[CFMAX];	/*	VarType field from HGBASE; SNP, Indel, etc. */
	char cstat[CFMAX];	/*	CurationStatus field from HGBASE */
	char freq[CFMAX];	/*	Frequency data from HGBASE */
	char genen[CFMAX];	/*	Gene name from HGBASE */
	char gener[CFMAX];	/*	Gene region data from HGBASE */

	char seq[SEQMAX];	/*	Sequence */
	char snp[SNPMAX];   /*	SNP Sequence (full polymorphism) */
	int slen,snplen;	/*	Sequence / SNP lengths */
    char ales[N_SNP][SNPMAX];     /* Allele sequences */
    char iubc[DEF_BS];  /* SNP code */
	int nales;			/*	Number of alleles */ 
	char sequp[SEQMAX];	/*	Upstream (3') sequence */
	char seqdn[SEQMAX];	/*	Downstream (5') sequence */
    int uplen,dnlen;    /*  Upstream / downstream length */
	int do_cs;			/* 	Flag to "collapse" sequences */ 
	int do_awin;		/* 	Flag to output all windows, regardless of fit */
	int do_nwin;		/* 	Flag for max ambigs allowed in a window */
	int do_twin;		/* 	Flag to trim ambigs off of windows */
	int nal;			/* 	Flag for number of SNP alleles */
	int maxa;			/* 	Flag for max SNP alleles */
	int in_form;		/*	Flag for input format */
	int out_form;		/*	Flag for output format */
    int do_oexs;        /*  Flag to output explicit seqs for all alleles */
	int do_oexd;		/*	Flag for dashes in explicit output */
}SNPREC;

#define INF_SNPDB	20		/*	SNPDb format */


/*********************** ppp ********************
* C function listing generated by gen_prot
* Fri Feb 25 16:43:24 2011
*/
/****************************************************************
* getsnps.c
*/
int main(int argc, char **argv);
void GetSnpsIUse(void);
int GetSnpsI(int argc,char **argv);
void InitSnprec(SNPREC *snPO,int full);
void DumpSnprec(SNPREC *snPO, FILE *outPF);
int LoadSNPdbFastaRecI(FILE *inPF, SNPREC *snPO);
int LoadSNPdbFastaRecI(FILE *inPF, SNPREC *snPO);
int ParseSNPdbHeadFields(SNPREC *snPO, char *headS);
int OkSnpRecI(SNPREC *snPO, char *iubS, int class, int min, int max,
	char *vtypeS, char *cstatS, char *generS);
int ExtractSnpWinI(SNPREC *snPO, int uwin, int dwin, FILE *outPF);
int SetWindowStartEndI(SNPREC *snPO,int uwin,int dwin,int *sPI,int *ePI);
void WriteOutSequence(char *nameS, char *seqS, int oform, FILE *outPF);
void OutputHeader(SNPREC *snPO, char *inS, char *snpS, int class, int min, 
	int max, int not, char *outS,FILE *fPF);
int LoadRawSnpRecI(FILE *inPF,SNPREC *snPO);
int LoadFastaSnpRecI(FILE *inPF, SNPREC *snPO);
int ParseSnpAllelesI(SNPREC *snPO);
int ExtractSNPInfoFromSeqI(SEQ *seqPO, SNPREC *snPO);

