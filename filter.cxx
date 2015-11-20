#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

void reading(double* const p,const int N, const string fname){
 ifstream in(fname.c_str());
 for(int i=0; i<N; i++){
  in >> p[i];
 }
 in.close();
}

void filter(double* const p,const int N){
  double a,b,s;
  a=p[N-1];
  s=p[0];
 
 for(int i=0; i<N-1; i++){
   
   b=p[i];
   
   p[i]=(a+p[i]+p[i+1])/3;
 
   a=b;
 }
 p[N-1]=(p[N-1]+b+s)/3;
} 


int main(void){
 const int N=240;
 const string filename="noisy.txt";
 double* p=new double[N];

 reading(p,N,filename);
 filter(p,N);
 filter(p,N);
 
 ofstream out("filtered.txt");
 
 for(int i=0; i<N; i++){
   out << i << "\t" << p[i] << endl;
 }
 delete [] p;
 out.close();

  return 0; 
}