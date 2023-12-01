#include <stdio.h>
struct sparseMatrix{
		int row;
		int col;
		int value;
	}sparse[100];
void main(){
	int rowOriginal, colOriginal, k=1, nonZeroCount=0; 
	printf("Enter the number of Rows and Columns in original matrix: ");
	scanf("%d %d", &rowOriginal, &colOriginal);
	int originalMatrix[rowOriginal][colOriginal];
	printf("Enter the values: \n");
	for(int i = 0; i < rowOriginal; i++){
		for(int j=0; j<colOriginal; j++){
			scanf("%d", &originalMatrix[i][j]);	
		}
	}
	for(int i=0;i<rowOriginal; i++){
		for(int j=0;j<colOriginal; j++){
			if(originalMatrix[i][j]!=0){
				sparse[k].row = i;
				sparse[k].col = j;
				sparse[k].value = originalMatrix[i][j];
				k++;
				nonZeroCount++;
			}
		}
	}
	sparse[0].row = rowOriginal;
	sparse[0].col = colOriginal;
	sparse[0].value = nonZeroCount;
	printf("Sparse matrix represenatation of the given matrix is:\n");
	printf("Row\t Column \t Non-Zero Values\n");
	for(int i=0; i<=nonZeroCount; i++){
		printf("%d\t%d\t%d", sparse[i].row, sparse[i].col, sparse[i].value);
		printf("\n");
	}
}



	
	
	
