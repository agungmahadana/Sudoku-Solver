#include <stdio.h>
#include <stdlib.h>
#define N 9

void cetak(int arr[N][N], int row, int col)
{
    printf("\nHasil:\n=========================================\n||");
	for (int i = 0; i < N; i++)
	{
        if (row != 3 && i != 0)
		    printf("|\n-----------------------------------------\n|");

        else if (row == 3){
            printf("|\n=========================================\n|");
            row = 0;
        }
        row++;
		for (int j = 0; j < N; j++){
            if (col != 3)
			    printf(" %d |", arr[i][j]);

            else if (col == 3){
			    printf("| %d |", arr[i][j]);
                col = 0;
            }
            col++;
        }
	}
    printf("|\n=========================================\n");
}

int cek(int matrix[N][N], int row, int col, int bil)
{
	for (int x = 0; x < N; x++)
		if (matrix[row][x] == bil)
			return 0;

	for (int x = 0; x < N; x++)
		if (matrix[x][col] == bil)
			return 0;

	int ujungRow = row - row % 3, ujungCol = col - col % 3; 
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (matrix[i + ujungRow][j + ujungCol] == bil)
				return 0;

	return 1;
}

int solve(int matrix[N][N], int row, int col)
{
	if (row == N - 1 && col == N)
		return 1;

	if (col == N)
	{
		row++;
		col = 0;
	}
	if (matrix[row][col] > 0)
		return solve(matrix, row, col + 1);

	for (int bil = 1; bil <= N; bil++)
	{
		if (cek(matrix, row, col, bil)==1)
		{
			matrix[row][col] = bil;
			if (solve(matrix, row, col + 1)==1)
				return 1;
		}
		matrix[row][col] = 0;
	}
	return 0;
}

int main()
{
	int matrix[N][N], inp;
    printf("=========================================\n");
    printf("||            Sudoku Solver            ||\n");
    printf("=========================================\n");
    printf("\nMasukkan sudoku yang akan di selesaikan:\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("Kotak (%d,%d) = ",i+1,j+1);
            scanf("%d", &inp);
            matrix[i][j] = inp;
        }
    }
	if (solve(matrix, 0, 0)==1)
		cetak(matrix, 0, 0);

	else
		printf("\nSudoku ini tidak bisa diselesaikan");

	return 0;
}