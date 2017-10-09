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


void Analysis(){
    
    BGPVanalysis();
    //    Macro_loop_Annealing();
    //    err =  	Macro_loop_ToT();   --- da finire
    //

   if ( Board == 4 && Case == 0) { 

   Dir = "C:/Users/CHIPIX65/My Documents/LabVIEW Data/CHIPIX65_DATA/Board4/Misure/MisureTORINO-old/";
 
// TO Fit Curve a S  VCAL sweep
    if (TO == 1) {

	par0 = 45;
	par1 = 2.5;
	NEVT = 50;
	it == 0;
    while ( it<5 )  {
		it++;
		
     if (it==1 ) file =  "20170125093629_TO2-VCAL-SCAN_000.";
     if (it==2 ) file =  "20170125094818_TO1-VCAL-SCAN_000.";

	
//    if (it==1 ) file =  "20170124353027_TO2-VCAL-SCAN_000.";
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
    analisiMC(Dir,file,70,30,100,0.,5.);
      }
	} 

    if (BG == 1 ) {
		
	par0 = 60;
	par1 = 2.5;
	NEVT = 50;		
		
    it ==0;
    while ( it<3  )  {
		it++;
		
     if (it==1 ) file =  "20170125100113_BGPV-VCAL-SCAN_000.";

//    if (it==1 ) file =  "20170124353027_TO2-VCAL-SCAN_000.";
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
    analisiMC(Dir,file,70,30,200,0.,5.);

      }					
	}			
  }
	
}

// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 45;
	par1 = 2.5;
	NEVT = 50;
	
	TString file, Mfile, Ofile, Efile,Dir, Dir0;
    Int_t it=0;
    Int_t TO=1;
	Int_t BG=1;
    Int_t Board = 7;
	Int_t Case = 1;
    Int_t S_Curve = 0;
	Int_t Plot = 0;

	xmin = 30;
	xmax = 300;

    par0 = 45;
	par1 = 3.5;
	NEVT = 50;
	
	it = 0;
    Dir0 = "/afs/cern.ch/delphi/scratch/d/demaria/Padova/board_7/";
//    Dir0 = "$SCRATCH/Padova/board_7/";

//     Dir0 = "C:/Users/CHIPIX65/My Documents/LabVIEW Data/CHIPIX65_DATA/Padova/board_7/";

// === PRE-IRR
    while ( it<3 )  {
		it++;
	 Dir = Dir0+"pre-irraggiamento/";	

	 if (it==1 ) file =  "20170126122839_TO2-VCAL-SCAN_000.";
	 if (it==2 ) file =  "20170126124119_TO1-VCAL-SCAN_000.";
	 if (it==3 ) file =  "20170126125652_BGPV-VCAL-SCAN_000.";	

         Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
      if (it==3) {	 analisiMC(Dir,file,70,30,200,0.,5.); }
	    else {       analisiMC(Dir,file,70,30,100,0.,5.); }
    }
	
// == during 200krad irr
    it = 3;
    while ( it<3  )  {
	 it++;
     Dir = Dir0+"200krad_irr/";	
     if (it==1 ) file =  "20170126134139_TO2-VCAL-SCAN_000.";	
//     Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
     analisiMC(Dir,file,70,30,100,0.,5.);
    } 		

// ==== post 200krad 

//    it = 0;
    while ( it<3   )  {
	 it++;
	 Dir = Dir0+"200krad_post_irr/";	
 	 if (it==1 ) file = "20170126134712_TO2-VCAL-SCAN_000.";
	 if (it==2 ) file =  "20170126135950_TO1-VCAL-SCAN_000.";	
     if (it==3 ) file =  "20170126141458_BGPV-VCAL-SCAN_000.";	
      Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
   	 if (it==3) {
		 analisiMC(Dir,file,70,30,200,0.,5.);
		 }
	 else { 
     analisiMC(Dir,file,70,30,100,0.,5.);
	 }	 
    } 		
	
// ==== post 600krad 
//	it = 0;
    while ( it<3   )  {
	 it++;
	 Dir = Dir0+"600krad_post_irr/";	
 	 if (it==1 ) file = "20170126155216_TO2-VCAL-SCAN_000.";
	 if (it==2 ) file =  "20170126160440_TO1-VCAL-SCAN_000.";	
	 if (it==3 ) file =  "20170126162004_BGPV-VCAL-SCAN_000.";	
         Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 if (it==3) {
		 analisiMC(Dir,file,70,30,200,0.,5.);
		 }
	 else { 
     analisiMC(Dir,file,70,30,100,0.,5.);
	 }
    }

// ==== post 400krad  				
//    it = 0;
    while ( it<3   )  {
	 it++;
	 Dir = Dir0+"400krad_post_irr/";	
 	 if (it==1 ) file = "20170126145013_TO2-VCAL-SCAN_000.";
	 if (it==2 ) file =  "20170126150241_TO1-VCAL-SCAN_000.";	
	 if (it==3 ) file =  "20170126151801_BGPV-VCAL-SCAN_000.";	
     Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);	 
	 	 	 if (it==3) {
		 analisiMC(Dir,file,70,30,200,0.,5.);
		 }
	 else { 
     analisiMC(Dir,file,70,30,100,0.,5.);
	 }
    } 		

// ==== post 800krad 	
//    it = 0;
    while ( it<3   )  {
	 it++;
	 Dir = Dir0+"800krad_post_irr/";	
 	 if (it==1 ) file = "20170126165257_TO2-VCAL-SCAN_000.";
	 if (it==2 ) file =  "20170126170526_TO1-VCAL-SCAN_000.";	
	 if (it==3 ) file =  "20170126172100_BGPV-VCAL-SCAN_000.";	
        Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT); 
	 	 if (it==3) {
		 analisiMC(Dir,file,70,30,200,0.,5.);
		 }
	 else { 
     analisiMC(Dir,file,70,30,100,0.,5.);
	   } 
    } 


// ==== post 38 Mrad

//    it = 0;
    while ( it<3   )  {
	 it++;
	 	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.5;
	NEVT = 50;
	 
//	 Dir = Dir0+"2017-01-27_09-00_post_irr/";	
	 Dir = Dir0+"38Mrad_post_irr/";	
 	 if (it==1 ) file = "20170127091958_TO2-VCAL-SCAN_000.";
	 if (it==2 ) file =  "20170127093604_TO1-VCAL-SCAN_000.";	
	 if (it==3 ) file =  "20170127095654_BGPV-VCAL-SCAN_000.";	
     Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT); 
	 	 if (it==3) {
		 analisiMC(Dir,file,70,30,200,0.,5.);
		 }
	 else { 
     analisiMC(Dir,file,70,30,100,0.,5.);
	   } 
    } 


// it = 0;
    while ( it<1   )  {
	 it++;
	 	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.5;
	NEVT = 50;
	 
	 Dir = Dir0+"2017-01-27_09-00_post_irr/backup/";	
 	 if (it==1 ) file = "20170127104943_TO2-VCAL-SCAN_000.";
     Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT); 
	 	 if (it==3) {
		 analisiMC(Dir,file,70,30,200,0.,5.);
		 }

	 else { 
     analisiMC(Dir,file,70,30,100,0.,5.);
	   } 
    } 

//   ===== 237 MRad

//    it = 0;
	it=6;
    while ( it<5   )  {
	 it++;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 5.5;
	NEVT = 25;
	 
	 Dir = Dir0+"237Mrad_post_irr/";	
 	 if (it==1 ) file = "20170130120135_TO2-VCAL-SCAN_000.";
 	 if (it==2 ) file = "20170130125516_TO2-VCAL-SCAN_001.";
 	 if (it==3 ) file = "20170130134709_TO2-VCAL-SCAN_002.";
 	 if (it==4 ) file = "20170130121207_TO1-VCAL-SCAN_000.";
 	 if (it==5 ) file = "20170130130757_TO1-VCAL-SCAN_001.";
 	 if (it==6 ) file = "20170130123112_BGPV-VCAL-SCAN_000.";
     Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT); 
	 	 if (it==4) {
		 analisiMC(Dir,file,70,30,200,0.,5.);
		 }

	 else {      analisiMC(Dir,file,70,30,100,0.,15.);} 
    } 
}



	
	
void Macro_loop_SCurve()
{
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 45;
	par1 = 2.5;
	NEVT = 50;
	
	TString file, Mfile, Ofile, Efile,Dir;
    Int_t it=0;
    Int_t TO=1;
	Int_t BG=1;
    Int_t Board = 7;
	Int_t Case = 1;

    Int_t S_Curve = 0;
	Int_t Plot = 0;

	xmin = 30;
	xmax = 300;
	
// =================== Misure Board 7 no cavo lungo =============================================================   

   if ( Board == 7 && Case == 0) { 

   Dir = "C:/Users/CHIPIX65/My Documents/LabVIEW Data/CHIPIX65_DATA/Board7/Misure/Misure_TORINO/";
 
// TO Fit Curve a S  VCAL sweep
    if (TO == 1) {

	par0 = 45;
	par1 = 2.5;
	NEVT = 50;
	it == 0;

    while ( it<5 )  {
		it++;
		
     if (it==1 ) file =  "20170125121844_TO2-VCAL-SCAN_000.";
     if (it==2 ) file =  "20170125130436_TO2-VCAL-SCAN_001.";
 	 if (it==3 ) file =  "20170125123037_TO1-VCAL-SCAN_000.";
	 if (it==4 ) file =  "20170125131607_TO1-VCAL-SCAN_001.";	
	
//    if (it==1 ) file =  "20170124353027_TO2-VCAL-SCAN_000.";
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
    analisiMC(Dir,file,70,30,100,0.,5.);


      }
	} 

    if (BG == 1 ) {
		

	par0 = 60;
	par1 = 2.5;
	NEVT = 50;		
		
    it ==0;
    while ( it<3  )  {
		it++;
		
     if (it==1 ) file =  "20170125124412_BGPV-VCAL-SCAN_000.";
     //if (it==2 ) file =  "20170125135213_BGPV-VCAL-SCAN_001.";

//    if (it==1 ) file =  "20170124353027_TO2-VCAL-SCAN_000.";
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
    analisiMC(Dir,file,70,30,200,0.,5.);

      }					
	}			
  }


// =================== Misure Board 7 cavo lungo =============================================================   

   if ( Board == 7 && Case == 1 ) { 

   Dir = "C:/Users/CHIPIX65/My Documents/LabVIEW Data/CHIPIX65_DATA/Board7/Misure/MisureTORINO/";
 
// TO Fit Curve a S  VCAL sweep

 while ( it<5 )  {
		it++;
		
    if (it==1 ) file =  "20170125121844_TO2-VCAL-SCAN_000.";
     if (it==2 ) file =  "20170125130436_TO2-VCAL-SCAN_001.";
 	 if (it==3 ) file =  "20170125123037_TO1-VCAL-SCAN_000.";
	 if (it==4 ) file =  "20170125131607_TO1-VCAL-SCAN_001.";	
	
//    if (it==1 ) file =  "20170124353027_TO2-VCAL-SCAN_000.";
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
    analisiMC(Dir,file,70,30,100,0.,5.);


      }
  }
  

// ====================== Board 4 cavo lungo ===================

   if ( Board == 4 && Case == 0) { 

   Dir = "C:/Users/CHIPIX65/My Documents/LabVIEW Data/CHIPIX65_DATA/Board4/Misure/MisureTORINO-old/";
 
// TO Fit Curve a S  VCAL sweep
    if (TO == 1) {

	par0 = 45;
	par1 = 2.5;
	NEVT = 50;
	it == 0;
    while ( it<5 )  {
		it++;
		
     if (it==1 ) file =  "20170125093629_TO2-VCAL-SCAN_000.";
     if (it==2 ) file =  "20170125094818_TO1-VCAL-SCAN_000.";

	
//    if (it==1 ) file =  "20170124353027_TO2-VCAL-SCAN_000.";
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
    analisiMC(Dir,file,70,30,100,0.,5.);
      }
	} 

    if (BG == 1 ) {
		
	par0 = 60;
	par1 = 2.5;
	NEVT = 50;		
		
    it ==0;
    while ( it<3  )  {
		it++;
		
     if (it==1 ) file =  "20170125100113_BGPV-VCAL-SCAN_000.";

//    if (it==1 ) file =  "20170124353027_TO2-VCAL-SCAN_000.";
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
    analisiMC(Dir,file,70,30,200,0.,5.);

      }					
	}			
  }
	
}
	Macro_loop_Irr_VSCAN();

}

void  pippo(){

}


 BGPVanalysis(){
// ===========================================================================================================================
        Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 10;
	xmax = 150;
        par0 = 80;
        par1 = 2.6;
	
	TString file, Mfile, Ofile, Efile,Dir, Dir0;
        Int_t it=0;
        Int_t TO=1;
	Int_t BG=1;
        Int_t Board = 7;
	Int_t Case = 1;
        Int_t S_Curve = 0;
	Int_t Plot = 0;

	NEVT = 50;
	
	it = 0;
//    Dir0 = "/afs/cern.ch/delphi/scratch/d/demaria/Padova/board_7/";
//    Dir0 = "$SCRATCH/Padova/board_7/";
    Dir0 = "BGPV/";

    while ( it<3 )  {
		it++;
	 Dir = Dir0+"";	

	 if (it==1 ) { file =  "B4_IGDAC550_ILDAC160_e1_bis.";
	   NEVT=50.;
         }
         if (it==2 ) {
	   file =  "B4_IGDAC550_ILDAC250_TRIM_e8.";
           par0 = 80;
           par1 = 2.6;
	 }
         if (it==3 ) { 
	    file =  "B4_IGDAC500_ILDAC250_TRIM_e8.";
	    //
            par0 = 90;
            par1 = 2.6;
         }
         if (it==4 ) { 
	   file =  "B4_IGDAC450_ILDAC250_TRIM_e8.";
	   par0 = 80;
	   par1 = 2.6;
	 }
         if (it==5 ) { 
	   file =  "B4_IGDAC330_ILDAC250_TRIM_e8.";
	   par0 = 50;
	   par1 = 2.6;
	 }
         if (it==6 ) { 
	   file =  "B4_IGDAC320_ILDAC250_TRIM_e8.";
	   par0 = 40;
           par1 = 2.6;
	 }
         if (it==7 ) { 
	   file =  "B4_IGDAC310_ILDAC250_TRIM_e8.";
	   par0 = 40;
           par1 = 2.6;
	 }
	   NEVT=50.;
     //	 	Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	        analisiMC(Dir,file,20,60.,130.,0.,7.); 
     //         generateTRIM(Dir,file,0,300);
    }

}


void Macro_loop_Irr_VSCAN()
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 45;
	par1 = 2.5;
	NEVT = 50;
	
	TString file, Mfile, Ofile, Efile,Dir, Dir0;
    Int_t it=0;
    Int_t TO=1;
	Int_t BG=1;
    Int_t Board = 7;
	Int_t Case = 1;
    Int_t S_Curve = 0;
	Int_t Plot = 0;

	xmin = 30;
	xmax = 300;

    par0 = 45;
	par1 = 3.5;
	NEVT = 50;
	
	it = 0;
    Dir0 = "/afs/cern.ch/delphi/scratch/d/demaria/Padova/board_7/";
//    Dir0 = "$SCRATCH/Padova/board_7/";

//     Dir0 = "C:/Users/CHIPIX65/My Documents/LabVIEW Data/CHIPIX65_DATA/Padova/board_7/";

// === PRE-IRR
    while ( it<3 )  {
		it++;
	 Dir = Dir0+"pre-irraggiamento/";	

	 if (it==1 ) file =  "20170126122839_TO2-VCAL-SCAN_000.";
	 if (it==2 ) file =  "20170126124119_TO1-VCAL-SCAN_000.";
	 if (it==3 ) file =  "20170126125652_BGPV-VCAL-SCAN_000.";	

         Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
      if (it==3) {	 analisiMC(Dir,file,70,30,200,0.,5.); }
	    else {       analisiMC(Dir,file,70,30,100,0.,5.); }
    }
	
// == during 200krad irr
    it = 3;
    while ( it<3  )  {
	 it++;
     Dir = Dir0+"200krad_irr/";	
     if (it==1 ) file =  "20170126134139_TO2-VCAL-SCAN_000.";	
//     Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
     analisiMC(Dir,file,70,30,100,0.,5.);
    } 		

// ==== post 200krad 

//    it = 0;
    while ( it<3   )  {
	 it++;
	 Dir = Dir0+"200krad_post_irr/";	
 	 if (it==1 ) file = "20170126134712_TO2-VCAL-SCAN_000.";
	 if (it==2 ) file =  "20170126135950_TO1-VCAL-SCAN_000.";	
     if (it==3 ) file =  "20170126141458_BGPV-VCAL-SCAN_000.";	
      Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
   	 if (it==3) {
		 analisiMC(Dir,file,70,30,200,0.,5.);
		 }
	 else { 
     analisiMC(Dir,file,70,30,100,0.,5.);
	 }	 
    } 		
	
// ==== post 600krad 
//	it = 0;
    while ( it<3   )  {
	 it++;
	 Dir = Dir0+"600krad_post_irr/";	
 	 if (it==1 ) file = "20170126155216_TO2-VCAL-SCAN_000.";
	 if (it==2 ) file =  "20170126160440_TO1-VCAL-SCAN_000.";	
	 if (it==3 ) file =  "20170126162004_BGPV-VCAL-SCAN_000.";	
         Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
	 if (it==3) {
		 analisiMC(Dir,file,70,30,200,0.,5.);
		 }
	 else { 
     analisiMC(Dir,file,70,30,100,0.,5.);
	 }
    }

// ==== post 400krad  				
//    it = 0;
    while ( it<3   )  {
	 it++;
	 Dir = Dir0+"400krad_post_irr/";	
 	 if (it==1 ) file = "20170126145013_TO2-VCAL-SCAN_000.";
	 if (it==2 ) file =  "20170126150241_TO1-VCAL-SCAN_000.";	
	 if (it==3 ) file =  "20170126151801_BGPV-VCAL-SCAN_000.";	
     Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);	 
	 	 	 if (it==3) {
		 analisiMC(Dir,file,70,30,200,0.,5.);
		 }
	 else { 
     analisiMC(Dir,file,70,30,100,0.,5.);
	 }
    } 		

// ==== post 800krad 	
//    it = 0;
    while ( it<3   )  {
	 it++;
	 Dir = Dir0+"800krad_post_irr/";	
 	 if (it==1 ) file = "20170126165257_TO2-VCAL-SCAN_000.";
	 if (it==2 ) file =  "20170126170526_TO1-VCAL-SCAN_000.";	
	 if (it==3 ) file =  "20170126172100_BGPV-VCAL-SCAN_000.";	
        Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT); 
	 	 if (it==3) {
		 analisiMC(Dir,file,70,30,200,0.,5.);
		 }
	 else { 
     analisiMC(Dir,file,70,30,100,0.,5.);
	   } 
    } 


// ==== post 38 Mrad

//    it = 0;
    while ( it<3   )  {
	 it++;
	 	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.5;
	NEVT = 50;
	 
//	 Dir = Dir0+"2017-01-27_09-00_post_irr/";	
	 Dir = Dir0+"38Mrad_post_irr/";	
 	 if (it==1 ) file = "20170127091958_TO2-VCAL-SCAN_000.";
	 if (it==2 ) file =  "20170127093604_TO1-VCAL-SCAN_000.";	
	 if (it==3 ) file =  "20170127095654_BGPV-VCAL-SCAN_000.";	
     Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT); 
	 	 if (it==3) {
		 analisiMC(Dir,file,70,30,200,0.,5.);
		 }
	 else { 
     analisiMC(Dir,file,70,30,100,0.,5.);
	   } 
    } 


// it = 0;
    while ( it<1   )  {
	 it++;
	 	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 2.5;
	NEVT = 50;
	 
	 Dir = Dir0+"2017-01-27_09-00_post_irr/backup/";	
 	 if (it==1 ) file = "20170127104943_TO2-VCAL-SCAN_000.";
     Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT); 
	 	 if (it==3) {
		 analisiMC(Dir,file,70,30,200,0.,5.);
		 }

	 else { 
     analisiMC(Dir,file,70,30,100,0.,5.);
	   } 
    } 

//   ===== 237 MRad

//    it = 0;
	it=6;
    while ( it<5   )  {
	 it++;
	xmin = 30;
	xmax = 300;
	par0 = 50;
	par1 = 5.5;
	NEVT = 25;
	 
	 Dir = Dir0+"237Mrad_post_irr/";	
 	 if (it==1 ) file = "20170130120135_TO2-VCAL-SCAN_000.";
 	 if (it==2 ) file = "20170130125516_TO2-VCAL-SCAN_001.";
 	 if (it==3 ) file = "20170130134709_TO2-VCAL-SCAN_002.";
 	 if (it==4 ) file = "20170130121207_TO1-VCAL-SCAN_000.";
 	 if (it==5 ) file = "20170130130757_TO1-VCAL-SCAN_001.";
 	 if (it==6 ) file = "20170130123112_BGPV-VCAL-SCAN_000.";
     Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT); 
	 	 if (it==4) {
		 analisiMC(Dir,file,70,30,200,0.,5.);
		 }

	 else {      analisiMC(Dir,file,70,30,100,0.,15.);} 
    } 
}



	
	
void Macro_loop_SCurve()
{
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 45;
	par1 = 2.5;
	NEVT = 50;
	
	TString file, Mfile, Ofile, Efile,Dir;
    Int_t it=0;
    Int_t TO=1;
	Int_t BG=1;
    Int_t Board = 7;
	Int_t Case = 1;

    Int_t S_Curve = 0;
	Int_t Plot = 0;

	xmin = 30;
	xmax = 300;
	
// =================== Misure Board 7 no cavo lungo =============================================================   

   if ( Board == 7 && Case == 0) { 

   Dir = "C:/Users/CHIPIX65/My Documents/LabVIEW Data/CHIPIX65_DATA/Board7/Misure/Misure_TORINO/";
 
// TO Fit Curve a S  VCAL sweep
    if (TO == 1) {

	par0 = 45;
	par1 = 2.5;
	NEVT = 50;
	it == 0;

    while ( it<5 )  {
		it++;
		
     if (it==1 ) file =  "20170125121844_TO2-VCAL-SCAN_000.";
     if (it==2 ) file =  "20170125130436_TO2-VCAL-SCAN_001.";
 	 if (it==3 ) file =  "20170125123037_TO1-VCAL-SCAN_000.";
	 if (it==4 ) file =  "20170125131607_TO1-VCAL-SCAN_001.";	
	
//    if (it==1 ) file =  "20170124353027_TO2-VCAL-SCAN_000.";
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
    analisiMC(Dir,file,70,30,100,0.,5.);


      }
	} 

    if (BG == 1 ) {
		

	par0 = 60;
	par1 = 2.5;
	NEVT = 50;		
		
    it ==0;
    while ( it<3  )  {
		it++;
		
     if (it==1 ) file =  "20170125124412_BGPV-VCAL-SCAN_000.";
     //if (it==2 ) file =  "20170125135213_BGPV-VCAL-SCAN_001.";

//    if (it==1 ) file =  "20170124353027_TO2-VCAL-SCAN_000.";
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
    analisiMC(Dir,file,70,30,200,0.,5.);

      }					
	}			
  }


// =================== Misure Board 7 cavo lungo =============================================================   

   if ( Board == 7 && Case == 1 ) { 

   Dir = "C:/Users/CHIPIX65/My Documents/LabVIEW Data/CHIPIX65_DATA/Board7/Misure/MisureTORINO/";
 
// TO Fit Curve a S  VCAL sweep

 while ( it<5 )  {
		it++;
		
    if (it==1 ) file =  "20170125121844_TO2-VCAL-SCAN_000.";
     if (it==2 ) file =  "20170125130436_TO2-VCAL-SCAN_001.";
 	 if (it==3 ) file =  "20170125123037_TO1-VCAL-SCAN_000.";
	 if (it==4 ) file =  "20170125131607_TO1-VCAL-SCAN_001.";	
	
//    if (it==1 ) file =  "20170124353027_TO2-VCAL-SCAN_000.";
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
    analisiMC(Dir,file,70,30,100,0.,5.);


      }
  }
  

// ====================== Board 4 cavo lungo ===================

   if ( Board == 4 && Case == 0) { 

   Dir = "C:/Users/CHIPIX65/My Documents/LabVIEW Data/CHIPIX65_DATA/Board4/Misure/MisureTORINO-old/";
 
// TO Fit Curve a S  VCAL sweep
    if (TO == 1) {

	par0 = 45;
	par1 = 2.5;
	NEVT = 50;
	it == 0;
    while ( it<5 )  {
		it++;
		
     if (it==1 ) file =  "20170125093629_TO2-VCAL-SCAN_000.";
     if (it==2 ) file =  "20170125094818_TO1-VCAL-SCAN_000.";

	
//    if (it==1 ) file =  "20170124353027_TO2-VCAL-SCAN_000.";
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
    analisiMC(Dir,file,70,30,100,0.,5.);
      }
	} 

    if (BG == 1 ) {
		
	par0 = 60;
	par1 = 2.5;
	NEVT = 50;		
		
    it ==0;
    while ( it<3  )  {
		it++;
		
     if (it==1 ) file =  "20170125100113_BGPV-VCAL-SCAN_000.";

//    if (it==1 ) file =  "20170124353027_TO2-VCAL-SCAN_000.";
    Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
    analisiMC(Dir,file,70,30,200,0.,5.);

      }					
	}			
  }
	
}



void Macro_loop_Annealing()
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 300;
	par0 = 45;
	par1 = 2.;
	NEVT = 50;
	
	TString file, Mfile, Ofile, Efile,Dir, Dir0;
    Int_t it=0;
    Int_t TO=1;
	Int_t BG=1;
    Int_t Board = 7;
	Int_t Case = 1;
    Int_t S_Curve = 0;
	Int_t Plot = 0;
	xmin = 30;
	xmax = 300;
    par0 = 45;
	par1 = 3.5;
	NEVT = 50;
	
	it = 0;

    Dir0 = "data/Padova/board_7/annealing/";

//     Dir0 = "C:/Users/CHIPIX65/My Documents/LabVIEW Data/CHIPIX65_DATA/Padova/board_7/annealing/";

    it=0;
    par0 = 50;
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
            if (it==99) {	 analisiMC(Dir,file,70,30,200,0.,5.); }
	    else {       analisiMC(Dir,file,50,30,80,0.,5.); }
    }
    return;



// B4-non irraggiata
    it=0;
    par0 = 50;
    while ( it<16 )  {
		it++;
	 Dir = Dir0+"B4-non-irraggiata/11-Feb/";	
     if (it==1 ) file =  "20170210182124_TO2-VCAL-SCAN_000.";
	 if (it==2 ) file =  "20170210201315_TO2-VCAL-SCAN_001.";
	 if (it==3 ) file =  "20170210235212_TO2-VCAL-SCAN_003.";	
	 if (it==4 ) file =  "20170211014219_TO2-VCAL-SCAN_004.";
	 if (it==5 ) file =  "20170211033241_TO2-VCAL-SCAN_005.";
	 if (it==6 ) file =  "20170211052301_TO2-VCAL-SCAN_006.";
	 if (it==7 ) file =  "20170211071301_TO2-VCAL-SCAN_007.";
 if (it==8 ) file =  "20170211105252_TO2-VCAL-SCAN_009.";
 if (it==9 ) file =  "20170211143234_TO2-VCAL-SCAN_011.";
 if (it==10 ) file =  "20170211195447_TO2-VCAL-SCAN_014.";
 if (it==11 ) file =  "20170211233536_TO2-VCAL-SCAN_016.";
 if (it==12 ) file =  "20170212050352_TO2-VCAL-SCAN_019.";
 if (it==13 ) file =  "20170212103434_TO2-VCAL-SCAN_022.";
 if (it==14 ) file =  "20170212160034_TO2-VCAL-SCAN_025.";
 if (it==15 ) file =  "20170213063953_TO2-VCAL-SCAN_033.";
 if (it==16 ) file =  "20170213083013_TO2-VCAL-SCAN_034.";


	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
      if (it==99) {	 analisiMC(Dir,file,70,30,200,0.,5.); }
	    else {       analisiMC(Dir,file,70,30,100,0.,5.); }
    }	
    return;


// B4-non irraggiata
    it=7;
    par0 = 80;
    while ( it<16 )  {
		it++;
	 Dir = Dir0+"B4-non-irraggiata/";	
     if (it==1 ) file =  "20170210150112_TO2-VCAL-SCAN_000.";
	 if (it==2 ) file =  "20170210151431_TO2-VCAL-SCAN_001.";
	 if (it==3 ) file =  "20170210152041_TO2-VCAL-SCAN_000";	
	 if (it==4 ) file =  "20170210152723_TO2-VCAL-SCAN_001.";
	 if (it==5 ) file =  "20170210153522_TO2-VCAL-SCAN_002.";
	 if (it==6 ) file =  "20170210154214_TO2-VCAL-SCAN_003.";
	 if (it==7 ) file =  "20170210154840_TO2-VCAL-SCAN_004.";

 if (it==15 ) file =  "20170210164003_TO2-VCAL-SCAN_000.";
 if (it==10 ) file =  "20170210160900_TO2-VCAL-SCAN_007.";
 if (it==14 ) file =  "20170210163606_TO2-VCAL-SCAN_011.";
 if (it==16 ) file =  "20170210164647_TO2-VCAL-SCAN_001.";
 if (it==12 ) file =  "20170210162233_TO2-VCAL-SCAN_009.";
 if (it==9 ) file =  "20170210160212_TO2-VCAL-SCAN_006.";
 if (it==8 ) file =  "20170210155525_TO2-VCAL-SCAN_005.";
 if (it==13 ) file =  "20170210162920_TO2-VCAL-SCAN_010.";
 if (it==11 ) file =  "20170210161547_TO2-VCAL-SCAN_008.";


	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
      if (it==99) {	 analisiMC(Dir,file,70,30,200,0.,5.); }
	    else {       analisiMC(Dir,file,70,30,100,0.,5.); }
    }	
    return;


// Annealing 9-Feb 
    par0 = 45;
    while ( it<14 )  {
		it++;
	 Dir = Dir0+"Settings-Feb-9/";	
     if (it==1 ) file =  "20170209195057_TO2-VCAL-SCAN_000.";
	 if (it==2 ) file =  "20170209215714_TO2-VCAL-SCAN_001.";
	 if (it==3 ) file =  "20170210000119_TO2-VCAL-SCAN_002.";	
	 if (it==4 ) file =  "20170210020711_TO2-VCAL-SCAN_003.";
	 if (it==5 ) file =  "20170210041147_TO2-VCAL-SCAN_004.";
	 if (it==6 ) file =  "20170210061539_TO2-VCAL-SCAN_005.";
	 if (it==7 ) file =  "20170210081239_TO2-VCAL-SCAN_006.";
	 if (it==8 ) file =  "20170210090922_TO2-VCAL-SCAN_000.";
	 if (it==9 ) file =  "20170210092043_TO2-VCAL-SCAN_001.";
	 if (it==10 ) file =  "20170210093135_TO2-VCAL-SCAN_002.";
	 if (it==11 ) file =  "20170210094253_TO2-VCAL-SCAN_003.";
	 if (it==12 ) file =  "20170210095407_TO2-VCAL-SCAN_004.";
	 if (it==13 ) file =  "20170210100532_TO2-VCAL-SCAN_005.";
	 if (it==14 ) file =  "20170210101702_TO2-VCAL-SCAN_006.";

	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
      if (it==99) {	 analisiMC(Dir,file,70,30,200,0.,5.); }
	    else {       analisiMC(Dir,file,70,30,100,0.,5.); }
    }	
    return;
    it=99;

// === Annealing 7-fe
    while ( it<5 )  {
		it++;
	 Dir = Dir0+"Setting-7-feb/";	
     if (it==1 ) file =  "20170207183248_TO2-VCAL-SCAN_000.";
	 if (it==2 ) file =  "20170208123220_TO2-VCAL-SCAN_001.";
	 if (it==3 ) file =  "20170207190246_TO1-VCAL-SCAN_000.";	
	 if (it==4 ) file =  "20170208130108_TO1-VCAL-SCAN_001.";
	 if (it==5 ) file =  "20170207193125_BGPV-VCAL-SCAN_000.";
	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
      if (it==5) {	 analisiMC(Dir,file,70,30,200,0.,5.); }
	    else {       analisiMC(Dir,file,70,30,100,0.,5.); }
    }	
    it=0;
// === Annealing 6-fe
    while ( it<1 )  {
		it++;
	 Dir = Dir0+"Setting-6-feb/";
	 if (it==1 ) file =  "20170206225708_TO2-VCAL-SCAN_002.";
     if (it==6 ) file =  "20170206153704_TO2-VCAL-SCAN_000.";
	 if (it==2 ) file =  "20170206205449_TO2-VCAL-SCAN_001.";
	 if (it==3 ) file =  "20170206191857_TO1-VCAL-SCAN_000.";	
	 if (it==4 ) file =  "20170206212135_TO1-VCAL-SCAN_001.";
	 if (it==5 ) file =  "20170206194518_BGPV-VCAL-SCAN_000.";
	
	 if (it==7 ) file =  "20170207005931_TO2-VCAL-SCAN_003.";
	 if (it==8 ) file =  "20170207030227_TO2-VCAL-SCAN_004.";
	 if (it==9 ) file =  "20170207050413_TO2-VCAL-SCAN_005.";
	 if (it==10 ) file =  "20170207070609_TO2-VCAL-SCAN_006.";
	 if (it==11 ) file =  "20170207090748_TO2-VCAL-SCAN_007.";

	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
      if (it==5) {	 analisiMC(Dir,file,70,30,200,0.,5.); }
	    else {       analisiMC(Dir,file,70,30,100,0.,5.); }
    }	


	it=44;
	NEVT = 50;

// === 800krad
	Dir0 = "C:/Users/CHIPIX65/My Documents/LabVIEW Data/CHIPIX65_DATA/Padova/board_7/800krad_post_irr/";
    while ( it<2 )  {
		it++;
	 Dir = Dir0+"";	
     if (it==1 ) file =  "20170126165257_TO2-VCAL-SCAN_000.";
	 if (it==2 ) file =  "20170126174440_TO2-VCAL-SCAN_001.";

	 Macro_scurve(Dir,file,xmin,xmax,par0,par1,NEVT);
      if (it==5) {	 analisiMC(Dir,file,70,30,200,0.,5.); }
	    else {       analisiMC(Dir,file,70,30,100,0.,5.); }
    }	
  }



void Macro_loop_ToT() 
{
// ===========================================================================================================================
    Float_t xmin, xmax, par0, par1, NEVT;
	xmin = 30;
	xmax = 140;
	par0 = 45;
	par1 = 2.;
	NEVT = 50;
	
	TString file, Mfile, Ofile, Efile,Dir, Dir0;
    Int_t it=0;
    Int_t TO=1;
	Int_t BG=1;
    Int_t Board = 7;
	Int_t Case = 1;
    Int_t S_Curve = 0;
	Int_t Plot = 0;
	xmin = 50.;
	xmax = 100.;
        par0 = -4;
	par1 = 0.25;
	NEVT = 50;
	
	it = 0;

    Dir0 = "annealing/";

//     Dir0 = "C:/Users/CHIPIX65/My Documents/LabVIEW Data/CHIPIX65_DATA/Padova/board_7/annealing/";

    it=0;
   
    while ( it<1 )  {
		it++;
	 Dir = Dir0+"16-Feb-ShortPHI/";	
     if (it==1 ) file =  "201702161911_STDPARA_B7-VSCAN-320-6-ToTLinearity.";
 	 	 Macro_ToT(Dir,file,xmin,xmax,par0,par1,NEVT);
            	 analisiMCTOT(Dir,file,70,0,10,0.,0.5);
    return;
    }
}
