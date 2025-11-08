//rock paper scissors.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<unistd.h>
int main(){
	char *choose = "rps";
	int choose_len = strlen(choose);
	int n;
	int y = 0, c = 0;
	printf("Number of rounds you want to play :");
	scanf("%d", &n);
	srand(time(NULL));
	getchar();
	for(int i = 0; i < n; i++){
		char p;
		int comp_ch = choose[rand() % choose_len];
		printf("\nRound %d\n", i+1);
		printf("your choise(r/p/s) : ");
		scanf(" %c", &p);
		printf("computers choise : %c\n", comp_ch);
		if(p == comp_ch) printf("it's a tie!\n");
		else if((p == 'r' && comp_ch == 's') || (p == 'p' && comp_ch == 'r') || (p == 's' && comp_ch == 'p')){printf("you won this round!\n"); y++;}
		else {
			printf("computer won!\n");
			c++;
		}
	}
	if(y > c){
		printf("\nyou won!\nyour score : %d and comp score : %d\n", y, c);
	}
	else if(y < c){
		printf("\nyou lose!\nyour score : %d and comp score : %d\n", y, c);
	}
	else {
		printf("\nit's a tie!\nyour score : %d and comp score : %d\n", y, c);
	}
	return 0;
}
