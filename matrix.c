#include <stdio.h>

void setup(int m_1[10][10], int m_2[10][10]) {
    int row, col, ro, co;

    printf("For matrix 1:\n");
    printf("n(row): ");
    scanf("%d", &row);
    printf("n(column): ");
    scanf("%d", &col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("number(%d,%d): ", i, j);
            scanf("%d", &m_1[i][j]);
        }
    }
	printf("\t\tMATRIX 1\n");

	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
		printf("%d ", m_1[i][j]);
		}
		printf("\n");
	}

    printf("\nFor matrix 2:\n");
    printf("n(row): ");
    scanf("%d", &ro);
    printf("n(column): ");
    scanf("%d", &co);

    for (int i = 0; i < ro; i++) {
        for (int j = 0; j < co; j++) {
            printf("number(%d,%d): ", i, j);
            scanf("%d", &m_2[i][j]);
        }
    }
    	printf("\t\tMATRIX 2\n");

	for(int i = 0; i < ro; i++){
		for(int j = 0; j < co; j++){
		printf("%d ", m_2[i][j]);
		}
		printf("\n");
	}

 if(col != ro){
        printf("cant multiply!..");
        return;
    }
    int m_r[10][10] = {0};
    printf("\t\tMATRIX RESULT\n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < co; j++){
            for(int k = 0; k < col; k++){
                m_r[i][k] += m_1[i][j]*m_2[j][k];
            }
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < co; j++){
            printf("%d ", m_r[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m_1[10][10], m_2[10][10];
    setup(m_1, m_2);
    return 0;
}
