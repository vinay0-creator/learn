//Q : print  1
//	    2 3
//	   4 5 6

#include<stdio.h>
int n = 1;
int main(){
	for(int i = 1; i <= 3; i++){
		for(int k = 3 - i; k >= 0; k--){
			printf(" ");
		}
		for(int j = 1; j <= i; j++){
		printf("%d ", n);
		n++;
		}
	printf("\n");
	}
	return 0;
}
