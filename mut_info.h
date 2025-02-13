/*
* mut_info.h
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

#ifndef __MUT_INFOH__
#define __MUT_INFOH__
#include "numlist.h"
#include "histogram.h"



/*********************** ppp ********************
* C function listing generated by gen_prot
* Sat Jul 12 15:32:31 2014
*/
/****************************************************************
* mut_info.c
*/
int NumlistMutInfoI(NUMLIST *nums1PO, NUMLIST *nums2PO, int maxb, DOUB *minfPD, 
    int *nb1PI, int *nb2PI);
int HistogramMutInfoI(HISTOGRAM *his1PO, HISTOGRAM *his2PO, DOUB *minfPD);


#endif
