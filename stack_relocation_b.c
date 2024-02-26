/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_relocation_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:08:09 by junhhong          #+#    #+#             */
/*   Updated: 2024/02/21 11:12:19 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sb(Stack *b)
{
	int	temp;

	if (b->top < 1)
		return ;
	temp = b->data[b->top];
	b->data[b->top] = b->data[b->top - 1];
	b->data[b->top - 1] = temp;
    ft_putstr_fd("sb\n", 1);
}

void	pb(Stack *b, Stack *a) // pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
{
	push(b, a->data[a->top]);
	pop(a);
	ft_putstr_fd("pb\n", 1);
}

void	rb(Stack *b) // Shift up all elements of stack a by 1.
{
	int	i;
	int	temp;

	if (b->top < 1)
		return ;
	i = b->top;
	temp = b->data[b->top];
	while(i > 0)
	{
		b->data[i] = b->data[i - 1];
		i -- ;
	}
	b->data[0] = temp;
    ft_putstr_fd("rb\n", 1);
}


void	rrb(Stack *b) // Shift down all elements of stack a by 1.
{
	int	i;
	int	temp;

	if (b->top < 1)
		return ;
	i = 0;
	temp = b->data[0];
	while(i <= b->top - 1)
	{
		b->data[i] = b->data[i + 1];
		i ++ ;
	}
	b->data[b->top] = temp;
    ft_putstr_fd("rrb\n", 1);
}
