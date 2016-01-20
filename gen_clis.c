/*
* gen_clis.c
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define __MAIN__
#include "prim.h"


#define VERSION_S   "gen_clis Version 0.32"


#define INFILE_S    "cfile.lis"
#define DEF_EXT_S   "cfl"

int main(int argc, char **argv);
void Gen_ClisUse(void);
int Gen_ClisfileI(int argc, char **argv);


/**************************************************************************/
int main(int argc, char **argv)
{ Init(argc,argv); exit(AllDoneI(Gen_ClisfileI(argc,argv),NULL)); }
/**************************************************************************/
void Gen_ClisUse()
{
    VersionSplash(NULL,VERSION_S,"#  ",TRUE);
    printf("Usage: ...[options]\n");
    printf("   -i XXX     Read in XXX (default = %s)\n",INFILE_S);
    printf("   -ext XXX   Set extent to XXX (default = %s)\n",DEF_EXT_S);
}
/**************************************************************************/
int Gen_ClisfileI(int argc, char **argv)
{
    int line,n,pb,com;
    char bufS[DEF_BS],inS[NSIZE],outS[NSIZE],extS[NSIZE];
    FILE *inPF, *outPF;

    sprintf(inS,"%s",INFILE_S);
    sprintf(extS,"%s",DEF_EXT_S);
    if(!ParseArgsI(argc,argv,
        "-i S -ext S",
        inS,extS,
        (int *)NULL))
    {
        Gen_ClisUse();
        return(FALSE);
    }
    if(!(inPF = OpenUFilePF(inS,"r",NULL)))
    {
        return(FALSE);
    }
    outPF = NULL;
    pb = TRUE;
    com = FALSE;
    line = n = 0;
    while(fgets(bufS,LINEGRAB,inPF) != NULL)
    {
        line++;
        if( (!com) && strstr(bufS,"/*") )
            com = TRUE;
        if( (com) && strstr(bufS,"*/") )
            com = FALSE;
        if(com)
            continue;
        if((pb) && (bufS[0] == '#'))
        {
            INIT_S(outS);
            sscanf(bufS,"# %s",outS);
            if(NO_S(outS))
            {
                printf("Error on line %d\n",line);
                printf("Need name to follow '#'\n");
                printf("ABORTING\n");
                break;
            }
            strcat(outS,".");
            strcat(outS,extS);
            if(!(outPF = OpenUFilePF(outS,"w",NULL)))
            {
                printf("ABORTING\n");
                break;
            }
            GetFilePartsI(outS,NULL,bufS,NULL);
            fprintf(outPF,"# Source listing for %s\n",bufS);
            fprintf(outPF,"# Generated by gen_clis\n");
            FillDateString(bufS);
            fprintf(outPF,"# %s\n",bufS);
            pb = FALSE;
            n++;
            continue;
        }
        if(!outPF)
        {
            continue;   
        }
        if((!isgraph(INT(bufS[0]))) || (strstr(bufS,"break")))
        {
            pb = TRUE;
            if(outPF)
            {
                FILECLOSE(outPF);
                printf("NEW FILE: %s\n",outS);
            }
            continue;
        }
        pb = FALSE;
        fputs(bufS,outPF);
    }
    if(outPF)
    {
        FILECLOSE(outPF);
        printf("NEW FILE: %s\n",outS);
    }
    FILECLOSE(inPF);
    return(TRUE);
}
