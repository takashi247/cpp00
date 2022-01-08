#ifndef _CONTACT_HPP_
# define _CONTACT_HPP_

# include <string>

class Contact
{
	public:
		Contact();
		~Contact();
		std::string	get_first_name() const;
		std::string	get_last_name() const;
		std::string	get_nickname() const;
		std::string	get_phone_number() const;
		std::string	get_darkest_secret() const;
		void		set_first_name(std::string string);
		void		set_last_name(std::string string);
		void		set_nickname(std::string string);
		void		set_phone_number(std::string string);
		void		set_darkest_secret(std::string string);
	private:
		std::string	first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

#endif