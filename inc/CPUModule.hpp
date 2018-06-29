/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:43:27 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 15:21:08 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP
# include "IMonitorModule.hpp"
# include <iostream>

class					CPUModule : public IMonitorModule
{
	public:
		CPUModule(std::string const  & top);
		CPUModule(CPUModule const & src);
		CPUModule		&operator=(CPUModule const & src);
		~CPUModule(void);
		void			update(void);
		int				getData1(void);
		int				getData2(void);
		std::string		getTitle(void);
		std::string		getText1(void);
		std::string		getText2(void);
	private:
		CPUModule(void);
		std::string		_title;
		std::string		_text1;
		std::string		_text2;
		int				_data1;
		int				_data2;
		std::string const	&_top;
};

#endif
