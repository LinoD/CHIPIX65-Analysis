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



Float_t SCurve(Double_t *xx, Double_t *par){
// -----------------------------------------------------------------------------------------------------------------------------
    return  1./2. * (TMath::Erf((xx[0] - par[0])/(TMath::Sqrt(2)*par[1]))) + 0.5;
}
 // par[0] threshold
 // par[1] sigma della gaussiana

void Macro_scurve(TString Dir, TString filei, Float_t xmin = 30 , Float_t xmax = 60, Float_t par0 = 45 , Float_t par1 = 2, Float_t NEVT=200.){
// ----------------------------------------------------------------------------------------------------------------------------------------    
	Int_t ideb=0;

    TString output_filename, output_filename_error, filename;

    gStyle->SetOptStat(00111111);

    filename = Dir+filei+"txt";	
    output_filename = Dir+"Out/"+filei+"out";		
    output_filename_error = Dir+"Err/"+filei+"err";	

	TString Rfile = Dir+"Out/"+filei+"S_VCAL.root";		
	TString Jfile = Dir+"Out/"+filei+"S_VCAL.pdf";	

//    new TCanvas(filename,filename,600,300);
    TCanvas *cvs = new TCanvas(filename,filename,900,300);
		
//    cout << filename << "\n";
//    cout << output_filename << "\n";
//    cout << output_filename_error << "\n";

//    break;	
    ofstream output_file(output_filename);
	if (output_file.is_open())
	{ cout << "The file: " << output_filename << " IS OPEN " << "\n"; }
	else 
	{ cout << "The file: " << output_filename << " IS NOT OPEN " << "\n";
	 return; }

    ofstream output_file_error(output_filename_error);
	if (output_file_error.is_open())
	{ cout << "The file: " << output_filename_error << " IS OPEN " << "\n"; }
	else 
	{ cout << "The file: " << output_filename_error << " IS NOT OPEN " << "\n";
	  return; }

    ifstream file(filename);
	if (file.is_open())
	{ cout << "The file: " << filename << " IS OPEN " << "\n"; }
	else 
	{ cout << "The file: " << filename << " IS NOT OPEN " << "\n";
	  return;}

    Float_t x,y,y2;
    
    vector<float> charge;
    vector<float> eff;
    Int_t npix, nsw;    
    TString dummy, dummy1, dummy2, dummy3, dummy4, spix;
     
    cout << " Reading file : " << filename << "\n"; 

    file >> dummy1 >> dummy2 >> dummy3 >> dummy4 >> dummy; 
//	file >> dummy >> dummy >> dummy >> dummy ; 
    cout << dummy1 << dummy2 << dummy3 << dummy4 << "\n";
//    cout << "pluto 4 " << "\n";	

    file >> npix >> dummy >> nsw >> dummy;


	nsw++; 
//    npix=4;

//    file >> xmin; 
//    file >> xmax; 
//    file >> par0;
//    file >> par1; 
	if (ideb>0) { cout <<  npix << " " << nsw <<  " " << xmin <<  " " << xmax <<   " " << par0 <<   " " << par1 << "\n"; } 
    
	Int_t ipix = 0; 
    Int_t isweep = 0;
    Int_t counter = 0;
    Int_t iipix;    

    file >> dummy1 >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy; 
	if (ideb>0) { cout << dummy << "\n"; }

    TF1 *fitcurve = new TF1("fiteff",SCurve,xmin,xmax,2);
    fitcurve -> SetParameters(par0,par1);
    TFile f("file.root","RECREATE");

    TGraph *plot[2049];
	
    TMultiGraph *multiplot = new TMultiGraph();
    //    npix = 2048;
    //        npix = 256;	
    //	npix = 1024;
	
     while (ipix < npix ) {

//     cout << " pippo \n";
     ipix++;     
     isweep=0;
     counter = 0;     
     
    while (isweep < nsw)  {
	if(counter== (nsw-1)){
	   file >> dummy1 >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy; 
	   cout << ipix << " pixelnum " <<  dummy1 << endl;   
           spix = dummy1(2,10);
           iipix = atoi(spix);
           isweep++;
//	   continue;
//	   counter=0;
	}
        else {
//        cout << " pluto \n" ;
        file >> x >> dummy >> dummy  >> y >> dummy  >> dummy >> dummy  >> dummy;
           isweep++;
        charge.push_back(x);
        y2 = y / NEVT;
		if (ideb>0) { cout << counter << " " << x << " " << y << " " << y2 << endl; }
       
        eff.push_back(y2);
        counter++;
       }
    }

    fitcurve -> SetParameters(par0,par1); 
    plot[ipix] = new TGraph(counter,&charge[0],&eff[0]);
    plot[ipix]->Fit(fitcurve,"Q");


   Float_t cut0 = 1.05;
   Float_t cut1 = 1.55;

// -------------- Trying to recover bad fit 

   if ( fitcurve->GetParError(0)>cut0 || fitcurve->GetParError(1)> cut1 )  {
// Second attempt to cure: bad S-CURVES
     fitcurve -> SetParameters(1.2*par0,par1);
     plot[ipix]->Fit(fitcurve,"Q");
     if ( fitcurve->GetParError(0)<cut0 && fitcurve->GetParError(1)< cut1 ) cout << " RECOVERED 1.2 " << "\n";
   } 
   if ( fitcurve->GetParError(0)>cut0 || fitcurve->GetParError(1)> cut1 )  {
// Second attempt to cure: bad S-CURVES
     fitcurve -> SetParameters(1.4*par0,par1);
     plot[ipix]->Fit(fitcurve,"Q");
     if ( fitcurve->GetParError(0)<cut0 && fitcurve->GetParError(1)< cut1 ) cout << " RECOVERED 1.4 " << "\n";
   } 
   if ( fitcurve->GetParError(0)>cut0 || fitcurve->GetParError(1)> cut1 )  {
// Third attempt to cure: bad S-CURVES
     fitcurve -> SetParameters(0.8*par0,par1);
     plot[ipix]->Fit(fitcurve,"Q");
     if ( fitcurve->GetParError(0)<cut0 && fitcurve->GetParError(1)< cut1 ) cout << " RECOVERED 0.8 " << "\n";
   } 
   if ( fitcurve->GetParError(0)>cut0 || fitcurve->GetParError(1)> cut1 )  {
// Third attempt to cure: bad S-CURVES
     fitcurve -> SetParameters(0.6*par0,par1);
     plot[ipix]->Fit(fitcurve,"Q");
     if ( fitcurve->GetParError(0)<cut0 && fitcurve->GetParError(1)< cut1 ) cout << " RECOVERED 0.6 " << "\n";
   } 

    Float_t g0 = fitcurve->GetParameter(0);
    Float_t g1 = fitcurve->GetParameter(1);

    output_file << iipix << "  " << fitcurve->GetParameter(0) << "  " << fitcurve->GetParameter(1) <<  " " << fitcurve->GetParError(0) <<  " " << fitcurve->GetParError(1) << endl;



   if (ideb>0) { cout << ipix << "  " << fitcurve->GetParameter(0) << "  " << fitcurve->GetParameter(1) << " " << fitcurve->GetParError(0) <<  " " << fitcurve->GetParError(1) << endl; }

   if ( fitcurve->GetParError(0)>cut0 || fitcurve->GetParError(1)> cut1 )  {
// Filtering bad S-CURVES
	   if (ideb>0) { cout << ipix << "  " << fitcurve->GetParameter(0) << "  " << fitcurve->GetParameter(1) << " " << fitcurve->GetParError(0) <<  " " << fitcurve->GetParError(1) << endl; }
   
     output_file_error << ipix << "  " << fitcurve->GetParameter(0) << "  " << fitcurve->GetParameter(1) << " " << fitcurve->GetParError(0) <<  " " << fitcurve->GetParError(1) << endl;

   }


//   plot-> Fit(fitcurve);
    plot[ipix]->SetTitle("S-curve");
    //plot-> SetTitle(Form("%s",filename.Data())); 
    plot[ipix]->GetXaxis()-> SetTitle("Vcal [DAC counts]");
    plot[ipix]->GetYaxis()-> SetTitle("Efficiency");
    plot[ipix]->SetMarkerStyle(20);
    plot[ipix]->SetMarkerSize(1);
//    gStyle -> SetOptFit(1);



    plot[ipix]->Write();
    multiplot->Add(plot[ipix]);

//    plot -> Draw("AP");
//    break;
//    delete plot;
    charge.clear();
    eff.clear();
//    break;       
   } 
      
    multiplot->Draw("A");
    cvs->SaveAs(Rfile);
    cvs->SaveAs(Jfile);
	return;
}



Float_t PCurve(Double_t *xx, Double_t *par){
    return   par[0] + ((xx[0]-30) * par[1]);
}


void Macro_ToT(TString Dir, TString filei, Float_t xmin = 30 , Float_t xmax = 60, Float_t par0 = 45 , Float_t par1 = 2, Float_t NEVT=200.){
// ----------------------------------------------------------------------------------------------------------------------------------------    
    Int_t ideb=0;

    TString output_filename, output_filename_error, filename;

    gStyle->SetOptStat(00111111);

    filename = Dir+filei+"txt";	
    output_filename = Dir+"Out/"+filei+"out";		
    output_filename_error = Dir+"Err/"+filei+"err";	

	TString Rfile = Dir+"Out/"+filei+"ToT.root";		
	TString Jfile = Dir+"Out/"+filei+"ToT.pdf";	

//    new TCanvas(filename,filename,600,300);
    TCanvas *cvs = new TCanvas(filename,filename,900,300);
		
    cout << filename << "\n";
    cout << output_filename << "\n";
//    cout << output_filename_error << "\n";

//    break;	
    ofstream output_file(output_filename);
	if (output_file.is_open())
	{ cout << "The file: " << output_filename << " IS OPEN " << "\n"; }
	else 
	{ cout << "The file: " << output_filename << " IS NOT OPEN " << "\n";
	 return; }

    ofstream output_file_error(output_filename_error);
	if (output_file_error.is_open())
	{ cout << "The file: " << output_filename_error << " IS OPEN " << "\n"; }
	else 
	{ cout << "The file: " << output_filename_error << " IS NOT OPEN " << "\n";
	  return; }

    ifstream file(filename);
	if (file.is_open())
	{ cout << "The file: " << filename << " IS OPEN " << "\n"; }
	else 
	{ cout << "The file: " << filename << " IS NOT OPEN " << "\n";
	  return;}

    Float_t x,y,y2;
    
    vector<float> charge;
    vector<float> eff;
    Int_t npix, nsw;    
    string dummy, dummy1, dummy2, dummy3, dummy4 ;
     
    cout << " Reading file : " << filename << "\n"; 

    file >> dummy1 >> dummy2 >> dummy3 >> dummy4 >> dummy; 
    //    cout << dummy1 << dummy2 << dummy3 << dummy4 << "\n";

    file >> npix >> dummy >> nsw >> dummy;
    //    cout << npix << " " << dummy << " " << nsw << "\n";

    nsw++; 
    ideb=0;
    if (ideb>0) { cout <<  npix << " " << nsw <<  " " << xmin <<  " " << xmax <<   " " << par0 <<   " " << par1 << "\n"; } 
    
    Int_t ipix = 0; 
    Int_t isweep = 0;
    Int_t counter = 0;    

    file >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy; 
	if (ideb>0) { cout << dummy << "\n"; }

	//    cout << "xmin : " << xmin << " xmax : " << xmax  << endl;
    TF1 *fitcurve = new TF1("fiteff",PCurve,xmin,xmax,2);
    fitcurve -> SetParameters(par0,par1);
    TFile f("file.root","RECREATE");

    TGraph *plot[2049];
    TMultiGraph *multiplot = new TMultiGraph();
    ipix=0;

    //    npix = 2048;
    //        npix = 4;	
    //	npix = 1024;
	//	npix = 4;
     while (ipix < npix ) {

       //        cout << " ipix " << ipix << " npix " << npix <<  "\n";
        ipix++;     
        string numpix;
        isweep=0;
        counter = 0;    
        Int_t count =0; 
     
	while (isweep < nsw)  {
	  //	  cout << " iswepp = " << isweep << " nsw " << nsw;     
	  if(counter== (nsw-1)){
	    file >> numpix >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy; 
	    //	    cout << "pixel number : " << numpix <<  dummy << endl;   
	    isweep++;
	    //	   continue;
	    counter=0;
	  }
	  else {
	    //	    cout << " reading data... \n" ;
	    file >> x >> dummy >> dummy  >> dummy >> dummy  >> dummy >> y  >> dummy;
	    isweep++;
	    //	    cout << "VCAL-value(DAC)=" << x << " <ToT>= " << y << endl;

	    if ((x>xmin) && (x<xmax))
	      { charge.push_back(x);
                y2 = y;
                eff.push_back(y2);              
                count++;
	      }
	    counter++;
	  }
    }
    fitcurve -> SetParameters(par0,par1); 
    plot[ipix] = new TGraph(count,&charge[0],&eff[0]);
    plot[ipix]->Fit(fitcurve,"Q");


   Float_t cut0 = 99.;
   Float_t cut1 = 99.;

// -------------- Trying to recover bad fit 

   if ( fitcurve->GetParError(0)>cut0 || fitcurve->GetParError(1)> cut1 )  {
// Second attempt to cure: bad S-CURVES
     fitcurve -> SetParameters(1.2*par0,par1);
     plot[ipix]->Fit(fitcurve,"Q");
     if ( fitcurve->GetParError(0)<cut0 && fitcurve->GetParError(1)< cut1 ) cout << " RECOVERED 1.2 " << "\n";
   } 
   if ( fitcurve->GetParError(0)>cut0 || fitcurve->GetParError(1)> cut1 )  {
// Second attempt to cure: bad S-CURVES
     fitcurve -> SetParameters(1.4*par0,par1);
     plot[ipix]->Fit(fitcurve,"Q");
     if ( fitcurve->GetParError(0)<cut0 && fitcurve->GetParError(1)< cut1 ) cout << " RECOVERED 1.4 " << "\n";
   } 
   if ( fitcurve->GetParError(0)>cut0 || fitcurve->GetParError(1)> cut1 )  {
// Third attempt to cure: bad S-CURVES
     fitcurve -> SetParameters(0.8*par0,par1);
     plot[ipix]->Fit(fitcurve,"Q");
     if ( fitcurve->GetParError(0)<cut0 && fitcurve->GetParError(1)< cut1 ) cout << " RECOVERED 0.8 " << "\n";
   } 
   if ( fitcurve->GetParError(0)>cut0 || fitcurve->GetParError(1)> cut1 )  {
// Third attempt to cure: bad S-CURVES
     fitcurve -> SetParameters(0.6*par0,par1);
     plot[ipix]->Fit(fitcurve,"Q");
     if ( fitcurve->GetParError(0)<cut0 && fitcurve->GetParError(1)< cut1 ) cout << " RECOVERED 0.6 " << "\n";
   } 

    Float_t g0 = fitcurve->GetParameter(0);
    Float_t g1 = fitcurve->GetParameter(1);

    output_file << ipix << "  " << fitcurve->GetParameter(0) << "  " << fitcurve->GetParameter(1) <<  " " << fitcurve->GetParError(0) <<  " " << fitcurve->GetParError(1) << endl;



    if (ideb>0) { cout << " Fit parameters for pix # " << ipix << " = " << fitcurve->GetParameter(0) << "  " << fitcurve->GetParameter(1) << " " << fitcurve->GetParError(0) <<  " " << fitcurve->GetParError(1) << endl; }

   //   if ( fitcurve->GetParError(0)>cut0 || fitcurve->GetParError(1)> cut1 )  {
// Filtering bad S-CURVES
//	   if (ideb>0)) { cout << ipix << "  " << fitcurve->GetParameter(0) << "  " << fitcurve->GetParameter(1) << " " << fitcurve->GetParError(0) <<  " " << fitcurve->GetParError(1) << endl; }
   
   //   output_file_error << ipix << "  " << fitcurve->GetParameter(0) << "  " << fitcurve->GetParameter(1) << " " << fitcurve->GetParError(0) <<  " " << fitcurve->GetParError(1) << endl;

   //  }


//   plot-> Fit(fitcurve);
    plot[ipix]->SetTitle("S-curve");
    //plot-> SetTitle(Form("%s",filename.Data())); 
    plot[ipix]->GetXaxis()-> SetTitle("Vcal [DAC counts]");
    plot[ipix]->GetYaxis()-> SetTitle("Mean ToT");
    plot[ipix]->SetMarkerStyle(20);
    plot[ipix]->SetMarkerSize(1);
//    gStyle -> SetOptFit(1);



    plot[ipix]->Write();
    multiplot->Add(plot[ipix]);

//    plot -> Draw("AP");
//    break;
//    delete plot;
    charge.clear();
    eff.clear();
//    break;       
   } 
      
     //    multiplot->Draw("A");
    cvs->SaveAs(Rfile);
    cvs->SaveAs(Jfile);
	return;
}
