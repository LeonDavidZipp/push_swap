#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	int stacka[6] = {1, 2, 3, 4, 0, 5};
	int temp = stacka[0];
	while (temp <= stacka[0])
	{
		ra_wrapper(stacka, 6);
	}
	printf("stack a: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", stacka[i]);
	}
	printf("\n");
}
