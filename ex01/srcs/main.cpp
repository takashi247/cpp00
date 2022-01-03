#include "phonebook.hpp"
#include <iostream>

int
	main(void)
{
	std::string	command;
	Phonebook	Phonebook;

	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	while (1)
	{
		std::cout << "Please select a commnad [ADD/SEARCH/EXIT]: ";
		std::cin >> command;
		if (command == "ADD")
			Phonebook.add_contact();
		else if (command == "SEARCH")
			Phonebook.search_contact();
		else if (command == "EXIT")
		{
			Phonebook.exit();
			break ;
		}
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return (0);
}