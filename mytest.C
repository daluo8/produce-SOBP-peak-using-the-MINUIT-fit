#include "Minuit2/FCNBase.h"
#include "Minuit2/FunctionMinimum.h"
#include "Minuit2/MnUserParameterState.h"
#include "Minuit2/MnMigrad.h"
#include "Minuit2/MnPrint.h"
#include "math.h"
#include<string>
#include<fstream>
using namespace ROOT::Minuit2;
void read(double array[],string filename){
	ifstream infile(filename,ios::in);
	double* ptr=&array[0];
	for(int i=0;i<100;i++)
	{
		infile>>*ptr;
		ptr++;
	}
	//infile.close;
}
class MinimizeFCN:public ROOT::Minuit2::FCNBase
{
	public:
	MinimizeFCN()
        : error_def{1.0} // change to 0.5 if maximizing LL
    	{
    	}
	virtual ~MinimizeFCN()
	{
	}
	virtual
	double Up() const
	{
		return error_def;
	}
	//operator()
	//this function calculates "fval"
	//In this code,parabola:F=RxS
	virtual
	double operator()(const std::vector<double>&par)const
	{
		double w1=par[0];
		double w2=par[1];
		double w3=par[2];
		double w4=par[3];
		double w5=par[4];
		double w6=par[5];
		double w7=par[6];
		double w8=par[7];
		double w9=par[8];
		double w10=par[9];
		double w11=par[10];
		double ft_1[100],ft_2[100],ft_3[100],ft_4[100],ft_5[100],ft_6[100],ft_7[100],ft_8[100],ft_9[100],ft_10[100],ft_11[100];
		string file1="dosedata_1.txt",file2="dosedata_2.txt",file3="dosedata_3.txt",file4="dosedata_4.txt",file5="dosedata_5.txt",file6="dosedata_6.txt",file7="dosedata_7.txt",file8="dosedata_8.txt",file9="dosedata_9.txt",file10="dosedata_10.txt",file11="dosedata_11.txt";
	read(ft_1,file1);
	read(ft_2,file2);
	read(ft_3,file3);
	read(ft_4,file4);
	read(ft_5,file5);
	read(ft_6,file6);
	read(ft_7,file7);
	read(ft_8,file8);
	read(ft_9,file9);
	read(ft_10,file10);
	read(ft_11,file11);
		double fn=(w1*2.7232+w2*2.7876+w3*2.8593+w4*2.9328+w5*3.0233+w6*3.1259+w7*3.2393+w8*3.3752+w9*3.5491+w10*3.7827+w11*4.1533)*pow(10,-8);
		
		double ft=(w1*4.7219+w2*5.4480+w3*5.8435+w4*5.4761+w5*5.0463+w6*4.5898+w7*4.1050+w8*2.5634+w9*2.9523+w10*2.2434+w11*1.2775)*pow(10,-8);
		double r=fn/ft;
		cout<<"r="<<r<<endl;
		double ft2=0.0;
		for(int i=0;i<100;i++)
		{
			ft2+=pow(w1*ft_1[i]+w2*ft_2[i]+w3*ft_3[i]+w4*ft_4[i]+w5*ft_5[i]+w6*ft_6[i]+w7*ft_7[i]+w8*ft_8[i]+w9*ft_9[i]+w10*ft_10[i]+w11*ft_11[i],2);	
		}
		ft2=0.1*ft2/10;
		double temp=ft2-ft*ft;
		cout<<"ft2-ft^2="<<temp<<endl;
		double s=(sqrt(ft2-ft*ft))/ft;
		
		cout<<"s="<<s<<endl;
		double fval=0.0;
		fval=r*s;
		return fval;
	}
	protected:
	double error_def;
	private:
};


int myfcn()
{
	MinimizeFCN fcn;
	VariableMetricMinimizer theMinimizer;
	MnUserParameters upar;
	upar.Add("w1",1.);
	upar.Add("w2",1.,0.1,0.0,1.0);
	upar.Add("w3",1.,0.1,0.0,1.0);
	upar.Add("w4",1.,0.1,0.0,1.0);
	upar.Add("w5",1.,0.1,0.0,1.0);
	upar.Add("w6",1.,0.1,0.0,1.0);
	upar.Add("w7",1.,0.1,0.0,1.0);
	upar.Add("w8",1.,0.1,0.0,1.0);
	upar.Add("w9",1.,0.1,0.0,1.0);
	upar.Add("w10",1.,0.1,0.0,1.0);
	upar.Add("w11",1.,0.1,0.0,1.0);
	MnMigrad migrad(fcn,upar);
	FunctionMinimum min = migrad();
	std::cout<<"minum:"<<min<<std::endl;
    	return 0;

}
	
