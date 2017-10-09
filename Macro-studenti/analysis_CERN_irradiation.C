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



void PADOVA_Annealing()
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 45;
	par1 = 2.;
	NEVT = 50;
	
	TString file,Dir, Dir0;
	Int_t it=0;

    Dir0 = "data/Padova/board_7/annealing/";

//     Dir0 = "C:/Users/CHIPIX65/My Documents/LabVIEW Data/CHIPIX65_DATA/Padova/board_7/annealing/";

    while ( it<6 )  {
		it++;
	 Dir = Dir0+"16-Feb-ShortPHI/";	
         if (it==1 ) file =  "201702161831_STDPARA_B7-VSCAN-320-6-VTH90.";
	 if (it==2 ) file =  "201702161831_STDPARA_B7-VSCAN-320-6-VTH70.";
	 if (it==3 ) file =  "201702161831_STDPARA_B7-VSCAN-320-6-VTH130.";	
	 if (it==4 ) file =  "201702161831_STDPARA_B7-VSCAN-320-6-VTH110.";
         if (it==5 ) file =  "201702161831_STDPARA_B7-VSCAN-320-6-VTH160.";
         if (it==6 ) file =  "201702161831_STDPARA_B7-VSCAN-320-6-VTH60.";
         if (it==7 ) file =  "201702161831_STDPARA_B7-VSCAN-320-6-VTH60_AZ.";
         if (it==8 ) file =  "201702161831_STDPARA_B7-VSCAN-320-6-VTH80_AZ.";
         if (it==9 ) file =  "201702161831_STDPARA_B7-VSCAN-320-6-VTH120_AZ.";
         if (it==10 ) file =  "201702161831_STDPARA_B7-VSCAN-320-6-VTH160_AZ.";

 	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiMC(Dir,file,50,30,80,0.,5.); 
    }	

}


void CERN_beforeT25C()
{
// ===========================================================================================================================
  Float_t xmin, xmax, par0, par1;
  Int_t NEVT, npix;
	xmin = 30;
	xmax = 300;
	par0 = 45;
	par1 = 2.;
	NEVT = 50;
        
	
	TString file,Dir, Dir0;
	Int_t it=0;

	Dir0 = "data/CERN/board4/Preirraggiamento/TEMP+25-RETURN/";

        it=4;
	while ( it<4 )  {
		it++;
	 Dir = Dir0+"";	
         if (it==1 ) {  par0=40; 
	   file =  "20170227214256_TO2-CALSWEEP-VTH60_000."; }
	 if (it==2 ) { par0=50;
	   file =  "20170227214418_TO2-CALSWEEP-VTH90_000.";}
	 if (it==3 ) { par0=65;
	   file =  "20170227215700_TO2-CALSWEEP-VTH130_001.";}	
	 if (it==4 ) { par0=75; 
	   file =  "20170227214728_TO2-CALSWEEP-VTH160_000.";}
 	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiMC(Dir,file,100,30,130,0.,10.); 
	}

        it=4;
	while ( it<4 )  {
		it++;
	 Dir = Dir0+"";	
         if (it==1 ) {  par0=40; 
	   file =  "20170227214851_TO1-CALSWEEP-VTH60_000."; }
	 if (it==2 ) { par0=50;
	   file =  "20170227215013_TO1-CALSWEEP-VTH90_000.";}
	 if (it==3 ) { par0=65;
	   file =  "20170227215132_TO1-CALSWEEP-VTH130_000.";}	
	 if (it==4 ) { par0=75; 
	   file =  "20170227215251_TO1-CALWEEP-VTH160_000.";}
 	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiMC(Dir,file,100,30,130,0.,10.); 
	}
}


void CERN_afterT25C()
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 45;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;


	Dir0 = "data/CERN/board4/Annealing/roomTemp/AllCH/";
 // Mar-9 : 3days annealing FILES =========================================
        it=0;
	while ( it<4 )  {
		it++;
	 Dir = Dir0+"";	
         if (it==1 ) {  par0=40; 
	   file =  "20170309113653_TO2-CALSWEEP-VTH60_001."; }
	 if (it==2 ) { par0=50;
	   file =  "20170309114815_TO2-CALSWEEP-VTH90_001.";}
	 if (it==3 ) { par0=65;
	   file =  "20170309092945_TO2-CALSWEEP-VTH130_000.";}	
	 if (it==4 ) { par0=75; 
	   file =  "20170309094059_TO2-CALSWEEP-VTH160_000.";}
 	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiMC(Dir,file,100,30,130,0.,10.); 
	}
        it=4;
	while ( it<4 )  {
		it++;
	 Dir = Dir0+"";	
         if (it==1 ) {  par0=40; 
	   file =  "20170309095217_TO1-CALSWEEP-VTH60_000."; }
	 if (it==2 ) { par0=50;
	   file =  "20170309100309_TO1-CALSWEEP-VTH90_000.";}
	 if (it==3 ) {
	   par0=65;
	   file =  "20170309101407_TO1-CALSWEEP-VTH130_000.";}	
	 if (it==4 ) { par0=75; 
	   file =  "20170309102505_TO1-CALWEEP-VTH160_000.";}

 	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiMC(Dir,file,100,30,130,0.,10.); 
	}



	Dir0 = "data/CERN/board4/Annealing/roomTemp/";
 // Mar-6 FILES :  11h annealing at room temperature  =========================================
        it=4;
	while ( it<4 )  {
		it++;
	 Dir = Dir0+"";	
         if (it==1 ) {  par0=40; 
	   file =  "20170306194031_TO2-CALSWEEP-VTH60_008."; }
	 if (it==2 ) { par0=50;
	   file =  "20170306194158_TO2-CALSWEEP-VTH90_008.";}
	 if (it==3 ) { par0=65;
	   file =  "20170306194331_TO2-CALSWEEP-VTH130_008.";}	
	 if (it==4 ) { par0=75; 
	   file =  "20170306185812_TO2-CALSWEEP-VTH160_007.";}
 	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiMC(Dir,file,100,30,130,0.,10.); 
	}
        it=4;
	while ( it<4 )  {
		it++;
	 Dir = Dir0+"";	
         if (it==1 ) {  par0=40; 
	   file =  "20170306185938_TO1-CALSWEEP-VTH60_007."; }
	 if (it==2 ) { par0=50;
	   file =  "20170306190101_TO1-CALSWEEP-VTH90_007.";}
	 if (it==3 ) {
	   par0=65;
	   file =  "20170306190224_TO1-CALSWEEP-VTH130_007.";}	
	 if (it==4 ) { par0=75; 
	   file =  "20170306190348_TO1-CALWEEP-VTH160_007.";}
 	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiMC(Dir,file,100,30,130,0.,10.); 
	}

}

void CERN_afterTm20C()
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 45;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;

	Dir0 = "data/CERN/board4/Annealing/-20C/";

        it=0;
	while ( it<4 )  {
		it++;
	 Dir = Dir0+"";	
         if (it==1 ) {  par0=40; 
	   file =  "20170306061810_TO2-CALSWEEP-VTH60_013."; }
	 if (it==2 ) { par0=50;
	   file =  "20170306061935_TO2-CALSWEEP-VTH90_013.";}
	 if (it==3 ) { par0=65;
	   file =  "20170306062100_TO2-CALSWEEP-VTH130_013.";}	
	 if (it==4 ) { par0=75; 
	   file =  "20170306062225_TO2-CALSWEEP-VTH160_013.";}
 	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiMC(Dir,file,100,30,130,0.,10.); 
	}
        it=0;
	while ( it<4 )  {
		it++;
	 Dir = Dir0+"";	
         if (it==1 ) {  par0=40; 
	   file =  "20170306062350_TO1-CALSWEEP-VTH60_013."; }
	 if (it==2 ) { par0=50;
	   file =  "20170306062513_TO1-CALSWEEP-VTH90_013.";}
	 if (it==3 ) { 
	   par0=65;
	   file =  "20170306062636_TO1-CALSWEEP-VTH130_013.";}	
	 if (it==4 ) { par0=75; 
	   file =  "20170306062802_TO1-CALWEEP-VTH160_013.";}
 	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiMC(Dir,file,100,30,130,0.,10.); 
	}

}

void TDR_Plots()
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 45;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;

	Dir0 = "data/Board1/CERN_meaasurements/Ifeed75-Vbl350/";

        it=4;
	while ( it<4 )  {
		it++;
	 Dir = Dir0+"";	
         if (it==1 ) {  par0=40; 
	   file =  "20170321131508_TO2-CALSWEEP-VTH60_000."; }
	 if (it==2 ) { par0=50;
	   file =  "20170321131737_TO2-CALSWEEP-VT100_000.";}
	 if (it==3 ) { par0=65;
	   file =  "20170321132008_TO2-CALSWEEP-VTH140_000.";}	
	 if (it==4 ) { par0=75; 
	   file =  "20170321132243_TO2-CALSWEEP-VTH180_000.";}
 	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiMC(Dir,file,100,30,130,0.,10.); 
	}
        it=4;
	while ( it<4 )  {
		it++;
	 Dir = Dir0+"";	
         if (it==1 ) {  par0=40; 
	   file =  "20170321132518_TO1-CALSWEEP-VTH35_000."; }
	 if (it==2 ) { par0=50;
	   file =  "20170321132913_TO1-CALSWEEP-VTH75_000.";}
	 if (it==3 ) { 
	   par0=65;
	   file =  "20170321133307_TO1-CALSWEEP-VTH115_000.";}	
	 if (it==4 ) { par0=75; 
	   file =  "20170321133758_TO1-CALWEEP-VTH155_000.";}
 	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiMC(Dir,file,100,30,130,0.,10.); 
	}



	Dir0 = "data/Board1/CERN_meaasurements/Ifeed75_Vbl350_FastToT/";

        it=4;
	while ( it<4 )  {
		it++;
	 Dir = Dir0+"";	
         if (it==1 ) {  par0=40; 
	   file =  "20170321144635_TO2-CALSWEEP-VTH60_000."; }
	 if (it==2 ) { par0=50;
	   file =  "20170321145603_TO2-CALSWEEP-VT100_000.";}
	 if (it==3 ) { par0=65;
	   file =  "20170321150528_TO2-CALSWEEP-VTH140_000.";}	
	 if (it==4 ) { par0=75; 
	   file =  "20170321151539_TO2-CALSWEEP-VTH180_000.";}
 	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiMC(Dir,file,100,30,130,0.,10.); 
	}
        it=4;
	while ( it<4 )  {
		it++;
	 Dir = Dir0+"";	
         if (it==1 ) {  par0=40; 
	   file =  "20170321152539_TO1-CALSWEEP-VTH35_000."; }
	 if (it==2 ) { par0=50;
	   file =  "20170321153456_TO1-CALSWEEP-VTH75_000.";}
	 if (it==3 ) { 
	   par0=65;
	   file =  "20170321154407_TO1-CALSWEEP-VTH115_000.";}	
	 if (it==4 ) { par0=75; 
	   file =  "20170321155510_TO1-CALWEEP-VTH155_000.";}
 	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiMC(Dir,file,100,30,130,0.,10.); 
	}

	// ============================================== 

	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl350/";

        it=4;
	while ( it<4 )  {
		it++;
	 Dir = Dir0+"";	
         if (it==1 ) {  par0=40; 
	   file =  "20170321172719_TO2-CALSWEEP-VTH60_000."; }
	 if (it==2 ) { par0=50;
	   file =  "20170321173639_TO2-CALSWEEP-VT100_000.";}
	 if (it==3 ) { par0=65;
	   file =  "20170321174606_TO2-CALSWEEP-VTH140_000.";}	
	 if (it==4 ) { par0=75; 
	   file =  "20170321175544_TO2-CALSWEEP-VTH180_000.";}
 	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiMC(Dir,file,100,30,130,0.,10.); 
	}
        it=0;
	while ( it<4 )  {
		it++;
	 Dir = Dir0+"";	
         if (it==1 ) {  par0=40; 
	   file =  "20170321180512_TO1-CALSWEEP-VTH35_000."; }
	 if (it==2 ) { par0=50;
	   file =  "20170321181442_TO1-CALSWEEP-VTH75_000.";}
	 if (it==3 ) { 
	   par0=65;
	   file =  "20170321182356_TO1-CALSWEEP-VTH115_000.";}	
	 if (it==4 ) { par0=75; 
	   file =  "20170321183518_TO1-CALWEEP-VTH155_000.";}
 	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiMC(Dir,file,100,30,130,0.,10.); 
	}




}


void CERN_beforeTm20C()
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 45;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;

	Dir0 = "data/CERN/board4/Preirraggiamento/TEMP-20C/";

        it=0;
	while ( it<4 )  {
		it++;
	 Dir = Dir0+"";	
         if (it==1 ) {  par0=40; 
	   file =  "20170227235239_TO2-CALSWEEP-VTH60_001."; }
	 if (it==2 ) { par0=50;
	   file =  "20170227235404_TO2-CALSWEEP-VTH90_001.";}
	 if (it==3 ) { par0=65;
	   file =  "20170227232710_TO2-CALSWEEP-VTH130_000.";}	
	 if (it==4 ) { par0=75; 
	   file =  "20170227232834_TO2-CALSWEEP-VTH160_000.";}
 	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiMC(Dir,file,100,30,130,0.,10.); 
	}
        it=0;
	while ( it<4 )  {
		it++;
	 Dir = Dir0+"";	
         if (it==1 ) {  par0=40; 
	   file =  "20170227232959_TO1-CALSWEEP-VTH60_000."; }
	 if (it==2 ) { par0=50;
	   file =  "20170227233123_TO1-CALSWEEP-VTH90_000.";}
	 if (it==3 ) { 
	   par0=65;
	   file =  "20170227233243_TO1-CALSWEEP-VTH130_000.";}	
	 if (it==4 ) { par0=75; 
	   file =  "20170227233403_TO1-CALWEEP-VTH160_000.";}
 	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiMC(Dir,file,100,30,130,0.,10.); 
	}

}


void CERN_TOT()
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 60;
	xmax = 300;
	par0 = 5;
	par1 = 0.06;
	NEVT = 50;
	TString file,Dir, Dir0, fileL, fileF;
	Int_t it=0;

 // PREIRRADIATION

	Dir0 = "data/CERN/board4/Preirraggiamento/TEMP-20C/";
        it=4;
	while ( it<4 )  {
		it++;
		Dir = Dir0+"";	

		if (it==1 ) file =  "20170227233641_TO2-LOWTOT-LINEARITY_000.";
		if (it==2 ) file =  "20170227233907_TO1-LOWTOT-LINEARITY_000.";
		if (it < 3 ) { xmin=60;
		  xmax=300; }
		else {  xmin=65;
		  xmax=105; }
		if (it==3 ) file =  "20170227233528_TO2-FASTTOT-LINEARITY_000.";
		if (it==4 ) file =  "20170227233755_TO1-FASTTOT-LINEARITY_000.";

		Macro_ToT(Dir,file,xmin,xmax,par0,par1,NEVT);
		analisiMCTOT(Dir,file,150,-6,6,0.,0.6); 
	}

        fileL = "20170227233641_TO2-LOWTOT-LINEARITY_000.";
        fileF = "20170227233528_TO2-FASTTOT-LINEARITY_000.";    
        analisiTOT_freq(Dir0,fileL,fileF,45,100,500);

        fileL = "20170227233907_TO1-LOWTOT-LINEARITY_000.";
        fileF = "20170227233755_TO1-FASTTOT-LINEARITY_000.";    
        analisiTOT_freq(Dir0,fileL,fileF,45,100,500);





// After 600 Mrad -20C

	Dir0 = "data/CERN/board4/Annealing/-20C/";
        it=4;
	Dir = Dir0+"";	
	while ( it<4 )  {
		it++;
		//	Dir = Dir0+"";	

		if (it==1 ) file =  "20170306063318_TO1-LOWTOT-LINEARITY_013.";
		if (it==2 ) file =  "20170306063053_TO2-LOWTOT-LINEARITY_013.";
		if (it < 3 ) { xmin=60;
		  xmax=300; }
		else {  xmin=65;
		  xmax=125; }
		if (it==3 ) file =  "20170306063206_TO1-FASTTOT-LINEARITY_013.";
		if (it==4 ) file =  "20170306062939_TO2-FASTTOT-LINEARITY_013.";

		Macro_ToT(Dir,file,xmin,xmax,par0,par1,NEVT);
		analisiMCTOT(Dir,file,150,-6,6,0.,0.6); 

	}

        fileL = "20170306063053_TO2-LOWTOT-LINEARITY_013.";
        fileF = "20170306062939_TO2-FASTTOT-LINEARITY_013.";    
        analisiTOT_freq(Dir,fileL,fileF,45,100,500);
        fileL = "20170306063318_TO1-LOWTOT-LINEARITY_013.";
        fileF = "20170306063206_TO1-FASTTOT-LINEARITY_013.";    
        analisiTOT_freq(Dir,fileL,fileF,45,100,500);

}


void CERN_BaselineL(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 20;
	xmax = 7000;
	par0 = 10;
	par1 = 0.0002;
	NEVT = 50;
	TString file,Dir, Dir0, fileL, fileF;
	Int_t it;

 // --- Several steps of irradiation

	Dir0 = "data/CERN/board4/Step5-irraggiamento-continuo-40kV-50mA-4cm/";
        it=24;
	while ( it<24 )  {
		it++;
              
		Dir = Dir0+"";	

                if (it==i)  {
		// 200 Mrad - first day at high irradiation
		if (it==1 ) file =  "20170302154436_TO2-BASELINE-LONG_000.";
		// 23
		if (it==2 ) file =  "20170302205648_TO2-BASELINE-LONG_006.";
                // 260
		if (it==3 ) file =  "20170303020521_TO2-BASELINE-LONG_012.";
                // 290
  		if (it==4 ) file =  "20170303071554_TO2-BASELINE-LONG_018.";
		// 310
		if (it==5 ) file =  "20170303122932_TO2-BASELINE-LONG_024.";    
		if (it==6 ) file =  "20170303185702_TO2-BASELINE-LONG_000.";
		if (it==7 ) file =  "20170303231837_TO2-BASELINE-LONG_005.";
		if (it==8 ) file =  "20170304053513_TO2-BASELINE-LONG_012.";
		if (it==9 ) file =  "20170304110253_TO2-BASELINE-LONG_018.";
		if (it==10 ) file =  "20170304173507_TO2-BASELINE-LONG_025.";
		if (it==11 ) file =  "20170304222135_TO2-BASELINE-LONG_030.";
		if (it==12 ) file =  "20170305040448_TO2-BASELINE-LONG_036.";
		if (it==13 ) file =  "20170305094533_TO2-BASELINE-LONG_042.";
		if (it==14 ) file =  "20170305152908_TO2-BASELINE-LONG_048c.";
		if (it==15 ) file =  "20170305213446_TO2-BASELINE-LONG_003c.";
		// 550 Mrad
		if (it==16 ) file =  "20170306031533_TO2-BASELINE-LONG_009c.";

		Macro_ToT(Dir,file,xmin,xmax,par0,par1,NEVT);
		analisiMCTOT(Dir,file,20,2,22.,2.E-6,5E-4); 
	}
	}

 // --- Annealing 20C

	Dir0 = "data/CERN/board4/Annealing/roomTemp/AllCH/";
        it=0;
        xmax = 1800;
	while ( it<6 )  {
		it++;
              
		Dir = Dir0+"";	

                if (it==i)  {
		// 14h
		if (it==1 ) file =  "20170306221202_TO2-BASELINE_000c.";
		// 24h
		if (it==2 ) file =  "20170307082509_TO2-BASELINE_004c.";
                // 35h
		if (it==3 ) file =  "20170307190848_TO2-BASELINE_002c.";
                // 290
  		if (it==4 ) file =  "20170308125621_TO2-BASELINE_001c.";
		// 310
  		if (it==5 ) file =  "20170309112728_TO2-BASELINE_000c.";
		// 310
	
		Macro_ToT(Dir,file,xmin,xmax,par0,par1,NEVT);
		analisiMCTOT(Dir,file,20,2,22.,2.E-6,2.5E-3); 
	}
	}


}


void Unirr_Baseline(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 20;
	xmax = 7000;
	par0 = 10;
	par1 = 0.0002;
	NEVT = 50;
	TString file,Dir, Dir0, fileL, fileF;
	Int_t it;

 // --- Several steps of irradiation

	Dir0 = "data/Board1/CERN_meaasurements/";
        it=0;
	//        xmax= 1800;
	while ( it<1 )  {
		it++;
              
		Dir = Dir0+"";	

                if (it==i)  {
		// 
		if (it==1 ) file =  "20170320121939_TO2-BASELINE_000c.";
		// 23

		Macro_ToT(Dir,file,xmin,xmax,par0,par1,NEVT);
		analisiMCTOT(Dir,file,20,2,22.,2.E-6,5E-4); 
	}
	}

}
void Special_tests()
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 45;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;

	/// CHIP irraggiato !!!!!

	Dir0 = "data/CERN/board4/Annealed/SpecialTests/";

        it=7;
	while ( it<9 )  {
		it++;
	 Dir = Dir0+"";	
         if (it==1 ) {  par0=40; 
	   file =  "LowThreshold_Ifeed5."; }
	 if (it==2 ) { par0=50;
	   file =  "LowThreshold_Ifeed20.";}
	 if (it==3 ) { par0=50;
	   file =  "LowThreshold_Ifeed40.";}
	 if (it==4 ) { par0=50;
	   file =  "LowThreshold_Ifeed5-Ibiasx3.";}
	 if (it==5 ) { par0=50;
	   file =  "LowThreshold_Ifeed5-Ibiasx6.";}
	 if (it==6 ) { par0=50;
	   file =  "LowThreshold_Ifeed80-Ibiasx05.";}
	 if (it==7 ) { par0=50;
	   file =  "LowThreshold_Ifeed80-Ibiasx03.";}
	 if (it==8 ) { NEVT=200;
           par0 = 35.;
	   file =  "FastToT-StressTest.";}
	 if (it==9 ) { par0=50;
	   file =  "FastToT-StressTest-referenceMASKED.";}


 	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 //	 analisiMC(Dir,file,100,20,120,0.,5.); 
	 analisiMC(Dir,file,40,20,60,1.,4.); 

	}

}


void TwoDim_Plots(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 45;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;

	Dir0 = "data/CERN/board4/Annealed/Ifeed75-Vbl350/";

        it=0;
        float_t tmax,tmin;
        tmin=20.;
        tmax=100;
	while ( it<250 )  {
		it++;
		if (it==i ) {

         if (it==1 ) {  par0=40; 
	   file =  "20170321172719_TO2-CALSWEEP-VTH60_000."; }
	 if (it==2 ) { par0=50;
	   file =  "20170321173639_TO2-CALSWEEP-VT100_000.";}
	 if (it==3 ) { par0=65;
	   file =  "20170321180512_TO1-CALSWEEP-VTH35_000.";}	
	 if (it==4 ) { par0=75; 
	   file =  "20170321175544_TO2-CALSWEEP-VTH180_000.";}
	 if (it==5 ) { par0=75; 
	   file =  "Vth60-CalSweep-Ifeed75-C6F.";
	   Dir0 = "data/CERN/board4/Annealed/SpecialTests/";}
	 if (it==6 ) { par0=75; 
	   file =  "LowThreshold_Ifeed5.";
	   Dir0 = "data/CERN/board4/Annealed/SpecialTests/";}
	 if (it==7 ) { par0=75; 
	   file =  "LowThreshold_Ifeed5-TPphase2500.";
	   Dir0 = "data/CERN/board4/Annealed/SpecialTests/";}
	 if (it==8 ) { par0=75; 
	   file =  "LowThreshold_Ifeed5-TPphase3600.";
	   Dir0 = "data/CERN/board4/Annealed/SpecialTests/";}
	 if (it==9 ) { par0=75; 
	   file =  "VTH60-CalSweep-TO2.";
	   Dir0 = "data/Board1/CERN_meaasurements/SpecialTests/";}
	 if (it==10 ) { par0=75; 
	   file =  "VTH60-CalSweep-TO2-Ifeed5.";
	   Dir0 = "data/Board1/CERN_meaasurements/SpecialTests/";}
	 if (it==11 ) { par0=75; 
	   file =  "STRESS-TEST-VTH60-CalSweep-TO2.";
	   Dir0 = "data/Board1/CERN_meaasurements/SpecialTests/";}
	 if (it==12 ) { par0=75; 
	   file =  "VTH60-CalSweep-TO2-Ifeed120.";
	   Dir0 = "data/Board1/CERN_meaasurements/SpecialTests/";}
	 if (it==13 ) { par0=35; 
	   file =  "VTH60-CalSweep-TO2-Ifeed5-C6F.";
	   Dir0 = "data/Board1/CERN_meaasurements/SpecialTests/";}
	 if (it==14 ) { par0=35; 
	   file =  "VTH60-CalSweep-TO2-IPHI-8.";
	   Dir0 = "data/Board1/CERN_meaasurements/SpecialTests/";}
	 if (it==15 ) { par0=35; 
	   file =  "VTH60-CalSweep-TO2-IPHI-15.";
	   Dir0 = "data/Board1/CERN_meaasurements/SpecialTests/";}
	 if (it==16 ) { par0=35; 
	   file =  "VTH60-CalSweep-TO2-IPHI-24.";
	   Dir0 = "data/Board1/CERN_meaasurements/SpecialTests/";}

	 if (it==17 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-std.";
	   Dir0 = "data/board9/special-test/";}

	 if (it==18 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP0.";
	   Dir0 = "data/board9/special-test/";}

	 if (it==19 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1000.";
	   Dir0 = "data/board9/sTP1200ecial-test/";}

	 if (it==20 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200.";
	   Dir0 = "data/board9/special-test/";}

	 if (it==21 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP800.";
	   Dir0 = "data/board9/special-test/";}
	 if (it==22 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1350.";    //////////////////////////
	   Dir0 = "data/board9/special-test/";}

	 if (it==23 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1275.";
	   Dir0 = "data/board9/special-test/";}

  	 if (it==24 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP2000.";
	   Dir0 = "data/board9/special-test/";}

 	 if (it==25 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP2500.";
	   Dir0 = "data/board9/special-test/";}

 	 if (it==26 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP3000.";
	   Dir0 = "data/board9/special-test/";}

 	 if (it==27 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP3500.";
	   Dir0 = "data/board9/special-test/";}



	 if (it==28 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1000-IFEED40.";
	   Dir0 = "data/board9/special-test/";}

	 if (it==29 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP800-IFEED40.";
	   Dir0 = "data/board9/special-test/";}

	 if (it==30 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP900-IFEED40.";
	   Dir0 = "data/board9/special-test/";}
/// ======================================
	  if (it>30) NEVT = 100;

	 if (it==31 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED05.";
	   Dir0 = "data/board9/special-test/";
           tmin=48;
            tmax=62;}
            
	 if (it==32 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED05_IBIAS200-300.";
	   Dir0 = "data/board9/special-test/";
           tmin=48;
            tmax=62;}
                       
	 if (it==33 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED05_IBIAS200-300_IBIASSF200.";
	   Dir0 = "data/board9/special-test/";
           tmin=48;
            tmax=62;   }

	 if (it==34 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED05_IBIAS200-300_IBIASSF200_IBIASDISC300.";
	   Dir0 = "data/board9/special-test/";
 	   tmin=48;
            tmax=62;}

	 if (it==35 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED05_IBIAS400-600.";
	   Dir0 = "data/board9/special-test/";
	   tmin=48;
           tmax=65;}
	 if (it==36 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED05_IBIAS600-900.";
	   Dir0 = "data/board9/special-test/";
	   tmin=48;
           tmax=62;}
	 if (it==37 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED05_IBIAS80-120.";
	   Dir0 = "data/board9/special-test/";
	   tmin=48;
           tmax=62;}

	 if (it==38 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED05_IBIASDISC300_IBIAS50-100.";
	   Dir0 = "data/board9/special-test/";
	   tmin=43;
           tmax=57;}
	if (it==39 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED05_IBIASDISC400_IBIAS100-150.";
	   Dir0 = "data/board9/special-test/";
	   tmin=43;
           tmax=57;}

	if (it==40 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED05_IBIASDISC300_IBIAS100-150.";
	   Dir0 = "data/board9/special-test/";
	   tmin=43;
           tmax=57;}
	if (it==41 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED75_IBIASDISC200_IBIAS50-100.";
	   Dir0 = "data/board9/special-test/";
	   tmin=32;
           tmax=45;}
	if (it==42 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED75_IBIASDISC400_IBIAS50-100.";
	   Dir0 = "data/board9/special-test/";
	   tmin=32;
           tmax=45;}
	if (it==43 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED75_IBIASDISC300_IBIAS50-100.";
	   Dir0 = "data/board9/special-test/";
	   tmin=32;
           tmax=45;}
	if (it==44 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED75_IBIASDISC400_IBIAS100-150.";
	   Dir0 = "data/board9/special-test/";
	   tmin=32;
           tmax=45;}
	if (it==45 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED75_IBIASDISC300_IBIAS100-150.";
	   Dir0 = "data/board9/special-test/";
	   tmin=32;
           tmax=45;}
	if (it==46 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED75_IBIASDISC600_IBIAS100-150.";
	   Dir0 = "data/board9/special-test/";
	   tmin=32;
           tmax=45;}

	if (it==47 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED75_IBIASDISC200_IBIAS60-90.";
	   Dir0 = "data/board9/special-test/";
	   tmin=30;
           tmax=45;}

	if (it==48 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED75_IBIASDISC200_IBIAS30-45.";
	   Dir0 = "data/board9/special-test/";
	   tmin=30;
           tmax=45;}

	if (it==49 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED75_IBIASDISC200_IBIAS50-75.";
	   Dir0 = "data/board9/special-test/";
	   tmin=30;
           tmax=45;}
	if (it==50 ) { par0=35; 
	   file =  "TO2-VTH60-CALSWEEP-TP1200-IFEED75_IBIASDISC200_IBIAS75-114.";
	   Dir0 = "data/board9/special-test/";
	   tmin=30;
           tmax=45;}

///////// TP scan IBIAS 50-75


	if (it==51 ) { par0=35; 
	   file =  "20170510175355_TO2-TP1200-ID300-IB50-75_000.";
	   Dir0 = "data/board9/special-test/IBIAS50-75/";
	   tmin=30;
           tmax=45;}
	if (it==52 ) { par0=35; 
	   file =  "20170510180449_TO2-TP1000-ID300-IB50-75_000.";
	   Dir0 = "data/board9/special-test/IBIAS50-75/";
	   tmin=30;
           tmax=45;}
	if (it==53 ) { par0=35; 
	   file =  "20170510181541_TO2-TP800-ID300-IB50-75_000.";
	   Dir0 = "data/board9/special-test/IBIAS50-75/";
	   tmin=30;
           tmax=45;}
	if (it==54 ) { par0=35; 
	   file =  "20170510182631_TO2-TP600-ID300-IB50-75_000.";
	   Dir0 = "data/board9/special-test/IBIAS50-75/";
	   tmin=30;
           tmax=45;}
	if (it==55 ) { par0=35; 
	   file =  "20170510183723_TO2-TP400-ID300-IB50-75_000.";
	   Dir0 = "data/board9/special-test/IBIAS50-75/";
	   tmin=30;
           tmax=45;}
	if (it==56 ) { par0=35; 
	   file =  "20170510184813_TO2-TP200-ID300-IB50-75_000.";
	   Dir0 = "data/board9/special-test/IBIAS50-75/";
	   tmin=30;
           tmax=45;}
	if (it==57 ) { par0=35; 
	   file =  "20170510185904_TO2-TP0-ID300-IB50-75_000.";
	   Dir0 = "data/board9/special-test/IBIAS50-75/";
	   tmin=30;
           tmax=45;}

	if (it==58 ) { par0=35; 
	   file =  "20170510190359_TO2-TP1400-ID300-IB50-75_000.";
	   Dir0 = "data/board9/special-test/IBIAS50-75/";
	   tmin=30;
           tmax=45;}

	if (it==59 ) { par0=35; 
	   file =  "20170510191450_TO2-TP1600-ID300-IB50-75_000.";
	   Dir0 = "data/board9/special-test/IBIAS50-75/";
	   tmin=30;
           tmax=45;}

	 Dir = Dir0+"";	
         Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
         analisiMC(Dir,file,40,20,60,1.,4.); 
	}
	}
}


void TwoDim_Plots_20MHz(Int_t i)
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 45;
	par1 = 2.;
	NEVT = 50;
	TString file,Dir, Dir0;
	Int_t it=0;

	Dir0 = "data/board9/20MHz-results/";

        it=0;
        float_t tmax,tmin;
        tmin=20.;
        tmax=100;
	while ( it<250 )  {
		it++;
		if (it==i ) {

         if (it==1 ) {  par0=40; 
	   file =  "TO2-VTH60-TP2900-VBL370."; }

	 Dir = Dir0+"";	
         Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 analisiTHR2(Dir,file,320,tmin,tmax,0.,10.,23.); 
         analisiMC(Dir,file,40,20,60,1.,4.); 
	}
	}
}


void Sensor12_CAL(Int_t i )
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 60;
	xmax = 300;
	par0 = -0.1;
	par1 = 0.06;
	NEVT = 50;
	TString file,Dir, Dir0, fileL, fileF;
	Int_t it=0;

	Dir0 = "data/Sensore12/Calibration/Calibration/";
       
	while ( it<4 )  {
		it++;
                if (it==i) {
		Dir = Dir0+"";	

		if (it==1 ) file =  "FastToT100-IFeed150-CAL-TO2.";
		if (it==2 ) file =  "FastToT100-IFeed150-CAL-TO1.";

		Macro_ToT(Dir,file,xmin,xmax,par0,par1,NEVT);
		analisiMCTOT(Dir,file,150,-2,2,0.,0.2); 
		//		Macro_scurve(Dir,file,xmin,90,47,3,NEVT);
		//		analisiMC(Dir,file,150,20,100,0.,6); 
		}
	}

}



void Analysis(Int_t i){
  //   PADOVA_Annealing();
  //   CERN_Annealing();
  // CERN_beforeT25C();
  //   CERN_afterT25C();
  // CERN_afterTm20C();
  //  CERN_beforeTm20C();
  //   TDR_Plots();
//   TwoDim_Plots(i);
//  TwoDim_Plots_20MHz(i);
  // CERN_beforeT25C();
  //     CERN_TOT();

  Sensor12_CAL(i);
  //      Special_tests();
  //  CERN_BaselineL(i);
 //  Unirr_Baseline(i);
}
