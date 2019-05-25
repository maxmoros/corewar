/**
 * File              : main.c
 * Author            : pdeguing <pdeguing@student.42.us.org>
 * Date              : 25.05.2019
 * Last Modified Date: 25.05.2019
 * Last Modified By  : pdeguing <pdeguing@student.42.us.org>
 */

#include "assembler.h"

int		main(int ac, char **av)
{
	t_error	err;

	if (ac == 2)
	{
		err = assembler(av[1]);
		if (err)
		{
			printf("%s\n", err);
			return 1;
		}
	}
	else
	{
		ft_printf("usage: ./asm monchampion.s\n");
	}
	return 0;
}
