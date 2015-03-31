/*
* plot_lib.h
*
* Copyright 2015 Ryan Koehler, VerdAscend Sciences, ryan@verdascend.com
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


#define NUM_COL     250

/***
*   Data structure to hold image settings
*/
#define IMAGEPLOT_ID    6055
typedef struct IMAGEPLOT
{
    int ID;
    char outname[NSIZE];    /* Filename */
    int otype;              /* Output format */
    int oqual;              /* Output quality (for jpg) */
    int x,y;                /* X Y dims */
    int havegd;             /* Flag for GD lib datastructure */
    int havedefcol;         /* Flag for default colors */
    int havespeccol;        /* Flag for spectrum colors */
    int bgcol,fgcol;        /* Background and foreground colors */
    int ncol;               /* Number of real allocated colors */
    int colors[NUM_COL];    /* Color indices */
    int ccoff,nccol;        /* Custom color offset and number */
    int scoff,nscol;        /* Spectrum color offset and number */
    int sucol,socol;        /* Spectrum under and over color indices */
    int specx,specy;        /* Spectrum X and Y dims */
    int specw,spech;        /* Spectrum Width and Height dims */
    int spectex;            /* Spectrum text X offset */
    REAL losc,hisc,dsc;     /* Score low, hi, and diff for spectrum */
    char pnform[NSIZE];     /* Printed number formatting string */
    gdImagePtr gd;          /* D library structure pointer */
}IMAGEPLOT;

#define CHECK_IMAGEPLOT(pl) if(pl){DestroyImageplotI(pl); pl=NULL;}

#define DEF_IMPNFORM_S    "%4.2f"

#define DEF_XDIM    200
#define DEF_YDIM    200

#define DEF_SPECLO  0.0
#define DEF_SPECHI  1.0

#define DEF_SPECX   20
#define DEF_SPECY   10
#define DEF_SPECH   40
#define DEF_SPECW   100

#define MAX_COL_TRIES   10

#define GFONT_TINY      208
#define GFONT_SMALL     209
#define GFONT_MEDBOLD   210
#define GFONT_LARGE     211
#define GFONT_GIANT     212

#define PLOTOUT_PNG     233
#define PLOTOUT_JPG     234

/*********************** ppp ********************
* C function listing generated by gen_prot
* Mon Mar 23 15:11:34 2015
*/
/****************************************************************
* plot_lib.c
*/
IMAGEPLOT *CreateImageplotPO(int x,int y);
int DestroyImageplotI(IMAGEPLOT *plotPO);
void InitImageplotPars(IMAGEPLOT *plotPO);
int InitImageplotImageI(IMAGEPLOT *plotPO,int x,int y);
int SaveImageplotImageI(IMAGEPLOT *plotPO);
int GetImpageplotStatusI(IMAGEPLOT *plotPO);
void SetImageplotSpecLegDims(IMAGEPLOT *plotPO,int x,int y,int w,int h,int tex);
void SetImageplotFilename(IMAGEPLOT *plotPO,char *fileS);
void SetImageplotOutFormat(IMAGEPLOT *plotPO,int type);
void SetImageplotOutQuality(IMAGEPLOT *plotPO,int qual);
int SetImageplotDefColorsI(IMAGEPLOT *plotPO);
int SetImageplotSpecUnOvColorI(IMAGEPLOT *plotPO,int uc,int oc);
void CheckImageplotSpecUnOvCols(IMAGEPLOT *plotPO);
int SetImageplotColorI(IMAGEPLOT *plotPO,REAL rR,REAL gR,REAL bR,int ind);
int AllocGdColorI(IMAGEPLOT *plotPO,int r,int g,int b);
void SetImageplotLoHiScore(IMAGEPLOT *plotPO, REAL loR, REAL hiR);
int GetImageplotLoHiScoreI(IMAGEPLOT *plotPO,REAL *loPR, REAL *hiPR);
int GetImageplotForBackColorsI(IMAGEPLOT *plotPO,int *forPI,int *backPI);
int SetImageplotHSVSpectrumI(IMAGEPLOT *plotPO, int ncol, REAL hR, REAL sR,
    REAL vR, REAL dhR, REAL dsR,REAL dvR,int new);
int ImageplotColorForScoreI(IMAGEPLOT *plotPO, REAL scR);
void ImageplotSpectrumLegend(IMAGEPLOT *plotPO);
void ImageplotSpecLegendTex(IMAGEPLOT *plotPO, char *sS,char *eS);
void ImageplotSpecLegendColor(IMAGEPLOT *plotPO);
void ImageplotSubSpecTex(IMAGEPLOT *plotPO,char *sS);
int ImageplotTextStringI(IMAGEPLOT *plotPO, int x, int y, char *texPC, int font,
    int color, int rotate);
int ImageplotColorBoxI(IMAGEPLOT *plotPO, int x,int y,int w,int h,int color);

/****************************************************************
* plot_spec.c
*/
int SetCorrelationRWBSpectrumI(IMAGEPLOT *plotPO);
int SetCorrelationRKGSpectrumI(IMAGEPLOT *plotPO);
int SetRainbowRHighSpectrumI(IMAGEPLOT *plotPO);
int SetOrangeGreyCyanSpectrumI(IMAGEPLOT *plotPO);
int ParseRGBStringI(char *rgbS,REAL *rPR, REAL *gPR, REAL *bPR);

