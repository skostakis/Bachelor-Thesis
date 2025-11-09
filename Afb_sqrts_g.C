#include <TGraphErrors.h>
#include "TF1.h"
#include "TLatex.h"

{
     float x[11] = {30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130}; 
// sqrt(s) [GeV]
     float y[11] = {0.00122945, 0.00496524, -0.00898893, -0.00173319, 
-0.00380566,
                    0.00420774, 0.00187883, 0.00627959, -0.00003297, 
-0.00770627,
                    -0.00892035}; // A_FB
     float ex[11];
     float ey[11];

     for (int i = 0; i < 11; i++) {
         ex[i] = 0.1;
     }

     float sigma_values[11] = {2.41, 2.31, 2.48, 2.67, 2.78, 2.94, 
3.08, 3.22, 3.30, 3.42, 3.54};
     for (int i = 0; i < 11; i++) {
         ey[i] = sigma_values[i] * 1e-5;
     }

     // Create the graph
     auto gr = new TGraphErrors(11, x, y, ex, ey);
     gr->SetTitle("A_FB - sqrt(s); sqrt(s) [GeV]; A_FB");
     gr->SetMarkerColor(4);
     gr->SetMarkerStyle(21);
     gr->Draw("ALP");

     // Define a fitting function (linear example)
     TF1 *fitFunc = new TF1("fitFunc", "[0]", 30, 130); // p0 is the constant
     gr->Fit(fitFunc);

     // Extract p0 and its error
     double p0 = fitFunc->GetParameter(0);
     double p0_err = fitFunc->GetParError(0);

     // Add text to the canvas showing p0 +/- error
     TLatex latex;
     latex.SetNDC();
     latex.SetTextSize(0.04);
     latex.DrawLatex(0.2, 0.8, Form("p0 = %.6f #pm %.6f", p0, p0_err));

     // Optional: update canvas
     gPad->Update();
}
