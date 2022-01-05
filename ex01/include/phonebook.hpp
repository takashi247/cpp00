#ifndef _PHONEBOOK_HPP_
# define _PHONEBOOK_HPP_

# include "contact.hpp"

class Phonebook
{
	private:
		int		num_of_contacts;
		int		index;
		Contact	contact_list[8];
	public:
		Phonebook();
		~Phonebook();
		void	add_contact(void);
		void	search_contact(void);
		void	launch_app(void);
};

#endif
