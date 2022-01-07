#include "phonebook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

const int	MAX_NUM_OF_CONTACT = 8;
const int	WIDTH_OF_COLUMN = 10;

Phonebook::Phonebook():
	num_of_contacts(0), index(0)
{
	std::cout << "\nWelcome to My Awesome PhoneBook!\n" << std::endl;
}

Phonebook::~Phonebook()
{
	std::cout << "\nThank you for using this app! Bye for now!\n" << std::endl;
}

void
	Phonebook::get_string_input(std::string &str)
{
	std::getline(std::cin, str);
	if (!std::cin.good())
	{
		std::cin.clear();
		std::cout << "\n\nInvalid input. Terminate the app.\n" << std::endl;
		std::exit(1);
	}
}

void
	Phonebook::add_contact()
{
	if (this->index == MAX_NUM_OF_CONTACT)
		this->index = 0;
	std::cout << "\nPlease input a new contact's information.\n" << std::endl;
	std::cout << "What is his/her first name?: ";
	std::string	first_name;
	Phonebook::get_string_input(first_name);
	this->contact_list[this->index].set_first_name(first_name);
	std::cout << "What is his/her last name?: ";
	std::string	last_name;
	Phonebook::get_string_input(last_name);
	this->contact_list[this->index].set_last_name(last_name);
	std::cout << "What is his/her nickname?: ";
	std::string	nickname;
	Phonebook::get_string_input(nickname);
	this->contact_list[this->index].set_nickname(nickname);
	std::cout << "What is his/her phone number?: ";
	std::string	phone_number;
	Phonebook::get_string_input(phone_number);
	this->contact_list[this->index].set_phone_number(phone_number);
	std::cout << "What is his/her darkest secret?: ";
	std::string	darkest_secret;
	Phonebook::get_string_input(darkest_secret);
	this->contact_list[this->index].set_darkest_secret(darkest_secret);
	std::cout << std::endl;
	if (this->num_of_contacts < MAX_NUM_OF_CONTACT)
		this->num_of_contacts++;
	this->index++;
}

void
	Phonebook::print_with_width(std::string str)
{
	std::cout << std::setw(WIDTH_OF_COLUMN);
	if (str.length() <= WIDTH_OF_COLUMN)
		std::cout << str;
	else
	{
		std::string	cpy = str.substr(0, WIDTH_OF_COLUMN - 1);
		cpy += ".";
		std::cout << cpy;
	}
}

void
	Phonebook::print_column_names()
{
	std::cout << "\n|";
	Phonebook::print_with_width("index");
	std::cout << "|";
	Phonebook::print_with_width("first name");
	std::cout << "|";
	Phonebook::print_with_width("last name");
	std::cout << "|";
	Phonebook::print_with_width("nickname");
	std::cout << "|" << std::endl;
}

void
	Phonebook::print_contact(int i, Contact contact)
{
	std::cout << "|";
	std::cout << std::setw(WIDTH_OF_COLUMN);
	std::cout << i + 1;
	std::cout << "|";
	Phonebook::print_with_width(contact.get_first_name());
	std::cout << "|";
	Phonebook::print_with_width(contact.get_last_name());
	std::cout << "|";
	Phonebook::print_with_width(contact.get_nickname());
	std::cout << "|" << std::endl;
}

int
	Phonebook::get_index_input()
{
	std::cout << "\nPlease type in the index number: ";
	std::string	num_str;
	Phonebook::get_string_input(num_str);
	std::istringstream	iss(num_str);
	int	num_int;
	iss >> num_int;
	return (num_int);
}

void
	Phonebook::print_all_info(Contact contact)
{
	std::cout << "\nFirst name    : " << contact.get_first_name() << std::endl;
	std::cout << "Last name     : " << contact.get_last_name() << std::endl;
	std::cout << "Nickname      : " << contact.get_nickname() << std::endl;
	std::cout << "Phone number  : " << contact.get_phone_number() << std::endl;
	std::cout << "Darkets secret: " << contact.get_darkest_secret() << "\n" << std::endl;
}

void
	Phonebook::search_contact()
{
	if (this->num_of_contacts == 0)
		std::cout << "\nERROR: No contacts are registered. Please ADD contacts first.\n" << std::endl;
	else
	{
		Phonebook::print_column_names();
		for (int i = 0; i < this->num_of_contacts; i++)
			Phonebook::print_contact(i, this->contact_list[i]);
		int	index = Phonebook::get_index_input();
		if (index <= 0 || this->num_of_contacts < index)
			std::cout << "\nERROR: Invalid index. Try again.\n" << std::endl;
		else
			Phonebook::print_all_info(this->contact_list[index - 1]);
	}
	return ;
}

void
	Phonebook::launch_app()
{
	while (1)
	{
		std::cout << "Please select a commnad [ADD/SEARCH/EXIT]: ";
		std::string	command;
		Phonebook::get_string_input(command);
		if (command.compare("ADD") == 0)
			this->add_contact();
		else if (command.compare("SEARCH") == 0)
			this->search_contact();
		else if (command.compare("EXIT") == 0)
			break ;
		else
			std::cout << "\nERROR: Invalid command. Available commands are ADD, SEARCH, or, EXIT\n" << std::endl;
	}
}
