
#include "ft_ls.h"


void	ft_fuite(char *tmp)
{
	char *lol;

	lol= ft_strnew(1);
	//ft_printf("%p\n", lol);
	lol = NULL;
	tmp = ft_strdup("coucou");
//	ft_printf("dans fonction%lu\n", tmp);
//	tmp = NULL;
//	tmp = ft_strdup("coucou");
//	ft_printf("dans fonction%lu\n", tmp);
//	tmp = NULL;

}


int main(int argc, const char *argv[])
{
	char *tmp;
	//ft_printf("%lu\n", tmp);
	//tmp = ft_strdup("coucou");
	ft_fuite(tmp);
	//ft_printf(" sortie de fonction%lu\n", tmp);
	//ft_printf("au moment de free apres tmp= NULL %lu\n", tmp);
	while (1);

	return 0;
}
