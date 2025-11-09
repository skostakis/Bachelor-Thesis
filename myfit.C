{
TFile *_file0 = TFile::Open("mymain91.root");
TBrowser s;
mupluscostheta -> Draw();
int N = mupluscostheta -> Integral();
int Nfwd = mupluscostheta -> Integral(6,10);
int Nbwd = mupluscostheta -> Integral(1,5);
float A = (Nfwd - Nbwd)/(1.0*N);
float sigmaA = 2*sqrt(Nfwd)/N;
float epsilon = 1.0*Nfwd/N;
float sigma_AFB = 2*sqrt(epsilon*(1-epsilon)/N);
cout<<"N, Nfwd, Nbwd, A, sigmaA , sigma_AFB : " << N << " , " << Nfwd << " , "
<< Nbwd << " , " << A << " , " << sigmaA << " , " << sigma_AFB << endl;
}
