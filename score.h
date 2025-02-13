/*
* score.h
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


#ifndef __SCOREH__
#define __SCOREH__

#include "numlist.h"
#include "wordlist.h"

#define MAX_SCF_LIST    1000  /* Max num of SCFIELDS to load at once into array */
#define MIN_SCF_XSTEP   0.001 /* Minium step in X for SCFIELD */

typedef struct SCOREC
{
    int id;     /* Index */
    DOUB sc;    /* Value */
}SCOREC;

#define SCFIELD_ID  4042
typedef struct SCFIELD
{
    int ID;
    char name[NSIZE+1];     /* score field name */
    int n;                  /* Number of X,Y values */
    DOUB minx, maxx;        /* Min and max X values */
    NUMLIST *xvals;         /* X values */
    NUMLIST *yvals;         /* Y values */
}SCFIELD;

#define CHECK_SCOREC(sc)    if(sc){DestroyScorecsI(sc); sc=NULL;}
#define CHECK_SCFIELD(ob)   if(ob){DestroyScfieldI(ob); ob=NULL;}

/***
*   IO stuff
*/
#define SCFIELD_START_S "SCFIELD_START"
#define SCFIELD_END_S   "SCFIELD_END"


/*********************** ppp ********************
* C function listing generated by gen_prot
* Mon Jan  4 13:23:34 2016
*/
/****************************************************************
* score.c
*/
SCOREC *CreateScorecsPO(int n);
int DestroyScorecsI(SCOREC *recsPO);
void InitScorecs(SCOREC *recsPO,int n);
SCFIELD *CreateScfieldPO(char *nameS);
int DestroyScfieldI(SCFIELD *sfPO);
void SortScorecVals(SCOREC *scPO,int n,int dir);
void SortScorecIds(SCOREC *scPO,int n,int dir);
void DumpScorecsI(SCOREC *recsPO,int n,FILE *outPF);
int SetScfieldNameI(SCFIELD *sfPO,char *nameS,int max);
int FillScfieldNameStringI(SCFIELD *sfPO,char *nameS,int max);
REAL EvalScfieldScoreR(SCFIELD *sfPO, REAL vR);

/****************************************************************
* score_io.c
*/
int LoadScfieldI(FILE *inPF, int error, SCFIELD **sfPPO);
int LoadScfieldArrayI(FILE *inPF, SCFIELD ***scPPPO);
int ReportScfieldI(SCFIELD *sfPO, char *prefixS, FILE *oPF);
int ReportScfieldArrayI(SCFIELD **scPPO, int n, char *prefixS, FILE *oPF);


#endif
