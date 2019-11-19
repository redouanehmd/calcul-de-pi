// hammad radhouane

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#include<math.h>
#include<time.h>
#include<omp.h>


#define n 2000

int main(){
	double TDebSeq ,TFinSeq ,TDebPar ,TFinPar ;
	double ResSeq ,SumSeq ,ResPar ,SommeParal;
	int i;
	
	//calcul sequantielle
	
	TDebSeq=clock();
	SumSeq=0;
	
	for(i=0;i<n*600;i++){
		SumSeq=SumSeq+pow(-1,i)/(2*i+1);
	}
	ResSeq=SumSeq*4;
	
	TFinSeq=clock();
	
	printf("pi seq = %f \n",ResSeq);
    printf("temps execution seq = %f\n",  (double)(TFinSeq-TDebSeq)/CLOCKS_PER_SEC); 
    
    //calcul parallel
    
    
    #pragma omp parallel 
    {
    	SommeParal=0;
	TDebPar = clock();
	#pragma omp for reduction( +: sum ) 
    {
    
    	for(i=0;i<n*600;i++){
	    SommeParal=SommeParal+pow(-1,i)/(2*i+1);
	}
	ResPar=SommeParal*4;
	TFinPar=clock();
	printf("pi par = %f \n",ResPar);
    printf("temps execution par = %f\n",  (double)(TFinPar-TDebPar)/CLOCKS_PER_SEC); 
	}
	
    } 
    
     
}

