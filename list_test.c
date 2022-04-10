#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
	int		data;
	struct s_list	*next;
}		t_list;		

t_list	*int_array_to_list(const int *arr, int len)
{
	t_list	*first = NULL;
	t_list	*last = NULL;
	t_list	*tmp;

	for (int i = 0; i < len; ++i)
	{
		tmp = (t_list *) malloc(sizeof(t_list));
		if (!tmp)
			return (NULL);
		tmp->data = arr[i];
		tmp->next = NULL;
		if (last)
		{
			last->next = tmp;
			last = last->next;
		}
		else
			first = last = tmp;
	}
	return (first);
}

t_list	*int_array_to_list2(const int *arr, int len)
{
	t_list	*first = NULL;
	t_list	*tmp;

	for (int i = len - 1; i >= 0; --i)
	{
		tmp = (t_list *) malloc(sizeof(t_list));
		if (!tmp)
			return (NULL);
		tmp->data = arr[i];
		tmp->next = first;
		first = tmp;
	}
	return (first);
}

t_list	*int_array_to_list3(const int *arr, int len)
{
	t_list	*first;

	if (!len)
		return (NULL);
	first = (t_list *) malloc(sizeof(t_list));
	first->data = *arr;
	first->next = int_array_to_list(arr + 1, len - 1);
	return (first);
}	

int	lst_sum(const t_list *lst)
{
	int	sum;

	sum = 0;
	while (lst)
	{
		sum += lst->data;
		lst = lst->next;
	}
	return (sum);
}

int	lst_sum_rec(const t_list *lst)
{
	if (lst)
		return (lst->data + lst_sum_rec(lst->next));
	else
		return (0);
}

int	lst_sum_rec2(const t_list *lst)
{
	return (lst ? lst->data + lst_sum_rec2(lst->next) : 0);
}

void	lst_print(const t_list *lst)
{
	while (lst)
	{
		printf("%d\n", lst->data);
		lst = lst->next;
	}
}

void	del_int_lst(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	del_int_lst_rec(t_list *lst)
{
	if (!lst)
		return ;
	del_int_lst_rec(lst->next);
	free(lst);
}

void	del_int_lst_rec2(t_list *lst)
{
	if (lst)
	{
		del_int_lst_rec2(lst->next);
		free(lst);
	}
}

void	del_negatives_from_int_lst(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		if ((*lst)->data < 0)
		{
			tmp = *lst;
			*lst = (*lst)->next;
			free(tmp);
		}
		else
			lst = &(*lst)->next;
	}
}

int	main(void)
{
	int	arr[] = { 1, 2, 3, 4, 5, -6, -7, -8, -9 };
	t_list	*lst;
	
	//lst = int_array_to_list(arr, sizeof(arr) / sizeof(*arr));
	//lst = int_array_to_list2(arr, sizeof(arr) / sizeof(*arr));
	lst = int_array_to_list3(arr, sizeof(arr) / sizeof(*arr));

	lst_print(lst);
	printf("sum = %d\n", lst_sum(lst));
	printf("sum = %d\n", lst_sum_rec(lst));
	printf("sum = %d\n", lst_sum_rec2(lst));
	del_negatives_from_int_lst(&lst);
	lst_print(lst);
	//del_int_lst(lst);
	del_int_lst_rec(lst);
}
