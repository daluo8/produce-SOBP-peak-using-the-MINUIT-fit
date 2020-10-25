# produce-SOBP-peak-using-the-MINUIT-fit
Here we use TOPAS(a Monte Carlo simulation package based on GEANT4)to calculate 20 different BP curves.
The calculate.m calculates the dose in normal and tumor area for each BP.
The we use MINUIT2(a C++ rewritten version of MINUIT) to calculate the best weight of each BP to produce a SOBP. 
In the folder "dosedata"are the BP dose-depth data which is saved as .csv format.
Then use drawBP.m to draw a SOBP curve.
P.S You need to install the ROOT data calculate frame before use MINUIT2.
