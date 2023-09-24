#include "sort.h"

/**
 * shell_sort - sorts array in ascending order using shell sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 0, i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;
	for (; gap >= 1; gap = (gap - 1) / 3)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; (int)i >= 0; i--)
			{
				if (array[i + gap] < array[i])
				{
					tmp = array[i];
					array[i] = array[i + gap];
					array[i + gap] = tmp;
				}
				else
					break;
			}
		}
		print_array((const int*)array, size);
	}
}
