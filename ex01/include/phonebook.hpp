#ifndef _PHONEBOOK_HPP_
# define _PHONEBOOK_HPP_

# include "contact.hpp"

extern const int	MAX_NUM_OF_CONTACT;
extern const int	WIDTH_OF_COLUMN;

class Phonebook
{
	public:
		Phonebook();
		~Phonebook();
		void	launch_app();
	private:
		int		num_of_contacts;
		int		index;
		Contact	contact_list[8];
		void	add_contact();
		void	search_contact();
		void	print_with_width(std::string str);
		void	print_column_names();
		void	print_contact(int i, Contact contact);
		int		get_index_input();
		void	print_all_info(Contact contact);
		void	get_string_input(std::string &str);
};

#endif
