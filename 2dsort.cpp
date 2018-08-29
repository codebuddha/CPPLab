#include <stdio.h>
#include <stdlib.h>

void qsrt(int left, int right, int **arr, int n, int m)
{
	if(left>=right-2)
		return;
	int pivot = arr[(left+1)/m][(left+1)%m], i=0, j, temp, end = right, 											start=left;
	while(left!=right-1)
	{
		if(i%2 == 0)
		{
			if(pivot>=arr[(left+1)/m][(left+1)%m])
				left++;
			else
			{
				temp = arr[(left+1)/m][(left+1)%m];
				arr[(left+1)/m][(left+1)%m] = arr[(right-											1)/m][(right-1)%m];
				arr[(right-1)/m][(right-1)%m] = temp;
				right--;
			}
		}
		else
		{
			if(pivot<=arr[(right-1)/m][(right-1)%m])
				right--;
			else
			{
				temp = arr[(left+1)/m][(left+1)%m];
				arr[(left+1)/m][(left+1)%m] = arr[(right-											1)/m][(right-1)%m];
				arr[(right-1)/m][(right-1)%m] = temp;
				left++;
			}
		}
		i++;
	}
	if(left!=start)
	{
		arr[(start+1)/m][(start+1)%m] = arr[left/m][left%m];
		arr[left/m][left%m] = pivot;
	}
	qsrt(start, left, arr, n, m);
	qsrt(left, end, arr, n, m);
}

int main()
{
	int **arr, i, j, n, m;
	printf("Enter the row and column size: ");
	scanf("%d%d",&n, &m);
	arr = (int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		arr[i] = (int *)malloc(m*sizeof(int));
	printf("Enter the 2D array:\n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d", &arr[i][j]);
	qsrt(-1, n*m, arr, n, m);
	printf("The sorted 2D array is:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("\t%d", arr[i][j]);
		printf("\n");
	}
	printf("\n");
	return 0;
}
