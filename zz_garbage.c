static void	sort_4(t_stack *st_a, t_stack *st_b)
{
	if (st_a->h < 4)
	{
		sort_3_a(st_a);
		return ;
	}
	pb_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
	sort_3_a(st_a);
	if (st_b->st[0] < st_a->st[0] || st_b->st[0] > st_a->st[st_a->h - 1])
	{
		pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
		if (st_a->st[0] > st_a->st[st_a->h - 1])
			ra_wrapper(st_a->st, st_a->h);
		return ;
	}
	// else if (st_b->st[0] > st_a->st[0] && st_b->st[0] < st_a->st[1])
	// {
	// 	ra_wrapper(st_a->st, st_a->h);
	// 	pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
	// 	rra_wrapper(st_a->st, st_a->h);
	// }
	// else
	// {
	// 	rra_wrapper(st_a->st, st_a->h);
	// 	pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
	// 	ra_wrapper(st_a->st, st_a->h);
	// 	ra_wrapper(st_a->st, st_a->h);
	// }
	// if (st_b->st[0] > st_a->st[0] && st_b->st[0] < st_a->st[1])
	// 	ra_wrapper(st_a->st, st_a->h);
	// else
	// 	rra_wrapper(st_a->st, st_a->h);
	// pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
	// if (st_a->st[st_a->h - 1] < st_a->st[0])
	// 	rra_wrapper(st_a->st, st_a->h);
	// else
	// {
	// 	ra_wrapper(st_a->st, st_a->h);
	// 	ra_wrapper(st_a->st, st_a->h);
	// }
}