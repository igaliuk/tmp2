/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:43:27 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 15:37:10 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP
# include "IMonitorModule.hpp"
# include <iostream>

class					RAMModule : public IMonitorModule
{
	public:
		RAMModule(std::string const  & top);
		RAMModule(RAMModule const & src);
		RAMModule		&operator=(RAMModule const & src);
		~RAMModule(void);
		void			update(void);
		int				getData1(void);
		int				getData2(void);
		std::string		getTitle(void);
		std::string		getText1(void);
		std::string		getText2(void);
	private:
		RAMModule(void);
		std::string		_title;
		std::string		_text1;
		std::string		_text2;
		int				_data1;
		int				_data2;
		std::string const	&_top;
};

#endif
