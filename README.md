# Bachelor Thesis
## Calculation of the weak mixing angle sin2(θw) with e− e+ → γ/Ζ → μ− μ+ simulated events

The aim of this Thesis is to calculate the weak mixing angle (θw) with the help of a simulated experiment. In particular, we simulate the collision of an electron with a positron, which leads to the creation of a muon and an antimuon, at collision energies between 30 GeV and 130 GeV. The simulation is performed with the help of the PYTHIA software, while the data analysis and processing is performed with code developed in C++ in the ROOT (CERN) environment. The angular distribution of the antimuon (μ+) is stored in histograms, from which the code calculates the "forward-backward" asymmetry (events where μ+ has a polar angle θ>0 or has θ<0). The forward-backward asymmetry is the parameter that is strongly related to the weak mixing angle and depends strongly on the collision energy. Thus, by measuring the asymmetry at different energies we can calculate the mixing angle. In the present work, we simulated the above process in three ways: with only the photon (γ) as a propagator, with only the boson Z as a propagator, and with both γ and Ζ in the propagator (which is the realistic case). The angular distributions of the positive muon and the asymmetry values were found to be in agreement with the predictions of the theory. The value of the weak mixing angle, calculated from the asymmetry, was found to be constant, independent of the collision energy. Its value is in relatively good agreement with both the value used by PYTHIA and with the experimental measurements in the literature.

The full Bachelor's Thesis can be found here: https://ikee.lib.auth.gr/record/360530/files/Kostakis.pdf

## How this works

Keep in mind that this current work was done using "outdated" versions of Pythia event simulator and ROOT. Nothing changes dramatically though, so the basic analysis logic does not change.

* Download the files mymain91.cc, inputmyeezpythia.cmd and myfit.C into your examples file inside Pythia
* Using `make mymain91` you can make the file mymain91 (which was based on the main91 example of Pythia)
* To run the file use `./mymain91 inputmyeezpythia.cmd`
* We now run the myfit.C file using `root myfit.C` to find the  forward - backward assymetry (A_FB) and the error in A_FB for a **specific** Center of Mass (CoM) energy you coose in the inputmyeezpythia.cmd file.
* Exept from playing with the CoM energy in the inputmyeezpythia.cmd file, you can also play arround with the 3 propagator cases (gamma only, Z only and both)
* The uploaded .C files like Afb are the code files in ROOT I used to take my forward - backward Assymetry measurements. You can follow the logic of these files and do them on your own (since the Monte Carlo seed will be different and you will have different "numbers" after you run the code)
