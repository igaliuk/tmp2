/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProcessesModule.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:43:27 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 17:41:06 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESSESMODULE_HPP
# define PROCESSESMODULE_HPP
# include "IMonitorModule.hpp"
# include <iostream>

class					ProcessesModule : public IMonitorModule
{
	public:
		ProcessesModule(std::string const  & top);
		ProcessesModule(ProcessesModule const & src);
		ProcessesModule		&operator=(ProcessesModule const & src);
		~ProcessesModule(void);
		void			update(void);
		int				getData1(void);
		int				getData2(void);
		std::string		getTitle(void);
		std::string		getText1(void);
		std::string		getText2(void);
	private:
		ProcessesModule(void);
		std::string		_title;
		std::string		_text1;
		std::string		_text2;
		int				_data1;
		int				_data2;
		std::string const	&_top;
};

#endif
