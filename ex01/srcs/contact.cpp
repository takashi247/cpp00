#include "contact.hpp"

Contact::Contact():
	first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("")
{
}

Contact::~Contact(){}

std::string
	Contact::get_first_name() const
{
	return (this->first_name);
}

std::string
	Contact::get_last_name() const
{
	return (this->last_name);
}

std::string
	Contact::get_nickname() const
{
	return (this->nickname);
}

std::string
	Contact::get_phone_number() const
{
	return (this->phone_number);
}

std::string
	Contact::get_darkest_secret() const
{
	return (this->darkest_secret);
}

void
	Contact::set_first_name(std::string string)
{
	this->first_name = string;
}

void
	Contact::set_last_name(std::string string)
{
	this->last_name = string;
}

void
	Contact::set_nickname(std::string string)
{
	this->nickname = string;
}

void
	Contact::set_phone_number(std::string string)
{
	this->phone_number = string;
}

void
	Contact::set_darkest_secret(std::string string)
{
	this->darkest_secret = string;
}
