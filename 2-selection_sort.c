#include "sort.h"

/**
 * selection_sort - sorts array of ints in ascending order
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, index;
	int min;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		index = 0;
		for (j = i + 1; j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				index = j;
			}
		}
		if (index != 0)
		{
			array[index] = array[i];
			array[i] = min;
			print_array(array, size);
		}
	}
}
