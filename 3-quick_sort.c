#include "sort.h"

void swap(int *a, int *b);
int lomuto_part(int *array, size_t size, int left, int right);
void quick_sort_helper(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap - Swap two integers.
 * @num1: first number to swap.
 * @num2: second number to swap.
 */

void swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * lomuto_part - Order subset of an array of integers according to
 *                    the lomuto partition.
 * @array: array of ints.
 * @size: size of array.
 * @left: starting index.
 * @right: ending index.
 *
 * Return: final partition index.
 */

int lomuto_part(int *array, size_t size, int left, int right)
{
	int *piv, top, bottom;

	piv = array + right;
	for (top = bottom = left; bottom < right; bottom++)
	{
		if (array[bottom] < *piv)
		{
			if (top < bottom)
			{
				swap(array + bottom, array + top);
				print_array(array, size);
			}
			top++;
		}
	}
	if (array[top] > *piv)
	{
		swap(array + top, piv);
		print_array(array, size);
	}
	return (top);
}

/**
 * quick_sort_helper - quicksort through recursion.
 * @array: array.
 * @size: size of array.
 * @left: starting index.
 * @right: ending index.
 *
 * Description: Uses the Lomuto partition scheme.
 */

void quick_sort_helper(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = lomuto_part(array, size, left, right);
		quick_sort_helper(array, size, left, p - 1);
		quick_sort_helper(array, size, p + 1, right);
	}
}

/**
 * quick_sort - Sort array of ints in asc order
 *
 * @array: array .
 * @size: size
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_helper(array, size, 0, size - 1);
}
