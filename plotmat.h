/*
* plotmat.h
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


#define VERSION_S   "PlotMat Version 0.62"

#define PLOTMAT_ID     5121
typedef struct PLOTMAT
{
    int ID;
    char inname[NSIZE];     /* Input filename */
    int rlab,clab;          /* Flag to expect table with row/colum lables */
    char outname[NSIZE];    /* Output filename */
    struct TABLE *tab;      /* Table with numbers */
    struct IMAGEPLOT *plot; /* Plotting object */
    int xdim,ydim;          /* X Y dims for (full) plot (not just matrix) */
    int xc,yc;              /* X Y dims for matrix cells */
    int tm,bm,lm,rm;        /* Top, bottom,left, right margins */
    DOUB lo,hi;             /* Value bounds for coloring */
    int do_igd;             /* Flag to ignore diagonal */
    int do_corcol;          /* Flag for correlation coloring scheme */
    int do_corgbr;          /* Flag for correlation coloring Green Black Red */
    int do_rowlab;          /* Flag to label rows */
    int do_collab;          /* Flag to label cols */
    int do_roclab;          /* Flag rotate col labels */
    int rlab_step;          /* Row label step (i.e. plot every x'th) */
    int do_pcv;             /* Flag to print cell values */
    int do_pxv;             /* Flag to print only extreme cell values */
    DOUB do_pcr1, do_pcr2;  /* Range of values to print cell values */
    int do_pcnot;           /* Flag to invert print range; i.e. not in range */
    int pgrid;              /* Plot grid spaced every x spaces */
    int pftw,pftp;          /* Print format width and precision */
    char pnform[NSIZE];     /* Printed number formatting string */
    int rowlabw;            /* Row label width */
    int collabh;            /* Col label height */
    int do_acr;             /* Flag for auto color range */
    DOUB sd_col;            /* lag / value for color range by SD */
    int ocolor;             /* Over-range color */
    int ucolor;             /* Under-range color */
    char fcolor[DEF_BS];    /* Print cell value font color name */
    int pcvcolor;           /* Print cell value font color */
}PLOTMAT;

#define CHECK_PLOTMAT(pm)  if(pm){DestroyPlotmatI(pm); pm=NULL;}

/****
*   Def size values
*/
#define DEF_DIMS    450     /* Default plotting space dims */
#define DEF_TMAR    100     /* Top margin */
#define DEF_TMAR_NL 20      /* Top margin if no col lable */
#define DEF_BMAR    20      /* Bottom margin */
#define DEF_LMAR    20      /* Left margin */
#define DEF_RMAR    20      /* Right margin */
#define DEF_MSPACE  40
#define DEF_LEGH    20      /* Legend height */
#define DEF_LEGW    200     /* Legend width */
#define DEF_LEGY    30      
#define DEF_LEGTEX  50
#define DEF_RLABW   80      /* Row label extra width */
#define DEF_CLABH   20      /* Col label extra height */
#define DEF_RLPPC   8       /* Row label pixel per char (for auto width) */

#define ASCORE_OFF  0.0001  /* Auto score offset */

#define DEF_OUTNAME "plotmat"


/*********************** ppp ********************
* C function listing generated by gen_prot
* Thu May 15 21:33:33 2014
*/
/****************************************************************
* plotmat.c
*/
int main(int argc, char **argv);
void PlotMatUse(void);
int PlotMatI(int argc,char **argv);
PLOTMAT *CreatePlotmatPO(void);
int DestroyPlotmatI(PLOTMAT *pmPO);
void InitPlotmat(PLOTMAT *pmPO);
void SetPlotmatFormatString(PLOTMAT *pmPO);
int CheckPlotmatOptionsI(PLOTMAT *pmPO);
void FigurePlotDims(PLOTMAT *pmPO,int nr,int nc);
void ReportPlotSettings(PLOTMAT *pmPO);
int SetUpPlottingI(PLOTMAT *pmPO, char *ucolS, char *ocolS);
void SetLegendPosition(PLOTMAT *pmPO);
void SetupPlotPage(PLOTMAT *pmPO, IMAGEPLOT *plotPO);
void PlotTableOnPage(PLOTMAT *pmPO);
void PlotCellValue(PLOTMAT *pmPO, int x, int y, DOUB rD, int color);

