#include "phonebook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

Phonebook::Phonebook(): num_of_contacts(0), index(0)
{
	std::cout << "\nWelcome to My Awesome PhoneBook!\n" << std::endl;
}

Phonebook::~Phonebook()
{
	std::cout << "\nThank you for using this app! Bye for now!\n" << std::endl;
}

void
	Phonebook::add_contact(void)
{
	std::string	first_name, last_name, nickname, phone_number, darkest_secret;

	if (this->index == 8)
		this->index = 0;
	std::cout << std::endl;
	std::cout << "Please input a new contact's information." << std::endl;
	std::cout << std::endl;
	std::cout << "What is his/her first name?: ";
	std::getline(std::cin, first_name);
	this->contact_list[this->index].set_first_name(first_name);
	std::cout << "What is his/her last name?: ";
	std::getline(std::cin, last_name);
	this->contact_list[this->index].set_last_name(last_name);
	std::cout << "What is his/her nickname?: ";
	std::getline(std::cin, nickname);
	this->contact_list[this->index].set_nickname(nickname);
	std::cout << "What is his/her phone number?: ";
	std::getline(std::cin, phone_number);
	this->contact_list[this->index].set_phone_number(phone_number);
	std::cout << "What is his/her darkest secret?: ";
	std::getline(std::cin, darkest_secret);
	this->contact_list[this->index].set_darkest_secret(darkest_secret);
	std::cout << std::endl;
	if (this->num_of_contacts < 8)
		this->num_of_contacts++;
	this->index++;
}

void
	print_with_width(std::string str)
{
	std::cout << std::setw(10);
	if (str.length() <= 10)
		std::cout << str;
	else
	{
		std::string	cpy = str.substr(0, 9);
		cpy += ".";
		std::cout << cpy;
	}
}

void
	print_column_names(void)
{
	std::cout << std::endl;
	std::cout << "|";
	print_with_width("index");
	std::cout << "|";
	print_with_width("first name");
	std::cout << "|";
	print_with_width("last name");
	std::cout << "|";
	print_with_width("nickname");
	std::cout << "|" << std::endl;
}

void
	print_contact(int i, Contact contact)
{
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << i + 1;
	std::cout << "|";
	print_with_width(contact.get_first_name());
	std::cout << "|";
	print_with_width(contact.get_last_name());
	std::cout << "|";
	print_with_width(contact.get_nickname());
	std::cout << "|" << std::endl;
}

int
	get_index_input(void)
{
	std::cout << "\nPlease type in the index number: ";
	std::string	num_str;
	std::getline(std::cin, num_str);
	std::istringstream	iss(num_str);
	int	num_int;
	iss >> num_int;
	return (num_int);
}

void
	print_all_info(Contact contact)
{
	std::cout << std::endl;
	std::cout << "First name: " << contact.get_first_name() << std::endl;
	std::cout << "Last name: " << contact.get_last_name() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone number: " << contact.get_phone_number() << std::endl;
	std::cout << "Darkets secret: " << contact.get_darkest_secret() << std::endl;
	std::cout << std::endl;
}

void
	Phonebook::search_contact(void)
{
	if (this->num_of_contacts == 0)
	{
		std::cout << std::endl;
		std::cout << "ERROR: No contacts are registered. Please ADD contacts first." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		print_column_names();
		for (int i = 0; i < this->num_of_contacts; i++)
			print_contact(i, this->contact_list[i]);
		int	index = get_index_input();
		if (index <= 0 || this->num_of_contacts < index)
		{
			std::cout << std::endl;
			std::cout << "ERROR: Invalid index. Try again." << std::endl;
			std::cout << std::endl;
		}
		else
			print_all_info(this->contact_list[index - 1]);
	}
	return ;
}

void
	Phonebook::launch_app(void)
{
	std::string	command;

	while (1)
	{
		std::cout << "Please select a commnad [ADD/SEARCH/EXIT]: ";
		if (!std::getline(std::cin, command))
		{
			std::cin.clear();
			std::cout << "you should enter something" << std::endl;
			continue ;
		}
		if (command.compare("ADD") == 0)
			this->add_contact();
		else if (command.compare("SEARCH") == 0)
			this->search_contact();
		else if (command.compare("EXIT") == 0)
			break ;
		else if (std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else
			std::cout << "\nERROR: Invalid command. Available commands are ADD, SEARCH, or, EXIT\n" << std::endl;
	}
}