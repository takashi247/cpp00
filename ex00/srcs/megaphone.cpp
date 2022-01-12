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
			for (std::string::size_type j = 0; j < s.length(); j++)
				s[j] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[j])));
			std::cout << s;
		}
		std::cout << std::endl;
	}
	return (0);
}
