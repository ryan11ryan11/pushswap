/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:39:45 by junhhong          #+#    #+#             */
/*   Updated: 2024/02/09 15:14:20 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#define MAX 100


typedef struct stack
{
	int	data[MAX];
	int	top;
}Stack;

int		is_empty(Stack *a);
int		is_full(Stack *a);
int		push(Stack *a, int i);
int		pop(Stack *a);
void	stack_init(Stack *a);