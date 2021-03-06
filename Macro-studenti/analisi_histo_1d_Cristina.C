//#if !defined(__CINT__) || defined(__MAKECINT__)

//#endif


void analisiMC(TString Dir, TString inFileName, Double_t nbins, Double_t min_thr, Double_t max_thr, Double_t min_noise, Double_t max_noise, Int_t par_analisi, Int_t val_min, Int_t val_max){

    Int_t ideb=0;  
    gStyle->SetOptStat(112211);
    gStyle->SetOptFit(1111);

    TString file = inFileName;
    inFileName = Dir+"Out/"+ inFileName+"out";
    TString RfileT = inFileName+"_thr.root";	
    TString RfileN = inFileName+"_noi.root";	
    TString Jfile = inFileName+".pdf";	
    TString Resfile = inFileName+".res";
	

     ofstream output_file(Resfile);
		if (output_file.is_open())
		{ cout << "The file: " << Resfile << " IS OPEN " << "\n"; }
		else 
		{ cout << "The file: " << Resfile << " IS NOT OPEN " << "\n";
		return; }
      
       	ifstream in(inFileName);
		if(!in){
		cout<<"Il file"<<inFileName<<"non esiste"<<endl;
		return;}	

	float x,y,z,e1,e2;

	Int_t isweep = 0;

	vector<float> npix;
	vector<float> thr;
	vector<float> noise;
	Int_t npixels = 0;
  
  
  
	while (in >> x)  {
	 //cout << x;
//     if((in >> x )){
        npixels++;
        in >> y;
        in >> z;
        in >> e1;
        in >> e2; 
        isweep++;
	//        cout << x << " " << y << " " << z << " " << e1 << " " << e2 << endl;  
        if ( e1>0.5 || e2>1 || e1<0.001 || e2 <0.002 ) {
			if (ideb>0)  { cout << x << " " << y << " " << z << " " << e1 << " " << e2 << endl;  }
              y = -99;
              z = -99;
        } 
        npix.push_back(x);
        thr.push_back(y);
        noise.push_back(z);
 
    }
//    }   


    TF1 *f1thr = new TF1("f1thr","gaus");
    TF1 *f1noise = new TF1("f1noise","gaus");

    //    TF1 *f1thr = new TF1("f1thr","gaus",60.,min_thr,max_thr);
    //    TF1 *f1noise = new TF1("f1noise","gaus",2.,min_noise,max_noise);



	TH1F *histo_thr = new TH1F("histo_thr","histo_thr",nbins,min_thr,max_thr);
	TH1F *histo_noise = new TH1F("histo_noise","histo_noise",nbins,min_noise,max_noise);
//  TH1D *histAmpl = new TH1D("histAmpl","histAmpl",20,0.1105,0.131);
	
	if(par_analisi == 0){
		for(Int_t i=0;i<npixels;i++){ 
		histo_thr->Fill(thr.at(i));
		histo_noise->Fill(noise.at(i));
		}  
	}
	
	if(par_analisi == 1){
		/*
		do{
		cout << "\n "<< "INSERIRE IL VALORE DI PIXEL COME ESTREMO INFERIORE DEL RANGE TRA 0 E 1023:"<<endl;
		cin >> pix_inf;
		}while(pix_inf>1023 || pix_inf<0);
	
		do{
		cout <<"\n"<< "INSERIRE IL VALORE DI PIXEL COME ESTREMO SUPERIORE DEL RANGE:"<<endl;
		cin >> pix_sup;
		}while(pix_sup<pix_inf);
		cout << "\n"<<endl;
	*/
		if(val_min <0 && val_min >1023 || val_max < val_min && val_max > 1023){
			cout << "/n VALORI NON ACCETTABILI" <<endl;
		}
		else{
			for(Int_t i=0;i<npixels;i++){ 
				if(i>= val_min && i<= val_max){
				histo_thr->Fill(thr.at(i));
				histo_noise->Fill(noise.at(i));
				}
			}
		}
	}
	 
	if(par_analisi == 2){
		
		/*
		do{
		cout << "\n "<< "INSERIRE NUMERO DELLA RIGA INFERIORE DA ANALIZZARE:"<<endl;
		cin >> riga_inf;
		}while(riga_inf>64 || riga_inf<0);
	
		do{
		cout << "\n "<< "INSERIRE NUMERO DELLA RIGA SUPERIORE DA ANALIZZARE:"<<endl;
		cin >> riga_sup;
		}while(riga_sup>64 || riga_sup<riga_inf);
		*/
	
		int num_riga;
	
		if(val_min < 0 && val_min > 64 || val_max < val_min && val_max > 64){
			cout << " /n VALORI NON CONSENTITI" << endl;
		}
		else{
			for(Int_t i=0;i<npixels;i++){ 
				num_riga = i % 64;
				if(num_riga>= val_min && num_riga<= val_max){
				histo_thr->Fill(thr.at(i));
				histo_noise->Fill(noise.at(i));
				}
			}	
		}	
	}
//  TFile f(Rfile,"RECREATE");

  TCanvas *cvs = new TCanvas("Plot","plot",900,400);
  cvs->Divide(2,1);
  cvs->cd(1);
  histo_thr->SetTitle("Threshold distribution");
  histo_thr->GetXaxis()->SetTitle("Threshold [DAC counts]");
  histo_thr->GetYaxis()->SetTitle("Entries");
  histo_thr->SetMarkerStyle(3);
  histo_thr->SetMarkerSize(6);
  histo_thr->Draw();  
  histo_thr->Fit(f1thr,"Q");
  
  int n_entries ;
  n_entries= histo_thr->GetEntries();
  
  float mean = histo_thr->GetMean();
  
  if(n_entries > 50){
  //  f1thr->GetParameter(0)

    output_file << "  " << f1thr->GetParameter(0) << "  " << f1thr->GetParameter(1) << "  " << f1thr->GetParameter(2)  <<  " " << f1thr->GetParError(0) <<  " " << f1thr->GetParError(1)  <<  " " << f1thr->GetParError(2) << endl;
  }
  else {
	  output_file << "  " << 1 << "  " << mean << "  " << 1  <<  " " << 1 <<  " " << 0.1 <<  " " << 1 << endl;
  }
  cvs->cd(2);
  histo_noise->SetTitle("Noise distribution");
  histo_noise->GetXaxis()->SetTitle("Noise [DAC counts]");
  histo_noise->GetYaxis()->SetTitle("Entries");
  histo_noise->SetMarkerStyle(3);
  histo_noise->SetMarkerSize(6);
  histo_noise->Draw();
  histo_noise->Fit(f1noise,"Q");
//  f.Write();
 
 output_file << "  " << f1noise->GetParameter(0) << "  " << f1noise->GetParameter(1) << "  " << f1noise->GetParameter(2)  <<  " " << f1noise->GetParError(0) <<  " " << f1noise->GetParError(1)  <<  " " << f1noise->GetParError(2) << endl;


   histo_thr->SaveAs(RfileT);
   histo_noise->SaveAs(RfileN);
   cvs->SaveAs(Jfile);
 
  }
  
  
void analisiMCTOT(TString Dir, TString inFileName, Double_t nbins, Double_t min_thr, Double_t max_thr, Double_t min_noise, Double_t max_noise){

	Int_t ideb=0;  
	gStyle->SetOptStat(112211);
    gStyle->SetOptFit(1111);

    TString file = inFileName;
    inFileName = Dir+"Out/"+ inFileName+"out";
    TString RfileT = inFileName+"_thr.root";	
    TString RfileN = inFileName+"_noi.root";	
    TString Jfile = inFileName+".pdf";	
    TString Resfile = inFileName+".res";


     ofstream output_file(Resfile);
	if (output_file.is_open())
	{ cout << "The file: " << Resfile << " IS OPEN " << "\n"; }
	else 
	{ cout << "The file: " << Resfile << " IS NOT OPEN " << "\n";
	 return; }

       	ifstream in(inFileName);
	if(!in){
		cout<<"Il file"<<inFileName<<"non esiste"<<endl;
		return;
	}	

  float x,y,z,e1,e2;

  Int_t isweep = 0;

  vector<float> npix;
  vector<float> thr;
  vector<float> noise;
  Int_t npixels = 0;


/*  
float xrd, xru;
  
cout << "Inserire il pixel estremo inferiore del range:"<<endl;
cin >> xrd;
cout << "Inserire il pixel estremo superiore del range:"<<endl;
cin >> xru;
 */ 

 while (in >> x)  {
//     if((in >> x )){
        npixels++;
        in >> y;
        in >> z;
        in >> e1;
        in >> e2; 
        isweep++;
	//        cout << x << " " << y << " " << z << " " << e1 << " " << e2 << endl;  
	//        if ( e1>0.5 || e2>1 || e1<0.001 || e2 <0.002 ) {
	//			if (ideb>0)  { cout << x << " " << y << " " << z << " " << e1 << " " << e2 << endl;  }
	//              y = -99;
	//         z = -99;
	//        } 
        npix.push_back(x);
        thr.push_back(y);
        noise.push_back(z);
 
    }
//    }   


    TF1 *f1thr = new TF1("f1thr","gaus");
    TF1 *f1noise = new TF1("f1noise","gaus");

    //    TF1 *f1thr = new TF1("f1thr","gaus",60.,min_thr,max_thr);
    //    TF1 *f1noise = new TF1("f1noise","gaus",2.,min_noise,max_noise);



  TH1F *histo_thr = new TH1F("histo_thr","histo_thr",nbins,min_thr,max_thr);
  TH1F *histo_noise = new TH1F("histo_noise","histo_noise",nbins,min_noise,max_noise);
//  TH1D *histAmpl = new TH1D("histAmpl","histAmpl",20,0.1105,0.131);

  for(Int_t i=0;i<npixels;i++){
	  if(i>=xrd && i<=xru){
  //cout<<a[i]<<" "<<b[i]<<endl;
  histo_thr->Fill(thr.at(i));
  histo_noise->Fill(noise.at(i));
	  }
  }  
  
  
//  TFile f(Rfile,"RECREATE");

  TCanvas *cvs = new TCanvas("Plot","plot",900,400);
  cvs->Divide(2,1);
  cvs->cd(1);
  histo_thr->SetTitle("ToT offset distribution");
  histo_thr->GetXaxis()->SetTitle("ToT [DAC counts]");
  histo_thr->GetYaxis()->SetTitle("Entries");
  histo_thr->SetMarkerStyle(3);
  histo_thr->SetMarkerSize(6);
  histo_thr->Draw();  
  histo_thr->Fit(f1thr,"Q");
  
  //  f1thr->GetParameter(0)

    output_file << "  " << f1thr->GetParameter(0) << "  " << f1thr->GetParameter(1) << "  " << f1thr->GetParameter(2)  <<  " " << f1thr->GetParError(0) <<  " " << f1thr->GetParError(1)  <<  " " << f1thr->GetParError(2) << endl;
  
  
  cvs->cd(2);
  histo_noise->SetTitle("ToT slope distribution");
  histo_noise->GetXaxis()->SetTitle("d(ToT)/d(Cal-DAC) ");
  histo_noise->GetYaxis()->SetTitle("Entries");
  histo_noise->SetMarkerStyle(3);
  histo_noise->SetMarkerSize(6);
  histo_noise->Draw();
  histo_noise->Fit(f1noise,"Q");
//  f.Write();
 
 output_file << "  " << f1noise->GetParameter(0) << "  " << f1noise->GetParameter(1) << "  " << f1noise->GetParameter(2)  <<  " " << f1noise->GetParError(0) <<  " " << f1noise->GetParError(1)  <<  " " << f1noise->GetParError(2) << endl;


   histo_thr->SaveAs(RfileT);
   histo_noise->SaveAs(RfileN);
   cvs->SaveAs(Jfile);

 
  }


void generateTRIM(TString Dir, TString inFileName, Int_t gain, Int_t ILDAC)
//  ==========================================================================
{

    Double_t avg_thr;
    inFileName = Dir+"Out/"+ inFileName+"out";    
    TString Resfile = inFileName+".res"; 

   TString ouFileName =  inFileName+".trim"; 

    Double_t min_thr, max_thr;
    Double_t nbins=16; 
    Double_t delta= 30.;
	if ( gain==0 ) { 
	    delta=15.*ILDAC/160.  ;    // if ILDAC=160 (default)
//		delta=76/2.;   // if ILDAC=400.
	}
       	ifstream res(Resfile);
	if(!res){
		cout<<"Il file"<<Resfile<<"non esiste"<<endl;
		return;}

        Float_t sdummy;	
        res >> sdummy >>  avg_thr;


	ifstream in(inFileName);
	if(!in){
		cout<<"Il file"<<inFileName<<"non esiste"<<endl;
		return;
	}


    ofstream output_file(ouFileName);
	output_file << "CHIPIX Thresholds file v1.0"  << endl;  
	cout << ouFileName << endl;
	float x,y,z,ey,ez;


	min_thr = avg_thr - delta;
	max_thr = avg_thr + delta;

  Int_t isweep = 0;
  Float_t itrim;
  
  vector<float> npix;
  vector<float> thr;
  vector<float> noise;
  Int_t npixels = 0;
  float xmin = 999;
  float xmax = -999;
  
  
 while (in >> x)  {
//     if((in >> x )){
        npixels++;
        npix.push_back(x);
        in >> y;
//        y=-(y-avg_thr);
//        if (y<xmin) xmin=y-0.001;
//		if (y>xmax) xmax=y+0.001;  
        thr.push_back(y);
//        itrim=int(y);
        in >> z >> ey >> ez ;
        isweep++;
             
	//	cout << x << " " << y << " " << z << " " << ey << " " << ez << endl;  
    }
//    }   
 

  TH1D *histo_thr = new TH1D("histo_thr","histo_thr",nbins,min_thr,max_thr);
  TH1D *histo_trim = new TH1D("histo_trim","histo_trim",16,-0.5,15.5);
//  TH1D *histo_noise = new TH1D("histo_noise","histo_noise",nbins,min_noise,max_noise);
//  TH1D *histAmpl = new TH1D("histAmpl","histAmpl",20,0.1105,0.131);


  for(Int_t i=0;i<npixels;i++){
  //cout<<a[i]<<" "<<b[i]<<endl;
  histo_thr->Fill(thr.at(i));
  itrim = int((-thr.at(i)+max_thr)/2./delta*16);
  if (itrim<0) itrim=0;
  if (itrim>15) itrim=15;
  histo_trim->Fill(itrim); 
//   output_file << i << " " << itrim  << endl;  
  output_file << itrim  << endl;     
  //  histo_noise->Fill(noise.at(i));
  }  
  
  TCanvas *cvs = new TCanvas("cvs");
  cvs->Divide(2,1);
  cvs->cd(1);
  histo_thr->SetTitle("Trimming distribution");
  histo_thr->GetXaxis()->SetTitle("Threshold [DAC counts]");
  histo_thr->GetYaxis()->SetTitle("Entries");
  histo_thr->SetMarkerStyle(3);
  histo_thr->SetMarkerSize(6);
  histo_thr->Draw();


  
  cvs->cd(2);
  histo_trim->SetTitle("Trimming distribution 2 ");
  histo_trim->GetXaxis()->SetTitle("Threshold [DAC counts]");
  histo_trim->GetYaxis()->SetTitle("Entries");
  histo_trim->SetMarkerStyle(3);
  histo_trim->SetMarkerSize(6);
  histo_trim->Draw();

 
}


void analisiTHR2(TString Dir, TString inFileName, Double_t nbins, Double_t min_thr, Double_t max_thr, Double_t min_noise, Double_t max_noise,Int_t Hrow ){

  //  gStyle->reset;
   gStyle->SetOptStat(111);


    inFileName = Dir+"Out/"+ inFileName+"out";    
    //    TString Resfile = inFileName+".res"; 

    ifstream in(inFileName);
    if(!in){
		cout<<"Il file"<<inFileName<<"non esiste"<<endl;
		return;
	}

    float x,y,z,ex,ey,ez,cutn,cutt;
    cutn = 0.2;
    cutt = 0.2;

  Int_t isweep = 0;

  vector<float> npix;
  vector<float> thr;
  vector<float> noise;
  Int_t npixels = 0;

 while (in >> x)  {
//     if((in >> x )){
       
	//       npix.push_back(x);
        in >> y;
	//        thr.push_back(y);
        in >> z;
	//        noise.push_back(z);
        in >> ey;
        in >> ez;
	  if ( (ey < cutt) && (ez<cutn) ) {
	      npixels++;
	      //              x=x+2;
              npix.push_back(x);
              thr.push_back(y);
              noise.push_back(z);
	  }
          else { cout << "Err " << x <<  y <<  z << ex << ey  << endl;   
	  }
        isweep++;
	        cout << x << " " << y << " " << z << endl;  
    }
//    }   

 cout << " End of Pixel loop " << npixels << endl;

  TH1D *histo_thr = new TH1D("histo_thr","histo_thr",nbins,min_thr,max_thr);
  TH1D *histo_thr_LowestRow = new TH1D("histo_thr","histo_thr",nbins,min_thr,max_thr);
  TH1D *histo_thr_HighestRow = new TH1D("histo_thr","histo_thr",nbins,min_thr,max_thr);
  TH2D *Thisto_thrR = new TH2D("2dhisto_thr","2dhisto_thr",nbins,min_thr,max_thr,64,-0.5,63.5);
  TH2D *Thisto_thrC = new TH2D("2dhisto_thr","2dhisto_thr",nbins,min_thr,max_thr,64,-0.5,63.5);
  TH2D *Thisto_thrPR = new TH2D("2dhisto_thr","2dhisto_thr",nbins,min_thr,max_thr,16,-0.5,15.5);

  TH2D *Thisto_thrMAP = new TH2D("2dhisto_thr","2dhisto_thr",64,-0.5,63.5,64,-0.5,63.5);
  TH2D *Thisto_noiseMAP = new TH2D("2dhisto_noise","2dhisto_noise",64,-0.5,63.5,64,-0.5,63.5);



//  TH1D *histAmpl = new TH1D("histAmpl","histAmpl",20,0.1105,0.131);
  Int_t row, col, prow, pcol, pindex, ii;

  for(Int_t i=0;i<npixels;i++){

  //  for(Int_t i=0;i<128;i++){
    //  cout<<a[i]<<" "<<b[i]<<endl;
  histo_thr->Fill(thr.at(i));

  ii = npix.at(i);
  row = (ii-int(ii/64)*64);
  col = int(ii/64);

  Thisto_thrMAP->Fill(col,row,thr.at(i));
  Thisto_noiseMAP->Fill(col,row,noise.at(i));

  prow = (row-int(row/4)*4);
  pcol = (col-int(col/4)*4);
  pindex = prow + pcol*4;  
  Float_t scol, srow, spindex;
  scol = col;
  srow = row;
  spindex = pindex;
//  cout << i << "pix num: " << ii << " col=" << scol << " row =" <<  srow << " pindex=" << spindex  << "   " << thr.at(i) << endl;

  Thisto_thrR->Fill(thr.at(i),srow);
  Thisto_thrC->Fill(thr.at(i),scol);

  Thisto_thrPR->Fill(thr.at(i),spindex);

  if ( row < Hrow ) {
     histo_thr_LowestRow->Fill(thr.at(i));
  }
  else {
     histo_thr_HighestRow->Fill(thr.at(i));
  }
 
  // histo_noise->Fill(noise.at(i));
  }  
  
  TCanvas *cvs = new TCanvas("cvs");
  cvs->Divide(3,1);
  cvs->cd(1);
  histo_thr->SetTitle("Threshold distribution");
  histo_thr->GetXaxis()->SetTitle("Threshold [DAC counts]");
  histo_thr->GetYaxis()->SetTitle("Entries");
  histo_thr->SetMarkerStyle(2);
  histo_thr->SetMarkerSize(1);
  histo_thr->Draw();
  cvs->cd(2);
  histo_thr_LowestRow->Draw();
  cvs->cd(3);
  histo_thr_HighestRow->Draw();
  
  TCanvas *Tcvs = new TCanvas("Tcvs");
  Tcvs->Divide(2,1);
  Tcvs->cd(1);
  Thisto_thrR->SetTitle("Threshold distribution");
  Thisto_thrR->GetXaxis()->SetTitle("Threshold [DAC counts]");
  Thisto_thrR->GetYaxis()->SetTitle("Row");
  Thisto_thrR->SetMarkerStyle(2);
  Thisto_thrR->SetMarkerSize(1);
  Thisto_thrR->Draw("2");

  Tcvs->cd(2);
  Thisto_thrC->SetTitle("Threshold distribution");
  Thisto_thrC->GetXaxis()->SetTitle("Threshold [DAC counts]");
  Thisto_thrC->GetYaxis()->SetTitle("Column");
  Thisto_thrC->SetMarkerStyle(2);
  Thisto_thrC->SetMarkerSize(1);
  Thisto_thrC->Draw("2");

  TCanvas *Pcvs = new TCanvas("Pcvs");
  Pcvs->Divide(1,1);
  Pcvs->cd(1);
  Thisto_thrPR->SetTitle("Threshold distribution");
  Thisto_thrPR->GetXaxis()->SetTitle("Threshold [DAC counts]");
  Thisto_thrPR->GetYaxis()->SetTitle("Pixel-num  in (4,4) region");
  Thisto_thrPR->SetMarkerStyle(2);
  Thisto_thrPR->SetMarkerSize(1);
  Thisto_thrPR->Draw("2");

  TCanvas *MAP = new TCanvas("Pixel Map");
  MAP->Divide(2,1);
  MAP->cd(1);
  Thisto_thrMAP->SetTitle("Threshold Pixel Map");
  Thisto_thrMAP->GetXaxis()->SetTitle("Column");
  Thisto_thrMAP->GetYaxis()->SetTitle("Row");
  Thisto_thrMAP->SetMarkerStyle(2);
  Thisto_thrMAP->SetMarkerSize(1);
  Thisto_thrMAP->SetMinimum(30);
  Thisto_thrMAP->Draw("COLz");
  MAP->cd(2);
  Thisto_noiseMAP->SetTitle("ENC Pixel Map");
  Thisto_noiseMAP->GetXaxis()->SetTitle("Column");
  Thisto_noiseMAP->GetYaxis()->SetTitle("Row");
  Thisto_noiseMAP->SetMarkerStyle(2);
  Thisto_noiseMAP->SetMarkerSize(1);
  Thisto_noiseMAP->SetMinimum(0.8);
  Thisto_noiseMAP->Draw("COLz");



}



void analisiTOT_freq(TString Dir, TString inFileName1,  TString inFileName2, Double_t nbins, Double_t min_freq, Double_t max_freq){

	Int_t ideb=0;  
	gStyle->SetOptStat(112211);
    gStyle->SetOptFit(1111);

    TString Resfile =  Dir+"Out/"+ inFileName2+"_FREQ.res";

    inFileName2 = Dir+"Out/"+ inFileName2+"out";
    inFileName1 = Dir+"Out/"+ inFileName1+"out";

    TString RfileF = inFileName2+"_FREQ.root";		
    TString Jfile = inFileName2+"_FREQ.pdf";	


     ofstream output_file(Resfile);
	if (output_file.is_open())
	{ cout << "The file: " << Resfile << " IS OPEN " << "\n"; }
	else 
	{ cout << "The file: " << Resfile << " IS NOT OPEN " << "\n";
	 return; }

       	ifstream inL(inFileName1);
	if(!inL){
		cout<<"Il file"<< inFileName1 <<"non esiste"<<endl;
		return;
        }
       	else
          { cout << "The file: " << inFileName1 << " IS OPEN " << "\n"; 
        }   
	
	
       	ifstream inF(inFileName2);
	if(!inF){
		cout<<"Il file"<<inFileName2<<"non esiste"<<endl;
		return;
	}
	else  { cout << "The file: " << inFileName2 << " IS OPEN " << "\n"; 
        }   
	        
  float x,y,z,e1,e2;
  Int_t isweep = 0;

  vector<float> npix;
  vector<float> low;
  Int_t npixels = 0;

 while (inL >> x)  {
//     if((in >> x )){
        npixels++;
        inL >> y;
        inL >> z;
        inL >> e1;
        inL >> e2; 
        isweep++;
        npix.push_back(x);
        low.push_back(z);
     }
  vector<float> fast;

 while (inF >> x)  {
//     if((in >> x )){
        inF >> y;
        inF >> z;
        inF >> e1;
        inF >> e2; 
	//        isweep++;
        fast.push_back(z);
     }


    TString fileLow = inFileName1;
    TF1 *f1thr = new TF1("f1thr","gaus");

    float freq, f,l; 
    TH1F *histo_freq = new TH1F("histo_frq","histo_frq",nbins,min_freq,max_freq);

  for(Int_t i=0;i<npixels;i++){
  //cout<<a[i]<<" "<<b[i]<<endl;
    f=fast.at(i);
    l=low.at(i);
    //    cout << i << " " << f << " " << l << " " << npixels << endl;
    freq=80.*fast.at(i)/low.at(i);
    histo_freq->Fill(freq);
    //    output_file << i << " " << freq <<  endl;
  }  
  

  TCanvas *cvs = new TCanvas("Plot","plot",900,400);
  cvs->Divide(1,1);
  cvs->cd(1);
  histo_freq->SetTitle("Fast ToT frequency distribution");
  histo_freq->GetXaxis()->SetTitle("Freq [MHz]");
  histo_freq->GetYaxis()->SetTitle("Entries");
  histo_freq->SetMarkerStyle(3);
  histo_freq->SetMarkerSize(6);
  histo_freq->Draw();  
  histo_freq->Fit(f1thr,"Q");
  
  //  f1thr->GetParameter(0)

  //    output_file_Low << "  " << f1thr->GetParameter(0) << "  " << f1thr->GetParameter(1) << "  " << f1thr->GetParameter(2)  <<  " " << f1thr->GetParError(0) <<  " " << f1thr->GetParError(1)  <<  " " << f1thr->GetParError(2) << endl;
  
   histo_freq->SaveAs(RfileF);
   //   histo_noise->SaveAs(RfileN);
   cvs->SaveAs(Jfile);
 
	}