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

23 4 67
3 87