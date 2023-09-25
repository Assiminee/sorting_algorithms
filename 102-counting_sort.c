#include "sort.h"

/**
 * largest_int - finds the largest integer in an array
 * @array: array
 * @size: size of the array
 *
 * Return: the largest integer in an array
 */
int largest_int(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return max;
}

/**
 * init_count_array - creates the count array and initializes it to zeros
 * @size: size to allocate
 *
 * Return: the count array
 */
int *init_count_array(int size)
{
	int *count = malloc(size * sizeof(int));
	int i;

	for (i = 0; i < size; i++)
		count[i] = 0;
	return count;
}

/**
 * counting_sort - sorts an array in ascending order using counting sort
 * @array: array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int k;
	int *count;

	if (array == NULL || size < 2)
		return;

	k = largest_int(array, size);
	count = init_count_array(k + 1);

	for (i = 0; i < size; i++)
		count[array[i]] += 1;

	for (i = 1; (int)i < k + 1; i++)
		count[i] += count[i - 1];

	print_array((const int *)count, (size_t)k+1);

	for (i = 0; (int)i < k + 1; i++)
	{
		if (count[i] == 0 || count[i] == count[i - 1])
			continue;
		array[count[i - 1]] = i;
	}
}
