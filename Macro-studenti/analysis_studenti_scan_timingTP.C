#include "Riostream.h"
// #include "fstream"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TF1.h"
#include "TMath.h"
#include "TString.h"
#include "TAxis.h"
#include "TFile.h"
// #include "vector"
#include "TStyle.h" 


//Analisi per ricavare i valori di soglie e rumore dei dati raccolti facendo variare la TPphase
//per richiamare dati a diverse frequenze guardare la funzione di analisi al fondo
//Controllare i diversi parametri per vedere se ci sono delle discrepanze tra i vari parametri 

//Inserire il parametro di analisi che si vuole effettuare:
// 0 se si vuole l'analisis su tutti i pixel del chip
// 1 se si vuole fare l'analisi di una regione di pixel
// 2 se si vuole fare l'analisi di alcune righe del chip

void TwoDim_Plots_40M_timing(Int_t i, Int_t type, Int_t min, Int_t max)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 200;
	TString file,Dir, Dir0;
	Int_t it=0;

//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";

    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;


	while ( it<20 )  {
		it++;
		if (it==i ) {

         if (it==1 ) {  par0=40; 
		 
   	   file =  "20170601004206_board8-CALsw-allch-TP200_001."; 
	   NEVT=200.;

    }
		if (it==2 ) {  par0=40; 
		 
   	   file =  "20170531191742_board8-CALsw-allch-TP400_000."; 
	   NEVT=200.;

    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170531194049_board8-CALsw-allch-TP600_000."; 
	   NEVT=200.;

    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170531200358_board8-CALsw-allch-TP800_000."; 
	   NEVT=200.;

    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170531202711_board8-CALsw-allch-TP1000_000."; 
	   NEVT=200.;

    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170601023819_board8-CALsw-allch-TP1200_001."; 
	   NEVT=200.;

    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170531211343_board8-CALsw-allch-TP1400_000."; 
	   NEVT=200.;

    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170531213700_board8-CALsw-allch-TP1600_000."; 
	   NEVT=200.;

    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170531220020_board8-CALsw-allch-TP1800_000."; 
	   NEVT=200.;

    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170531222337_board8-CALsw-allch-TP2000_000."; 
	   NEVT=200.;

    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170531224649_board8-CALsw-allch-TP2200_000."; 
	   NEVT=200.;

    }
	
	if (it==12	) {  par0=40; 
		 
   	   file =  "20170531231001_board8-CALsw-allch-TP2400_000."; 
	   NEVT=200.;

    }
	
	if (it==13	) {  par0=40; 
		 
   	   file =  "20170531233312_board8-CALsw-allch-TP2600_000."; 
	   NEVT=200.;

    }
	
	if (it==14	) {  par0=40; 
		 
   	   file =  "20170531235613_board8-CALsw-allch-TP2800_000."; 
	   NEVT=200.;

    }
	
	if (it==15	) {  par0=40; 
		 
   	   file =  "20170601001908_board8-CALsw-allch-TP3000_000."; 
	   NEVT=200.;

    }
	
	if (it==16	) {  par0=40; 
		 
   	   file =  "20170706095228_board8-CALsw-allch-TP3200_002."; 
	   NEVT=200.;

    }
	
	if (it==17	) {  par0=40; 
		 
   	   file =  "20170706111354_board8-CALsw-allch-TP3400_004."; 
	   NEVT=200.;

    }
	
	if (it==18	) {  par0=40; 
		 
   	   file =  "20170706112546_board8-CALsw-allch-TP3600_004."; 
	   NEVT=200.;

    }
	
	Dir = Dir0+"";	
	
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    analisiMC(Dir,file,60,20,80,1.,4.,type,min,max); 

	}
	//FileOutRes(Dir,file,i);
	}
}


/*
//Dati presi facendo variare la tensione ad un diverso valore di corrente di scarica Ifeed = 160 DAC
void TwoDim_Plots_If160_timing(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;
//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl350/";
    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan-40MHz-Ifeed160/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
	while ( it<20 )  {
		it++;
		
	if (it==i ) {
			
	if (it==1 ) {  par0=40; 
		 
   	   file =  "20170623123707_board8-CALsw-allch-If160-TP200_002."; 
	   NEVT=50.;
    }
	
	if (it==2 ) {  par0=40; 
		 
   	   file =  "20170623125058_board8-CALsw-allch-If160-TPphase400_002."; 
	   NEVT=50.;
    }
	
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170623130449_board8-CALsw-allch-If160-TPphase600_002."; 
	   NEVT=50.;
    }
	
	if (it==4 ) {  par0=40; 
		 
   	   file =  "20170623131848_board8-CALsw-allch-If160-TPphase800_002."; 
	   NEVT=50.;
    }
	
	if (it==5 ) {  par0=40; 
		 
   	   file =  "20170623133255_board8-CALsw-allch-If160-TPphase1000_002."; 
	   NEVT=50.;
    }
    if (it==6 ) {  par0=40; 
		 
   	   file =  "220170614222316_board8-CALsw-allch-TP1200_001."; 
	   NEVT=50.;
    }
    
	if (it==7 ) {  par0=40; 
		 
   	   file =  "20170614223825_board8-CALsw-allch-TP1400_001."; 
	   NEVT=50.;
    }
	if (it==8 ) {  par0=40; 
		 
   	   file =  "20170614224900_board8-CALsw-allch-TP1600_001."; 
	   NEVT=50.;
    }
	
	if (it==9	) {  par0=40; 
		 
   	   file =  "20170614225947_board8-CALsw-allch-TP1800_001."; 
	   NEVT=50.;
    }
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170615021655_board8-CALsw-allch-TP2000_002."; 
	   NEVT=50.;
    }
	
	if (it==11 ) {  par0=40; 
		 
   	   file =  "20170615022743_board8-CALsw-allch-TP2200_002."; 
	   NEVT=50.;
    }
	if (it==12	) {  par0=40; 
		 
   	   file =  "20170614233152_board8-CALsw-allch-TP2400_001."; 
	   NEVT=50.;
    }
	
	
	if (it==13	) {  par0=40; 
		 
   	   file =  "20170614234238_board8-CALsw-allch-TP2600_001."; 
	   NEVT=50.;
    }
	
    if (it==14	) {  par0=40; 
		 
   	   file =  "20170614235323_board8-CALsw-allch-TP2800_001."; 
	   NEVT=50.;
    }
	
	if (it==15	) {  par0=40; 
		 
   	   file =  "20170615000402_board8-CALsw-allch-TP3000_001."; 
	   NEVT=50.;
    }
	
	if (it==16	) {  par0=40; 
		 
   	   file =  "20170614215338_board8-CALsw-allch-TP3600_001."; 
	   NEVT=50.;
    }
	
	if (it==17 ) {  par0=40; 
		 
   	   file =  "20170623134706_board8-CALsw-allch-If160-TPphase3200_002."; 
	   NEVT=50.;
    }
	
	if (it==18 ) {  par0=40; 
		 
   	   file =  "20170623105900_board8-CALsw-allch-Pmezzi-TPphase3400_000."; 
	   NEVT=50.;
    }
	
	if (it==19 ) {  par0=40; 
		 
   	   file =  "20170615012926_board8-CALsw-allch-TP1200_002."; 
	   NEVT=50.;
    }
	
	Dir = Dir0+"";	
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    analisiMC(Dir,file,60,20,80,1.,4.,type,min,max); 
	}
	}
}
void TwoDim_Plots_If40_timing(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;
//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl350/";
    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan-40MHz-Ifeed40/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
	while ( it<20 )  {
		it++;
		if (it==i ) {
         if (it==1 ) {  par0=40; 
		 
   	   file =  "20170615210326_board8-CALsw-allch-i40-TP200_003."; 
	   NEVT=50.;
    }
		if (it==2 ) {  par0=40; 
		 
   	   file =  "20170615211500_board8-CALsw-allch-i40-TP400_003."; 
	   NEVT=50.;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170615212701_board8-CALsw-allch-i40-TP600_003."; 
	   NEVT=50.;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170615213127_board8-CALsw-allch-i40-TP800_003."; 
	   NEVT=50.;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170615214253_board8-CALsw-allch-i40-TP1000_003."; 
	   NEVT=50.;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170615215454_board8-CALsw-allch-i40-TP12000_003."; 
	   NEVT=50.;
    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170615220656_board8-CALsw-allch-i40-TP1400_003."; 
	   NEVT=50.;
    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170615221527_board8-CALsw-allch-i40-TP1600_003."; 
	   NEVT=50.;
    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170615222400_board8-CALsw-allch-i40-TP1800_003."; 
	   NEVT=50.;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170615223232_board8-CALsw-allch-i40-TP2000_003."; 
	   NEVT=50.;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170615224104_board8-CALsw-allch-i40-TP2200_003."; 
	   NEVT=50.;
    }
	
	if (it==12 ) {  par0=40; 
		 
   	   file =  "20170615224934_board8-CALsw-allch-i40-TP2400_003."; 
	   NEVT=50.;
    }
	
	if (it==13 ) {  par0=40; 
		 
   	   file =  "20170615225805_board8-CALsw-allch-i40-TP2600_003."; 
	   NEVT=50.;
    }
	
	if (it==14 ) {  par0=40; 
		 
   	   file =  "20170615230636_board8-CALsw-allch-i40-TP2800_003."; 
	   NEVT=50.;
    }
	
	if (it==15 ) {  par0=40; 
		 
   	   file =  "20170615231507_board8-CALsw-allch-i40-TP3000_003."; 
	   NEVT=50.;
    }
	
	if (it==16 ) {  par0=40; 
		 
   	   file =  "20170626142315_board8-CALsw-allch-i40-TP3200_000."; 
	   NEVT=50.;
    }
	
	if (it==17 ) {  par0=40; 
		 
   	   file =  "20170626143520_board8-CALsw-allch-i40-TP3400_000."; 
	   NEVT=50.;
    }
	
	if (it==18 ) {  par0=40; 
		 
   	   file =  "20170626144725_board8-CALsw-allch-i40-TP3600_000."; 
	   NEVT=50.;
    }
	
	Dir = Dir0+"";	
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    analisiMC(Dir,file,100,20,120,1.,8.,0); 
	}
	}
}
void TwoDim_Plots_If10_timing(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;
//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl350/";
    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan-40MHz-Ifeed10/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
	while ( it<20 )  {
		it++;
		if (it==i ) {
         if (it==1 ) {  par0=40; 
		 
   	   file =  "20170620025444_board8-CALsw-allch-i10-TP0_004."; 
	   NEVT=50.;
    }
		if (it==2 ) {  par0=40; 
		 
   	   file =  "20170620024520_board8-CALsw-allch-i10-TP200_004."; 
	   NEVT=50.;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170620023611_board8-CALsw-allch-i10-TP400_004."; 
	   NEVT=50.;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170620023609_board8-CALsw-allch-i10-TP600_004."; 
	   NEVT=50.;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170622124715_board8-CALsw-allch-If10-TPphase800_000."; 
	   NEVT=50.;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170622130007_board8-CALsw-allch-If10-TPphase1000_000."; 
	   NEVT=50.;
    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170622131150_board8-CALsw-allch-If10-TPphase1200_000."; 
	   NEVT=50.;
    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170622132338_board8-CALsw-allch-If10-TPphase1400_000."; 
	   NEVT=50.;
    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170622133223_board8-CALsw-allch-If10-TPphase1600_000."; 
	   NEVT=50.;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170622134120_board8-CALsw-allch-If10-TPphase1800_000."; 
	   NEVT=50.;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170622135005_board8-CALsw-allch-If10-TPphase2000_000."; 
	   NEVT=50.;
    }
	
	if (it==12 ) {  par0=40; 
		 
   	   file =  "20170622135909_board8-CALsw-allch-If10-TPphase2200_000."; 
	   NEVT=50.;
    }
	
	if (it==13 ) {  par0=40; 
		 
   	   file =  "20170622140812_board8-CALsw-allch-If10-TPphase2400_000."; 
	   NEVT=50.;
    }
	
	if (it==14 ) {  par0=40; 
		 
   	   file =  "20170622141700_board8-CALsw-allch-If10-TPphase2600_000."; 
	   NEVT=50.;
    }
	
	if (it==15 ) {  par0=40; 
		 
   	   file =  "20170622142549_board8-CALsw-allch-If10-TPphase2800_000."; 
	   NEVT=50.;
    }
	
	if (it==16 ) {  par0=40; 
		 
   	   file =  "20170622143430_board8-CALsw-allch-If10-TPphase3000_000."; 
	   NEVT=50.;
    }
	
	if (it==17 ) {  par0=40; 
		 
   	   file =  "20170620044544_board8-CALsw-allch-i10-TP3200_006."; 
	   NEVT=50.;
    }
	
	if (it==18 ) {  par0=40; 
		 
   	   file =  "20170620020914_board8-CALsw-allch-i10-TP3400_004."; 
	   NEVT=50.;
    }
	
	if (it==19 ) {  par0=40; 
		 
   	   file =  "20170620015557_board8-CALsw-allch-i10-TP3600_004."; 
	   NEVT=50.;
    }
	
	Dir = Dir0+"";	
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    analisiMC(Dir,file,100,20,120,1.,8.,0); 
	}
	}
}
void TwoDim_Plots_C4F_timing(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;
//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl350/";
    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan-40MHz-C4F/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
	while ( it<20 )  {
		it++;
		if (it==i ) {
         if (it==1 ) {  par0=40; 
		 
   	   file =  "20170622001007_board8-CALsw-allch-C4F-TP200_004."; 
	   NEVT=50.;
    }
		if (it==2 ) {  par0=40; 
		 
   	   file =  "20170622002334_board8-CALsw-allch-C4F-TPphase400_004."; 
	   NEVT=50.;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170622003656_board8-CALsw-allch-C4F-TPphase600_004."; 
	   NEVT=50.;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170622005022_board8-CALsw-allch-C4F-TPphase800_004."; 
	   NEVT=50.;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170622010348_board8-CALsw-allch-C4F-TPphase1000_004."; 
	   NEVT=50.;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170622011717_board8-CALsw-allch-C4F-TPphase1200_004."; 
	   NEVT=50.;
    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170622013048_board8-CALsw-allch-C4F-TPphase1400_004."; 
	   NEVT=50.;
    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170622014025_board8-CALsw-allch-C4F-TPphase1600_004."; 
	   NEVT=50.;
    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170622014946_board8-CALsw-allch-C4F-TPphase1800_004."; 
	   NEVT=50.;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170622015920_board8-CALsw-allch-C4F-TPphase2000_004."; 
	   NEVT=50.;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170622020853_board8-CALsw-allch-C4F-TPphase2200_004."; 
	   NEVT=50.;
    }
	
	if (it==12 ) {  par0=40; 
		 
   	   file =  "20170622021826_board8-CALsw-allch-C4F-TPphase2400_004."; 
	   NEVT=50.;
    }
	
	if (it==13 ) {  par0=40; 
		 
   	   file =  "20170622022742_board8-CALsw-allch-C4F-TPphase2600_004."; 
	   NEVT=50.;
    }
	
	if (it==14 ) {  par0=40; 
		 
   	   file =  "20170622023654_board8-CALsw-allch-C4F-TPphase2800_004."; 
	   NEVT=50.;
    }
	
	if (it==15 ) {  par0=40; 
		 
   	   file =  "20170621232704_board8-CALsw-allch-C4F-TPphase3000_003."; 
	   NEVT=50.;
    }
	
	if (it==16 ) {  par0=40; 
		 
   	   file =  "20170621233627_board8-CALsw-allch-C4F-TPphase3200_003."; 
	   NEVT=50.;
    }
	
	if (it==17 ) {  par0=40; 
		 
   	   file =  "20170621234559_board8-CALsw-allch-C4F-TPphase3400_003."; 
	   NEVT=50.;
    }
	
	if (it==18 ) {  par0=40; 
		 
   	   file =  "20170621235530_board8-CALsw-allch-C4F-TPphase3600_003."; 
	   NEVT=50.;
    }
	
	if (it==19 ) {  par0=40; 
		 
   	   file =  "20170622064647_board8-CALsw-allch-C4F-TPphase0_005."; 
	   NEVT=50.;
    }
	
	Dir = Dir0+"";	
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    analisiMC(Dir,file,100,20,120,1.,8.,0); 
	}
	}
}
void TwoDim_Plots_Vth90_timing(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;
//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl350/";
    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan-40MHz-Vth90/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
	while ( it<20 )  {
		it++;
		if (it==i ) {
         if (it==1 ) {  par0=40; 
		 
   	   file =  "20170620233859_board8-CALsw-allch-Vth90-TP200_002."; 
	   NEVT=50.;
    }
		if (it==2 ) {  par0=40; 
		 
   	   file =  "20170620235205_board8-CALsw-allch-Vth90-TPphase400_002."; 
	   NEVT=50.;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170621000513_board8-CALsw-allch-Vth90-TPphase600_002."; 
	   NEVT=50.;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170621001803_board8-CALsw-allch-Vth90-TPphase800_002."; 
	   NEVT=50.;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170621003113_board8-CALsw-allch-Vth90-TPphase1000_002."; 
	   NEVT=50.;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170620213201_board8-CALsw-allch-Vth90-TPphase1200_001."; 
	   NEVT=50.;
    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170621005721_board8-CALsw-allch-Vth90-TPphase1400_002."; 
	   NEVT=50.;
    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170621010624_board8-CALsw-allch-Vth90-TPphase1600_002."; 
	   NEVT=50.;
    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170621011542_board8-CALsw-allch-Vth90-TPphase1800_002."; 
	   NEVT=50.;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170621012502_board8-CALsw-allch-Vth90-TPphase2000_002."; 
	   NEVT=50.;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170621044018_board8-CALsw-allch-Vth90-TPphase2200_003."; 
	   NEVT=50.;
    }
	
	if (it==12 ) {  par0=40; 
		 
   	   file =  "20170621044917_board8-CALsw-allch-Vth90-TPphase2400_003."; 
	   NEVT=50.;
    }
	
	if (it==13 ) {  par0=40; 
		 
   	   file =  "20170621014615_board8-CALsw-allch-Vth90-TPphase2600_002."; 
	   NEVT=50.;
    }
	
	if (it==14 ) {  par0=40; 
		 
   	   file =  "20170621015525_board8-CALsw-allch-Vth90-TPphase2800_002."; 
	   NEVT=50.;
    }
	
	if (it==15 ) {  par0=40; 
		 
   	   file =  "20170621020415_board8-CALsw-allch-Vth90-TPphase3000_002."; 
	   NEVT=50.;
    }
	
	if (it==16 ) {  par0=40; 
		 
   	   file =  "20170621021323_board8-CALsw-allch-Vth90-TPphase3200_002."; 
	   NEVT=50.;
    }
	
	if (it==17 ) {  par0=40; 
		 
   	   file =  "20170621022231_board8-CALsw-allch-Vth90-TPphase3400_002."; 
	   NEVT=50.;
    }
	
	if (it==18 ) {  par0=40; 
		 
   	   file =  "20170620232446_board8-CALsw-allch-Vth90-TPphase3600_001."; 
	   NEVT=50.;
    }
	
	if (it==19 ) {  par0=40; 
		 
   	   file =  "20170621024437_board8-CALsw-allch-Vth90-TPphase0_002."; 
	   NEVT=50.;
    }
	
	
	Dir = Dir0+"";	
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    analisiMC(Dir,file,100,20,120,1.,8.,0); 
	}
	}
}
void TwoDim_Plots_Vth90_timing(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;
//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl350/";
    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan-40MHz-Vth90/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
	while ( it<20 )  {
		it++;
		if (it==i ) {
         if (it==1 ) {  par0=40; 
		 
   	   file =  "20170627091851_board8-CALsw-allch-Vth90-TP200_000."; 
	   NEVT=50.;
    }
		if (it==2 ) {  par0=40; 
		 
   	   file =  "20170627093232_board8-CALsw-allch-Vth90-TP400_000."; 
	   NEVT=50.;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170627094604_board8-CALsw-allch-Vth90-TP600_000."; 
	   NEVT=50.;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170627095939_board8-CALsw-allch-Vth90-TP800_000."; 
	   NEVT=50.;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170627101346_board8-CALsw-allch-Vth90-TP1000_000."; 
	   NEVT=50.;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170627102005_board8-CALsw-allch-Vth90-TP1200_000."; 
	   NEVT=50.;
    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170627103413_board8-CALsw-allch-Vth90-TP1400_000."; 
	   NEVT=50.;
    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170627104405_board8-CALsw-allch-Vth90-TP1600_000."; 
	   NEVT=50.;
    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170627105359_board8-CALsw-allch-Vth90-TP1800_000."; 
	   NEVT=50.;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170627130036_board8-CALsw-allch-Vth90-TP2000_000."; 
	   NEVT=50.;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170627131005_board8-CALsw-allch-Vth90-TP2200_000."; 
	   NEVT=50.;
    }
	
	if (it==12 ) {  par0=40; 
		 
   	   file =  "20170627131954_board8-CALsw-allch-Vth90-TP2400_000."; 
	   NEVT=50.;
    }
	
	if (it==13 ) {  par0=40; 
		 
   	   file =  "20170627132942_board8-CALsw-allch-Vth90-TP2600_000."; 
	   NEVT=50.;
    }
	
	if (it==14 ) {  par0=40; 
		 
   	   file =  "20170627133928_board8-CALsw-allch-Vth90-TP2800_000."; 
	   NEVT=50.;
    }
	
	if (it==15 ) {  par0=40; 
		 
   	   file =  "20170627134912_board8-CALsw-allch-Vth90-TP3000_000."; 
	   NEVT=50.;
    }
	
	if (it==16 ) {  par0=40; 
		 
   	   file =  "20170621021323_board8-CALsw-allch-Vth90-TPphase3200_002."; 
	   NEVT=50.;
    }
	
	if (it==17 ) {  par0=40; 
		 
   	   file =  "20170621022231_board8-CALsw-allch-Vth90-TPphase3400_002."; 
	   NEVT=50.;
    }
	
	if (it==18 ) {  par0=40; 
		 
   	   file =  "20170620232446_board8-CALsw-allch-Vth90-TPphase3600_001."; 
	   NEVT=50.;
    }
	
	if (it==19 ) {  par0=40; 
		 
   	   file =  "20170621024437_board8-CALsw-allch-Vth90-TPphase0_002."; 
	   NEVT=50.;
    }
	
	
	Dir = Dir0+"";	
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    analisiMC(Dir,file,100,20,120,1.,8.,0); 
	}
	}
}
void TwoDim_Plots_Pmezzi_timing(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;
//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl350/";
    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan-40MHz-Pmezzi/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
	while ( it<20 )  {
		it++;
		if (it==i ) {
         if (it==1 ) {  par0=40; 
		 
   	   file =  "20170622231341_board8-CALsw-allch-Pmezzi-TP200_002."; 
	   NEVT=50.;
    }
		if (it==2 ) {  par0=40; 
		 
   	   file =  "20170622232733_board8-CALsw-allch-Pmezzi-TPphase400_002."; 
	   NEVT=50.;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170622234124_board8-CALsw-allch-Pmezzi-TPphase600_002."; 
	   NEVT=50.;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170623032003_board8-CALsw-allch-Pmezzi-TPphase800_003."; 
	   NEVT=50.;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170623000905_board8-CALsw-allch-Pmezzi-TPphase1000_002."; 
	   NEVT=50.;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170623002256_board8-CALsw-allch-Pmezzi-TPphase1200_002."; 
	   NEVT=50.;
    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170623003644_board8-CALsw-allch-Pmezzi-TPphase1400_002."; 
	   NEVT=50.;
    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170623004629_board8-CALsw-allch-Pmezzi-TPphase1600_002."; 
	   NEVT=50.;
    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170623005614_board8-CALsw-allch-Pmezzi-TPphase1800_002."; 
	   NEVT=50.;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170623010556_board8-CALsw-allch--TPphase2000_002."; 
	   NEVT=50.;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170623011538_board8-CALsw-allch-Pmezzi-TPphase2200_002."; 
	   NEVT=50.;
    }
	
	if (it==12 ) {  par0=40; 
		 
   	   file =  "20170623012517_board8-CALsw-allch-Pmezzi-TPphase2400_002."; 
	   NEVT=50.;
    }
	
	if (it==13 ) {  par0=40; 
		 
   	   file =  "20170623013456_board8-CALsw-allch-Pmezzi-TPphase2600_002."; 
	   NEVT=50.;
    }
	
	if (it==14 ) {  par0=40; 
		 
   	   file =  "20170623014435_board8-CALsw-allch-Pmezzi-TPphase2800_002."; 
	   NEVT=50.;
    }
	
	if (it==15 ) {  par0=40; 
		 
   	   file =  "20170623015417_board8-CALsw-allch-Pmezzi-TPphase3000_002."; 
	   NEVT=50.;
    }
	
	if (it==16 ) {  par0=40; 
		 
   	   file =  "20170623020401_board8-CALsw-allch-Pmezzi-TPphase3200_002."; 
	   NEVT=50.;
    }
	
	if (it==17 ) {  par0=40; 
		 
   	   file =  "20170623021344_board8-CALsw-allch-Pmezzi-TPphase3400_002."; 
	   NEVT=50.;
    }
	
	if (it==18 ) {  par0=40; 
		 
   	   file =  "20170623022328_board8-CALsw-allch-Pmezzi-TPphase3600_002."; 
	   NEVT=50.;
    }
	
	if (it==19 ) {  par0=40; 
		 
   	   file =  "20170623023717_board8-CALsw-allch-Pmezzi-TPphase0_002."; 
	   NEVT=50.;
    }
	
	Dir = Dir0+"";	
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    analisiMC(Dir,file,100,20,120,1.,8.,0); 
	}
	}
}
void TwoDim_Plots_Pdoppi_timing(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;
//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl350/";
    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan-40MHz-Pdoppi/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
	while ( it<20 )  {
		it++;
		if (it==i ) {
         if (it==1 ) {  par0=40; 
		 
   	   file =  "20170627211603_board8-CALsw-allch-Pdoppi-TP200_002."; 
	   NEVT=50.;
    }
		if (it==2 ) {  par0=40; 
		 
   	   file =  "20170627212951_board8-CALsw-allch-Pdoppi-TP400_002."; 
	   NEVT=50.;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170627214344_board8-CALsw-allch-Pdoppi-TP600_002."; 
	   NEVT=50.;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170627215732_board8-CALsw-allch-Pdoppi-TP800_002."; 
	   NEVT=50.;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170627221126_board8-CALsw-allch-Pdoppi-TP1000_002."; 
	   NEVT=50.;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170627222547_board8-CALsw-allch-Pdoppi-TP1200_002."; 
	   NEVT=50.;
    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170627223938_board8-CALsw-allch-Pdoppi-TP1400_002."; 
	   NEVT=50.;
    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170627224945_board8-CALsw-allch-Pdoppi-TP1600_002."; 
	   NEVT=50.;
    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170627225935_board8-CALsw-allch-Pdoppi-TP1800_002."; 
	   NEVT=50.;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170627194929_board8-CALsw-allch-Pdoppi-TP2000_001."; 
	   NEVT=50.;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170627231913_board8-CALsw-allch-Pdoppi-TP2200_002."; 
	   NEVT=50.;
    }
	
	if (it==12 ) {  par0=40; 
		 
   	   file =  "20170627232901_board8-CALsw-allch-Pdoppi-TP2400_002."; 
	   NEVT=50.;
    }
	
	if (it==13 ) {  par0=40; 
		 
   	   file =  "20170627233851_board8-CALsw-allch-Pdoppi-TP2600_002."; 
	   NEVT=50.;
    }
	
	if (it==14 ) {  par0=40; 
		 
   	   file =  "20170627234840_board8-CALsw-allch-Pdoppi-TP2800_002."; 
	   NEVT=50.;
    }
	
	if (it==15 ) {  par0=40; 
		 
   	   file =  "20170627235823_board8-CALsw-allch-Pdoppi-TP3000_002."; 
	   NEVT=50.;
    }
	
	if (it==16 ) {  par0=40; 
		 
   	   file =  "20170628032854_board8-CALsw-allch-Pdoppi-TP3200_003."; 
	   NEVT=50.;
    }
	
	if (it==17 ) {  par0=40; 
		 
   	   file =  "20170628001813_board8-CALsw-allch-Pdoppi-TP3400_002."; 
	   NEVT=50.;
    }
	
	if (it==18 ) {  par0=40; 
		 
   	   file =  "20170627174715_board8-CALsw-allch-Pdoppi-TP3600_000."; 
	   NEVT=50.;
    }
	
	
	Dir = Dir0+"";	
//    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    analisiMC(Dir,file,100,20,120,1.,8.,0); 
	}
	}
}
void TwoDim_Plots_20M_timing(Int_t i, Int_t type, Int_t min, Int_t max)
//void TwoDim_Plots_20M_timing(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;
//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";
    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan-20MHz/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
	while ( it<20 )  {
		it++;
		if (it==i ) {
     if (it==1 ) {  par0=40; 
		 
   	   file =  "20170608233903_board8-CALsw-allch-TP200_001."; 
	   NEVT=50.;
    }
	if (it==2 ) {  par0=40; 
		 
   	   file =  "20170608235649_board8-CALsw-allch-TP400_001."; 
	   NEVT=50.;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170609001415_board8-CALsw-allch-TP600_001."; 
	   NEVT=50.;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170609003143_board8-CALsw-allch-TP800_001."; 
	   NEVT=50.;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170609004912_board8-CALsw-allch-TP1000_001."; 
	   NEVT=50.;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170609010658_board8-CALsw-allch-TP1200_001."; 
	   NEVT=50.;
    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170609012448_board8-CALsw-allch-TP1400_001."; 
	   NEVT=50.;
    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170609013731_board8-CALsw-allch-TP1600_001."; 
	   NEVT=50.;
    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170609015016_board8-CALsw-allch-TP1800_001."; 
	   NEVT=50.;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170609020307_board8-CALsw-allch-TP2000_001."; 
	   NEVT=50.;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170609021557_board8-CALsw-allch-TP2200_001."; 
	   NEVT=50.;
    }
	
	if (it==12	) {  par0=40; 
		 
   	   file =  "20170609022853_board8-CALsw-allch-TP2400_001."; 
	   NEVT=50.;
    }
	
	if (it==13	) {  par0=40; 
		 
   	   file =  "20170609024149_board8-CALsw-allch-TP2600_001."; 
	   NEVT=50.;
    }
	
	if (it==14	) {  par0=40; 
		 
   	   file =  "20170609025448_board8-CALsw-allch-TP2800_001."; 
	   NEVT=50.;
		NEVT=50.;
    }
	
	if (it==15	) {  par0=40; 
		 
   	   file =  "20170609030746_board8-CALsw-allch-TP3000_001."; 
	   NEVT=50.;
		NEVT=50.;
    }
	
	if (it==16	) {  par0=40; 
		 
   	   file =  "20170609155821_board8-CALsw-allch-TP3200_000."; 
	   NEVT=50.;
		
    }
	
	if (it==17	) {  par0=40; 
		 
   	   file =  "20170609161543_board8-CALsw-allch-TP3400_000."; 
	   NEVT=50.;
		
    }
	
	if (it==18	) {  par0=40; 
		 
   	   file =  "20170609163253_board8-CALsw-allch-TP3600_000."; 
	   NEVT=50.;
		
    }
	
	Dir = Dir0+"";	
    //Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	//analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    analisiMC(Dir,file,60,20,80,1.,4.,type,min,max);
	//analisiMC(Dir,file,100,20,120,1.,8.); 	
	}
	}
}
//void TwoDim_Plots_If40_20M_timing(Int_t i, Int_t type, Int_t min, Int_t max)
void TwoDim_Plots_If40_20M_timing(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;
//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";
    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan-20MHz-Ifeed40/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
	while ( it<20 )  {
		it++;
		if (it==i ) {
     if (it==1 ) {  par0=40; 
		 
   	   file =  "20170629101803_board8-CALsw-allch-If40-TP200_000."; 
	   NEVT=50.;
    }
	if (it==2 ) {  par0=40; 
		 
   	   file =  "20170629103658_board8-CALsw-allch-If40-TP400_000."; 
	   NEVT=50.;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170629105551_board8-CALsw-allch-If40-TP600_000."; 
	   NEVT=50.;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170629111430_board8-CALsw-allch-If40-TP800_000."; 
	   NEVT=50.;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170629113321_board8-CALsw-allch-If40-TP1000_000."; 
	   NEVT=50.;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170629115216_board8-CALsw-allch-If40-TP1200_000."; 
	   NEVT=50.;
    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170629121112_board8-CALsw-allch-If40-TP1400_000."; 
	   NEVT=50.;
    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170629122443_board8-CALsw-allch-If40-TP1600_000."; 
	   NEVT=50.;
    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170629123806_board8-CALsw-allch-If40-TP1800_000."; 
	   NEVT=50.;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170629125136_board8-CALsw-allch-If40-TP2000_000."; 
	   NEVT=50.;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170629130507_board8-CALsw-allch-If40-TP2200_000."; 
	   NEVT=50.;
    }
	
	if (it==12	) {  par0=40; 
		 
   	   file =  "20170629131837_board8-CALsw-allch-If40-TP2400_000."; 
	   NEVT=50.;
    }
	
	if (it==13	) {  par0=40; 
		 
   	   file =  "20170629133201_board8-CALsw-allch-If40-TP2600_000."; 
	   NEVT=50.;
    }
	
	if (it==14	) {  par0=40; 
		 
   	   file =  "20170629134536_board8-CALsw-allch-If40-TP2800_000."; 
	   NEVT=50.;
		NEVT=50.;
    }
	
	if (it==15	) {  par0=40; 
		 
   	   file =  "20170629135906_board8-CALsw-allch-If40-TP3000_000."; 
	   NEVT=50.;
		NEVT=50.;
    }
	
	if (it==16	) {  par0=40; 
		 
   	   file =  "20170629141239_board8-CALsw-allch-If40-TP3200_000."; 
	   NEVT=50.;
		
    }
	
	if (it==17	) {  par0=40; 
		 
   	   file =  "20170629185731_board8-CALsw-allch-If40-TP3400_001."; 
	   NEVT=50.;
		
    }
	
	if (it==18	) {  par0=40; 
		 
   	   file =  "20170629190851_board8-CALsw-allch-If40-TP3600_001."; 
	   NEVT=50.;
		
    }
	
	Dir = Dir0+"";	
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    //analisiMC(Dir,file,60,20,80,1.,4.,type,min,max);
	analisiMC(Dir,file,100,20,120,1.,8.); 	
	}
	}
}
void TwoDim_Plots_Pdoppi_20M_timing(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;
//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";
    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan-20MHz-Pdoppi/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
	while ( it<20 )  {
		it++;
		if (it==i ) {
     if (it==1 ) {  par0=40; 
		 
   	   file =  "20170628135604_board8-CALsw-allch-Pdoppi-TP200_001."; 
	   NEVT=50.;
    }
	if (it==2 ) {  par0=40; 
		 
   	   file =  "20170628141435_board8-CALsw-allch-Pdoppi-TP400_001."; 
	   NEVT=50.;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170628143255_board8-CALsw-allch-Pdoppi-TP600_001."; 
	   NEVT=50.;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170628145107_board8-CALsw-allch-Pdoppi-TP800_001."; 
	   NEVT=50.;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170628150927_board8-CALsw-allch-Pdoppi-TP1000_001."; 
	   NEVT=50.;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170628152811_board8-CALsw-allch-Pdoppi-TP1200_001."; 
	   NEVT=50.;
    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170628154654_board8-CALsw-allch-Pdoppi-TP1400_001."; 
	   NEVT=50.;
    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170628160015_board8-CALsw-allch-Pdoppi-TP1600_001."; 
	   NEVT=50.;
    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170628161337_board8-CALsw-allch-Pdoppi-TP1800_001."; 
	   NEVT=50.;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170628162701_board8-CALsw-allch-Pdoppi-TP2000_001."; 
	   NEVT=50.;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170628164028_board8-CALsw-allch-Pdoppi-TP2200_001."; 
	   NEVT=50.;
    }
	
	if (it==12	) {  par0=40; 
		 
   	   file =  "20170628165355_board8-CALsw-allch-Pdoppi-TP2400_001."; 
	   NEVT=50.;
    }
	
	if (it==13	) {  par0=40; 
		 
   	   file =  "20170628170725_board8-CALsw-allch-Pdoppi-TP2600_001."; 
	   NEVT=50.;
    }
	
	if (it==14	) {  par0=40; 
		 
   	   file =  "20170628172050_board8-CALsw-allch-Pdoppi-TP2800_001."; 
	   NEVT=50.;
		
    }
	
	if (it==15	) {  par0=40; 
		 
   	   file =  "20170628173422_board8-CALsw-allch-Pdoppi-TP3000_001."; 
	   NEVT=50.;
		
    }
	
	if (it==16	) {  par0=40; 
		 
   	   file =  "20170628174753_board8-CALsw-allch-Pdoppi-TP3200_001."; 
	   NEVT=50.;
		
    }
	
	if (it==17	) {  par0=40; 
		 
   	   file =  "20170628133153_board8-CALsw-allch-Pdoppi-TP3400_000."; 
	   NEVT=50.;
		
    }
	
	if (it==18	) {  par0=40; 
		 
   	   file =  "20170628181245_board8-CALsw-allch-Pdoppi-TP3600_001."; 
	   NEVT=50.;
		
    }
	
	Dir = Dir0+"";	
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    //analisiMC(Dir,file,60,20,80,1.,4.,type,min,max);
	analisiMC(Dir,file,100,20,120,1.,8.); 	
	}
	}
}
void TwoDim_Plots_Vthchange_20M_timing(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;
//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";
    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-VTHSCAN-std-956mV-VDD/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
	while ( it<20 )  {
		it++;
		if (it==i ) {
     if (it==1 ) {  par0=40; 
		 
   	   file =  "20170712221639_board8-VTHsw-allch-TP200_001."; 
	   NEVT=50.;
    }
	if (it==2 ) {  par0=40; 
		 
   	   file =  "20170712223732_board8-VTHsw-allch-TP400_001."; 
	   NEVT=50.;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170712225814_board8-VTHsw-allch-TP600_001."; 
	   NEVT=50.;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170712231852_board8-VTHsw-allch-TP800_001."; 
	   NEVT=50.;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170712233936_board8-VTHsw-allch-TP1000_001."; 
	   NEVT=50.;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170713000027_board8-VTHsw-allch-TP1200_001."; 
	   NEVT=50.;
    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170713002113_board8-VTHsw-allch-TP1400_001."; 
	   NEVT=50.;
    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170713004212_board8-VTHsw-allch-TP1600_001."; 
	   NEVT=50.;
    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170713010313_board8-VTHsw-allch-TP1800_001."; 
	   NEVT=50.;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170713012418_board8-VTHsw-allch-TP2000_001."; 
	   NEVT=50.;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170713014525_board8-VTHsw-allch-TP2200_001."; 
	   NEVT=50.;
    }
	
	if (it==12	) {  par0=40; 
		 
   	   file =  "20170713020636_board8-VTHsw-allch-TP2400_001."; 
	   NEVT=50.;
    }
	
	if (it==13	) {  par0=40; 
		 
   	   file =  "20170713022747_board8-VTHsw-allch-TP2600_001."; 
	   NEVT=50.;
    }
	
	if (it==14	) {  par0=40; 
		 
   	   file =  "20170713024903_board8-VTHsw-allch-TP2800_001."; 
	   NEVT=50.;
		
    }
	
	if (it==15	) {  par0=40; 
		 
   	   file =  "20170713031020_board8-VTHsw-allch-TP3000_001."; 
	   NEVT=50.;
		
    }
	
	if (it==16	) {  par0=40; 
		 
   	   file =  "20170713033135_board8-VTHsw-allch-TP3200_001."; 
	   NEVT=50.;
		
    }
	
	if (it==17	) {  par0=40; 
		 
   	   file =  "20170713035255_board8-VTHsw-allch-TP3400_001."; 
	   NEVT=50.;
		
    }
	
	if (it==18	) {  par0=40; 
		 
   	   file =  "20170713041027_board8-VTHsw-allch-TP3600_001."; 
	   NEVT=50.;
		
    }
	
	Dir = Dir0+"";	
    Macro_scurve_Vth(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    //analisiMC(Dir,file,60,20,80,1.,4.,type,min,max);
	analisiMC(Dir,file,100,40,180,1.,8.); 	
	}
	}
}
*/

void TwoDim_Plots_Vthchange1200_20M_timing(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;

//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";

    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-VTHSCAN-std-1200mV-VDD/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;


	while ( it<20 )  {
		it++;
		if (it==i ) {

     if (it==1 ) {  par0=40; 
		 
   	   file =  "20170713214516_board8-VTHsw-allch-TP200_002."; 
	   NEVT=50.;
    }
	if (it==2 ) {  par0=40; 
		 
   	   file =  "20170713220623_board8-VTHsw-allch-TP400_002."; 
	   NEVT=50.;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170713222723_board8-VTHsw-allch-TP600_002."; 
	   NEVT=50.;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170713224824_board8-VTHsw-allch-TP800_002."; 
	   NEVT=50.;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170713230927_board8-VTHsw-allch-TP1000_002."; 
	   NEVT=50.;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170713233032_board8-VTHsw-allch-TP1200_002."; 
	   NEVT=50.;
    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170713235138_board8-VTHsw-allch-TP1400_002."; 
	   NEVT=50.;
    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170714001248_board8-VTHsw-allch-TP1600_002."; 
	   NEVT=50.;
    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170714003401_board8-VTHsw-allch-TP1800_002."; 
	   NEVT=50.;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170714005518_board8-VTHsw-allch-TP2000_002."; 
	   NEVT=50.;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170714011635_board8-VTHsw-allch-TP2200_002."; 
	   NEVT=50.;

    }
	
	if (it==12	) {  par0=40; 
		 
   	   file =  "20170714013755_board8-VTHsw-allch-TP2400_002."; 
	   NEVT=50.;

    }
	
	if (it==13	) {  par0=40; 
		 
   	   file =  "20170714015915_board8-VTHsw-allch-TP2600_002."; 
	   NEVT=50.;

    }
	
	if (it==14	) {  par0=40; 
		 
   	   file =  "20170714022038_board8-VTHsw-allch-TP2800_002."; 
	   NEVT=50.;
		
    }
	
	if (it==15	) {  par0=40; 
		 
   	   file =  "20170714024203_board8-VTHsw-allch-TP3000_002."; 
	   NEVT=50.;
		
    }
	
	if (it==16	) {  par0=40; 
		 
   	   file =  "20170714030328_board8-VTHsw-allch-TP3200_002."; 
	   NEVT=50.;
		
    }
	
	if (it==17	) {  par0=40; 
		 
   	   file =  "20170714032501_board8-VTHsw-allch-TP3400_002."; 
	   NEVT=50.;
		
    }
	
	if (it==18	) {  par0=40; 
		 
   	   file =  "20170714034242_board8-VTHsw-allch-TP3600_002."; 
	   NEVT=50.;
		
    }
	
	Dir = Dir0+"";	
    Macro_scurve_Vth(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    //analisiMC(Dir,file,60,20,80,1.,4.,type,min,max);
	analisiMC(Dir,file,100,80,200,1.,8.); 	
	}
	}
}
/*
void TwoDim_Plots_40M_timing_loop(Int_t type, Int_t min, Int_t max)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 200;
	TString file,Dir, Dir0;
	Int_t it=0;
//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";
    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan/";	
	
    it=0;
	int t;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
    //file="pippo";
	
	TString output_filename2, filename,Resfile2;
	
	Resfile2 = Dir0+"Out/"+"Result.txt" ;
	cout << " file to be opened " << Resfile2 << endl;
	ofstream output_file2(Resfile2);
	
	if (output_file2.is_open())
	{ cout << "The file: " << Resfile2 << " IS OPEN " << "\n"; }
	else 
	{ cout << "The file: " << Resfile2 << " IS NOT OPEN " << "\n";
	return; }
	
	float mean0 ;
	int n_entries2 ;
	
     it=0;
	for(it=1;it<19;it++){
	
    if (it==1 ) {  par0=40; 
		 
   	   file =  "20170601004206_board8-CALsw-allch-TP200_001."; 
	   NEVT=200.;
		t = 200;
    }
	if (it==2 ) {  par0=40; 
		 
   	   file =  "20170531191742_board8-CALsw-allch-TP400_000."; 
	   NEVT=200.;
       t = t + 200;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170531194049_board8-CALsw-allch-TP600_000."; 
	   NEVT=200.;
		t = t + 200;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170531200358_board8-CALsw-allch-TP800_000."; 
	   NEVT=200.;
		t = t + 200;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170531202711_board8-CALsw-allch-TP1000_000."; 
	   NEVT=200.;
		t = t + 200;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170601023819_board8-CALsw-allch-TP1200_001."; 
	   NEVT=200.;
		t = t + 200;
    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170531211343_board8-CALsw-allch-TP1400_000."; 
	   NEVT=200.;
		t = t + 200;
    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170531213700_board8-CALsw-allch-TP1600_000."; 
	   NEVT=200.;
		t = t + 200;
    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170531220020_board8-CALsw-allch-TP1800_000."; 
	   NEVT=200.;
		t = t + 200;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170531222337_board8-CALsw-allch-TP2000_000."; 
	   NEVT=200.;
		t = t + 200;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170531224649_board8-CALsw-allch-TP2200_000."; 
	   t = t + 200;
    }
	
	if (it==12	) {  par0=40; 
		 
   	   file =  "20170531231001_board8-CALsw-allch-TP2400_000."; 
	   t = t + 200;
    }
	
	if (it==13	) {  par0=40; 
		 
   	   file =  "20170531233312_board8-CALsw-allch-TP2600_000."; 
	   t = t + 200;
    }
	
	if (it==14	) {  par0=40; 
		 
   	   file =  "20170531235613_board8-CALsw-allch-TP2800_000."; 
	   NEVT=200.;
		t = t + 200;
    }
	
	if (it==15	) {  par0=40; 
		 
   	   file =  "20170601001908_board8-CALsw-allch-TP3000_000."; 
	   NEVT=200.;
		t = t + 200;
    }
	
	if (it==16	) {  par0=40; 
		 
   	   file =  "20170706110201_board8-CALsw-allch-TP3200_004."; 
	   NEVT=200.;
		t = t + 200;
    }
	
	if (it==17	) {  par0=40; 
		 
   	   file =  "20170706111354_board8-CALsw-allch-TP3400_004."; 
	   NEVT=200.;
		t = t + 200;
    }
	
	if (it==18	) {  par0=40; 
		 
   	   file =  "20170706112546_board8-CALsw-allch-TP3600_004."; 
	   NEVT=200.;
		t = t + 200;
    }
	
	Dir = Dir0+"";	
	
    //Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	//analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
	
	
    analisiMC(Dir,file,3000,35,60,1.,4.,type,min,max); 
	
	
	n_entries2 = histo_thr->GetEntries();
  
	
	mean0 = histo_thr->GetMean();
	
	if(n_entries2 > 50){
	//  f1thr->GetParameter(0)
    output_file2 << t << "  " << f1thr->GetParameter(1) << "  " << f1thr->GetParError(1) << "  " <<f1thr->GetParameter(2)<< "  " << f1thr->GetParError(2) << endl;	
	}
	else {
	//  output_file2 << t << "  " << mean0 << "  " << 0.1 << "  " << 1.  <<  " " << 1. << endl;
	output_file2 << t << "  " << f1thr->GetParameter(1) << "  " << 0.1 << "  " <<f1thr->GetParameter(2)<< "  " << f1thr->GetParError(2) << endl;
	}
		
}
	grafico(Dir,Resfile2);
}
void TwoDim_Plots_If160_40M_timing_loop(Int_t type, Int_t min, Int_t max)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 200;
	TString file,Dir, Dir0;
	Int_t it=0;
//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";
    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan/";	
	
    it=0;
	int t;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
    //file="pippo";
	
	TString output_filename2, filename,Resfile2;
	
	Resfile2 = Dir0+"Out/"+"Result.txt" ;
	cout << " file to be opened " << Resfile2 << endl;
	ofstream output_file2(Resfile2);
	
	if (output_file2.is_open())
	{ cout << "The file: " << Resfile2 << " IS OPEN " << "\n"; }
	else 
	{ cout << "The file: " << Resfile2 << " IS NOT OPEN " << "\n";
	return; }
	
	
     it=0;
	for(it=1;it<19;it++){
	
    if (it==1 ) {  par0=40; 
		 
   	   file =  "20170623123707_board8-CALsw-allch-If160-TP200_002.."; 
	   NEVT=200.;
		t = 200;
    }
	if (it==2 ) {  par0=40; 
		 
   	   file =  "20170623125058_board8-CALsw-allch-If160-TPphase400_002."; 
	   NEVT=200.;
       t = t + 200;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170623130449_board8-CALsw-allch-If160-TPphase600_002."; 
	   NEVT=200.;
		t = t + 200;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170623131848_board8-CALsw-allch-If160-TPphase800_002."; 
	   NEVT=200.;
		t = t + 200;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170623133255_board8-CALsw-allch-If160-TPphase1000_002."; 
	   NEVT=200.;
		t = t + 200;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "220170614222316_board8-CALsw-allch-TP1200_001."; 
	   NEVT=200.;
		t = t + 200;
    }
	
	if (it==7 ) {  par0=40; 
		 
   	   file =  "20170614223825_board8-CALsw-allch-TP1400_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	if (it==8 ) {  par0=40; 
		 
   	   file =  "20170614224900_board8-CALsw-allch-TP1600_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==9	) {  par0=40; 
		 
   	   file =  "20170614225947_board8-CALsw-allch-TP1800_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170615021655_board8-CALsw-allch-TP2000_002."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==11 ) {  par0=40; 
		 
   	   file =  "20170615022743_board8-CALsw-allch-TP2200_002."; 
	   NEVT=50.;
		t = t + 200;
    }
	if (it==12	) {  par0=40; 
		 
   	   file =  "20170614233152_board8-CALsw-allch-TP2400_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	
	if (it==13	) {  par0=40; 
		 
   	   file =  "20170614234238_board8-CALsw-allch-TP2600_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
    if (it==14	) {  par0=40; 
		 
   	   file =  "20170614235323_board8-CALsw-allch-TP2800_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==15	) {  par0=40; 
		 
   	   file =  "20170615000402_board8-CALsw-allch-TP3000_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==16	) {  par0=40; 
		 
   	   file =  "20170614215338_board8-CALsw-allch-TP3600_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==17 ) {  par0=40; 
		 
   	   file =  "20170623134706_board8-CALsw-allch-If160-TPphase3200_002."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==18 ) {  par0=40; 
		 
   	   file =  "20170623105900_board8-CALsw-allch-Pmezzi-TPphase3400_000."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==19 ) {  par0=40; 
		 
   	   file =  "20170615012926_board8-CALsw-allch-TP1200_002."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	Dir = Dir0+"";	
	
   // Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	//analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
	
	
    analisiMC(Dir,file,60,20,80,1.,4.,type,min,max); 
	
	output_file2 << t << "  " << f1thr->GetParameter(1) << "  " << f1thr->GetParError(1) << "  " <<f1thr->GetParameter(2)<< "  " << f1thr->GetParError(2) << endl;		
}
	//FileOutRes(Dir,file,i);
}
void TwoDim_Plots_20M_timing_loop(Int_t type, Int_t min, Int_t max)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 200;
	TString file,Dir, Dir0;
	Int_t it=0;
//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";
    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan-20MHz/";	
	
    it=0;
	int t;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
    //file="pippo";
	
	TString output_filename2, filename,Resfile2;
	
	Resfile2 = Dir0+"Out/"+"Result.txt" ;
	cout << " file to be opened " << Resfile2 << endl;
	ofstream output_file2(Resfile2);
	
	if (output_file2.is_open())
	{ cout << "The file: " << Resfile2 << " IS OPEN " << "\n"; }
	else 
	{ cout << "The file: " << Resfile2 << " IS NOT OPEN " << "\n";
	return; }
	
	float mean0 ;
	int n_entries2 ;
	
     it=0;
	for(it=1;it<19;it++){
	
    if (it==1 ) {  par0=40; 
		 
   	   file =  "20170608233903_board8-CALsw-allch-TP200_001."; 
	   NEVT=50.;
		t = 200;
    }
	if (it==2 ) {  par0=40; 
		 
   	   file =  "20170608235649_board8-CALsw-allch-TP400_001."; 
	   NEVT=50.;
       t = t + 200;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170609001415_board8-CALsw-allch-TP600_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170609003143_board8-CALsw-allch-TP800_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170609004912_board8-CALsw-allch-TP1000_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170609010658_board8-CALsw-allch-TP1200_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170609012448_board8-CALsw-allch-TP1400_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170609013731_board8-CALsw-allch-TP1600_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170609015016_board8-CALsw-allch-TP1800_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170609020307_board8-CALsw-allch-TP2000_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170609021557_board8-CALsw-allch-TP2200_001."; 
	   t = t + 200;
    }
	
	if (it==12	) {  par0=40; 
		 
   	   file =  "20170609022853_board8-CALsw-allch-TP2400_001."; 
	   t = t + 200;
    }
	
	if (it==13	) {  par0=40; 
		 
   	   file =  "20170609024149_board8-CALsw-allch-TP2600_001."; 
	   t = t + 200;
    }
	
	if (it==14	) {  par0=40; 
		 
   	   file =  "20170609025448_board8-CALsw-allch-TP2800_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==15	) {  par0=40; 
		 
   	   file =  "20170609030746_board8-CALsw-allch-TP3000_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==16	) {  par0=40; 
		 
   	   file =  "20170609155821_board8-CALsw-allch-TP3200_000."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==17	) {  par0=40; 
		 
   	   file =  "20170609161543_board8-CALsw-allch-TP3400_000."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==18	) {  par0=40; 
		 
   	   file =  "20170609163253_board8-CALsw-allch-TP3600_000."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	Dir = Dir0+"";	
	
    //Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	//analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
	
	
    analisiMC(Dir,file,200,20,120,1.,4.,type,min,max); 
	
	
	n_entries2 = histo_thr->GetEntries();
  
	
	mean0 = histo_thr->GetMean();
	
	if(n_entries2 > 50){
	//  f1thr->GetParameter(0)
    output_file2 << t << "  " << f1thr->GetParameter(1) << "  " << f1thr->GetParError(1) << "  " <<f1thr->GetParameter(2)<< "  " << f1thr->GetParError(2) << endl;	
	}
	else {
	//  output_file2 << t << "  " << mean0 << "  " << 0.1 << "  " << 1.  <<  " " << 1. << endl;
	output_file2 << t << "  " << f1thr->GetParameter(1) << "  " << 0.1 << "  " <<f1thr->GetParameter(2)<< "  " << f1thr->GetParError(2) << endl;
	}
		
}
	grafico(Dir,Resfile2);
}
void TwoDim_Plots_If40_20M_timing_loop(Int_t type, Int_t min, Int_t max)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 200;
	TString file,Dir, Dir0;
	Int_t it=0;
//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";
    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan-20MHz-Ifeed40/";	
	
    it=0;
	int t;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
    //file="pippo";
	
	TString output_filename2, filename,Resfile2;
	
	Resfile2 = Dir0+"Out/"+"Result.txt" ;
	cout << " file to be opened " << Resfile2 << endl;
	ofstream output_file2(Resfile2);
	
	if (output_file2.is_open())
	{ cout << "The file: " << Resfile2 << " IS OPEN " << "\n"; }
	else 
	{ cout << "The file: " << Resfile2 << " IS NOT OPEN " << "\n";
	return; }
	
	float mean0 ;
	int n_entries2 ;
	
     it=0;
	for(it=1;it<19;it++){
	
     if (it==1 ) {  par0=40; 
		 
   	   file =  "20170629101803_board8-CALsw-allch-If40-TP200_000."; 
	   NEVT=50.;
	   t=200;
    }
	if (it==2 ) {  par0=40; 
		 
   	   file =  "20170629103658_board8-CALsw-allch-If40-TP400_000."; 
	   NEVT=50.;
	   t = t + 200;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170629105551_board8-CALsw-allch-If40-TP600_000."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170629111430_board8-CALsw-allch-If40-TP800_000."; 
	   NEVT=50.;
	   t = t + 200;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170629113321_board8-CALsw-allch-If40-TP1000_000."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170629115216_board8-CALsw-allch-If40-TP1200_000."; 
	   NEVT=50.;
	   t = t + 200;
    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170629121112_board8-CALsw-allch-If40-TP1400_000."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170629122443_board8-CALsw-allch-If40-TP1600_000."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170629123806_board8-CALsw-allch-If40-TP1800_000."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170629125136_board8-CALsw-allch-If40-TP2000_000."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170629130507_board8-CALsw-allch-If40-TP2200_000."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==12	) {  par0=40; 
		 
   	   file =  "20170629131837_board8-CALsw-allch-If40-TP2400_000."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==13	) {  par0=40; 
		 
   	   file =  "20170629133201_board8-CALsw-allch-If40-TP2600_000."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==14	) {  par0=40; 
		 
   	   file =  "20170629134536_board8-CALsw-allch-If40-TP2800_000."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==15	) {  par0=40; 
		 
   	   file =  "20170629135906_board8-CALsw-allch-If40-TP3000_000."; 
	   NEVT=50.;
		t = t + 200;    
	}
	
	if (it==16	) {  par0=40; 
		 
   	   file =  "20170629141239_board8-CALsw-allch-If40-TP3200_000."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==17	) {  par0=40; 
		 
   	   file =  "20170629185731_board8-CALsw-allch-If40-TP3400_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==18	) {  par0=40; 
		 
   	   file =  "20170629190851_board8-CALsw-allch-If40-TP3600_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	Dir = Dir0+"";	
	
    //Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	//analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
	
	
    analisiMC(Dir,file,200,20,120,1.,4.,type,min,max); 
	
	
	n_entries2 = histo_thr->GetEntries();
  
	
	mean0 = histo_thr->GetMean();
	
	if(n_entries2 > 50){
	//  f1thr->GetParameter(0)
    output_file2 << t << "  " << f1thr->GetParameter(1) << "  " << f1thr->GetParError(1) << "  " <<f1thr->GetParameter(2)<< "  " << f1thr->GetParError(2) << endl;	
	}
	else {
	//  output_file2 << t << "  " << mean0 << "  " << 0.1 << "  " << 1.  <<  " " << 1. << endl;
	output_file2 << t << "  " << f1thr->GetParameter(1) << "  " << 0.1 << "  " <<f1thr->GetParameter(2)<< "  " << f1thr->GetParError(2) << endl;
	}
		
}
	grafico(Dir,Resfile2);
}
void TwoDim_Plots_Pdoppi_20M_timing_loop(Int_t type, Int_t min, Int_t max)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 200;
	TString file,Dir, Dir0;
	Int_t it=0;
//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";
    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-scan-20MHz-Pdoppi/";	
	
    it=0;
	int t;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
    //file="pippo";
	
	TString output_filename2, filename,Resfile2;
	
	Resfile2 = Dir0+"Out/"+"Result.txt" ;
	cout << " file to be opened " << Resfile2 << endl;
	ofstream output_file2(Resfile2);
	
	if (output_file2.is_open())
	{ cout << "The file: " << Resfile2 << " IS OPEN " << "\n"; }
	else 
	{ cout << "The file: " << Resfile2 << " IS NOT OPEN " << "\n";
	return; }
	
	float mean0 ;
	int n_entries2 ;
	
     it=0;
	for(it=1;it<19;it++){
	
     if (it==1 ) {  par0=40; 
		 
   	   file =  "20170628135604_board8-CALsw-allch-Pdoppi-TP200_001."; 
	   NEVT=50.;
	   t=200;
    }
	if (it==2 ) {  par0=40; 
		 
   	   file =  "20170628141435_board8-CALsw-allch-Pdoppi-TP400_001."; 
	   NEVT=50.;
	   t = t + 200;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170628143255_board8-CALsw-allch-Pdoppi-TP600_001."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170628145107_board8-CALsw-allch-Pdoppi-TP800_001."; 
	   NEVT=50.;
	   t = t + 200;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170628150927_board8-CALsw-allch-Pdoppi-TP1000_001."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170628152811_board8-CALsw-allch-Pdoppi-TP1200_001."; 
	   NEVT=50.;
	   t = t + 200;
    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170628154654_board8-CALsw-allch-Pdoppi-TP1400_001."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170628160015_board8-CALsw-allch-Pdoppi-TP1600_001."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170628161337_board8-CALsw-allch-Pdoppi-TP1800_001."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170628162701_board8-CALsw-allch-Pdoppi-TP2000_001."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170628164028_board8-CALsw-allch-Pdoppi-TP2200_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==12	) {  par0=40; 
		 
   	   file =  "20170628165355_board8-CALsw-allch-Pdoppi-TP2400_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==13	) {  par0=40; 
		 
   	   file =  "20170628170725_board8-CALsw-allch-Pdoppi-TP2600_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==14	) {  par0=40; 
		 
   	   file =  "20170628172050_board8-CALsw-allch-Pdoppi-TP2800_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==15	) {  par0=40; 
		 
   	   file =  "20170628173422_board8-CALsw-allch-Pdoppi-TP3000_001."; 
	   NEVT=50.;
		t = t + 200;    
	}
	
	if (it==16	) {  par0=40; 
		 
   	   file =  "20170628174753_board8-CALsw-allch-Pdoppi-TP3200_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==17	) {  par0=40; 
		 
   	   file =  "20170628180132_board8-CALsw-allch-Pdoppi-TP3400_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==18	) {  par0=40; 
		 
   	   file =  "20170628181245_board8-CALsw-allch-Pdoppi-TP3600_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	Dir = Dir0+"";	
	
    //Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	//analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
	
	
    analisiMC(Dir,file,200,20,120,1.,4.,type,min,max); 
	
	
	n_entries2 = histo_thr->GetEntries();
  
	
	mean0 = histo_thr->GetMean();
	
	if(n_entries2 > 50){
	//  f1thr->GetParameter(0)
    output_file2 << t << "  " << f1thr->GetParameter(1) << "  " << f1thr->GetParError(1) << "  " <<f1thr->GetParameter(2)<< "  " << f1thr->GetParError(2) << endl;	
	}
	else {
	//  output_file2 << t << "  " << mean0 << "  " << 0.1 << "  " << 1.  <<  " " << 1. << endl;
	output_file2 << t << "  " << f1thr->GetParameter(1) << "  " << 0.1 << "  " <<f1thr->GetParameter(2)<< "  " << f1thr->GetParError(2) << endl;
	}
		
}
	grafico(Dir,Resfile2);
}
void TwoDim_Plots_Vthchange_20M_timing_loop(Int_t type, Int_t min, Int_t max)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 200;
	TString file,Dir, Dir0;
	Int_t it=0;
//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";
    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-VTHSCAN-std-956mV-VDD/";	
	
    it=0;
	int t;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
    //file="pippo";
	
	TString output_filename2, filename,Resfile2;
	
	Resfile2 = Dir0+"Out/"+"Result.txt" ;
	cout << " file to be opened " << Resfile2 << endl;
	ofstream output_file2(Resfile2);
	
	if (output_file2.is_open())
	{ cout << "The file: " << Resfile2 << " IS OPEN " << "\n"; }
	else 
	{ cout << "The file: " << Resfile2 << " IS NOT OPEN " << "\n";
	return; }
	
	float mean0 ;
	int n_entries2 ;
	
	
	
     it=0;
	for(it=1;it<19;it++){
	
    if (it==1 ) {  par0=40; 
		 
   	   file =  "20170712221639_board8-VTHsw-allch-TP200_001."; 
	   NEVT=50.;
		t = 200;
    }
	if (it==2 ) {  par0=40; 
		 
   	   file =  "20170712223732_board8-VTHsw-allch-TP400_001."; 
	   NEVT=50.;
       t = t + 200;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170712225814_board8-VTHsw-allch-TP600_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170712231852_board8-VTHsw-allch-TP800_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170712233936_board8-VTHsw-allch-TP1000_001.";
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170713000027_board8-VTHsw-allch-TP1200_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170713002113_board8-VTHsw-allch-TP1400_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170713004212_board8-VTHsw-allch-TP1600_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
    if (it==9	) {  par0=40; 
		 
   	  file =  "20170713010313_board8-VTHsw-allch-TP1800_001.";
		t = t + 200;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170713012418_board8-VTHsw-allch-TP2000_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170713014525_board8-VTHsw-allch-TP2200_001."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==12	) {  par0=40; 
		 
   	   file =  "20170713020636_board8-VTHsw-allch-TP2400_001."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==13	) {  par0=40; 
		 
   	   file =  "20170713022747_board8-VTHsw-allch-TP2600_001."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==14	) {  par0=40; 
		 
   	   file =  "20170713024903_board8-VTHsw-allch-TP2800_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==15	) {  par0=40; 
		 
   	   file =  "20170713031020_board8-VTHsw-allch-TP3000_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==16	) {  par0=40; 
		 
   	   file =  "20170713033135_board8-VTHsw-allch-TP3200_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==17	) {  par0=40; 
		 
   	   file =  "20170713035255_board8-VTHsw-allch-TP3400_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==18	) {  par0=40; 
		 
   	   file =  "20170713041027_board8-VTHsw-allch-TP3600_001."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	Dir = Dir0+"";	
	
    //Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	//analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
	
	
    analisiMC(Dir,file,200,20,220,1.,4.,type,min,max); 
	
	
	n_entries2 = histo_thr->GetEntries();
  
	
	mean0 = histo_thr->GetMean();
	
	if(n_entries2 > 50){
	//  f1thr->GetParameter(0)
    output_file2 << t << "  " << f1thr->GetParameter(1) << "  " << f1thr->GetParError(1) << "  " <<f1thr->GetParameter(2)<< "  " << f1thr->GetParError(2) << endl;	
	}
	else {
	//  output_file2 << t << "  " << mean0 << "  " << 0.1 << "  " << 1.  <<  " " << 1. << endl;
	output_file2 << t << "  " << f1thr->GetParameter(1) << "  " << 0.1 << "  " <<f1thr->GetParameter(2)<< "  " << f1thr->GetParError(2) << endl;
	}
		
}
	grafico_VTh(Dir,Resfile2);
}
*/
void TwoDim_Plots_Vthchange1200_20M_timing_loop(Int_t type, Int_t min, Int_t max)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 200;
	TString file,Dir, Dir0;
	Int_t it=0;

//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";

    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Board8/TPphase-VTHSCAN-std-1200mV-VDD/";	
	
    it=0;
	int t;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;
    //file="pippo";
	
	TString output_filename2, filename,Resfile2;
	
	Resfile2 = Dir0+"Out/"+"Result.txt" ;
	cout << " file to be opened " << Resfile2 << endl;
	ofstream output_file2(Resfile2);
	
	if (output_file2.is_open())
	{ cout << "The file: " << Resfile2 << " IS OPEN " << "\n"; }
	else 
	{ cout << "The file: " << Resfile2 << " IS NOT OPEN " << "\n";
	return; }
	
	float mean0 ;
	int n_entries2 ;
	
	
	
     it=0;
	for(it=1;it<19;it++){
	

    if (it==1 ) {  par0=40; 
		 
   	   file =  "20170713214516_board8-VTHsw-allch-TP200_002."; 
	   NEVT=50.;
	   t = 200;
    }
	if (it==2 ) {  par0=40; 
		 
   	   file =  "20170713220623_board8-VTHsw-allch-TP400_002."; 
	   NEVT=50.;
	   t = t + 200;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "20170713222723_board8-VTHsw-allch-TP600_002."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "20170713224824_board8-VTHsw-allch-TP800_002."; 
	   NEVT=50.;
	   t = t + 200;
    }
	if (it==5	) {  par0=40; 
		 
   	   file =  "20170713230927_board8-VTHsw-allch-TP1000_002."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==6 ) {  par0=40; 
		 
   	   file =  "20170713233032_board8-VTHsw-allch-TP1200_002."; 
	   NEVT=50.;
	   t = t + 200;
    }
	if (it==7	) {  par0=40; 
		 
   	   file =  "20170713235138_board8-VTHsw-allch-TP1400_002."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "20170714001248_board8-VTHsw-allch-TP1600_002."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
    if (it==9	) {  par0=40; 
		 
   	   file =  "20170714003401_board8-VTHsw-allch-TP1800_002."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "20170714005518_board8-VTHsw-allch-TP2000_002."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "20170714011635_board8-VTHsw-allch-TP2200_002."; 
	   NEVT=50.;
		t = t + 200;
    }
	
	if (it==12	) {  par0=40; 
		 
   	   file =  "20170714013755_board8-VTHsw-allch-TP2400_002."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==13	) {  par0=40; 
		 
   	   file =  "20170714015915_board8-VTHsw-allch-TP2600_002."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==14	) {  par0=40; 
		 
   	   file =  "20170714022038_board8-VTHsw-allch-TP2800_002."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==15	) {  par0=40; 
		 
   	   file =  "20170714024203_board8-VTHsw-allch-TP3000_002."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==16	) {  par0=40; 
		 
   	   file =  "20170714030328_board8-VTHsw-allch-TP3200_002."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==17	) {  par0=40; 
		 
   	   file =  "20170714032501_board8-VTHsw-allch-TP3400_002."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	if (it==18	) {  par0=40; 
		 
   	   file =  "20170714034242_board8-VTHsw-allch-TP3600_002."; 
	   NEVT=50.;
	   t = t + 200;
    }
	
	Dir = Dir0+"";	
	
    //Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	//analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
	
	
    analisiMC(Dir,file,200,20,220,1.,4.,type,min,max); 
	
	
	n_entries2 = histo_thr->GetEntries();
  
	
	mean0 = histo_thr->GetMean();
	
	if(n_entries2 > 50){
	//  f1thr->GetParameter(0)

    output_file2 << t << "  " << f1thr->GetParameter(1) << "  " << f1thr->GetParError(1) << "  " <<f1thr->GetParameter(2)<< "  " << f1thr->GetParError(2) << endl;	
	}
	else {
	//  output_file2 << t << "  " << mean0 << "  " << 0.1 << "  " << 1.  <<  " " << 1. << endl;
	output_file2 << t << "  " << f1thr->GetParameter(1) << "  " << 0.1 << "  " <<f1thr->GetParameter(2)<< "  " << f1thr->GetParError(2) << endl;
	}
		
}
	grafico_VTh(Dir,Resfile2);
}

void TwoDim_Plots_sensore7_Board2(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 100;
	TString file,Dir, Dir0;
	Int_t it=0;

//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";

    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Sensor7/Board2/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;


	while ( it<20 )  {
		it++;
		if (it==i ) {

     if (it==1 ) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C2F."; 
	   NEVT=100.;
    }
	if (it==2 ) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C2F_TO1-TO2."; 
	   NEVT=100.;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C4F."; 
	   NEVT=100.;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C4F_TO1-TO2."; 
	   NEVT=100.;
    }
	
	Dir = Dir0+"";	
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    //analisiMC(Dir,file,60,20,80,1.,4.,type,min,max);
	analisiMC(Dir,file,100,80,200,1.,8.); 	
	}
	}
}

void TwoDim_Plots_sensore12_Board4(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;

//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";

    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Sensor12/Board4/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;


	while ( it<20 )  {
		it++;
		if (it==i ) {

     if (it==1 ) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C2F-200V."; 
	   NEVT=100.;
    }
	if (it==2 ) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C2F-20V."; 
	   NEVT=100.;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C2F-20V-ch4."; 
	   NEVT=100.;
    }
	
	if (it==4	) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C2F-10V-ch4."; 
	   NEVT=100.;
    }
	
	if (it==5	) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C2F-5V-ch4."; 
	   NEVT=100.;
    }
	
	if (it==6	) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C2F-3V-ch4."; 
	   NEVT=100.;
    }
	
	if (it==7	) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C2F-1V-ch4."; 
	   NEVT=100.;
    }
	
	if (it==8	) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C2F-20Vnew-DC1p8uF-ch4."; 
	   NEVT=100.;
    }
	
	if (it==9	) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C2F-20Vnew-ch4."; 
	   NEVT=100.;
    }
	
	if (it==10	) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C2F-20Vnew-DC170nF-ch4."; 
	   NEVT=100.;
    }
	
	if (it==11	) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C2F-20Vnew-DC140nF-ch4."; 
	   NEVT=100.;
    }
	
	if (it==12  ) {  par0=40; 
   	   file =  "CALsw-VDD1200-TP300-C2F-If40-20Vnew-DC170nF-ch4."; 
	   NEVT=100.;
    }
	
	if (it==13  ) {  par0=40; 
   	   file =  "CALsw-VDD1200-TP300-C2F-If20-20Vnew-DC170nF-ch4."; 
	   NEVT=100.;
    }
	
	if (it==20	) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C2F-TO1-TO2-200V."; 
	   NEVT=100.;
    }
	
	if (it==21	) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C2F-TO1-TO2-200V_2."; 
	   NEVT=100.;
    }
	
	Dir = Dir0+"";	
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    //analisiMC(Dir,file,60,20,80,1.,4.,type,min,max);
	analisiMC(Dir,file,100,80,200,1.,8.); 	
	}
	}
}

void TwoDim_Plots_sensore12_Board4_PILA(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;

//	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl3200/";

    Dir0 = "C:/Users/CHIPIX65.CHIPIX65TO03/Documents/LabVIEW Data/CHIPIX_data/studenti/Sensor12/Board4/";	
	
    it=0;
    Float_t tmax,tmin;
    tmin=30.;
    tmax=65;


	while ( it<20 )  {
		it++;
		if (it==i ) {

     if (it==1 ) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C2F-PILA-ch4."; 
	   NEVT=100.;
    }
	if (it==2 ) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C2F-If40-PILA-ch4."; 
	   NEVT=100.;
    }
	if (it==3 ) {  par0=40; 
		 
   	   file =  "CALsw-VDD1200-TP300-C2F-If20-PILA-ch4."; 
	   NEVT=100.;
    }
	
	
	Dir = Dir0+"";	
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
    //analisiMC(Dir,file,60,20,80,1.,4.,type,min,max);
	analisiMC(Dir,file,100,80,200,1.,8.); 	
	}
	}
}


//void Analysis(int i,int type,int min, int max){
void Analysis(int i){
//  TwoDim_Plots_40M_timing(i, type, min, max);
//  TwoDim_Plots_40M_timing_range(i);
//  TwoDim_Plots_20M_timing(i, type, min, max);
//  TwoDim_Plots_20M_timing(i);
//  TwoDim_Plots_If160_timing(i);
//  TwoDim_Plots_If40_timing(i);
//  TwoDim_Plots_If10_timing(i);
//  TwoDim_Plots_If40_20M_timing(i);
//  TwoDim_Plots_Pdoppi_20M_timing(i);
//  TwoDim_Plots_C4F_timing(i);
//  TwoDim_Plots_Vth90_timing(i);
//  TwoDim_Plots_Pmezzi_timing(i);
//  TwoDim_Plots_Pdoppi_timing(i);
//  TwoDim_Plots_Vthchange_20M_timing(i);
//  TwoDim_Plots_Vthchange1200_20M_timing(i);
//  TwoDim_Plots_sensore7_Board2(i);
//  TwoDim_Plots_sensore12_Board4(i);
  TwoDim_Plots_sensore12_Board4_PILA(i);
}

void Analysis_loop(int type,int min, int max){

//  TwoDim_Plots_40M_timing_loop(type, min, max);
//  TwoDim_Plots_If160_timing_loop(type, min, max);
//  TwoDim_Plots_If40_timing_loop(type, min, max);
//  TwoDim_Plots_If10_timing_loop(type, min, max);
//  TwoDim_Plots_C4F_timing_loop(type, min, max);
//  TwoDim_Plots_Vth90_timing_loop(type, min, max);
//  TwoDim_Plots_Pmezzi_timing_loop(type, min, max);
//  TwoDim_Plots_Pdoppi_timing_loop(type, min, max);
//  TwoDim_Plots_20M_timing_loop(type, min, max);
// TwoDim_Plots_If40_20M_timing_loop(type, min, max);
//  TwoDim_Plots_Pdoppi_20M_timing_loop(type, min, max);
//  TwoDim_Plots_Vthchange_20M_timing_loop(type, min, max);
  TwoDim_Plots_Vthchange1200_20M_timing_loop(type, min, max);
}




void grafico(TString Dir, TString filename){
	
	//const float nmisure = 18;
	
	
	ifstream in(filename);
    if(!in){
		cout<<"Il file"<<filename<<"non esiste"<<endl;
		return;
	}
	
	/*
	ifstream file(filename);
	if (file.is_open())
	{ cout << "The file: " << filename << " IS OPEN " << "\n"; }
	else 
	{ cout << "The file: " << filename << " IS NOT OPEN " << "\n";
	  return;}
*/
	const int n = 18;
	int nmisure = 0;
	float t,thr,ethr,sr,esr, tm, q, sq;
	float TP[n], eTP[n], th[n], eth[n];
	/*
	vector<int> TPphase;
	vector<float> th;
	vector<float> eth;
	vector<float> s;
	vector<float> es;	
	*/
	while (in >> t)  {
//     if((in >> x )){
       
	//       npix.push_back(x);
        in >> thr;
	//        thr.push_back(y);
        in >> ethr;
	//        noise.push_back(z);
        in >> sr;
        in >> esr;
		
		//tm = 25 - t*25/3600;
		tm = 50 - t*50/3600;
		/*if (tm > 5 )  tm=tm;
		else tm = tm + 25;*/
		
		q = ((thr*48.5)-1500)*160/1000;
		sq = (ethr*48.5-1500)*160/1000;
	      //              x=x+2;
		  /*
              TPphase.push_back(tm);
              th.push_back(q);
              eth.push_back(sq);
			  s.push_back(sr);
              es.push_back(0);
			  nmisure++;*/
			  
		TP[nmisure] = tm;
		eTP[nmisure] = 0;
		th[nmisure] = q;
		eth[nmisure] = sq;
		nmisure++;
		
		//cout << tm << " " <<q << " " << sq << endl;
	  }
	        //cout << t << " " <<thr << " " << sr << endl;  
    
	TCanvas *csoglia = new TCanvas("csoglia","Q(TPphase)",200,50,600,400);
	csoglia -> cd();
	TGraphErrors *gsoglia = new TGraphErrors(nmisure, TP, th, eTP, eth);
	gsoglia->SetMarkerSize(0.6);
	gsoglia->SetMarkerStyle(21);
	gsoglia->SetTitle("<Q_{in}>(TPphase)_{20 MHz}");
	gsoglia->GetXaxis()->SetTitle("TPphase [ns]");
	gsoglia->GetYaxis()->SetTitle("<Q_{in}> [aC]");
	//gsoglia->SetMarkerColor(kBlue);
	gsoglia->Draw("AP");
	
	csoglia->cd();
	
	TF1 *fitQ = new TF1("fitQ","[4]+([0]+[3]*x)/(1-TMath::Exp(-(x-[1])/[2]))",5,31.6);
	//TF1 *fitQ = new TF1("fitQ","([0]+[3]*x)/(1-TMath::Exp(-(x-[1])/[2]))",0,50);

//	fitQ->SetParLimits(0,10.0,100.0);
//	fitQ->SetParLimits(1,-5.0,25.0);
	fitQ->SetParLimits(2,5.0,30.0);
//	fitQ->SetParLimits(3,0.5,20.0);
	//fitQ->SetParLimits(4,7,12);

	//TVirtualFitter::SetMaxInterations(100000);
	gsoglia->Fit(fitQ,"MR");
	//fitQ->SetParLimits(3,0.050,0.080);
	cout << "Chi^2: " << fitQ->GetChisquare() << endl;
	cout << "Probability: " << fitQ->GetProb() << endl;
	cout << "number of DoF: " << fitQ->GetNDF() << endl;
	/*
	float TP[nmisure], eTP[nmisure], th[nmisure], eth[nmisure];
	
    TString dummy, dummy1, dummy2, dummy3, dummy4;
     
    cout << " Reading file : " << filename << "\n"; 
    file >> dummy1 >> dummy2 >> dummy3 >> dummy4 >> dummy; 
//	file >> dummy >> dummy >> dummy >> dummy ; 
    cout << dummy1 << dummy2 << dummy3 << dummy4 << "\n";
	*/
	
	}
	
void grafico_VTh(TString Dir, TString filename){
	
	//const float nmisure = 18;
	
	
	ifstream in(filename);
    if(!in){
		cout<<"Il file"<<filename<<"non esiste"<<endl;
		return;
	}
	
	/*
	ifstream file(filename);
	if (file.is_open())
	{ cout << "The file: " << filename << " IS OPEN " << "\n"; }
	else 
	{ cout << "The file: " << filename << " IS NOT OPEN " << "\n";
	  return;}
*/
	const int n = 18;
	int nmisure = 0;
	float t,thr,ethr,sr,esr, tm, vth, svth;
	float TP[n], eTP[n], th[n], eth[n];
	/*
	vector<int> TPphase;
	vector<float> th;
	vector<float> eth;
	vector<float> s;
	vector<float> es;	
	*/
	while (in >> t)  {
//     if((in >> x )){
       
	//       npix.push_back(x);
        in >> thr;
	//        thr.push_back(y);
        in >> ethr;
	//        noise.push_back(z);
        in >> sr;
        in >> esr;
		
		//tm = 25 - t*25/3600;
		tm = 50 - t*50/3600;
		/*if (tm > 5 )  tm=tm;
		else tm = tm + 25;*/
		/*
		q = ((thr*48.5)-1500)*160/1000;
		sq = (ethr*48.5-1500)*160/1000;
		*/
		vth = thr*0.106/200 +0.49;
		svth = ethr*0.106/200;
	      //              x=x+2;
		  /*
              TPphase.push_back(tm);
              th.push_back(q);
              eth.push_back(sq);
			  s.push_back(sr);
              es.push_back(0);
			  nmisure++;*/
			  
		TP[nmisure] = tm;
		eTP[nmisure] = 0;
		th[nmisure] = vth;
		eth[nmisure] = svth;
		nmisure++;
		
		//cout << tm << " " <<q << " " << sq << endl;
	  }
	        //cout << t << " " <<thr << " " << sr << endl;  
    
	TCanvas *csoglia = new TCanvas("csoglia","Q(TPphase)",200,50,600,400);
	csoglia -> cd();
	TGraphErrors *gsoglia = new TGraphErrors(nmisure, TP, th, eTP, eth);
	gsoglia->SetMarkerSize(0.6);
	gsoglia->SetMarkerStyle(21);
	gsoglia->SetTitle("<V_{th}>(TPphase)_{20 MHz}");
	gsoglia->GetXaxis()->SetTitle("TPphase [ns]");
	gsoglia->GetYaxis()->SetTitle("<V_{th}> [mV]");
	//gsoglia->SetMarkerColor(kBlue);
	gsoglia->Draw("AP");
	
	csoglia->cd();
	
	float qDAC = 70.;
	float q_c;
	q_c = ((qDAC*48.5)-1500.)*1.6*pow(10.,-19.);
	cout << "/n" << q_c << "/n" << endl;
	
	float c = 2.4*pow(10.,-15.);
	
	//TF1 *fitV = new TF1("fitV","[0]*(1 + TMath::Exp(-(x-[1])/[2]))+[3]*(x+[1])+[4]",8,31.6);
	//TF1 *fitV = new TF1("fitV","[0]+[1]*TMath::Exp(-(x)/[2])+[3]*x",8,31.6);
	//TF1 *fitV = new TF1("fitV","(0.133)*(1-TMath::Exp(-(x-[0])/[1]))-[2]*4.1e14*(x-[0])",8,31.6);
	//TF1 *fitQ = new TF1("fitQ","([0]+[3]*x)/(1-TMath::Exp(-(x-[1])/[2]))",0,50);
	TF1 *fitV = new TF1("fitV","[0]*(1-TMath::Exp(-(x-[1])/[2]))-[3]*(x-[1])",8,31.6);

	//fitV->SetParameter(0,10.0e-9);
	//fitV->SetParameter(1,10.0e-9);
	//fitV->SetParameter(2,20.0e-9);
//	fitQ->SetParLimits(3,0.5,20.0);
	//fitQ->SetParLimits(4,7,12);

	//TVirtualFitter::SetMaxInterations(100000);
	gsoglia->Fit(fitV,"MR");
	//fitQ->SetParLimits(3,0.050,0.080);
	cout << "Chi^2: " << fitV->GetChisquare() << endl;
	cout << "Probability: " << fitV->GetProb() << endl;
	cout << "number of DoF: " << fitV->GetNDF() << endl;
	/*
	float TP[nmisure], eTP[nmisure], th[nmisure], eth[nmisure];
	
    TString dummy, dummy1, dummy2, dummy3, dummy4;
     
    cout << " Reading file : " << filename << "\n"; 
    file >> dummy1 >> dummy2 >> dummy3 >> dummy4 >> dummy; 
//	file >> dummy >> dummy >> dummy >> dummy ; 
    cout << dummy1 << dummy2 << dummy3 << dummy4 << "\n";
	*/
	
}