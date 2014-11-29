/*
* dset_tm.h
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


#define NP_S	"Nicolas Peyret, peyretnn@appliedbiosystems.com"

#define DSET_VERSION_S "dset ?"

# define DSET_IMP 		80	/*	Implicit second strand */
# define DSET_EXPNOCOAX 81	/*	Explicit second strand, no coaxial */
# define DSET_EXPCOAX 	82	/*	Explicit second strand, with coaxial */
# define DSET_PRIM 		83	/*	Primer mode, second implicit (kill ends) */

# define DSET_EV_FULL	0	/*	Full energy (no H/S for coaxial) */
# define DSET_EV_5P		1	/*	5' component without stacking */
# define DSET_EV_5P_ST	2	/*	5' component with stacking */
# define DSET_EV_3P		3	/*	3' component without stacking */
# define DSET_EV_3P_ST	4	/*	3' component with stacking */

# define DSET_EV_NUM	5	/*	Max number for energy value index */


/*********************** ppp ********************
* C function listing generated by gen_prot
* Wed Mar 21 11:54:41 2001
*/
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

