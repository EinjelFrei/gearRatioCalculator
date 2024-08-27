#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Get the difference bewteen a and b
float getDifference(float a, float b){
	if(a < b){
		return b - a;
	}else{
		return a - b;
	}
}

int main(){
	float target, max;
	float candidate = 0.0;
	float candidateDiff = 9999999.0;
	int candidateNum, candidateDen;
	int i, j;
	
	printf("Enter target ratio: ");
	scanf("%f", &target);
	
	for(i = 1; i <= 100; i++){
		for(j = 1; j <= 100; j++){
			printf("\n%d:%d (%f)", j, i, (float)j / (float)i);
			
			if(getDifference(target, (float)j / (float)i) < candidateDiff){
				candidate = (float)j / (float)i;
				candidateDiff = getDifference(target, candidate);
				candidateNum = j;
				candidateDen = i;
			}
		}
	}
	
	printf("\n\nFound gear ratio: %d:%d (%f)", candidateDen, candidateNum, candidate);
	printf("\nError: %f", candidateDiff);
}
