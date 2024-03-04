/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:59:30 by junhhong          #+#    #+#             */
/*   Updated: 2024/02/27 15:14:10 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ab_swap(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

void	stack_devide(Stack *a, Stack *b, int *s, int argc)
{
	int	standard;
	int	i;
	int	j;

	printf("devide start\n");
	i = 0;
	j = a->top;
	standard = s[(argc - 1) / 2];
	printf("argc:%d, a->top:%d, standard:%d\n",argc, a->top, standard);
	while (i <= j) // a->top = 8 (0~8 : 9개 숫자)
	{
		//printf("i::%d a::%d\n",i, a->data[a->top]);
		if (a->data[a->top] < standard)
			element_move(b, a, 'b');
		else
			stack_up(a,'a');
		i ++ ;
	}
	//printf("a->top:%d b->top:%d\n", a->top, b->top);
}

void	quicksort(int s[], int start, int end)
{
	int	left;
	int	right;
	int	pivot;

	pivot = start;
	left = pivot + 1;
	right = end ;
	if (start == end)
		return ;
	while (left <= right)
	{
		while (s[left] < s[pivot] && left <= end)
			left ++ ;
		while (s[right] > s[pivot] && right >= start)
			right -- ;
		if (left < right)
			ab_swap(&s[left], &s[right]);
	}
	if (left > right)
		ab_swap(&s[right], &s[pivot]);
	if (start < right)
		quicksort(s, start, right - 1);
	if (left < end)
		quicksort(s, right + 1, end);
}

int	*arr_maker(int argc, char *argv[])
{
	int	*arr;
	int	j;

	j = 0;
	arr = (int *)malloc(sizeof(int) * (argc - 1)); // argc = 10
	while(j <= argc - 2) // j <= 8
	{
		arr[j] = ft_atoi(argv[j + 1]);
		j ++ ;
	}
	return	arr;
}

void	stack_maker(int argc, Stack *a, int *arr)
{
	while(argc > 1)
	{
		push(a, arr[argc - 2]);
		argc -- ;	
	}
}

void	stack_check(Stack *a, Stack *b, int *s, int argc)
{
	int	j;
	int	i;
	int	k;

	k = 0;
	i = a->top;
	j = b->top;
	printf("sorted int arr::");
	while(k < argc - 1)
	{
		printf("%d,", s[k]);
		k ++ ;
	}
	printf("\n");
	while (j >= 0 || i >= 0)
	{
		while(i > j && i >= 0)
		{
			printf("1a[%d]%d		b[%d]-\n",i, a->data[i],i);
			i -- ;
		}
		while (j > i && j >= 0)
		{
			printf("2a[%d]-		b[%d]%d\n",i,j,b->data[j]);
			j -- ;
		}
		while(i >= 0 && j >= 0)
		{
			printf("3a[%d]%d		b[%d]%d\n",i,a->data[i],j,b->data[j]);
			i -- ;
			j -- ;
		}
	}
}

int		where_is(Stack *a, int target)
{
	int	i;

	i = a->top;
	while(i >= 0)
	{
		if (a->data[i] == target)
			return i;
		i -- ;
	}
	return (-1);
}

void	target_up(Stack *a, int *s, int argc)
{
	int	target;
	int	target_location;
	int	standard;

	standard = (argc - 1) / 2;
	target = s[standard];
	target_location = where_is(a, target);
	if (target_location == -1)
	{
		target_location = where_is(a, s[standard - 1]);
		target = s[standard - 1];
	}
	//printf("Target_location::%d standard:%d\n", target_location,standard);
	while (a->data[a->top] != target)
	{
		if (target_location > standard)
			stack_down(a,'a');
		else
			stack_up(a,'a');
	}
}

int	main(int argc, char *argv[])
{
	Stack	a;
	Stack	b;
	int		*s;

	if (argc <= 1) // 나중에 숫자 아닌 다른거 들어올 때 규칙 제정하기
		return (0);
	s = arr_maker(argc, argv);
	stack_init(&a);
	stack_maker(argc, &a, s);
	quicksort(s, 0 , argc - 2); 
	//printf("SORTED\n");
	stack_init(&b);

	//stack_check(&a,&b,s,argc);
	stack_devide(&a, &b, s, argc);
	printf("stack divided into a and b\n");
	stack_check(&a,&b,s,argc);

	a_sort(&a, s, argc);
	//printf("goto a_sort\n");
	//stack_sort(&a);
}