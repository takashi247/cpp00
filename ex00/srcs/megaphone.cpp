#include <iostream>
#include <string>

int
	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		ac--;
		av++;
		for (int i = 0; i < ac; i++)
		{
			std::string s = av[i];
			for (size_t j = 0; j < s.length(); j++)
				s[j] = std::toupper(s[j]);
			std::cout << s;
		}
		std::cout << std::endl;
	}
	return (0);
}
