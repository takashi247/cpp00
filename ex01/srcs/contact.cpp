#include "contact.hpp"

Contact::Contact():
	first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("")
{
}

Contact::~Contact(){}

const std::string
	Contact::get_first_name()
{
	return (this->first_name);
}

const std::string
	Contact::get_last_name()
{
	return (this->last_name);
}

const std::string
	Contact::get_nickname()
{
	return (this->nickname);
}

const std::string
	Contact::get_phone_number()
{
	return (this->phone_number);
}

const std::string
	Contact::get_darkest_secret()
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
