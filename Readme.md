how to use checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
segfaults!
ARG="4 67 3 87 100 10000"; ./push_swap $ARG | ./checker_Mac $ARG
4 67 3 87 100 10000

6 7 0 -1 3 A
10 -6 5 11 B
1. split up runs
2. start remerging runs, switching between stacks
	in the above example: merge run 1 of B (10) to run 1 of A (6, 7) 
	->6 7 10 0 -1 3 A
	  -6 5 11
	now merge run 1 of A (6 7 10) to run 1 of B (-6 5 11)
	->0 -1 3 A
	  -6 5 6 7 10 11

-1 1 10 2 A
6 7 8 9 B
if runs a > runs b merge from a to b first, else merge to a first and then alternate
whiel one run is ongoing (stack_a[0] < stack_a[1])
	if (stacka[0] < stackb[0])
		push to b
	rotate b b[0] to back
	counter++;
while counter-- > 0
	rotate b to front

4 67 3 87 23

23 4 67
3 87

23	3		
4	87	->
67


static void	merge_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int		counter;
	int		temp;

	counter = 0;
	while (1)
	{
		temp = stack_a->stack[0];
		if (stack_a->stack[0] < stack_b->stack[0])
			pb_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		rb_wrapper(stack_b->stack, stack_b->height);
		if (stack_a->stack[0] < stack_b->stack[0])
			pb_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		counter++;
		if (temp > stack_a->stack[0])
			break ;
	}
	while (counter-- > 0)
		rrb_wrapper(stack_b->stack, stack_b->height);
}

merging a run to the other stack
while first element of stack to merge from is larger than the following (inclusive) and first element of stack to push to is larger than stack to push from push the element. else rotate stack to push from and try again

while a[0] > a[1] && height[a] > 1
	if b[0] > a[0]:
		push to b
	rotate b
<!-- if height[a] > 1 && a[0] > a[1] -->
push to b
rotate b
