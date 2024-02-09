/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:59:30 by junhhong          #+#    #+#             */
/*   Updated: 2024/02/09 15:08:32 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(Stack *a)
{
	int	temp;

	if (a->top < 1)
		return ;
	temp = a->data[a->top];
	a->data[a->top] = a->data[a->top - 1];
	a->data[a->top - 1] = temp;
}

void	pa(Stack *a, Stack *b) // pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
{
	if (b->top < 0)
		return ;
	a->data[a->top] = b->data[b->top];
	b->top--;
}

void	pb(Stack *a, Stack *b) // Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
{
	if (a->top < 0)
		return ;
	b->data[a->top] = a->data[a->top];
	a->top--;
}

int	main()
{
	Stack	a;
	Stack	b;
	int		n;
	int		i=0;

	stack_init(&a);
	stack_init(&b);

	push(&b, 23);

	push(&a, 23);
	push(&a, 5);
	push(&a, 10);
	push(&a, 100);
	push(&a, 77);
	n = a.top;
	printf("##BEFORE##\n");
	while(n)
	{
		printf("%d[%d]		[%d]\n", n, a.data[n], b.data[n]);
		n -- ;
	}
	printf("/ a		b\n");
	printf("##AFTER##\n");
	sa(&a);
	n = a.top;
	while(n >= 0)
	{
		printf("%d[%d]\n", n, a.data[n]);
		n -- ;
	}
}