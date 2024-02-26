/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:39:45 by junhhong          #+#    #+#             */
/*   Updated: 2024/02/26 15:27:51 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100


typedef struct stack
{
	int	data[MAX];
	int	top;
}Stack;

typedef struct stackstructure
{
	int	target;
	int	standard;
	int	prv_target;
	int	mid;
	int	target_location;
}Stackstructure;

int		is_empty(Stack *a);
int		is_full(Stack *a);
int		push(Stack *a, int i);
int		pop(Stack *a);
void	stack_init(Stack *a);
int		ft_atoi(const char *nptr);
// void	pa(Stack *a, Stack *b);
// void	rra(Stack *a);
// void	sa(Stack *a);
// void	ra(Stack *a);
// void	pb(Stack *a, Stack *b);
// void	rrb(Stack *a);
// void	sb(Stack *a);
// void	rb(Stack *a);
void	ft_putstr_fd(char *s, int fd);
void	a_sort(Stack *a, int *s, int argc);
int		where_is(Stack *a, int target);
void	stack_check(Stack *a, Stack *b, int *s, int argc);


void	swap(Stack *s, int type);
void	element_move(Stack *a, Stack *b, int type);
void	stack_up(Stack *s, int type);
void	stack_down(Stack *s, int type);