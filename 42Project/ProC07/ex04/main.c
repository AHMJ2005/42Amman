#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int main ()
{
	char *nbr = "-QKqJkW";
	char *from = "aQXekWLct7brEMUyTBzKCixg2OFnqS1IHAmslYP0Nh598fJVj";
	char *to = "gTPnO1KrsheE5YfwZAjb4BS0cLyv2GpQRa3dtH";
	char *p = ft_convert_base(nbr,from,to);
	printf("%s", p);
	return 0;
}

