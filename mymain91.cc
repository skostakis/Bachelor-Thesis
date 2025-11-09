#include <iostream> // Stdlib header file for input and output.
#include "Pythia8/Pythia.h" // Header file to access Pythia 8 program elements.
#include "TH1.h" // ROOT, for histogramming.
#include "TFile.h" // ROOT, for saving file.
#include <cmath>
#include <stdexcept>
#include <string>
#include "TLorentzVector.h"


using namespace Pythia8;

int main(int argc, char *argv[]) {

   Pythia pythia;

   pythia.readFile(argv[1]); // Read in commands from external file inputmyeezpythia.cmd.

   //Initialize.
   pythia.init();

   Event &event = pythia.process;

   // Extract settings to be used in the main program.
   int nEvent  = pythia.mode("Main:numberOfEvents"); // Whatever value stored at inputmyeezpythia.cmd.
   double Ecm = pythia.info.eCM();
   cout << nEvent << endl;
   cout << Ecm << endl;

   TLorentzVector tmuplus0, tmuplus, tmuminus, t2mu; // Will be needed  later. // 0 is from the pythia.process, non0 is from pythia.event (the experiment)

   // Create file on which histogram(s) can be saved.
   TFile *outputfile = TFile::Open("mymain91.root", "recreate");

   // Book histograms.
   TH1F *mult = new TH1F("mult","charged multiplicity", 100, -0.5, 99.5);
   TH1F *muplus0costheta = new TH1F("muplus0costheta", "costheta for  mu plus0", 10, -1, 1);
   TH1F *mupluscostheta = new TH1F("mupluscostheta", "costheta for mu  plus", 10, -1, 1);
   TH1F *mumu_mass = new TH1F("mumu_mass", "mass of muminus muplus", 100, Ecm - 5, Ecm + 5);

   // Begin main for loop.
   for (int iEvent = 0; iEvent < nEvent; ++iEvent) {
     if (!pythia.next()) {
       continue;
       }

     // Find number of all final charged particles.
     int nCharged = 0; // Where it has process it used to have event. don't know which is right. seems to run with both process and event.

     for (int i = 0; i < pythia.event.size(); ++i) {
       if (pythia.event[i].isFinal() && pythia.event[i].isCharged()) 
        ++nCharged;
       if (pythia.event[i].isFinal() && pythia.event[i].id()==-13) {
         tmuplus.SetPxPyPzE( pythia.event[i].px(), pythia.event[i].py(), pythia.event[i].pz(), pythia.event[i].e() );
       }
       if (pythia.event[i].isFinal() && pythia.event[i].id()==13) {
         tmuminus.SetPxPyPzE( pythia.event[i].px(), pythia.event[i].py(), pythia.event[i].pz(), pythia.event[i].e() );
       }
     }

     mult->Fill(nCharged); // Fill charged multiplicity in histogram.

     // Construction of mucostheta histograms.
     Particle const & muminus = event[6];
     Particle const & muplus  = event[7];

      // Construction of TLorentzVector vectors.
      // tmuminus.SetPxPyPzE( muminus.px(), muminus.py(), muminus.pz(), muminus.e() );
     tmuplus0.SetPxPyPzE( muplus.px(), muplus.py(), muplus.pz(), muplus.e() );

     muplus0costheta->Fill(tmuplus0.CosTheta()); // Fill  muminuscostheta histogram.

     t2mu = tmuplus + tmuminus;
     mumu_mass->Fill(t2mu.M());
     
     if(abs(t2mu.M()-Ecm)<0.1) 
      mupluscostheta->Fill(tmuplus.CosTheta()); // Fill mupluscostheta histogram.

     if(iEvent<=1) {
       std::cout << "EVENT NUMBER: " << iEvent << endl;
       pythia.process.list();
       std::cout << "*****************FOUR VECTOR CALCULATION**************************\n" << endl;
       std::cout << "mu plus (E, px, px,pz): " << "("<<muplus.px()<<", "<<muplus.py()<<", "<<muplus.pz()<<", "<<muplus.e()<<")\n" << endl;
       std::cout << "TLorentzVevtor tmuplus: " << "("<<tmuplus.Px()<<", "<<tmuplus.Py()<<", "<<tmuplus.Pz()<<", "<<tmuplus.E()<<")\n" << endl;
       //std::cout << "mu plus0 (E, px, px,pz): " << "("<<muplus0.px()<<", "<<muplus0.py()<<", "<<muplus0.pz()<<", "<<muplus0.e()<<")\n" << endl;
       std::cout << "TLorentzVevtor tmu: " << "("<<tmuplus0.Px()<<", "<<tmuplus0.Py()<<", "<<tmuplus0.Pz()<<", "<<tmuplus0.E()<<")\n" << endl;
       std::cout << "********************************************************************\n" << endl;
       //std::cout << "Event size: " << pythia.event.size() << endl;

       pythia.event.list();
     }

   } // End of main for loop.

   // Statistics on event generation.
   pythia.stat();

   // Show histograms.
   mult->Draw();
   muplus0costheta->Draw();
   mupluscostheta->Draw();
   mumu_mass->Draw();

   // Save histograms on file and close file.
   mult->Write();
   muplus0costheta->Write();
   mupluscostheta->Write();
   mumu_mass->Write();

   outputfile->Write();
   outputfile->Close();
   delete outputfile;

   // Done.
   return 0;
}
