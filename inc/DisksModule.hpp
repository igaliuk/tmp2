/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisksModule.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:13:56 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 18:14:30 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISKSMODULE_HPP
# define DISKSMODULE_HPP
# include "IMonitorModule.hpp"
# include <iostream>

class					DisksModule : public IMonitorModule
{
	public:
		DisksModule(std::string const  & top);
		DisksModule(DisksModule const & src);
		DisksModule		&operator=(DisksModule const & src);
		~DisksModule(void);
		void			update(void);
		int				getData1(void);
		int				getData2(void);
		std::string		getTitle(void);
		std::string		getText1(void);
		std::string		getText2(void);
	private:
		DisksModule(void);
		std::string		_title;
		std::string		_text1;
		std::string		_text2;
		int				_data1;
		int				_data2;
		std::string const	&_top;
};

#endif
