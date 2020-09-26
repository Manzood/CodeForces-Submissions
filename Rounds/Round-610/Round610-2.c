#include <stdio.h>

int partition(int a[], int low, int high)
{
	int p = a[high];
	int i = low-1;

	for (int j = low; j< high; j++)
		if (a[j] < p)
		{
			i++;
			a[i] = a[i] + a[j];
			a[j] = a[i] - a[j];
			a[i] = a[i] - a[j];
		}

	i++;

	a[i] = a[i] + a[high];
	a[high] = a[i] - a[high];
	a[i] = a[i] - a[high];

	return (i);
}

void quicksort(int a[], int low, int high)
{
	if (low < high)
	{
		int p = partition(a, low, high);

		quicksort(a, low, p-1);
		quicksort(a, p+1, high);
	}
}

int main()
{
	int t;
	int n, p, k, max, anseven, ansodd, i;

	scanf("%d", &t);

	while (t--)
	{
		int sumeven = 0;
		int sumodd = 0;
		anseven = 0;
		ansodd = 0;

		scanf ("%d %d %d", &n, &p, &k);

		int a[n];

		for (int i = 0; i < n; i++)
		{
			scanf ("%d", &a[i]);
		}

		quicksort(a, 0, n-1);

		for (i = 0; i < n; i++)
		{
			printf("%d ", a[i]);
			max = i;
		}

		printf("max = %d\n", max);

		for (i = 0; i < max && (sumeven<p || sumodd<p); i++)
		{
			if (i%2==1 && sumodd<p)
			{
				sumodd += a[i];
				if (ansodd>0)
					ansodd+=2;
				else
					ansodd+=1;
			}
			
			if (i%2==0 && sumeven<p)
			{
				sumeven+=a[i];
				anseven+=2;
			}

			printf("e = %d\n", sumeven);
			printf("o = %d\n", sumodd);
		}

		if (anseven>ansodd)
			printf("%d\n", anseven);
		
		else
			printf("%d\n", ansodd);
	}
}