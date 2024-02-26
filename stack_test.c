/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:50:56 by junhhong          #+#    #+#             */
/*   Updated: 2024/02/26 15:32:56 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(Stack *s, int type)
{
	int	temp;

	if (s->top < 1)
		return ;
	temp = s->data[s->top];
	s->data[s->top] = s->data[s->top - 1];
	s->data[s->top - 1] = temp;
	if (type == 'a')
		ft_putstr_fd("sa\n", 1);
	if (type == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	element_move(Stack *a, Stack *b, int type) // pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
{
	push(a, b->data[b->top]); // pa , 타입란에 첫번째 요소 (a,b,a) or (a,b,b) 뒤에있는(b 를 빼서 a에 꼭대기에 넣음
	pop(b);
	if (type == 'a')
		ft_putstr_fd("pa\n", 1);
	if (type == 'b')
		ft_putstr_fd("pb\n", 1);
}

void	stack_up(Stack *s, int type) // Shift up all elements of stack a by 1. 
{
	int	i; // ra
	int	temp;

	if (s->top < 1)
		return ;
	i = s->top;
	temp = s->data[s->top];
	while(i > 0)
	{
		s->data[i] = s->data[i - 1];
		i -- ;
	}
	s->data[0] = temp;
	if (type == 'a')
	    ft_putstr_fd("ra\n", 1);
    if (type == 'b')
        ft_putstr_fd("rb\n", 1);
}


void	stack_down(Stack *s, int type) // Shift down all elements of stack a by 1.
{
	int	i; // rra
	int	temp;

	if (s->top < 1)
		return ;
	i = 0;
	temp = s->data[0];
	while(i <= s->top - 1)
	{
		s->data[i] = s->data[i + 1];
		i ++ ;
	}
	s->data[s->top] = temp;
	if (type == 'a')
	    ft_putstr_fd("rra\n", 1);
    if (type == 'b')
        ft_putstr_fd("rrb\n", 1);
}
