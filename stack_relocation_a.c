/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_relocation_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:50:56 by junhhong          #+#    #+#             */
/*   Updated: 2024/02/21 11:12:45 by junhhong         ###   ########.fr       */
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
	ft_putstr_fd("sa\n", 1);
}

void	pa(Stack *a, Stack *b) // pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
{
	push(a, b->data[b->top]);
	pop(b);
	ft_putstr_fd("pa\n", 1);
}

void	ra(Stack *a) // Shift up all elements of stack a by 1.
{
	int	i;
	int	temp;

	if (a->top < 1)
		return ;
	i = a->top;
	temp = a->data[a->top];
	while(i > 0)
	{
		a->data[i] = a->data[i - 1];
		i -- ;
	}
	a->data[0] = temp;
	ft_putstr_fd("ra\n", 1);
}


void	rra(Stack *a) // Shift down all elements of stack a by 1.
{
	int	i;
	int	temp;

	if (a->top < 1)
		return ;
	i = 0;
	temp = a->data[0];
	while(i <= a->top - 1)
	{
		a->data[i] = a->data[i + 1];
		i ++ ;
	}
	a->data[a->top] = temp;
	ft_putstr_fd("rra\n", 1);
}
