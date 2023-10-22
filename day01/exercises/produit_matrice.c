#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define N 500

 


// Fonction pour multiplier deux matrices en blocs
void Produit_Bloc(double A[N][N], double B[N][N], double C[N][N], int blockSize) {
    for (int i = 0; i < N; i += blockSize) {
        for (int j = 0; j < N; j += blockSize) {
            for (int k = 0; k < N; k += blockSize) {
                for (int ii = i; ii < i + blockSize && ii < N; ii++) {
                    for (int jj = j; jj < j + blockSize && jj < N; jj++) {
                        for (int kk = k; kk < k + blockSize && kk < N; kk++) {
                            C[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    // Matrices d'entrée et de sortie
    
    
  //int N = 1000000;
  
  double a[N][N], b[N][N], c[N][N];
  double mean, rate, msec, start, end;
  srand(time(NULL));
  
  
  // Remplir les matrices A et B avec des données
  for(int i = 0; i < N; i++)
  	for(int j = 0; j < N; j++){
  		a[i][j] = rand()%100 + 1.0;
  		b[i][j] = rand()%100 + 1.0;
  	}
    

    
  printf("stride, time(msec), rate(MB/s)\n");
  for(int k = 1; k < 50; k+=10){
  
  	start = (double)clock()/(double)CLOCKS_PER_SEC;
    	Produit_Bloc(a, b, c, k);
    	end = (double)clock()/(double)CLOCKS_PER_SEC;
    	
   	msec = end - start;
   	
   	//mean/=N;
			
	msec=(end-start)*1000.0; //time in milli-second;
	double rate = sizeof(double)*2*N*N*(1000.0/msec)/(1024*1024);
			
	printf("%d, %f; %f\n", k, msec, rate);
  }

    return 0;
}

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
      
  
