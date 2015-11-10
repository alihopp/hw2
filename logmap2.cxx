#include <iostream>
#include <fstream>

using namespace std;

int main(){
	double x0 = 0.5;
	double x;
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations
	double savdat[Nend-Nskip]; // data for ext.file

	ofstream out("output.dat");

	for(double r=0; r <= 4; r += 0.001){
	   x=x0;
	   for(int i=1; i <= Nskip; i++)
		   x = r*x*(1-x);
	   for(int i=Nskip+1; i <= Nend; i++){
	   		   x = r*x*(1-x);
	   		   //cout << r << "\t" << x << endl; 
			   // no use: should be printed for ext.file
			   savdat[i-Nskip-1] = x;
   	   }
		for(int i=1; i<=(Nend-Nskip);i++){
				out << r << "\t" << savdat[i-1] << endl;
		}
	}
	
	out.close();

	return 0;
}
