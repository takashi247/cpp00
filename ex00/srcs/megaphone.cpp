#include <iostream>
#include <string>

int
	main(int ac, char **av)
{
	std::locale	loc;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		ac--;
		av++;
		for (int i = 0; i < ac; i++)
		{
			std::string s = av[i];
			for (int j = 0; j < (int)s.length(); j++)
				s[j] = std::toupper(s[j]);
			std::cout << s;
		}
		std::cout << std::endl;
	}
	return (0);
}
