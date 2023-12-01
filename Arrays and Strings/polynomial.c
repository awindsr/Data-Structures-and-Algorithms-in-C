#include <stdio.h>
struct polynomial{
	int exp;
	int coeff;
}polyOne[100];

void main(){
	int elementCount;
	printf("Enter the number of polynomials: ");
	scanf("%d", &elementCount);
	
	printf("Enter the polynomials\n");
	for(int i=0; i<elementCount; i++){
		printf("Enter the Coefficient: ");
		scanf("%d", &polyOne[i].coeff);
		
		printf("Enter the Exponential: ");
		scanf("%d", &polyOne[i].exp);
	}
	int min_index=0;
    for(int i=0; i<elementCount; i++){
        min_index=i;
        for(int j=i+1; j<elementCount; j++){
            if (polyOne[i].exp < polyOne[j].exp){
                min_index = j;
            }
        }
		int expTemp = polyOne[i].exp;
        polyOne[i].exp = polyOne[min_index].exp;
        polyOne[min_index].exp = expTemp;
		int coeffTemp = polyOne[i].exp;
		polyOne[i].coeff = polyOne[min_index].coeff;
        polyOne[min_index].coeff = expTemp;

	}
	
	printf("Polynomial Representation\n");
	for(int i =0; i < elementCount; i++){
		printf("%dx^%d", polyOne[i].coeff, polyOne[i].exp);
		if(i!=elementCount-1){
			printf("+");
		}
		else{
		printf("\n");
		}
	}

}
