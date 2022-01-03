#include "phonebook.hpp"
#include <iostream>
#include <string>

Phonebook::Phonebook(): num_of_contacts(0), index(0){}

Phonebook::~Phonebook(){}

void
	Phonebook::exit(void)
{
	std::cout << "Thank you for using this app! Bye for now!" << std::endl;
}

void
	Phonebook::add_contact(void)
{
	std::string	first_name, last_name, nickname, phone_number, darkest_secret;

	if (this->index == 8)
		this->index = 0;
	std::cout << "Please input a new contact's information." << std::endl;
	std::cout << "What is his/her first name?: ";
	std::cin >> first_name;
	this->constact_list[this->index].set_first_name(first_name);
	std::cout << "What is his/her last name?: ";
	std::cin >> last_name;
	this->constact_list[this->index].set_last_name(last_name);
	std::cout << "What is his/her nickname?: ";
	std::cin >> nickname;
	this->constact_list[this->index].set_nickname(nickname);
	std::cout << "What is his/her phone number?: ";
	std::cin >> phone_number;
	this->constact_list[this->index].set_phone_number(phone_number);
	std::cout << "What is his/her darkest secret?: ";
	std::cin >> darkest_secret;
	this->constact_list[this->index].set_darkest_secret(darkest_secret);
	if (this->num_of_contacts < 8)
		this->num_of_contacts++;
	this->index++;
}

void
	Phonebook::search_contact(void)
{
	return ;
}
