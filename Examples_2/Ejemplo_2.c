#include <stdio.h>
#include <math.h>

float mean_calc(int a[], int n) {
	/* Calculation of the mean value of an array */
	int size = n;
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i];
		// printf("Score %d: %d. \n",i+1, a[i]);
		// printf("Sum: %d \n", sum);
		// printf("--------------\n");
	}
	// printf("Mean: %.2f.\n", (float)sum / size);
	return (float)sum / size;
}

float stand_dev(int a[], int n) {
	/* Calculation of the standard deviation of an array */
	float sum = 0.0;
	float mean = mean_calc(a, n);
	for (int i = 0; i < n; i++) {
		sum += powf(a[i]-mean,2);
	}
	return sqrtf(sum / (n-1));
}

void scoring_students(int n) {
	/* INTRODUCING ARRAYS AND POINTERS TO THE ARRAY MEMO */

	// What we are doing here is reserve some memory (int) in a specific memory point for the scores array. So if 5 int size is needed for the memory, we will have to reserve all that
	// So we will can use it. 

	int* scores = malloc(n * sizeof(int));
	printf("%p\n", scores);
	printf("%d\n", *scores);
	// Scaning which s each of the scores of the array

	for (int i = 0; i < n; i++) {
		printf("Enter score %d (0-100):", i + 1);
		scanf_s("%d", &scores[i]);
		while (scores[i] < 0 || scores[i]>100) {
			printf("\n");
			printf("Please, introduce an number for score %d between 1 and 100:", i + 1);
			scanf_s("%d", &scores[i]);
			printf("\n");
		}
	}
	printf("Adress of first element is %p:\n", &scores[0]);
	printf("Adress of scores is %p:\n", &scores);
	printf("Length of the scores is %d.\n", (&scores[0]) - &scores[n-1]);
	// Printing the scores of the different students. 


	printf("Size of the scores: %lu\n", n * sizeof(int));
	printf("Size of each element: %lu\n", sizeof(scores[0]));
	printf("The scores are:\n");
	for (int i = 0; i < n; i++) {
		printf("Score [%d] Adress: %p Content: %d \n", i + 1, &scores[i], scores[i]);
	}
	printf("The mean score of the students is: %.2f.\n", mean_calc(scores, n));
	printf("The standard deviation of the scores is: %.2f.\n", stand_dev(scores, n));
	
	free(scores);
	scores = NULL;
}

int main() {

	int n;
	
	printf("Introduce the size of the matrix array:");
	scanf_s("%d", &n);
	scoring_students(n);

	return 0;
}