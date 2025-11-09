#include <TGraphErrors.h>
#include "TF1.h"
#include "TLatex.h"

{
     float x[11] = {30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130}; 
// sqrt(s) [GeV]
     float y[11] = {0.019063, 0.0184803, 0.013827, 0.0148116, 0.0152938,
                    0.00980431, 0.0151478, 0.0190867, 0.0158339, 0.0205189,
                    0.0154266}; // A_FB

     float ex[11];  // Error in x (sqrt(s)), assumed to be zero
     float ey[11];  // Error in y (sigma_A_FB)

     // Initialize ex to 0.1 for all points
     for (int i = 0; i < 11; i++) {
         ex[i] = 0.1;  // Error in sqrt(s), adjust if needed
     }

     // Initialize ey with the given sigma values (scaled by 10^-5)
     float sigma_values[11] = {5.50, 3.82, 3.23, 2.86, 2.75, 2.96, 
5.97, 6.04, 9.84, 0.12, 0.14};
     for (int i = 0; i < 11; i++) {
         ey[i] = sigma_values[i] * 1e-5;  // Convert to 10^-5 scale
     }

     // Create the graph
     auto gr = new TGraphErrors(11, x, y, ex, ey);
     gr->SetTitle("A_FB - sqrt(s); sqrt(s) [GeV]; A_FB");
     gr->SetMarkerColor(4);
     gr->SetMarkerStyle(21);
     gr->Draw("ALP");

     // Define a fitting function (constant function for p0)
     TF1 *fitFunc = new TF1("fitFunc", "[0]", 30, 130);  // p0 is the constant
     gr->Fit(fitFunc);

     // Extract p0 and its error
     double p0 = fitFunc->GetParameter(0);
     double p0_err = fitFunc->GetParError(0);

     // Add text to the canvas showing p0 +/- error
     TLatex latex;
     latex.SetNDC();  // Use normalized coordinates
     latex.SetTextSize(0.04);
     latex.DrawLatex(0.2, 0.8, Form("p0 = %.6f #pm %.6f", p0, p0_err));

     // Optional: update canvas
     gPad->Update();
}
